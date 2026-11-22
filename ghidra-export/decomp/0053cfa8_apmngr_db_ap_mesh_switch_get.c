// func apmngr_db_ap_mesh_switch_get @ 0053cfa8 size=440

undefined4 apmngr_db_ap_mesh_switch_get(uint param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  param_1 = param_1 & 0xffff;
  if (param_2 == (int *)0x0) {
    if (apmngr_err_switch != '\0') {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[APMNGR_ERROR]%s()/%d Input error\n","apmngr_db_ap_mesh_switch_get",0x9d1);
      return 0xffffffff;
    }
  }
  else {
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
        *param_2 = (int)*(char *)(g_apmngr_entry_array + param_1 * 0x2d8 + 0x207);
      }
      FUN_00407f30(apmngr_db_mutex);
      return 0;
    }
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_ap_mesh_switch_get",0x9d7,
             param_1);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

