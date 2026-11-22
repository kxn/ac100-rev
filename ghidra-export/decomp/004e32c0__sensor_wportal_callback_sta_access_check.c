// func _sensor_wportal_callback_sta_access_check @ 004e32c0 size=128

uint _sensor_wportal_callback_sta_access_check(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if (param_1 == 0) {
    uVar2 = 0;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d inputs error.\n","_sensor_wportal_callback_sta_access_check",
             0x8db);
    }
  }
  else {
    uVar2 = 0;
    iVar1 = sensor_db_vap_item_get_by_bssid(param_1,&local_18);
    if (iVar1 == 0) {
      uVar2 = (uint)(local_10 << 0x1a) >> 0x1f;
    }
  }
  return uVar2;
}

