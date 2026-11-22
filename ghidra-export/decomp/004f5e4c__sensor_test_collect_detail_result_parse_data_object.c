// func _sensor_test_collect_detail_result_parse_data_object @ 004f5e4c size=1

undefined4
_sensor_test_collect_detail_result_parse_data_object
          (undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  undefined1 uVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined8 uVar13;
  char acStack_80 [39];
  undefined1 uStack_59;
  char acStack_58 [39];
  undefined1 uStack_31;
  int iStack_30;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_collect_detail_result_parse_data_object ENTER, test_type=%d\n"
           ,"_sensor_test_collect_detail_result_parse_data_object",0x1085,param_2);
  }
  switch(param_2) {
  case 0:
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d parse_data_onboarding_object ENTER\n",
             "_sensor_test_collect_detail_result_parse_data_onboarding_object",0xf80);
    }
    *(undefined1 *)(param_3 + 0x11) = 0;
    *(undefined4 *)(param_3 + 4) = 0;
    *(undefined1 *)(param_3 + 0x13) = 0;
    *(undefined4 *)(param_3 + 0xc) = 0;
    uVar1 = json_object_array_length(param_1);
    if ((int)uVar1 < 1) {
      if (sensor_test_debug_switch == '\0') {
        *(undefined1 *)(param_3 + 0x12) = 0;
        *(undefined4 *)(param_3 + 8) = 0;
      }
      else {
        printf("[SENSOR_TEST_DEBUG]%s()/%d data array\'s length <= 0\n",
               "_sensor_test_collect_detail_result_parse_data_onboarding_object",0xf92);
        *(undefined1 *)(param_3 + 0x12) = 0;
        *(undefined4 *)(param_3 + 8) = 0;
      }
      return 0;
    }
    *(undefined4 *)(param_3 + 8) = 0;
    *(char *)(param_3 + 0x12) = (char)uVar1;
    pvVar2 = (void *)FUN_00408450((uVar1 & 0xff) << 4,0xf9a);
    *(void **)(param_3 + 8) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      memset(pvVar2,0,(uint)*(byte *)(param_3 + 0x12) << 4);
      iVar10 = 0;
      uVar11 = 0;
      do {
        uVar3 = json_object_array_get_idx(param_1,uVar11);
        iVar12 = json_object_object_get(uVar3,"retryTime");
        if (iVar12 == 0) {
LAB_004f639c:
          if (jcs_err_switch == 0) {
            iVar12 = *(int *)(param_3 + 8);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_collect_detail_result_parse_data_onboarding_object",0xfa7);
            iVar12 = *(int *)(param_3 + 8);
          }
          *(undefined1 *)(iVar12 + iVar10 + 0xc) = 0xff;
        }
        else {
          iVar4 = json_object_get_type(iVar12);
          if (iVar4 == 3) {
            iVar4 = *(int *)(param_3 + 8);
            uVar8 = json_object_get_int(iVar12);
            *(undefined1 *)(iVar4 + iVar10 + 0xc) = uVar8;
          }
          else {
            iVar4 = json_object_get_type(iVar12);
            if (iVar4 != 2) goto LAB_004f639c;
            iVar4 = *(int *)(param_3 + 8);
            uVar13 = json_object_get_double(iVar12);
            uVar8 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            *(undefined1 *)(iVar4 + iVar10 + 0xc) = uVar8;
          }
        }
        iVar12 = json_object_object_get(uVar3,"errorCode");
        if (iVar12 == 0) {
LAB_004f6260:
          if (jcs_err_switch == 0) {
            iVar12 = *(int *)(param_3 + 8);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_collect_detail_result_parse_data_onboarding_object",0xfaa);
            iVar12 = *(int *)(param_3 + 8);
          }
          *(undefined4 *)(iVar12 + iVar10) = 0xffffffff;
        }
        else {
          iVar4 = json_object_get_type(iVar12);
          if (iVar4 == 3) {
            iVar4 = *(int *)(param_3 + 8);
            uVar6 = json_object_get_int(iVar12);
            *(undefined4 *)(iVar4 + iVar10) = uVar6;
          }
          else {
            iVar4 = json_object_get_type(iVar12);
            if (iVar4 != 2) goto LAB_004f6260;
            iVar4 = *(int *)(param_3 + 8);
            uVar13 = json_object_get_double(iVar12);
            uVar6 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            *(undefined4 *)(iVar4 + iVar10) = uVar6;
          }
        }
        iVar12 = json_object_object_get(uVar3,"duration");
        if (iVar12 == 0) {
LAB_004f62c0:
          if (jcs_err_switch == 0) {
            iVar12 = *(int *)(param_3 + 8);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_collect_detail_result_parse_data_onboarding_object",0xfad);
            iVar12 = *(int *)(param_3 + 8);
          }
          *(undefined4 *)(iVar12 + iVar10 + 8) = 0xffffffff;
        }
        else {
          iVar4 = json_object_get_type(iVar12);
          if (iVar4 == 3) {
            iVar4 = *(int *)(param_3 + 8);
            uVar6 = json_object_get_int(iVar12);
            *(undefined4 *)(iVar4 + iVar10 + 8) = uVar6;
          }
          else {
            iVar4 = json_object_get_type(iVar12);
            if (iVar4 != 2) goto LAB_004f62c0;
            iVar4 = *(int *)(param_3 + 8);
            uVar13 = json_object_get_double(iVar12);
            uVar6 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            *(undefined4 *)(iVar4 + iVar10 + 8) = uVar6;
          }
        }
        iVar12 = json_object_object_get(uVar3,"startTime");
        if (iVar12 == 0) {
LAB_004f6320:
          if (jcs_err_switch == 0) {
            iVar12 = *(int *)(param_3 + 8);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_collect_detail_result_parse_data_onboarding_object",0xfb0);
            iVar12 = *(int *)(param_3 + 8);
          }
          *(undefined4 *)(iVar12 + iVar10 + 4) = 0xffffffff;
        }
        else {
          iVar4 = json_object_get_type(iVar12);
          if (iVar4 == 3) {
            iVar4 = *(int *)(param_3 + 8);
            uVar3 = json_object_get_int(iVar12);
            *(undefined4 *)(iVar4 + iVar10 + 4) = uVar3;
          }
          else {
            iVar4 = json_object_get_type(iVar12);
            if (iVar4 != 2) goto LAB_004f6320;
            iVar4 = *(int *)(param_3 + 8);
            uVar13 = json_object_get_double(iVar12);
            uVar3 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            *(undefined4 *)(iVar4 + iVar10 + 4) = uVar3;
          }
        }
        uVar11 = uVar11 + 1;
        iVar10 = iVar10 + 0x10;
        if (uVar11 == uVar1) {
          return 0;
        }
      } while( true );
    }
    if (sensor_test_err_switch == '\0') goto LAB_004f6b38;
    pcVar9 = "_sensor_test_collect_detail_result_parse_data_onboarding_object";
    uVar3 = 0xf9d;
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 8:
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d parse_data_common_object ENTER\n",
             "_sensor_test_collect_detail_result_parse_data_common_object",0x101c);
    }
    memset(acStack_58,0,0x28);
    *(undefined1 *)(param_3 + 0x12) = 0;
    *(undefined1 *)(param_3 + 0x13) = 0;
    *(undefined4 *)(param_3 + 8) = 0;
    *(undefined4 *)(param_3 + 0xc) = 0;
    uVar1 = json_object_array_length(param_1);
    if ((int)uVar1 < 1) {
      if (sensor_test_debug_switch == '\0') {
        *(undefined1 *)(param_3 + 0x11) = 0;
        *(undefined4 *)(param_3 + 4) = 0;
      }
      else {
        printf("[SENSOR_TEST_DEBUG]%s()/%d data array\'s length <= 0 \n",
               "_sensor_test_collect_detail_result_parse_data_common_object",0x102e);
        *(undefined1 *)(param_3 + 0x11) = 0;
        *(undefined4 *)(param_3 + 4) = 0;
      }
      return 0;
    }
    *(undefined4 *)(param_3 + 4) = 0;
    uVar11 = 5;
    if ((int)uVar1 < 6) {
      uVar11 = uVar1;
    }
    *(char *)(param_3 + 0x11) = (char)uVar11;
    pvVar2 = (void *)FUN_00408450((uVar11 & 0xff) * 0x1c,0x1037);
    *(void **)(param_3 + 4) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      iVar10 = 0;
      iVar12 = 0;
      memset(pvVar2,0,(uint)*(byte *)(param_3 + 0x11) * 0x1c);
      do {
        uVar3 = json_object_array_get_idx(param_1,iVar12);
        iVar4 = json_object_object_get(uVar3,"errorCode");
        if (iVar4 == 0) {
LAB_004f60e4:
          if (jcs_err_switch == 0) {
            iVar4 = *(int *)(param_3 + 4);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_collect_detail_result_parse_data_common_object",0x1044);
            iVar4 = *(int *)(param_3 + 4);
          }
          *(undefined4 *)(iVar4 + iVar10 + 0x14) = 0xffffffff;
        }
        else {
          iVar5 = json_object_get_type(iVar4);
          if (iVar5 == 3) {
            iVar5 = *(int *)(param_3 + 4);
            uVar6 = json_object_get_int(iVar4);
            *(undefined4 *)(iVar5 + iVar10 + 0x14) = uVar6;
          }
          else {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 != 2) goto LAB_004f60e4;
            iVar5 = *(int *)(param_3 + 4);
            uVar13 = json_object_get_double(iVar4);
            uVar6 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            *(undefined4 *)(iVar5 + iVar10 + 0x14) = uVar6;
          }
        }
        iVar4 = json_object_object_get(uVar3,"duration");
        if (iVar4 == 0) {
LAB_004f6144:
          if (jcs_err_switch == 0) {
            iVar4 = *(int *)(param_3 + 4);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_collect_detail_result_parse_data_common_object",0x1047);
            iVar4 = *(int *)(param_3 + 4);
          }
          *(undefined2 *)(iVar4 + iVar10 + 0x18) = 0xffff;
        }
        else {
          iVar5 = json_object_get_type(iVar4);
          if (iVar5 == 3) {
            iVar5 = *(int *)(param_3 + 4);
            uVar7 = json_object_get_int(iVar4);
            *(undefined2 *)(iVar5 + iVar10 + 0x18) = uVar7;
          }
          else {
            iVar5 = json_object_get_type(iVar4);
            if (iVar5 != 2) goto LAB_004f6144;
            iVar5 = *(int *)(param_3 + 4);
            uVar13 = json_object_get_double(iVar4);
            uVar7 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            *(undefined2 *)(iVar5 + iVar10 + 0x18) = uVar7;
          }
        }
        iStack_30 = *(int *)(param_3 + 4);
        if (sensor_test_debug_switch != '\0') {
          printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_collect_detail_result_parse_ip_object ENTER\n"
                 ,"_sensor_test_collect_detail_result_parse_ip_object",0xf36);
        }
        memset(acStack_80,0,0x28);
        iVar4 = json_object_object_get(uVar3,&DAT_00677c24);
        if (iVar4 == 0) {
LAB_004f5ff8:
          if (sensor_test_warning_switch != '\0') {
            pcVar9 = "[SENSOR_TEST_WARNING]%s()/%d no ip infomation\n";
            uVar6 = 0xf73;
LAB_004f66e8:
            printf(pcVar9,"_sensor_test_collect_detail_result_parse_ip_object",uVar6);
          }
        }
        else {
          iVar5 = json_object_get_type(iVar4);
          if (iVar5 != 6) {
            iVar5 = json_object_get_type(iVar4);
            if ((iVar5 != 5) &&
               ((iVar5 = json_object_get_type(iVar4), iVar5 != 4 ||
                (iVar4 = json_object_object_length(iVar4), iVar4 != 0)))) goto LAB_004f5ff8;
            if (sensor_test_debug_switch == '\0') goto LAB_004f6008;
            pcVar9 = "[SENSOR_TEST_DEBUG]%s()/%d find ip array\n";
            uVar6 = 0xf52;
            goto LAB_004f66e8;
          }
          memset(acStack_80,0,0x28);
          iVar5 = json_object_get_type(iVar4);
          if (iVar5 == 6) {
            pcVar9 = (char *)json_object_get_string(iVar4);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_sensor_test_collect_detail_result_parse_ip_object",0xf4d);
            }
            pcVar9 = "";
          }
          strncpy(acStack_80,pcVar9,0x27);
          uStack_59 = 0;
          FUN_0051a7a8(acStack_80,iStack_30 + iVar10);
        }
