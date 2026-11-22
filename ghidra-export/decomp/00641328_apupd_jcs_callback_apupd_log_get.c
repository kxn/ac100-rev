// func apupd_jcs_callback_apupd_log_get @ 00641328 size=1428

void apupd_jcs_callback_apupd_log_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  FILE *__s;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined4 local_30 [2];
  
  local_30[0] = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_jcs_callback_apupd_log_get",0xadf);
    return;
  }
  uVar7 = 0;
  iVar1 = json_object_object_get(param_1,"start");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar7 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar8 = json_object_get_double(iVar1);
        uVar7 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
      }
      else {
        uVar7 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "apupd_jcs_callback_apupd_log_get",0xae5);
        }
      }
    }
  }
  uVar6 = 10;
  iVar1 = json_object_object_get(param_1,"size");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar6 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar8 = json_object_get_double(iVar1);
        uVar6 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
      }
      else {
        uVar6 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "apupd_jcs_callback_apupd_log_get",0xae7);
        }
      }
    }
  }
  iVar1 = json_object_object_get(param_1,"model_id");
  if (iVar1 == 0) {
    uVar7 = 1;
    if (g_apupd_error == 0) goto LAB_00641478;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar7 = 1;
      goto LAB_00641478;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: get model id from json failed.\r\n";
    uVar7 = 0xaeb;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
LAB_006415f0:
      if (iVar1 != -1) {
        iVar2 = json_object_new_array();
        if (iVar2 != 0) {
          iVar3 = apupd_db_model_log_num_get(iVar1,local_30);
          if (iVar3 == -1) {
            __s = (FILE *)0x0;
            if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar5 = "[APUPD_ERROR]%32s() %05d: get log number failed.\r\n";
              uVar7 = 0xaff;
LAB_0064169c:
              printf(pcVar5,"apupd_jcs_callback_apupd_log_get",uVar7);
            }
          }
          else {
            iVar3 = apupd_db_model_log_handle(iVar1,uVar7,uVar6,apupd_callback_log_json_add,iVar2);
            if (iVar3 == -1) {
              __s = (FILE *)0x0;
              if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                pcVar5 = "[APUPD_ERROR]%32s() %05d: get log failed.\r\n";
                uVar7 = 0xb06;
                goto LAB_0064169c;
              }
            }
            else {
              __s = fopen("/tmp/apupd_logs","w+");
              if (__s == (FILE *)0x0) {
                if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  printf("[APUPD_ERROR]%32s() %05d: open get file[%s] fail!\r\n",
                         "apupd_jcs_callback_apupd_log_get",0xb0d,"/tmp/apupd_logs");
                }
              }
              else {
                pcVar5 = (char *)json_object_to_json_string_ext(iVar2,0);
                if (pcVar5 == (char *)0x0) {
                  if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    pcVar5 = "[APUPD_ERROR]%32s() %05d: JSON_STRING_FROM_OBJ fail!\r\n";
                    uVar7 = 0xb12;
                    goto LAB_0064169c;
                  }
                }
                else {
                  sVar4 = strlen(pcVar5);
                  sVar4 = fwrite(pcVar5,sVar4,1,__s);
                  if (sVar4 == 1) {
                    fclose(__s);
                    json_object_put(iVar2);
                    uVar7 = json_object_new_string("/tmp/apupd_logs");
                    json_object_object_add(param_2,"file_name",uVar7);
                    uVar7 = json_object_new_int(local_30[0]);
                    json_object_object_add(param_2,"logs_num",uVar7);
                    uVar7 = json_object_new_int(iVar1);
                    json_object_object_add(param_2,"model_id",uVar7);
                    uVar7 = 0;
                    goto LAB_00641478;
                  }
                  if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                    pcVar5 = "[APUPD_ERROR]%32s() %05d: write result to file fail!\r\n";
                    uVar7 = 0xb18;
                    goto LAB_0064169c;
                  }
                }
              }
            }
          }
          json_object_put(iVar2);
          if (__s == (FILE *)0x0) {
            uVar7 = 1;
          }
          else {
            fclose(__s);
            uVar7 = 1;
          }
          goto LAB_00641478;
        }
        uVar7 = 1;
        if (g_apupd_error == 0) goto LAB_00641478;
        iVar1 = is_target_debug_ap(1);
        if (iVar1 == 0) {
          uVar7 = 1;
          goto LAB_00641478;
        }
        pcVar5 = "[APUPD_ERROR]%32s() %05d: malloc json obj failed.\r\n";
        uVar7 = 0xaf8;
        goto LAB_006415b8;
      }
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar8 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        goto LAB_006415f0;
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "apupd_jcs_callback_apupd_log_get",0xaee);
      }
    }
    uVar7 = 1;
    if (g_apupd_error == 0) goto LAB_00641478;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar7 = 1;
      goto LAB_00641478;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: get model id from json failed.\r\n";
    uVar7 = 0xaf1;
  }
LAB_006415b8:
  printf(pcVar5,"apupd_jcs_callback_apupd_log_get",uVar7);
  uVar7 = 1;
LAB_00641478:
  uVar7 = json_object_new_int(uVar7);
  json_object_object_add(param_2,&DAT_00676a24,uVar7);
  return;
}

