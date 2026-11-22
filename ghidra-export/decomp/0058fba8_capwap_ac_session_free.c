// func capwap_ac_session_free @ 0058fba8 size=332

void capwap_ac_session_free(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0xec) == 0) {
    iVar1 = *(int *)(param_1 + 0xb0);
  }
  else {
    cw_timer_remove(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x44));
    *(undefined4 *)(param_1 + 0xec) = 0;
    iVar1 = *(int *)(param_1 + 0xb0);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0xac);
  }
  else {
    cw_pkt_mngr_destroy();
    *(undefined4 *)(param_1 + 0xb0) = 0;
    iVar1 = *(int *)(param_1 + 0xac);
  }
  if (iVar1 != 0) {
    cw_frag_session_destroy();
    *(undefined4 *)(param_1 + 0xac) = 0;
  }
  while (iVar1 = FUN_004081b0(param_1 + 0xf8), iVar1 != 0) {
    FUN_00408500(iVar1);
    if (*(char *)(iVar1 + 0xc) == '\0') {
      cw_send_pkt_destroy(*(undefined4 *)(iVar1 + 0x10));
      *(undefined4 *)(iVar1 + 0x10) = 0;
    }
    else if (*(char *)(iVar1 + 0xc) == '\x03') {
      cw_user_defined_send_pkt_destroy(*(undefined4 *)(iVar1 + 0x14));
      *(undefined4 *)(iVar1 + 0x14) = 0;
    }
    FUN_00407df0(iVar1);
  }
  capwap_network_session_destroy(param_1 + 0x2c);
  if (*(int *)(param_1 + 0xd4) != 0) {
    cw_pkt_buf_destroy();
    *(undefined4 *)(param_1 + 0xd4) = 0;
  }
  FUN_00407df0(param_1);
  FUN_004082d0(total_num_mutex,0xffffffff);
  session_total_num = session_total_num + -1;
  FUN_00407f30(total_num_mutex);
  return;
}

