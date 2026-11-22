// func _uac_wsta_jcs_get @ 006316d0 size=1688

void _uac_wsta_jcs_get(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  FILE *__s;
  char *pcVar5;
  size_t sVar6;
  char *pcVar7;
  undefined2 *puVar8;
  undefined **ppuVar9;
  undefined *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  undefined4 local_a40;
  undefined4 local_a3c;
  undefined4 local_a38;
  undefined4 local_a34;
  undefined4 local_a30;
  undefined *local_a2c;
  char *local_a28;
  int local_a24;
  char local_a20 [256];
  undefined1 local_920;
  char local_91c [256];
  undefined1 local_81c;
  int local_818;
  undefined2 local_814 [1010];
  int local_30;
  
  memset(&local_818,0,0x7ec);
  memset(local_91c,0,0x101);
  memset(local_a20,0,0x101);
  memset(&local_a40,0,0x20);
  if ((g_wsta_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_jcs_get() begin.\r\n","_uac_wsta_jcs_get",0x3ef);
  }
  uVar12 = 0;
  iVar2 = json_object_object_get(param_1,"start");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar12 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar13 = json_object_get_double(iVar2);
        uVar12 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
      }
      else {
        uVar12 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wsta_jcs_get",0x3f2);
        }
      }
    }
  }
  uVar11 = 10;
  iVar2 = json_object_object_get(param_1,"size");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar11 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar13 = json_object_get_double(iVar2);
        uVar11 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
      }
      else {
        uVar11 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wsta_jcs_get",0x3f5);
        }
      }
    }
  }
  apmngr_db_group_id_parse(param_1,&local_818);
  uVar4 = apmngr_db_role_bitmap_get(param_1);
  iVar2 = json_object_object_get(param_1,"search_name");
  puVar10 = (undefined *)0x0;
  if ((iVar2 != 0) && (iVar3 = json_object_get_type(iVar2), iVar3 == 6)) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 6) {
      pcVar5 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_wsta_jcs_get",0x3fe);
      }
      pcVar5 = "";
    }
    ppuVar9 = &l_wsta_search_items;
    iVar2 = 0;
    strncpy(local_91c,pcVar5,0x100);
    local_81c = 0;
    pcVar5 = l_wsta_search_items;
    while( true ) {
      ppuVar9 = ppuVar9 + 2;
      iVar3 = strcmp(local_91c,pcVar5);
      if (iVar3 == 0) break;
      iVar2 = iVar2 + 1;
      if (iVar2 == 7) {
        puVar10 = (undefined *)0x0;
        goto LAB_00631b78;
      }
      pcVar5 = *ppuVar9;
    }
    puVar10 = (&PTR__uac_wsta_mac_cmp_00758bb4)[iVar2 * 2];
LAB_00631b78:
    iVar2 = json_object_object_get(param_1,"search_value");
    if ((iVar2 != 0) && (iVar3 = json_object_get_type(iVar2), iVar3 == 6)) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 6) {
        pcVar5 = (char *)json_object_get_string(iVar2);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_wsta_jcs_get",0x403);
        }
        pcVar5 = "";
      }
      strncpy(local_a20,pcVar5,0x100);
      local_920 = 0;
    }
  }
  iVar2 = json_object_new_array();
  if (iVar2 == 0) {
    if (g_wsta_error == 0) {
      return;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return;
    }
    printf("<wsta>[error]%s(): %d  -> JSON_ARRAY_CREATE() fail!\r\n","_uac_wsta_jcs_get",0x40a);
    return;
  }
  local_a38 = 0;
  local_a34 = 0;
  local_a30 = 0;
  if (((local_91c[0] != '\0') && (local_a20[0] != '\0')) && (puVar10 != (undefined *)0x0)) {
    local_a2c = puVar10;
    local_a28 = local_a20;
  }
  local_a40 = uVar12;
  local_a3c = uVar11;
  local_a24 = iVar2;
  if (local_818 == 0) {
    puVar8 = local_814;
    for (iVar3 = 0; iVar3 < local_30; iVar3 = iVar3 + 1) {
      uVar1 = *puVar8;
      puVar8 = puVar8 + 1;
      apmngr_db_foreach_proc_by_group(uVar1,uVar4,_uac_wta_get_entry_for_each_cb,&local_a40);
    }
LAB_006318c0:
    uVar12 = local_a30;
    __s = fopen("/tmp/wsta_get","w+");
    if (__s != (FILE *)0x0) {
      pcVar5 = (char *)json_object_to_json_string_ext(iVar2,0);
      if (pcVar5 == (char *)0x0) {
        if ((g_wsta_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00631924;
        pcVar5 = "<wsta>[error]%s(): %d  -> JSON_STRING_FROM_OBJ fail!\r\n";
        uVar12 = 0x437;
      }
      else {
        sVar6 = strlen(pcVar5);
        sVar6 = fwrite(pcVar5,sVar6,1,__s);
        if (sVar6 == 1) {
          uVar11 = json_object_new_string("/tmp/wsta_get");
          json_object_object_add(param_2,"file_name",uVar11);
          uVar12 = json_object_new_int(uVar12);
          json_object_object_add(param_2,"total_num",uVar12);
          uVar12 = wsta_db_get_total_num();
          uVar12 = json_object_new_int(uVar12);
          json_object_object_add(param_2,"all_num",uVar12);
          if ((g_wsta_debug == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00631924;
          pcVar5 = "<wsta>[debug]%s(): %d  -> _uac_wsta_jcs_get() success.\r\n";
          uVar12 = 0x445;
        }
        else {
          if ((g_wsta_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00631924;
          pcVar5 = "<wsta>[error]%s(): %d  -> write result to file fail!\r\n";
          uVar12 = 0x43e;
        }
      }
      printf(pcVar5,"_uac_wsta_jcs_get",uVar12);
      goto LAB_00631924;
    }
    if ((g_wsta_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00631924;
    pcVar5 = "<wsta>[error]%s(): %d  -> open get file[%s] fail!\r\n";
    uVar12 = 0x430;
    pcVar7 = "/tmp/wsta_get";
  }
  else {
    iVar3 = apmngr_db_foreach_proc(uVar4,_uac_wta_get_entry_for_each_cb,&local_a40);
    if (iVar3 != 1) goto LAB_006318c0;
    __s = (FILE *)0x0;
    if ((g_wserv_warning == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00631924;
    pcVar5 = "<wserv>[warning]%s(): %d  -> apmngr_db_foreach_proc() fail, ret=%d!\r\n";
    uVar12 = 0x41f;
    pcVar7 = (char *)0x1;
  }
  printf(pcVar5,"_uac_wsta_jcs_get",uVar12,pcVar7);
LAB_00631924:
  json_object_put(iVar2);
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  return;
}

