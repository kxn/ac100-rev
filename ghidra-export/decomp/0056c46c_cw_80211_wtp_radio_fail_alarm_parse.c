// func cw_80211_wtp_radio_fail_alarm_parse @ 0056c46c size=472

undefined4 cw_80211_wtp_radio_fail_alarm_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  char *__format;
  undefined4 uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  pbVar2 = (byte *)FUN_00408450(4,0x65);
  if (pbVar2 == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memeory\n","cw_80211_wtp_radio_fail_alarm_parse",0x68);
    return 0xffffffff;
  }
  *pbVar2 = 0;
  pbVar2[1] = 0;
  pbVar2[2] = 0;
  pbVar2[3] = 0;
  uVar3 = cw_protocol_retrieve8(param_1);
  *pbVar2 = (byte)uVar3;
  if (uVar3 < 0x20) {
    iVar4 = cw_protocol_retrieve8(param_1);
    pbVar2[1] = (byte)iVar4;
    if (iVar4 - 1U < 2) {
      uVar3 = cw_protocol_retrieve8(param_1);
      pbVar2[2] = (byte)uVar3;
      if (uVar3 < 2) {
        bVar5 = cw_protocol_retrieve8(param_1);
        pbVar2[3] = bVar5;
        *(byte **)(param_2 + 0x10) = pbVar2;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0056c598;
      uVar3 = (uint)pbVar2[2];
      __format = "[CW_ERROR]%32s():%4d status(%d) is wrong\n";
      uVar6 = 0x83;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0056c598;
      uVar3 = (uint)pbVar2[1];
      __format = "[CW_ERROR]%32s():%4d type(%d) is wrong\n";
      uVar6 = 0x7a;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0056c598;
    uVar3 = (uint)*pbVar2;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar6 = 0x71;
  }
  printf(__format,"cw_80211_wtp_radio_fail_alarm_parse",uVar6,uVar3);
LAB_0056c598:
  FUN_00407df0(pbVar2);
  return 0xffffffff;
}

