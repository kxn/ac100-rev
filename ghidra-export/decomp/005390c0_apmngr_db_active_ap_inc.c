// func apmngr_db_active_ap_inc @ 005390c0 size=524

void apmngr_db_active_ap_inc(uint param_1)

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
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) != 0) {
      uVar2 = param_1;
      if (49999 < param_1) {
        uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x20) == 0) {
        uVar2 = param_1;
        if (49999 < param_1) {
          uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x14) == 7) {
          g_apmngr_active_sensor_num = g_apmngr_active_sensor_num + 1;
        }
        else {
          g_apmngr_active_ap_num = g_apmngr_active_ap_num + 1;
        }
        if (49999 < param_1) {
          param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined4 *)(g_apmngr_entry_array + param_1 * 0x2d8 + 0x20) = 1;
      }
    }
    FUN_00407f30(apmngr_db_mutex);
    return;
  }
  if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_active_ap_inc",0x653,param_1);
    return;
  }
  return;
}

