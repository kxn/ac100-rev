// func rdmngr_bw_rd_mode_send_test @ 006174c8 size=1

void rdmngr_bw_rd_mode_send_test(uint param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 auStack_348 [2];
  undefined1 uStack_33f;
  undefined1 uStack_33e;
  undefined1 auStack_2f0 [732];
  
  memset(auStack_348,0,0x54);
  memset(auStack_2f0,0,0x2d8);
  iVar1 = rdmngr_db_rd_entry_get(param_1,auStack_348);
  if (iVar1 == 0) {
    iVar1 = rdmngr_db_update_reinit_state(param_1);
    if (iVar1 == 0) {
      uVar2 = rdmngr_db_generate_ap_id(auStack_348[0]);
      iVar1 = apmngr_db_entry_get_by_id(uVar2 & 0xffff,auStack_2f0);
      if (iVar1 != 0) {
        if (rdmngr_err_switch == 0) {
          return;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return;
        }
        pcVar3 = "[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id() fail:%d.\n";
        uVar4 = 0x657;
        goto code_r0x00617570;
      }
      uStack_33f = param_3;
      uStack_33e = param_2;
      iVar1 = rdmngr_wtp_pkt_send(uVar2,auStack_348);
      if (iVar1 == 0) {
        rdmngr_callback_proc(0,param_1,0,0);
        uVar4 = rdmngr_db_generate_ap_id(auStack_348[0]);
        iVar1 = rdmngr_wtp_pkt_send(uVar4,auStack_348);
        if (iVar1 == 0) {
          if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(1), iVar1 != 0)) {
            printf("[RDMNGR_DEBUG]%s()/%d rdmngr_bw_rd_mode_send_test send packet\n",
                   "rdmngr_bw_rd_mode_send_test",0x663);
          }
          rdmngr_callback_proc(1,param_1,0,0);
        }
      }
      iVar1 = apmngr_checksum_update(auStack_2f0,1);
      if (iVar1 == 0) {
        return;
      }
      if (rdmngr_err_switch == 0) {
        return;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return;
      }
      pcVar3 = "[RDMNGR_ERROR]%s()/%d apmngr_checksum_update() fail.\n";
      uVar4 = 0x66a;
    }
    else {
      if (rdmngr_err_switch == 0) {
        return;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return;
      }
      pcVar3 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_update_reinit_state() failed.\n";
      uVar4 = 0x64f;
    }
    printf(pcVar3,"rdmngr_bw_rd_mode_send_test",uVar4);
  }
  else {
    if (rdmngr_err_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    pcVar3 = "[RDMNGR_ERROR]%s()/%d rf_id:%d, rdmngr_db_rd_entry_get() failed.\n";
    uVar4 = 0x649;
    uVar2 = param_1;
code_r0x00617570:
    printf(pcVar3,"rdmngr_bw_rd_mode_send_test",uVar4,uVar2);
  }
  return;
}

