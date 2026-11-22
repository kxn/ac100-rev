// func apmngr_db_id_free @ 00534b5c size=328

void apmngr_db_id_free(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  ushort local_30 [4];
  int local_28 [5];
  
  param_2 = param_2 & 0xffff;
  local_28[0] = g_apmngr_template_id_allocator;
  local_30[1] = 0;
  local_28[1] = g_apmngr_ap_id_allocator;
  local_28[2] = g_apmngr_ap_id_allocator;
  local_30[2] = 0;
  local_28[3] = g_apmngr_sensor_id_allocator;
  local_30[0] = (ushort)apmngr_ap_num_max;
  local_30[3] = 50000;
  if (param_1 < 4) {
    iVar1 = local_28[param_1];
    if (((iVar1 != 0) && (local_30[param_1] <= param_2)) &&
       (iVar2 = param_2 - local_30[param_1], iVar2 + 1 <= *(int *)(iVar1 + 0x10))) {
      FUN_004082d0(apmngr_db_mutex,0xffffffff);
      FUN_004080f0(iVar1,iVar2);
      FUN_00407f30(apmngr_db_mutex);
      return;
    }
  }
  if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Illegal entry type:%d or id:%d\n","apmngr_db_id_free",0x1da,
           param_1,param_2);
  }
  return;
}

