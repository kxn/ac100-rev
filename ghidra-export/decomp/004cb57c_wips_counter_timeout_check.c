// func wips_counter_timeout_check @ 004cb57c size=272

void wips_counter_timeout_check(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  int local_14;
  
  if (sensor_debug_switch != '\0') {
    uVar2 = wips_local_time_get();
    printf("[SENSOR_DEBUG]%s()/%d wips_counter_timeout_check enter %d\n",
           "wips_counter_timeout_check",0xd2d,uVar2);
  }
  local_18 = 0;
  local_14 = 0;
  iVar1 = FUN_00408450((uint)g_wips_info_max_size * 0xb0,0xd31);
  if (iVar1 == 0) {
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d out of memory\n","wips_counter_timeout_check",0xd34);
    }
  }
  else {
    local_14 = 0;
    local_18 = iVar1;
    FUN_004082d0(wips_global_mutex,0xffffffff);
    FUN_00408570(g_counter_info_hash,_wips_get_timeout_counter_wips,&local_18);
    FUN_00407f30(wips_global_mutex);
    if (local_14 != 0) {
      wips_entry_counter(iVar1,local_14,0);
    }
    FUN_00407df0(iVar1);
  }
  return;
}

