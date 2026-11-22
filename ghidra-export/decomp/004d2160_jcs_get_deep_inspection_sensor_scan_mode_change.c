// func jcs_get_deep_inspection_sensor_scan_mode_change @ 004d2160 size=864

void jcs_get_deep_inspection_sensor_scan_mode_change(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  undefined8 uVar4;
  byte local_128;
  byte local_127 [3];
  char acStack_124 [264];
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_get_deep_inspection_sensor_scan_mode_change ENTER\n"
           ,"jcs_get_deep_inspection_sensor_scan_mode_change",0x106c);
  }
  local_127[0] = 0;
  local_128 = 0;
  iVar1 = json_object_object_get(param_1,"entry_id");
  if (iVar1 == 0) {
    if (sensor_di_err_switch == 0) {
      uVar3 = 1;
      goto LAB_004d2230;
    }
    __format = "[SENSOR_DI_ERROR]%s()/line %d : get sensor_id json obj failed\n";
    uVar3 = 0x1077;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar4 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      }
      else {
        iVar1 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "jcs_get_deep_inspection_sensor_scan_mode_change",0x107a);
        }
      }
    }
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : get entry_id=%d\n",
             "jcs_get_deep_inspection_sensor_scan_mode_change",0x107b,iVar1);
    }
    if (iVar1 < 0) {
      if (sensor_di_err_switch == 0) {
        uVar3 = 1;
        goto LAB_004d2230;
      }
      __format = "[SENSOR_DI_ERROR]%s()/line %d : entry_id < 0\n";
      uVar3 = 0x107e;
    }
    else {
      iVar1 = sensor_di_db_get_scan_mode(iVar1,local_127,&local_128);
      if (iVar1 == -1) {
        if (sensor_di_err_switch == 0) {
          uVar3 = 1;
          goto LAB_004d2230;
        }
        __format = "[SENSOR_DI_ERROR]%s()/line %d : get_scan_mode fail\n";
        uVar3 = 0x1084;
      }
      else {
        iVar1 = json_object_new_array();
        if (iVar1 != 0) {
          iVar2 = json_object_new_object();
          if (iVar2 == 0) {
            if (sensor_di_err_switch != 0) {
              printf("[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE fail\n",
                     "jcs_get_deep_inspection_sensor_scan_mode_change",0x1093);
            }
            json_object_put(iVar1);
            uVar3 = 1;
          }
          else {
            memset(acStack_124,0,0x100);
            snprintf(acStack_124,0x100,"%d",(uint)local_127[0]);
            uVar3 = json_object_new_string(acStack_124);
            json_object_object_add(iVar2,"scan_mode",uVar3);
            memset(acStack_124,0,0x100);
            snprintf(acStack_124,0x100,"%d",(uint)local_128);
            uVar3 = json_object_new_string(acStack_124);
            json_object_object_add(iVar2,"chnl",uVar3);
            json_object_array_add(iVar1,iVar2);
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_get_deep_inspection_sensor_scan_mode_change success EXIT\n"
                     ,"jcs_get_deep_inspection_sensor_scan_mode_change",0x109b);
            }
            json_object_object_add(param_2,"deep_inspection_scan_mode_change",iVar1);
            uVar3 = 0;
          }
          goto LAB_004d2230;
        }
        if (sensor_di_err_switch == 0) {
          uVar3 = 1;
          goto LAB_004d2230;
        }
        __format = "[SENSOR_DI_ERROR]%s()/line %d : JSON_ARRAY_CREATE fail\n";
        uVar3 = 0x108b;
      }
    }
  }
  printf(__format,"jcs_get_deep_inspection_sensor_scan_mode_change",uVar3);
  uVar3 = 1;
LAB_004d2230:
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  return;
}

