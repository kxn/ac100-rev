// func apmngr_db_ap_entry_timer_start @ 0053d670 size=1020

undefined4
apmngr_db_ap_entry_timer_start
          (uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  
  param_1 = param_1 & 0xffff;
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
          if ((apmngr_timer_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            uVar2 = param_1;
            if (49999 < param_1) {
              uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
            }
            printf("[APMNGR_TIMER]%s()/%d remove old timer, id = %d\n",
                   "apmngr_db_ap_entry_timer_start",0xa32,
                   *(undefined4 *)(g_apmngr_entry_array + uVar2 * 0x2d8 + (param_2 + 10) * 4 + 4));
          }
          uVar2 = param_1;
          if (49999 < param_1) {
            uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          FUN_00407f20(*(undefined4 *)
                        (g_apmngr_entry_array + uVar2 * 0x2d8 + (param_2 + 10) * 4 + 4));
          uVar2 = param_1;
          if (49999 < param_1) {
            uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          *(undefined4 *)(g_apmngr_entry_array + uVar2 * 0x2d8 + (param_2 + 10) * 4 + 4) =
               0xffffffff;
        }
        uVar2 = param_1;
        if (49999 < param_1) {
          uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        iVar1 = g_apmngr_entry_array + uVar2 * 0x2d8;
        uVar3 = FUN_00407ff0(param_3,0,param_4,param_5,param_6,"apmngr_db_ap_entry_timer_start",
                             0xa36);
        *(undefined4 *)(iVar1 + (param_2 + 10) * 4 + 4) = uVar3;
        if ((apmngr_timer_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          uVar2 = param_1;
          if (49999 < param_1) {
            uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          printf("[APMNGR_TIMER]%s()/%d Start ap entry timer[%d](%d secs) for ap %d, id = %d\n",
                 "apmngr_db_ap_entry_timer_start",0xa37,param_2,param_3,param_1,
                 *(undefined4 *)(g_apmngr_entry_array + uVar2 * 0x2d8 + (param_2 + 10) * 4 + 4));
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
      uVar3 = 0xa29;
      goto LAB_0053d784;
    }
  }
  else if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    __format = "[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n";
    uVar3 = 0xa23;
    param_2 = param_1;
LAB_0053d784:
    printf(__format,"apmngr_db_ap_entry_timer_start",uVar3,param_2);
    return 0xffffffff;
  }
  return 0xffffffff;
}

