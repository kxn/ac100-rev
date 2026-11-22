// func _uac_wserv_ip_jcs_del @ 005e6cf8 size=892

void _uac_wserv_ip_jcs_del(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char *__dest;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *__src;
  undefined4 *puVar7;
  
  puVar1 = (undefined4 *)FUN_004082a0(0x20,4,0xf03);
  if (puVar1 == (undefined4 *)0x0) {
    __dest = (char *)0x0;
    if (g_wserv_error != 0) {
      iVar2 = is_target_debug_ap();
      __dest = (char *)0x0;
      if (iVar2 != 0) {
        uVar5 = 0xf06;
        goto LAB_005e7050;
      }
    }
LAB_005e6e5c:
    uVar5 = json_object_new_int(0xffffffff);
    json_object_object_add(param_2,"result",uVar5);
    if (puVar1 == (undefined4 *)0x0) goto LAB_005e6e88;
  }
  else {
    __dest = (char *)FUN_00408450(0x100,0xf0a);
    if (__dest == (char *)0x0) {
      if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        uVar5 = 0xf0d;
LAB_005e7050:
        printf("<wserv>[error]%s(): %d  -> no memory!\r\n","_uac_wserv_ip_jcs_del",uVar5);
      }
      goto LAB_005e6e5c;
    }
    if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ip_jcs_del() begin.\r\n","_uac_wserv_ip_jcs_del"
             ,0xf11);
    }
    iVar2 = json_object_object_get(param_1,"id");
    if (iVar2 != 0) {
      memset(__dest,0,0x100);
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 6) {
        __src = (char *)json_object_get_string(iVar2);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_wserv_ip_jcs_del",0xf17);
        }
        __src = "";
      }
      strncpy(__dest,__src,0xff);
      __dest[0xff] = '\0';
      iVar2 = FUN_005d9d1c(__dest,puVar1,0x20);
      if (iVar2 < 1) {
        if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("<wserv>[error]%s(): %d  -> _uac_wserv_util_str_split() fail, str: %s!\r\n",
                 "_uac_wserv_ip_jcs_del",0xf1c,__dest);
        }
      }
      else {
        iVar3 = 0;
        puVar7 = puVar1;
        do {
          iVar4 = atoi((char *)*puVar7);
          uVar5 = wserv_db_ip_del(iVar4);
          if ((g_wserv_debug != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
            printf("<wserv>[debug]%s(): %d  -> wserv_db_ip_del() id=%d., ret = %d\r\n",
                   "_uac_wserv_ip_jcs_del",0xf24,iVar4,uVar5);
          }
          iVar3 = iVar3 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar3 != iVar2);
        uac_wservice_igmp_white_list_change();
      }
      goto LAB_005e6e5c;
    }
    if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_ip_jcs_del",0xf14,"id");
    }
  }
  FUN_00407df0(puVar1);
LAB_005e6e88:
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ip_jcs_del() end.\r\n","_uac_wserv_ip_jcs_del",
           0xf36);
    return;
  }
  return;
}

