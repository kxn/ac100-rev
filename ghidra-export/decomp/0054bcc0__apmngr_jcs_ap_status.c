// func _apmngr_jcs_ap_status @ 0054bcc0 size=2624

void _apmngr_jcs_ap_status(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  size_t sVar7;
  FILE *__s;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined2 *puVar11;
  undefined4 *puVar12;
  undefined2 *puVar13;
  int *piVar14;
  undefined8 uVar15;
  int local_1be0 [4];
  int local_1bd0;
  char *local_1bcc;
  char *local_1bc8;
  int local_1bc4;
  undefined4 local_1bc0;
  int local_1bbc;
  char acStack_1bb8 [127];
  undefined1 local_1b39;
  char acStack_1b38 [127];
  undefined1 local_1ab9;
  undefined1 auStack_1ab8 [728];
  int local_17e0;
  undefined2 local_17dc [1010];
  int local_ff8;
  undefined4 local_ff4;
  
  memset(acStack_1b38,0,0x80);
  memset(acStack_1bb8,0,0x80);
  memset(&local_17e0,0,0x7ec);
  memset(&local_ff4,0,0xfc8);
  memset(local_1be0 + 2,0,0x20);
  memset(auStack_1ab8,0,0x2d8);
  local_1be0[0] = 0;
  iVar2 = json_object_object_get(param_1,"start");
  if (iVar2 == 0) {
LAB_0054bd98:
    iVar2 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_apmngr_jcs_ap_status",0x96c);
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      iVar2 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 != 2) goto LAB_0054bd98;
      uVar15 = json_object_get_double(iVar2);
      iVar2 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    }
  }
  iVar3 = json_object_object_get(param_1,"size");
  if (iVar3 == 0) {
LAB_0054bde8:
    iVar3 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_apmngr_jcs_ap_status",0x96f);
    }
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 3) {
      iVar3 = json_object_get_int(iVar3);
    }
    else {
      iVar4 = json_object_get_type();
      if (iVar4 != 2) goto LAB_0054bde8;
      uVar15 = json_object_get_double(iVar3);
      iVar3 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    }
  }
  apmngr_db_group_id_parse(param_1,&local_17e0);
  iVar4 = json_object_object_get(param_1,"ap_status");
  if ((iVar4 != 0) &&
     ((iVar5 = json_object_get_type(iVar4), iVar5 == 5 ||
      ((iVar5 = json_object_get_type(iVar4), iVar5 == 4 &&
       (iVar5 = json_object_object_length(iVar4), iVar5 == 0)))))) {
    iVar5 = json_object_get_type(iVar4);
    if (iVar5 == 5) {
      piVar14 = local_1be0;
      for (iVar5 = 0; iVar8 = json_object_array_length(iVar4), iVar5 < iVar8; iVar5 = iVar5 + 1) {
        if (iVar5 == 2) goto LAB_0054c554;
        iVar8 = json_object_array_get_idx(iVar4,iVar5);
        if (iVar8 == 0) {
LAB_0054c530:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_apmngr_jcs_ap_status",0x978);
          }
          *piVar14 = -1;
        }
        else {
          iVar9 = json_object_get_type(iVar8);
          if (iVar9 != 6) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "_apmngr_jcs_ap_status",0x978);
            }
            goto LAB_0054c530;
          }
          pcVar10 = (char *)json_object_get_string(iVar8);
          iVar8 = atoi(pcVar10);
          *piVar14 = iVar8;
        }
        piVar14 = piVar14 + 1;
      }
      if (iVar5 == 0) goto LAB_0054c31c;
LAB_0054c554:
      local_1bbc = local_1be0[0];
    }
    else {
      iVar5 = json_object_get_type(iVar4);
      if (((iVar5 != 4) || (iVar4 = json_object_object_length(iVar4), iVar4 != 0)) &&
         (jcs_err_switch != 0)) {
        printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n"
               ,"_apmngr_jcs_ap_status",0x978);
      }
