// func sensor_test_db_get_detail_result @ 005062dc size=1060

void * sensor_test_db_get_detail_result(int param_1,int param_2,uint param_3,uint param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  void *__s;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_get_detail_result ENTER, case_id=%d, test_type=%d, serindex=%d \n"
           ,"sensor_test_db_get_detail_result",0x14f6,param_1,param_3,param_4 & 0xffff);
  }
  iVar2 = sensor_test_db_is_test_case_id_legal(param_1);
  if (iVar2 == 0) {
    __s = (void *)0x0;
    if (sensor_test_debug_switch == '\0') {
      return (void *)0x0;
    }
    pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d input case_id invalid\n";
    uVar8 = 0x1502;
LAB_00506524:
    printf(pcVar7,"sensor_test_db_get_detail_result",uVar8);
    return __s;
  }
  if (8 < param_3) {
    __s = (void *)0x0;
    if (sensor_test_debug_switch == '\0') {
      return (void *)0x0;
    }
    pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d input test_type or ser_index invalid\n";
    uVar8 = 0x1508;
    goto LAB_00506524;
  }
  if (param_2 == 0) {
    __s = (void *)0x0;
    if (sensor_test_debug_switch == '\0') {
      return (void *)0x0;
    }
    pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d bssid is null\n";
    uVar8 = 0x150e;
    goto LAB_00506524;
  }
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  iVar2 = FUN_00407fa0(*(undefined4 *)(l_sensor_test_result_list_hash + param_1 * 4),param_2);
  if (iVar2 != 0) {
    iVar3 = *(int *)(l_sensor_test_case_list + param_1 * 4);
    if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 4), iVar3 == 0)) {
      if (sensor_test_err_switch != '\0') {
        pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d case_ptr or setting is null\n";
        uVar8 = 0x1521;
LAB_005065e0:
        printf(pcVar7,"sensor_test_db_get_detail_result",uVar8);
      }
    }
    else {
      uVar4 = _sensor_test_db_get_idx_of_serindex(iVar3 + 0x3c,param_3,param_4 & 0xffff);
      if (uVar4 != 0xffffffff) {
        iVar3 = _sensor_test_db_get_sepcified_list_from_bssid_result_node
                          (iVar2,param_3 & 0xff,uVar4 & 0xffff);
        if (iVar3 == 0) {
          if (sensor_test_warning_switch == '\0') goto LAB_00506604;
          pcVar7 = 
          "[SENSOR_TEST_WARNING]%s()/%d no such config,please check the test_type or serindex\n";
          uVar8 = 0x1530;
        }
        else {
          iVar5 = FUN_00407fe0(iVar3);
          if (0 < iVar5) {
            __s = (void *)FUN_00408450(0x70,0x1541);
            if (__s == (void *)0x0) {
              FUN_00407f30(l_sensor_test_db_mutex);
              if (sensor_test_err_switch == '\0') {
                return (void *)0x0;
              }
              pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d get_detail_result mem_malloc result fail\n";
              uVar8 = 0x1545;
              goto LAB_00506524;
            }
            memset(__s,0,0x70);
            memcpy((void *)((int)__s + 0x34),(void *)(iVar2 + 0x3e),6);
            memcpy(__s,(void *)(iVar2 + 0xc),0x32);
            *(undefined2 *)((int)__s + 0x32) = *(undefined2 *)(iVar2 + 0x44);
            iVar2 = FUN_00408610(iVar3);
            if (iVar2 != 0) {
              *(undefined4 *)((int)__s + 0x68) = *(undefined4 *)(iVar2 + 0x2c);
              *(undefined2 *)((int)__s + 0x6c) = *(undefined2 *)(iVar2 + 0x30);
              uVar1 = *(undefined1 *)(iVar2 + 0x32);
              *(undefined4 *)((int)__s + 100) = 0;
              *(undefined1 *)((int)__s + 0x6e) = uVar1;
              uVar6 = _sensor_test_db_deep_copy_detail_result(*(undefined4 *)(iVar2 + 0x28));
              uVar8 = l_sensor_test_db_mutex;
              *(undefined4 *)((int)__s + 100) = uVar6;
              FUN_00407f30(uVar8);
              if (sensor_test_debug_switch == '\0') {
                return __s;
              }
              pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_get_detail_result success EXIT\n";
              uVar8 = 0x1562;
              goto LAB_00506524;
            }
            if (sensor_test_debug_switch != '\0') {
              printf("[SENSOR_TEST_DEBUG]%s()/%d no result exists in list\n",
                     "sensor_test_db_get_detail_result",0x1554);
            }
            FUN_00407f30(l_sensor_test_db_mutex);
            goto LAB_00506570;
          }
          if (sensor_test_debug_switch == '\0') goto LAB_00506604;
          pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d no result exists in list\n";
          uVar8 = 0x1538;
        }
        goto LAB_0050669c;
      }
      if (sensor_test_err_switch != '\0') {
        pcVar7 = "[SENSOR_TEST_ERROR]%s()/%d get index of serindex fail\n";
        uVar8 = 0x1528;
        goto LAB_005065e0;
      }
    }
    __s = (void *)0x0;
    FUN_00407f30(l_sensor_test_db_mutex);
LAB_00506570:
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d sensor_test_db_get_detail_result fail EXIT\n",
             "sensor_test_db_get_detail_result",0x1566);
    }
    if (__s != (void *)0x0) {
      if (*(int *)((int)__s + 100) != 0) {
        sensor_test_db_detail_result_nested_mem_free();
        FUN_00407df0(*(undefined4 *)((int)__s + 100));
        *(undefined4 *)((int)__s + 100) = 0;
      }
      FUN_00407df0(__s);
      return (void *)0x0;
    }
    return (void *)0x0;
  }
  if (sensor_test_debug_switch == '\0') goto LAB_00506604;
  pcVar7 = "[SENSOR_TEST_DEBUG]%s()/%d cannot find result_bssid_node\n";
  uVar8 = 0x1518;
LAB_0050669c:
  printf(pcVar7,"sensor_test_db_get_detail_result",uVar8);
LAB_00506604:
  FUN_00407f30(l_sensor_test_db_mutex);
  return (void *)0x0;
}

