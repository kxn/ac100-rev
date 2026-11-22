// func _sensor_test_multilink_callback_sensor_add @ 004fa560 size=692

/* WARNING: Type propagation algorithm not settling */

undefined4 _sensor_test_multilink_callback_sensor_add(uint param_1)

{
  uint uVar1;
  int iVar2;
  time_t tVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined2 local_ae0 [2];
  int local_adc;
  uint local_ad8 [6];
  undefined1 auStack_ac0 [64];
  undefined4 local_a80;
  undefined1 auStack_8a8 [192];
  undefined4 local_7e8 [500];
  
  param_1 = param_1 & 0xffff;
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_multilink_callback_sensor_add ENTER,ap_id=%d\n",
           "_sensor_test_multilink_callback_sensor_add",0x828,param_1);
  }
  memset(local_7e8,0,2000);
  local_ad8[0] = 0;
  local_ad8[1] = 0;
  local_ad8[2] = 0;
  local_ad8[3] = 0;
  local_ad8[4] = 0;
  memset(auStack_ac0,0,0x2d8);
  local_adc = 0;
  local_ae0[0] = 0;
  uVar1 = sensor_test_db_get_case_num_max();
  iVar2 = sensor_test_db_get_case_id_list_by_sensor(param_1,local_7e8,local_ad8);
  if (iVar2 == -1) {
    if (sensor_test_warning_switch == '\0') {
      return 0;
    }
    pcVar4 = "[SENSOR_TEST_WARNING]%s()/%d get_case_id_list fail by ap_id=%d\n";
    uVar5 = 0x833;
LAB_004fa654:
    uVar6 = 0;
    printf(pcVar4,"_sensor_test_multilink_callback_sensor_add",uVar5,param_1);
  }
  else {
    iVar2 = apmngr_db_entry_get_by_id(param_1,auStack_ac0);
    if ((iVar2 == 0) &&
       (iVar2 = apdb_get_radio_extend_capability
                          (local_a80,auStack_8a8,1,0xffffffff,local_ad8 + 1,0x10), iVar2 == 0)) {
      if ((local_ad8[4] & 1) == 0) {
        uVar6 = 0;
        if (sensor_warning_switch == '\0') {
          return 0;
        }
        pcVar4 = "[SENSOR_WARNING]%s()/%d sensor not support sensor_test\n";
        uVar5 = 0x841;
      }
      else {
        if (sensor_test_debug_switch != '\0') {
          printf("[SENSOR_TEST_DEBUG]%s()/%d case_num=%d\n",
                 "_sensor_test_multilink_callback_sensor_add",0x845,local_ad8[0]);
        }
        if (((int)local_ad8[0] < 1) || (uVar1 < local_ad8[0])) {
          if (sensor_test_warning_switch == '\0') {
            return 0;
          }
          pcVar4 = "[SENSOR_TEST_WARNING]%s()/%d no case to deploy by ap_id=%d\n";
          uVar5 = 0x849;
          goto LAB_004fa654;
        }
        puVar7 = local_7e8;
        iVar2 = 0;
        while (iVar2 < (int)local_ad8[0]) {
          sensor_test_db_set_case_sensor_add_flag(*puVar7,param_1,1);
          _sensor_test_sync_case_config_to_sensor(param_1,*puVar7,0);
          sensor_test_db_get_case_start_time(*puVar7,&local_adc,local_ae0);
          if (local_adc == 0) {
            uVar5 = *puVar7;
            iVar2 = iVar2 + 1;
            tVar3 = time((time_t *)0x0);
            puVar7 = puVar7 + 1;
            senosr_test_db_set_case_start_time(uVar5,tVar3);
          }
          else {
            iVar2 = iVar2 + 1;
            puVar7 = puVar7 + 1;
          }
        }
        uVar6 = 0;
        if (sensor_test_debug_switch == '\0') {
          return 0;
        }
        pcVar4 = 
        "[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_multilink_callback_sensor_add success EXIT\n";
        uVar5 = 0x85b;
      }
    }
    else {
      uVar6 = 0xffffffff;
      if (sensor_test_err_switch == '\0') {
        return 0xffffffff;
      }
      pcVar4 = "[SENSOR_TEST_ERROR]%s()/%d apdb_get_radio_extend_capability failed\n";
      uVar5 = 0x83b;
    }
    printf(pcVar4,"_sensor_test_multilink_callback_sensor_add",uVar5);
  }
  return uVar6;
}

