// func wsta_db_print_roam_entry @ 0063987c size=552

void wsta_db_print_roam_entry(int param_1)

{
  tm *__tp;
  char *pcVar1;
  char local_70 [92];
  
  local_70[0] = '\0';
  local_70[1] = '\0';
  local_70[2] = '\0';
  local_70[3] = '\0';
  local_70[4] = '\0';
  local_70[5] = '\0';
  local_70[6] = '\0';
  local_70[7] = '\0';
  local_70[8] = '\0';
  local_70[9] = '\0';
  local_70[10] = '\0';
  local_70[0xb] = '\0';
  local_70[0xc] = '\0';
  local_70[0xd] = '\0';
  local_70[0xe] = '\0';
  local_70[0xf] = '\0';
  local_70[0x10] = '\0';
  local_70[0x11] = '\0';
  local_70[0x12] = '\0';
  local_70[0x13] = '\0';
  if (((param_1 != 0) && (*(int *)(param_1 + 0x18) != 0)) && (*(char *)(param_1 + 0x34) != '\0')) {
    puts("#################################################################");
    printf("id       = %d\n",*(undefined4 *)(param_1 + 0x1c));
    printf("mac      = ");
    _wsta_db_mac_print(param_1 + 0x68);
    printf("ap_id    = %d,  ori_ap_id   = %d\n",*(undefined4 *)(param_1 + 0x20),
           *(undefined4 *)(param_1 + 0x28));
    printf("rd_id    = %d,  ori_rd_id   = %d\n",(uint)*(byte *)(param_1 + 0x24),
           (uint)*(byte *)(param_1 + 0x2c));
    printf("wlan_id  = %d,  ori_wlan_id = %d\n",(uint)*(byte *)(param_1 + 0x25),
           (uint)*(byte *)(param_1 + 0x2d));
    printf("vlan_id  = %d\n",(uint)*(ushort *)(param_1 + 0x2e));
    printf("rssi     = %d\n",(int)*(char *)(param_1 + 0x35));
    printf("roam     = %d\n",(uint)*(byte *)(param_1 + 0x34));
    pcVar1 = local_70 + 0x14;
    if (*(char *)(param_1 + 0x3c) == '\x01') {
      memset(pcVar1,0,0x40);
      FUN_00408190(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40),
                   *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                   *(undefined4 *)(param_1 + 0x4c),pcVar1,0x40,"---");
    }
    else {
      pcVar1 = "---";
    }
    printf("ip       = %s\n",pcVar1);
    pcVar1 = local_70 + 0x14;
    if (*(char *)(param_1 + 0x50) == '\x02') {
      memset(pcVar1,0,0x40);
      FUN_00408190(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
                   *(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c),
                   *(undefined4 *)(param_1 + 0x60),pcVar1,0x40,"---");
    }
    else {
      pcVar1 = "---";
    }
    printf("ipv6       = %s\n",pcVar1);
    printf("rssi_recv_time  = %u\n",*(undefined4 *)(param_1 + 0x38));
    __tp = gmtime((time_t *)(param_1 + 0x70));
    strftime(local_70,0x14,"%Y-%m-%d %H:%M:%S",__tp);
    printf("acs_time = %s\n",local_70);
  }
  return;
}

