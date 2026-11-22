// func cw_80211_wtp_radio_information_parse @ 0056c9d0 size=380

undefined4 cw_80211_wtp_radio_information_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x75);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memmory\n","cw_80211_wtp_radio_information_parse",0x78);
    return 0xffffffff;
  }
  memset(__s,0,8);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve32(param_1);
    *(uint *)(__s + 4) = uVar2;
    if ((uVar2 & 0x3f) == uVar2) {
      *(byte **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056cad0;
    uVar2 = *(uint *)(__s + 4);
    __format = "[CW_ERROR]%32s():%4d radio type(0x%08x) is wrong\n";
    uVar4 = 0x8a;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056cad0;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x81;
  }
  printf(__format,"cw_80211_wtp_radio_information_parse",uVar4,uVar2);
LAB_0056cad0:
  FUN_00407df0(__s);
  return 0xffffffff;
}

