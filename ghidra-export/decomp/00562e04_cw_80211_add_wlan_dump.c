// func cw_80211_add_wlan_dump @ 00562e04 size=1340

undefined4 cw_80211_add_wlan_dump(int param_1)

{
  ushort uVar1;
  byte *pbVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  
  pbVar6 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Add WLAN \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Type: IEEE 802.11 Add WLAN (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x%04x... \r\n",(uint)*pbVar6,(uint)pbVar6[1],
         (uint)*(ushort *)(pbVar6 + 2));
  uVar4 = (uint)*pbVar6;
  if (0x1f < uVar4) {
    pcVar3 = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
    goto LAB_005632dc;
  }
  printf("\t\t\tRadio ID: %d \r\n");
  uVar4 = (uint)pbVar6[1];
  if (0x10 < uVar4) {
    pcVar3 = "\t\t\t***Wlan ID(%d) Is Wrong \r\n";
    goto LAB_005632dc;
  }
  printf("\t\t\tWlan ID: %d \r\n");
  printf("\t\t\tCapability: 0x%04x \r\n",(uint)*(ushort *)(pbVar6 + 2));
  printf("\t\t\t\t%d... .... .... .... = ESS: %s \r\n",(uint)(*(ushort *)(pbVar6 + 2) >> 0xf),
         (&PTR_DAT_006d3980)[*(ushort *)(pbVar6 + 2) >> 0xf]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x11) >> 0x1f;
  printf("\t\t\t\t.%d.. .... .... .... = IBSS: %s \r\n",-iVar5,(&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x12) >> 0x1f;
  printf("\t\t\t\t..%d. .... .... .... = CF-Pollable: %s \r\n",-iVar5,(&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x13) >> 0x1f;
  printf("\t\t\t\t...%d .... .... .... = CF-Poll Request: %s \r\n",-iVar5,
         (&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x14) >> 0x1f;
  printf("\t\t\t\t.... %d... .... .... = Privacy: %s \r\n",-iVar5,(&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x15) >> 0x1f;
  printf("\t\t\t\t.... .%d.. .... .... = Short Preamble: %s \r\n",-iVar5,(&PTR_DAT_006d3980)[-iVar5]
        );
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x16) >> 0x1f;
  printf("\t\t\t\t.... ..%d. .... .... = PBCC: %s \r\n",-iVar5,(&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x17) >> 0x1f;
  printf("\t\t\t\t.... ...%d .... .... = Channek Agility: %s \r\n",-iVar5,
         (&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x18) >> 0x1f;
  printf("\t\t\t\t.... .... %d... .... = Spectrum Management: %s \r\n",-iVar5,
         (&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x19) >> 0x1f;
  printf("\t\t\t\t.... .... .%d.. .... = QoS: %s \r\n",-iVar5,(&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x1a) >> 0x1f;
  printf("\t\t\t\t.... .... ..%d. .... = Short Slot Time: %s \r\n",-iVar5,
         (&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x1b) >> 0x1f;
  printf("\t\t\t\t.... .... ...%d .... = APSD: %s \r\n",-iVar5,(&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x1c) >> 0x1f;
  printf("\t\t\t\t.... .... .... %d... = Reserved: %s \r\n",-iVar5,(&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x1d) >> 0x1f;
  printf("\t\t\t\t.... .... .... .%d.. = DSSS-OFDM: %s \r\n",-iVar5,(&PTR_DAT_006d3980)[-iVar5]);
  iVar5 = (int)((uint)*(ushort *)(pbVar6 + 2) << 0x1e) >> 0x1f;
  printf("\t\t\t\t.... .... .... ..%d. = Delayed Block ACK: %s \r\n",-iVar5,
         (&PTR_DAT_006d3980)[-iVar5]);
  printf("\t\t\t\t.... .... .... ...%d = Immediate Block ACK: %s \r\n",*(ushort *)(pbVar6 + 2) & 1,
         (&PTR_DAT_006d3980)[*(ushort *)(pbVar6 + 2) & 1]);
  printf("\t\t\tKey-Index: %d \r\n",(uint)pbVar6[4]);
  uVar4 = (uint)pbVar6[5];
  if (3 < uVar4) {
    pcVar3 = "\t\t\t***Key Status(%d) Is WRong \r\n";
    goto LAB_005632dc;
  }
  printf("\t\t\tKey Status: %d \r\n");
  printf("\t\t\tKey Length: %d \r\n",(uint)*(ushort *)(pbVar6 + 6));
  if (*(short *)(pbVar6 + 6) == 0) {
    if (*(int *)(pbVar6 + 8) != 0) {
LAB_005632cc:
      pcVar3 = "\t\t\t***Key Or Key-Length Is Wrong \r";
      goto LAB_005632f8;
    }
    puts("\t\t\tKey: <MISSING> \r");
  }
  else {
    if (*(int *)(pbVar6 + 8) == 0) goto LAB_005632cc;
    printf("\t\t\tKey: %s \r\n");
  }
  iVar5 = 0;
  printf("\t\t\tGroup TSC: ");
  pbVar2 = pbVar6;
  do {
    iVar5 = iVar5 + 1;
    printf("%02x",(uint)pbVar2[0xc]);
    pbVar2 = pbVar6 + iVar5;
  } while (iVar5 != 6);
  puts("\r");
  uVar4 = (uint)pbVar6[0x12];
  if (uVar4 < 4) {
    printf("\t\t\tQoS: %s (%d) \r\n",(&PTR_s_Best_Effort_006d3988)[uVar4]);
    uVar4 = (uint)pbVar6[0x13];
    if (uVar4 < 2) {
      printf("\t\t\tAuth Type: %s (%d) \r\n",(&PTR_s_Open_System_006d3998)[uVar4]);
      uVar4 = (uint)pbVar6[0x14];
      if (uVar4 < 2) {
        printf("\t\t\tMAC Mode: %s (%d) \r\n",(&PTR_s_Local_MAC_006d39a0)[uVar4]);
        uVar4 = (uint)pbVar6[0x15];
        if (uVar4 < 3) {
          printf("\t\t\tTunnel Mode: %s (%d) \r\n",(&PTR_s_Local_Bridging_006d39a8)[uVar4]);
          printf("\t\t\tSuppress SSID: %d \r\n",(uint)pbVar6[0x16]);
          if ((*(int *)(pbVar6 + 0x1c) != 0) && (*(short *)(pbVar6 + 0x18) != 0)) {
            printf("\t\t\tSSID Value: ");
            uVar1 = *(ushort *)(pbVar6 + 0x18);
            for (iVar5 = 0; iVar5 < (int)(uint)uVar1; iVar5 = iVar5 + 1) {
              printf("%02x",(uint)*(byte *)(*(int *)(pbVar6 + 0x1c) + iVar5));
              uVar1 = *(ushort *)(pbVar6 + 0x18);
            }
            puts("\r");
            printf("\t\t\tSSID: %s \r\n",*(undefined4 *)(pbVar6 + 0x1c));
            return 0;
          }
          pcVar3 = "\t\t\t***SSID Is NULL Or Length Is 0 \r";
LAB_005632f8:
          puts(pcVar3);
          return 0xffffffff;
        }
        pcVar3 = "\t\t\tTunnel Mode(%d) Is Wrong \r\n";
      }
      else {
        pcVar3 = "\t\t\t***MAC Mode(%d) Is Wrong \r\n";
      }
    }
    else {
      pcVar3 = "\t\t\t***Auth Type(%d) Is Wrong \r\n";
    }
  }
  else {
    pcVar3 = "\t\t\t***QoS(%d) Is Wrong \r\n";
  }
LAB_005632dc:
  printf(pcVar3,uVar4);
  return 0xffffffff;
}

