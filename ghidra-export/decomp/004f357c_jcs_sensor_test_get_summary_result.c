// func jcs_sensor_test_get_summary_result @ 004f357c size=2152

void jcs_sensor_test_get_summary_result(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ushort *puVar6;
  short sVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined8 uVar14;
  undefined4 uVar15;
  short local_150 [2];
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  ushort local_13c [4];
  char acStack_134 [260];
  time_t local_30;
  int local_2c;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs_sensor_test_get_summary_result ENTER\n",
           "jcs_sensor_test_get_summary_result",0x1616);
  }
  local_13c[0] = 0;
  local_13c[1] = 0;
  local_13c[2] = 0;
  local_140 = 0xffffffff;
  local_144 = 0;
  local_150[0] = 0;
  local_148 = 0;
  local_14c = 0;
  uVar1 = sensor_test_db_get_case_num_max();
  iVar2 = json_object_object_get(param_1,"test_case_id");
  if (iVar2 == 0) {
    if (sensor_test_err_switch != '\0') {
      pcVar8 = "[SENSOR_TEST_ERROR]%s()/%d get test_case_id fail\n";
      uVar4 = 0x1634;
LAB_004f3bc4:
      iVar3 = 0;
      iVar2 = 0;
      printf(pcVar8,"jcs_sensor_test_get_summary_result",uVar4);
      goto LAB_004f3714;
    }
LAB_004f370c:
    iVar3 = 0;
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar10 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar14 = json_object_get_double(iVar2);
        uVar10 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
      }
      else {
        uVar10 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "jcs_sensor_test_get_summary_result",0x1637);
        }
      }
    }
    iVar2 = json_object_object_get(param_1,"test_type");
    if (iVar2 == 0) {
      if (sensor_test_err_switch != '\0') {
        pcVar8 = "[SENSOR_TEST_ERROR]%s()/%d get test_type fail\n";
        uVar4 = 0x163d;
        goto LAB_004f3bc4;
      }
      goto LAB_004f370c;
    }
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar11 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar14 = json_object_get_double(iVar2);
        uVar11 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
      }
      else {
        uVar11 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "jcs_sensor_test_get_summary_result",0x1640);
        }
      }
    }
    iVar12 = -1;
    iVar2 = json_object_object_get(param_1,"ser_index");
    if (iVar2 != 0) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        sVar7 = json_object_get_int(iVar2);
        iVar12 = (int)sVar7;
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 == 2) {
          uVar14 = json_object_get_double(iVar2);
          sVar7 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
          iVar12 = (int)sVar7;
        }
        else if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "jcs_sensor_test_get_summary_result",0x1646);
        }
      }
    }
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d parse test_case_id=%d, test_type=%d, serindex=%d\n",
             "jcs_sensor_test_get_summary_result",0x164d,uVar10,uVar11,iVar12);
    }
    if (((int)uVar10 < 0) || (uVar1 <= uVar10)) {
      if (sensor_test_err_switch == '\0') goto LAB_004f370c;
      pcVar8 = "[SENSOR_TEST_ERROR]%s()/%d invalid test_case_id=%d\n";
      uVar4 = 0x1652;
      uVar11 = uVar10;
LAB_004f37b8:
      printf(pcVar8,"jcs_sensor_test_get_summary_result",uVar4,uVar11);
      iVar3 = 0;
    }
    else {
      if (8 < uVar11) {
        if (sensor_test_err_switch == '\0') goto LAB_004f370c;
        pcVar8 = "[SENSOR_TEST_ERROR]%s()/%d invalid test_type=%d\n";
        uVar4 = 0x1659;
        goto LAB_004f37b8;
      }
      iVar3 = json_object_new_array();
      if (iVar3 == 0) {
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d Create summary_result_obj failed\n",
                 "jcs_sensor_test_get_summary_result",0x1660);
          iVar2 = 0;
          goto LAB_004f3714;
        }
      }
      else {
        local_30 = time((time_t *)0x0);
        iVar2 = sensor_test_db_get_case_start_time(uVar10,&local_144,local_150);
        if (iVar2 == -1) {
          iVar2 = 0;
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d get_case_start_time fail, id=%d\n",
                   "jcs_sensor_test_get_summary_result",0x1669,uVar10);
            goto LAB_004f3714;
          }
        }
        else {
          iVar9 = 1;
          if (local_150[0] != 0) {
            iVar9 = _sensor_test_calc_total_test_round(local_144,(int)local_150[0],local_30);
          }
          if (sensor_test_debug_switch != '\0') {
            printf("[SENSOR_TEST_DEBUG]%s()/%d case_id=%d, test_round=%d\n",
                   "jcs_sensor_test_get_summary_result",0x1675,uVar10,iVar9);
          }
          while( true ) {
            if (iVar9 < 1) {
              if (sensor_test_debug_switch != '\0') {
                printf("[SENSOR_TEST_DEBUG]%s()/%d jcs_sensor_test_get_summary_result success EXIT\n"
                       ,"jcs_sensor_test_get_summary_result",0x16ad);
              }
              json_object_object_add(param_2,"sensor_test_summary",iVar3);
              uVar4 = json_object_new_int(0);
              json_object_object_add(param_2,&DAT_00676a24,uVar4);
              return;
            }
            if (local_150[0] < 1) break;
            _sensor_test_calc_time_interval
                      (local_144,(int)local_150[0],local_30,iVar9,&local_148,&local_14c);
            sensor_test_db_get_summary_result
                      (uVar10,uVar11,iVar12,local_148,local_14c,&local_140,local_13c);
            uVar4 = local_148;
LAB_004f3974:
            iVar2 = json_object_new_object();
            if (iVar2 == 0) {
              if (sensor_test_err_switch != '\0') {
                pcVar8 = "[SENSOR_TEST_ERROR]%s()/%d Create summary_result_item_obj failed\n";
                uVar4 = 0x168f;
                goto LAB_004f3d64;
              }
              goto LAB_004f3714;
            }
            memset(acStack_134,0,0x100);
            uVar15 = 0;
            snprintf(acStack_134,0x100,"%lld");
            uVar5 = json_object_new_string(acStack_134);
            json_object_object_add(iVar2,"sch_start_time",uVar5);
            memset(acStack_134,0,0x100);
            snprintf(acStack_134,0x100,"%d",local_140,uVar15,uVar4);
            uVar4 = json_object_new_string(acStack_134);
            json_object_object_add(iVar2,"brief_result",uVar4);
            local_2c = json_object_new_array();
            if (local_2c == 0) {
              if (sensor_test_err_switch != '\0') {
                pcVar8 = "[SENSOR_TEST_ERROR]%s()/%d Create result_list_obj failed\n";
                uVar4 = 0x169a;
                goto LAB_004f3d64;
              }
              goto LAB_004f3714;
            }
            iVar13 = 0;
            do {
              memset(acStack_134,0,0x100);
              puVar6 = (ushort *)((int)local_13c + iVar13);
              iVar13 = iVar13 + 2;
              snprintf(acStack_134,0x100,"%d",(uint)*puVar6);
              uVar4 = json_object_new_string(acStack_134);
              json_object_array_add(local_2c,uVar4);
            } while (iVar13 != 6);
            iVar9 = iVar9 + -1;
            json_object_object_add(iVar2,"brief_result_list",local_2c);
            memset(acStack_134,0,0x100);
            snprintf(acStack_134,0x100,"%d",uVar10);
            uVar4 = json_object_new_string(acStack_134);
            json_object_object_add(iVar2,"test_case_id",uVar4);
            memset(acStack_134,0,0x100);
            snprintf(acStack_134,0x100,"%d",uVar11);
            uVar4 = json_object_new_string(acStack_134);
            json_object_object_add(iVar2,"test_type",uVar4);
            memset(acStack_134,0,0x100);
            snprintf(acStack_134,0x100,"%d",iVar12);
            uVar4 = json_object_new_string(acStack_134);
            json_object_object_add(iVar2,"ser_index",uVar4);
            json_object_array_add(iVar3,iVar2);
          }
          iVar2 = sensor_test_db_get_summary_result
                            (uVar10,uVar11,iVar12,0,local_30,&local_140,local_13c);
          uVar4 = local_144;
          if (iVar2 != -1) goto LAB_004f3974;
          iVar2 = 0;
          if (sensor_test_err_switch != '\0') {
            pcVar8 = "[SENSOR_TEST_ERROR]%s()/%d get_summary_result fail\n";
            uVar4 = 0x167e;
LAB_004f3d64:
            printf(pcVar8,"jcs_sensor_test_get_summary_result",uVar4);
            goto LAB_004f3714;
          }
        }
      }
    }
  }
  iVar2 = 0;
LAB_004f3714:
  if (sensor_test_warning_switch != '\0') {
    printf("[SENSOR_TEST_WARNING]%s()/%d jcs_sensor_test_get_summary_result fail EXIT\n",
           "jcs_sensor_test_get_summary_result",0x16b4);
  }
  uVar4 = json_object_new_int(1);
  json_object_object_add(param_2,&DAT_00676a24,uVar4);
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  if (iVar3 != 0) {
    json_object_put(iVar3);
  }
  return;
}

