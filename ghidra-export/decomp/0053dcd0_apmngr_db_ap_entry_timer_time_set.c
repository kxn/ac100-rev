// func apmngr_db_ap_entry_timer_time_set @ 0053dcd0 size=384

undefined4 apmngr_db_ap_entry_timer_time_set(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  param_1 = param_1 & 0xffff;
  if (((int)param_1 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < param_1 && ((int)param_1 < apmngr_sensor_num_max + 50000)))) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar2 = param_1;
    if (49999 < param_1) {
      uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) == 1) {
      if (49999 < param_1) {
        param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(undefined4 *)(g_apmngr_entry_array + param_1 * 0x2d8 + (param_2 + 0xc) * 4 + 4) = param_3;
    }
    uVar3 = 0;
    FUN_00407f30(apmngr_db_mutex);
  }
  else {
    uVar3 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_ap_entry_timer_time_set",0xa5e,
             param_1);
    }
  }
  return uVar3;
}

