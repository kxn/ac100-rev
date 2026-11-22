// func _apmngr_jcs_online_ap_model_get @ 0054a68c size=1752

void _apmngr_jcs_online_ap_model_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  FILE *__s;
  undefined4 uVar6;
  char *pcVar7;
  uint uVar8;
  undefined8 uVar9;
  int local_1b8;
  int local_1b4;
  int local_1b0;
  char *local_1ac;
  char *local_1a8;
  int local_1a4;
  int local_1a0;
  undefined4 local_19c;
  char acStack_198 [127];
  undefined1 local_119;
  char acStack_118 [127];
  undefined1 local_99;
  char acStack_98 [127];
  undefined1 local_19;
  
  memset(acStack_98,0,0x80);
  memset(acStack_118,0,0x80);
  memset(acStack_198,0,0x80);
  iVar1 = json_object_object_get(param_1,"start");
  if (iVar1 == 0) {
LAB_0054a720:
    iVar1 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_apmngr_jcs_online_ap_model_get",0xa28);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0054a720;
      uVar9 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  iVar2 = json_object_object_get(param_1,"size");
  if (iVar2 == 0) {
LAB_0054a770:
    iVar2 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_apmngr_jcs_online_ap_model_get",0xa2b);
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      iVar2 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 != 2) goto LAB_0054a770;
      uVar9 = json_object_get_double(iVar2);
      iVar2 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
  }
  iVar3 = json_object_object_get(param_1,"search_name");
  if (iVar3 != 0) {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 6) {
      pcVar7 = (char *)json_object_get_string(iVar3);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_online_ap_model_get",0xa30);
      }
      pcVar7 = "";
    }
    strncpy(acStack_118,pcVar7,0x7f);
    local_99 = 0;
    iVar3 = json_object_object_get(param_1,"search_value");
    if (iVar3 == 0) {
      if ((apmngr_err_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[APMNGR_ERROR]%s()/%d Invalid jcs search request.\n",
               "_apmngr_jcs_online_ap_model_get",0xa37);
      }
    }
    else {
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 6) {
        pcVar7 = (char *)json_object_get_string(iVar3);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_apmngr_jcs_online_ap_model_get",0xa33);
        }
        pcVar7 = "";
      }
      strncpy(acStack_198,pcVar7,0x7f);
      local_119 = 0;
    }
  }
  uVar8 = 0xffff;
  iVar3 = json_object_object_get(param_1,"group_id");
  if (iVar3 != 0) {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 6) {
      pcVar7 = (char *)json_object_get_string(iVar3);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_online_ap_model_get",0xa3c);
      }
      pcVar7 = "";
    }
    strncpy(acStack_98,pcVar7,0x7f);
    local_19 = 0;
    uVar8 = atoi(acStack_98);
    uVar8 = uVar8 & 0xffff;
  }
  memset(&local_1b8,0,0x20);
  local_1ac = acStack_118;
  local_1a8 = acStack_198;
  local_1b8 = iVar1;
  local_1b4 = iVar2;
  local_1a0 = json_object_new_array();
  local_1b0 = 0;
  if ((apmngr_debug_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d Get AP online model from %d to %d.\n",
           "_apmngr_jcs_online_model_list_get",0x911,iVar1,iVar1 + iVar2);
  }
  if (local_1a0 == 0) {
    if (apmngr_err_switch == '\0') {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[APMNGR_ERROR]%s()/%d Failed to create json array.\n",
           "_apmngr_jcs_online_model_list_get",0x914);
    return;
  }
  local_1a4 = FUN_004080a0(_apmngr_online_model_data_obj,_apmngr_online_model_data_key,
                           _apmngr_online_model_data_cmp,600);
  if (local_1a4 == 0) {
    if (apmngr_err_switch != '\0') {
      iVar2 = is_target_debug_ap();
      iVar1 = 0;
      if (iVar2 == 0) {
        __s = (FILE *)0x0;
      }
      else {
        printf("[APMNGR_ERROR]%s()/%d Failed to create model hash.\n",
               "_apmngr_jcs_online_model_list_get",0x91d);
        __s = (FILE *)0x0;
      }
      goto LAB_0054a9ac;
    }
  }
  else {
    if (uVar8 == 0xffff) {
      local_19c = 1;
      apmngr_db_foreach_proc(0x15f0000,_apmngr_db_online_model_get,&local_1b8);
      local_19c = 0;
      apmngr_db_foreach_proc(0x15f0000,_apmngr_db_online_model_get,&local_1b8);
    }
    else {
      local_19c = 1;
      apmngr_db_foreach_proc_by_group(uVar8,0x15f0000,_apmngr_db_online_model_get,&local_1b8);
      local_19c = 0;
      apmngr_db_foreach_proc_by_group(uVar8,0x15f0000,_apmngr_db_online_model_get,&local_1b8);
    }
    pcVar7 = (char *)json_object_to_json_string_ext(local_1a0,0);
    if (pcVar7 != (char *)0x0) {
      sVar5 = strlen(pcVar7);
      __s = fopen("/tmp/ap_online_model","w+");
      if (__s == (FILE *)0x0) {
        iVar1 = 0;
        if (apmngr_err_switch == '\0') goto LAB_0054a9ac;
        iVar2 = is_target_debug_ap();
        iVar1 = 0;
        if (iVar2 == 0) goto LAB_0054a9ac;
        pcVar7 = "[APMNGR_ERROR]%s()/%d open ap-model file failed.\n";
        uVar6 = 0x93d;
      }
      else {
        sVar5 = fwrite(pcVar7,sVar5,1,__s);
        iVar1 = local_1b0;
        if (((sVar5 == 1) || (iVar1 = 0, apmngr_err_switch == '\0')) ||
           (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0054a9ac;
        pcVar7 = "[APMNGR_ERROR]%s()/%d write ap model to file failed.\n";
        uVar6 = 0x944;
      }
      printf(pcVar7,"_apmngr_jcs_online_model_list_get",uVar6);
      iVar1 = 0;
      goto LAB_0054a9ac;
    }
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __s = (FILE *)0x0;
      printf("[APMNGR_ERROR]%s()/%d translate ap-model json to string failed.\n",
             "_apmngr_jcs_online_model_list_get",0x934);
      iVar1 = 0;
      goto LAB_0054a9ac;
    }
  }
  __s = (FILE *)0x0;
  iVar1 = 0;
LAB_0054a9ac:
  if (local_1a0 != 0) {
    json_object_put();
  }
  if (local_1a4 != 0) {
    FUN_00408570(local_1a4,_apmngr_online_model_data_free,0);
    FUN_00408310(local_1a4);
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  if (0 < iVar1) {
    uVar6 = json_object_new_string("/tmp/ap_online_model");
    json_object_object_add(param_2,"file_name",uVar6);
    uVar6 = json_object_new_int(iVar1);
    json_object_object_add(param_2,"total_num",uVar6);
  }
  return;
}

