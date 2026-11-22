// func cw_80211_wtp_radio_configuration_parse @ 0056bf38 size=448

undefined4 cw_80211_wtp_radio_configuration_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  byte bVar5;
  undefined2 uVar4;
  int iVar3;
  char *__format;
  undefined4 uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x10,0x6b);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memeory\n","cw_80211_wtp_radio_configuration_parse",0x6e);
    return 0xffffffff;
  }
  memset(__s,0,0x10);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar2;
    if (uVar2 < 2) {
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[2] = bVar5;
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[3] = bVar5;
      cw_protocol_retrieve_bytes(param_1,__s + 4,6);
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 10) = uVar4;
      cw_protocol_retrieve_bytes(param_1,__s + 0xc,4);
      *(byte **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056c080;
    bVar5 = __s[1];
    __format = "[CW_ERROR]%32s():%4d short preamble(%d) is wrong\n";
    uVar6 = 0x80;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0056c080;
    bVar5 = *__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x77;
  }
  printf(__format,"cw_80211_wtp_radio_configuration_parse",uVar6,(uint)bVar5);
LAB_0056c080:
  FUN_00407df0(__s);
  return 0xffffffff;
}

