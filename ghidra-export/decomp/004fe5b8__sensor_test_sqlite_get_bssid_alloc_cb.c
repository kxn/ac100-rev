// func _sensor_test_sqlite_get_bssid_alloc_cb @ 004fe5b8 size=744

undefined4
_sensor_test_sqlite_get_bssid_alloc_cb
          (int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  void *__s;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char *__s1;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_sqlite_get_bssid_alloc_cb ENTER\n",
           "_sensor_test_sqlite_get_bssid_alloc_cb",0x22c);
  }
  if (param_1 == 0) {
    uVar4 = 0;
    if (sensor_test_err_switch == '\0') {
      return 0;
    }
    pcVar5 = "[SENSOR_TEST_ERROR]%s()/%d para is null.\n";
    uVar3 = 0x234;
  }
  else {
    __s = (void *)FUN_00408450(0x24,0x23a);
    if (__s != (void *)0x0) {
      memset(__s,0,0x24);
      for (iVar6 = 0; iVar6 < param_2; iVar6 = iVar6 + 1) {
        pcVar5 = (char *)*param_3;
        if ((pcVar5 == (char *)0x0) || (__s1 = (char *)*param_4, __s1 == (char *)0x0)) {
          if (sensor_test_warning_switch != '\0') {
            printf("[SENSOR_TEST_WARNING]%s()/%d column value or name is null.\n",
                   "_sensor_test_sqlite_get_bssid_alloc_cb",0x247);
          }
        }
        else {
          iVar2 = strcmp(__s1,"test_case_id");
          if (iVar2 == 0) {
            uVar1 = atoi(pcVar5);
            *(uint *)((int)__s + 0x18) = uVar1;
            if ((((int)uVar1 < 0) || (g_sensor_test_case_num_max <= uVar1)) &&
               (sensor_test_warning_switch != '\0')) {
              printf("[SENSOR_TEST_WARNING]%s()/%d invalid test_case_id=%d\n",
                     "_sensor_test_sqlite_get_bssid_alloc_cb",0x250,uVar1);
            }
          }
          else {
            iVar2 = strcmp(__s1,"bssid");
            if (iVar2 == 0) {
              _str2mac(pcVar5,(int)__s + 0xc);
            }
            else {
              iVar2 = strcmp(__s1,"sensor_id");
              if (iVar2 == 0) {
                iVar2 = atoi(pcVar5);
                *(short *)((int)__s + 0x20) = (short)iVar2;
              }
              else {
                iVar2 = strcmp(__s1,"serv_id");
                if (iVar2 == 0) {
                  iVar2 = atoi(pcVar5);
                  *(int *)((int)__s + 0x14) = iVar2;
                }
                else {
                  iVar2 = strcmp(__s1,"freqband");
                  if (iVar2 == 0) {
                    iVar2 = atoi(pcVar5);
                    *(int *)((int)__s + 0x1c) = iVar2;
                  }
                  else {
                    iVar2 = strcmp(__s1,"status");
                    if (iVar2 == 0) {
                      iVar2 = atoi(pcVar5);
                      *(char *)((int)__s + 0x22) = (char)iVar2;
                    }
                    else {
                      iVar2 = strcmp(__s1,"rssi");
                      if (iVar2 == 0) {
                        iVar2 = atoi(pcVar5);
                        *(char *)((int)__s + 0x23) = (char)iVar2;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        param_3 = param_3 + 1;
        param_4 = param_4 + 1;
      }
      FUN_004086b0(param_1,__s);
      return 0;
    }
    uVar4 = 1;
    if (sensor_test_err_switch == '\0') {
      return 1;
    }
    pcVar5 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc tmp_bssid_alloc fail\n";
    uVar3 = 0x23d;
  }
  printf(pcVar5,"_sensor_test_sqlite_get_bssid_alloc_cb",uVar3);
  return uVar4;
}

