// func apmngr_db_id_cost @ 00534ca4 size=272

void apmngr_db_id_cost(uint param_1,uint param_2)

{
  int iVar1;
  ushort local_28 [4];
  int local_20 [5];
  
  param_2 = param_2 & 0xffff;
  local_20[0] = g_apmngr_template_id_allocator;
  local_28[1] = 0;
  local_28[2] = 0;
  local_20[1] = g_apmngr_ap_id_allocator;
  local_20[2] = g_apmngr_ap_id_allocator;
  local_20[3] = g_apmngr_sensor_id_allocator;
  local_28[0] = (ushort)apmngr_ap_num_max;
  local_28[3] = 50000;
  if (param_1 < 4) {
    if (((local_20[param_1] != 0) && (local_28[param_1] <= param_2)) &&
       ((int)((param_2 - local_28[param_1]) + 1) <= *(int *)(local_20[param_1] + 0x10))) {
      FUN_00408440();
      return;
    }
  }
  if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Illegal entry type:%d or id:%d\n","apmngr_db_id_cost",499,param_1,
           param_2);
  }
  return;
}

