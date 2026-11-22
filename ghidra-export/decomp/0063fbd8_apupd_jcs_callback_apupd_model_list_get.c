// func apupd_jcs_callback_apupd_model_list_get @ 0063fbd8 size=1296

void apupd_jcs_callback_apupd_model_list_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  FILE *__s;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 auStack_1b8 [8];
  int local_1b0;
  char *local_1ac;
  char *local_1a8;
  int local_1a4;
  int local_1a0;
  char acStack_198 [127];
  undefined1 local_119;
  char acStack_118 [127];
  undefined1 local_99;
  char acStack_98 [127];
  undefined1 local_19;
  
  memset(acStack_98,0,0x80);
  memset(acStack_118,0,0x80);
  memset(acStack_198,0,0x80);
  iVar1 = json_object_object_get(param_1,"search_name");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar5 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "apupd_jcs_callback_apupd_model_list_get",0xd72);
      }
      pcVar5 = "";
    }
    strncpy(acStack_118,pcVar5,0x7f);
    local_99 = 0;
    iVar1 = json_object_object_get(param_1,"search_value");
    if (iVar1 == 0) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: Invalid jcs search request.\r\n",
               "apupd_jcs_callback_apupd_model_list_get",0xd79);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar5 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "apupd_jcs_callback_apupd_model_list_get",0xd75);
        }
        pcVar5 = "";
      }
      strncpy(acStack_198,pcVar5,0x7f);
      local_119 = 0;
    }
  }
  uVar6 = 0xffff;
  iVar1 = json_object_object_get(param_1,"group_id");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar5 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "apupd_jcs_callback_apupd_model_list_get",0xd7f);
      }
      pcVar5 = "";
    }
    strncpy(acStack_98,pcVar5,0x7f);
    local_19 = 0;
    uVar6 = atoi(acStack_98);
    uVar6 = uVar6 & 0xffff;
  }
  memset(auStack_1b8,0,0x20);
  local_1ac = acStack_118;
  local_1a8 = acStack_198;
  local_1a0 = json_object_new_array();
  local_1b0 = 0;
  if (local_1a0 == 0) {
    if (g_apupd_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APUPD_ERROR]%32s() %05d: Failed to create json array.\r\n",
           "apupd_firmed_model_list_get",0xd2a);
    return;
  }
  local_1a4 = FUN_004080a0(_apupd_firmed_model_data_obj,_apupd_firmed_model_data_key,
                           _apupd_firmed_model_data_cmp,600);
  if (local_1a4 == 0) {
    if (g_apupd_error != 0) {
      iVar2 = is_target_debug_ap();
      iVar1 = 0;
      if (iVar2 == 0) {
        __s = (FILE *)0x0;
      }
      else {
        printf("[APUPD_ERROR]%32s() %05d: Failed to create model hash.\r\n",
               "apupd_firmed_model_list_get",0xd33);
        __s = (FILE *)0x0;
      }
      goto LAB_0063fe1c;
    }
  }
  else {
    if (uVar6 == 0xffff) {
      apmngr_db_foreach_proc(0xff7fffff,apupd_db_firmed_model_get,auStack_1b8);
    }
    else {
      apmngr_db_foreach_proc_by_group(uVar6,0xff7fffff,apupd_db_firmed_model_get,auStack_1b8);
    }
    pcVar5 = (char *)json_object_to_json_string_ext(local_1a0,0);
    if (pcVar5 != (char *)0x0) {
      sVar3 = strlen(pcVar5);
      __s = fopen("/tmp/ap_firmed_model","w+");
      if (__s == (FILE *)0x0) {
        iVar1 = 0;
        if (g_apupd_error == 0) goto LAB_0063fe1c;
        iVar2 = is_target_debug_ap();
        iVar1 = 0;
        if (iVar2 == 0) goto LAB_0063fe1c;
        pcVar5 = "[APUPD_ERROR]%32s() %05d: open ap-upd-model file failed.\r\n";
        uVar4 = 0xd4e;
      }
      else {
        sVar3 = fwrite(pcVar5,sVar3,1,__s);
        iVar1 = local_1b0;
        if (((sVar3 == 1) || (iVar1 = 0, g_apupd_error == 0)) ||
           (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0063fe1c;
        pcVar5 = "[APUPD_ERROR]%32s() %05d: write ap model to file failed.\r\n";
        uVar4 = 0xd55;
      }
      printf(pcVar5,"apupd_firmed_model_list_get",uVar4);
      iVar1 = 0;
      goto LAB_0063fe1c;
    }
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __s = (FILE *)0x0;
      printf("[APUPD_ERROR]%32s() %05d: translate ap-upd-model json to string failed.\r\n",
             "apupd_firmed_model_list_get",0xd45);
      iVar1 = 0;
      goto LAB_0063fe1c;
    }
  }
  __s = (FILE *)0x0;
  iVar1 = 0;
LAB_0063fe1c:
  if (local_1a0 != 0) {
    json_object_put();
  }
  if (local_1a4 != 0) {
    FUN_00408570(local_1a4,_apupd_firmed_model_data_free,0);
    FUN_00408310(local_1a4);
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  if (0 < iVar1) {
    uVar4 = json_object_new_string("/tmp/ap_firmed_model");
    json_object_object_add(param_2,"file_name",uVar4);
    uVar4 = json_object_new_int(iVar1);
    json_object_object_add(param_2,"total_num",uVar4);
  }
  return;
}

