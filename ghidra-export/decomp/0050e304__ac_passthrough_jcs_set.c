// func _ac_passthrough_jcs_set @ 0050e304 size=2428

void _ac_passthrough_jcs_set(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  size_t sVar7;
  void *pvVar8;
  FILE *__stream;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  size_t __n;
  void *pvVar13;
  undefined8 uVar14;
  undefined4 local_b8;
  char local_b4 [127];
  undefined1 local_35;
  int local_30;
  
  local_b8 = 0xffffffff;
  memset(local_b4,0,0x80);
  if (ac_passthrough_debug_switch != '\0') {
    uVar6 = json_object_to_json_string_ext(param_1,0);
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d _ac_passthrough_jcs_set: %s\n","_ac_passthrough_jcs_set",
           0x74a,uVar6);
  }
  iVar1 = json_object_object_get(param_1,"request_info");
  if (iVar1 == 0) {
    iVar12 = json_object_object_get(param_1,"filepath");
    if (iVar12 == 0) {
      return;
    }
    memset(local_b4,0,0x80);
    iVar10 = json_object_get_type(iVar12);
    if (iVar10 == 6) {
      pcVar5 = (char *)json_object_get_string(iVar12);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_ac_passthrough_jcs_set",0x752);
      }
      pcVar5 = "";
    }
    strncpy(local_b4,pcVar5,0x7f);
    local_35 = 0;
    if (ac_passthrough_debug_switch != '\0') {
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d file_name: %s\n","_ac_passthrough_jcs_set",0x754,
             local_b4);
    }
    iVar12 = 0;
    if (local_b4[0] == '\0') goto LAB_0050e40c;
    __stream = fopen(local_b4,"r");
    if (__stream == (FILE *)0x0) {
      if (ac_passthrough_err_switch == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        printf("[AC_PASSTHROUGH_ERROR]%s()/%d open request_info_file[%s] fail!\n",
               "_ac_passthrough_jcs_set_get_request_info_by_file",0x6dc,local_b4);
      }
      goto LAB_0050e40c;
    }
    fseek(__stream,0,2);
    sVar7 = ftell(__stream);
    if ((int)sVar7 < 0x80000) {
      rewind(__stream);
      pvVar8 = (void *)FUN_00408450(sVar7 + 1,0x6e6);
      if (pvVar8 == (void *)0x0) {
        iVar10 = -1;
        if (ac_passthrough_err_switch != '\0') {
          printf("[AC_PASSTHROUGH_ERROR]%s()/%d malloc fail!\n",
                 "_ac_passthrough_jcs_set_get_request_info_by_file",0x6e8);
          iVar12 = 0;
        }
      }
      else {
        memset(pvVar8,0,sVar7 + 1);
        sVar7 = fread(pvVar8,sVar7,1,__stream);
        if (sVar7 == 1) {
          if (ac_passthrough_debug_switch != '\0') {
            printf("[AC_PASSTHROUGH_DEBUG]%s()/%d request info:%s!\n",
                   "_ac_passthrough_jcs_set_get_request_info_by_file",0x6f2,pvVar8);
          }
          iVar10 = json_tokener_new();
          if (iVar10 == 0) {
            if (ac_passthrough_err_switch != '\0') {
              printf("[AC_PASSTHROUGH_ERROR]%s()/%d Create tokener failed.\n\n","jsonParseStr",0x6bc
                    );
            }
          }
          else {
            iVar12 = json_tokener_parse_ex(iVar10,pvVar8,0xffffffff);
            if (*(int *)(iVar10 + 0x1c) == 0) {
              json_tokener_free(iVar10);
              iVar10 = 0;
              if (iVar12 != 0) goto LAB_0050e8bc;
            }
            else {
              if (ac_passthrough_err_switch != '\0') {
                printf("[AC_PASSTHROUGH_ERROR]%s()/%d Parse buf failed,%s.\n\n","jsonParseStr",0x6c3
                       ,pvVar8);
              }
              json_tokener_free(iVar10);
            }
          }
          if (ac_passthrough_err_switch == '\0') {
            iVar12 = 0;
            iVar10 = -1;
          }
          else {
            iVar12 = 0;
            printf("[AC_PASSTHROUGH_ERROR]%s()/%d request info formate error not json!\n",
                   "_ac_passthrough_jcs_set_get_request_info_by_file",0x6f5);
            iVar10 = -1;
          }
        }
        else {
          iVar10 = -1;
          if (ac_passthrough_err_switch != '\0') {
            printf("[AC_PASSTHROUGH_ERROR]%s()/%d read file fail!\n",
                   "_ac_passthrough_jcs_set_get_request_info_by_file",0x6ef);
          }
        }
      }
    }
    else {
      if (ac_passthrough_err_switch != '\0') {
        printf("[AC_PASSTHROUGH_ERROR]%s()/%d too long request info %d !\n",
               "_ac_passthrough_jcs_set_get_request_info_by_file",0x6e2,sVar7);
      }
      iVar10 = -1;
      pvVar8 = (void *)0x0;
    }
