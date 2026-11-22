// func _uac_wserv_igmp_query_parameter_to_ap @ 005db644 size=524

undefined4 _uac_wserv_igmp_query_parameter_to_ap(uint param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_2f8;
  undefined4 local_2f4;
  int local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [16];
  ushort local_2d8;
  
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2e8);
  if (iVar1 == 0) {
    local_2f8 = 0;
    local_2f4 = 0;
    uVar3 = 0xffffffff;
    local_2f0 = 0;
    local_2ec = 0;
    iVar1 = serv_wtp_address_arg_init(&local_2f8);
    if (iVar1 != 0) goto LAB_005db6a8;
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> ap_id = %d\r\n","_uac_wserv_igmp_query_parameter_to_ap",
             0x13aa,(uint)local_2d8);
    }
    iVar1 = apmngr_db_get_addr_by_capacity(local_2d8,&local_2f8,1,1,0x15f0000,1,0x2b);
    if (iVar1 == -1) {
      uVar3 = 0xffffffff;
      if ((g_wserv_warning == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005db6a8;
      param_1 = (uint)local_2d8;
      __format = "<wserv>[warning]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n"
      ;
      uVar2 = 0x13ad;
    }
    else {
      if (local_2f0 != 0) {
        uVar3 = 0;
        iVar1 = _uac_wserv_pkt_igmp_query_config_send(&local_2f8,DAT_0074fe5e,DAT_0074fe60);
        if (((iVar1 != 0) && (uVar3 = 0xffffffff, g_wserv_debug != 0)) &&
           (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[debug]%s(): %d  -> Failed to send igmp query config packet to all ap.\r\n"
                 ,"_uac_wserv_igmp_query_parameter_to_ap",0x13b7);
        }
        goto LAB_005db6a8;
      }
      uVar3 = 0xffffffff;
      if ((g_wserv_warning == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005db6a8;
      param_1 = (uint)local_2d8;
      __format = "<wserv>[warning]%s(): %d  -> ap[%d] 0 == arg.wtp_cnt.\r\n";
      uVar2 = 0x13b2;
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005db6a8;
    __format = "<wserv>[error]%s(): %d  -> get ap entry by ap_id[%d] error\r\n";
    uVar2 = 0x13a1;
  }
  uVar3 = 0xffffffff;
  printf(__format,"_uac_wserv_igmp_query_parameter_to_ap",uVar2,param_1);
LAB_005db6a8:
  serv_wtp_address_arg_destroy(&local_2f8);
  return uVar3;
}

