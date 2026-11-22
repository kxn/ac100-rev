// func apmngr_db_ap_is_run_state @ 0053bebc size=452

undefined4 apmngr_db_ap_is_run_state(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  param_1 = param_1 & 0xffff;
  if ((int)param_1 < apmngr_ap_num_max) {
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
      if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0xc) != 0) {
        uVar2 = param_1;
        if (49999 < param_1) {
          uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if (1 < *(uint *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x2ac)) {
          if (49999 < param_1) {
            param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          if (*(uint *)(g_apmngr_entry_array + param_1 * 0x2d8 + 0x2ac) < 4) {
            FUN_00407f30(apmngr_db_mutex);
            return 1;
          }
        }
      }
    }
    FUN_00407f30(apmngr_db_mutex);
  }
  else if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d input error\n","apmngr_db_ap_is_run_state",0x8c9);
  }
  return 0;
}

