// func _uac_wserv_igmp_snooping_parameter_to_ap @ 005dbf20 size=688

undefined4 _uac_wserv_igmp_snooping_parameter_to_ap(uint param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 local_300;
  undefined2 local_2fe;
  undefined4 local_2fc;
  undefined4 local_2f8;
  int local_2f4;
  undefined4 local_2f0;
  undefined1 auStack_2e8 [16];
  ushort local_2d8;
  undefined4 local_2a8;
  undefined2 local_2a4;
  undefined2 local_2a2;
  undefined1 auStack_d0 [192];
  
  local_2fc = 0;
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2e8);
  if (iVar1 == 0) {
    local_300 = local_2a4;
    local_2fe = local_2a2;
    param_1 = uac_wservice_get_ap_radio_cnt(local_2a8,auStack_d0,&local_300);
    if ((int)param_1 < 0) {
      uVar3 = 0xffffffff;
      if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005dbf88;
      __format = "<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n";
      uVar2 = 0x1379;
    }
    else {
      local_2fc = 0;
      local_2f8 = 0;
      uVar3 = 0xffffffff;
      local_2f4 = 0;
      local_2f0 = 0;
      iVar1 = serv_wtp_address_arg_init(&local_2fc);
      if (iVar1 != 0) goto LAB_005dbf88;
      if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> ap_id = %d\r\n",
               "_uac_wserv_igmp_snooping_parameter_to_ap",0x1382,(uint)local_2d8);
      }
      iVar1 = apmngr_db_get_addr_by_capacity(local_2d8,&local_2fc,1,1,0x15f0000,1,0x2b);
      if (iVar1 == -1) {
        uVar3 = 0xffffffff;
        if ((g_wserv_warning == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005dbf88;
        param_1 = (uint)local_2d8;
        __format = 
        "<wserv>[warning]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n";
        uVar2 = 0x1385;
      }
      else if (local_2f4 == 0) {
        uVar3 = 0xffffffff;
        if ((g_wserv_warning == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005dbf88;
        param_1 = (uint)local_2d8;
        __format = "<wserv>[warning]%s(): %d  -> ap[%d] 0 == arg.wtp_cnt.\r\n";
        uVar2 = 0x138a;
      }
      else {
        if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> rd_cnt = %d\r\n",
                 "_uac_wserv_igmp_snooping_parameter_to_ap",0x138d,param_1);
        }
        uVar3 = 0;
        iVar1 = _uac_wserv_pkt_igmp_snooping_config_send
                          (&local_2fc,g_wserv_igmp_entry,DAT_0074fe59,(undefined1)DAT_0074fe5a,
                           (undefined1)DAT_0074fe5c,param_1);
        if (((iVar1 == 0) || (uVar3 = 0xffffffff, g_wserv_debug == 0)) ||
           (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005dbf88;
        param_1 = (uint)local_2d8;
        __format = 
        "<wserv>[debug]%s(): %d  -> Failed to send igmp snooping config packet to ap(%d).\r\n";
        uVar2 = 0x1390;
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005dbf88;
    __format = "<wserv>[error]%s(): %d  -> get ap entry by ap_id[%d] error\r\n";
    uVar2 = 0x136f;
  }
  uVar3 = 0xffffffff;
  printf(__format,"_uac_wserv_igmp_snooping_parameter_to_ap",uVar2,param_1);
LAB_005dbf88:
  serv_wtp_address_arg_destroy(&local_2fc);
  return uVar3;
}

