// func cw_80211_wtp_radio_information_dump @ 0056c72c size=340

undefined4 cw_80211_wtp_radio_information_dump(int param_1)

{
  int iVar1;
  char *__format;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 WTP Radio Information \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 WTP Radio Information (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc))
  ;
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%08x \r\n",(uint)*pbVar2,*(undefined4 *)(pbVar2 + 4));
  if (*pbVar2 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if ((*(uint *)(pbVar2 + 4) & 0x3f) == *(uint *)(pbVar2 + 4)) {
      puts("\t\t\tRadio Type Reserved: 000000 \r");
      iVar1 = (*(int *)(pbVar2 + 4) << 0x1c) >> 0x1f;
      printf("\t\t\t%d... = Radio Type 802.11n: %s \r\n",-iVar1,
             *(undefined4 *)(&UNK_006d6300 + iVar1 * -4));
      iVar1 = (*(int *)(pbVar2 + 4) << 0x1d) >> 0x1f;
      printf("\t\t\t.%d.. = Radio Type 802.11g: %s \r\n",-iVar1,
             *(undefined4 *)(&UNK_006d6300 + iVar1 * -4));
      iVar1 = (*(int *)(pbVar2 + 4) << 0x1e) >> 0x1f;
      printf("\t\t\t..%d. = Radio Type 802.11a: %s \r\n",-iVar1,
             *(undefined4 *)(&UNK_006d6300 + iVar1 * -4));
      printf("\t\t\t...%d = Radio Type 802.11b: %s \r\n",*(uint *)(pbVar2 + 4) & 1,
             *(undefined4 *)(&UNK_006d6300 + (*(uint *)(pbVar2 + 4) & 1) * 4));
      return 0;
    }
    __format = "\t\t\t***Radio Type(%08x) Is Wrong \r\n";
  }
  else {
    __format = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(__format);
  return 0xffffffff;
}

