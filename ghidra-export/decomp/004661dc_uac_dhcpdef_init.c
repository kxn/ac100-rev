// func uac_dhcpdef_init @ 004661dc size=836

undefined4 uac_dhcpdef_init(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *local_70;
  undefined4 local_6c;
  code *local_68;
  undefined4 local_64;
  undefined1 auStack_60 [12];
  char *local_54;
  undefined4 local_50;
  code *local_4c;
  code *local_48;
  code *local_44;
  code *local_40;
  code *local_34;
  code *local_30;
  code *local_28;
  
  iVar1 = dhcpdef_sqlite_init();
  if (iVar1 == 0) {
    iVar1 = dhcpdef_db_init();
    if (iVar1 == 0) {
      iVar1 = _uac_dhcpdef_recover_firm_aps();
      if (iVar1 == 0) {
        FUN_004084d0("dhcpdef_svr",0,_uac_dhcpdef_jcs_svr_add);
        FUN_004084d0("dhcpdef_svr",1,_uac_dhcpdef_jcs_svr_del);
        FUN_004084d0("dhcpdef_svr",2,_uac_dhcpdef_jcs_svr_set);
        FUN_004084d0("dhcpdef_apbind",3,_uac_dhcpdef_jcs_get_bind_entries);
        FUN_004084d0("dhcpdef_apbind",2,_uac_dhcpdef_jcs_set_bind_entries);
        FUN_004084d0("dhcpdef_apbind_svr",3,_uac_dhcpdef_jcs_get_bind_svrs);
        FUN_004084d0("dhcpdef_apbind_svr",2,_uac_dhcpdef_jcs_set_bind_svrs);
        dhcpdef_debug_init();
        memset(auStack_60,0,0x4c);
        local_54 = "dhcp_defend";
        local_50 = 0x6e;
        local_4c = _uac_dhcpdef_ap_connect_cb;
        local_48 = _uac_dhcpdef_ap_disconnect_cb;
        local_44 = _uac_dhcpdef_ap_firm_cb;
        local_40 = _uac_dhcpdef_ap_del_cb;
        local_34 = _uac_dhcpdef_ap_inherit_cb;
        local_30 = _uac_dhcpdef_ap_copy_cb;
        local_28 = _uac_dhcpdef_cap_change_cb;
        iVar1 = apmngr_callback_register(auStack_60);
        if (iVar1 == 0) {
          local_64 = 0;
          local_6c = 0xa000000;
          local_70 = "dhcp_defend";
          local_68 = _uac_dhcpdef_ap_enter_run_cb;
          iVar1 = multi_link_reg(&local_70);
          if (iVar1 == 0) {
            apmngr_support_capacity_register(0xf);
            apmngr_support_capacity_register(0x1e);
            return 0;
          }
          if (g_dhcpdef_error == 0) {
            return 0;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0;
          }
          pcVar4 = "\x1b[31;49m[%s]<%s():%d> multi_link_reg() fail!\x1b[0m\r\n";
          uVar3 = 0x9b1;
        }
        else {
          if (g_dhcpdef_error == 0) {
            return 0;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0;
          }
          pcVar4 = "\x1b[31;49m[%s]<%s():%d> apmngr_callback_register() fail!\x1b[0m\r\n";
          uVar3 = 0x9a2;
        }
        printf(pcVar4,"dhcp_defend","uac_dhcpdef_init",uVar3);
        return 0;
      }
      if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n","dhcp_defend",
               "uac_dhcpdef_init",0x98f,iVar1,"_uac_dhcpdef_recover_firm_aps()");
        return 0xffffffff;
      }
    }
    else if (g_dhcpdef_error != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar4 = "dhcpdef_db_init()";
      uVar3 = 0x98e;
      goto LAB_0046628c;
    }
  }
  else if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    pcVar4 = "dhcpdef_sqlite_init()";
    uVar3 = 0x98d;
LAB_0046628c:
    printf("\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n","dhcp_defend",
           "uac_dhcpdef_init",uVar3,iVar1,pcVar4);
    return 0xffffffff;
  }
  return 0xffffffff;
}

