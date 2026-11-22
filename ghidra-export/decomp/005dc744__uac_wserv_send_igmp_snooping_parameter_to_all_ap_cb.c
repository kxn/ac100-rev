// func _uac_wserv_send_igmp_snooping_parameter_to_all_ap_cb @ 005dc744 size=740

undefined4 _uac_wserv_send_igmp_snooping_parameter_to_all_ap_cb(int param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  char *__format;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined2 local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  if (param_2 == (undefined1 *)0x0) {
    return 1;
  }
  local_30 = *(undefined2 *)(param_1 + 0x44);
  local_2e = *(undefined2 *)(param_1 + 0x46);
  uVar2 = uac_wservice_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_30);
  if ((int)uVar2 < 0) {
    uVar6 = 1;
    if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005dc858;
    __format = "<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n";
    uVar5 = 0x694;
  }
  else {
    local_2c = 0;
    local_28 = 0;
    uVar6 = 1;
    local_24 = 0;
    local_20 = 0;
    iVar3 = serv_wtp_address_arg_init(&local_2c);
    if (iVar3 != 0) goto LAB_005dc858;
    if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> ap_id = %d\r\n",
             "_uac_wserv_send_igmp_snooping_parameter_to_all_ap_cb",0x69d,
             (uint)*(ushort *)(param_1 + 0x10));
    }
    iVar3 = apmngr_db_get_addr_by_capacity
                      (*(undefined2 *)(param_1 + 0x10),&local_2c,1,1,0x15f0000,1,0x2b);
    if (iVar3 == -1) {
      uVar6 = 1;
      if ((g_wserv_warning == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005dc858;
      uVar2 = (uint)*(ushort *)(param_1 + 0x10);
      __format = "<wserv>[warning]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n"
      ;
      uVar5 = 0x6a0;
    }
    else if (local_24 == 0) {
      uVar6 = 0;
      if ((g_wserv_warning == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005dc858;
      uVar2 = (uint)*(ushort *)(param_1 + 0x10);
      __format = "<wserv>[warning]%s(): %d  -> ap[%d] 0 == arg.wtp_cnt.\r\n";
      uVar5 = 0x6a5;
    }
    else {
      if (g_wserv_warning == 0) {
        uVar4 = param_2[5];
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          uVar4 = param_2[5];
        }
        else {
          printf("<wserv>[warning]%s(): %d  -> rd_cnt = %d\r\n",
                 "_uac_wserv_send_igmp_snooping_parameter_to_all_ap_cb",0x6a9,uVar2);
          uVar4 = param_2[5];
        }
      }
      iVar3 = _uac_wserv_pkt_igmp_snooping_config_send
                        (&local_2c,*param_2,param_2[1],param_2[3],uVar4,uVar2);
      if (iVar3 == 0) {
        iVar3 = apmngr_checksum_update(param_1,0);
        if (iVar3 == 0) {
          uVar1 = *(undefined2 *)(param_1 + 0x10);
          uVar6 = 0;
          uVar5 = apmngr_db_timer_md5_send_interval_default_get();
          iVar3 = apmngr_entry_timer_start(uVar1,1,uVar5);
          if (iVar3 == 0) goto LAB_005dc858;
        }
        uVar6 = 1;
        if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("<wserv>[debug]%s(): %d  -> update md5 failed.\r\n",
                 "_uac_wserv_send_igmp_snooping_parameter_to_all_ap_cb",0x6b1);
        }
        goto LAB_005dc858;
      }
      uVar6 = 1;
      if ((g_wserv_debug == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005dc858;
      uVar2 = (uint)*(ushort *)(param_1 + 0x10);
      __format = 
      "<wserv>[debug]%s(): %d  -> Failed to send igmp snooping config packet to ap(%d).\r\n";
      uVar5 = 0x6ac;
    }
  }
  printf(__format,"_uac_wserv_send_igmp_snooping_parameter_to_all_ap_cb",uVar5,uVar2);
LAB_005dc858:
  serv_wtp_address_arg_destroy(&local_2c);
  return uVar6;
}

