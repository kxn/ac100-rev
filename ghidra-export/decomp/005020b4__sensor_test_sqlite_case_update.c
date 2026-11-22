// func _sensor_test_sqlite_case_update @ 005020b4 size=1652

int _sensor_test_sqlite_case_update(uint *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_998 [100];
  char acStack_934 [256];
  undefined1 auStack_834 [300];
  undefined4 local_708;
  undefined1 auStack_704 [58];
  undefined4 local_6ca;
  char acStack_62c [1540];
  
  memset(acStack_62c,0,0x600);
  memset(auStack_834,0,0x205);
  memset(auStack_998,0,100);
  if ((((param_1 == (uint *)0x0) || ((int)*param_1 < 0)) || (g_sensor_test_case_num_max <= *param_1)
      ) || (param_1[1] == 0)) {
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d input invalid\n","_sensor_test_sqlite_case_update",0x157);
    }
    iVar7 = -1;
    if (param_1 == (uint *)0x0) {
      return -1;
    }
    iVar3 = 0;
    iVar2 = 0;
    iVar1 = 0;
  }
  else {
    iVar1 = json_object_new_array();
    if (iVar1 == 0) {
      if (sensor_test_err_switch != '\0') {
        printf("[SENSOR_TEST_ERROR]%s()/%d create group_id_obj fail\n",
               "_sensor_test_sqlite_case_update",0x15e);
      }
      iVar2 = 0;
      iVar3 = 0;
      iVar7 = -1;
    }
    else {
      iVar2 = json_object_new_array();
      if (iVar2 == 0) {
        if (sensor_test_err_switch == '\0') {
          iVar3 = 0;
          iVar7 = -1;
        }
        else {
          iVar3 = 0;
          printf("[SENSOR_TEST_ERROR]%s()/%d create join_test_sensor_obj fail\n",
                 "_sensor_test_sqlite_case_update",0x165);
          iVar7 = -1;
        }
      }
      else {
        iVar7 = 0;
        iVar3 = json_object_new_array();
        if (iVar3 == 0) {
          iVar7 = -1;
          if (sensor_test_err_switch == '\0') goto LAB_0050215c;
          __format = "[SENSOR_TEST_ERROR]%s()/%d create ssid_info_obj fail\n";
          uVar6 = 0x16c;
        }
        else {
          for (; uVar4 = param_1[1], iVar7 < (int)(uint)*(byte *)(uVar4 + 9); iVar7 = iVar7 + 1) {
            uVar6 = json_object_new_int(*(undefined2 *)(*(int *)(uVar4 + 0x30) + iVar7 * 2));
            json_object_array_add(iVar1,uVar6);
          }
          for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(uVar4 + 10); iVar7 = iVar7 + 1) {
            uVar6 = json_object_new_int(*(undefined2 *)(*(int *)(uVar4 + 0x34) + iVar7 * 4));
            json_object_array_add(iVar2,uVar6);
            uVar4 = param_1[1];
          }
          iVar7 = 0;
          while (iVar7 < (int)(uint)*(byte *)(param_1[1] + 0xb)) {
            iVar5 = json_object_new_object();
            if (iVar5 == 0) {
              if (sensor_test_err_switch == '\0') {
                iVar7 = iVar7 + 1;
              }
              else {
                printf("[SENSOR_TEST_ERROR]%s()/%d ssid_info_item_obj create fail, continue\n",
                       "_sensor_test_sqlite_case_update",0x180);
                iVar7 = iVar7 + 1;
              }
            }
            else {
              memset(auStack_834,0,0x205);
              iVar8 = iVar7 * 0x220;
              wserv_db_get_entry_by_id
                        (*(undefined4 *)(*(int *)(param_1[1] + 0x38) + iVar8),auStack_834);
              memset(auStack_998,0,100);
              FUN_00408420(auStack_704,0x32,auStack_998,100);
              uVar6 = json_object_new_string(auStack_998);
              json_object_object_add(iVar5,"ssid_name",uVar6);
              memset(acStack_934,0,0x100);
              snprintf(acStack_934,0x100,"%d",local_708);
              uVar6 = json_object_new_string(acStack_934);
              json_object_object_add(iVar5,"ssid_code_type",uVar6);
              uVar6 = json_object_new_int(*(undefined4 *)(*(int *)(param_1[1] + 0x38) + iVar8));
              json_object_object_add(iVar5,"serv_id",uVar6);
              uVar6 = json_object_new_int(*(undefined4 *)(*(int *)(param_1[1] + 0x38) + iVar8 + 4));
              json_object_object_add(iVar5,"freqband",uVar6);
              uVar6 = json_object_new_int(*(undefined4 *)(*(int *)(param_1[1] + 0x38) + iVar8 + 8));
              json_object_object_add(iVar5,"support_freqband",uVar6);
              uVar6 = json_object_new_int(local_6ca);
              json_object_object_add(iVar5,"encryption",uVar6);
              uVar6 = json_object_new_string(*(int *)(param_1[1] + 0x38) + iVar8 + 0x10);
              json_object_object_add(iVar5,"radius_type",uVar6);
              uVar6 = json_object_new_string(*(int *)(param_1[1] + 0x38) + iVar8 + 0x30);
              json_object_object_add(iVar5,"radius_key",uVar6);
              uVar6 = json_object_new_string(*(int *)(param_1[1] + 0x38) + iVar8 + 0xa8);
              json_object_object_add(iVar5,"radius_name",uVar6);
              json_object_array_add(iVar3,iVar5);
              iVar7 = iVar7 + 1;
            }
          }
          iVar7 = json_object_to_json_string_ext(iVar1,0);
          if (iVar7 == 0) {
            iVar7 = -1;
            if (sensor_test_err_switch == '\0') goto LAB_0050215c;
            __format = "[SENSOR_TEST_ERROR]%s()/%d generate field_group_id_str fail\n";
            uVar6 = 0x198;
          }
          else {
            iVar5 = json_object_to_json_string_ext(iVar2,0);
            if (iVar5 == 0) {
              iVar7 = -1;
              if (sensor_test_err_switch == '\0') goto LAB_0050215c;
              __format = "[SENSOR_TEST_ERROR]%s()/%d generate field_join_test_sensor_str fail\n";
              uVar6 = 0x19f;
            }
            else {
              iVar8 = json_object_to_json_string_ext(iVar3,0);
              if (iVar8 == 0) {
                iVar7 = -1;
                if (sensor_test_err_switch == '\0') goto LAB_0050215c;
                __format = "[SENSOR_TEST_ERROR]%s()/%d generate field_ssid_info_str fail\n";
                uVar6 = 0x1a6;
              }
              else {
                snprintf(acStack_62c,0x600,
                         "UPDATE %s SET %s = \'%d\', %s = \'%s\', %s = \'%s\', %s = \'%s\' WHERE %s = \'%d\';"
                         ,"testcase_tbl","change_id",(uint)*(byte *)(param_1[1] + 8),"group_id",
                         iVar7,"join_test_sensor",iVar5,"ssid_info",iVar8,"test_case_id",*param_1);
                iVar7 = FUN_00407d60(l_sensor_test_db_ptr,acStack_62c);
                if (iVar7 != 0) {
                  iVar5 = FUN_00408410();
                  if (iVar5 != 0) {
                    printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                           "_sensor_test_sqlite_case_update",0x1b9,iVar7,acStack_62c,
                           "Failed to insert into table in flash.");
                  }
                  goto LAB_0050215c;
                }
                if (sensor_test_debug_switch == '\0') goto LAB_0050215c;
                __format = "[SENSOR_TEST_DEBUG]%s()/%d sqlite case update success\n";
                uVar6 = 0x1bb;
              }
            }
          }
        }
        printf(__format,"_sensor_test_sqlite_case_update",uVar6);
      }
    }
  }
LAB_0050215c:
  sensor_test_db_case_setting_mem_free(param_1[1]);
  param_1[1] = 0;
  FUN_00407df0(param_1);
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  if (iVar3 != 0) {
    json_object_put(iVar3);
  }
  return iVar7;
}

