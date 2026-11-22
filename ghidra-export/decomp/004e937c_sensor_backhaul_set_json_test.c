// func sensor_backhaul_set_json_test @ 004e937c size=1

void sensor_backhaul_set_json_test(undefined4 param_1)

{
  int iVar1;
  undefined4 uStack_218;
  undefined2 uStack_214;
  undefined1 auStack_210 [520];
  
  memset(auStack_210,0,0x205);
  uStack_218 = 0;
  uStack_214 = 0;
  iVar1 = wserv_db_get_entry_by_id(param_1,auStack_210);
  if (iVar1 == 0) {
    iVar1 = FUN_004e4340(1,&uStack_218,auStack_210,2);
    if (iVar1 != 0) {
      printf("backhaul_json_str is %s\n",iVar1);
      FUN_00407df0(iVar1);
    }
  }
  else if (sensor_err_switch != '\0') {
    printf("[SENSOR_ERROR]%s()/%d Get backhaul wservice(%d) failed\n",
           "sensor_backhaul_set_json_test",0xb57,param_1);
  }
  return;
}

