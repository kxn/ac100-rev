// func apupd_md5_calc @ 006610f0 size=272

void apupd_md5_calc(char *param_1,size_t param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_70 [8];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58 [18];
  
  if (param_3 != 0) {
    if (param_2 == 0) {
      param_2 = strlen(param_1);
    }
    local_58[0] = 0;
    local_58[1] = 0;
    local_68 = 0x67452301;
    local_64 = 0xefcdab89;
    local_60 = 0x98badcfe;
    local_5c = 0x10325476;
    _mdUpdate(&local_68,param_1,param_2,param_4);
    _mdEncode(auStack_70,local_58,8);
    uVar1 = (uint)(local_58[0] << 0x17) >> 0x1a;
    iVar2 = 0x38;
    if (0x37 < uVar1) {
      iVar2 = 0x78;
    }
    _mdUpdate(&local_68,&l_md5Padding,iVar2 - uVar1,param_4);
    _mdUpdate(&local_68,auStack_70,8,param_4);
    _mdEncode(param_3,&local_68,0x10);
    memset(&local_68,0,0x58);
  }
  return;
}

