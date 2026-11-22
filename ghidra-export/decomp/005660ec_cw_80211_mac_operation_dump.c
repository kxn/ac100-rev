// func cw_80211_mac_operation_dump @ 005660ec size=344

undefined4 cw_80211_mac_operation_dump(int param_1)

{
  char *__format;
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 MAC Operation \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 MAC Operation (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x%04x%02x%02x%04x%08x%08x \r\n",(uint)*pbVar1,(uint)pbVar1[1],
         (uint)*(ushort *)(pbVar1 + 2),(uint)pbVar1[4],(uint)pbVar1[5],(uint)*(ushort *)(pbVar1 + 6)
         ,*(undefined4 *)(pbVar1 + 8),*(undefined4 *)(pbVar1 + 0xc));
  if (*pbVar1 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if (pbVar1[1] == 0) {
      printf("\t\t\tReserved: %d \r\n",0);
      printf("\t\t\tRTS Threshold: %d \r\n",(uint)*(ushort *)(pbVar1 + 2));
      printf("\t\t\tShort Retry: %d \r\n",(uint)pbVar1[4]);
      printf("\t\t\tLong Retry: %d \r\n",(uint)pbVar1[5]);
      printf("\t\t\tFragmentation Threshold: %d \r\n",(uint)*(ushort *)(pbVar1 + 6));
      printf("\t\t\tTx MSDU Lifetime: %d \r\n",*(undefined4 *)(pbVar1 + 8));
      printf("\t\t\tRx MSDU Lifetime: %d \r\n",*(undefined4 *)(pbVar1 + 0xc));
      return 0;
    }
    __format = "\t\t\t***Reserved(%d) Isn\'t Zeroed \r\n";
  }
  else {
    __format = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(__format);
  return 0xffffffff;
}