LAB_0050e8bc:
    fclose(__stream);
    if (pvVar8 != (void *)0x0) {
      FUN_00407df0(pvVar8);
    }
    if (((((iVar10 != 0) || (iVar12 == 0)) ||
         (iVar10 = json_object_object_get(iVar12,"params"), iVar10 == 0)) ||
        ((iVar10 = json_object_object_get(iVar10,"requestData"), iVar10 == 0 ||
         (iVar10 = json_object_object_get(iVar10,"apmng_passthrough"), iVar10 == 0)))) ||
       ((iVar10 = json_object_object_get(iVar10,"passthrough_to_subdevice"), iVar10 == 0 ||
        (iVar10 = json_object_object_get(iVar10,"request_info"), iVar10 == 0)))) goto LAB_0050e40c;
  }
  else {
    iVar12 = 0;
    iVar10 = 0;
  }
  iVar2 = json_object_object_get(param_1,"ap_mac");
  iVar3 = json_object_object_get(param_1,"request_id");
  iVar4 = json_object_object_get(param_1,"need_result");
  if (ac_passthrough_debug_switch != '\0') {
    uVar6 = json_object_to_json_string_ext(iVar2,0);
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d mac: %s\n","_ac_passthrough_jcs_set",0x765,uVar6);
  }
  if (ac_passthrough_debug_switch != '\0') {
    uVar6 = json_object_to_json_string_ext(iVar3,0);
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d requeset_id_obj: %s\n","_ac_passthrough_jcs_set",0x766,
           uVar6);
  }
  if (ac_passthrough_debug_switch != '\0') {
    uVar6 = json_object_to_json_string_ext(iVar4,0);
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d need_result_obj: %s\n","_ac_passthrough_jcs_set",0x767,
           uVar6);
  }
  if (iVar10 != 0) {
    iVar1 = iVar10;
  }
  pcVar5 = (char *)json_object_to_json_string_ext(iVar1,0);
  if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) goto LAB_0050e40c;
  if (ac_passthrough_debug_switch == '\0') {
    if (iVar2 == 0) goto LAB_0050e780;
LAB_0050e484:
    pcVar11 = (char *)json_object_to_json_string_ext(iVar2,0);
    sVar7 = strlen(pcVar11);
    pcVar11 = (char *)FUN_00408450(sVar7 + 1,0x77a);
    if (pcVar11 == (char *)0x0) goto LAB_0050e40c;
    __n = sVar7 - 1;
    if ((int)sVar7 < 2) {
      __n = 0;
    }
    memset(pcVar11,0,sVar7 + 1);
    iVar1 = json_object_get_type(iVar2);
    if (iVar1 == 6) {
      pcVar9 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_ac_passthrough_jcs_set",0x77f);
      }
      pcVar9 = "";
    }
    strncpy(pcVar11,pcVar9,__n);
    pcVar11[__n] = '\0';
    iVar1 = FUN_0050c8a0(pcVar11);
    if (0 < iVar1) {
      pvVar8 = (void *)FUN_00408450(iVar1 * 6,0x787);
      if (pvVar8 == (void *)0x0) goto LAB_0050e7b8;
      memset(pvVar8,0,iVar1 * 6);
      local_30 = 0;
      pcVar9 = pcVar11;
      pvVar13 = pvVar8;
      do {
        ac_passthrough_str2mac(pcVar9,pvVar13);
        pcVar9 = pcVar9 + 0x12;
        pvVar13 = (void *)((int)pvVar13 + 6);
        local_30 = local_30 + 1;
      } while (local_30 != iVar1);
      goto LAB_0050e578;
    }
    pvVar8 = (void *)0x0;
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d _uac_nms_report_util_str_split() fail, str: %s!\n",
             "_ac_passthrough_jcs_set",0x783,pcVar11);
