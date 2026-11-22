// func rdmngr_wtp_frame_rate_pkt_send_test @ 00617710 size=1

void rdmngr_wtp_frame_rate_pkt_send_test(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  undefined2 uVar2;
  char *__format;
  undefined4 uVar3;
  undefined1 auStack_340 [41];
  undefined1 uStack_317;
  undefined1 auStack_2e8 [728];
  
  memset(auStack_340,0,0x54);
  memset(auStack_2e8,0,0x2d8);
  memset(auStack_340,0,0x54);
  memset(auStack_2e8,0,0x2d8);
  iVar1 = rdmngr_db_rd_entry_get(param_1,auStack_340);
  if (iVar1 != 0) {
    if (rdmngr_err_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[RDMNGR_ERROR]%s()/%d Invalid rd id %d\n","rdmngr_wtp_frame_rate_pkt_send_test",0x624,
           param_1);
    return;
  }
  iVar1 = rdmngr_db_update_reinit_state(param_1);
  if (iVar1 == 0) {
    frame_rate_num = param_2;
    uStack_317 = param_3;
    uVar2 = rdmngr_db_generate_ap_id(param_1);
    iVar1 = apmngr_db_entry_get_by_id(uVar2,auStack_2e8);
    if ((iVar1 == 0) && (iVar1 = apmngr_checksum_update(auStack_2e8,0), iVar1 == 0)) {
      uVar3 = rdmngr_db_generate_ap_id(param_1);
      iVar1 = rdmngr_wtp_pkt_send(uVar3,auStack_340);
      if (iVar1 != 0) {
        return;
      }
      if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d shutdown radio %d OK.\n","rdmngr_wtp_frame_rate_pkt_send_test"
               ,0x636,param_1);
      }
      rdmngr_callback_proc(0,param_1,0,0);
      uVar3 = rdmngr_db_generate_ap_id(param_1);
      iVar1 = rdmngr_wtp_pkt_send(uVar3,auStack_340);
      if (iVar1 != 0) {
        return;
      }
      if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(1), iVar1 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d open radio %d OK.\n","rdmngr_wtp_frame_rate_pkt_send_test",
               0x63a,param_1);
      }
      rdmngr_callback_proc(1,param_1,0,0);
      return;
    }
    if (rdmngr_err_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    __format = "[RDMNGR_ERROR]%s()/%d update md5 failed.\n";
    uVar3 = 0x631;
  }
  else {
    if (rdmngr_err_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_update_reinit_state() failed.\n";
    uVar3 = 0x629;
  }
  printf(__format,"rdmngr_wtp_frame_rate_pkt_send_test",uVar3);
  return;
}

