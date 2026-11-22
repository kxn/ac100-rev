// func jcs_sensor_test_add_test_case @ 004fc2ac size=1172

void jcs_sensor_test_add_test_case(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  time_t tVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 *__s;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_30c;
  uint local_308;
  undefined1 auStack_300 [64];
  undefined4 local_2c0;
  undefined1 auStack_e8 [196];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs_sensor_test_add_test_case ENTER\n",
           "jcs_sensor_test_add_test_case",0x1acd);
  }
  local_314 = 0;
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  memset(auStack_300,0,0x2d8);
  local_318 = 0;
  uVar2 = json_object_object_get(param_1,"join_test_sensor");
  iVar3 = json_object_array_length(uVar2);
  if (iVar3 < 1) {
    if (sensor_test_err_switch == '\0') {
      __s = (undefined4 *)0x0;
      iVar3 = 0;
    }
    else {
      __s = (undefined4 *)0x0;
      printf("[SENSOR_TEST_ERROR]%s()/%d no sensor to test\n","jcs_sensor_test_add_test_case",0x1add
            );
      iVar3 = 0;
    }
  }
  else {
    iVar3 = _sensor_test_build_case_setting(param_1);
    if (iVar3 == 0) {
      __s = (undefined4 *)0x0;
      if (sensor_test_err_switch != '\0') {
        printf("[SENSOR_TEST_ERROR]%s()/%d build_case_setting fail\n",
               "jcs_sensor_test_add_test_case",0x1ae6);
        __s = (undefined4 *)0x0;
      }
    }
    else {
      iVar8 = 0;
      if (*(char *)(iVar3 + 10) != '\0') {
LAB_004fc35c:
        do {
          bVar1 = *(byte *)(iVar3 + 10);
          while( true ) {
            if ((int)(uint)bVar1 <= iVar8) {
              __s = (undefined4 *)FUN_00408450(8,0x1b04);
              if (__s == (undefined4 *)0x0) {
                if (sensor_test_err_switch == '\0') goto LAB_004fc434;
                pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d new_case_ptr malloc ERROR\n";
                uVar2 = 0x1b07;
                goto LAB_004fc530;
              }
              memset(__s,0,8);
              __s[1] = iVar3;
              *__s = 0xffffffff;
              iVar3 = sensor_test_db_add_case(__s,&local_318);
              if (iVar3 == -1) {
                iVar3 = 0;
                if (sensor_test_err_switch == '\0') goto LAB_004fc434;
                pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d add case to db fail\n";
                uVar2 = 0x1b13;
                goto LAB_004fc530;
              }
              uVar2 = *__s;
              iVar3 = sensor_test_deployment_case(0,uVar2,__s[1],&local_318);
              if (iVar3 == -1) {
                if (sensor_test_err_switch != '\0') {
                  printf("[SENSOR_TEST_ERROR]%s()/%d add case fail at deploy stage\n",
                         "jcs_sensor_test_add_test_case",0x1b1c);
                }
                sensor_test_db_del_case(uVar2,0);
                iVar3 = 0;
                goto LAB_004fc434;
              }
              if (*(short *)__s[1] == 0) {
                tVar6 = time((time_t *)0x0);
                senosr_test_db_set_case_start_time(uVar2,tVar6);
              }
              sensor_test_db_case_setting_mem_free(__s[1]);
              __s[1] = 0;
              FUN_00407df0(__s);
              if (sensor_test_debug_switch != '\0') {
                printf("[SENSOR_TEST_DEBUG]%s()/%d jcs add test case success EXIT\n",
                       "jcs_sensor_test_add_test_case",0x1b35);
              }
              uVar5 = json_object_new_int(0);
              json_object_object_add(param_2,&DAT_00676a24,uVar5);
              uVar2 = json_object_new_int(uVar2);
              pcVar7 = "new_case_id";
              goto LAB_004fc49c;
            }
            iVar9 = iVar8 * 4;
            iVar4 = apmngr_db_entry_get_by_id
                              (*(undefined2 *)(*(int *)(iVar3 + 0x34) + iVar9),auStack_300);
            if ((iVar4 == 0) &&
               (iVar4 = apdb_get_radio_extend_capability
                                  (local_2c0,auStack_e8,1,0xffffffff,&local_314,0x10), iVar4 == 0))
            {
              if ((local_308 & 1) != 0) {
                iVar8 = iVar8 + 1;
                goto LAB_004fc35c;
              }
              if (sensor_test_err_switch != '\0') {
                printf("[SENSOR_TEST_ERROR]%s()/%d sensor_id=%d not support sensor_test, add_case fail\n"
                       ,"jcs_sensor_test_add_test_case",0x1af7,
                       (uint)*(ushort *)(*(int *)(iVar3 + 0x34) + iVar9));
              }
              __s = (undefined4 *)0x0;
              local_318 = 0xfffffffd;
              goto LAB_004fc434;
            }
            if (sensor_test_err_switch == '\0') break;
            iVar8 = iVar8 + 1;
            printf("[SENSOR_TEST_ERROR]%s()/%d apdb_get_radio_extend_capability failed,entry_id=%d\n"
                   ,"jcs_sensor_test_add_test_case",0x1af1,
                   (uint)*(ushort *)(*(int *)(iVar3 + 0x34) + iVar9));
            bVar1 = *(byte *)(iVar3 + 10);
          }
          iVar8 = iVar8 + 1;
        } while( true );
      }
      __s = (undefined4 *)0x0;
      if (sensor_test_err_switch != '\0') {
        pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d sensor_cnt <= 0\n";
        uVar2 = 0x1aff;
LAB_004fc530:
        printf(pcVar7,"jcs_sensor_test_add_test_case",uVar2);
      }
    }
  }
LAB_004fc434:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d jcs add test case fail EXIT\n",
           "jcs_sensor_test_add_test_case",0x1b3b);
  }
  if (iVar3 != 0) {
    sensor_test_db_case_setting_mem_free(iVar3);
  }
  if (__s != (undefined4 *)0x0) {
    sensor_test_db_case_setting_mem_free(__s[1]);
    __s[1] = 0;
    FUN_00407df0(__s);
  }
  uVar2 = json_object_new_int(1);
  json_object_object_add(param_2,&DAT_00676a24,uVar2);
  uVar2 = json_object_new_int(local_318);
  pcVar7 = "err_code";
LAB_004fc49c:
  json_object_object_add(param_2,pcVar7,uVar2);
  return;
}

