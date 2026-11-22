// func sensor_test_db_msg_send @ 004fee40 size=156

undefined4 sensor_test_db_msg_send(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_18;
  int local_14;
  
  if (param_2 != 0) {
    local_18 = param_1;
    local_14 = param_2;
    FUN_00407e80("sensor_test_db_msg_send");
    uVar1 = FUN_00407d40(g_sensor_test_msgq,&local_18,8,0xc9,5000);
    FUN_004082b0(1,"sensor_test_db_msg_send");
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d uac_msgQ_send(), ret = %d\n","sensor_test_db_msg_send",
             0xe48,uVar1);
    }
  }
  return 0;
}

