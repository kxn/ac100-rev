// func cw_80211_wtp_qos_dump @ 0056b41c size=452

undefined4 cw_80211_wtp_qos_dump(int param_1)

{
  char *__format;
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Delete WLAN \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Delete WLAN (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar2,(uint)pbVar2[1]);
  uVar1 = (uint)*pbVar2;
  if (uVar1 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    uVar1 = (uint)pbVar2[1];
    if ((uVar1 & 0x1f) == uVar1) {
      printf("\t\t\tTagging Policy: %02x \r\n");
      puts("\t\t\tSubElement: \r");
      iVar3 = 0;
      while( true ) {
        printf("\t\t\t\tQueue Depth: %d \r\n",(uint)pbVar2[2]);
        printf("\t\t\t\tCWMin: %d \r\n",(uint)*(ushort *)(pbVar2 + 4));
        printf("\t\t\t\tCWMax: %d \r\n",(uint)*(ushort *)(pbVar2 + 6));
        printf("\t\t\t\tAIFS: %d \r\n",(uint)pbVar2[8]);
        uVar1 = (uint)pbVar2[9];
        if ((uVar1 & 7) != uVar1) {
          __format = "\t\t\t\t***Priority 8021p(%02x) Is Wrong \r\n";
          goto LAB_0056b5b8;
        }
        printf("\t\t\t\tPriority 8021p: %02x \r\n");
        uVar1 = (uint)pbVar2[10];
        if ((uVar1 & 0x3f) != uVar1) break;
        printf("\t\t\t\tDSCP: %02x \r\n");
        iVar3 = iVar3 + 1;
        pbVar2 = pbVar2 + 10;
        if (iVar3 == 4) {
          return 0;
        }
      }
      __format = "\t\t\t\t***DSCP(%02x) Is Wrong \r\n";
    }
    else {
      __format = "\t\t\t***Tagging Policy(%02x) Is Wrong \r\n";
    }
  }
  else {
    __format = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
LAB_0056b5b8:
  printf(__format,uVar1);
  return 0xffffffff;
}

