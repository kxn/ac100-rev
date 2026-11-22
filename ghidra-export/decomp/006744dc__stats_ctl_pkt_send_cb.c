// func _stats_ctl_pkt_send_cb @ 006744dc size=380

undefined4 _stats_ctl_pkt_send_cb(undefined2 param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_2f8;
  undefined4 local_2f4;
  int local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == -1) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar2 = "[STATISTICS_ERROR]%s()/%d get ap entry by id failed.\n";
    uVar4 = 500;
LAB_00674624:
    printf(pcVar2,"_stats_ctl_pkt_send_cb",uVar4);
    return 0xffffffff;
  }
  iVar1 = serv_wtp_address_arg_init(&local_2f8);
  if (iVar1 == -1) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar2 = "[STATISTICS_ERROR]%s()/%d serv arg init failed\n";
    uVar4 = 0x1fb;
    goto LAB_00674624;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(local_2d8,&local_2f8,1,1,0x15f0000,1,0x18);
  if ((iVar1 == -1) || (local_2f0 == 0)) {
    uVar4 = 0;
    if (stats_debug_switch == '\0') goto LAB_0067458c;
    pcVar2 = "[STATISTICS_DEBUG]%s()/%d no AP need to send configure\n";
    uVar3 = 0x202;
  }
  else {
    uVar4 = 0;
    iVar1 = _stats_ctl_packet_send(&local_2f8);
    if ((iVar1 != -1) || (uVar4 = 0xffffffff, stats_err_switch == '\0')) goto LAB_0067458c;
    pcVar2 = "[STATISTICS_ERROR]%s()/%d send packet to AP failed\n";
    uVar3 = 0x209;
  }
  printf(pcVar2,"_stats_ctl_pkt_send_cb",uVar3);
LAB_0067458c:
  serv_wtp_address_arg_destroy(&local_2f8);
  return uVar4;
}

