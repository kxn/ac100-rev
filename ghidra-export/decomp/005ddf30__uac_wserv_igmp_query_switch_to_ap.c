// func _uac_wserv_igmp_query_switch_to_ap @ 005ddf30 size=404

/* WARNING: Type propagation algorithm not settling */

void _uac_wserv_igmp_query_switch_to_ap(uint param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  uint local_18 [4];
  
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[0] = param_1;
  FUN_0051ad88(local_18 + 1);
  uac_wservice_for_each_entry_bind_ap(param_1,_uac_wserv_for_collect_igmp_switch_cb,local_18);
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  iVar1 = serv_wtp_address_arg_init(&local_28);
  if (iVar1 != 0) goto LAB_005ddf8c;
  iVar1 = apmngr_db_get_addr_by_capacity(param_1 & 0xffff,&local_28,1,1,0x15f0000,1,0x2b);
  if (iVar1 == 0) {
    if (local_20 == 0) {
      if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> ap[%d] 0 == arg.wtp_cnt.\r\n",
               "_uac_wserv_igmp_query_switch_to_ap",0x1351,param_1);
      }
      goto LAB_005ddf8c;
    }
    iVar1 = _uac_wserv_pkt_igmp_query_switch_send(&local_28,local_18);
    if (((iVar1 == 0) || (g_wserv_error == 0)) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_005ddf8c;
    __format = "<wserv>[debug]%s(): %d  -> Update to ap error\r\n";
    uVar2 = 0x1356;
  }
  else {
    if ((g_wserv_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005ddf8c;
    __format = "<wserv>[debug]%s(): %d  -> get addr from apmngr failed.\r\n";
    uVar2 = 0x134c;
  }
  printf(__format,"_uac_wserv_igmp_query_switch_to_ap",uVar2);
LAB_005ddf8c:
  serv_wtp_address_arg_destroy(&local_28);
  while (iVar1 = FUN_004081b0(local_18 + 1), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  }
  return;
}

