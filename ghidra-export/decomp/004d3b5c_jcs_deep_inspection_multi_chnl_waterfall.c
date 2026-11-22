// func jcs_deep_inspection_multi_chnl_waterfall @ 004d3b5c size=2388

void jcs_deep_inspection_multi_chnl_waterfall(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  size_t sVar9;
  char *__format;
  int iVar10;
  FILE *__s;
  short *psVar11;
  char *pcVar12;
  short *psVar13;
  undefined8 uVar14;
  short local_1b0 [2];
  char acStack_1ac [120];
  char acStack_134 [260];
  int local_30;
  int local_2c;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_multi_chnl_waterfall ENTER\n",
           "jcs_deep_inspection_multi_chnl_waterfall",0xcb6);
  }
  local_1b0[0] = 0;
  memset(acStack_1ac,0,0x78);
  iVar2 = _jcs_parse_sensor_id(param_1);
  if (iVar2 == -1) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : invalid entry_id\n",
             "jcs_deep_inspection_multi_chnl_waterfall",0xcca);
    }
    iVar2 = 0;
LAB_004d3eb0:
    pcVar12 = (char *)0x0;
    __s = (FILE *)0x0;
    iVar3 = 0;
    iVar6 = 0;
    iVar5 = 0;
  }
  else {
    iVar3 = json_object_object_get(param_1,"start");
    if (iVar3 == 0) {
      bVar1 = false;
      iVar3 = 0;
    }
    else {
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 3) {
        bVar1 = true;
        iVar3 = json_object_get_int(iVar3);
      }
      else {
        iVar4 = json_object_get_type();
        if (iVar4 == 2) {
          uVar14 = json_object_get_double(iVar3);
          bVar1 = true;
          iVar3 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_deep_inspection_multi_chnl_waterfall",0xcd3);
          }
          bVar1 = true;
          iVar3 = -1;
        }
      }
    }
    iVar4 = json_object_object_get(param_1,"end");
    if (iVar4 == 0) {
      bVar1 = false;
      iVar4 = 0;
    }
    else {
      iVar5 = json_object_get_type(iVar4);
      if (iVar5 == 3) {
        iVar4 = json_object_get_int(iVar4);
      }
      else {
        iVar5 = json_object_get_type();
        if (iVar5 == 2) {
          uVar14 = json_object_get_double(iVar4);
          iVar4 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
        }
        else {
          iVar4 = -1;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_deep_inspection_multi_chnl_waterfall",0xcde);
          }
        }
      }
    }
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : start=%d, end=%d\n",
             "jcs_deep_inspection_multi_chnl_waterfall",0xce4,iVar3,iVar4);
    }
    iVar2 = sensor_di_db_get_freq_water_fall(iVar2,local_1b0);
    if (iVar2 == 0) {
      if (sensor_di_debug_switch != 0) {
        pcVar12 = "[SENSOR_DI_DEBUG]%s()/line %d : get_freq_water_fall fail\n";
        uVar8 = 0xce9;
LAB_004d402c:
        printf(pcVar12,"jcs_deep_inspection_multi_chnl_waterfall",uVar8);
      }
      goto LAB_004d3eb0;
    }
    if (local_1b0[0] < 1) {
      if (sensor_di_err_switch != 0) {
        pcVar12 = "[SENSOR_DI_ERROR]%s()/line %d : param invalid\n";
        uVar8 = 0xcef;
        goto LAB_004d402c;
      }
      goto LAB_004d3eb0;
    }
    iVar5 = json_object_new_object();
    if (iVar5 == 0) {
      if (sensor_di_err_switch != 0) {
        printf("[SENSOR_DI_ERROR]%s()/line %d : Create json object ret_obj failed\n",
               "jcs_deep_inspection_multi_chnl_waterfall",0xcf7);
      }
      pcVar12 = (char *)0x0;
      __s = (FILE *)0x0;
      iVar3 = 0;
      iVar6 = 0;
    }
    else {
      iVar6 = json_object_new_array();
      if (iVar6 == 0) {
        if (sensor_di_err_switch != 0) {
          pcVar12 = "[SENSOR_DI_ERROR]%s()/line %d : JSON_ARRAY_CREATE fail\n";
          uVar8 = 0xcfe;
LAB_004d4128:
          printf(pcVar12,"jcs_deep_inspection_multi_chnl_waterfall",uVar8);
        }
      }
      else {
        if ((-1 < iVar3) && (iVar3 <= iVar4)) {
          iVar7 = (int)local_1b0[0];
          if (bVar1) {
            if (iVar7 <= iVar4) {
              iVar4 = iVar7 + -1;
            }
            if (iVar7 < iVar3) {
              if (sensor_di_err_switch != 0) {
                pcVar12 = "[SENSOR_DI_ERROR]%s()/line %d : invalid start value\n";
                uVar8 = 0xd10;
                goto LAB_004d4128;
              }
              goto LAB_004d40b4;
            }
          }
          else {
            iVar4 = iVar7 + -1;
            iVar3 = 0;
          }
          psVar13 = (short *)(iVar2 + iVar3 * 0x188);
          for (local_30 = iVar3; local_30 <= iVar4; local_30 = local_30 + 1) {
            iVar3 = json_object_new_object();
            if (iVar3 == 0) {
              if (sensor_di_err_switch == 0) {
LAB_004d4358:
                __s = (FILE *)0x0;
                pcVar12 = (char *)0x0;
              }
              else {
                pcVar12 = "[SENSOR_DI_ERROR]%s()/line %d : JSON_OBJ_CREATE fail\n";
                uVar8 = 0xd20;
LAB_004d4370:
                __s = (FILE *)0x0;
                printf(pcVar12,"jcs_deep_inspection_multi_chnl_waterfall",uVar8);
                pcVar12 = (char *)0x0;
              }
              goto LAB_004d3ebc;
            }
            memset(acStack_134,0,0x100);
            snprintf(acStack_134,0x100,"%d",(int)*psVar13);
            uVar8 = json_object_new_string(acStack_134);
            json_object_object_add(iVar3,"time",uVar8);
            memset(acStack_134,0,0x100);
            snprintf(acStack_134,0x100,"%d",(int)psVar13[1]);
            uVar8 = json_object_new_string(acStack_134);
            json_object_object_add(iVar3,"start",uVar8);
            memset(acStack_134,0,0x100);
            snprintf(acStack_134,0x100,"%d",(int)psVar13[2]);
            uVar8 = json_object_new_string(acStack_134);
            json_object_object_add(iVar3,"end",uVar8);
            iVar7 = json_object_new_array();
            if (iVar7 == 0) {
              if (sensor_di_err_switch != 0) {
                pcVar12 = "[SENSOR_DI_ERROR]%s()/line %d : JSON_ARRAY_CREATE fail\n";
                uVar8 = 0xd2b;
                goto LAB_004d4370;
              }
              goto LAB_004d4358;
            }
            if (psVar13[3] != 0) {
              psVar11 = psVar13;
              for (local_2c = 0; local_2c < psVar13[3]; local_2c = local_2c + 1) {
                if (*(char *)(psVar11 + 4) < -0x78) {
                  memset(acStack_134,0,0x100);
                  iVar10 = -0x78;
                }
                else {
                  memset(acStack_134,0,0x100);
                  iVar10 = (int)*(char *)(psVar11 + 4);
                }
                psVar11 = (short *)((int)psVar11 + 1);
                snprintf(acStack_134,0x100,"%d",iVar10);
                uVar8 = json_object_new_string(acStack_134);
                json_object_array_add(iVar7,uVar8);
              }
            }
            memset(acStack_134,0,0x100);
            psVar11 = psVar13 + 3;
            psVar13 = psVar13 + 0xc4;
            snprintf(acStack_134,0x100,"%d",(int)*psVar11);
            uVar8 = json_object_new_string(acStack_134);
            json_object_object_add(iVar3,"length",uVar8);
            json_object_object_add(iVar3,"spectrums",iVar7);
            json_object_array_add(iVar6,iVar3);
          }
          json_object_object_add(iVar5,"deep_inspection_multi_chnl_waterfall",iVar6);
          FUN_00407df0(iVar2);
          pcVar12 = (char *)json_object_to_json_string_ext(iVar5,0);
          pcVar12 = strdup(pcVar12);
          if (pcVar12 == (char *)0x0) {
            if (sensor_di_err_switch == 0) {
              __s = (FILE *)0x0;
            }
            else {
              __s = (FILE *)0x0;
              printf("[SENSOR_DI_ERROR]%s()/line %d : generate result_str failed\n",
                     "jcs_deep_inspection_multi_chnl_waterfall",0xd51);
            }
          }
          else {
            json_object_put(iVar5);
            sVar9 = strlen(pcVar12);
            l_sensor_di_file_write_counter = l_sensor_di_file_write_counter + 1;
            snprintf(acStack_1ac,0x78,"/tmp/deep_checkup_result_%d");
            __s = fopen(acStack_1ac,"w+");
            if (__s == (FILE *)0x0) {
              if (sensor_di_err_switch != 0) {
                __format = "[SENSOR_DI_ERROR]%s()/line %d : open result file failed.\n";
                uVar8 = 0xd5e;
LAB_004d4334:
                printf(__format,"jcs_deep_inspection_multi_chnl_waterfall",uVar8);
              }
            }
            else {
              sVar9 = fwrite(pcVar12,(int)(short)sVar9,1,__s);
              if (sVar9 == 1) {
                free(pcVar12);
                fclose(__s);
                if (sensor_di_debug_switch != 0) {
                  printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_deep_inspection_multi_chnl_waterfall success EXIT\n"
                         ,"jcs_deep_inspection_multi_chnl_waterfall",0xd74);
                }
                memset(acStack_134,0,0x100);
                snprintf(acStack_134,0x100,"%d",(int)local_1b0[0]);
                uVar8 = json_object_new_string(acStack_134);
                json_object_object_add(param_2,"waterfall_cnt",uVar8);
                uVar8 = json_object_new_string(acStack_1ac);
                json_object_object_add(param_2,"file_name",uVar8);
                uVar8 = 0;
                goto LAB_004d3f30;
              }
              if (sensor_di_err_switch != 0) {
                __format = "[SENSOR_DI_ERROR]%s()/line %d : write result to file failed.\n";
                uVar8 = 0xd64;
                goto LAB_004d4334;
              }
            }
          }
          iVar2 = 0;
          iVar3 = 0;
          iVar6 = 0;
          goto LAB_004d3ebc;
        }
        if (sensor_di_err_switch != 0) {
          pcVar12 = "[SENSOR_DI_ERROR]%s()/line %d : start or end invalid\n";
          uVar8 = 0xd04;
          goto LAB_004d4128;
        }
      }
LAB_004d40b4:
      pcVar12 = (char *)0x0;
      __s = (FILE *)0x0;
      iVar3 = 0;
    }
  }
LAB_004d3ebc:
  if (sensor_di_warning_switch != 0) {
    printf("[SENSOR_DI_WARNING]%s()/line %d : jcs_deep_inspection_multi_chnl_waterfall fail EXIT\n",
           "jcs_deep_inspection_multi_chnl_waterfall",0xd7b);
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  if (pcVar12 != (char *)0x0) {
    free(pcVar12);
  }
  if (iVar3 != 0) {
    json_object_put(iVar3);
  }
  if (iVar6 != 0) {
    json_object_put(iVar6);
  }
  if (iVar5 != 0) {
    json_object_put(iVar5);
  }
  uVar8 = 1;
  if (iVar2 != 0) {
    FUN_00407df0(iVar2);
    uVar8 = 1;
  }
LAB_004d3f30:
  uVar8 = json_object_new_int(uVar8);
  json_object_object_add(param_2,&DAT_00676a24,uVar8);
  return;
}

