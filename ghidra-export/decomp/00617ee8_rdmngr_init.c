// func rdmngr_init @ 00617ee8 size=1060

/* WARNING: Removing unreachable block (ram,0x00617f40) */

undefined4 rdmngr_init(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
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
  code *local_2c;
  code *local_28;
  code *local_1c;
  
  uVar4 = 0xffffffff;
  memset(auStack_60,0,0x4c);
  iVar1 = FUN_0051eb48("apmng_rf","rd_chnl_collect_interval",&rdmngr_channel_collect_interval_max);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  rdmngr_channel_collect_interval = rdmngr_channel_collect_interval_max / 10;
  local_50 = 0x6e;
  local_54 = "rdmngr";
  local_4c = rdmngr_api_for_apmngr_connect;
  local_44 = rdmngr_api_for_apmngr_firm;
  local_40 = rdmngr_api_for_apmngr_del;
  local_34 = rdmngr_api_for_apmngr_inherit;
  local_30 = rdmngr_api_for_apmngr_copy;
  local_28 = rdmngr_api_for_apmngr_cap_change;
  local_2c = rdmngr_checksum_update_cb;
  local_48 = rdmngr_api_for_ap_leave;
  local_1c = rdmngr_api_for_ap_model_update;
  iVar1 = apmngr_callback_register(auStack_60);
  if (iVar1 != 0) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[RDMNGR_ERROR]%s()/%d apmngr_callback_register() failed.\n";
    uVar3 = 0xb67;
    goto LAB_006180c4;
  }
  local_64 = 0;
  local_6c = 0x5a000000;
  local_70 = "rdmngr";
  local_68 = rdmngr_multilink_callback_rdmngr_add;
  iVar1 = multi_link_reg(&local_70);
  if (iVar1 == -1) {
    if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d register callback to multi link failed.\n",
             "rdmngr_multilink_callback_rdmngr_init",0x877);
    }
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    uVar4 = 0xffffffff;
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[RDMNGR_ERROR]%s()/%d multilink_callback_rdmngr_init() failed.\n";
    uVar3 = 0xb6d;
    goto LAB_006180c4;
  }
  iVar1 = serv_msg_mngr_register(9,0x5a,rdmngr_capwap_callback_wtp_event_request_listen);
  if (iVar1 == -1) {
    if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      pcVar2 = "[RDMNGR_ERROR]%s()/%d register callback to listen wtp event request failed.\n";
      uVar4 = 0x77a;
LAB_0061815c:
      printf(pcVar2,"rdmngr_capwap_callback_rdmngr_init",uVar4);
    }
  }
  else {
    iVar1 = serv_msg_mngr_register(5,0x5a,rdmngr_capwap_callback_cfg_status_request_listen);
    if (iVar1 == -1) {
      if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar2 = "[RDMNGR_ERROR]%s()/%d register callback to listen wtp event request failed.\n";
        uVar4 = 0x781;
        goto LAB_0061815c;
      }
    }
    else {
      iVar1 = serv_msg_mngr_register(3,0x73,rdmngr_capwap_callback_join_req_listen);
      if (iVar1 != -1) {
        iVar1 = FUN_004084e0(&g_rdmngr_thread,"rdmngr_thread",rdmngr_thread_callback,0);
        if (iVar1 == -1) {
          if (rdmngr_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          pcVar2 = "[RDMNGR_ERROR]%s()/%d create thread failed.\n";
          uVar3 = 0xb78;
        }
        else {
          FUN_0051ad88(&g_rdmngr_cb_list);
          l_working_channel_mutex = FUN_00407f00("working_channel_mutex",1);
          if (l_working_channel_mutex == 0) {
            if (rdmngr_err_switch == 0) {
              return 0xffffffff;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 != 0) {
              printf("[RDMNGR_ERROR]%s()/%d Create l_working_channel_mutex failed.\n","rdmngr_init",
                     0xb80);
              return 0xffffffff;
            }
            return 0xffffffff;
          }
          uVar4 = 0;
          udbg_help_register("rdmngr","rdmngr_debug_help()");
          if (rdmngr_debug_switch == 0) {
            return 0;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0;
          }
          pcVar2 = "[RDMNGR_DEBUG]%s()/%d rdmngr_init() OK.\n";
          uVar3 = 0xb87;
        }
        goto LAB_006180c4;
      }
      if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar2 = "[RDMNGR_ERROR]%s()/%d register callback to listen join request failed.\n";
        uVar4 = 0x787;
        goto LAB_0061815c;
      }
    }
  }
  uVar4 = 0xffffffff;
  if (rdmngr_err_switch == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar2 = "[RDMNGR_ERROR]%s()/%d rdmngr_capwap_callback_rdmngr_init() failed.\n";
  uVar3 = 0xb73;
LAB_006180c4:
  printf(pcVar2,"rdmngr_init",uVar3);
  return uVar4;
}

