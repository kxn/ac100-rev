// func apmngr_db_id_alloc @ 00534a38 size=292

int apmngr_db_id_alloc(uint param_1)

{
  int iVar1;
  int iVar2;
  ushort local_30 [4];
  int local_28 [5];
  
  local_28[0] = g_apmngr_template_id_allocator;
  local_30[1] = 0;
  local_28[1] = g_apmngr_ap_id_allocator;
  local_28[2] = g_apmngr_ap_id_allocator;
  local_30[2] = 0;
  local_28[3] = g_apmngr_sensor_id_allocator;
  local_30[0] = (ushort)apmngr_ap_num_max;
  local_30[3] = 50000;
  if ((param_1 < 4) && (iVar2 = local_28[param_1], iVar2 != 0)) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    iVar1 = FUN_004085b0(iVar2);
    iVar2 = -1;
    FUN_00407f30(apmngr_db_mutex);
    if (iVar1 != -1) {
      iVar2 = iVar1 + (uint)local_30[param_1];
    }
  }
  else {
    iVar2 = -1;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Illegal entry type:%d\n","apmngr_db_id_alloc",0x1bb,param_1);
    }
  }
  return iVar2;
}

