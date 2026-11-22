// func cw_80211_update_station_qos_dump @ 0056a36c size=376

undefined4 cw_80211_update_station_qos_dump(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  
  pbVar6 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Update Station Qos \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Update Station Qos (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x... \r\n",(uint)*pbVar6);
  uVar4 = (uint)*pbVar6;
  if (uVar4 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    iVar5 = 0;
    printf("\t\t\tMAC Address: ");
    do {
      pcVar3 = "%02x \r\n";
      if (iVar5 == 5) {
        bVar1 = pbVar6[6];
      }
      else {
        bVar1 = pbVar6[iVar5 + 1];
        pcVar3 = "%02x:";
      }
      iVar5 = iVar5 + 1;
      printf(pcVar3,(uint)bVar1);
    } while (iVar5 != 6);
    iVar5 = 0;
    do {
      uVar4 = (uint)pbVar6[7];
      if ((uVar4 & 7) != uVar4) {
        pcVar3 = "\t\t\t***Priority 8021p(%02x) Is Wrong \r\n";
        goto LAB_0056a4c4;
      }
      printf("\t\t\tPriority 8021p: %02x \r\n");
      uVar4 = (uint)pbVar6[8];
      if ((uVar4 & 0x3f) != uVar4) {
        pcVar3 = "\t\t\t***DSCP(%02x) Is Wrong \r\n";
        goto LAB_0056a4c4;
      }
      iVar5 = iVar5 + 1;
      printf("\t\t\tDSCP: %02x \r\n");
      pbVar6 = pbVar6 + 2;
    } while (iVar5 != 4);
    uVar2 = 0;
  }
  else {
    pcVar3 = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
LAB_0056a4c4:
    printf(pcVar3,uVar4);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

