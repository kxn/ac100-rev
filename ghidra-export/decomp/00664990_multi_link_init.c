// func multi_link_init @ 00664990 size=656

undefined4 multi_link_init(void)

{
  int iVar1;
  int iVar2;
  void *__s;
  char *__format;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 auStack_60 [12];
  char *local_54;
  undefined4 local_50;
  code *local_4c;
  code *local_48;
  
  memset(auStack_60,0,0x4c);
  FUN_0051ad88(&g_multi_link_reg_list);
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_sensor_max();
  g_multi_link_array = FUN_00408450(iVar1 + iVar2,0x2b6);
  if (g_multi_link_array != 0) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_sensor_max();
    __s = (void *)FUN_00408450(iVar1 + iVar2,700);
    g_multi_link_config_changed_array = __s;
    if (__s != (void *)0x0) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_sensor_max();
      memset(__s,1,iVar1 + iVar2);
      iVar1 = FUN_00408040(&g_multi_link_ac_name,0x40);
      if (iVar1 == 0) {
        iVar1 = multi_link_config_restore();
        if (iVar1 == 0) {
          local_54 = "Multi-Link";
          local_50 = 0x6e;
          local_4c = multi_link_entry_init;
          local_48 = multi_link_entry_init;
          iVar1 = apmngr_callback_register(auStack_60);
          if (iVar1 == 0) {
            iVar1 = FUN_004084d0("apmng_backup_link",2,_multi_link_jcs_global_set);
            if (iVar1 == 0) {
              iVar1 = serv_ent_mngr_register(1,0x6e,_multi_link_enter_run_cb);
              if (iVar1 == 0) {
                iVar1 = serv_msg_mngr_register(1,100,_multi_link_pkt_discover_or_join_req_listen);
                if ((iVar1 == -1) ||
                   (iVar1 = serv_msg_mngr_register
                                      (3,100,_multi_link_pkt_discover_or_join_req_listen),
                   iVar1 == -1)) {
                  if (multi_link_err_switch == '\0') {
                    return 0xffffffff;
                  }
                  __format = 
                  "[MULTI_LINK_ERROR]%s()/%d register callback to listen disc-req capwap message event failed.\n"
                  ;
                  pcVar3 = "multi_link_pkt_register";
                  uVar4 = 0x22c;
                }
                else {
                  iVar1 = serv_msg_mngr_register(9,100,_multi_link_pkt_wtp_evt_req_listen);
                  if (iVar1 != -1) {
                    apmngr_support_capacity_register(4);
                    apmngr_support_capacity_register(0x33);
                    udbg_help_register("multi_link","multi_link_debug_help()");
                    return 0;
                  }
                  if (multi_link_err_switch == '\0') {
                    return 0xffffffff;
                  }
                  __format = 
                  "[MULTI_LINK_ERROR]%s()/%d register callback to listen wtp-event-req capwap message event failed.\n"
                  ;
                  pcVar3 = "multi_link_pkt_register";
                  uVar4 = 0x231;
                }
              }
              else {
                if (multi_link_err_switch == '\0') {
                  return 0xffffffff;
                }
                __format = 
                "[MULTI_LINK_ERROR]%s()/%d register callback to listen Enter-Run Event.\n";
                pcVar3 = "multi_link_init";
                uVar4 = 0x2e2;
              }
            }
            else {
              if (multi_link_err_switch == '\0') {
                return 0xffffffff;
              }
              __format = "[MULTI_LINK_ERROR]%s()/%d Failed to register callback to jcs.\n";
              pcVar3 = "multi_link_init";
              uVar4 = 0x2db;
            }
            goto LAB_00664b08;
          }
        }
      }
      else if (multi_link_err_switch != '\0') {
        __format = "[MULTI_LINK_ERROR]%s()/%d get dev model failed.\n";
        pcVar3 = "multi_link_init";
        uVar4 = 0x2c5;
LAB_00664b08:
        printf(__format,pcVar3,uVar4);
        return 0xffffffff;
      }
    }
  }
  return 0xffffffff;
}

