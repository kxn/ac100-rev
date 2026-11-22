// func cloud_mngt_stats_db_ssid_print @ 0048e320 size=384

void cloud_mngt_stats_db_ssid_print(int param_1)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    for (uVar4 = 1; uVar1 = rdmngr_profile_get_max_wlan_per_rd(), uVar4 <= uVar1; uVar4 = uVar4 + 1)
    {
      printf("\t\t\twlan id: %u\r\n",uVar4);
      pcVar2 = "active";
      if ((*(byte *)(param_1 + 8) & 1) == 0) {
        pcVar2 = "inactive";
      }
      if ((*(byte *)(param_1 + 8) & 2) == 0) {
        pcVar3 = "not-ready";
      }
      else {
        pcVar3 = "ready";
      }
      printf("\t\t\t\tstate: %s, %s\r\n",pcVar2,pcVar3);
      printf("\t\t\t\tbssid: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*(byte *)(param_1 + 9),
             (uint)*(byte *)(param_1 + 10),(uint)*(byte *)(param_1 + 0xb),
             (uint)*(byte *)(param_1 + 0xc),(uint)*(byte *)(param_1 + 0xd),
             (uint)*(byte *)(param_1 + 0xe));
      printf("\t\t\t\tcapabilities: 0x%04x \r\n",(uint)*(ushort *)(param_1 + 0x10));
      printf("\t\t\t\tpacket rtx rate: %u%% \r\n",(uint)*(byte *)(param_1 + 0x12));
      printf("\t\t\t\tpacket loss rate: %u%% \r\n",(uint)*(byte *)(param_1 + 0x13));
      printf("\t\t\t\tupstream rate: %u Kbps\r\n",*(undefined4 *)(param_1 + 0x14));
      printf("\t\t\t\tdownstream rate: %u Kbps\r\n",*(undefined4 *)(param_1 + 0x18));
      printf("\t\t\t\tupstream load: %llu KBytes\r\n");
      param_1 = param_1 + 0x100;
      printf("\t\t\t\tdownstream load: %llu KBytes\r\n");
    }
  }
  return;
}

