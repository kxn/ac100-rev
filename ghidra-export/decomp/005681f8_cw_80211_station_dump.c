// func cw_80211_station_dump @ 005681f8 size=508

undefined4 cw_80211_station_dump(int param_1)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Station \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Station (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%04x... \r\n",(uint)*pbVar3,(uint)*(ushort *)(pbVar3 + 2));
  if (*pbVar3 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    printf("\t\t\tAssociation ID: %d \r\n",(uint)*(ushort *)(pbVar3 + 2));
    if (pbVar3[4] != 0) {
      return 0xffffffff;
    }
    printf("\t\t\tFlags: %d \r\n",0);
    iVar4 = 0;
    printf("\t\t\tMAC Address: ");
    do {
      pcVar2 = "%02x \r\n";
      if (iVar4 == 5) {
        bVar1 = pbVar3[10];
      }
      else {
        bVar1 = pbVar3[iVar4 + 5];
        pcVar2 = "%02x:";
      }
      iVar4 = iVar4 + 1;
      printf(pcVar2,(uint)bVar1);
    } while (iVar4 != 6);
    printf("\t\t\tCapabilities: %04x \r\n",(uint)*(ushort *)(pbVar3 + 0xc));
    if (0x10 < pbVar3[0xe]) {
      printf("\t\t\tWlan ID: %d \r\n");
      if (((pbVar3[0xf] != 0) && (*(int *)(pbVar3 + 0x10) != 0)) &&
         (*(ushort *)(param_1 + 0xe) - 0xd == (uint)pbVar3[0xf])) {
        printf("\t\t\tSupported Rates: ");
        for (iVar4 = 0; iVar4 < (int)(uint)pbVar3[0xf]; iVar4 = iVar4 + 1) {
          printf("%02x",(uint)*(byte *)(*(int *)(pbVar3 + 0x10) + iVar4));
        }
        puts("\r");
        return 0;
      }
      puts("\t\t\t***Supported Rates Is Wrong \r");
      return 0xffffffff;
    }
    pcVar2 = "\t\t\t***WLAN ID(%d) Is Wrong \r\n";
  }
  else {
    pcVar2 = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(pcVar2);
  return 0xffffffff;
}

