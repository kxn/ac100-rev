// func cw_80211_tx_power_level_dump @ 00569dbc size=328

undefined4 cw_80211_tx_power_level_dump(int param_1)

{
  ushort *puVar1;
  byte bVar2;
  char *__format;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  
  pbVar5 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 TX Power Level \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 TX Power Level (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar5,(uint)pbVar5[1]);
  if (*pbVar5 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    uVar3 = (uint)pbVar5[1];
    if (*(ushort *)(param_1 + 0xe) - 2 == uVar3 << 1) {
      if (uVar3 == 0) {
        __format = "\t\t\t***Num Levels(%d) Is Wrong \r\n";
      }
      else {
        if (uVar3 < 9) {
          printf("\t\t\tNum Levels: %d \r\n");
          printf("\t\t\tPower Level: ");
          bVar2 = pbVar5[1];
          pbVar4 = pbVar5;
          for (iVar6 = 0; iVar6 < (int)(uint)bVar2; iVar6 = iVar6 + 1) {
            puVar1 = (ushort *)(pbVar4 + 2);
            pbVar4 = pbVar4 + 2;
            printf("%04x",(uint)*puVar1);
            bVar2 = pbVar5[1];
          }
          puts("\r");
          return 0;
        }
        __format = "\t\t\t***Num Levels(%d) Is Wrong \r\n";
      }
    }
    else {
      __format = "\t\t\t***Num Levels(%d) Is Wrong \r\n";
    }
  }
  else {
    __format = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(__format);
  return 0xffffffff;
}

