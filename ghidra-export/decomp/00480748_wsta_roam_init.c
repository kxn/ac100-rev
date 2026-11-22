// func wsta_roam_init @ 00480748 size=932

undefined4 wsta_roam_init(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *local_58;
  char local_54 [4];
  code *local_50;
  char *local_4c;
  undefined4 local_48;
  code *local_40;
  code *local_38;
  code *local_34;
  
  iVar1 = wsta_roam_db_init();
  if (iVar1 == 0) {
    iVar1 = wsta_roam_pkt_init();
    if (iVar1 == 0) {
      memset(&local_58,0,0x2c);
      local_58 = (char *)0x61635f72;
      local_54[2] = 'm';
      local_54[0] = 'o';
      local_54[1] = 'a';
      local_38 = (code *)0xa;
      local_34 = wsta_roam_sta_assoc_callback;
      iVar1 = wsta_db_event_register(0,&local_58);
      if (iVar1 == 0) {
        local_34 = wsta_roam_start_delete_timer;
        iVar1 = wsta_db_event_register(1,&local_58);
        if (iVar1 == 0) {
          memset(&local_58,0,0x4c);
          local_4c = "ac_roam";
          local_48 = 0x5a;
          local_40 = _wsta_roam_ap_disconnect_cb;
          local_38 = _wsta_roam_ap_disconnect_cb;
          iVar1 = apmngr_callback_register(&local_58);
          if (iVar1 == 0) {
            local_4c = (char *)0x0;
            local_54[0] = '\t';
            local_54[1] = '\0';
            local_54[2] = '\0';
            local_54[3] = '\0';
            local_58 = "ac_roam";
            local_50 = _wsta_roam_ap_online_cb;
            iVar1 = multi_link_reg(&local_58);
            if (iVar1 == -1) {
              if (wsta_roam_err_switch != '\0') {
                printf("[WSTA_ROAM_ERROR]%s()/%d register callback to multi link failed.\n",
                       "_wsta_roam_multilink_callback_init",0x1b1);
              }
              if (wsta_roam_err_switch == '\0') goto LAB_004807e4;
              pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d _wsta_roam_multilink_callback_init() fail!\n";
              uVar3 = 0x204;
            }
            else {
              iVar1 = FUN_004084d0("ac_roam",2,_wsta_roam_jcs_intelligent_set);
              if (iVar1 == 0) {
                iVar1 = FUN_004084d0("roam_wireless_network_mode",2,
                                     _wsta_roam_jcs_intelligent_wireless_network_set);
                if (iVar1 == 0) {
                  iVar1 = FUN_004084d0("roam_wireless_network_mode",3,
                                       _wsta_roam_jcs_intelligent_wireless_network_get);
                  if (iVar1 == 0) {
                    iVar1 = FUN_004084d0("roam_exist_unsupport_ap",3,
                                         _wsta_roam_jcs_exist_unsupport_ap);
                    if (iVar1 == 0) {
                      apmngr_support_capacity_register(0x12);
                      apmngr_support_capacity_register(0x19);
                      apmngr_support_capacity_register(0x35);
                      apmngr_support_capacity_register(0x42);
                      wsta_roam_help_reg();
                      return 0;
                    }
                    if (wsta_roam_err_switch == '\0') goto LAB_004807e4;
                    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d jcs_callback_register() fail!\n";
                    uVar3 = 0x21b;
                  }
                  else {
                    if (wsta_roam_err_switch == '\0') goto LAB_004807e4;
                    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d jcs_callback_register() fail!\n";
                    uVar3 = 0x216;
                  }
                }
                else {
                  if (wsta_roam_err_switch == '\0') goto LAB_004807e4;
                  pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d jcs_callback_register() fail!\n";
                  uVar3 = 0x211;
                }
              }
              else {
                if (wsta_roam_err_switch == '\0') goto LAB_004807e4;
                pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d jcs_callback_register() fail!\n";
                uVar3 = 0x20a;
              }
            }
          }
          else {
            if (wsta_roam_err_switch != '\0') {
              printf("[WSTA_ROAM_ERROR]%s()/%d apmngr_callback_register() fail!\n",
                     "_wsta_roam_apmngr_callback_init",0x194);
            }
            if (wsta_roam_err_switch == '\0') goto LAB_004807e4;
            pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d _wsta_roam_apmngr_callback_init() fail!\n";
            uVar3 = 0x1fe;
          }
          goto LAB_004809a8;
        }
        if (wsta_roam_err_switch != '\0') {
          pcVar2 = 
          "[WSTA_ROAM_ERROR]%s()/%d register disassociation event callback to wstation  block failed.\n"
          ;
          uVar3 = 0x177;
          goto LAB_0048085c;
        }
      }
      else if (wsta_roam_err_switch != '\0') {
        pcVar2 = 
        "[WSTA_ROAM_ERROR]%s()/%d register association event callback to wstation  block failed.\n";
        uVar3 = 0x171;
LAB_0048085c:
        printf(pcVar2,"wsta_roam_wstation_callback_init",uVar3);
      }
      if (wsta_roam_err_switch == '\0') goto LAB_004807e4;
      pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d wsta_roam_wstation_callback_init() fail!\n";
      uVar3 = 0x1f8;
    }
    else {
      if (wsta_roam_err_switch == '\0') goto LAB_004807e4;
      pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d wsta_roam_pkt_init() fail!\n";
      uVar3 = 0x1f2;
    }
  }
  else {
    if (wsta_roam_err_switch == '\0') goto LAB_004807e4;
    pcVar2 = "[WSTA_ROAM_ERROR]%s()/%d wsta_roam_db_init() fail!\n";
    uVar3 = 0x1ec;
  }
LAB_004809a8:
  printf(pcVar2,"wsta_roam_init",uVar3);
LAB_004807e4:
  wsta_roam_pkt_uninit();
  wsta_roam_db_uninit();
  return 0xffffffff;
}

