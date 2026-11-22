// func rdmngr_rf_edit_channel_bwMode_test @ 00616e30 size=1

undefined4 rdmngr_rf_edit_channel_bwMode_test(undefined4 param_1,short param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 auStack_68 [2];
  undefined1 uStack_5e;
  undefined1 uStack_27;
  
  memset(auStack_68,0,0x54);
  iVar1 = rdmngr_db_rd_entry_get(param_1,auStack_68);
  if (iVar1 == 0) {
    iVar1 = rdmngr_db_update_reinit_state(param_1);
    if (iVar1 == 0) {
      uStack_27 = (undefined1)param_2;
      uStack_5e = param_3;
      uVar2 = rdmngr_db_generate_ap_id(auStack_68[0]);
      iVar1 = rdmngr_wtp_pkt_send(uVar2,auStack_68);
      if (iVar1 == 0) {
        rdmngr_callback_proc(0,param_1,0,0);
        uVar2 = rdmngr_db_generate_ap_id(auStack_68[0]);
        iVar1 = rdmngr_wtp_pkt_send(uVar2,auStack_68);
        if (iVar1 == 0) {
          if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(1,(int)param_2), iVar1 != 0)
             ) {
            printf("[RDMNGR_DEBUG]%s()/%d rdmngr_rf_edit_channel_bwMode_test send packet\n",
                   "rdmngr_rf_edit_channel_bwMode_test",0xb29);
          }
          rdmngr_callback_proc(1,param_1,0,0);
        }
      }
      rdmngr_db_rd_entry_region_code_linkage(param_1,(int)param_2,param_3);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
      if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_update_reinit_state() failed.\n",
               "rdmngr_rf_edit_channel_bwMode_test",0xb1d);
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
    if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d rf_id:%d, rdmngr_db_rd_entry_get() failed.\n",
             "rdmngr_rf_edit_channel_bwMode_test",0xb17,param_1);
    }
  }
  return uVar2;
}

