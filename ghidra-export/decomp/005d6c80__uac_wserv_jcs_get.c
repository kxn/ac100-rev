// func _uac_wserv_jcs_get @ 005d6c80 size=2628

void _uac_wserv_jcs_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined2 uVar7;
  int iVar5;
  FILE *__s;
  size_t sVar6;
  undefined4 uVar8;
  undefined **ppuVar9;
  undefined2 *puVar10;
  code *pcVar11;
  int *piVar12;
  char *pcVar13;
  int iVar14;
  int iVar15;
  undefined8 uVar16;
  char *local_1d10;
  int local_1d0c;
  int local_1d08;
  int local_1d04;
  int local_1d00;
  int local_1cfc;
  char *local_1cf8;
  code *local_1cf4;
  int local_1cf0;
  undefined1 auStack_1cec [84];
  char local_1c98 [256];
  undefined1 local_1b98;
  char local_1b94 [256];
  undefined1 local_1a94;
  undefined1 auStack_1a90 [60];
  int local_1a54;
  int local_17b8;
  undefined2 local_17b4 [1010];
  int local_fd0;
  int local_fcc [1001];
  
  memset(&local_17b8,0,0x7ec);
  memset(local_1b94,0,0x101);
  memset(local_1c98,0,0x101);
  memset(&local_1d10,0,0x24);
  memset(local_fcc,0,4000);
  apmngr_db_group_id_parse(param_1,&local_17b8);
  iVar1 = json_object_object_get(param_1,"serv_id");
  if (iVar1 == 0) {
    __s = (FILE *)0x0;
    if (g_wserv_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) goto LAB_005d6ff0;
      pcVar4 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
      uVar8 = 0x8b6;
      pcVar13 = "serv_id";
      goto LAB_005d7200;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      pcVar13 = (char *)json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar16 = json_object_get_double(iVar1);
        pcVar13 = (char *)__fixdfsi((int)((ulonglong)uVar16 >> 0x20),(int)uVar16);
      }
      else {
        pcVar13 = (char *)0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_get",0x8b7);
        }
      }
    }
    iVar2 = 0;
    iVar1 = json_object_object_get(param_1,"offset");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        iVar2 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar16 = json_object_get_double(iVar1);
          iVar2 = __fixdfsi((int)((ulonglong)uVar16 >> 0x20),(int)uVar16);
        }
        else {
          iVar2 = -1;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_wserv_jcs_get",0x8ba);
          }
        }
      }
    }
    iVar15 = 10;
    iVar1 = json_object_object_get(param_1,"limit");
    if (iVar1 != 0) {
      iVar15 = json_object_get_type(iVar1);
      if (iVar15 == 3) {
        iVar15 = json_object_get_int(iVar1);
      }
      else {
        iVar15 = json_object_get_type();
        if (iVar15 == 2) {
          uVar16 = json_object_get_double(iVar1);
          iVar15 = __fixdfsi((int)((ulonglong)uVar16 >> 0x20),(int)uVar16);
        }
        else {
          iVar15 = -1;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_wserv_jcs_get",0x8bd);
          }
        }
      }
    }
    iVar14 = 0;
    iVar1 = json_object_object_get(param_1,"radio_id");
    if (iVar1 != 0) {
      iVar3 = json_object_get_type(iVar1);
      piVar12 = local_fcc;
      if (iVar3 == 5) {
        for (iVar14 = 0; iVar3 = json_object_array_length(iVar1), iVar14 < iVar3;
            iVar14 = iVar14 + 1) {
          if (iVar14 == 1000) {
            iVar14 = 1000;
            break;
          }
          iVar3 = json_object_array_get_idx(iVar1,iVar14);
          if (iVar3 == 0) {
LAB_005d7280:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                     "_uac_wserv_jcs_get",0x8c0);
            }
            *piVar12 = -1;
          }
          else {
            iVar5 = json_object_get_type(iVar3);
            if (iVar5 != 6) {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                       "_uac_wserv_jcs_get",0x8c0);
              }
              goto LAB_005d7280;
            }
            pcVar4 = (char *)json_object_get_string(iVar3);
            iVar3 = atoi(pcVar4);
            *piVar12 = iVar3;
          }
          piVar12 = piVar12 + 1;
        }
      }
      else {
        iVar3 = json_object_get_type(iVar1);
        if (((iVar3 != 4) || (iVar1 = json_object_object_length(iVar1), iVar1 != 0)) &&
           (iVar14 = 0, jcs_err_switch != 0)) {
          printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n"
                 ,"_uac_wserv_jcs_get",0x8c0);
        }
      }
    }
    pcVar11 = (code *)0x0;
    iVar1 = json_object_object_get(param_1,"search_name");
    if ((iVar1 != 0) && (iVar3 = json_object_get_type(iVar1), iVar3 == 6)) {
      iVar3 = json_object_get_type(iVar1);
      if (iVar3 == 6) {
        pcVar4 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_get",0x8c5);
        }
        pcVar4 = "";
      }
      ppuVar9 = &l_wserv_rd_search_items;
      iVar1 = 0;
      strncpy(local_1b94,pcVar4,0x100);
      local_1a94 = 0;
      pcVar4 = l_wserv_rd_search_items;
      while( true ) {
        ppuVar9 = ppuVar9 + 2;
        iVar3 = strcmp(local_1b94,pcVar4);
        if (iVar3 == 0) break;
        iVar1 = iVar1 + 1;
        if (iVar1 == 5) {
          pcVar11 = (code *)0x0;
          goto LAB_005d714c;
        }
        pcVar4 = *ppuVar9;
      }
      pcVar11 = (code *)(&PTR__uac_wserv_rd_ap_name_cmp_0074fe34)[iVar1 * 2];
