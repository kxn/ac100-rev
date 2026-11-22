// func cw_80211_wtp_radio_fail_alarm_dump @ 0056c1ec size=212

undefined4 cw_80211_wtp_radio_fail_alarm_dump(int param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 WTP Radio Fail Alarm \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 WTP Radio Fail Alarm (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x.. \r\n",(uint)*pbVar2,(uint)pbVar2[1]);
  if (*pbVar2 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    printf("\t\t\tType: %d \r\n",(uint)pbVar2[1]);
    printf("\t\t\tStatus: %d \r\n",(uint)pbVar2[2]);
    printf("\t\t\tPad: %d \r\n",(uint)pbVar2[3]);
    uVar1 = 0;
  }
  else {
    printf("\t\t\t***Radio ID(%d) Is Wrong \r\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

