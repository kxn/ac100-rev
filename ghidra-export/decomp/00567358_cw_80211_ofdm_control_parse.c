// func cw_80211_ofdm_control_parse @ 00567358 size=476

undefined4 cw_80211_ofdm_control_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  int iVar3;
  byte bVar5;
  undefined4 uVar4;
  char *__format;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x67);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memeory\n","cw_80211_ofdm_control_parse",0x6a);
    return 0xffffffff;
  }
  memset(__s,0,8);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    iVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)iVar3;
    if (iVar3 == 0) {
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[2] = bVar5;
      uVar2 = cw_protocol_retrieve8(param_1);
      __s[3] = (byte)uVar2;
      if ((uVar2 & 0x7f) == uVar2) {
        uVar4 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(__s + 4) = uVar4;
        *(byte **)(param_2 + 0x10) = __s;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00567484;
      uVar2 = (uint)__s[3];
      __format = "[CW_ERROR]%32s():%4d band support(0x%02x) is wrong\n";
      uVar4 = 0x88;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00567484;
      uVar2 = (uint)__s[1];
      __format = "[CW_ERROR]%32s():%4d reserved(%d) isn\'t reserved\n";
      uVar4 = 0x7c;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00567484;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x73;
  }
  printf(__format,"cw_80211_ofdm_control_parse",uVar4,uVar2);
LAB_00567484:
  FUN_00407df0(__s);
  return 0xffffffff;
}

