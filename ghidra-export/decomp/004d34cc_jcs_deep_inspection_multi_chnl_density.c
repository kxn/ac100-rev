// func jcs_deep_inspection_multi_chnl_density @ 004d34cc size=1680

void jcs_deep_inspection_multi_chnl_density(undefined4 param_1,undefined4 param_2)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  FILE *__s;
  undefined4 uVar6;
  char *__format;
  int iVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  int iVar12;
  char acStack_1a8 [120];
  char acStack_130 [256];
  int local_30;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_multi_chnl_density ENTER\n",
           "jcs_deep_inspection_multi_chnl_density",0xda1);
  }
  memset(acStack_1a8,0,0x78);
  iVar2 = _jcs_parse_sensor_id(param_1);
  if (iVar2 == -1) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid entry_id\n",
             "jcs_deep_inspection_multi_chnl_density",0xdb2);
    }
    psVar11 = (short *)0x0;
LAB_004d371c:
    pcVar4 = (char *)0x0;
    __s = (FILE *)0x0;
    iVar7 = 0;
    iVar10 = 0;
    iVar2 = 0;
  }
  else {
    psVar11 = (short *)sensor_di_db_get_freq_density(iVar2);
    if (psVar11 == (short *)0x0) {
      if (sensor_di_err_switch != 0) {
        printf("[SENSOR_DI_ERROR]%s()/line %d : get_freq_density fail\n",
               "jcs_deep_inspection_multi_chnl_density",0xdb9);
      }
      goto LAB_004d371c;
    }
    iVar2 = json_object_new_object();
    if (iVar2 == 0) {
      if (sensor_di_err_switch != 0) {
        printf("[SENSOR_DI_ERROR]%s()/line %d : Create json object ret_obj failed\n",
               "jcs_deep_inspection_multi_chnl_density",0xdc1);
      }
      pcVar4 = (char *)0x0;
      __s = (FILE *)0x0;
      iVar7 = 0;
      iVar10 = 0;
    }
    else {
      iVar10 = json_object_new_array();
      if (iVar10 == 0) {
        if (sensor_di_err_switch != 0) {
          printf("[SENSOR_DI_ERROR]%s()/line %d : JSON_ARRAY_CREATE fail\n",
                 "jcs_deep_inspection_multi_chnl_density",0xdc8);
        }
        __s = (FILE *)0x0;
        pcVar4 = (char *)0x0;
        iVar7 = 0;
      }
      else {
        if ((*psVar11 != 0) && (psVar11[1] != 0)) {
          iVar9 = 0;
          psVar8 = psVar11;
          do {
            iVar7 = json_object_new_object();
            if (iVar7 == 0) {
              if (sensor_di_err_switch == 0) {
LAB_004d3af0:
                __s = (FILE *)0x0;
                pcVar4 = (char *)0x0;
              }
              else {
                pcVar4 = "[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE fail\n";
                uVar6 = 0xdd5;
LAB_004d3b08:
                __s = (FILE *)0x0;
                printf(pcVar4,"jcs_deep_inspection_multi_chnl_density",uVar6);
                pcVar4 = (char *)0x0;
              }
              goto LAB_004d3728;
            }
            if (iVar9 == 0x6e) {
              pcVar4 = "average";
            }
            else {
              memset(acStack_130,0,0x100);
              snprintf(acStack_130,0x100,"%d",iVar9);
              pcVar4 = acStack_130;
            }
            uVar6 = json_object_new_string(pcVar4);
            json_object_object_add(iVar7,"density",uVar6);
            memset(acStack_130,0,0x100);
            snprintf(acStack_130,0x100,"%d",(int)*psVar8);
            uVar6 = json_object_new_string(acStack_130);
            json_object_object_add(iVar7,"start",uVar6);
            memset(acStack_130,0,0x100);
            snprintf(acStack_130,0x100,"%d",(int)psVar8[1]);
            uVar6 = json_object_new_string(acStack_130);
            json_object_object_add(iVar7,"end",uVar6);
            local_30 = json_object_new_array();
            if (local_30 == 0) {
              if (sensor_di_err_switch != 0) {
                pcVar4 = "[SENSOR_DI_ERROR]%s()/line %d : JSON_ARRAY_CREATE fail\n";
                uVar6 = 0xde7;
                goto LAB_004d3b08;
              }
              goto LAB_004d3af0;
            }
            iVar3 = (int)psVar8[2];
            iVar12 = 0;
            if (iVar3 != 0) {
              for (; iVar12 < iVar3; iVar12 = iVar12 + 1) {
                memset(acStack_130,0,0x100);
                snprintf(acStack_130,0x100,"%d",(int)*(char *)((int)psVar8 + iVar12 + 6));
                uVar6 = json_object_new_string(acStack_130);
                json_object_array_add(local_30,uVar6);
                iVar3 = (int)psVar8[2];
              }
            }
            iVar9 = iVar9 + 10;
            memset(acStack_130,0,0x100);
            psVar1 = psVar8 + 2;
            psVar8 = psVar8 + 0xc3;
            snprintf(acStack_130,0x100,"%d",(int)*psVar1);
            uVar6 = json_object_new_string(acStack_130);
            json_object_object_add(iVar7,"length",uVar6);
            json_object_object_add(iVar7,"spectrums",local_30);
            json_object_array_add(iVar10,iVar7);
          } while (iVar9 != 0x78);
        }
        json_object_object_add(iVar2,"deep_inspection_multi_chnl_density",iVar10);
        FUN_00407df0(psVar11);
        pcVar4 = (char *)json_object_to_json_string_ext(iVar2,0);
        pcVar4 = strdup(pcVar4);
        if (pcVar4 == (char *)0x0) {
          if (sensor_di_err_switch == 0) {
            __s = (FILE *)0x0;
          }
          else {
            __s = (FILE *)0x0;
            printf("[SENSOR_DI_ERROR]%s()/line %d : generate result_str failed\n",
                   "jcs_deep_inspection_multi_chnl_density",0xe06);
          }
        }
        else {
          json_object_put(iVar2);
          sVar5 = strlen(pcVar4);
          l_sensor_di_file_write_counter = l_sensor_di_file_write_counter + 1;
          snprintf(acStack_1a8,0x78,"/tmp/deep_checkup_result_%d");
          __s = fopen(acStack_1a8,"w+");
          if (__s == (FILE *)0x0) {
            if (sensor_di_err_switch != 0) {
              __format = "[SENSOR_DI_ERROR]%s()/line %d : open result file failed.\n";
              uVar6 = 0xe13;
LAB_004d3a08:
              printf(__format,"jcs_deep_inspection_multi_chnl_density",uVar6);
            }
          }
          else {
            sVar5 = fwrite(pcVar4,(int)(short)sVar5,1,__s);
            if (sVar5 == 1) {
              free(pcVar4);
              fclose(__s);
              if (sensor_di_debug_switch != 0) {
                printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_multi_chnl_density success EXIT\n"
                       ,"jcs_deep_inspection_multi_chnl_density",0xe29);
              }
              uVar6 = json_object_new_string(acStack_1a8);
              json_object_object_add(param_2,"file_name",uVar6);
              uVar6 = 0;
              goto LAB_004d379c;
            }
            if (sensor_di_err_switch != 0) {
              __format = "[SENSOR_DI_ERROR]%s()/line %d : write result to file failed.\n";
              uVar6 = 0xe19;
              goto LAB_004d3a08;
            }
          }
        }
        psVar11 = (short *)0x0;
        iVar7 = 0;
        iVar10 = 0;
      }
    }
  }
LAB_004d3728:
  if (sensor_di_warning_switch != 0) {
    printf("[SENSOR_DI_WARNING]%s()/line %d : jcs_deep_inspection_multi_chnl_density fail EXIT\n",
           "jcs_deep_inspection_multi_chnl_density",0xe2f);
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  if (pcVar4 != (char *)0x0) {
    free(pcVar4);
  }
  if (iVar7 != 0) {
    json_object_put(iVar7);
  }
  if (iVar10 != 0) {
    json_object_put(iVar10);
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  uVar6 = 1;
  if (psVar11 != (short *)0x0) {
    FUN_00407df0(psVar11);
    uVar6 = 1;
  }
LAB_004d379c:
  uVar6 = json_object_new_int(uVar6);
  json_object_object_add(param_2,&DAT_00676a24,uVar6);
  return;
}

