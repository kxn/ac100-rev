// func cw_80211_information_element_assemble @ 00565cf0 size=452

undefined4 cw_80211_information_element_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar5 < 0x20) {
    cw_protocol_restore8();
    if (pbVar5[1] < 0x11) {
      cw_protocol_restore8(param_1);
      if ((pbVar5[2] & 0xc0) == pbVar5[2]) {
        cw_protocol_restore8(param_1);
        if (((uint)*(ushort *)(pbVar5 + 4) == *(ushort *)(param_2 + 0xe) - 3) &&
           (*(int *)(pbVar5 + 8) != 0)) {
          cw_protocol_restore_raw_bytes(param_1);
          if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d length or info_ele is wrong\n",
               "cw_80211_information_element_assemble",0xc0);
        return 0xffffffff;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar4 = (uint)pbVar5[2];
      __format = "[CW_ERROR]%32s():%4d flags(0x%02x) is wrong\n";
      uVar3 = 0xb8;
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar4 = (uint)pbVar5[1];
      __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar3 = 0xb0;
    }
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar4 = (uint)*pbVar5;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar3 = 0xa8;
  }
  printf(__format,"cw_80211_information_element_assemble",uVar3,uVar4);
  return 0xffffffff;
}

