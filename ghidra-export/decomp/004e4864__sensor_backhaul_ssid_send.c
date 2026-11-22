// func _sensor_backhaul_ssid_send @ 004e4864 size=328

undefined4
_sensor_backhaul_ssid_send
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,int param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_004e4340(param_3,param_2,param_4,param_5);
  if (iVar1 == 0) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d _sensor_backhaul_set_json_create failed\n",
           "_sensor_backhaul_ssid_send",0x5b3);
    return 0xffffffff;
  }
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d json_str is %s\n","_sensor_backhaul_ssid_send",0x5b6,iVar1);
  }
  if (param_6 == 0) {
    iVar2 = sensor_pkt_tdcp_send(param_1,iVar1);
    if (iVar2 == 0) goto LAB_004e48c8;
    if (sensor_err_switch == '\0') goto LAB_004e495c;
    uVar3 = 0x5c4;
  }
  else {
    iVar2 = sensor_pkt_tdcp_send_need_response(param_1,iVar1,param_6);
    if (iVar2 == 0) {
LAB_004e48c8:
      FUN_00407df0(iVar1);
      return 0;
    }
    if (sensor_err_switch == '\0') goto LAB_004e495c;
    uVar3 = 0x5bb;
  }
  printf("[SENSOR_ERROR]%s()/%d Send tdcp to ap %d failed\n","_sensor_backhaul_ssid_send",uVar3,
         param_1);
LAB_004e495c:
  FUN_00407df0(iVar1);
  return 0xffffffff;
}

