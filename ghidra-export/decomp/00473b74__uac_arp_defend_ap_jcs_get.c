// func _uac_arp_defend_ap_jcs_get @ 00473b74 size=1856

void _uac_arp_defend_ap_jcs_get(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  FILE *__s;
  char *pcVar4;
  size_t sVar5;
  char *pcVar6;
  undefined2 *puVar7;
  undefined **ppuVar8;
  undefined *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined8 uVar12;
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
  if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[ARP_DEFEND_DEBUG]%s()/%d _uac_arp_defend_ap_jcs_get() begin.\n",
           "_uac_arp_defend_ap_jcs_get",0x18e);
  }
  apmngr_db_group_id_parse(param_1,&local_818);
  uVar11 = 0;
  iVar2 = json_object_object_get(param_1,"offset");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar11 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar12 = json_object_get_double(iVar2);
        uVar11 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      }
      else {
        uVar11 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_arp_defend_ap_jcs_get",0x193);
        }
      }
    }
  }
  uVar10 = 10;
  iVar2 = json_object_object_get(param_1,"limit");
  if (iVar2 != 0) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar10 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar12 = json_object_get_double(iVar2);
        uVar10 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
      }
      else {
        uVar10 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_arp_defend_ap_jcs_get",0x196);
        }
      }
    }
  }
  iVar2 = json_object_object_get(param_1,"search_name");
  if (iVar2 == 0) {
    puVar9 = (undefined *)0x0;
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    puVar9 = (undefined *)0x0;
    if (iVar3 == 6) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 6) {
        pcVar4 = (char *)json_object_get_string(iVar2);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_arp_defend_ap_jcs_get",0x19b);
        }
        pcVar4 = "";
      }
      ppuVar8 = &l_arp_defend_search_items;
      iVar2 = 0;
      strncpy(local_91c,pcVar4,0x100);
      local_81c = 0;
      pcVar4 = l_arp_defend_search_items;
      while( true ) {
        ppuVar8 = ppuVar8 + 2;
        iVar3 = strcmp(local_91c,pcVar4);
        if (iVar3 == 0) break;
        iVar2 = iVar2 + 1;
        if (iVar2 == 5) {
          puVar9 = (undefined *)0x0;
          if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[ARP_DEFEND_ERROR]%s()/%d can NOT find cmp_func for search_name[%s]!\n",
                   "_uac_arp_defend_get_cmp_func",0x113,local_91c);
          }
          goto LAB_00473fe4;
        }
        pcVar4 = *ppuVar8;
      }
      puVar9 = (&PTR__uac_arp_defend_ap_name_cmp_00731494)[iVar2 * 2];
LAB_00473fe4:
      iVar2 = json_object_object_get(param_1,"search_value");
      if ((iVar2 != 0) && (iVar3 = json_object_get_type(iVar2), iVar3 == 6)) {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 6) {
          pcVar4 = (char *)json_object_get_string(iVar2);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_arp_defend_ap_jcs_get",0x1a1);
          }
          pcVar4 = "";
        }
        strncpy(local_a20,pcVar4,0x100);
        local_920 = 0;
        sVar5 = strlen(local_a20);
        if (0x100 < sVar5) {
          if (arp_defend_err_switch == 0) {
            return;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return;
          }
          pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d search_value too long[%s]!\n";
          uVar11 = 0x1a4;
          pcVar6 = local_a20;
          goto LAB_00474090;
        }
      }
    }
  }
  iVar2 = json_object_new_array();
  if (iVar2 == 0) {
    if (arp_defend_err_switch == 0) {
      return;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return;
    }
    printf("[ARP_DEFEND_ERROR]%s()/%d JSON_ARRAY_CREATE() fail!\n","_uac_arp_defend_ap_jcs_get",
           0x1ae);
    return;
  }
  local_a38 = 0;
  local_a34 = 0;
  local_a30 = 0;
  local_a40 = uVar11;
  local_a3c = uVar10;
  local_a24 = iVar2;
  if (((local_91c[0] != '\0') && (local_a20[0] != '\0')) && (puVar9 != (undefined *)0x0)) {
    if (arp_defend_debug_switch != 0) {
      iVar3 = is_target_debug_ap();
      if (iVar3 != 0) {
        printf("[ARP_DEFEND_DEBUG]%s()/%d search: name:%s, value:%s!\n","_uac_arp_defend_ap_jcs_get"
               ,0x1bb,local_91c,local_a20);
      }
    }
    local_a2c = local_a20;
    local_a28 = puVar9;
  }
  if (local_818 == 0) {
    puVar7 = local_814;
    for (iVar3 = 0; iVar3 < local_30; iVar3 = iVar3 + 1) {
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
      apmngr_db_foreach_proc_by_group(uVar1,0xf0000,_uac_arp_defend_foreach,&local_a40);
    }
  }
  else {
    iVar3 = apmngr_db_foreach_proc(0xf0000,_uac_arp_defend_foreach,&local_a40);
    if (iVar3 == 1) {
      if (arp_defend_warning_switch == 0) {
        return;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return;
      }
      pcVar4 = "[ARP_DEFEND_WARNING]%s()/%d apmngr_db_foreach_proc() fail, ret=%d!\n";
      uVar11 = 0x1c6;
      pcVar6 = (char *)0x1;
LAB_00474090:
      printf(pcVar4,"_uac_arp_defend_ap_jcs_get",uVar11,pcVar6);
      return;
    }
  }
  uVar11 = local_a30;
  __s = fopen("/tmp/arp_defend_ap_get","w+");
  if (__s == (FILE *)0x0) {
    if ((arp_defend_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d open get file[%s] fail!\n","_uac_arp_defend_ap_jcs_get",
             0x1d6,"/tmp/arp_defend_ap_get");
    }
  }
  else {
    pcVar4 = (char *)json_object_to_json_string_ext(iVar2,0);
    if (pcVar4 == (char *)0x0) {
      if ((arp_defend_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
      goto LAB_00473db8;
      pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d JSON_STRING_FROM_OBJ fail!\n";
      uVar11 = 0x1dd;
    }
    else {
      sVar5 = strlen(pcVar4);
      sVar5 = fwrite(pcVar4,sVar5,1,__s);
      if (sVar5 == 1) {
        uVar10 = json_object_new_string("/tmp/arp_defend_ap_get");
        json_object_object_add(param_2,"file_name",uVar10);
        uVar11 = json_object_new_int(uVar11);
        json_object_object_add(param_2,"total_num",uVar11);
        if ((arp_defend_debug_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_00473db8;
        pcVar4 = "[ARP_DEFEND_DEBUG]%s()/%d _uac_arp_defend_ap_jcs_get() success.\n";
        uVar11 = 0x1ea;
      }
      else {
        if ((arp_defend_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_00473db8;
        pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d write result to file fail!\n";
        uVar11 = 0x1e4;
      }
    }
    printf(pcVar4,"_uac_arp_defend_ap_jcs_get",uVar11);
  }
LAB_00473db8:
  json_object_put(iVar2);
  if (__s != (FILE *)0x0) {
    fclose(__s);
  }
  return;
}

