// func cw_80211_assigned_wtp_bssid_dump @ 0056487c size=308

undefined4 cw_80211_assigned_wtp_bssid_dump(int param_1)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Assigned WTP BSSID \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Assigned WTP BSSID (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar3,(uint)pbVar3[1]);
  if (*pbVar3 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if (0x10 < pbVar3[1]) {
      printf("\t\t\tWlan ID: %d \r\n");
      iVar4 = 0;
      printf("\t\t\tBSSID: ");
      do {
        pcVar2 = "%02x \r\n";
        if (iVar4 == 5) {
          bVar1 = pbVar3[7];
        }
        else {
          bVar1 = pbVar3[iVar4 + 2];
          pcVar2 = "%02x:";
        }
        iVar4 = iVar4 + 1;
        printf(pcVar2,(uint)bVar1);
      } while (iVar4 != 6);
      return 0;
    }
    pcVar2 = "\t\t\t***WLAN ID(%d) Is Wrong \r\n";
  }
  else {
    pcVar2 = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(pcVar2);
  return 0xffffffff;
}

