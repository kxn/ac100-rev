// func cw_wtp_static_ip_address_information_parse @ 00586f3c size=248

undefined4 cw_wtp_static_ip_address_information_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 *__s;
  undefined4 uVar2;
  undefined1 uVar4;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined4 *)FUN_00408450(0x10,0x75);
  if (__s == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_wtp_static_ip_address_information_parse",
             0x78);
    }
  }
  else {
    memset(__s,0,0x10);
    uVar2 = cw_protocol_retrieve32(param_1);
    *__s = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    __s[1] = uVar2;
    uVar2 = cw_protocol_retrieve32(param_1);
    __s[2] = uVar2;
    uVar4 = cw_protocol_retrieve8(param_1);
    *(undefined1 *)(__s + 3) = uVar4;
    *(undefined4 **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