LAB_004f6008:
        iVar4 = json_object_object_get(uVar3,"domainServerIp");
        if (iVar4 != 0) {
          memset(acStack_58,0,0x28);
          iVar5 = json_object_get_type(iVar4);
          if (iVar5 == 6) {
            pcVar9 = (char *)json_object_get_string(iVar4);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_sensor_test_collect_detail_result_parse_data_common_object",0x1054);
            }
            pcVar9 = "";
          }
          strncpy(acStack_58,pcVar9,0x27);
          uStack_31 = 0;
          iVar4 = FUN_0051a7a8(acStack_58,*(int *)(param_3 + 4) + iVar10);
          if (iVar4 == -1) {
            if (sensor_test_warning_switch == '\0') {
              iVar4 = *(int *)(param_3 + 4);
            }
            else {
              printf("[SENSOR_TEST_WARNING]%s()/%d collect domainServerip is not either ipv4 or ipv6\n"
                     ,"_sensor_test_collect_detail_result_parse_data_common_object",0x1057);
              iVar4 = *(int *)(param_3 + 4);
            }
            *(undefined1 *)(iVar4 + iVar10) = 0;
          }
        }
        iVar12 = iVar12 + 1;
        iVar10 = iVar10 + 0x1c;
        if ((int)uVar11 <= iVar12) {
          return 0;
        }
      } while( true );
    }
    if (sensor_test_err_switch == '\0') goto LAB_004f6b38;
    pcVar9 = "_sensor_test_collect_detail_result_parse_data_common_object";
    uVar3 = 0x103a;
    break;
  case 7:
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d parse_data_speed_object ENTER\n",
             "_sensor_test_collect_detail_result_parse_data_speed_object",0xfbd);
    }
    *(undefined1 *)(param_3 + 0x12) = 0;
    *(undefined4 *)(param_3 + 8) = 0;
    *(undefined1 *)(param_3 + 0x11) = 0;
    *(undefined4 *)(param_3 + 4) = 0;
    uVar1 = json_object_array_length(param_1);
    if ((int)uVar1 < 1) {
      if (sensor_test_debug_switch == '\0') {
        *(undefined1 *)(param_3 + 0x13) = 0;
        *(undefined4 *)(param_3 + 0xc) = 0;
      }
      else {
        printf("[SENSOR_TEST_DEBUG]%s()/%d data array\'s length <= 0\n",
               "_sensor_test_collect_detail_result_parse_data_speed_object",0xfd0);
        *(undefined1 *)(param_3 + 0x13) = 0;
        *(undefined4 *)(param_3 + 0xc) = 0;
      }
      return 0;
    }
    *(undefined4 *)(param_3 + 0xc) = 0;
    *(char *)(param_3 + 0x13) = (char)uVar1;
    pvVar2 = (void *)FUN_00408450((uVar1 & 0xff) << 3,0xfd8);
    *(void **)(param_3 + 0xc) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      memset(pvVar2,0,(uint)*(byte *)(param_3 + 0x13) << 3);
      iVar10 = 0;
      uVar11 = 0;
      do {
        uVar3 = json_object_array_get_idx(param_1,uVar11);
        iVar12 = json_object_object_get(uVar3,"downloadSpeed");
        if (iVar12 == 0) {
LAB_004f65c8:
          if (jcs_err_switch == 0) {
            iVar12 = *(int *)(param_3 + 0xc);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_collect_detail_result_parse_data_speed_object",0xfe5);
            iVar12 = *(int *)(param_3 + 0xc);
          }
          *(undefined2 *)(iVar12 + iVar10) = 0xffff;
        }
        else {
          iVar4 = json_object_get_type(iVar12);
          if (iVar4 == 3) {
            iVar4 = *(int *)(param_3 + 0xc);
            uVar7 = json_object_get_int(iVar12);
            *(undefined2 *)(iVar4 + iVar10) = uVar7;
          }
          else {
            iVar4 = json_object_get_type(iVar12);
            if (iVar4 != 2) goto LAB_004f65c8;
            iVar4 = *(int *)(param_3 + 0xc);
            uVar13 = json_object_get_double(iVar12);
            uVar7 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            *(undefined2 *)(iVar4 + iVar10) = uVar7;
          }
        }
        iVar12 = json_object_object_get(uVar3,"uploadSpeed");
        if (iVar12 == 0) {
LAB_004f648c:
          if (jcs_err_switch == 0) {
            iVar12 = *(int *)(param_3 + 0xc);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_collect_detail_result_parse_data_speed_object",0xfe8);
            iVar12 = *(int *)(param_3 + 0xc);
          }
          *(undefined2 *)(iVar12 + iVar10 + 2) = 0xffff;
        }
        else {
          iVar4 = json_object_get_type(iVar12);
          if (iVar4 == 3) {
            iVar4 = *(int *)(param_3 + 0xc);
            uVar7 = json_object_get_int(iVar12);
            *(undefined2 *)(iVar4 + iVar10 + 2) = uVar7;
          }
          else {
            iVar4 = json_object_get_type(iVar12);
            if (iVar4 != 2) goto LAB_004f648c;
            iVar4 = *(int *)(param_3 + 0xc);
            uVar13 = json_object_get_double(iVar12);
            uVar7 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            *(undefined2 *)(iVar4 + iVar10 + 2) = uVar7;
          }
        }
        iVar12 = json_object_object_get(uVar3,"latency");
        if (iVar12 == 0) {
LAB_004f64ec:
          if (jcs_err_switch == 0) {
            iVar12 = *(int *)(param_3 + 0xc);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_collect_detail_result_parse_data_speed_object",0xfeb);
            iVar12 = *(int *)(param_3 + 0xc);
          }
          *(undefined2 *)(iVar12 + iVar10 + 4) = 0xffff;
        }
        else {
          iVar4 = json_object_get_type(iVar12);
          if (iVar4 == 3) {
            iVar4 = *(int *)(param_3 + 0xc);
            uVar7 = json_object_get_int(iVar12);
            *(undefined2 *)(iVar4 + iVar10 + 4) = uVar7;
          }
          else {
            iVar4 = json_object_get_type(iVar12);
            if (iVar4 != 2) goto LAB_004f64ec;
            iVar4 = *(int *)(param_3 + 0xc);
            uVar13 = json_object_get_double(iVar12);
            uVar7 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            *(undefined2 *)(iVar4 + iVar10 + 4) = uVar7;
          }
        }
        iVar12 = json_object_object_get(uVar3,"distance");
        if (iVar12 == 0) {
LAB_004f654c:
          if (jcs_err_switch == 0) {
            iVar12 = *(int *)(param_3 + 0xc);
          }
          else {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_sensor_test_collect_detail_result_parse_data_speed_object",0xfee);
            iVar12 = *(int *)(param_3 + 0xc);
          }
          *(undefined2 *)(iVar12 + iVar10 + 6) = 0xffff;
        }
        else {
          iVar4 = json_object_get_type(iVar12);
          if (iVar4 == 3) {
            iVar4 = *(int *)(param_3 + 0xc);
            uVar7 = json_object_get_int(iVar12);
            *(undefined2 *)(iVar4 + iVar10 + 6) = uVar7;
          }
          else {
            iVar4 = json_object_get_type(iVar12);
            if (iVar4 != 2) goto LAB_004f654c;
            iVar4 = *(int *)(param_3 + 0xc);
            uVar13 = json_object_get_double(iVar12);
            uVar7 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            *(undefined2 *)(iVar4 + iVar10 + 6) = uVar7;
          }
        }
        uVar11 = uVar11 + 1;
        iVar10 = iVar10 + 8;
        if (uVar11 == uVar1) {
          return 0;
        }
      } while( true );
    }
    if (sensor_test_err_switch == '\0') goto LAB_004f6b38;
    pcVar9 = "_sensor_test_collect_detail_result_parse_data_speed_object";
    uVar3 = 0xfdb;
    break;
  default:
    if (sensor_test_warning_switch != '\0') {
      printf("[SENSOR_TEST_WARNING]%s()/%d No matched test type for further data parsing\n",
             "_sensor_test_collect_detail_result_parse_data_object",0x109c);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n",pcVar9,uVar3);
LAB_004f6b38:
  sensor_test_db_stage_nested_mem_free(param_3);
  return 0xffffffff;
}

