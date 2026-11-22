// func _wips_wserv_to_json @ 004c7abc size=200

undefined4 _wips_wserv_to_json(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  if ((*param_2 < param_2[1]) || (param_2[2] <= *param_2)) {
    uVar1 = *param_2;
  }
  else {
    iVar2 = json_object_new_object();
    if (iVar2 == 0) {
      if (sensor_err_switch == '\0') {
        return 0xffffffff;
      }
      printf("[SENSOR_ERROR]%s()/%d _wips_wserv_to_json malloc json obj failed.\n",
             "_wips_wserv_to_json",0x772);
      return 0xffffffff;
    }
    wips_wserv_whitelist_to_json(param_1,iVar2);
    json_object_array_add(param_2[3],iVar2);
    uVar1 = *param_2;
  }
  *param_2 = uVar1 + 1;
  return 0;
}

