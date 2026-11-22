// func _sensor_backhaul_test_result_handle @ 004e33e4 size=1816

undefined4 _sensor_backhaul_test_result_handle(ushort *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  char local_58 [20];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  int local_30;
  
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_58[0] = '\0';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  local_58[4] = '\0';
  local_58[5] = '\0';
  local_58[6] = '\0';
  local_58[7] = '\0';
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_58[0xc] = '\0';
  local_58[0xd] = '\0';
  local_58[0xe] = '\0';
  local_58[0xf] = '\0';
  local_58[0x10] = '\0';
  local_58[0x11] = '\0';
  local_58[0x12] = '\0';
  local_58[0x13] = '\0';
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 0xc) == 0)) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d Input error\n","_sensor_backhaul_test_result_handle",0x3fe);
    return 0xffffffff;
  }
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if (((g_sensor_enable == 0) || (g_sensor_state != 3)) || (g_sensor_backhaul_test_state != 1)) {
    uVar9 = 0;
    if (sensor_warning_switch == '\0') goto LAB_004e3480;
    pcVar5 = "[SENSOR_WARNING]%s()/%d Sensor state %d or backhaul test state %d is not correct\n";
    uVar7 = 0x404;
    iVar8 = g_sensor_state;
    iVar1 = g_sensor_backhaul_test_state;
LAB_004e35e0:
    uVar9 = 0;
    printf(pcVar5,"_sensor_backhaul_test_result_handle",uVar7,iVar8,iVar1);
  }
  else {
    if (((unfinished_sensor_list == 0) || (unfinished_sensor_num < 1)) ||
       ((unfinished_sensor_id_map == 0 ||
        (iVar1 = (int)*(short *)(unfinished_sensor_id_map + (*param_1 - 50000) * 2), iVar1 == -1))))
    {
      uVar9 = 0xffffffff;
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d No unfinished sensor found\n",
               "_sensor_backhaul_test_result_handle",0x40a);
      }
      goto LAB_004e3480;
    }
    iVar8 = *(int *)(current_backhaul_test_operation_id + iVar1 * 4);
    iVar6 = iVar8 + -1;
    if (iVar8 < 1) {
      if (iVar8 == 0) {
        iVar6 = *(int *)(param_1 + 2);
        iVar4 = 0xfffffff;
        goto LAB_004e354c;
      }
    }
    else {
      iVar4 = *(int *)(param_1 + 2);
LAB_004e354c:
      if (iVar6 != iVar4) {
        uVar9 = 0;
        if (sensor_warning_switch == '\0') goto LAB_004e3480;
        iVar1 = *(int *)(param_1 + 2);
        pcVar5 = "[SENSOR_WARNING]%s()/%d Current bh and data operation ID %d and %d not matched\n";
        uVar7 = 0x413;
        iVar8 = iVar8 + -1;
        goto LAB_004e35e0;
      }
    }
    iVar8 = unfinished_sensor_list + iVar1 * 0x30;
    uVar9 = 0;
    if (*(int *)(iVar8 + 4) == 1) {
      iVar1 = json_object_object_get(*(undefined4 *)(param_1 + 0xc),"testData");
      if (((iVar1 == 0) || (iVar6 = json_object_get_type(iVar1), iVar6 != 5)) ||
         (iVar6 = json_object_array_length(iVar1), iVar6 < 1)) {
        if (sensor_err_switch != '\0') {
          printf("[SENSOR_ERROR]%s()/%d Invalid json string for backhaul test data\n",
                 "_sensor_backhaul_test_result_handle",0x41e);
        }
      }
      else {
        iVar6 = json_object_array_length(iVar1);
        if (iVar6 == *(int *)(iVar8 + 8)) {
          local_30 = 0;
          for (iVar6 = 0; iVar4 = json_object_array_length(iVar1), iVar6 < iVar4; iVar6 = iVar6 + 1)
          {
            uVar9 = json_object_array_get_idx(iVar1,iVar6);
            iVar4 = json_object_object_get(uVar9,"testIdx");
            if ((iVar4 == 0) || (iVar2 = json_object_get_type(iVar4), iVar2 != 6)) {
              if (sensor_err_switch != '\0') {
                pcVar5 = "[SENSOR_ERROR]%s()/%d Test idx not exist or format error for item %d\n";
                uVar9 = 0x42e;
LAB_004e39dc:
                printf(pcVar5,"_sensor_backhaul_test_result_handle",uVar9,iVar6);
              }
              goto LAB_004e367c;
            }
            iVar2 = json_object_get_type(iVar4);
            if (iVar2 == 6) {
              pcVar5 = (char *)json_object_get_string(iVar4);
              iVar4 = atoi(pcVar5);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                       "_sensor_backhaul_test_result_handle",0x432);
              }
              iVar4 = -1;
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                       "_sensor_backhaul_test_result_handle",0x432);
                iVar4 = -1;
              }
            }
            if ((*(int *)(iVar8 + 8) <= iVar4) || (iVar4 < 0)) {
              if (sensor_err_switch == '\0') goto LAB_004e367c;
              pcVar5 = "[SENSOR_ERROR]%s()/%d Illegal test idx %d for item %d\n";
              uVar9 = 0x435;
              goto LAB_004e3710;
            }
            iVar2 = json_object_object_get(uVar9,"result");
            if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
              if (sensor_err_switch != '\0') {
                pcVar5 = 
                "[SENSOR_ERROR]%s()/%d Field reachable not exist or format error for item %d\n";
                uVar9 = 0x43c;
                goto LAB_004e39dc;
              }
              goto LAB_004e367c;
            }
            iVar3 = json_object_get_type(iVar2);
            if (iVar3 == 6) {
              pcVar5 = (char *)json_object_get_string(iVar2);
              iVar2 = atoi(pcVar5);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                       "_sensor_backhaul_test_result_handle",0x440);
              }
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                       "_sensor_backhaul_test_result_handle",0x440);
              }
              iVar2 = -1;
            }
            iVar3 = iVar8 + iVar4 * 0xc;
            *(int *)(iVar3 + 0x14) = iVar2;
            if ((iVar2 != 0) && (local_30 = 1, *(char *)(iVar3 + 0x12) != '\0')) {
              iVar2 = json_object_object_get(uVar9,"bssid");
              if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
                if (sensor_err_switch != '\0') {
                  printf("[SENSOR_ERROR]%s()/%d Bssid not exist or format error for item %d\n",
                         "_sensor_backhaul_test_result_handle",0x449,iVar6);
                }
              }
              else {
                iVar3 = json_object_get_type(iVar2);
                if (iVar3 == 6) {
                  pcVar5 = (char *)json_object_get_string(iVar2);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_sensor_backhaul_test_result_handle",0x44e);
                  }
                  pcVar5 = "";
                }
                strncpy((char *)&local_44,pcVar5,0x13);
                local_34 = local_34 & 0xffffff00;
                FUN_004e3340(iVar8 + iVar4 * 0xc + 0xc,local_58);
                iVar2 = strcasecmp((char *)&local_44,local_58);
                if (iVar2 == 0) {
                  local_30 = 1;
                  goto LAB_004e38a4;
                }
                if (sensor_err_switch != '\0') {
                  printf("[SENSOR_ERROR]%s()/%d Bssid %s not match test bssid %s for item %d\n",
                         "_sensor_backhaul_test_result_handle",0x452,&local_44,local_58,iVar6);
                }
              }
              *(undefined4 *)(iVar8 + iVar4 * 0xc + 0x14) = 0;
              goto LAB_004e367c;
            }