LAB_0054c31c:
      iVar5 = 0;
      local_1bbc = 0;
    }
    if ((apmngr_debug_switch != '\0') && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d ap_status_len:%d,%d\n","_apmngr_jcs_ap_status",0x981,iVar5,
             local_1bbc);
    }
  }
  iVar4 = json_object_object_get(param_1,"search_name");
  if (iVar4 != 0) {
    iVar5 = json_object_get_type(iVar4);
    if (iVar5 == 6) {
      pcVar10 = (char *)json_object_get_string(iVar4);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apmngr_jcs_ap_status",0x989);
      }
      pcVar10 = "";
    }
    strncpy(acStack_1b38,pcVar10,0x7f);
    local_1ab9 = 0;
    iVar4 = strcmp(acStack_1b38,"entry_id");
    if (iVar4 != 0) {
      iVar4 = json_object_object_get(param_1,"search_value");
      if (iVar4 == 0) {
        if ((apmngr_err_switch != '\0') && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[APMNGR_ERROR]%s()/%d Invalid jcs search request.\n","_apmngr_jcs_ap_status",0x992
                );
        }
      }
      else {
        iVar5 = json_object_get_type(iVar4);
        if (iVar5 == 6) {
          pcVar10 = (char *)json_object_get_string(iVar4);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_ap_status",0x98e);
          }
          pcVar10 = "";
        }
        strncpy(acStack_1bb8,pcVar10,0x7f);
        local_1b39 = 0;
      }
    }
  }
  uVar6 = apmngr_db_role_bitmap_get(param_1);
  local_1be0[2] = iVar2;
  local_1be0[3] = iVar3;
  local_1bc4 = json_object_new_array();
  local_1bd0 = 0;
  iVar2 = strcmp(acStack_1b38,"entry_id");
  if (iVar2 == 0) {
    iVar2 = 0;
    iVar3 = json_object_object_get(param_1,"search_value");
    if (iVar3 != 0) {
      iVar4 = json_object_get_type(iVar3);
      iVar2 = 0;
      if ((iVar4 == 5) && (iVar4 = json_object_array_length(iVar3), 0 < iVar4)) {
        iVar4 = json_object_get_type(iVar3);
        if (iVar4 == 5) {
          puVar12 = &local_ff4;
          for (; iVar4 = json_object_array_length(iVar3), iVar2 < iVar4; iVar2 = iVar2 + 1) {
            if (iVar2 == 0x3f2) {
              iVar2 = 0x3f2;
              break;
            }
            iVar4 = json_object_array_get_idx(iVar3,iVar2);
            if (iVar4 == 0) {
LAB_0054c680:
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_apmngr_jcs_ap_status",0x9a3);
              }
              *puVar12 = 0xffffffff;
            }
            else {
              iVar5 = json_object_get_type(iVar4);
              if (iVar5 == 3) {
                uVar6 = json_object_get_int(iVar4);
                *puVar12 = uVar6;
              }
              else {
                iVar5 = json_object_get_type();
                if (iVar5 != 2) goto LAB_0054c680;
                uVar15 = json_object_get_double(iVar4);
                uVar6 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                *puVar12 = uVar6;
              }
            }
            puVar12 = puVar12 + 1;
          }
        }
        else {
          iVar4 = json_object_get_type(iVar3);
          if (((iVar4 != 4) || (iVar3 = json_object_object_length(iVar3), iVar3 != 0)) &&
             (iVar2 = 0, jcs_err_switch != 0)) {
            printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n"
                   ,"_apmngr_jcs_ap_status",0x9a3);
          }
        }
      }
    }
    puVar12 = &local_ff4;
    iVar3 = 0;
    local_1bc0 = 0xffffffff;
