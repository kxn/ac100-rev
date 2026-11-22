// func _sensor_test_aged_result_clean_time_out_handler @ 004f43e0 size=324

void _sensor_test_aged_result_clean_time_out_handler(void)

{
  time_t tVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  short local_7f8 [2];
  undefined4 local_7f4;
  int local_7f0;
  undefined4 local_7ec [502];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d aged_result_clean_time_out_handler ENTER\n",
           "_sensor_test_aged_result_clean_time_out_handler",0x13b4);
  }
  memset(local_7ec,0,2000);
  local_7f0 = 0;
  tVar1 = time((time_t *)0x0);
  local_7f4 = 0;
  local_7f8[0] = 0;
  iVar2 = sensor_test_db_get_case_id_list(local_7ec,&local_7f0);
  puVar5 = local_7ec;
  if (iVar2 == -1) {
    uVar4 = 0x13bf;
  }
  else {
    for (iVar2 = 0; iVar2 < local_7f0; iVar2 = iVar2 + 1) {
      iVar3 = sensor_test_db_get_case_start_time(*puVar5,&local_7f4,local_7f8);
      if (iVar3 != -1) {
        uVar4 = sensor_test_db_calc_aging_timestamp(local_7f4,(int)local_7f8[0],tVar1,10);
        sensor_test_db_clear_aging_result_by_case_id(*puVar5,uVar4);
      }
      puVar5 = puVar5 + 1;
    }
    uVar4 = 0x13ce;
  }
  l_sensor_test_aged_result_clear_timer =
       FUN_00408340(0x708,0,_sensor_test_aged_result_clean_time_out_handler,0,0,
                    "_sensor_test_aged_result_clean_time_out_handler",uVar4);
  return;
}

