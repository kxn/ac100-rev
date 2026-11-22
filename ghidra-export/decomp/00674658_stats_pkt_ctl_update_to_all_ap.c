// func stats_pkt_ctl_update_to_all_ap @ 00674658 size=1

undefined4 stats_pkt_ctl_update_to_all_ap(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  
  uStack_20 = 0;
  uStack_1c = 0;
  iStack_18 = 0;
  uStack_14 = 0;
  iVar1 = serv_wtp_address_arg_init(&uStack_20);
  if (iVar1 == -1) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_ERROR]%s()/%d serv arg init failed\n","stats_pkt_ctl_update_to_all_ap",0x232
          );
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_all_addr_by_capacity(&uStack_20,1,1,0x15f0000,1,0x18);
  if ((iVar1 == -1) || (iStack_18 == 0)) {
    uVar3 = 0;
    if (stats_debug_switch == '\0') goto code_r0x006746d0;
    __format = "[STATISTICS_DEBUG]%s()/%d no AP need to send configure\n";
    uVar2 = 0x239;
  }
  else {
    uVar3 = 0;
    iVar1 = _stats_ctl_packet_send(&uStack_20);
    if ((iVar1 != -1) || (uVar3 = 0xffffffff, stats_err_switch == '\0')) goto code_r0x006746d0;
    __format = "[STATISTICS_ERROR]%s()/%d send packet to AP failed\n";
    uVar2 = 0x23f;
  }
  printf(__format,"stats_pkt_ctl_update_to_all_ap",uVar2);
code_r0x006746d0:
  serv_wtp_address_arg_destroy(&uStack_20);
  return uVar3;
}

