// func _rrm_jcs_manual_rrm_set @ 004ad8e4 size=496

void _rrm_jcs_manual_rrm_set(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = rrm_db_state_get();
    if ((iVar1 == 0) || (iVar1 == 7)) {
      if (((g_chnl_enable == 0) && (g_pwr_enable == 0)) ||
         (iVar1 = uac_wserv_send_pkt_check(), iVar1 == 0)) {
        if (g_chnl_enable == 0) {
          if (g_pwr_enable == 0) {
            iVar3 = -4;
            loggerk_reg(0x55,0x397e,0);
          }
          else {
            iVar3 = pwr_rrm_start(1);
            if (iVar3 == 0) {
              rrm_type = 1;
              rrm_callback_proc(0);
              loggerk_reg(0x55,0x3975,0);
              pwr_rrm_count = pwr_rrm_count + 1;
            }
          }
        }
        else {
          iVar3 = chnl_rrm_start();
          if (iVar3 == 0) {
            rrm_type = 1;
            rrm_callback_proc(0);
            loggerk_reg(0x55,0x3972,0);
          }
        }
      }
      else {
        iVar3 = -2;
        if (rrm_debug_switch != '\0') {
          printf("[RRM_DEBUG]%s()/%d You can\'t do rrm while radio or wireless operation\n",
                 "_rrm_jcs_manual_rrm_set",0x9d8);
        }
      }
    }
    else {
      iVar3 = -1;
      if (rrm_debug_switch != '\0') {
        printf("[RRM_DEBUG]%s()/%d You can\'t do rrm in state(%d),please wait for a moment\n",
               "_rrm_jcs_manual_rrm_set",0x9d2,iVar1);
      }
    }
    uVar2 = json_object_new_int(iVar3);
    json_object_object_add(param_2,&DAT_00676a24,uVar2);
    return;
  }
  if (rrm_err_switch != '\0') {
    printf("[RRM_ERROR]%s()/%d inputs error.\n","_rrm_jcs_manual_rrm_set",0x9cc);
    return;
  }
  return;
}