LAB_0054bf40:
    do {
      if (iVar2 <= iVar3) goto LAB_0054c048;
      iVar4 = apmngr_db_entry_get_by_id(*(undefined2 *)((int)puVar12 + 2),auStack_1ab8);
      if (iVar4 == 0) {
        _apmngr_db_status_get(auStack_1ab8,local_1be0 + 2);
      }
      else {
        if ((apmngr_warning_switch == '\0') || (iVar4 = is_target_debug_ap(), iVar4 == 0)) {
          iVar3 = iVar3 + 1;
          puVar12 = puVar12 + 1;
          goto LAB_0054bf40;
        }
        printf("[APMNGR_WARNING]%s()/%d apmngr_db_entry_get_by_id() failed.\n",
               "_apmngr_jcs_ap_status",0x9aa);
      }
      iVar3 = iVar3 + 1;
      puVar12 = puVar12 + 1;
    } while( true );
  }
  local_1bc8 = acStack_1bb8;
  local_1bcc = acStack_1b38;
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d Get AP status from %d to %d.\n","_apmngr_jcs_status_list_get",
           0x8b0,local_1be0[2],local_1be0[2] + local_1be0[3]);
  }
  if (local_17e0 == 0) {
    puVar13 = local_17dc;
    local_1bc0 = 1;
    puVar11 = puVar13;
    for (iVar2 = 0; iVar2 < local_ff8; iVar2 = iVar2 + 1) {
      uVar1 = *puVar11;
      puVar11 = puVar11 + 1;
      apmngr_db_foreach_proc_by_group(uVar1,uVar6,_apmngr_db_status_get,local_1be0 + 2);
    }
    local_1bc0 = 0;
    for (iVar2 = 0; iVar2 < local_ff8; iVar2 = iVar2 + 1) {
      uVar1 = *puVar13;
      puVar13 = puVar13 + 1;
      apmngr_db_foreach_proc_by_group(uVar1,uVar6,_apmngr_db_status_get,local_1be0 + 2);
    }
  }
  else {
    local_1bc0 = 1;
    apmngr_db_foreach_proc(uVar6,_apmngr_db_status_get,local_1be0 + 2);
    local_1bc0 = 0;
    apmngr_db_foreach_proc(uVar6,_apmngr_db_status_get,local_1be0 + 2);
  }
LAB_0054c048:
  pcVar10 = (char *)json_object_to_json_string_ext(local_1bc4,0);
  if (pcVar10 == (char *)0x0) {
    if ((apmngr_err_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
      local_1bd0 = 0;
      __s = (FILE *)0x0;
    }
    else {
      __s = (FILE *)0x0;
      printf("[APMNGR_ERROR]%s()/%d translate ap-status json to string failed.\n",
             "_apmngr_jcs_ap_status",0x9ba);
      local_1bd0 = 0;
    }
    goto LAB_0054c0b0;
  }
  sVar7 = strlen(pcVar10);
  __s = fopen("/tmp/ap_status","w+");
  if (__s == (FILE *)0x0) {
    if (apmngr_err_switch == '\0') {
      local_1bd0 = 0;
      goto LAB_0054c0b0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      local_1bd0 = 0;
      goto LAB_0054c0b0;
    }
    pcVar10 = "[APMNGR_ERROR]%s()/%d open ap-status file failed.\n";
    uVar6 = 0x9c3;
  }
  else {
    sVar7 = fwrite(pcVar10,sVar7,1,__s);
    if (sVar7 == 1) goto LAB_0054c0b0;
    if (apmngr_err_switch == '\0') {
      local_1bd0 = 0;
      goto LAB_0054c0b0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      local_1bd0 = 0;
      goto LAB_0054c0b0;
    }
    pcVar10 = "[APMNGR_ERROR]%s()/%d write ap status to file failed.\n";
    uVar6 = 0x9ca;
  }
  printf(pcVar10,"_apmngr_jcs_ap_status",uVar6);
  local_1bd0 = 0;
LAB_0054c0b0:
  if (0 < local_1bd0) {
    uVar6 = json_object_new_string("/tmp/ap_status");
    json_object_object_add(param_2,"file_name",uVar6);
    uVar6 = json_object_new_int(local_1bd0);
    json_object_object_add(param_2,"total_num",uVar6);
  }
  if (local_1bc4 != 0) {
    json_object_put();
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  return;
}

