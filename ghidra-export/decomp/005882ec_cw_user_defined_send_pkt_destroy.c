// func cw_user_defined_send_pkt_destroy @ 005882ec size=148

void cw_user_defined_send_pkt_destroy(int *param_1)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    *param_1 = *param_1 + -1;
    if (capwap_debug_switch == 0) {
      iVar1 = *param_1;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        iVar1 = *param_1;
      }
      else {
        printf("[CW_DEBUG]%32s():%4d free CW_USER_DEFINED_SEND_PKT,remain rel_cnt=%d]\n",
               "cw_user_defined_send_pkt_destroy",0x517,*param_1);
        iVar1 = *param_1;
      }
    }
    if (iVar1 == 0) {
      FUN_00407df0(param_1);
      return;
    }
  }
  return;
}

