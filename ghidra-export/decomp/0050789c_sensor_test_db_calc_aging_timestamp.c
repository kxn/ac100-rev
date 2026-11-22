// func sensor_test_db_calc_aging_timestamp @ 0050789c size=260

uint sensor_test_db_calc_aging_timestamp(uint param_1,short param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (int)param_2;
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d calc_aging_timestamp ENTER,case_start_time=%d, cur_time=%d, period=%d(mins)\n"
           ,"sensor_test_db_calc_aging_timestamp",0x17c5,param_1,param_3,iVar2);
  }
  if ((param_1 <= param_3) && (0 < iVar2)) {
    uVar3 = iVar2 * 0x3c;
    if (uVar3 == 0) {
      trap(7);
    }
    uVar1 = (param_3 - param_1) / uVar3 + (uint)((param_3 - param_1) % uVar3 != 0);
    if ((param_4 & 0xff) < uVar1) {
      param_1 = (uVar1 - (param_4 & 0xff) & 0xff) * uVar3 + param_1;
    }
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d aging_timestamp=%d\n","sensor_test_db_calc_aging_timestamp"
             ,0x17e2,param_1);
    }
  }
  return param_1;
}

