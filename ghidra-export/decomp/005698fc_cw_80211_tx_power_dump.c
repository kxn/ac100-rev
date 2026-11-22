// func cw_80211_tx_power_dump @ 005698fc size=224

undefined4 cw_80211_tx_power_dump(int param_1)

{
  char *__format;
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Tx Power \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Tx Power (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x%04x \r\n",(uint)*pbVar1,(uint)pbVar1[1],
         (uint)*(ushort *)(pbVar1 + 2));
  if (*pbVar1 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if (pbVar1[1] == 0) {
      printf("\t\t\tReserved: %d \r\n",0);
      printf("\t\t\tCurrent Tx Power: %d \r\n",(uint)*(ushort *)(pbVar1 + 2));
      return 0;
    }
    __format = "\t\t\tReserved(%d) Is Wrong \r\n";
  }
  else {
    __format = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(__format);
  return 0xffffffff;
}

