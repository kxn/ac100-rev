// func wsta_roam_pkt_init @ 00489f2c size=820

int wsta_roam_pkt_init(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *__format;
  undefined4 uVar4;
  char *local_68;
  undefined4 local_64;
  code *local_60;
  char *local_5c;
  undefined4 local_58;
  code *local_50;
  code *local_48;
  code *local_44;
  undefined4 local_34;
  
  iVar1 = serv_msg_mngr_register(9,0x5a,_wsta_roam_pkt_wtp_event_listener);
  if (iVar1 == 0) {
    local_5c = (char *)0x0;
    local_64 = 0xa000000;
    local_68 = "intelligent_roam";
    local_60 = _wsta_intelligent_roam_ctl_pkt_send_cb;
    iVar2 = multi_link_reg(&local_68);
    if (iVar2 == -1) {
      if (wsta_roam_err_switch != '\0') {
        printf("[WSTA_ROAM_ERROR]%s()/%d register callback to multi link failed.\n",
               "_wsta_intelligent_roam_multilink_callback_init",0xc10);
      }
      if (stats_err_switch == '\0') {
        return 0;
      }
      __format = "[STATISTICS_ERROR]%s()/%d register multilink for wsta_roam_pkt module fail.\n";
      uVar4 = 0xe2f;
    }
    else {
      memset(&local_68,0,0x2c);
      memcpy(&local_68,"intelligent_roam",0x10);
      local_48 = (code *)0x9;
      local_44 = _wsta_intelligent_roam_sta_stats;
      iVar2 = wsta_db_event_register(0,&local_68);
      if (iVar2 == 0) {
        memset(&local_68,0,0x38);
        local_5c = "intelligent_roam";
        local_34 = 100;
        local_48 = _wsta_roam_rd_chnl_changed_by_subdev;
        local_44 = _wsta_roam_rd_chnl_modify_by_manual;
        iVar2 = rdmngr_callback_register(&local_68);
        if (iVar2 == -1) {
          if (wsta_roam_err_switch != '\0') {
            printf("[WSTA_ROAM_ERROR]%s()/%d rdmngr_callback_register() fail!\n",
                   "_wsta_intelligent_roam_rdmngr_callback_init",0xdbc);
          }
          if (wsta_roam_err_switch == '\0') {
            return 0;
          }
          __format = 
          "[WSTA_ROAM_ERROR]%s()/%d _wsta_intelligent_roam_rdmngr_callback_init() fail!\n";
          uVar4 = 0xe3b;
        }
        else {
          memset(&local_68,0,0x4c);
          local_5c = "intelligent_roam";
          local_58 = 100;
          local_50 = _wsta_intelligent_roam_callback_wtp_leave;
          iVar2 = apmngr_callback_register(&local_68);
          if (iVar2 == -1) {
            if (wsta_roam_err_switch != '\0') {
              printf("[WSTA_ROAM_ERROR]%s()/%d register callback to apmngr failed.\n",
                     "_wsta_intelligent_roam_apmngr_callback_init",0xe14);
            }
            if (wsta_roam_err_switch == '\0') {
              return 0;
            }
            __format = 
            "[WSTA_ROAM_ERROR]%s()/%d _wsta_intelligent_roam_apmngr_callback_init() fail!\n";
            uVar4 = 0xe40;
          }
          else {
            iVar2 = 0;
            piVar3 = &l_roaming_nbr_index_array;
            do {
              *piVar3 = iVar2;
              iVar2 = iVar2 + 1;
              piVar3 = piVar3 + 1;
            } while (iVar2 != 0xc);
            wsta_roam_pkt_chnl_mutex = FUN_00407f00("_wsta_roam_pkt_chnl_mutex",0);
            if (wsta_roam_pkt_chnl_mutex != 0) {
              iVar1 = apmngr_support_capacity_register(0x48);
              if (iVar1 != 0) {
                return 0;
              }
              check_cur_wireless_network_mode(0);
              return 0;
            }
            if (wsta_roam_err_switch == '\0') {
              return 0;
            }
            __format = "[WSTA_ROAM_ERROR]%s()/%d Create  mutex failed.\n";
            uVar4 = 0xe4c;
            wsta_roam_pkt_chnl_mutex = 0;
          }
        }
      }
      else {
        if (wsta_roam_err_switch != '\0') {
          printf("[WSTA_ROAM_ERROR]%s()/%d register association event callback to intelligent_roam block failed.\n"
                 ,"_wsta_intelligent_roam_wstation_callback_init",0xd6e);
        }
        if (stats_err_switch == '\0') {
          return 0;
        }
        __format = "[STATISTICS_ERROR]%s()/%d register wstation for wsta_roam_pkt module fail.\n";
        uVar4 = 0xe35;
      }
    }
  }
  else {
    if (wsta_roam_err_switch == '\0') {
      return iVar1;
    }
    __format = "[WSTA_ROAM_ERROR]%s()/%d register wtp event req for wstation module fail.\n";
    uVar4 = 0xe29;
  }
  printf(__format,"wsta_roam_pkt_init",uVar4);
  return iVar1;
}

