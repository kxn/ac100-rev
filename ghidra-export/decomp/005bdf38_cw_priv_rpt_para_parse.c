// func cw_priv_rpt_para_parse @ 005bdf38 size=260

undefined4 cw_priv_rpt_para_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 *__s;
  undefined2 uVar4;
  undefined1 uVar5;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined2 *)FUN_00408450(0x10,0x75);
  if (__s == (undefined2 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_rpt_para_parse",0x78);
    }
  }
  else {
    memset(__s,0,0x10);
    uVar4 = cw_protocol_retrieve16(param_1);
    *__s = uVar4;
    uVar4 = cw_protocol_retrieve16(param_1);
    __s[1] = uVar4;
    uVar5 = cw_protocol_retrieve8(param_1);
    *(undefined1 *)(__s + 2) = uVar5;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 4) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 6) = uVar2;
    *(undefined2 **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

