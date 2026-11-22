// func cw_80211_delete_wlan_dump @ 00564d8c size=204

undefined4 cw_80211_delete_wlan_dump(int param_1)

{
  char *__format;
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Delete WLAN \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Delete WLAN (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x \r\n",(uint)*pbVar1,(uint)pbVar1[1]);
  if (*pbVar1 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if (pbVar1[1] < 0x11) {
      printf("\t\t\tWlan ID: %d \r\n");
      return 0;
    }
    __format = "\t\t\t***WLAN ID(%d) Is Wrong \r\n";
  }
  else {
    __format = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(__format);
  return 0xffffffff;
}

