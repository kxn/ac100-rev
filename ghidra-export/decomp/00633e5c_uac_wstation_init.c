// func uac_wstation_init @ 00633e5c size=836

undefined4 uac_wstation_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  char *local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  code *local_c4;
  char acStack_c0 [32];
  undefined4 local_a0;
  code *local_9c;
  undefined4 local_98;
  undefined1 auStack_94 [12];
  char *local_88;
  undefined4 local_84;
  code *local_80;
  undefined4 local_60;
  undefined1 auStack_5c [12];
  char *local_50;
  undefined4 local_4c;
  code *local_44;
  code *local_3c;
  code *local_38;
  
  memset(auStack_5c,0,0x4c);
  memset(auStack_94,0,0x38);
  memset(acStack_c0,0,0x2c);
  local_d0 = (char *)0x0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = (code *)0x0;
  iVar1 = wsta_db_init();
  if (iVar1 == 0) {
    FUN_004084d0("wstation",3,_uac_wsta_jcs_get);
    FUN_004084d0("wstation",2,_uac_wsta_jcs_set);
    FUN_004084d0("wstation",1,_uac_wsta_jcs_del);
    FUN_004084d0("wstation_mac",1,_uac_wsta_jcs_del_by_mac);
    FUN_004084d0("wstation_backup",3,_uac_wsta_jcs_backup);
    iVar1 = uac_wstation_pkt_init();
    if (iVar1 == 0) {
      memset(auStack_5c,0,0x4c);
      local_50 = "wstation";
      local_4c = 0x6e;
      local_44 = _uac_wsta_ap_disconnect;
      local_3c = _uac_wsta_ap_disconnect;
      local_38 = _uac_wsta_ap_disconnect;
      iVar1 = apmngr_callback_register(auStack_5c);
      if (iVar1 == 0) {
        local_84 = 0;
        local_88 = "wstation";
        local_80 = _uac_wsta_rd_disable;
        local_60 = 0x96;
        iVar1 = rdmngr_callback_register(auStack_94);
        if (iVar1 == -1) {
          if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00634068;
          __format = "<wsta>[error]%s(): %d  -> rdmngr_callback_register() fail!\r\n";
          uVar2 = 0x63c;
        }
        else {
          strncpy(acStack_c0,"wstation",0x1f);
          local_a0 = 0xffffffff;
          local_98 = 0;
          local_9c = _uac_wsta_wlan_disable;
          iVar1 = wserv_db_event_register(3,acStack_c0);
          if (iVar1 == 0) {
            local_c8 = 0;
            local_cc = 0x32000000;
            local_d0 = "wstation";
            local_c4 = _uac_wsta_ap_switch_to_standby;
            iVar1 = multi_link_reg(&local_d0);
            if (iVar1 != -1) {
              apmngr_support_capacity_register(0);
              apmngr_support_capacity_register(6);
              apmngr_support_capacity_register(0x16);
              apmngr_support_capacity_register(0x1a);
              apmngr_support_capacity_register(0x38);
              uac_wstation_help_reg();
              return 0;
            }
            if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_00634068;
            __format = "<wserv>[error]%s(): %d  -> multi_link_reg() fail!\r\n";
            uVar2 = 0x654;
          }
          else {
            if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_00634068;
            __format = "<wsta>[error]%s(): %d  -> wserv_db_event_register() fail!\r\n";
            uVar2 = 0x647;
          }
        }
      }
      else {
        if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00634068;
        __format = "<wsta>[error]%s(): %d  -> apmngr_callback_register() fail!\r\n";
        uVar2 = 0x631;
      }
    }
    else {
      if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00634068;
      __format = "<wsta>[error]%s(): %d  -> uac_wstation_pkt_init() fail!\r\n";
      uVar2 = 0x624;
    }
  }
  else {
    if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00634068;
    __format = "<wsta>[error]%s(): %d  -> wsta_db_init() fail!\r\n";
    uVar2 = 0x618;
  }
  printf(__format,"uac_wstation_init",uVar2);
LAB_00634068:
  uac_wstation_pkt_uninit();
  wsta_db_uninit();
  return 0xffffffff;
}

