// func _uac_wserv_send_igmp_white_list_to_all_ap_cb @ 005d5ff8 size=468

undefined4 _uac_wserv_send_igmp_white_list_to_all_ap_cb(int param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  if (param_2 == (undefined4 *)0x0) {
    return 1;
  }
  local_20 = 0;
  local_1c = 0;
  uVar4 = 1;
  local_18 = 0;
  local_14 = 0;
  iVar2 = serv_wtp_address_arg_init(&local_20);
  if (iVar2 != 0) goto LAB_005d6040;
  iVar2 = apmngr_db_get_addr_by_capacity
                    (*(undefined2 *)(param_1 + 0x10),&local_20,1,1,0x15f0000,1,0x2b);
  if (iVar2 == -1) {
    if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005d6040;
    __format = "<wserv>[warning]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n";
    uVar3 = 0x1886;
  }
  else if (local_18 == 0) {
    uVar4 = 0;
    if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005d6040;
    __format = "<wserv>[warning]%s(): %d  -> ap[%d] 0 == arg.wtp_cnt.\r\n";
    uVar3 = 0x188b;
  }
  else {
    iVar2 = _uac_wserv_pkt_igmp_group_policy_send(&local_20,*param_2,*(undefined1 *)(param_2 + 1));
    if (iVar2 == 0) {
      iVar2 = apmngr_checksum_update(param_1,0);
      if (iVar2 == 0) {
        uVar1 = *(undefined2 *)(param_1 + 0x10);
        uVar4 = 0;
        uVar3 = apmngr_db_timer_md5_send_interval_default_get();
        iVar2 = apmngr_entry_timer_start(uVar1,1,uVar3);
        if (iVar2 == 0) goto LAB_005d6040;
      }
      uVar4 = 1;
      if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> update md5 failed.\r\n",
               "_uac_wserv_send_igmp_white_list_to_all_ap_cb",0x1897);
      }
      goto LAB_005d6040;
    }
    if ((g_wserv_debug == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005d6040;
    __format = "<wserv>[debug]%s(): %d  -> Failed to send igmp group policy packet to ap(%d).\r\n";
    uVar3 = 0x1892;
  }
  printf(__format,"_uac_wserv_send_igmp_white_list_to_all_ap_cb",uVar3,
         (uint)*(ushort *)(param_1 + 0x10));
LAB_005d6040:
  serv_wtp_address_arg_destroy(&local_20);
  return uVar4;
}

