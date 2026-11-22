// func cw_80211_information_element_dump @ 005659ac size=376

undefined4 cw_80211_information_element_dump(int param_1)

{
  char *__format;
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Information Element \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Information Element (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar2,(uint)pbVar2[1]);
  uVar1 = (uint)*pbVar2;
  if (uVar1 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    uVar1 = (uint)pbVar2[1];
    if (uVar1 < 0x11) {
      __format = "\t\t\t***WLAN ID(%d) Is Wrong \r\n";
    }
    else {
      printf("\t\t\tWlan ID: %d \r\n");
      uVar1 = (uint)pbVar2[2];
      if ((uVar1 & 0xc0) == uVar1) {
        printf("\t\t\tFlags: %02x \r\n");
        if (((uint)*(ushort *)(pbVar2 + 4) == *(ushort *)(param_1 + 0xe) - 3) &&
           (*(int *)(pbVar2 + 8) != 0)) {
          printf("\t\t\tInformation Element: ");
          for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(pbVar2 + 4); iVar3 = iVar3 + 1) {
            printf("%02x",(uint)*(byte *)(*(int *)(pbVar2 + 8) + iVar3));
          }
          puts("\r");
          return 0;
        }
        puts("\t\t\t***Information Element Is Wrong \r");
        return 0xffffffff;
      }
      __format = "\t\t\t***Flags(%02x) Is Wrong \r\n";
    }
  }
  else {
    __format = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(__format,uVar1);
  return 0xffffffff;
}

