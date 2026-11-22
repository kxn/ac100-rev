// func apupd_jcs_callback_apupd_wtp_get @ 006404fc size=1396

void apupd_jcs_callback_apupd_wtp_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  FILE *__s;
  size_t sVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined1 auStack_818 [2032];
  
  memset(auStack_818,0,0x7ec);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_jcs_callback_apupd_wtp_get",0xc98);
    return;
  }
  uVar9 = 0;
  iVar1 = json_object_object_get(param_1,"start");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar9 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar10 = json_object_get_double(iVar1);
        uVar9 = __fixunsdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
      else {
        uVar9 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "apupd_jcs_callback_apupd_wtp_get",0xc9e);
        }
      }
    }
  }
  uVar8 = 10;
  iVar1 = json_object_object_get(param_1,"size");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar8 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar10 = json_object_get_double(iVar1);
        uVar8 = __fixunsdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
      else {
        uVar8 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "apupd_jcs_callback_apupd_wtp_get",0xca0);
        }
      }
    }
  }
  iVar1 = json_object_object_get(param_1,"model_id");
  if (iVar1 == 0) {
    iVar1 = -2;
LAB_0064073c:
    apmngr_db_group_id_parse(param_1,auStack_818);
    uVar3 = apmngr_db_role_bitmap_get(param_1);
    iVar2 = json_object_new_array();
    if (iVar2 != 0) {
      if (iVar1 == -2) {
        pcVar4 = apupd_callback_wtp_json_add_for_ap;
      }
      else {
        pcVar4 = apupd_callback_wtp_json_add;
      }
      iVar5 = apupd_db_model_wtp_handle(iVar1,auStack_818,uVar3,uVar9,uVar8,pcVar4,iVar2);
      if (iVar5 == -1) {
        __s = (FILE *)0x0;
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          pcVar7 = "[APUPD_ERROR]%32s() %05d: delete log by model id failed.\r\n";
          uVar9 = 0xcc4;
          goto LAB_00640854;
        }
      }
      else {
        __s = fopen("/tmp/apupd_wtps","w+");
        if (__s == (FILE *)0x0) {
          if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[APUPD_ERROR]%32s() %05d: open get file[%s] fail!\r\n",
                   "apupd_jcs_callback_apupd_wtp_get",0xccb,"/tmp/apupd_wtps");
          }
        }
        else {
          pcVar7 = (char *)json_object_to_json_string_ext(iVar2,0);
          if (pcVar7 == (char *)0x0) {
            if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar7 = "[APUPD_ERROR]%32s() %05d: JSON_STRING_FROM_OBJ fail!\r\n";
              uVar9 = 0xcd0;
LAB_00640854:
              printf(pcVar7,"apupd_jcs_callback_apupd_wtp_get",uVar9);
            }
          }
          else {
            sVar6 = strlen(pcVar7);
            sVar6 = fwrite(pcVar7,sVar6,1,__s);
            if (sVar6 == 1) {
              fclose(__s);
              json_object_put(iVar2);
              uVar9 = json_object_new_string("/tmp/apupd_wtps");
              json_object_object_add(param_2,"file_name",uVar9);
              uVar9 = json_object_new_int(iVar5);
              json_object_object_add(param_2,"wtp_num",uVar9);
              uVar9 = json_object_new_int(iVar1);
              json_object_object_add(param_2,"model_id",uVar9);
              uVar9 = 0;
              goto LAB_00640660;
            }
            if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar7 = "[APUPD_ERROR]%32s() %05d: write result to file fail!\r\n";
              uVar9 = 0xcd6;
              goto LAB_00640854;
            }
          }
        }
      }
      json_object_put(iVar2);
      if (__s == (FILE *)0x0) {
        uVar9 = 1;
      }
      else {
        fclose(__s);
        uVar9 = 1;
      }
      goto LAB_00640660;
    }
    uVar9 = 1;
    if (g_apupd_error == 0) goto LAB_00640660;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar9 = 1;
      goto LAB_00640660;
    }
    pcVar7 = "[APUPD_ERROR]%32s() %05d: malloc json obj failed.\r\n";
    uVar9 = 0xcb3;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
LAB_00640730:
      if (iVar1 != -1) goto LAB_0064073c;
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar10 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        goto LAB_00640730;
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "apupd_jcs_callback_apupd_wtp_get",0xca5);
      }
    }
    uVar9 = 1;
    if (g_apupd_error == 0) goto LAB_00640660;
    iVar1 = is_target_debug_ap(1);
    if (iVar1 == 0) {
      uVar9 = 1;
      goto LAB_00640660;
    }
    pcVar7 = "[APUPD_ERROR]%32s() %05d: get model id from json failed.\r\n";
    uVar9 = 0xca8;
  }
  printf(pcVar7,"apupd_jcs_callback_apupd_wtp_get",uVar9);
  uVar9 = 1;
LAB_00640660:
  uVar9 = json_object_new_int(uVar9);
  json_object_object_add(param_2,&DAT_00676a24,uVar9);
  return;
}

