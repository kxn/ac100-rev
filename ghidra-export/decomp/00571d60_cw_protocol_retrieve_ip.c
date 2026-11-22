// func cw_protocol_retrieve_ip @ 00571d60 size=260

undefined4 cw_protocol_retrieve_ip(int param_1,byte *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_retrieve_ip",0xf8);
    }
  }
  else {
    iVar1 = cw_protocol_retrieve8();
    *param_2 = (byte)iVar1;
    if (iVar1 == 1) {
      uVar2 = cw_protocol_retrieve32(param_1);
      uVar3 = 5;
      *(undefined4 *)(param_2 + 4) = uVar2;
    }
    else if (iVar1 == 2) {
      cw_protocol_retrieve_bytes(param_1,param_2 + 4,0x10);
      uVar3 = 0x11;
    }
    else {
      uVar3 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d illegal ip type:%d\n","cw_protocol_retrieve_ip",0x108,
               (uint)*param_2);
      }
    }
  }
  return uVar3;
}

