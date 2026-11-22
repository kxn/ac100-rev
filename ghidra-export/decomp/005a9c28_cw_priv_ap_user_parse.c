// func cw_priv_ap_user_parse @ 005a9c28 size=232

undefined4 cw_priv_ap_user_parse(int param_1,int param_2)

{
  ushort uVar1;
  void *__s;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(0x80,0x7d);
  if (__s == (void *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_user_parse",0x80);
    }
  }
  else {
    memset(__s,0,0x80);
    cw_protocol_retrieve_bytes(param_1,__s,0x40);
    cw_protocol_retrieve_bytes(param_1,(int)__s + 0x40,0x40);
    *(void **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

