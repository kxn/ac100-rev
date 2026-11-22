// func cw_dtls_pkt_parsed @ 005983bc size=296

undefined4 cw_dtls_pkt_parsed(int param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d inputs error.\n";
    uVar2 = 0x91;
  }
  else {
    iVar1 = cw_protocol_retrieve_bytes(param_1,param_2,4);
    if (iVar1 == 4) {
      iVar1 = cw_dtls_pkt_eles_parsed(param_1,param_2);
      if (iVar1 != -1) {
        if (*(short *)(param_1 + 6) != *(short *)(param_1 + 4)) {
          return 0xffffffff;
        }
        return 0;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[CW_ERROR]%32s():%4d parsed dtls elements failed.\n";
      uVar2 = 0x9f;
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[CW_ERROR]%32s():%4d parsed capwap dtls header failed.\n";
      uVar2 = 0x98;
    }
  }
  printf(__format,"cw_dtls_pkt_parsed",uVar2);
  return 0xffffffff;
}

