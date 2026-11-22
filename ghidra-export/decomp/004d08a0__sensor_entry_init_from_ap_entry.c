// func _sensor_entry_init_from_ap_entry @ 004d08a0 size=188

undefined4 _sensor_entry_init_from_ap_entry(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar2 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  iVar1 = sensor_db_get(*(undefined2 *)(param_1 + 0x10),&local_28,0);
  if (iVar1 != 0) {
    local_28 = CONCAT22(*(undefined2 *)(param_1 + 0x10),local_28._2_2_);
    iVar1 = sensor_db_add(&local_28);
    if (((iVar1 != 0) || (iVar1 = sensor_db_firm(*(undefined2 *)(param_1 + 0x10)), iVar1 != 0)) &&
       (uVar2 = 1, sensor_err_switch != '\0')) {
      printf("[SENSOR_ERROR]%s()/%d Add ap entry(%d) failed\n","_sensor_entry_init_from_ap_entry",
             0x255,(uint)*(ushort *)(param_1 + 0x10));
    }
  }
  return uVar2;
}

