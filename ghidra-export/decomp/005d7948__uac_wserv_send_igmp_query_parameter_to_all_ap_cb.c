// func _uac_wserv_send_igmp_query_parameter_to_all_ap_cb @ 005d7948 size=540

undefined4 _uac_wserv_send_igmp_query_parameter_to_all_ap_cb(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  
  if (param_2 == 0) {
    return 1;
  }
  local_28 = 0;
  local_24 = 0;
  uVar5 = 1;
  local_20 = 0;
  local_1c = 0;
  iVar2 = serv_wtp_address_arg_init(&local_28);
  if (iVar2 == 0) {
    if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> ap_id = %d\r\n",
             "_uac_wserv_send_igmp_query_parameter_to_all_ap_cb",0x6e3,
             (uint)*(ushort *)(param_1 + 0x10));
    }
    iVar2 = apmngr_db_get_addr_by_capacity
                      (*(undefined2 *)(param_1 + 0x10),&local_28,1,1,0x15f0000,1,0x2b);
    if (iVar2 == -1) {
      uVar5 = 1;
      if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005d79ec;
      pcVar3 = "<wserv>[warning]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n";
      uVar4 = 0x6e6;
    }
    else {
      if (local_20 != 0) {
        iVar2 = _uac_wserv_pkt_igmp_query_config_send
                          (&local_28,*(undefined2 *)(param_2 + 6),*(undefined1 *)(param_2 + 8));
        if (iVar2 == 0) {
          iVar2 = apmngr_checksum_update(param_1,0);
          if (iVar2 == 0) {
            uVar1 = *(undefined2 *)(param_1 + 0x10);
            uVar5 = 0;
            uVar4 = apmngr_db_timer_md5_send_interval_default_get();
            iVar2 = apmngr_entry_timer_start(uVar1,1,uVar4);
            if (iVar2 == 0) goto LAB_005d79ec;
          }
          uVar5 = 1;
          if ((g_wserv_debug == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005d79ec;
          pcVar3 = "<wserv>[debug]%s(): %d  -> update md5 failed.\r\n";
          uVar4 = 0x6f7;
        }
        else {
          uVar5 = 1;
          if ((g_wserv_debug == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005d79ec;
          pcVar3 = 
          "<wserv>[debug]%s(): %d  -> Failed to send igmp query config packet to all ap.\r\n";
          uVar4 = 0x6f2;
        }
        uVar5 = 1;
        printf(pcVar3,"_uac_wserv_send_igmp_query_parameter_to_all_ap_cb",uVar4);
        goto LAB_005d79ec;
      }
      uVar5 = 0;
      if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005d79ec;
      pcVar3 = "<wserv>[warning]%s(): %d  -> ap[%d] 0 == arg.wtp_cnt.\r\n";
      uVar4 = 0x6eb;
    }
    printf(pcVar3,"_uac_wserv_send_igmp_query_parameter_to_all_ap_cb",uVar4,
           (uint)*(ushort *)(param_1 + 0x10));
  }
LAB_005d79ec:
  serv_wtp_address_arg_destroy(&local_28);
  return uVar5;
}

