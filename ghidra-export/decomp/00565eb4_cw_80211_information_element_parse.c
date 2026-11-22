// func cw_80211_information_element_parse @ 00565eb4 size=548

undefined4 cw_80211_information_element_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0xc,0x65);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_information_element_parse",0x68);
    return 0xffffffff;
  }
  memset(__s,0,0xc);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar2;
    if (uVar2 < 0x11) {
      uVar2 = cw_protocol_retrieve8(param_1);
      __s[2] = (byte)uVar2;
      if ((uVar2 & 0xc0) == uVar2) {
        *(short *)(__s + 4) = *(short *)(param_2 + 0xe) + -3;
        iVar3 = cw_protocol_retrieve_raw_bytes(param_1);
        *(int *)(__s + 8) = iVar3;
        if (iVar3 != 0) {
          *(byte **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to read information element\n",
                 "cw_80211_information_element_parse",0x8d);
        }
        goto LAB_00565ff0;
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00565ff0;
      uVar2 = (uint)__s[2];
      __format = "[CW_ERROR]%32s():%4d flags(0x%02x)\n";
      uVar4 = 0x83;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00565ff0;
      uVar2 = (uint)__s[1];
      __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar4 = 0x7a;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00565ff0;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x71;
  }
  printf(__format,"cw_80211_information_element_parse",uVar4,uVar2);
LAB_00565ff0:
  FUN_00407df0(__s);
  return 0xffffffff;
}

