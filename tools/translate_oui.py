#!/usr/bin/env python3
"""Offline Chinese reference names; original IEEE names remain identity keys.

Optional preparation dependencies: ctranslate2 and sentencepiece. The AC never
loads this model or runs translation. Weights remain outside the repository.
"""
import argparse
import collections
import gzip
import hashlib
import json
import pathlib
import re
import time
from prepare_oui import brand_for

BRANDS_ZH = {
 "Apple":"苹果","Samsung":"三星","Huawei":"华为","Xiaomi":"小米","vivo":"维沃","OPPO":"OPPO","Honor":"荣耀","OnePlus":"一加","realme":"真我","Google":"谷歌","Microsoft":"微软","Amazon":"亚马逊","Sony":"索尼","Lenovo":"联想","Motorola":"摩托罗拉","Nokia":"诺基亚","ASUS":"华硕","Acer":"宏碁","Dell":"戴尔","HP":"惠普","HPE":"慧与","TP-Link":"普联","NETGEAR":"网件","Ubiquiti":"优倍快","Cisco":"思科","Aruba":"Aruba","Ruijie":"锐捷","H3C":"新华三","Hikvision":"海康威视","Dahua":"大华","Espressif":"乐鑫","Tuya":"涂鸦","Intel":"英特尔","MediaTek":"联发科","Qualcomm":"高通","Broadcom":"博通","Raspberry Pi":"树莓派","ZTE":"中兴","TCL":"TCL","LG":"LG","Panasonic":"松下","Nintendo":"任天堂","Sonos":"Sonos","DJI":"大疆","Tesla":"特斯拉","Murata":"村田","AzureWave":"海华","Lite-On":"光宝","Foxconn":"富士康","Wistron":"纬创","Compal":"仁宝"
}
TOKENS = {
 "HPE":[r"hewlett[ -]+packard enterprise",r"hpe"], "HP":[r"hewlett[ -]+packard",r"hp"],
 "TP-Link":[r"tp[- ]?link"],"ASUS":[r"asustek",r"asus"],"Panasonic":[r"panasonic",r"matsushita"],"Foxconn":[r"foxconn",r"hon hai"],"Lite-On":[r"lite[- ]on"],
}
LEGAL = re.compile(r"(?i)(?:^|[,\s]+)(co(?:mpany)?[.,\s]*ltd\.?|limited|ltd\.?|incorporated|inc\.?|corporation|corp\.?|llc|gmbh|ag|s\.?a\.?)\s*$")
HAN = re.compile(r"[\u3400-\u9fff]")


def parts(name):
    """Keep legal type deterministic; Inc does not imply joint-stock company."""
    suffix=""
    match=LEGAL.search(name)
    core=name
    if match:
        kind=re.sub(r"[.,\s]","",match.group(1)).casefold()
        suffix="有限公司" if kind in ("coltd","companyltd","limited","ltd","llc","gmbh") else "公司"
        core=name[:match.start()].strip(" ,.")
    brand=brand_for(name)
    if brand:
        tokens=TOKENS.get(brand,[re.escape(brand)])
        pattern=re.compile(r"(?i)(?<![a-z0-9])(?:"+"|".join(tokens)+r")(?![a-z0-9])")
        match=pattern.search(core)
        if match:
            return [core[:match.start()], BRANDS_ZH[brand], core[match.end():]],suffix,True
    return [core],suffix,False


def translate(model_path,input_path,output_path,threads):
    import ctranslate2
    import sentencepiece
    payload=json.loads(gzip.decompress(input_path.read_bytes()))
    names=[o['name'] for o in payload['organizations']]
    result=json.loads(gzip.decompress(output_path.read_bytes())) if output_path.exists() else {"schema":1,"translations":{}}
    cache=result['translations']
    todo=[name for name in names if name not in cache]
    parsed={name:parts(name) for name in todo}
    segments=sorted({part.strip(" ,.") for name,(p,_,_) in parsed.items() for i,part in enumerate(p) if part.strip(" ,.") and not(len(p)==3 and i==1) and not HAN.search(part)})
    sp=sentencepiece.SentencePieceProcessor(model_file=str(model_path/'sentencepiece.model'))
    engine=ctranslate2.Translator(str(model_path/'model'),device='cpu',compute_type='int8',intra_threads=threads,inter_threads=1)
    translated={};started=time.monotonic()
    for start in range(0,len(segments),128):
        batch=segments[start:start+128]
        outputs=engine.translate_batch([sp.encode(x,out_type=str) for x in batch],beam_size=2,max_decoding_length=96)
        for original,out in zip(batch,outputs):
            value=sp.decode(out.hypotheses[0]).replace('▁',' ').strip().rstrip('.')
            translated[original]=value
        if start%2048==0:print(json.dumps({'segments':min(start+128,len(segments)),'total':len(segments),'seconds':round(time.monotonic()-started,1)}),flush=True)
    for name,(p,suffix,glossary) in parsed.items():
        if name.strip().casefold() == "private":
            cache[name]={"name_zh":"未公开机构","source":"registry-meaning"};continue
        if HAN.search(name):
            cache[name]={"name_zh":name,"source":"original-han"};continue
        output=''
        for i,part in enumerate(p):
            part=part.strip(" ,.")
            if not part:continue
            if len(p)==3 and i==1:output+=part
            else:output+=translated.get(part,part)
        output=(output+suffix).strip()
        if not HAN.search(output):
            cache[name]={"name_zh":"","source":"untranslated"};continue
        cache[name]={"name_zh":output,"source":"glossary+machine" if glossary else "machine-unreviewed"}
    result['model']={'name':'Argos Translate en_zh 1.9','package_sha256':'433e7c4f034d87fbe2353161e05f18646d7999452f801a4e1f0378522b9850ab','url':'https://data.argosopentech.com/argospm/v1/translate-en_zh-1_9.argosmodel','engine':'CTranslate2 int8 CPU, beam2','weights_committed':False}
    output_path.parent.mkdir(parents=True,exist_ok=True)
    output_path.write_bytes(gzip.compress(json.dumps(result,ensure_ascii=False,separators=(',',':')).encode(),mtime=0))
    print(json.dumps({'organizations':len(names),'sources':dict(collections.Counter(cache[n]['source'] for n in names)),'seconds':round(time.monotonic()-started,1),'bytes':output_path.stat().st_size}),flush=True)

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--model',required=True,type=pathlib.Path)
    parser.add_argument('--input',default='uacgo/data/oui/registry.json.gz',type=pathlib.Path)
    parser.add_argument('--output',default='uacgo/data/oui/names-zh.json.gz',type=pathlib.Path)
    parser.add_argument('--threads',type=int,default=4)
    args=parser.parse_args();translate(args.model,args.input,args.output,args.threads)
