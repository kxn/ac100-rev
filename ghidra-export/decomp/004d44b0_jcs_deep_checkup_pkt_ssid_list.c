// func jcs_deep_checkup_pkt_ssid_list @ 004d44b0 size=1552

void jcs_deep_checkup_pkt_ssid_list(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar7;
  size_t sVar6;
  undefined4 uVar8;
  char *__format;
  FILE *__s;
  char *pcVar9;
  undefined8 uVar10;
  char acStack_1a0 [120];
  char acStack_128 [256];
  
  memset(acStack_1a0,0,0x78);
  iVar1 = _jcs_parse_sensor_id(param_1);
  if (iVar1 < 0) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid entry_id\n","jcs_deep_checkup_pkt_ssid_list",
             0x9f5);
    }
    __s = (FILE *)0x0;
    pcVar9 = (char *)0x0;
    iVar1 = 0;
    iVar3 = 0;
    iVar2 = 0;
  }
  else {
    iVar2 = json_object_object_get(param_1,"chnl");
    if (iVar2 == 0) {
LAB_004d4544:
      sVar7 = -1;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "jcs_deep_checkup_pkt_ssid_list",0x9fa);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        sVar7 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004d4544;
        uVar10 = json_object_get_double(iVar2);
        sVar7 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
    }
    iVar2 = json_object_new_object();
    if (iVar2 == 0) {
      if (sensor_di_err_switch != 0) {
        printf("[SENSOR_DI_ERROR]%s()/line %d : Create json object ret_obj failed\n",
               "jcs_deep_checkup_pkt_ssid_list",0xa00);
      }
      pcVar9 = (char *)0x0;
      __s = (FILE *)0x0;
      goto LAB_004d47f0;
    }
    iVar3 = json_object_new_array();
    if (iVar3 == 0) {
      if (sensor_di_err_switch != 0) {
        printf("[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE FAIL\n",
               "jcs_deep_checkup_pkt_ssid_list",0xa07);
      }
    }
    else {
      iVar4 = sensor_di_db_pkt_stat_data_available(iVar1,(int)sVar7);
      if ((iVar4 != 0) &&
         (iVar1 = sensor_di_db_pkt_stat_cache_refresh(&l_sensor_di_pkt_stat_cache,iVar1,(int)sVar7),
         iVar1 != -1)) {
        for (iVar4 = FUN_004081b0(&DAT_007680fc); iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
          iVar1 = json_object_new_object();
          if (iVar1 == 0) {
            if (sensor_di_err_switch == 0) {
LAB_004d49b4:
              __s = (FILE *)0x0;
              pcVar9 = (char *)0x0;
            }
            else {
              __s = (FILE *)0x0;
              printf("[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n",
                     "jcs_deep_checkup_pkt_ssid_list",0xa1c);
              pcVar9 = (char *)0x0;
            }
            goto LAB_004d459c;
          }
          iVar5 = json_object_new_array();
          if (iVar5 == 0) {
            __s = (FILE *)0x0;
            if (sensor_di_err_switch == 0) goto LAB_004d49b4;
            printf("[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n",
                   "jcs_deep_checkup_pkt_ssid_list",0xa24);
            pcVar9 = (char *)0x0;
            goto LAB_004d459c;
          }
          memset(acStack_128,0,0x100);
          snprintf(acStack_128,0x100,"%d",(int)*(short *)(iVar4 + 0x3e));
          uVar8 = json_object_new_string(acStack_128);
          json_object_object_add(iVar1,"ssid_id",uVar8);
          if (*(char *)(iVar4 + 0x3d) == '\0') {
            uVar8 = json_object_new_string(iVar4 + 0xc);
            json_object_object_add(iVar1,"name",uVar8);
          }
          memset(acStack_128,0,0x100);
          snprintf(acStack_128,0x100,"%d",(uint)*(ushort *)(iVar4 + 0x40));
          uVar8 = json_object_new_string(acStack_128);
          json_object_array_add(iVar5,uVar8);
          memset(acStack_128,0,0x100);
          snprintf(acStack_128,0x100,"%d",(uint)*(ushort *)(iVar4 + 0x42));
          uVar8 = json_object_new_string(acStack_128);
          json_object_array_add(iVar5,uVar8);
          json_object_object_add(iVar1,"percent",iVar5);
          json_object_array_add(iVar3,iVar1);
        }
        json_object_object_add(iVar2,"deep_checkup_pkt_ssid_list",iVar3);
        pcVar9 = (char *)json_object_to_json_string_ext(iVar2,0);
        pcVar9 = strdup(pcVar9);
        if (pcVar9 == (char *)0x0) {
          if (sensor_di_err_switch == 0) {
            __s = (FILE *)0x0;
            iVar1 = 0;
            iVar3 = 0;
            goto LAB_004d459c;
          }
          __format = "[SENSOR_DI_ERROR]%s()/line %d : generate result_str failed\n";
          uVar8 = 0xa3d;
          __s = (FILE *)0x0;
LAB_004d4990:
          iVar1 = 0;
          printf(__format,"jcs_deep_checkup_pkt_ssid_list",uVar8);
          iVar3 = 0;
        }
        else {
          json_object_put(iVar2);
          sVar6 = strlen(pcVar9);
          l_sensor_di_file_write_counter = l_sensor_di_file_write_counter + 1;
          snprintf(acStack_1a0,0x78,"/tmp/deep_checkup_result_%d");
          __s = fopen(acStack_1a0,"w+");
          if (__s == (FILE *)0x0) {
            if (sensor_di_err_switch != 0) {
              __format = "[SENSOR_DI_ERROR]%s()/line %d : open result file failed.\n";
              uVar8 = 0xa4a;
              goto LAB_004d4990;
            }
          }
          else {
            sVar6 = fwrite(pcVar9,(int)(short)sVar6,1,__s);
            if (sVar6 == 1) {
              free(pcVar9);
              fclose(__s);
              if (sensor_di_debug_switch != 0) {
                printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_checkup_pkt_ssid_list success EXIT\n"
                       ,"jcs_deep_checkup_pkt_ssid_list",0xa60);
              }
              uVar8 = json_object_new_string(acStack_1a0);
              json_object_object_add(param_2,"file_name",uVar8);
              uVar8 = 0;
              goto LAB_004d45fc;
            }
            if (sensor_di_err_switch != 0) {
              __format = "[SENSOR_DI_ERROR]%s()/line %d : write result to file failed.\n";
              uVar8 = 0xa50;
              goto LAB_004d4990;
            }
          }
LAB_004d47f0:
          iVar1 = 0;
          iVar3 = 0;
        }
        goto LAB_004d459c;
      }
    }
    __s = (FILE *)0x0;
    pcVar9 = (char *)0x0;
    iVar1 = 0;
  }
LAB_004d459c:
  if (sensor_di_warning_switch != 0) {
    printf("[SENSOR_DI_WARNING]%s()/line %d : jcs_deep_checkup_pkt_ssid_list fail EXIT\n",
           "jcs_deep_checkup_pkt_ssid_list",0xa66);
  }
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  if (iVar3 != 0) {
    json_object_put(iVar3);
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  uVar8 = 1;
  if (pcVar9 != (char *)0x0) {
    free(pcVar9);
    uVar8 = 1;
  }
LAB_004d45fc:
  uVar8 = json_object_new_int(uVar8);
  json_object_object_add(param_2,&DAT_00676a24,uVar8);
  return;
}

