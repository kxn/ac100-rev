// func cw_priv_large_fireware_info_parse @ 005b4adc size=264

undefined4 cw_priv_large_fireware_info_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *__s;
  undefined1 uVar4;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined1 *)FUN_00408450(0x20,0x7e);
  if (__s == (undefined1 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_large_fireware_info_parse",0x81);
    }
  }
  else {
    memset(__s,0,0x20);
    uVar4 = cw_protocol_retrieve8(param_1);
    *__s = uVar4;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 4) = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 8) = uVar2;
    cw_protocol_retrieve_bytes(param_1,__s + 0xc,0x10);
    uVar2 = cw_protocol_retrieve32(param_1);
    *(undefined4 *)(__s + 0x1c) = uVar2;
    *(undefined1 **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

