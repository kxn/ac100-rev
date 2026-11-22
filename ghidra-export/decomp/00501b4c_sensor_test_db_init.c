// func sensor_test_db_init @ 00501b4c size=988

undefined4 sensor_test_db_init(void)

{
  int iVar1;
  time_t tVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_init ENTER\n","sensor_test_db_init",0xd99);
  }
  iVar1 = FUN_0051eb48("sensor","st_test_case_max",&g_sensor_test_case_num_max);
  if (iVar1 == -1) {
    if (sensor_test_err_switch == '\0') {
      g_sensor_test_case_num_max = 0x14;
    }
    else {
      printf("[SENSOR_TEST_ERROR]%s()/%d get profile[sensor->st_test_case_max] failed.\n",
             "sensor_test_db_init",0xd9f);
      g_sensor_test_case_num_max = 0x14;
    }
  }
  l_sensor_test_case_id_allocator = FUN_004080e0(g_sensor_test_case_num_max);
  if (l_sensor_test_case_id_allocator == 0) {
    if (sensor_test_err_switch != '\0') {
      pcVar3 = "[SENSOR_TEST_ERROR]%s()/%d l_sensor_test_case_id_allocator init fail. it\'s NULL\n";
      uVar5 = 0xda7;
LAB_00501d34:
      printf(pcVar3,"sensor_test_db_init",uVar5);
    }
  }
  else {
    l_sensor_test_db_mutex = FUN_00407f00("l_sensor_test_db_mutex",1);
    if (l_sensor_test_db_mutex == 0) {
      if (sensor_test_err_switch != '\0') {
        pcVar3 = "[SENSOR_TEST_ERROR]%s()/%d Create sensor test l_sensor_test_db_ptr mutex fail.\n";
        uVar5 = 0xdaf;
        goto LAB_00501d34;
      }
    }
    else {
      l_sensor_test_case_list = (void *)FUN_00408450(g_sensor_test_case_num_max << 2,0xdb4);
      if (l_sensor_test_case_list == (void *)0x0) {
        if (sensor_test_err_switch != '\0') {
          pcVar3 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc l_sensor_test_case_list fail\n";
          uVar5 = 0xdb7;
          goto LAB_00501d34;
        }
      }
      else {
        memset(l_sensor_test_case_list,0,g_sensor_test_case_num_max << 2);
        l_sensor_test_result_list = (void *)FUN_00408450(g_sensor_test_case_num_max * 0xc,0xdbe);
        if (l_sensor_test_result_list == (void *)0x0) {
          if (sensor_test_err_switch != '\0') {
            pcVar3 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc l_sensor_test_result_list fail\n";
            uVar5 = 0xdc1;
            goto LAB_00501d34;
          }
        }
        else {
          memset(l_sensor_test_result_list,0,g_sensor_test_case_num_max * 0xc);
          l_sensor_test_result_list_hash =
               (void *)FUN_00408450(g_sensor_test_case_num_max << 2,0xdc8);
          if (l_sensor_test_result_list_hash == (void *)0x0) {
            if (sensor_test_err_switch != '\0') {
              pcVar3 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc l_sensor_test_result_list_hash fail\n"
              ;
              uVar5 = 0xdcb;
              goto LAB_00501d34;
            }
          }
          else {
            uVar7 = 0;
            memset(l_sensor_test_result_list_hash,0,g_sensor_test_case_num_max << 2);
            iVar1 = sensor_test_sqlite_init();
            if (iVar1 == 0) {
              for (; uVar7 < g_sensor_test_case_num_max; uVar7 = uVar7 + 1) {
                if (*(int *)((int)l_sensor_test_case_list + uVar7 * 4) != 0) {
                  puVar6 = (undefined4 *)((int)l_sensor_test_result_list_hash + uVar7 * 4);
                  uVar5 = FUN_004080a0(_sensor_test_db_hash_obj,_sensor_test_db_hash_key,
                                       _sensor_test_db_hash_cmp,1000);
                  *puVar6 = uVar5;
                  FUN_0051ad88((void *)((int)l_sensor_test_result_list + uVar7 * 0xc));
                }
              }
              uVar7 = 0;
              while (uVar7 < g_sensor_test_case_num_max) {
                iVar1 = *(int *)((int)l_sensor_test_case_list + uVar7 * 4);
                if (iVar1 == 0) {
                  uVar7 = uVar7 + 1;
                }
                else {
                  iVar1 = *(int *)(iVar1 + 4);
                  if (iVar1 == 0) {
                    uVar7 = uVar7 + 1;
                  }
                  else if (*(short *)(iVar1 + 2) == 0) {
                    uVar7 = uVar7 + 1;
                  }
                  else {
                    uVar7 = uVar7 + 1;
                    tVar2 = time((time_t *)0x0);
                    *(time_t *)(iVar1 + 4) = tVar2;
                  }
                }
              }
              uVar5 = 0;
              if (sensor_test_debug_switch == '\0') {
                return 0;
              }
              pcVar3 = "[SENSOR_TEST_DEBUG]%s()/%d sensor_test_db_init success EXIT\n";
              uVar4 = 0xdea;
              goto LAB_00501d8c;
            }
            if (sensor_test_err_switch != '\0') {
              pcVar3 = "[SENSOR_TEST_ERROR]%s()/%d Failed to init sqlite\n";
              uVar5 = 0xdd4;
              goto LAB_00501d34;
            }
          }
        }
      }
    }
  }
  uVar5 = 0xffffffff;
  sensor_test_sqlite_uninit();
  sensor_test_db_uninit();
  if (sensor_test_err_switch == '\0') {
    return 0xffffffff;
  }
  pcVar3 = "[SENSOR_TEST_ERROR]%s()/%d sensor_test_db_init fail EXIT\n";
  uVar4 = 0xdf0;
LAB_00501d8c:
  printf(pcVar3,"sensor_test_db_init",uVar4);
  return uVar5;
}

