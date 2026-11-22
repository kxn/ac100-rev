// func apmngr_db_ap_reset_op_set @ 0053ff40 size=448

void apmngr_db_ap_reset_op_set(uint param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  param_1 = param_1 & 0xffff;
  if (((int)param_1 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < param_1 && ((int)param_1 < apmngr_sensor_num_max + 50000)))) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar2 = param_1;
    if (49999 < param_1) {
      uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) == 1) {
      uVar2 = param_1;
      if (49999 < param_1) {
        uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x2ac) != 0) {
        if (49999 < param_1) {
          param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined4 *)(g_apmngr_entry_array + param_1 * 0x2d8 + 0x24) = param_2;
      }
    }
    FUN_00407f30(apmngr_db_mutex);
    return;
  }
  if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_ap_reset_op_set",0xc72,param_1);
    return;
  }
  return;
}

