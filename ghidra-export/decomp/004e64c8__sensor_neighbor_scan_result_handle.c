// func _sensor_neighbor_scan_result_handle @ 004e64c8 size=2880

undefined4 _sensor_neighbor_scan_result_handle(short *param_1)

{
  int iVar1;
  void *__s;
  int iVar2;
  int iVar3;
  char *__s2;
  undefined2 uVar4;
  undefined1 uVar5;
  undefined4 extraout_v1;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  size_t __n;
  size_t __n_00;
  void *__src;
  void *__dest;
  undefined8 uVar9;
  char local_b8 [16];
  uint local_a8;
  undefined4 auStack_a0 [24];
  void *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d _sensor_neighbor_scan_result_handle ENTER\n",
           "_sensor_neighbor_scan_result_handle",0x517);
  }
  local_b8[0] = '\0';
  local_b8[1] = '\0';
  local_b8[2] = '\0';
  local_b8[3] = '\0';
  local_b8[4] = '\0';
  local_b8[5] = '\0';
  local_b8[6] = '\0';
  local_b8[7] = '\0';
  local_b8[8] = '\0';
  local_b8[9] = '\0';
  local_b8[10] = '\0';
  local_b8[0xb] = '\0';
  local_b8[0xc] = '\0';
  local_b8[0xd] = '\0';
  local_b8[0xe] = '\0';
  local_b8[0xf] = '\0';
  local_a8 = 0;
  memcpy(auStack_a0,&PTR_s_20MHz_006b1d10,0x60);
  if ((param_1 == (short *)0x0) || (*(int *)(param_1 + 0xc) == 0)) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d Input error\n","_sensor_neighbor_scan_result_handle",0x52b);
    return 0xffffffff;
  }
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if (g_sensor_enable == 0) {
    uVar8 = 0;
    if (sensor_warning_switch == '\0') goto LAB_004e6578;
    pcVar6 = "[SENSOR_WARNING]%s()/%d Sensor not enabled\n";
    uVar7 = 0x531;
  }
  else {
    if (*(int *)(param_1 + 2) != 0) {
      uVar8 = 0;
      if (sensor_warning_switch != '\0') {
        printf("[SENSOR_WARNING]%s()/%d Current neighbor scan and data operation ID %d and %d not matched\n"
               ,"_sensor_neighbor_scan_result_handle",0x537,0,*(int *)(param_1 + 2));
      }
      goto LAB_004e6578;
    }
    local_3c = json_object_object_get(*(undefined4 *)(param_1 + 0xc),"data");
    if ((local_3c == 0) ||
       ((iVar1 = json_object_get_type(local_3c), iVar1 != 5 &&
        ((iVar1 = json_object_get_type(local_3c), iVar1 != 4 ||
         (iVar1 = json_object_object_length(local_3c), iVar1 != 0)))))) {
      uVar8 = 0xffffffff;
      if (sensor_err_switch == '\0') goto LAB_004e6578;
      pcVar6 = "[SENSOR_ERROR]%s()/%d Invalid json string for neighbor scan data\n";
      uVar7 = 0x53f;
    }
    else {
      local_38 = json_object_array_length(local_3c);
      if (local_38 < 1) {
        __s = (void *)0x0;
        local_40 = (void *)0x0;
LAB_004e6b70:
        uVar8 = 0;
        _sensor_update_scan_bssid_info((int)*param_1,local_38,local_40,__s);
        if (local_40 != (void *)0x0) {
LAB_004e683c:
          FUN_00407df0(local_40);
        }
        if (__s != (void *)0x0) {
          FUN_00407df0(__s);
        }
        goto LAB_004e6578;
      }
      __n_00 = local_38 * 0x14;
      local_40 = (void *)FUN_00408450(__n_00,0x545);
      if (local_40 != (void *)0x0) {
        __n = local_38 * 0x48;
        __s = (void *)FUN_00408450(__n,0x54b);
        if (__s != (void *)0x0) {
          memset(local_40,0,__n_00);
          memset(__s,0,__n);
          iVar1 = 0;
          FUN_00407e70();
          __src = local_40;
          __dest = __s;
          local_2c = extraout_v1;
          do {
            uVar8 = json_object_array_get_idx(local_3c,iVar1);
            iVar2 = json_object_object_get(uVar8,"bssid");
            if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
              if (sensor_err_switch != '\0') {
                pcVar6 = "[SENSOR_ERROR]%s()/%d Bssid not exist or format error for item %d\n";
                uVar8 = 0x55a;
                goto LAB_004e6ea8;
              }
              uVar8 = 0xffffffff;
              goto LAB_004e683c;
            }
            iVar3 = json_object_get_type(iVar2);
            if (iVar3 == 6) {
              pcVar6 = (char *)json_object_get_string(iVar2);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_sensor_neighbor_scan_result_handle",0x55d);
              }
              pcVar6 = "";
            }
            strncpy(local_b8,pcVar6,0x13);
            local_a8 = local_a8 & 0xffffff00;
            if (__src == (void *)0x0) {
              if (sensor_err_switch != '\0') {
                printf("[SENSOR_ERROR]%s()/%d Input error\n","_sensor_bssid_transfer",0xf7);
              }
LAB_004e682c:
              if (sensor_err_switch == '\0') {
                uVar8 = 0xffffffff;
              }
              else {
                printf("[SENSOR_ERROR]%s()/%d Illegal bssid %s for item %d\n",
                       "_sensor_neighbor_scan_result_handle",0x560,local_b8,iVar1);
                uVar8 = 0xffffffff;
              }
              goto LAB_004e683c;
            }
            iVar2 = sscanf(local_b8,"%hhX-%hhX-%hhX-%hhX-%hhX-%hhX",__src,(int)__src + 1,
                           (int)__src + 2,(int)__src + 3,(int)__src + 4,(int)__src + 5);
            if (iVar2 != 6) goto LAB_004e682c;
            iVar2 = json_object_object_get(uVar8,"channel");
            if ((iVar2 == 0) ||
               ((iVar3 = json_object_get_type(iVar2), iVar3 != 3 &&
                (iVar3 = json_object_get_type(iVar2), iVar3 != 2)))) {
              if (sensor_err_switch == '\0') {
                uVar8 = 0xffffffff;
              }
              else {
                pcVar6 = "[SENSOR_ERROR]%s()/%d Channel not exist or format error for item %d\n";
                uVar8 = 0x567;
LAB_004e6ea8:
                printf(pcVar6,"_sensor_neighbor_scan_result_handle",uVar8,iVar1);
                uVar8 = 0xffffffff;
              }
              goto LAB_004e683c;
            }
            iVar3 = json_object_get_type(iVar2);
            if (iVar3 == 3) {
              uVar4 = json_object_get_int(iVar2);
            }
            else {
              iVar3 = json_object_get_type();
              if (iVar3 == 2) {
                uVar9 = json_object_get_double(iVar2);
                uVar4 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_neighbor_scan_result_handle",0x56a);
                }
                uVar4 = 0xffff;
              }
            }
            *(undefined2 *)((int)__src + 8) = uVar4;
            iVar2 = json_object_object_get(uVar8,"rssi");
            if ((iVar2 == 0) ||
               ((iVar3 = json_object_get_type(iVar2), iVar3 != 3 &&
                (iVar3 = json_object_get_type(iVar2), iVar3 != 2)))) {
              if (sensor_err_switch != '\0') {
                pcVar6 = "[SENSOR_ERROR]%s()/%d Rssi not exist or format error for item %d\n";
                uVar8 = 0x56f;
                goto LAB_004e6ea8;
              }
              uVar8 = 0xffffffff;
              goto LAB_004e683c;
            }
            iVar3 = json_object_get_type(iVar2);
            if (iVar3 == 3) {
              uVar5 = json_object_get_int(iVar2);
            }
            else {
              iVar3 = json_object_get_type();
              if (iVar3 == 2) {
                uVar9 = json_object_get_double(iVar2);
                uVar5 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_neighbor_scan_result_handle",0x572);
                }
                uVar5 = 0xff;
              }
            }
            *(undefined1 *)((int)__src + 6) = uVar5;
            local_30 = json_object_object_get(uVar8,&DAT_00698cb4);
            if ((local_30 == 0) || (iVar2 = json_object_get_type(local_30), iVar2 != 6)) {
              if (sensor_err_switch != '\0') {
                pcVar6 = "[SENSOR_ERROR]%s()/%d Rssi not exist or format error for item %d\n";
                uVar8 = 0x577;
                goto LAB_004e6ea8;
              }
              uVar8 = 0xffffffff;
              goto LAB_004e683c;
            }
            iVar2 = json_object_get_type(local_30);
            if (iVar2 == 6) {
              local_34 = 0;
              do {
                iVar2 = local_34;
                pcVar6 = (char *)auStack_a0[local_34 * 4];
                if (pcVar6 != (char *)0x0) {
                  __s2 = (char *)json_object_get_string(local_30);
                  iVar3 = strcmp(pcVar6,__s2);
                  if (iVar3 == 0) {
                    uVar5 = (undefined1)auStack_a0[iVar2 * 4 + 3];
                    goto LAB_004e6a18;
                  }
                }
                local_34 = local_34 + 1;
              } while (local_34 != 6);
              if (jcs_err_switch != 0) {
                pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_004e6c1c:
                printf(pcVar6,"_sensor_neighbor_scan_result_handle",0x57a);
              }
            }
            else if (jcs_err_switch != 0) {
              pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
              goto LAB_004e6c1c;
            }
            if (jcs_err_switch == 0) {
              uVar5 = 0xff;
            }
            else {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_sensor_neighbor_scan_result_handle",0x57a);
              uVar5 = 0xff;
            }
LAB_004e6a18:
            *(undefined1 *)((int)__src + 10) = uVar5;
            iVar2 = json_object_object_get(uVar8,"iBssidWl");
            if ((iVar2 == 0) ||
               ((iVar3 = json_object_get_type(iVar2), iVar3 != 3 &&
                (iVar3 = json_object_get_type(iVar2), iVar3 != 2)))) {
              if (sensor_err_switch != '\0') {
                pcVar6 = "[SENSOR_ERROR]%s()/%d iBssidWl not exist or format error for item %d\n";
                uVar8 = 0x57f;
                goto LAB_004e6ea8;
              }
              uVar8 = 0xffffffff;
              goto LAB_004e683c;
            }
            iVar3 = json_object_get_type(iVar2);
            if (iVar3 == 3) {
              uVar5 = json_object_get_int(iVar2);
            }
            else {
              iVar3 = json_object_get_type();
              if (iVar3 == 2) {
                uVar9 = json_object_get_double(iVar2);
                uVar5 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_neighbor_scan_result_handle",0x582);
                }
                uVar5 = 0xff;
              }
            }
            *(undefined1 *)((int)__src + 0xb) = uVar5;
            iVar2 = json_object_object_get(uVar8,"iSsidWl");
            if ((iVar2 == 0) ||
               ((iVar3 = json_object_get_type(iVar2), iVar3 != 3 &&
                (iVar3 = json_object_get_type(iVar2), iVar3 != 2)))) {
              if (sensor_err_switch != '\0') {
                pcVar6 = "[SENSOR_ERROR]%s()/%d iBssidWl not exist or format error for item %d\n";
                uVar8 = 0x587;
                goto LAB_004e6ea8;
              }
              uVar8 = 0xffffffff;
              goto LAB_004e683c;
            }
            iVar3 = json_object_get_type(iVar2);
            if (iVar3 == 3) {
              uVar5 = json_object_get_int(iVar2);
              *(undefined1 *)((int)__src + 0xc) = uVar5;
            }
            else {
              iVar3 = json_object_get_type();
              if (iVar3 == 2) {
                uVar9 = json_object_get_double(iVar2);
                uVar5 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
                *(undefined1 *)((int)__src + 0xc) = uVar5;
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_sensor_neighbor_scan_result_handle",0x58a);
                }
                *(undefined1 *)((int)__src + 0xc) = 0xff;
              }
            }
            *(undefined4 *)((int)__src + 0x10) = local_2c;
            memcpy(__dest,__src,0x14);
            iVar2 = json_object_object_get(uVar8,"ssid");
            if ((iVar2 != 0) && (iVar3 = json_object_get_type(iVar2), iVar3 == 6)) {
              iVar3 = json_object_get_type(iVar2);
              if (iVar3 == 6) {
                pcVar6 = (char *)json_object_get_string(iVar2);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_sensor_neighbor_scan_result_handle",0x591);
                }
                pcVar6 = "";
              }
              strncpy((char *)((int)__dest + 0x14),pcVar6,0x31);
              *(undefined1 *)((int)__dest + 0x45) = 0;
              iVar2 = json_object_object_get(uVar8,"ssidCodeType");
              if ((iVar2 == 0) ||
                 ((iVar3 = json_object_get_type(iVar2), iVar3 != 3 &&
                  (iVar3 = json_object_get_type(iVar2), iVar3 != 2)))) {
                if (sensor_err_switch != '\0') {
                  pcVar6 = 
                  "[SENSOR_ERROR]%s()/%d ssidCodeType not exist or format error for item %d\n";
                  uVar8 = 0x595;
                  goto LAB_004e6ea8;
                }
                uVar8 = 0xffffffff;
                goto LAB_004e683c;
              }
              iVar3 = json_object_get_type(iVar2);
              if (iVar3 == 3) {
                uVar5 = json_object_get_int(iVar2);
                *(undefined1 *)((int)__dest + 0x46) = uVar5;
              }
              else {
                iVar3 = json_object_get_type();
                if (iVar3 == 2) {
                  uVar9 = json_object_get_double(iVar2);
                  uVar5 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
                  *(undefined1 *)((int)__dest + 0x46) = uVar5;
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                           ,"_sensor_neighbor_scan_result_handle",0x598);
                  }
                  *(undefined1 *)((int)__dest + 0x46) = 0xff;
                }
              }
            }
            iVar1 = iVar1 + 1;
            __src = (void *)((int)__src + 0x14);
            __dest = (void *)((int)__dest + 0x48);
          } while (iVar1 != local_38);
          goto LAB_004e6b70;
        }
        if (sensor_err_switch == '\0') {
          uVar8 = 0xffffffff;
        }
        else {
          printf("[SENSOR_ERROR]%s()/%d Malloc failed\n","_sensor_neighbor_scan_result_handle",0x54e
                );
          uVar8 = 0xffffffff;
        }
        goto LAB_004e683c;
      }
      uVar8 = 0xffffffff;
      if (sensor_err_switch == '\0') goto LAB_004e6578;
      pcVar6 = "[SENSOR_ERROR]%s()/%d Malloc failed\n";
      uVar7 = 0x548;
    }
  }
  printf(pcVar6,"_sensor_neighbor_scan_result_handle",uVar7);
LAB_004e6578:
  FUN_00407f30(g_sensor_mngt_mutex);
  return uVar8;
}

