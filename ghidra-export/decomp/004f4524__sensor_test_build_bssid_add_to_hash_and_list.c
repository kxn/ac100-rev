// func _sensor_test_build_bssid_add_to_hash_and_list @ 004f4524 size=644

undefined4
_sensor_test_build_bssid_add_to_hash_and_list
          (undefined4 param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
          int param_6,int param_7)

{
  undefined1 uVar2;
  int iVar1;
  char *__format;
  undefined4 uVar3;
  void *__s;
  undefined1 auStack_120 [9];
  undefined1 auStack_117 [251];
  
  memset(auStack_120,0,0x100);
  if ((param_6 == 0) || (param_7 == 0)) {
    __s = (void *)0x0;
    if (sensor_test_err_switch == '\0') {
LAB_004f4620:
      __s = (void *)0x0;
      goto LAB_004f4624;
    }
    __format = "[SENSOR_TEST_ERROR]%s()/%d input bssid_hash or bssid_list is null\n";
    uVar3 = 0x667;
  }
  else if ((param_2 == 0xffffffff) || (param_3 == -1)) {
    __s = (void *)0x0;
    if (sensor_test_err_switch == '\0') goto LAB_004f4620;
    __format = "[SENSOR_TEST_ERROR]%s()/%d input rd_id or serv_id is invalid\n";
    uVar3 = 0x66d;
  }
  else {
    memset(auStack_120,0,0x100);
    uVar2 = wserv_db_wlanid_get_by_wservid(param_2,param_3);
    iVar1 = stats_db_ssid_get(param_1,param_2 & 0xf,uVar2,auStack_120);
    if (iVar1 != 0) {
      if (sensor_test_warning_switch == '\0') {
        return 0;
      }
      printf("[SENSOR_TEST_WARNING]%s()/%d get bssid fail by stats_db_ssid_get()\n",
             "_sensor_test_build_bssid_add_to_hash_and_list",0x67c);
      return 0;
    }
    iVar1 = FUN_00407fa0(param_6,auStack_117);
    if (iVar1 != 0) {
      return 0;
    }
    __s = (void *)FUN_00408450(0x24,0x687);
    if (__s == (void *)0x0) {
      if (sensor_test_err_switch == '\0') goto LAB_004f4624;
      __format = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
      uVar3 = 0x68a;
    }
    else {
      memset(__s,0,0x24);
      memcpy((void *)((int)__s + 0xc),auStack_117,6);
      *(int *)((int)__s + 0x14) = param_3;
      *(undefined4 *)((int)__s + 0x1c) = param_4;
      *(undefined4 *)((int)__s + 0x18) = param_5;
      if (sensor_test_debug_switch != '\0') {
        printf("[SENSOR_TEST_DEBUG]%s()/%d bssid_hash add\n",
               "_sensor_test_build_bssid_add_to_hash_and_list",0x696);
      }
      iVar1 = FUN_00408380(param_6,__s);
      if (iVar1 != -1) {
        FUN_004086b0(param_7,__s);
        return 0;
      }
      if (sensor_test_err_switch == '\0') goto LAB_004f4624;
      __format = "[SENSOR_TEST_ERROR]%s()/%d uac_hash_add fail\n";
      uVar3 = 0x699;
    }
  }
  printf(__format,"_sensor_test_build_bssid_add_to_hash_and_list",uVar3);
LAB_004f4624:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d _sensor_test_build_bssid_add_to_hash_and_list fail EXIT\n",
           "_sensor_test_build_bssid_add_to_hash_and_list",0x6a1);
  }
  if (__s != (void *)0x0) {
    FUN_00407df0(__s);
  }
  return 0xffffffff;
}

