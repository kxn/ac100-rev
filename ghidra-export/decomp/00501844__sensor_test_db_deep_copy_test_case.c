// func _sensor_test_db_deep_copy_test_case @ 00501844 size=420

undefined4 * _sensor_test_db_deep_copy_test_case(undefined4 *param_1)

{
  int iVar1;
  undefined4 *__s;
  char *__format;
  undefined4 uVar2;
  
  if (sensor_test_debug_switch == '\0') {
    if (param_1 != (undefined4 *)0x0) {
      iVar1 = param_1[1];
LAB_00501874:
      if (iVar1 != 0) {
        __s = (undefined4 *)FUN_00408450(8,0xc26);
        if (__s == (undefined4 *)0x0) {
          if (sensor_test_err_switch == '\0') {
            return (undefined4 *)0x0;
          }
          __format = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
          uVar2 = 0xc29;
        }
        else {
          memset(__s,0,8);
          *__s = *param_1;
          iVar1 = _sensor_test_db_deep_copy_test_case_setting(param_1[1]);
          __s[1] = iVar1;
          if (iVar1 == 0) {
            if (sensor_test_err_switch != '\0') {
              printf("[SENSOR_TEST_ERROR]%s()/%d deep_copy_setting fail\n",
                     "_sensor_test_db_deep_copy_test_case",0xc32);
            }
            if (sensor_test_err_switch == '\0') {
              iVar1 = __s[1];
            }
            else {
              printf("[SENSOR_TEST_ERROR]%s()/%d _sensor_test_db_deep_copy_test_case fail EXIT\n",
                     "_sensor_test_db_deep_copy_test_case",0xc3a);
              iVar1 = __s[1];
            }
            if (iVar1 != 0) {
              sensor_test_db_case_setting_mem_free();
              __s[1] = 0;
            }
            FUN_00407df0(__s);
            return (undefined4 *)0x0;
          }
          if (sensor_test_debug_switch == '\0') {
            return __s;
          }
          __format = "[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_db_deep_copy_test_case success EXIT\n"
          ;
          uVar2 = 0xc36;
        }
        goto LAB_0050194c;
      }
    }
  }
  else {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_db_deep_copy_test_case ENTER\n",
           "_sensor_test_db_deep_copy_test_case",0xc1d);
    if (param_1 != (undefined4 *)0x0) {
      iVar1 = param_1[1];
      goto LAB_00501874;
    }
  }
  __s = (undefined4 *)0x0;
  if (sensor_test_err_switch == '\0') {
    return (undefined4 *)0x0;
  }
  __format = "[SENSOR_TEST_ERROR]%s()/%d deep_copy_test_case fail\n";
  uVar2 = 0xc22;
LAB_0050194c:
  printf(__format,"_sensor_test_db_deep_copy_test_case",uVar2);
  return __s;
}

