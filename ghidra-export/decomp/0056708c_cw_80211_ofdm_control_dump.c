// func cw_80211_ofdm_control_dump @ 0056708c size=276

undefined4 cw_80211_ofdm_control_dump(int param_1)

{
  char *__format;
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 OFMD Control \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 OFMD Control (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar2,(uint)pbVar2[1]);
  uVar1 = (uint)*pbVar2;
  if (uVar1 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    uVar1 = (uint)pbVar2[1];
    if (uVar1 == 0) {
      printf("\t\t\tReserved: %d \r\n",0);
      printf("\t\t\tCurrrent Channel: %d \r\n",(uint)pbVar2[2]);
      uVar1 = (uint)pbVar2[3];
      if ((uVar1 & 0x7f) == uVar1) {
        printf("\t\t\tBand Support: %d \r\n");
        printf("\t\t\tTI Threshold: %d \r\n",*(undefined4 *)(pbVar2 + 4));
        return 0;
      }
      __format = "\t\t\t***Band Support(%d) Is Wrong \r\n";
    }
    else {
      __format = "\t\t\t***Reserved(%d) Is Wrong \r\n";
    }
  }
  else {
    __format = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(__format,uVar1);
  return 0xffffffff;
}