LAB_004e38a4:
          }
          iVar1 = backhaul_test_finished_sensor_num + 1;
          uVar9 = 5;
          if (local_30 != 0) {
            backhaul_test_suc_sensor_num = backhaul_test_suc_sensor_num + 1;
            uVar9 = 2;
          }
          backhaul_test_finished_sensor_num = iVar1;
          *(undefined4 *)(iVar8 + 4) = uVar9;
          uVar9 = 0;
          if (unfinished_sensor_num <= iVar1) {
            g_sensor_backhaul_test_state = 2;
          }
          goto LAB_004e3480;
        }
        if (sensor_err_switch != '\0') {
          iVar4 = json_object_array_length(iVar1);
          iVar6 = *(int *)(iVar8 + 8);
          pcVar5 = 
          "[SENSOR_ERROR]%s()/%d Test data\'s bssid num %d not match with test bssid num %d\n";
          uVar9 = 0x424;
LAB_004e3710:
          printf(pcVar5,"_sensor_backhaul_test_result_handle",uVar9,iVar4,iVar6);
        }
      }
LAB_004e367c:
      uVar9 = 0xffffffff;
      *(undefined4 *)(iVar8 + 4) = 5;
    }
  }
LAB_004e3480:
  FUN_00407f30(g_sensor_mngt_mutex);
  return uVar9;
}