LAB_0050e7b8:
      pvVar8 = (void *)0x0;
    }
LAB_0050e7bc:
    FUN_00407df0(pcVar11);
  }
  else {
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d _ac_passthrough_jcs_set: %s\n","_ac_passthrough_jcs_set",
           0x776,pcVar5);
    if (iVar2 != 0) goto LAB_0050e484;
LAB_0050e780:
    pvVar8 = (void *)0x0;
    iVar1 = 0;
    pcVar11 = (char *)0x0;
LAB_0050e578:
    if (iVar3 != 0) {
      iVar10 = json_object_get_type(iVar3);
      if (iVar10 == 3) {
        local_b8 = json_object_get_int(iVar3);
      }
      else {
        iVar10 = json_object_get_type();
        if (iVar10 == 2) {
          uVar14 = json_object_get_double(iVar3);
          local_b8 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_ac_passthrough_jcs_set",0x796);
          }
          local_b8 = 0xffffffff;
        }
      }
    }
    uVar6 = 0;
    if (iVar4 != 0) {
      iVar10 = json_object_get_type(iVar4);
      if (iVar10 == 3) {
        uVar6 = json_object_get_int(iVar4);
      }
      else {
        iVar10 = json_object_get_type();
        if (iVar10 == 2) {
          uVar14 = json_object_get_double(iVar4);
          uVar6 = __fixdfsi((int)((ulonglong)uVar14 >> 0x20),(int)uVar14);
        }
        else {
          uVar6 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_ac_passthrough_jcs_set",0x79b);
          }
        }
      }
    }
    iVar1 = send_tdcp_request_to_ap(uVar6,pvVar8,iVar1,pcVar5,&local_b8,0x15f0000,0);
    if (iVar1 == 0) {
      if (pcVar11 != (char *)0x0) {
        FUN_00407df0(pcVar11);
      }
      if (pvVar8 != (void *)0x0) {
        FUN_00407df0(pvVar8);
      }
      if (iVar12 != 0) {
        json_object_put(iVar12);
      }
      if (param_2 == 0) {
        return;
      }
      uVar6 = json_object_new_int(1);
      json_object_object_add(param_2,&DAT_00676a24,uVar6);
      uVar6 = json_object_new_int(local_b8);
      json_object_object_add(param_2,"request_id",uVar6);
      return;
    }
    if (pcVar11 != (char *)0x0) goto LAB_0050e7bc;
  }
  if (pvVar8 != (void *)0x0) {
    FUN_00407df0(pvVar8);
  }
LAB_0050e40c:
  if (param_2 != 0) {
    uVar6 = json_object_new_int(0);
    json_object_object_add(param_2,&DAT_00676a24,uVar6);
  }
  if (iVar12 != 0) {
    json_object_put(iVar12);
  }
  return;
}

