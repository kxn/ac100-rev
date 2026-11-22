// func cw_80211_direct_sequence_control_dump @ 00565238 size=432

undefined4 cw_80211_direct_sequence_control_dump(int param_1)

{
  char *__format;
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Direct Sequence Control \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Direct Sequence Control (%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x%02x%02x%08x \r\n",(uint)*pbVar2,(uint)pbVar2[1],(uint)pbVar2[2],
         (uint)pbVar2[3],*(undefined4 *)(pbVar2 + 4));
  uVar1 = (uint)*pbVar2;
  if (uVar1 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    uVar1 = (uint)pbVar2[1];
    if (uVar1 == 0) {
      printf("\t\t\tReserved: %d \r\n",0);
      printf("\t\t\tCurrent Chan: %d \r\n",(uint)pbVar2[2]);
      uVar1 = (uint)pbVar2[3];
      if ((uVar1 & 0x1f) == uVar1) {
        printf("\t\t\tCurrent CCA: %d \r\n");
        printf("\t\t\tEnergy Detect Threshold: %d \r\n",*(undefined4 *)(pbVar2 + 4));
        if (*(short *)(param_1 + 0xe) != 0x13) {
          return 0;
        }
        printf("\t\t\tch_switch_type: %d\r\n",(uint)pbVar2[8]);
        printf("\t\t\tch_scan_interval: %d\r\n ",(uint)*(ushort *)(pbVar2 + 10));
        printf("\t\t\tch_occup_threshold: %d\r\n ",(uint)*(ushort *)(pbVar2 + 0xc));
        printf("\t\t\tch_err_fame_ratio: %d\r\n ",(uint)*(ushort *)(pbVar2 + 0xe));
        printf("\t\t\tch_tolerance_ratio: %d\r\n ",(uint)*(ushort *)(pbVar2 + 0x10));
        printf("\t\t\tch_online_switch %d\r\n",(uint)pbVar2[0x12]);
        printf("\t\t\tch_reselect: %d\r\n",(uint)pbVar2[0x13]);
        return 0;
      }
      __format = "\t\t\t***Current CCA(%d) Is Wrong \r\n";
    }
    else {
      __format = "\t\t\t***Reserved(%d) Is Wrong \r\n";
    }
  }
  else {
    __format = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(__format,uVar1);
  return 0xffffffff;
}

