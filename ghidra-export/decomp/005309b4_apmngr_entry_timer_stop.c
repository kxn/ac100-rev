// func apmngr_entry_timer_stop @ 005309b4 size=1

undefined4 apmngr_entry_timer_stop(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  
  param_1 = param_1 & 0xffff;
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d apmngr_entry_timer_end: %d, op_type : %d\n",
           "apmngr_entry_timer_stop",0xc68,param_1,param_2);
  }
  apmngr_db_ap_entry_timer_time_set(param_1,param_2,0);
  if (((int)param_1 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < param_1 && ((int)param_1 < apmngr_sensor_num_max + 50000)))) {
    if (param_2 < 2) {
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
        if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + (param_2 + 10) * 4 + 4) != -1) {
          uVar2 = param_1;
          if (49999 < param_1) {
            uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          FUN_00407f20(*(undefined4 *)
                        (g_apmngr_entry_array + uVar2 * 0x2d8 + (param_2 + 10) * 4 + 4));
          if (49999 < param_1) {
            param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          *(undefined4 *)(g_apmngr_entry_array + param_1 * 0x2d8 + (param_2 + 10) * 4 + 4) =
               0xffffffff;
        }
      }
      FUN_00407f30(apmngr_db_mutex);
      return 0;
    }
    if (apmngr_err_switch != '\0') {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d Invalid op_type[%d].\n";
      uVar3 = 0xa48;
      goto LAB_0053db5c;
    }
  }
  else if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    __format = "[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n";
    uVar3 = 0xa42;
    param_2 = param_1;
LAB_0053db5c:
    printf(__format,"apmngr_db_ap_entry_timer_stop",uVar3,param_2);
    return 0xffffffff;
  }
  return 0xffffffff;
}

