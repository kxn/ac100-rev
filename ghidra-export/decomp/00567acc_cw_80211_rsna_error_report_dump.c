// func cw_80211_rsna_error_report_dump @ 00567acc size=524

undefined4 cw_80211_rsna_error_report_dump(int param_1)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 RSNA Error Report \r\n",(uint)*(ushort *)(param_1 + 0xc)
         ,(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 RSNA Error Report (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar4 = 0;
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar3,(uint)pbVar3[1]);
  printf("\t\t\tClient Mac Address: ");
  do {
    pcVar2 = "%02x \r\n";
    if (iVar4 == 5) {
      bVar1 = pbVar3[5];
    }
    else {
      bVar1 = pbVar3[iVar4];
      pcVar2 = "%02x:";
    }
    iVar4 = iVar4 + 1;
    printf(pcVar2,(uint)bVar1);
  } while (iVar4 != 6);
  iVar4 = 0;
  printf("\t\t\tBSSID: ");
  do {
    pcVar2 = "%02x \r\n";
    if (iVar4 == 5) {
      bVar1 = pbVar3[0xb];
    }
    else {
      bVar1 = pbVar3[iVar4 + 6];
      pcVar2 = "%02x:";
    }
    iVar4 = iVar4 + 1;
    printf(pcVar2,(uint)bVar1);
  } while (iVar4 != 6);
  if (pbVar3[0xc] < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if (pbVar3[0xd] < 0x11) {
      pcVar2 = "\t\t\t***WLAN ID(%d) Is Wrong \r\n";
    }
    else {
      printf("\t\t\tWlan ID: %d \r\n");
      if (*(short *)(pbVar3 + 0xe) == 0) {
        printf("\t\t\tReserved: %d \r\n",0);
        printf("\t\t\tTKIP ICV Errors: %d \r\n",*(undefined4 *)(pbVar3 + 0x10));
        printf("\t\t\tTKIP Local MIC Failures: %d \r\n",*(undefined4 *)(pbVar3 + 0x14));
        printf("\t\t\tTKIP Remote MIC Failures: %d \r\n",*(undefined4 *)(pbVar3 + 0x18));
        printf("\t\t\tCCMP Replays: %d \r\n",*(undefined4 *)(pbVar3 + 0x1c));
        printf("\t\t\tCCMP Decrypt Errors: %d \r\n",*(undefined4 *)(pbVar3 + 0x20));
        printf("\t\t\tTKIP Replays: %d \r\n",*(undefined4 *)(pbVar3 + 0x24));
        return 0;
      }
      pcVar2 = "\t\t\t***Reserved(%d) Is Wrong \r\n";
    }
  }
  else {
    pcVar2 = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(pcVar2);
  return 0xffffffff;
}

