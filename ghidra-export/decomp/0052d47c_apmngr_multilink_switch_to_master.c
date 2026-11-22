// func apmngr_multilink_switch_to_master @ 0052d47c size=372

undefined4 apmngr_multilink_switch_to_master(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2e0 [72];
  undefined1 auStack_298 [528];
  uint local_88;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 auStack_2c [29];
  undefined1 local_f;
  
  memset(auStack_2e0,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e0);
  if ((((iVar1 == 0) &&
       (iVar1 = apmngr_pkt_config_update_request_pkt_send(auStack_2e0,0), iVar1 == 0)) &&
      (iVar1 = apmngr_pkt_aplog_config_pkt_send(param_1), iVar1 == 0)) &&
     (((iVar1 = apmngr_lag_config_edit(param_1,local_2f,local_2e,local_2d,auStack_2c), iVar1 == 0 &&
       (iVar1 = apmngr_pkt_telnet_config_pkt_send(param_1), iVar1 == 0)) &&
      (iVar1 = apmngr_region_code_send(param_1,local_f), iVar1 == 0)))) {
    iVar1 = apmngr_is_support_capacity(0x54);
    if (((iVar1 == 0) || (-1 < (int)(local_88 << 0xb))) && ((local_88 & 0x1000) != 0)) {
      iVar1 = apmngr_proxy_url_info_pkt_send(param_1);
      if (((iVar1 != 0) && (apmngr_warning_switch != '\0')) &&
         (iVar1 = is_target_debug_ap(auStack_298), iVar1 != 0)) {
        printf("[APMNGR_WARNING]%s()/%d send proxy_url_info_pkt failed!\n",
               "apmngr_multilink_switch_to_master",0xce2);
      }
    }
    uVar2 = 0;
    remove_standby_ap(auStack_298);
  }
  else {
    uVar2 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d switch to master failed\n","apmngr_multilink_switch_to_master",
             0xcd9);
    }
  }
  return uVar2;
}

