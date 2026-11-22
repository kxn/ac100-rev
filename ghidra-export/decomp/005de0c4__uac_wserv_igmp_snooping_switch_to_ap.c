// func _uac_wserv_igmp_snooping_switch_to_ap @ 005de0c4 size=488

/* WARNING: Type propagation algorithm not settling */

void _uac_wserv_igmp_snooping_switch_to_ap(uint param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  uint local_20 [5];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> ap_id = %d\r\n","_uac_wserv_igmp_snooping_switch_to_ap",
           0x1310,param_1);
  }
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[0] = param_1;
  FUN_0051ad88(local_20 + 1);
  uac_wservice_for_each_entry_bind_ap(param_1,_uac_wserv_for_collect_igmp_switch_cb,local_20);
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_30);
  if (iVar1 != 0) goto LAB_005de140;
  iVar1 = apmngr_db_get_addr_by_capacity(param_1 & 0xffff,&local_30,1,1,0x15f0000,1,0x2b);
  if (iVar1 == 0) {
    if (local_28 == 0) {
      if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> ap[%d] 0 == arg.wtp_cnt.\r\n",
               "_uac_wserv_igmp_snooping_switch_to_ap",0x1324,param_1);
      }
      goto LAB_005de140;
    }
    iVar1 = _uac_wserv_pkt_igmp_snooping_switch_send(&local_30,local_20);
    if (((iVar1 == 0) || (g_wserv_error == 0)) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_005de140;
    __format = "<wserv>[debug]%s(): %d  -> Update to ap error\r\n";
    uVar2 = 0x1329;
  }
  else {
    if ((g_wserv_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005de140;
    __format = "<wserv>[debug]%s(): %d  -> get addr from apmngr failed.\r\n";
    uVar2 = 0x131f;
  }
  printf(__format,"_uac_wserv_igmp_snooping_switch_to_ap",uVar2);
LAB_005de140:
  serv_wtp_address_arg_destroy(&local_30);
  while (iVar1 = FUN_004081b0(local_20 + 1), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  }
  return;
}

