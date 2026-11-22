// func _uac_wserv_igmp_white_list_to_ap @ 005e741c size=676

undefined4 _uac_wserv_igmp_white_list_to_ap(uint param_1)

{
  int iVar1;
  void *__s;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  byte local_308 [4];
  undefined4 local_304;
  undefined4 local_300;
  int local_2fc;
  undefined4 local_2f8;
  undefined1 auStack_2f0 [728];
  
  local_308[0] = 0;
  local_304 = 0;
  local_300 = 0;
  local_2fc = 0;
  local_2f8 = 0;
  memset(auStack_2f0,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2f0);
  if (iVar1 != 0) {
    uVar3 = 0xffffffff;
    if (g_wserv_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar3 = 0xffffffff;
      }
      else {
        printf("<wserv>[error]%s(): %d  -> get ap entry by ap_id[%d] error\r\n",
               "_uac_wserv_igmp_white_list_to_ap",0x18c7,param_1);
        uVar3 = 0xffffffff;
      }
    }
    goto LAB_005e7498;
  }
  __s = (void *)FUN_00408450(0x380,0x18cb);
  if (__s == (void *)0x0) {
    uVar3 = 0xffffffff;
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> malloc fail\r\n","_uac_wserv_igmp_white_list_to_ap",0x18cd)
      ;
      uVar3 = 0xffffffff;
    }
    goto LAB_005e7498;
  }
  memset(__s,0,0x380);
  iVar1 = uac_wservice_igmp_white_list_collect(__s,local_308);
  uVar3 = 0xffffffff;
  if (iVar1 == 0) {
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> ip_num = %d\r\n","_uac_wserv_igmp_white_list_to_ap",0x18d5,
             (uint)local_308[0]);
    }
    uVar3 = 0;
    if (local_308[0] != 0) {
      local_304 = 0;
      local_300 = 0;
      uVar3 = 0xffffffff;
      local_2fc = 0;
      local_2f8 = 0;
      iVar1 = serv_wtp_address_arg_init(&local_304);
      if (iVar1 == 0) {
        iVar1 = apmngr_db_get_addr_by_capacity(param_1 & 0xffff,&local_304,1,1,0x15f0000,1,0x2b);
        if (iVar1 == -1) {
          if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            __format = 
            "<wserv>[warning]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n";
            uVar2 = 0x18e3;
            goto LAB_005e75a0;
          }
        }
        else if (local_2fc == 0) {
          uVar3 = 0;
          if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            __format = "<wserv>[warning]%s(): %d  -> ap[%d] 0 == arg.wtp_cnt.\r\n";
            uVar2 = 0x18e8;
LAB_005e75a0:
            printf(__format,"_uac_wserv_igmp_white_list_to_ap",uVar2,param_1);
          }
        }
        else {
          uVar3 = 0;
          iVar1 = _uac_wserv_pkt_igmp_group_policy_send(&local_304,__s,local_308[0]);
          if (((iVar1 != 0) && (uVar3 = 0xffffffff, g_wserv_debug != 0)) &&
             (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            __format = 
            "<wserv>[debug]%s(): %d  -> Failed to send igmp group policy packet to ap(%d).\r\n";
            uVar2 = 0x18ef;
            goto LAB_005e75a0;
          }
        }
      }
    }
  }
  FUN_00407df0(__s);
LAB_005e7498:
  serv_wtp_address_arg_destroy(&local_304);
  return uVar3;
}

