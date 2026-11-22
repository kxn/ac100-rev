// func _sensor_neighbor_scan_send @ 004e5ae0 size=276

undefined4
_sensor_neighbor_scan_send
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_004e5664(param_2,param_3,param_4,param_5,param_6,param_7);
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d _sensor_neighbor_scan_do_json_create failed\n",
             "_sensor_neighbor_scan_send",0x5ea);
    }
  }
  else {
    if (sensor_debug_switch != '\0') {
      printf("[SENSOR_DEBUG]%s()/%d json_str is %s\n","_sensor_neighbor_scan_send",0x5ed,iVar1);
    }
    iVar2 = sensor_pkt_tdcp_send(param_1,iVar1);
    if (iVar2 == 0) {
      uVar3 = 0;
      FUN_00407df0(iVar1);
    }
    else {
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d Send tdcp to ap %d failed\n","_sensor_neighbor_scan_send",
               0x5f0,param_1);
      }
      FUN_00407df0(iVar1);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

