// func _uac_dhcpdef_jcs_get_bind_entries @ 00461ee4 size=2084

void _uac_dhcpdef_jcs_get_bind_entries(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  FILE *__s;
  char *pcVar4;
  size_t sVar5;
  undefined2 *puVar6;
  undefined **ppuVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  char *__s_00;
  undefined4 local_a40;
  undefined4 local_a3c;
  undefined4 local_a38;
  undefined4 local_a34;
  undefined4 local_a30;
  char *local_a2c;
  undefined *local_a28;
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
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_jcs_get_bind_entries",0x54e,
           "_uac_dhcpdef_jcs_get_bind_entries");
  }
  apmngr_db_group_id_parse(param_1,&local_818);
  uVar10 = 0;
  iVar2 = json_object_object_get(param_1,"offset");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar10 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar11 = json_object_get_double(iVar2);
        uVar10 = __fixdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
      else {
        uVar10 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_dhcpdef_jcs_get_bind_entries",0x553);
        }
      }
    }
  }
  uVar9 = 10;
  iVar2 = json_object_object_get(param_1,"limit");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar9 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar11 = json_object_get_double(iVar2);
        uVar9 = __fixdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
      else {
        uVar9 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_dhcpdef_jcs_get_bind_entries",0x556);
        }
      }
    }
  }
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> offset=%d, limit=%d.\r\n","dhcp_defend",
           "_uac_dhcpdef_jcs_get_bind_entries",0x558,uVar10,uVar9);
  }
  iVar2 = json_object_object_get(param_1,"search_name");
  if (iVar2 == 0) {
    puVar8 = (undefined *)0x0;
LAB_00462054:
    memset(&local_a40,0,0x20);
    local_a24 = json_object_new_array();
    if (local_a24 == 0) {
      __s = (FILE *)0x0;
      if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00462138;
      pcVar4 = "\x1b[31;49m[%s]<%s():%d> JSON_ARRAY_CREATE() fail!\x1b[0m\r\n";
      uVar10 = 0x577;
    }
    else {
      local_a40 = 0;
      local_a34 = 0;
      local_a30 = 0;
      local_a3c = uVar10;
      local_a38 = uVar9;
      if (((local_91c[0] != '\0') && (local_a20[0] != '\0')) && (puVar8 != (undefined *)0x0)) {
        if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[%s]<%s():%d> search_name: %s, search_value: %s\r\n","dhcp_defend",
                 "_uac_dhcpdef_jcs_get_bind_entries",0x583,local_91c,local_a20);
        }
        local_a2c = local_a20;
        local_a28 = puVar8;
      }
      if (local_818 == 0) {
        puVar6 = local_814;
        for (iVar2 = 0; iVar2 < local_30; iVar2 = iVar2 + 1) {
          uVar1 = *puVar6;
          puVar6 = puVar6 + 1;
          apmngr_db_foreach_proc_by_group(uVar1,0xf0000,_bind_entries_foreach,&local_a40);
        }
      }
      else {
        iVar2 = apmngr_db_foreach_proc(0xf0000,_bind_entries_foreach,&local_a40);
        if (iVar2 == 1) {
          if (g_dhcpdef_error == 0) {
            return;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return;
          }
          printf("\x1b[31;49m[%s]<%s():%d> apmngr_db_foreach_proc() / apmngr_db_foreach_proc fail, ret=%d!\x1b[0m\r\n"
                 ,"dhcp_defend","_uac_dhcpdef_jcs_get_bind_entries",0x58c,1);
          return;
        }
      }
      __s = fopen("/tmp/dhcpdef_apbind","w+");
      if (__s == (FILE *)0x0) {
        if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00462138;
        pcVar4 = "\x1b[31;49m[%s]<%s():%d> open get file[%s] fail!\x1b[0m\r\n";
        __s_00 = "/tmp/dhcpdef_apbind";
        uVar10 = 0x59b;
        goto LAB_004621f8;
      }
      pcVar4 = (char *)json_object_to_json_string_ext(local_a24,0);
      if (pcVar4 == (char *)0x0) {
        if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00462138;
        pcVar4 = "\x1b[31;49m[%s]<%s():%d> JSON_STRING_FROM_OBJ() fail!\x1b[0m\r\n";
        uVar10 = 0x5a2;
      }
      else {
        sVar5 = strlen(pcVar4);
        sVar5 = fwrite(pcVar4,sVar5,1,__s);
        if (sVar5 == 1) {
          uVar10 = json_object_new_string("/tmp/dhcpdef_apbind");
          json_object_object_add(param_2,"file_name",uVar10);
          uVar10 = json_object_new_int(local_a30);
          json_object_object_add(param_2,"total_num",uVar10);
          if ((g_dhcpdef_info == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_00462138;
          __s_00 = "_uac_dhcpdef_jcs_get_bind_entries";
          pcVar4 = "[%s]<%s():%d> %s() success.\r\n";
          uVar10 = 0x5af;
          goto LAB_004621f8;
        }
        if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00462138;
        pcVar4 = "\x1b[31;49m[%s]<%s():%d> write result to file fail!\x1b[0m\r\n";
        uVar10 = 0x5a9;
      }
    }
    printf(pcVar4,"dhcp_defend","_uac_dhcpdef_jcs_get_bind_entries",uVar10);
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    puVar8 = (undefined *)0x0;
    if (iVar3 != 6) goto LAB_00462054;
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_dhcpdef_jcs_get_bind_entries",0x55d);
      }
      pcVar4 = "";
    }
    ppuVar7 = &_bind_search_items;
    iVar2 = 0;
    strncpy(local_91c,pcVar4,0x100);
    local_81c = 0;
    pcVar4 = _bind_search_items;
    while( true ) {
      ppuVar7 = ppuVar7 + 2;
      iVar3 = strcmp(local_91c,pcVar4);
      if (iVar3 == 0) break;
      iVar2 = iVar2 + 1;
      if (iVar2 == 5) {
        __s = (FILE *)0x0;
        if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          __s = (FILE *)0x0;
          printf("\x1b[31;49m[%s]<%s():%d> can NOT find cmp_func for search_name[%s]!\x1b[0m\r\n",
                 "dhcp_defend","_bind_get_cmp_func",0x18c,local_91c);
        }
        goto LAB_00462138;
      }
      pcVar4 = *ppuVar7;
    }
    puVar8 = (&PTR__ap_name_cmp_00731434)[iVar2 * 2];
    __s = (FILE *)0x0;
    if (puVar8 == (undefined *)0x0) goto LAB_00462138;
    iVar2 = json_object_object_get(param_1,"search_value");
    if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) goto LAB_00462054;
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_dhcpdef_jcs_get_bind_entries",0x56a);
      }
      pcVar4 = "";
    }
    __s_00 = local_a20;
    strncpy(local_a20,pcVar4,0x100);
    local_920 = 0;
    sVar5 = strlen(__s_00);
    if (sVar5 < 0x101) goto LAB_00462054;
    __s = (FILE *)0x0;
    if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00462138;
    pcVar4 = "\x1b[31;49m[%s]<%s():%d> search_value too long[%s]!\x1b[0m\r\n";
    uVar10 = 0x56d;
LAB_004621f8:
    printf(pcVar4,"dhcp_defend","_uac_dhcpdef_jcs_get_bind_entries",uVar10,__s_00);
  }
LAB_00462138:
  if (local_a24 != 0) {
    json_object_put();
    local_a24 = 0;
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  return;
}

