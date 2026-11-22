// func cw_priv_ap_offline_mngr_parse @ 005a6b88 size=272

undefined4 cw_priv_ap_offline_mngr_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 *__s;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined4 *)FUN_00408450(0x18,0x79);
  if (__s == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_offline_mngr_parse",0x7c);
    }
  }
  else {
    memset(__s,0,0x18);
    uVar2 = cw_protocol_retrieve32(param_1);
    *__s = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    __s[1] = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    __s[2] = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    __s[3] = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    __s[4] = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    __s[5] = uVar2;
    *(undefined4 **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