LAB_005d714c:
      iVar1 = json_object_object_get(param_1,"search_value");
      if ((iVar1 != 0) && (iVar3 = json_object_get_type(iVar1), iVar3 == 6)) {
        iVar3 = json_object_get_type(iVar1);
        if (iVar3 == 6) {
          pcVar4 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_wserv_jcs_get",0x8ca);
          }
          pcVar4 = "";
        }
        strncpy(local_1c98,pcVar4,0x100);
        local_1b98 = 0;
      }
    }
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_get() begin, wserv_id=%d,offset=%d,limit=%d.\r\n"
             ,"_uac_wserv_jcs_get",0x8ce,pcVar13,iVar2,iVar15);
    }
    local_1cf0 = json_object_new_array();
    if (local_1cf0 != 0) {
      if (((int)pcVar13 < 0) ||
         (pcVar4 = (char *)wserv_profile_get_max_wservice(), pcVar4 <= pcVar13)) {
        __s = (FILE *)0x0;
        if (g_wserv_warning == 0) goto LAB_005d6fec;
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) goto LAB_005d6ff0;
        pcVar4 = "<wserv>[warning]%s(): %d  -> wserv_id[%d] is invalid!\r\n";
        uVar8 = 0x8d8;
      }
      else {
        local_1d04 = 0;
        local_1d00 = 0;
        local_1cfc = 0;
        local_1d10 = pcVar13;
        local_1d0c = iVar2;
        local_1d08 = iVar15;
        if (((local_1b94[0] != '\0') && (local_1c98[0] != '\0')) && (pcVar11 != (code *)0x0)) {
          if (g_wserv_debug != 0) {
            iVar1 = is_target_debug_ap();
            if (iVar1 != 0) {
              printf("<wserv>[debug]%s(): %d  -> search: name:%s, value:%s!\r\n",
                     "_uac_wserv_jcs_get",0x8e4,local_1b94,local_1c98);
            }
          }
          local_1cf8 = local_1c98;
          local_1cf4 = pcVar11;
        }
        piVar12 = local_fcc;
        if (iVar14 < 1) {
          if (local_17b8 == 0) {
            puVar10 = local_17b4;
            for (iVar1 = 0; iVar1 < local_fd0; iVar1 = iVar1 + 1) {
              uVar7 = *puVar10;
              puVar10 = puVar10 + 1;
              apmngr_db_foreach_proc_by_group(uVar7,0xf0000,_uac_wserv_foreach_proc,&local_1d10);
            }
          }
          else {
            iVar1 = apmngr_db_foreach_proc(0xf0000,_uac_wserv_foreach_proc,&local_1d10);
            if (iVar1 == 1) {
              __s = (FILE *)0x0;
              if (g_wserv_warning == 0) goto LAB_005d6fec;
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) goto LAB_005d6ff0;
              pcVar4 = "<wserv>[warning]%s(): %d  -> apmngr_db_foreach_proc() fail, ret=%d!\r\n";
              uVar8 = 0x8f7;
              pcVar13 = (char *)0x1;
              goto LAB_005d7200;
            }
          }
        }
        else {
          iVar1 = 0;
          do {
            iVar15 = *piVar12;
            memset(auStack_1a90,0,0x2d8);
            memset(auStack_1cec,0,0x54);
            uVar7 = rdmngr_db_generate_ap_id(iVar15);
            iVar2 = apmngr_db_entry_get_by_id(uVar7,auStack_1a90);
            if ((((iVar2 == 0) && (iVar2 = rdmngr_db_rd_entry_get(iVar15,auStack_1cec), iVar2 == 0))
                && (local_1a54 != 0)) &&
               (((local_1cf8 == (char *)0x0 || (local_1cf4 == (code *)0x0)) ||
                (iVar2 = (*local_1cf4)(local_1d10,iVar15), iVar2 == 0)))) {
              local_1cfc = local_1cfc + 1;
              if (local_1d04 < local_1d0c) {
                local_1d04 = local_1d04 + 1;
              }
              else if (local_1d00 < local_1d08) {
                local_1d00 = local_1d00 + 1;
                _uac_wserv_get_rd_bind_entry(auStack_1a90,iVar15,&local_1d10);
              }
            }
            iVar1 = iVar1 + 1;
            piVar12 = piVar12 + 1;
          } while (iVar1 != iVar14);
        }
        __s = fopen("/tmp/wserv_rd_get","w+");
        if (__s != (FILE *)0x0) {
          pcVar13 = (char *)json_object_to_json_string_ext(local_1cf0,0);
          if (pcVar13 == (char *)0x0) {
            if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_005d6ff0;
            pcVar13 = "<wserv>[error]%s(): %d  -> JSON_STRING_FROM_OBJ fail!\r\n";
            uVar8 = 0x90d;
          }
          else {
            sVar6 = strlen(pcVar13);
            sVar6 = fwrite(pcVar13,sVar6,1,__s);
            if (sVar6 == 1) {
              uVar8 = json_object_new_string("/tmp/wserv_rd_get");
              json_object_object_add(param_2,"file_name",uVar8);
              uVar8 = json_object_new_int(local_1cfc);
              json_object_object_add(param_2,"total_num",uVar8);
              if ((g_wserv_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_005d6ff0;
              pcVar13 = "<wserv>[debug]%s(): %d  -> _uac_wsta_jcs_get() success.\r\n";
              uVar8 = 0x91a;
            }
            else {
              if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_005d6ff0;
              pcVar13 = "<wserv>[error]%s(): %d  -> write result to file fail!\r\n";
              uVar8 = 0x914;
            }
          }
          goto LAB_005d7430;
        }
        if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005d6ff0;
        pcVar4 = "<wserv>[error]%s(): %d  -> open get file[%s] fail!\r\n";
        uVar8 = 0x906;
        pcVar13 = "/tmp/wserv_rd_get";
      }
LAB_005d7200:
      printf(pcVar4,"_uac_wserv_jcs_get",uVar8,pcVar13);
      goto LAB_005d6ff0;
    }
    __s = (FILE *)0x0;
    if (g_wserv_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) goto LAB_005d6ff0;
      pcVar13 = "<wserv>[error]%s(): %d  -> JSON_ARRAY_CREATE() fail!\r\n";
      uVar8 = 0x8d3;
LAB_005d7430:
      printf(pcVar13,"_uac_wserv_jcs_get",uVar8);
      goto LAB_005d6ff0;
    }
  }
LAB_005d6fec:
  __s = (FILE *)0x0;
LAB_005d6ff0:
  if (local_1cf0 != 0) {
    json_object_put();
    local_1cf0 = 0;
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  return;
}

