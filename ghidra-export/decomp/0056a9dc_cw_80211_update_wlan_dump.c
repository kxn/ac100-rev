// func cw_80211_update_wlan_dump @ 0056a9dc size=952

undefined4 cw_80211_update_wlan_dump(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Update WLAN \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Type: IEEE 802.11 Update WLAN (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x%04x... \r\n",(uint)*pbVar2,(uint)pbVar2[1],
         (uint)*(ushort *)(pbVar2 + 2));
  if (*pbVar2 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if (pbVar2[1] < 0x11) {
      printf("\t\t\tWlan ID: %d \r\n");
      printf("\t\t\tCapability: 0x%04x \r\n",(uint)*(ushort *)(pbVar2 + 2));
      printf("\t\t\t\t%d... .... .... .... = ESS: %s \r\n",(uint)(*(ushort *)(pbVar2 + 2) >> 0xf),
             *(undefined4 *)(&UNK_006d5b40 + (uint)(*(ushort *)(pbVar2 + 2) >> 0xf) * 4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x11) >> 0x1f;
      printf("\t\t\t\t.%d.. .... .... .... = IBSS: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x12) >> 0x1f;
      printf("\t\t\t\t..%d. .... .... .... = CF-Pollable: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x13) >> 0x1f;
      printf("\t\t\t\t...%d .... .... .... = CF-Poll Request: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x14) >> 0x1f;
      printf("\t\t\t\t.... %d... .... .... = Privacy: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x15) >> 0x1f;
      printf("\t\t\t\t.... .%d.. .... .... = Short Preamble: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x16) >> 0x1f;
      printf("\t\t\t\t.... ..%d. .... .... = PBCC: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x17) >> 0x1f;
      printf("\t\t\t\t.... ...%d .... .... = Channek Agility: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x18) >> 0x1f;
      printf("\t\t\t\t.... .... %d... .... = Spectrum Management: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x19) >> 0x1f;
      printf("\t\t\t\t.... .... .%d.. .... = QoS: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x1a) >> 0x1f;
      printf("\t\t\t\t.... .... ..%d. .... = Short Slot Time: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x1b) >> 0x1f;
      printf("\t\t\t\t.... .... ...%d .... = APSD: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x1c) >> 0x1f;
      printf("\t\t\t\t.... .... .... %d... = Reserved: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x1d) >> 0x1f;
      printf("\t\t\t\t.... .... .... .%d.. = DSSS-OFDM: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      iVar3 = (int)((uint)*(ushort *)(pbVar2 + 2) << 0x1e) >> 0x1f;
      printf("\t\t\t\t.... .... .... ..%d. = Delayed Block ACK: %s \r\n",-iVar3,
             *(undefined4 *)(&UNK_006d5b40 + iVar3 * -4));
      printf("\t\t\t\t.... .... .... ...%d = Immediate Block ACK: %s \r\n",
             *(ushort *)(pbVar2 + 2) & 1,
             *(undefined4 *)(&UNK_006d5b40 + (*(ushort *)(pbVar2 + 2) & 1) * 4));
      printf("\t\t\tKey-Index: %d \r\n",(uint)pbVar2[4]);
      if (pbVar2[5] < 4) {
        printf("\t\t\tKey Status: %d \r\n");
        printf("\t\t\tKey Length: %d \r\n",(uint)*(ushort *)(pbVar2 + 6));
        if (*(short *)(pbVar2 + 6) == 0) {
          if (*(int *)(pbVar2 + 8) != 0) goto LAB_0056ad54;
          pcVar1 = "\t\t\tKey: <MISSING> \r";
        }
        else {
          if (*(int *)(pbVar2 + 8) == 0) {
LAB_0056ad54:
            puts("\t\t\t***Key Or Key-Length Is Wrong \r");
            return 0xffffffff;
          }
          printf("\t\t\tKey:");
          for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(pbVar2 + 6); iVar3 = iVar3 + 1) {
            printf("%02x",(uint)*(byte *)(*(int *)(pbVar2 + 8) + iVar3));
          }
          pcVar1 = "\r";
        }
        puts(pcVar1);
        return 0;
      }
      pcVar1 = "\t\t\t***Key Status(%d) Is WRong \r\n";
    }
    else {
      pcVar1 = "\t\t\t***Wlan ID(%d) Is Wrong \r\n";
    }
  }
  else {
    pcVar1 = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
  printf(pcVar1);
  return 0xffffffff;
}

