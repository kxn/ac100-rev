// func jcs_deep_inspection_chnl_usage_list @ 004d2bfc size=1176

void jcs_deep_inspection_chnl_usage_list(undefined4 param_1,undefined4 param_2)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *__format;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  short local_130 [2];
  char acStack_12c [260];
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_chnl_usage_list ENTER\n",
           "jcs_deep_inspection_chnl_usage_list",0xeb4);
  }
  local_130[0] = 0;
  iVar2 = _jcs_parse_sensor_id(param_1);
  if (iVar2 == -1) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid entry_id\n",
             "jcs_deep_inspection_chnl_usage_list",0xebf);
    }
    pbVar6 = (byte *)0x0;
  }
  else {
    pbVar6 = (byte *)sensor_di_db_get_chnls_util_info(iVar2,local_130);
    if (pbVar6 != (byte *)0x0) {
      if (local_130[0] < 1) {
        iVar2 = 0;
        if (sensor_di_warning_switch == 0) goto LAB_004d2f34;
        __format = "[SENSOR_DI_WARNING]%s()/line %d : result chnl_cnt <= 0\n";
        uVar4 = 0xecc;
      }
      else {
        iVar2 = json_object_new_array();
        if (iVar2 == 0) {
          if (sensor_di_err_switch == 0) goto LAB_004d2f38;
          __format = "[SENSOR_DI_ERROR]%s()/line %d : JSON_ARRAY_CREATE fail\n";
          uVar4 = 0xed3;
        }
        else {
          iVar7 = 0;
          pbVar5 = pbVar6;
          while( true ) {
            if (local_130[0] <= iVar7) {
              FUN_00407df0(pbVar6);
              json_object_object_add(param_2,"deep_inspection_chnl_usage_list",iVar2);
              uVar4 = json_object_new_int(0);
              json_object_object_add(param_2,&DAT_00676a24,uVar4);
              if (sensor_di_debug_switch == 0) {
                return;
              }
              printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_chnl_usage_list success EXIT\n"
                     ,"jcs_deep_inspection_chnl_usage_list",0xef3);
              return;
            }
            iVar3 = json_object_new_object();
            if (iVar3 == 0) break;
            iVar7 = iVar7 + 1;
            memset(acStack_12c,0,0x100);
            snprintf(acStack_12c,0x100,"%d",(uint)*pbVar5);
            uVar4 = json_object_new_string(acStack_12c);
            json_object_object_add(iVar3,"chnl",uVar4);
            memset(acStack_12c,0,0x100);
            snprintf(acStack_12c,0x100,"%d",(uint)pbVar5[1]);
            uVar4 = json_object_new_string(acStack_12c);
            json_object_object_add(iVar3,"wifi_util",uVar4);
            memset(acStack_12c,0,0x100);
            snprintf(acStack_12c,0x100,"%d",(uint)pbVar5[2]);
            uVar4 = json_object_new_string(acStack_12c);
            json_object_object_add(iVar3,"non_wifi_util",uVar4);
            memset(acStack_12c,0,0x100);
            snprintf(acStack_12c,0x100,"%d",(uint)pbVar5[3]);
            uVar4 = json_object_new_string(acStack_12c);
            json_object_object_add(iVar3,"free_util",uVar4);
            memset(acStack_12c,0,0x100);
            snprintf(acStack_12c,0x100,"%d",(uint)*(ushort *)(pbVar5 + 4));
            uVar4 = json_object_new_string(acStack_12c);
            json_object_object_add(iVar3,"ap_num",uVar4);
            memset(acStack_12c,0,0x100);
            snprintf(acStack_12c,0x100,"%d",(uint)*(ushort *)(pbVar5 + 6));
            uVar4 = json_object_new_string(acStack_12c);
            json_object_object_add(iVar3,"ssid_num",uVar4);
            memset(acStack_12c,0,0x100);
            puVar1 = (ushort *)(pbVar5 + 8);
            pbVar5 = pbVar5 + 10;
            snprintf(acStack_12c,0x100,"%d",(uint)*puVar1);
            uVar4 = json_object_new_string(acStack_12c);
            json_object_object_add(iVar3,"sta_num",uVar4);
            json_object_array_add(iVar2,iVar3);
          }
          if (sensor_di_err_switch == 0) goto LAB_004d2f38;
          __format = "[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE fail\n";
          uVar4 = 0xedd;
        }
      }
      printf(__format,"jcs_deep_inspection_chnl_usage_list",uVar4);
      goto LAB_004d2f38;
    }
    if (sensor_di_warning_switch != 0) {
      printf("[SENSOR_DI_WARNING]%s()/line %d : get_chnls_util_info fail\n",
             "jcs_deep_inspection_chnl_usage_list",0xec6);
      iVar2 = 0;
      goto LAB_004d2f38;
    }
  }
LAB_004d2f34:
  iVar2 = 0;
LAB_004d2f38:
  if (sensor_di_warning_switch != 0) {
    printf("[SENSOR_DI_WARNING]%s()/line %d : jcs_deep_inspection_chnl_usage_list fail EXIT\n",
           "jcs_deep_inspection_chnl_usage_list",0xef7);
  }
  if (pbVar6 != (byte *)0x0) {
    FUN_00407df0(pbVar6);
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  uVar4 = json_object_new_int(1);
  json_object_object_add(param_2,&DAT_00676a24,uVar4);
  return;
}

