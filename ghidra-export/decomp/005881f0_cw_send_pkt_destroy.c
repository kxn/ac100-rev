// func cw_send_pkt_destroy @ 005881f0 size=176

void cw_send_pkt_destroy(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    if (capwap_debug_switch == 0) {
      iVar1 = *(int *)(param_1 + 8);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 8);
      }
      else {
        printf("[CW_DEBUG]%32s():%4d free CW_SEND_PKT,remain rel_cnt=%d]\n","cw_send_pkt_destroy",
               0x4fa,*(undefined4 *)(param_1 + 8));
        iVar1 = *(int *)(param_1 + 8);
      }
    }
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x10) != 0) {
        FUN_00407df0();
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
      FUN_00407df0(param_1);
      return;
    }
  }
  return;
}

