// func jcs_deep_inspection_sensor_scan_mode_change @ 004db3bc size=1024

void jcs_deep_inspection_sensor_scan_mode_change(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  byte local_30;
  byte local_2f [11];
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_sensor_scan_mode_change ENTER\n",
           "jcs_deep_inspection_sensor_scan_mode_change",0xc6a);
  }
  local_2f[0] = 0;
  local_30 = 0;
  iVar1 = _sensor_di_get_cur_status();
  if (iVar1 == 0) {
    if (sensor_di_debug_switch == 0) {
      uVar5 = 0;
      goto LAB_004db41c;
    }
    pcVar6 = "[SENSOR_DI_DEBUG]%s()/line %d : cur_status is off\n";
    uVar5 = 0xc78;
LAB_004db470:
    printf(pcVar6,"jcs_deep_inspection_sensor_scan_mode_change",uVar5);
    uVar5 = 0;
    goto LAB_004db41c;
  }
  iVar1 = _jcs_parse_sensor_id(param_1);
  if (iVar1 < 0) {
    if (sensor_di_err_switch != 0) {
      pcVar6 = "[SENSOR_DI_ERROR]%s()/line %d : invalid entry_id\n";
      uVar5 = 0xc80;
LAB_004db64c:
      printf(pcVar6,"jcs_deep_inspection_sensor_scan_mode_change",uVar5);
    }
  }
  else {
    iVar2 = json_object_object_get(param_1,"scan_mode");
    if (iVar2 == 0) {
LAB_004db4d0:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "jcs_deep_inspection_sensor_scan_mode_change",0xc85);
      }
      uVar4 = 0xffffffff;
      uVar8 = 0;
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar4 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004db4d0;
        uVar10 = json_object_get_double(iVar2);
        uVar4 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
      uVar8 = 0;
      if (uVar4 == 1) {
        iVar2 = json_object_object_get(param_1,"chnl");
        if (iVar2 == 0) {
LAB_004db744:
          uVar8 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_deep_inspection_sensor_scan_mode_change",0xc8b);
          }
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 3) {
            uVar8 = json_object_get_int(iVar2);
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 != 2) goto LAB_004db744;
            uVar10 = json_object_get_double(iVar2);
            uVar8 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
          }
        }
      }
    }
    iVar2 = sensor_di_db_get_scan_mode(iVar1,local_2f,&local_30);
    if (iVar2 == -1) {
      if (sensor_di_err_switch != 0) {
        pcVar6 = "[SENSOR_DI_ERROR]%s()/line %d : get_scan_mode fail\n";
        uVar5 = 0xc90;
        goto LAB_004db64c;
      }
    }
    else {
      uVar7 = 0;
      uVar9 = (uint)(local_2f[0] != uVar4);
      if ((local_2f[0] == 1) && (uVar4 == 1)) {
        uVar7 = (uint)(local_30 != uVar8);
      }
      if (sensor_di_debug_switch != 0) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : is_scan_mode_change=%d, is_chnl_change=%d\n",
               "jcs_deep_inspection_sensor_scan_mode_change",0xc96,uVar9,uVar7);
      }
      if (uVar7 != 0 || uVar9 != 0) {
        sensor_di_db_pkt_stat_clear(iVar1);
        sensor_di_db_set_pkt_stat_chnl(iVar1,uVar8);
      }
      iVar2 = sensor_di_db_set_scan_mode(iVar1,uVar4 & 0xff,uVar8 & 0xff);
      if (iVar2 == -1) {
        if (sensor_di_err_switch != 0) {
          pcVar6 = "[SENSOR_DI_ERROR]%s()/line %d : set scan mode fail\n";
          uVar5 = 0xc9f;
          goto LAB_004db64c;
        }
      }
      else {
        iVar1 = sensor_di_cw_send_change_sensor_scan_mode(iVar1,uVar8);
        if (iVar1 != -1) {
          if (sensor_di_debug_switch == 0) {
            uVar5 = 0;
            goto LAB_004db41c;
          }
          pcVar6 = "[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_status success EXIT\n";
          uVar5 = 0xca9;
          goto LAB_004db470;
        }
        if (sensor_di_err_switch != 0) {
          pcVar6 = "[SENSOR_DI_ERROR]%s()/line %d : send_change_sensor_scan_mode fail\n";
          uVar5 = 0xca5;
          goto LAB_004db64c;
        }
      }
    }
  }
  if (sensor_di_warning_switch == 0) {
    uVar5 = 1;
  }
  else {
    printf("[SENSOR_DI_WARNING]%s()/line %d : jcs_deep_inspection_status fail EXIT\n",
           "jcs_deep_inspection_sensor_scan_mode_change",0xcae);
    uVar5 = 1;
  }
LAB_004db41c:
  uVar5 = json_object_new_int(uVar5);
  json_object_object_add(param_2,&DAT_00676a24,uVar5);
  return;
}

