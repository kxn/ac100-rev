// func cw_80211_supported_rates_dump @ 00569458 size=276

undefined4 cw_80211_supported_rates_dump(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Supported Rates \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Supported Rates (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x... \r\n",(uint)*pbVar3);
  if (*pbVar3 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if (*(ushort *)(param_1 + 0xe) - 1 == (uint)pbVar3[1]) {
      printf("\t\t\tSupported Rates: ");
      for (iVar2 = 0; iVar2 < (int)(uint)pbVar3[1]; iVar2 = iVar2 + 1) {
        printf("%02x",(uint)pbVar3[iVar2 + 2]);
      }
      puts("\r");
      uVar1 = 0;
    }
    else {
      puts("\t\t\t***Supported Rates Is Wrong \r");
      uVar1 = 0xffffffff;
    }
  }
  else {
    printf("\t\t\t***Radio ID(%d) Is Wrong \r\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

