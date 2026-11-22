// func sensor_test_result_collect_cb @ 004f6bb0 size=4824

undefined4 sensor_test_result_collect_cb(undefined2 *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  void *__s;
  undefined1 uVar7;
  char cVar8;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  char *pcVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined4 local_50;
  uint local_4c;
  undefined2 local_48;
  char local_44 [12];
  uint local_38;
  char local_34 [12];
  uint local_28;
  uint local_24;
  
  if ((param_1 == (undefined2 *)0x0) || (*(int *)(param_1 + 0xc) == 0)) {
    uVar10 = 0xffffffff;
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar1 = "[SENSOR_TEST_ERROR]%s()/%d find input data or data->param is null\n";
    uVar5 = 0x1ef6;
LAB_004f6ce4:
    printf(pcVar1,"sensor_test_result_collect_cb",uVar5);
    return uVar10;
  }
  pcVar1 = (char *)json_object_to_json_string_ext(*(int *)(param_1 + 0xc),0);
  pcVar1 = strdup(pcVar1);
  if (pcVar1 == (char *)0x0) {
    uVar10 = 0;
    if (sensor_test_err_switch == '\0') {
      return 0;
    }
    pcVar1 = "[SENSOR_TEST_ERROR]%s()/%d Malloc json_str failed\n";
    uVar5 = 0x1f00;
    goto LAB_004f6ce4;
  }
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d RECEIVED JSON IS:%s\n","sensor_test_result_collect_cb",0x1f03
           ,pcVar1);
  }
  free(pcVar1);
  iVar2 = json_object_object_get(*(undefined4 *)(param_1 + 0xc),"changeId");
  if (iVar2 == 0) {
    uVar10 = *(undefined4 *)(param_1 + 4);
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar10 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar11 = json_object_get_double(iVar2);
        uVar10 = __fixdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
      else {
        uVar10 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "sensor_test_result_collect_cb",0x1f0b);
        }
      }
    }
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d changeid from params is=%d\n",
             "sensor_test_result_collect_cb",0x1f0c,uVar10);
    }
  }
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d result_collect_cb ENTER,operation_id=%d, change_id=%d\n",
           "sensor_test_result_collect_cb",0x1f12,*(undefined4 *)(param_1 + 2),uVar10);
  }
  iVar2 = sensor_test_db_is_test_case_id_legal(*(undefined4 *)(param_1 + 2));
  if ((iVar2 == 0) ||
     (iVar2 = sensor_test_db_is_change_id_equal(*(undefined4 *)(param_1 + 2),uVar10), iVar2 == 0)) {
    uVar10 = 0;
    if (sensor_test_debug_switch == '\0') {
      return 0;
    }
    pcVar1 = "[SENSOR_TEST_DEBUG]%s()/%d test_case_id is illegal or changeid not match,EXIT\n";
    uVar5 = 0x1f17;
    goto LAB_004f6ce4;
  }
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_collect_result ENTER\n",
           "_sensor_test_collect_result",0x1238);
  }
  pcVar1 = (char *)FUN_00408450(0x3a,0x1243);
  if (pcVar1 == (char *)0x0) {
    __s = (void *)0x0;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n","_sensor_test_collect_result",0x1246);
      __s = (void *)0x0;
    }
    goto LAB_004f7664;
  }
  memset(pcVar1,0,0x3a);
  if (sensor_test_debug_switch == '\0') {
    uVar10 = *(undefined4 *)(param_1 + 0xc);
  }
  else {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_collect_result_basic_info ENTER\n",
           "_sensor_test_collect_result_basic_info",0x1214);
    uVar10 = *(undefined4 *)(param_1 + 0xc);
  }
  *(undefined2 *)(pcVar1 + 0x32) = *param_1;
  local_34[0] = '\0';
  local_34[1] = '\0';
  local_34[2] = '\0';
  local_34[3] = '\0';
  local_34[4] = '\0';
  local_34[5] = '\0';
  local_34[6] = '\0';
  local_34[7] = '\0';
  local_34[8] = '\0';
  local_34[9] = '\0';
  local_34[10] = '\0';
  local_34[0xb] = '\0';
  local_28 = 0;
  local_24 = 0;
  iVar2 = json_object_object_get(uVar10,"bssid");
  if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_sensor_test_collect_result_basic_info",0x1226);
    }
    pcVar9 = "";
  }
  else {
    pcVar9 = (char *)json_object_get_string(iVar2);
  }
  strncpy(local_34,pcVar9,0x13);
  local_24 = local_24 & 0xffffff00;
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d begin str2mac, bssid_str=%s\n",
           "_sensor_test_collect_result_basic_info",0x1227,local_34);
  }
  _str2mac(local_34,pcVar1 + 0x34);
  printmac(pcVar1 + 0x34);
  iVar2 = json_object_object_get(uVar10,"ssid");
  if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_sensor_test_collect_result_basic_info",0x122c);
    }
    pcVar9 = "";
  }
  else {
    pcVar9 = (char *)json_object_get_string(iVar2);
  }
  strncpy(pcVar1,pcVar9,0x31);
  pcVar1[0x31] = '\0';
  __s = (void *)FUN_00408450(0x34,0x1254);
  if (__s == (void *)0x0) {
    if (sensor_test_err_switch == '\0') goto LAB_004f7664;
    pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
    uVar10 = 0x1257;
  }
  else {
    memset(__s,0,0x34);
    if (sensor_test_debug_switch == '\0') {
      uVar10 = *(undefined4 *)(param_1 + 0xc);
    }
    else {
      printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_collect_result_unit ENTER\n",
             "_sensor_test_collect_result_unit",0x117e);
      uVar10 = *(undefined4 *)(param_1 + 0xc);
    }
    local_44[0] = '\0';
    local_44[1] = '\0';
    local_44[2] = '\0';
    local_44[3] = '\0';
    local_44[4] = '\0';
    local_44[5] = '\0';
    local_44[6] = '\0';
    local_44[7] = '\0';
    local_44[8] = '\0';
    local_44[9] = '\0';
    local_44[10] = '\0';
    local_44[0xb] = '\0';
    local_38 = 0;
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_34[0] = '\0';
    local_34[1] = '\0';
    local_34[2] = '\0';
    local_34[3] = '\0';
    local_34[4] = '\0';
    local_34[5] = '\0';
    local_34[6] = '\0';
    local_34[7] = '\0';
    local_34[8] = '\0';
    local_34[9] = '\0';
    local_34[10] = '\0';
    local_34[0xb] = '\0';
    local_28 = 0;
    iVar2 = json_object_object_get(uVar10,"serName");
    if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x1192);
      }
      pcVar9 = "";
    }
    else {
      pcVar9 = (char *)json_object_get_string(iVar2);
    }
    strncpy(local_34,pcVar9,0xf);
    local_28 = local_28 & 0xffffff00;
    uVar7 = sensor_test_db_get_test_type_enum_from_str(local_34);
    *(undefined1 *)((int)__s + 0x32) = uVar7;
    iVar2 = json_object_object_get(uVar10,"serIndex");
    if (iVar2 == 0) {
LAB_004f6f68:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x1196);
      }
      uVar6 = 0xffff;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar6 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f6f68;
        uVar11 = json_object_get_double(iVar2);
        uVar6 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    *(undefined2 *)((int)__s + 0x30) = uVar6;
    iVar2 = json_object_object_get(uVar10,"startTime");
    if (iVar2 == 0) {
LAB_004f6fc0:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x1199);
      }
      uVar5 = 0xffffffff;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar5 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f6fc0;
        uVar11 = json_object_get_double(iVar2);
        uVar5 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    *(undefined4 *)((int)__s + 0x2c) = uVar5;
    iVar2 = json_object_object_get(uVar10,"failStage");
    local_44[0] = '\0';
    local_44[1] = '\0';
    local_44[2] = '\0';
    local_44[3] = '\0';
    local_44[4] = '\0';
    local_44[5] = '\0';
    local_44[6] = '\0';
    local_44[7] = '\0';
    local_44[8] = '\0';
    local_44[9] = '\0';
    local_44[10] = '\0';
    local_44[0xb] = '\0';
    local_38 = 0;
    if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x119e);
      }
      pcVar9 = "";
    }
    else {
      pcVar9 = (char *)json_object_get_string(iVar2);
    }
    strncpy(local_44,pcVar9,0xf);
    local_38 = local_38 & 0xffffff00;
    uVar7 = sensor_test_db_get_stage_type_enum_from_str(local_44);
    *(undefined1 *)((int)__s + 0x24) = uVar7;
    iVar2 = json_object_object_get(uVar10,"failReason");
    if (iVar2 == 0) {
LAB_004f7088:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x11a2);
      }
      uVar5 = 0xffffffff;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar5 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f7088;
        uVar11 = json_object_get_double(iVar2);
        uVar5 = __fixdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    *(undefined4 *)((int)__s + 0x10) = uVar5;
    iVar2 = json_object_object_get(uVar10,"totalTime");
    if (iVar2 == 0) {
LAB_004f70e0:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x11a5);
      }
      uVar5 = 0xffffffff;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar5 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f70e0;
        uVar11 = json_object_get_double(iVar2);
        uVar5 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    *(undefined4 *)((int)__s + 0xc) = uVar5;
    iVar2 = json_object_object_get(uVar10,"rssi");
    if (iVar2 == 0) {
LAB_004f7138:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x11a8);
      }
      uVar7 = 0xff;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar7 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f7138;
        uVar11 = json_object_get_double(iVar2);
        uVar7 = __fixdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    *(undefined1 *)((int)__s + 0x25) = uVar7;
    iVar2 = json_object_object_get(uVar10,&DAT_00698ce4);
    if (iVar2 == 0) {
LAB_004f7190:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x11ab);
      }
      uVar6 = 0xffff;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar6 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f7190;
        uVar11 = json_object_get_double(iVar2);
        uVar6 = __fixdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    *(undefined2 *)((int)__s + 0x1c) = uVar6;
    iVar2 = json_object_object_get(uVar10,"txRate");
    if (iVar2 == 0) {
LAB_004f71e8:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x11ae);
      }
      uVar6 = 0xffff;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar6 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f71e8;
        uVar11 = json_object_get_double(iVar2);
        uVar6 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    *(undefined2 *)((int)__s + 0x14) = uVar6;
    iVar2 = json_object_object_get(uVar10,"rxRate");
    if (iVar2 == 0) {
LAB_004f7240:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x11b1);
      }
      uVar6 = 0xffff;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar6 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f7240;
        uVar11 = json_object_get_double(iVar2);
        uVar6 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    *(undefined2 *)((int)__s + 0x16) = uVar6;
    iVar2 = json_object_object_get(uVar10,"txCount");
    if (iVar2 == 0) {
LAB_004f7298:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x11b4);
      }
      uVar6 = 0xffff;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar6 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f7298;
        uVar11 = json_object_get_double(iVar2);
        uVar6 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    *(undefined2 *)((int)__s + 0x18) = uVar6;
    iVar2 = json_object_object_get(uVar10,"retryCount");
    if (iVar2 == 0) {
LAB_004f72f0:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x11b7);
      }
      uVar6 = 0xffff;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar6 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f72f0;
        uVar11 = json_object_get_double(iVar2);
        uVar6 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    *(undefined2 *)((int)__s + 0x1a) = uVar6;
    iVar2 = json_object_object_get(uVar10,"channel");
    if (iVar2 == 0) {
LAB_004f7348:
      iVar2 = -1;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_sensor_test_collect_result_unit",0x11cd);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        iVar2 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004f7348;
        uVar11 = json_object_get_double(iVar2);
        iVar2 = __fixdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
    }
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d collect chnl is =%d\n","_sensor_test_collect_result_unit",
             0x11ce,iVar2);
    }
    cVar8 = '\x01';
    if (((((0xd < iVar2 - 1U) && (cVar8 = '\x02', iVar2 != 0x95)) && (iVar2 != 0x99)) &&
        ((((iVar2 != 0x9d && (iVar2 != 0xa1)) &&
          ((iVar2 != 0xa5 && ((iVar2 != 0x24 && (iVar2 != 0x28)))))) && (iVar2 != 0x2c)))) &&
       ((((iVar2 != 0x30 && (iVar2 != 0x34)) && (iVar2 != 0x38)) &&
        ((iVar2 != 0x3c && (iVar2 != 0x40)))))) {
      if (iVar2 == 100) {
        cVar8 = '\x02';
      }
      else if (iVar2 != 0x68) {
        cVar8 = '\0';
      }
    }
    *(char *)((int)__s + 0x26) = cVar8;
    if (cVar8 == '\0') {
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      memcpy(&local_50,pcVar1 + 0x34,6);
      iVar2 = stats_db_bssid_get(&local_50);
      if (iVar2 == 0) {
        uVar10 = rdmngr_db_generate_rd_id(local_4c & 0xffff,local_48._0_1_);
        iVar2 = rdmngr_db_get_rd_freq_band(uVar10);
        if (iVar2 == 0) {
          *(undefined1 *)((int)__s + 0x26) = 1;
        }
        else if (iVar2 == 1) {
          *(undefined1 *)((int)__s + 0x26) = 2;
        }
        else {
          *(undefined1 *)((int)__s + 0x26) = 0;
        }
        goto LAB_004f7400;
      }
      cVar8 = *(char *)((int)__s + 0x32);
    }
    else {
LAB_004f7400:
      cVar8 = *(char *)((int)__s + 0x32);
    }
    if (cVar8 == '\a') {
      if (*(int *)((int)__s + 0x10) == 0) {
        if (sensor_test_debug_switch != '\0') {
          printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_parse_speed_result_detail ENTER\n",
                 "_sensor_test_parse_speed_result_detail",0x10a4);
        }
        iVar2 = json_object_object_get(*(undefined4 *)(param_1 + 0xc),"details");
        if (iVar2 == 0) {
          if (sensor_test_err_switch == '\0') {
            *(undefined4 *)((int)__s + 0x28) = 0;
          }
          else {
            pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d detail_obj invalid\n";
            uVar10 = 0x10b7;
LAB_004f7d24:
            printf(pcVar9,"_sensor_test_parse_speed_result_detail",uVar10);
LAB_004f7a74:
            *(undefined4 *)((int)__s + 0x28) = 0;
          }
        }
        else {
          iVar2 = json_object_object_get(iVar2,"test");
          if (iVar2 == 0) {
            if (sensor_test_err_switch != '\0') {
              pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d test_obj invalid\n";
              uVar10 = 0x10be;
              goto LAB_004f7d24;
            }
            *(undefined4 *)((int)__s + 0x28) = 0;
          }
          else {
            iVar3 = json_object_array_length(iVar2);
            if (iVar3 < 1) {
              if (sensor_test_err_switch != '\0') {
                pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d test_array_len=%d\n";
                uVar10 = 0x10c6;
LAB_004f7d80:
                printf(pcVar9,"_sensor_test_parse_speed_result_detail",uVar10,iVar3);
                goto LAB_004f7a74;
              }
              *(undefined4 *)((int)__s + 0x28) = 0;
            }
            else {
              iVar2 = json_object_array_get_idx(iVar2,0);
              if (iVar2 == 0) {
                if (sensor_test_err_switch != '\0') {
                  pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d stage_obj invalid\n";
                  uVar10 = 0x10ce;
                  goto LAB_004f7d24;
                }
                *(undefined4 *)((int)__s + 0x28) = 0;
              }
              else {
                uVar10 = json_object_object_get(iVar2,"data");
                iVar3 = json_object_array_length(uVar10);
                if (iVar3 < 1) {
                  if (sensor_test_err_switch != '\0') {
                    pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d data_array_len=%d\n";
                    uVar10 = 0x10d7;
                    goto LAB_004f7d80;
                  }
                  *(undefined4 *)((int)__s + 0x28) = 0;
                }
                else {
                  iVar2 = json_object_array_get_idx(uVar10,0);
                  if (iVar2 == 0) {
                    if (sensor_test_err_switch != '\0') {
                      pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d data_ele_obj invalid\n";
                      uVar10 = 0x10de;
                      goto LAB_004f7d24;
                    }
                    *(undefined4 *)((int)__s + 0x28) = 0;
                  }
                  else {
                    iVar3 = json_object_object_get(iVar2,"latency");
                    if (iVar3 != 0) {
                      iVar4 = json_object_get_type(iVar3);
                      if (iVar4 == 3) {
                        uVar6 = json_object_get_int(iVar3);
                      }
                      else {
                        iVar4 = json_object_get_type();
                        if (iVar4 != 2) {
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                   ,"_sensor_test_parse_speed_result_detail",0x10e5);
                          }
                          *(undefined2 *)((int)__s + 0x22) = 0xffff;
                          goto LAB_004f795c;
                        }
                        uVar11 = json_object_get_double(iVar3);
                        uVar6 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
                      }
                      *(undefined2 *)((int)__s + 0x22) = uVar6;
                    }
LAB_004f795c:
                    iVar3 = json_object_object_get(iVar2,"downloadSpeed");
                    if (iVar3 != 0) {
                      iVar4 = json_object_get_type(iVar3);
                      if (iVar4 == 3) {
                        uVar6 = json_object_get_int(iVar3);
                      }
                      else {
                        iVar4 = json_object_get_type();
                        if (iVar4 != 2) {
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                   ,"_sensor_test_parse_speed_result_detail",0x10eb);
                          }
                          *(undefined2 *)((int)__s + 0x20) = 0xffff;
                          goto LAB_004f79cc;
                        }
                        uVar11 = json_object_get_double(iVar3);
                        uVar6 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
                      }
                      *(undefined2 *)((int)__s + 0x20) = uVar6;
                    }
LAB_004f79cc:
                    iVar2 = json_object_object_get(iVar2,"uploadSpeed");
                    if (iVar2 != 0) {
                      iVar3 = json_object_get_type(iVar2);
                      if (iVar3 == 3) {
                        uVar6 = json_object_get_int(iVar2);
                      }
                      else {
                        iVar3 = json_object_get_type();
                        if (iVar3 != 2) {
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                   ,"_sensor_test_parse_speed_result_detail",0x10f1);
                          }
                          *(undefined2 *)((int)__s + 0x1e) = 0xffff;
                          goto LAB_004f7a3c;
                        }
                        uVar11 = json_object_get_double(iVar2);
                        uVar6 = __fixunsdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
                      }
                      *(undefined2 *)((int)__s + 0x1e) = uVar6;
                    }
LAB_004f7a3c:
                    if (sensor_test_debug_switch != '\0') {
                      printf("[SENSOR_TEST_DEBUG]%s()/%d parsed success, relay=%d, downSpeed=%d, upSpeed=%d\n"
                             ,"_sensor_test_parse_speed_result_detail",0x10f4,
                             (uint)*(ushort *)((int)__s + 0x22),(uint)*(ushort *)((int)__s + 0x20),
                             (uint)*(ushort *)((int)__s + 0x1e));
                      goto LAB_004f7a74;
                    }
                    *(undefined4 *)((int)__s + 0x28) = 0;
                  }
                }
              }
            }
          }
        }
      }
      else {
        *(undefined4 *)((int)__s + 0x28) = 0;
      }
    }
    else {
      *(undefined4 *)((int)__s + 0x28) = 0;
    }
    iVar2 = sensor_test_db_set_result(*(undefined4 *)(param_1 + 2),pcVar1,__s);
    if (iVar2 != -1) {
      sensor_test_db_result_unit_node_mem_free(__s);
      FUN_00407df0(pcVar1);
      return 0;
    }
    if (sensor_test_err_switch == '\0') goto LAB_004f7664;
    pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d db_set_result fail\n";
    uVar10 = 0x1266;
  }
  printf(pcVar9,"_sensor_test_collect_result",uVar10);
LAB_004f7664:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d _sensor_test_collect_result fail EXIT\n",
           "_sensor_test_collect_result",0x127a);
  }
  if (__s != (void *)0x0) {
    sensor_test_db_result_unit_node_mem_free(__s);
  }
  if (pcVar1 == (char *)0x0) {
    return 0xffffffff;
  }
  FUN_00407df0(pcVar1);
  return 0xffffffff;
}

