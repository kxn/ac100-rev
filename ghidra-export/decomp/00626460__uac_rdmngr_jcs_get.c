// func _uac_rdmngr_jcs_get @ 00626460 size=2964

void _uac_rdmngr_jcs_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  FILE *__s;
  char *pcVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined2 uVar10;
  int iVar9;
  int iVar11;
  undefined4 *puVar12;
  undefined2 *puVar13;
  undefined **ppuVar14;
  undefined *puVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int *piVar19;
  undefined8 uVar20;
  int local_d78 [4];
  undefined4 local_d68;
  undefined4 local_d64;
  int local_d60;
  char *local_d5c;
  undefined *local_d58;
  int local_d54;
  int local_d50;
  undefined1 auStack_d4c [84];
  char local_cf8 [256];
  undefined1 local_bf8;
  char local_bf4 [256];
  undefined1 local_af4;
  undefined1 auStack_af0 [728];
  int local_818;
  undefined2 local_814 [1010];
  int local_30;
  
  memset(&local_818,0,0x7ec);
  memset(local_bf4,0,0x101);
  memset(local_cf8,0,0x101);
  memset(local_d78 + 2,0,0x24);
  memset(auStack_af0,0,0x2d8);
  memset(auStack_d4c,0,0x54);
  local_d78[0] = 0;
  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_jcs_get() begin.\n","_uac_rdmngr_jcs_get",0x3cd);
  }
  apmngr_db_group_id_parse(param_1,&local_818);
  iVar1 = json_object_object_get(param_1,"ap_status");
  if ((iVar1 != 0) &&
     ((iVar2 = json_object_get_type(iVar1), iVar2 == 5 ||
      ((iVar2 = json_object_get_type(iVar1), iVar2 == 4 &&
       (iVar2 = json_object_object_length(iVar1), iVar2 == 0)))))) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 5) {
      piVar19 = local_d78;
      for (iVar2 = 0; iVar11 = json_object_array_length(iVar1), iVar2 < iVar11; iVar2 = iVar2 + 1) {
        if (iVar2 == 2) goto LAB_00626c5c;
        iVar11 = json_object_array_get_idx(iVar1,iVar2);
        if (iVar11 == 0) {
LAB_006269b8:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "_uac_rdmngr_jcs_get",0x3d4);
          }
          *piVar19 = -1;
        }
        else {
          iVar6 = json_object_get_type(iVar11);
          if (iVar6 != 6) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                     "_uac_rdmngr_jcs_get",0x3d4);
            }
            goto LAB_006269b8;
          }
          pcVar4 = (char *)json_object_get_string(iVar11);
          iVar11 = atoi(pcVar4);
          *piVar19 = iVar11;
        }
        piVar19 = piVar19 + 1;
      }
      if (iVar2 != 0) {
LAB_00626c5c:
        local_d50 = local_d78[0];
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (((iVar2 != 4) || (iVar1 = json_object_object_length(iVar1), iVar1 != 0)) &&
         (jcs_err_switch != 0)) {
        printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n"
               ,"_uac_rdmngr_jcs_get",0x3d4);
      }
    }
  }
  uVar18 = 0;
  iVar1 = json_object_object_get(param_1,"start");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar18 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar20 = json_object_get_double(iVar1);
        uVar18 = __fixdfsi((int)((ulonglong)uVar20 >> 0x20),(int)uVar20);
      }
      else {
        uVar18 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_get",0x3da);
        }
      }
    }
  }
  uVar17 = 10;
  iVar1 = json_object_object_get(param_1,"size");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar17 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar20 = json_object_get_double(iVar1);
        uVar17 = __fixdfsi((int)((ulonglong)uVar20 >> 0x20),(int)uVar20);
      }
      else {
        uVar17 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_get",0x3dd);
        }
      }
    }
  }
  uVar3 = apmngr_db_role_bitmap_get(param_1);
  iVar1 = json_object_object_get(param_1,"search_name");
  puVar15 = (undefined *)0x0;
  if ((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 6)) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_rdmngr_jcs_get",0x3e4);
      }
      pcVar4 = "";
    }
    strncpy(local_bf4,pcVar4,0x100);
    local_af4 = 0;
    puVar15 = (undefined *)0x0;
    iVar1 = strcmp(local_bf4,"rf_id");
    if (iVar1 != 0) {
      ppuVar14 = &l_rdmmgr_search_items;
      iVar1 = 0;
      pcVar4 = l_rdmmgr_search_items;
      while( true ) {
        ppuVar14 = ppuVar14 + 2;
        iVar2 = strcmp(local_bf4,pcVar4);
        if (iVar2 == 0) break;
        iVar1 = iVar1 + 1;
        if (iVar1 == 8) {
          puVar15 = (undefined *)0x0;
          goto LAB_00626aa4;
        }
        pcVar4 = *ppuVar14;
      }
      puVar15 = (&PTR__uac_rdmngr_ap_name_cmp_00758b34)[iVar1 * 2];
LAB_00626aa4:
      iVar1 = json_object_object_get(param_1,"search_value");
      if ((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 6)) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          pcVar4 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_rdmngr_jcs_get",0x3ec);
          }
          pcVar4 = "";
        }
        strncpy(local_cf8,pcVar4,0x100);
        local_bf8 = 0;
      }
    }
  }
  iVar1 = json_object_new_array();
  if (iVar1 == 0) {
    if (rdmngr_err_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[RDMNGR_ERROR]%s()/%d JSON_ARRAY_CREATE() fail!\n","_uac_rdmngr_jcs_get",0x3f5);
    return;
  }
  local_d68 = 0;
  local_d64 = 0;
  local_d60 = 0;
  local_d78[2] = uVar18;
  local_d78[3] = uVar17;
  local_d54 = iVar1;
  if (local_bf4[0] == '\0') {
LAB_00626670:
    if (local_818 == 0) {
      puVar13 = local_814;
      for (iVar11 = 0; iVar2 = local_d60, iVar11 < local_30; iVar11 = iVar11 + 1) {
        uVar10 = *puVar13;
        puVar13 = puVar13 + 1;
        apmngr_db_foreach_proc_by_group(uVar10,uVar3,_uac_rdmngr_foreach_proc,local_d78 + 2);
      }
    }
    else {
      iVar11 = apmngr_db_foreach_proc(uVar3,_uac_rdmngr_foreach_proc,local_d78 + 2);
      iVar2 = local_d60;
      if (iVar11 == 1) {
        if (rdmngr_warning_switch == 0) {
          return;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return;
        }
        printf("[RDMNGR_WARNING]%s()/%d apmngr_db_foreach_proc() fail, ret=%d!\n",
               "_uac_rdmngr_jcs_get",0x426,1);
        return;
      }
    }
LAB_006266b8:
    __s = fopen("/tmp/rdmngr_rd_get","w+");
    if (__s == (FILE *)0x0) {
      if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d open get file[%s] fail!\n","_uac_rdmngr_jcs_get",0x438,
               "/tmp/rdmngr_rd_get");
      }
      goto LAB_00626718;
    }
    pcVar4 = (char *)json_object_to_json_string_ext(iVar1,0);
    if (pcVar4 == (char *)0x0) {
      if ((rdmngr_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00626718;
      pcVar4 = "[RDMNGR_ERROR]%s()/%d JSON_STRING_FROM_OBJ fail!\n";
      uVar18 = 0x43f;
    }
    else {
      sVar5 = strlen(pcVar4);
      sVar5 = fwrite(pcVar4,sVar5,1,__s);
      if (sVar5 == 1) {
        uVar18 = json_object_new_string("/tmp/rdmngr_rd_get");
        json_object_object_add(param_2,"file_name",uVar18);
        uVar18 = json_object_new_int(iVar2);
        json_object_object_add(param_2,"total_num",uVar18);
        if ((rdmngr_debug_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_00626718;
        pcVar4 = "[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_jcs_get() success.\n";
        uVar18 = 0x44c;
      }
      else {
        if ((rdmngr_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_00626718;
        pcVar4 = "[RDMNGR_ERROR]%s()/%d write result to file fail!\n";
        uVar18 = 0x446;
      }
    }
  }
  else {
    iVar2 = strcmp(local_bf4,"rf_id");
    if (iVar2 != 0) {
      if ((local_cf8[0] != '\0') && (puVar15 != (undefined *)0x0)) {
        if (rdmngr_debug_switch != 0) {
          iVar2 = is_target_debug_ap();
          if (iVar2 != 0) {
            printf("[RDMNGR_DEBUG]%s()/%d search: name:%s, value:%s!\n","_uac_rdmngr_jcs_get",0x41d,
                   local_bf4,local_cf8);
          }
        }
        local_d5c = local_cf8;
        local_d58 = puVar15;
      }
      goto LAB_00626670;
    }
    iVar2 = rdmngr_profile_get_max_rd_per_ap();
    iVar11 = apmngr_db_get_ap_max();
    iVar6 = apmngr_db_get_template_max();
    iVar7 = apmngr_db_get_sensor_max();
    puVar8 = (undefined4 *)FUN_004082a0((iVar11 + iVar6 + iVar7) * iVar2,4,0x401);
    if (puVar8 != (undefined4 *)0x0) {
      uVar16 = 0;
      iVar2 = json_object_object_get(param_1,"search_value");
      if (iVar2 != 0) {
        iVar11 = json_object_get_type(iVar2);
        uVar16 = 0;
        if ((iVar11 == 5) && (iVar11 = json_object_array_length(iVar2), 0 < iVar11)) {
          iVar11 = json_object_get_type(iVar2);
          if (iVar11 == 5) {
            puVar12 = puVar8;
            for (uVar16 = 0; iVar11 = json_object_array_length(iVar2), (int)uVar16 < iVar11;
                uVar16 = uVar16 + 1) {
              iVar11 = rdmngr_profile_get_max_rd_per_ap();
              iVar6 = apmngr_db_get_ap_max();
              iVar7 = apmngr_db_get_template_max();
              iVar9 = apmngr_db_get_sensor_max();
              if ((uint)((iVar6 + iVar7 + iVar9) * iVar11) <= uVar16) break;
              iVar11 = json_object_array_get_idx(iVar2,uVar16);
              if (iVar11 == 0) {
LAB_00626f90:
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_uac_rdmngr_jcs_get",0x40a);
                }
                *puVar12 = 0xffffffff;
              }
              else {
                iVar6 = json_object_get_type(iVar11);
                if (iVar6 == 3) {
                  uVar18 = json_object_get_int(iVar11);
                }
                else {
                  iVar6 = json_object_get_type();
                  if (iVar6 != 2) goto LAB_00626f90;
                  uVar20 = json_object_get_double(iVar11);
                  uVar18 = __fixdfsi((int)((ulonglong)uVar20 >> 0x20),(int)uVar20);
                }
                *puVar12 = uVar18;
              }
              puVar12 = puVar12 + 1;
            }
          }
          else {
            iVar11 = json_object_get_type(iVar2);
            if (((iVar11 != 4) || (iVar2 = json_object_object_length(iVar2), iVar2 != 0)) &&
               (uVar16 = 0, jcs_err_switch != 0)) {
              printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n"
                     ,"_uac_rdmngr_jcs_get",0x40a);
            }
          }
        }
      }
      iVar11 = 0;
      iVar2 = 0;
      puVar12 = puVar8;
      while (iVar11 < (int)uVar16) {
        uVar10 = rdmngr_db_generate_ap_id(*puVar12);
        iVar6 = apmngr_db_entry_get_by_id(uVar10,auStack_af0);
        if ((iVar6 == 0) && (iVar6 = rdmngr_db_rd_entry_get(*puVar12,auStack_d4c), iVar6 == 0)) {
          _uac_rdmngr_get_rd_entry(auStack_af0,auStack_d4c,iVar1);
          iVar2 = iVar2 + 1;
          iVar11 = iVar11 + 1;
          puVar12 = puVar12 + 1;
        }
        else if ((rdmngr_warning_switch == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) {
          iVar11 = iVar11 + 1;
          puVar12 = puVar12 + 1;
        }
        else {
          printf("[RDMNGR_WARNING]%s()/%d apmngr_db_entry_get_by_id() failed.\n",
                 "_uac_rdmngr_jcs_get",0x411);
          iVar11 = iVar11 + 1;
          puVar12 = puVar12 + 1;
        }
      }
      FUN_00407df0(puVar8);
      goto LAB_006266b8;
    }
    __s = (FILE *)0x0;
    if ((rdmngr_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00626718;
    pcVar4 = "[RDMNGR_ERROR]%s()/%d no memory!\n";
    uVar18 = 0x404;
  }
  printf(pcVar4,"_uac_rdmngr_jcs_get",uVar18);
LAB_00626718:
  json_object_put(iVar1);
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  return;
}

