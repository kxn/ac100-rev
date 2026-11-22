// func rdmngr_rf_state_set @ 00616fd8 size=592

undefined4 rdmngr_rf_state_set(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 uVar3;
  int iVar2;
  char *__format;
  undefined4 uVar4;
  undefined4 local_348 [18];
  char local_300;
  undefined1 auStack_2f0 [732];
  
  memset(local_348,0,0x54);
  memset(auStack_2f0,0,0x2d8);
  memset(local_348,0,0x54);
  memset(auStack_2f0,0,0x2d8);
  iVar1 = rdmngr_db_rd_entry_get(param_1,local_348);
  if (iVar1 == 0) {
    iVar1 = (int)local_300;
    if (rdmngr_debug_switch != 0) {
      iVar2 = is_target_debug_ap();
      iVar1 = (int)local_300;
      if (iVar2 != 0) {
        printf("[RDMNGR_DEBUG]%s()/%d newStatus:%d, old:%d\n","rdmngr_rf_state_set",0xa4a,param_2,
               iVar1);
        iVar1 = (int)local_300;
      }
    }
    if (iVar1 == 0) {
      if (param_2 == 0) {
        return 0;
      }
      rdmngr_db_rd_entry_enable(local_348[0]);
    }
    else {
      if (param_2 != 0) {
        return 0;
      }
      rdmngr_db_rd_entry_disable(local_348[0]);
    }
    rdmngr_trigger_radio_onoff_nms_event(param_1,param_2);
    local_300 = (char)param_2;
    if (param_3 == 0) {
LAB_006171ac:
      rdmngr_db_rd_status_update(local_348[0],param_2);
      return 0;
    }
    uVar3 = rdmngr_db_generate_ap_id(local_348[0]);
    iVar1 = apmngr_db_entry_get_by_id(uVar3,auStack_2f0);
    if ((iVar1 == 0) && (iVar1 = apmngr_checksum_update(auStack_2f0,0), iVar1 == 0)) {
      uVar4 = rdmngr_db_generate_ap_id(local_348[0]);
      iVar1 = rdmngr_wtp_pkt_send(uVar4,local_348);
      if (iVar1 == 0) {
        rdmngr_callback_proc(param_2 != 0,local_348[0],0,0);
        goto LAB_006171ac;
      }
      if (rdmngr_err_switch != 0) {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[RDMNGR_ERROR]%s()/%d rd_id:%d, rdmngr_wtp_pkt_send() failed.\n";
        uVar4 = 0xa63;
        param_1 = local_348[0];
        goto LAB_00617188;
      }
    }
    else if (rdmngr_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[RDMNGR_ERROR]%s()/%d update md5 failed.\n","rdmngr_rf_state_set",0xa5e);
      return 0xffffffff;
    }
  }
  else if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    __format = "[RDMNGR_ERROR]%s()/%d rd_id:%d, rdmngr_db_rd_entry_get() failed.\n";
    uVar4 = 0xa46;
LAB_00617188:
    printf(__format,"rdmngr_rf_state_set",uVar4,param_1);
    return 0xffffffff;
  }
  return 0xffffffff;
}

