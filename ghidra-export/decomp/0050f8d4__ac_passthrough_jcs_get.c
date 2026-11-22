// func _ac_passthrough_jcs_get @ 0050f8d4 size=1168

void _ac_passthrough_jcs_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  void *__s;
  undefined4 uVar6;
  char *pcVar7;
  size_t __n;
  void *pvVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [128];
  
  memset(auStack_a8,0,0x80);
  local_ac = 0;
  local_b0 = 0;
  iVar1 = json_object_object_get(param_1,"request_id");
  if (iVar1 == 0) {
    __s = (void *)0x0;
    pcVar4 = (char *)0x0;
LAB_0050fc6c:
    uVar9 = json_object_new_int(local_b0);
    json_object_object_add(param_2,"continue",uVar9);
    uVar9 = json_object_new_int(local_ac);
    json_object_object_add(param_2,"cnt",uVar9);
    if (pcVar4 == (char *)0x0) goto LAB_0050fb64;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar10 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
      else {
        iVar1 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_ac_passthrough_jcs_get",0x7e6);
        }
      }
    }
    uVar9 = 0;
    iVar2 = json_object_object_get(param_1,"get_rsponse_info_sync");
    if (iVar2 != 0) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar9 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 == 2) {
          uVar10 = json_object_get_double(iVar2);
          uVar9 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        }
        else {
          uVar9 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_ac_passthrough_jcs_get",0x7ea);
          }
        }
      }
    }
    if (ac_passthrough_debug_switch != '\0') {
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d requeset_id_obj:%d\n","_ac_passthrough_jcs_get",0x7ed,
             iVar1);
    }
    if (iVar1 < 1) {
      return;
    }
    iVar2 = json_object_object_get(param_1,"ap_mac");
    if (iVar2 == 0) {
      __s = (void *)0x0;
      iVar2 = 0;
      pcVar4 = (char *)0x0;
LAB_0050fc28:
      get_tdcp_response_from_ap(__s,iVar2,iVar1,auStack_a8,&local_ac,&local_b0,uVar9);
      uVar9 = json_object_new_string(auStack_a8);
      json_object_object_add(param_2,"get_rsponse_info",uVar9);
      goto LAB_0050fc6c;
    }
    if (ac_passthrough_debug_switch != '\0') {
      uVar6 = json_object_to_json_string_ext(iVar2,0);
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d ap_mac_obj:%s \n","_ac_passthrough_jcs_get",0x7f4,uVar6)
      ;
    }
    pcVar4 = (char *)json_object_to_json_string_ext(iVar2,0);
    sVar5 = strlen(pcVar4);
    pcVar4 = (char *)FUN_00408450(sVar5 + 1,0x7f6);
    if (pcVar4 == (char *)0x0) {
      return;
    }
    __n = sVar5 - 1;
    if ((int)sVar5 < 2) {
      __n = 0;
    }
    memset(pcVar4,0,sVar5 + 1);
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 6) {
      pcVar7 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_ac_passthrough_jcs_get",0x7fb);
      }
      pcVar7 = "";
    }
    strncpy(pcVar4,pcVar7,__n);
    pcVar4[__n] = '\0';
    iVar2 = FUN_0050c8a0(pcVar4);
    if (iVar2 < 1) {
      __s = (void *)0x0;
      if (ac_passthrough_err_switch != '\0') {
        printf("[AC_PASSTHROUGH_ERROR]%s()/%d _uac_nms_report_util_str_split() fail, str: %s!\n",
               "_ac_passthrough_jcs_get",0x7ff,pcVar4);
        goto LAB_0050fb58;
      }
    }
    else {
      __s = (void *)FUN_00408450(iVar2 * 6,0x803);
      if (__s != (void *)0x0) {
        memset(__s,0,iVar2 * 6);
        iVar3 = 0;
        pcVar7 = pcVar4;
        pvVar8 = __s;
        do {
          if (ac_passthrough_debug_switch != '\0') {
            printf("[AC_PASSTHROUGH_DEBUG]%s()/%d tmp_macs:%s \n","_ac_passthrough_jcs_get",0x80c,
                   pcVar7);
          }
          ac_passthrough_str2mac(pcVar7,pvVar8);
          iVar3 = iVar3 + 1;
          pvVar8 = (void *)((int)pvVar8 + 6);
          pcVar7 = pcVar4 + iVar3 * 0x12;
        } while (iVar3 != iVar2);
        goto LAB_0050fc28;
      }
LAB_0050fb58:
      __s = (void *)0x0;
    }
  }
  FUN_00407df0(pcVar4);
LAB_0050fb64:
  if (__s != (void *)0x0) {
    FUN_00407df0(__s);
  }
  return;
}

