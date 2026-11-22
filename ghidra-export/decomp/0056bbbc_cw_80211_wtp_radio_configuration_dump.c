// func cw_80211_wtp_radio_configuration_dump @ 0056bbbc size=492

undefined4 cw_80211_wtp_radio_configuration_dump(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  
  pbVar4 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Wtp Radio Configuration \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Wtp Radio COnfiguration (%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  iVar5 = 0;
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x%02x%02x",(uint)*pbVar4,(uint)pbVar4[1],(uint)pbVar4[2],
         (uint)pbVar4[3]);
  pbVar2 = pbVar4;
  do {
    iVar5 = iVar5 + 1;
    printf("%02x",(uint)pbVar2[4]);
    pbVar2 = pbVar4 + iVar5;
  } while (iVar5 != 6);
  iVar5 = 0;
  printf("%04x",(uint)*(ushort *)(pbVar4 + 10));
  pbVar2 = pbVar4;
  do {
    iVar5 = iVar5 + 1;
    printf("%02x",(uint)pbVar2[0xc]);
    pbVar2 = pbVar4 + iVar5;
  } while (iVar5 != 4);
  puts("\r");
  if (*pbVar4 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if (pbVar4[1] < 2) {
      printf("\t\t\tShort Preamble: %d \r\n");
      iVar5 = 0;
      printf("\t\t\tNum Of Bssids: %d \r\n",(uint)pbVar4[2]);
      printf("\t\t\tDTIM period: %d\r\n",(uint)pbVar4[3]);
      printf("\t\t\tBSSID: ");
      do {
        if (iVar5 == 5) {
          bVar1 = pbVar4[9];
          pcVar3 = "%02x \r\n";
        }
        else {
          bVar1 = pbVar4[iVar5 + 4];
          pcVar3 = "%02x:";
        }
        iVar5 = iVar5 + 1;
        printf(pcVar3,(uint)bVar1);
      } while (iVar5 != 6);
      printf("\t\t\tBeacon Period: %d \r\n",(uint)*(ushort *)(pbVar4 + 10));
      printf("\t\t\tCountry String: %s \r\n",pbVar4 + 0xc);
      return 0;
    }
    pcVar3 = "\t\t\tShort Preamble(%d) Is Wrong \r\n";
  }
  else {
    pcVar3 = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(pcVar3);
  return 0xffffffff;
}

