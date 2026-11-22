// func _uac_dhcpdef_jcs_get_bind_svrs @ 00460b88 size=2436

void _uac_dhcpdef_jcs_get_bind_svrs(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  FILE *__s;
  char *pcVar4;
  size_t sVar5;
  char *__format;
  undefined **ppuVar6;
  undefined *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  int local_258 [3];
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  char *local_240;
  undefined *local_23c;
  int local_238;
  char local_234 [256];
  undefined1 local_134;
  char local_130 [256];
  undefined1 local_30;
  
  memset(local_130,0,0x101);
  memset(local_234,0,0x101);
  memset(local_258,0,0x24);
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_jcs_get_bind_svrs",0x6e6,
           "_uac_dhcpdef_jcs_get_bind_svrs");
  }
  iVar1 = json_object_object_get(param_1,"ap_id");
  if (iVar1 == 0) {
    iVar1 = dhcpdef_db_apbind_entry_get_first_id();
    if (iVar1 < 0) {
LAB_004610f8:
      if (g_dhcpdef_error == 0) {
        return;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return;
      }
      printf("\x1b[31;49m[%s]<%s():%d> can NOT find used ap!\x1b[0m\r\n","dhcp_defend",
             "_uac_dhcpdef_jcs_get_bind_svrs",0x6f8);
      return;
    }
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    if ((iVar2 + iVar3 <= iVar1) &&
       ((iVar1 < 50000 || (iVar2 = apmngr_db_get_sensor_max(), iVar2 + 50000 <= iVar1))))
    goto LAB_004610f8;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) {
        if (jcs_err_switch == 0) {
          iVar1 = -1;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_dhcpdef_jcs_get_bind_svrs",0x6eb);
          iVar1 = -1;
        }
        goto LAB_00460c50;
      }
      uVar10 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
    }
    if (iVar1 < 0) {
LAB_00460c50:
      if (g_dhcpdef_error == 0) {
        return;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return;
      }
      printf("\x1b[31;49m[%s]<%s():%d> ap_id[%d] is invalid! just return.\x1b[0m\r\n","dhcp_defend",
             "_uac_dhcpdef_jcs_get_bind_svrs",0x6ee,iVar1);
      return;
    }
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    if ((iVar2 + iVar3 <= iVar1) &&
       ((iVar1 < 50000 || (iVar2 = apmngr_db_get_sensor_max(), iVar2 + 50000 <= iVar1))))
    goto LAB_00460c50;
  }
  uVar9 = 0;
  iVar2 = json_object_object_get(param_1,"offset");
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
                 "_uac_dhcpdef_jcs_get_bind_svrs",0x6fe);
        }
      }
    }
  }
  uVar8 = 10;
  iVar2 = json_object_object_get(param_1,"limit");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar8 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar10 = json_object_get_double(iVar2);
        uVar8 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
      }
      else {
        uVar8 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_dhcpdef_jcs_get_bind_svrs",0x701);
        }
      }
    }
  }
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> ap_id=%d, offset=%d, limit=%d.\r\n","dhcp_defend",
           "_uac_dhcpdef_jcs_get_bind_svrs",0x703,iVar1,uVar9,uVar8);
  }
  iVar2 = json_object_object_get(param_1,"search_name");
  if (iVar2 == 0) {
    puVar7 = (undefined *)0x0;
LAB_00460e58:
    memset(local_258,0,0x24);
    local_238 = json_object_new_array();
    if (local_238 == 0) {
      __s = (FILE *)0x0;
      if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00460f78;
      pcVar4 = "\x1b[31;49m[%s]<%s():%d> JSON_ARRAY_CREATE() fail!\x1b[0m\r\n";
      uVar9 = 0x71a;
    }
    else {
      local_258[1] = 0;
      local_248 = 0;
      local_244 = 0;
      local_258[0] = iVar1;
      local_258[2] = uVar9;
      local_24c = uVar8;
      if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[%s]<%s():%d> get_arg: ap_id[%d], offset[%d], limit[%d], total_size[%d]\r\n",
               "dhcp_defend","_uac_dhcpdef_jcs_get_bind_svrs",0x725,local_258[0],local_258[2],
               local_24c,local_244);
      }
      if (((local_130[0] != '\0') && (local_234[0] != '\0')) && (puVar7 != (undefined *)0x0)) {
        if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(0x460000,local_258), iVar1 != 0)) {
          printf("[%s]<%s():%d> search_name: %s, search_value: %s\r\n","dhcp_defend",
                 "_uac_dhcpdef_jcs_get_bind_svrs",0x729,local_130,local_234);
        }
        local_240 = local_234;
        local_23c = puVar7;
      }
      iVar1 = dhcpdef_db_all_svr_foreach(_set_bind_svrs_arg,local_258);
      if (iVar1 != 0) {
        return;
      }
      __s = fopen("/tmp/dhcpdef_svr","w+");
      if (__s == (FILE *)0x0) {
        if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00460f78;
        pcVar4 = "/tmp/dhcpdef_svr";
        __format = "\x1b[31;49m[%s]<%s():%d> open get file[%s] fail!\x1b[0m\r\n";
        uVar9 = 0x737;
        goto LAB_00461278;
      }
      pcVar4 = (char *)json_object_to_json_string_ext(local_238,0);
      if (pcVar4 == (char *)0x0) {
        if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00460f78;
        pcVar4 = "\x1b[31;49m[%s]<%s():%d> JSON_STRING_FROM_OBJ fail!\x1b[0m\r\n";
        uVar9 = 0x73e;
      }
      else {
        sVar5 = strlen(pcVar4);
        sVar5 = fwrite(pcVar4,sVar5,1,__s);
        if (sVar5 == 1) {
          uVar9 = json_object_new_string("/tmp/dhcpdef_svr");
          json_object_object_add(param_2,"file_name",uVar9);
          uVar9 = json_object_new_int(local_244);
          json_object_object_add(param_2,"total_num",uVar9);
          if ((g_dhcpdef_info == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
          goto LAB_00460f78;
          pcVar4 = "_uac_dhcpdef_jcs_get_bind_svrs";
          __format = "[%s]<%s():%d> %s() success.\r\n";
          uVar9 = 0x74b;
          goto LAB_00461278;
        }
        if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00460f78;
        pcVar4 = "\x1b[31;49m[%s]<%s():%d> write result to file fail!\x1b[0m\r\n";
        uVar9 = 0x745;
      }
    }
    printf(pcVar4,"dhcp_defend","_uac_dhcpdef_jcs_get_bind_svrs",uVar9);
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    puVar7 = (undefined *)0x0;
    if (iVar3 != 6) goto LAB_00460e58;
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_dhcpdef_jcs_get_bind_svrs",0x708);
      }
      pcVar4 = "";
    }
    ppuVar6 = &_svr_search_items;
    iVar2 = 0;
    strncpy(local_130,pcVar4,0x100);
    local_30 = 0;
    pcVar4 = _svr_search_items;
    while( true ) {
      ppuVar6 = ppuVar6 + 2;
      iVar3 = strcmp(local_130,pcVar4);
      if (iVar3 == 0) break;
      iVar2 = iVar2 + 1;
      if (iVar2 == 4) {
        puVar7 = (undefined *)0x0;
        if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("\x1b[31;49m[%s]<%s():%d> can NOT find cmp_func for search_name[%s]!\x1b[0m\r\n",
                 "dhcp_defend","_svr_get_cmp_func",0xf6,local_130);
        }
        goto LAB_004611cc;
      }
      pcVar4 = *ppuVar6;
    }
    puVar7 = (&PTR__svr_name_cmp_0073145c)[iVar2 * 2];
LAB_004611cc:
    iVar2 = json_object_object_get(param_1,"search_value");
    if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) goto LAB_00460e58;
    iVar1 = json_object_get_type(iVar2);
    if (iVar1 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_dhcpdef_jcs_get_bind_svrs",0x70d);
      }
      pcVar4 = "";
    }
    __s = (FILE *)0x0;
    strncpy(local_234,pcVar4,0x100);
    local_134 = 0;
    if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00460f78;
    pcVar4 = local_234;
    __format = "\x1b[31;49m[%s]<%s():%d> search_value too long[%s]!\x1b[0m\r\n";
    uVar9 = 0x70f;
LAB_00461278:
    printf(__format,"dhcp_defend","_uac_dhcpdef_jcs_get_bind_svrs",uVar9,pcVar4);
  }
LAB_00460f78:
  if (local_238 != 0) {
    json_object_put();
    local_238 = 0;
  }
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  return;
}

