// func cw_80211_station_qos_dump @ 00568a0c size=240

undefined4 cw_80211_station_qos_dump(int param_1)

{
  byte bVar1;
  char *__format;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Station Qos \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Station Qos (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar2 = 0;
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x \r\n",(uint)*pbVar3,(uint)pbVar3[1]);
  printf("\t\t\tMAC Address: ");
  do {
    __format = "%02x \r\n";
    if (iVar2 == 5) {
      bVar1 = pbVar3[5];
    }
    else {
      bVar1 = pbVar3[iVar2];
      __format = "%02x:";
    }
    iVar2 = iVar2 + 1;
    printf(__format,(uint)bVar1);
  } while (iVar2 != 6);
  printf("\t\t\t8021p: %04x \r\n",(uint)*(ushort *)(pbVar3 + 6));
  return 0;
}

