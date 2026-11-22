// func jcs_deep_inspection_selected_chnl_usage @ 004d3094 size=1080

void jcs_deep_inspection_selected_chnl_usage(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  undefined4 uVar6;
  short sVar7;
  char *__format;
  uint uVar8;
  short *psVar9;
  undefined8 uVar10;
  char acStack_128 [256];
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_selected_chnl_usage ENTER\n",
           "jcs_deep_inspection_selected_chnl_usage",0xe56);
  }
  iVar2 = _jcs_parse_sensor_id(param_1);
  if (iVar2 == -1) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid entry_id\n",
             "jcs_deep_inspection_selected_chnl_usage",0xe64);
    }
    psVar5 = (short *)0x0;
  }
  else {
    iVar3 = json_object_object_get(param_1,"chnl");
    if (iVar3 == 0) {
LAB_004d312c:
      iVar3 = -1;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "jcs_deep_inspection_selected_chnl_usage",0xe69);
      }
    }
    else {
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 3) {
        sVar7 = json_object_get_int(iVar3);
        iVar3 = (int)sVar7;
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 != 2) goto LAB_004d312c;
        uVar10 = json_object_get_double(iVar3);
        sVar7 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        iVar3 = (int)sVar7;
      }
    }
    psVar5 = (short *)sensor_di_db_get_chnl_util_time(iVar2,iVar3);
    if (psVar5 != (short *)0x0) {
      uVar8 = (uint)*(byte *)(psVar5 + 0xf0);
      if (0x78 < uVar8) {
        uVar8 = 0x78;
      }
      if (uVar8 == 0) {
        iVar2 = 0;
        if (sensor_di_warning_switch == 0) goto LAB_004d3320;
        __format = "[SENSOR_DI_WARNING]%s()/line %d : chnl_util_time->point_num <= 0\n";
        uVar6 = 0xe77;
      }
      else {
        iVar2 = json_object_new_array();
        if (iVar2 == 0) {
          if (sensor_di_err_switch == 0) goto LAB_004d3324;
          __format = "[SENSOR_DI_ERROR]%s()/line %d : JSON_ARRAY_CREATE fail\n";
          uVar6 = 0xe7e;
        }
        else {
          iVar3 = 0;
          psVar9 = psVar5;
          while (iVar4 = json_object_new_object(), iVar4 != 0) {
            iVar3 = iVar3 + 1;
            memset(acStack_128,0,0x100);
            snprintf(acStack_128,0x100,"%d",(int)*psVar9);
            uVar6 = json_object_new_string(acStack_128);
            json_object_object_add(iVar4,"time",uVar6);
            memset(acStack_128,0,0x100);
            snprintf(acStack_128,0x100,"%d",(uint)*(byte *)(psVar9 + 1));
            uVar6 = json_object_new_string(acStack_128);
            json_object_object_add(iVar4,"wifi_util",uVar6);
            memset(acStack_128,0,0x100);
            pbVar1 = (byte *)((int)psVar9 + 3);
            psVar9 = psVar9 + 2;
            snprintf(acStack_128,0x100,"%d",(uint)*pbVar1);
            uVar6 = json_object_new_string(acStack_128);
            json_object_object_add(iVar4,"non_wifi_util",uVar6);
            json_object_array_add(iVar2,iVar4);
            if ((int)uVar8 <= iVar3) {
              FUN_00407df0(psVar5);
              json_object_object_add(param_2,"deep_inspection_selected_chnl_usage",iVar2);
              uVar6 = json_object_new_int(0);
              json_object_object_add(param_2,&DAT_00676a24,uVar6);
              if (sensor_di_debug_switch == 0) {
                return;
              }
              printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_selected_chnl_usage success EXIT\n"
                     ,"jcs_deep_inspection_selected_chnl_usage",0xe99);
              return;
            }
          }
          if (sensor_di_err_switch == 0) goto LAB_004d3324;
          __format = "[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE fail\n";
          uVar6 = 0xe87;
        }
      }
      printf(__format,"jcs_deep_inspection_selected_chnl_usage",uVar6);
      goto LAB_004d3324;
    }
    if (sensor_di_warning_switch != 0) {
      printf("[SENSOR_DI_WARNING]%s()/line %d : get_chnl_util_time fail\n",
             "jcs_deep_inspection_selected_chnl_usage",0xe6f);
      iVar2 = 0;
      goto LAB_004d3324;
    }
  }
LAB_004d3320:
  iVar2 = 0;
LAB_004d3324:
  if (sensor_di_warning_switch != 0) {
    printf("[SENSOR_DI_WARNING]%s()/line %d : jcs_deep_inspection_selected_chnl_usage fail EXIT\n",
           "jcs_deep_inspection_selected_chnl_usage",0xe9d);
  }
  if (psVar5 != (short *)0x0) {
    FUN_00407df0(psVar5);
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  uVar6 = json_object_new_int(1);
  json_object_object_add(param_2,&DAT_00676a24,uVar6);
  return;
}

