// func cw_80211_station_session_key_dump @ 00568d8c size=480

undefined4 cw_80211_station_session_key_dump(int param_1)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  char *__format;
  byte *pbVar5;
  int iVar6;
  
  iVar6 = 0;
  pbVar5 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Station Session Key \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Station Session Key (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar5,(uint)pbVar5[1]);
  printf("\t\t\tMAC Address: ");
  do {
    __format = "%02x \r\n";
    if (iVar6 == 5) {
      bVar1 = pbVar5[5];
    }
    else {
      bVar1 = pbVar5[iVar6];
      __format = "%02x:";
    }
    iVar6 = iVar6 + 1;
    printf(__format,(uint)bVar1);
  } while (iVar6 != 6);
  iVar6 = 0;
  printf("\t\t\tPairwise TSC: ");
  pbVar3 = pbVar5;
  do {
    iVar6 = iVar6 + 1;
    printf("%02x",(uint)pbVar3[8]);
    pbVar3 = pbVar5 + iVar6;
  } while (iVar6 != 6);
  iVar6 = 0;
  puts("\r");
  printf("\t\t\tPairwise RSC: ");
  pbVar3 = pbVar5;
  do {
    iVar6 = iVar6 + 1;
    printf("%02x",(uint)pbVar3[0xe]);
    pbVar3 = pbVar5 + iVar6;
  } while (iVar6 != 6);
  puts("\r");
  if ((*(ushort *)(pbVar5 + 0x14) - 0x14 == (uint)*(ushort *)(param_1 + 0xe)) &&
     (*(int *)(pbVar5 + 0x18) != 0)) {
    printf("\t\t\tKey: ");
    uVar2 = *(ushort *)(pbVar5 + 0x14);
    for (iVar6 = 0; iVar6 < (int)(uint)uVar2; iVar6 = iVar6 + 1) {
      printf("%02x",(uint)*(byte *)(*(int *)(pbVar5 + 0x18) + iVar6));
      uVar2 = *(ushort *)(pbVar5 + 0x14);
    }
    puts("\r");
    uVar4 = 0;
  }
  else {
    puts("\t\t\t***Key Is Wrong \r");
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

