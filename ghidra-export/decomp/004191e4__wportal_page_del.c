// func _wportal_page_del @ 004191e4 size=1936

undefined4 _wportal_page_del(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *__s;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *__src;
  int iVar7;
  int *piVar8;
  undefined8 uVar9;
  char local_2a8 [240];
  int local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  char local_184 [292];
  int local_60 [7];
  undefined1 local_41;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  local_198 = 0;
  iVar1 = json_object_object_get(param_1,"count");
  if (iVar1 == 0) {
LAB_00419254:
    if (jcs_err_switch == 0) {
      return 0;
    }
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_page_del",0x1f37);
    return 0;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    iVar1 = json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 != 2) goto LAB_00419254;
    uVar9 = json_object_get_double(iVar1);
    iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
  }
  if (iVar1 < 1) {
    return 0;
  }
  __s = (int *)FUN_00408450(iVar1 << 2,0x1f3b);
  if (__s == (int *)0x0) {
    return 0xffffffff;
  }
  memset(__s,0,iVar1 << 2);
  if (g_portal_auth_mode == 1) {
    iVar2 = json_object_object_get(param_1,"vlan_id");
    if (iVar2 != 0) {
      iVar7 = json_object_get_type(iVar2);
      if (iVar7 == 5) {
        piVar8 = __s;
        for (iVar7 = 0; (iVar5 = json_object_array_length(iVar2), iVar7 < iVar5 && (iVar7 != iVar1))
            ; iVar7 = iVar7 + 1) {
          iVar5 = json_object_array_get_idx(iVar2,iVar7);
          if (iVar5 == 0) {
LAB_004197f4:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_wportal_page_del",0x1f45);
            }
            *piVar8 = -1;
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 == 3) {
              iVar5 = json_object_get_int(iVar5);
              *piVar8 = iVar5;
            }
            else {
              iVar6 = json_object_get_type();
              if (iVar6 != 2) goto LAB_004197f4;
              uVar9 = json_object_get_double(iVar5);
              iVar5 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
              *piVar8 = iVar5;
            }
          }
          piVar8 = piVar8 + 1;
        }
        goto LAB_00419328;
      }
      iVar1 = json_object_get_type(iVar2);
      if (iVar1 == 4) {
        iVar1 = json_object_object_length(iVar2);
        iVar7 = 0;
        if (iVar1 == 0) goto LAB_00419328;
      }
    }
    iVar7 = 0;
    if (jcs_err_switch == 0) goto LAB_00419328;
    uVar4 = 0x1f45;
  }
  else {
    if (g_portal_auth_mode != 0) {
      iVar7 = 0;
      if (g_portal_auth_mode == 2) {
        iVar1 = json_object_object_get(param_1,"interface");
        if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_wportal_page_del",0x1f4f);
          }
          iVar7 = 0;
          strncpy((char *)local_60,"",0x1f);
          local_41 = 0;
        }
        else {
          __src = (char *)json_object_get_string(iVar1);
          strncpy((char *)local_60,__src,0x1f);
          local_41 = 0;
        }
      }
      goto LAB_00419328;
    }
    iVar2 = json_object_object_get(param_1,"serv_id");
    if (iVar2 != 0) {
      iVar7 = json_object_get_type(iVar2);
      if (iVar7 == 5) {
        piVar8 = __s;
        for (iVar7 = 0; (iVar5 = json_object_array_length(iVar2), iVar7 < iVar5 && (iVar7 != iVar1))
            ; iVar7 = iVar7 + 1) {
          iVar5 = json_object_array_get_idx(iVar2,iVar7);
          if (iVar5 == 0) {
LAB_00419890:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_wportal_page_del",0x1f4a);
            }
            *piVar8 = -1;
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 == 3) {
              iVar5 = json_object_get_int(iVar5);
              *piVar8 = iVar5;
            }
            else {
              iVar6 = json_object_get_type();
              if (iVar6 != 2) goto LAB_00419890;
              uVar9 = json_object_get_double(iVar5);
              iVar5 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
              *piVar8 = iVar5;
            }
          }
          piVar8 = piVar8 + 1;
        }
        goto LAB_00419328;
      }
      iVar1 = json_object_get_type(iVar2);
      if (iVar1 == 4) {
        iVar1 = json_object_object_length(iVar2);
        iVar7 = 0;
        if (iVar1 == 0) goto LAB_00419328;
      }
    }
    iVar7 = 0;
    if (jcs_err_switch == 0) goto LAB_00419328;
    uVar4 = 0x1f4a;
  }
  iVar7 = 0;
  printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
         "_wportal_page_del",uVar4);
LAB_00419328:
  iVar1 = 0;
  piVar8 = __s;
  do {
    while( true ) {
      if (iVar7 <= iVar1) {
        FUN_00407df0(__s);
        if (((g_portal_auth_mode == 2) &&
            (uVar4 = wportal_db_iface_del(local_60), wportal_debug_switch != 0)) &&
           (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d wportal_db_iface_del ret is : %d\n\n","_wportal_page_del",
                 0x1f8e,uVar4);
        }
        return 0;
      }
      memset(&local_194,0,0x16c);
      iVar2 = *piVar8;
      if (g_portal_auth_mode != 1) break;
      if (iVar2 == 0) {
        iVar2 = 0xfff;
      }
      iVar2 = wportal_db_rdt_get_by_vlan(iVar2,&local_194);
      if ((iVar2 != -1) && (local_60[0] != 0)) {
        if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d _wportal_sync_auth_status\n","_wportal_page_del",0x1f60);
        }
        FUN_00419130(&local_194,0);
        iVar2 = *piVar8;
        if (iVar2 == 0) {
          iVar2 = 0xfff;
        }
        wportal_db_rdt_del(iVar2);
        _wportal_update_portal_to_ap(&local_194,3);
        if (local_194._0_1_ != '\0') {
          for (uVar3 = 0; uVar3 < 0x80; uVar3 = uVar3 + 1) {
            local_2a8[uVar3 + 0x70] = local_184[uVar3 + 0x70];
          }
          local_1b8 = local_60[0];
          local_1b4 = local_40;
          local_1b0 = local_3c;
          local_1ac = local_38;
          local_1a8 = 1;
          local_1a4 = 2;
          for (uVar3 = 0; uVar3 < 0x70; uVar3 = uVar3 + 1) {
            local_2a8[uVar3] = local_184[uVar3];
          }
          FUN_00416a5c(local_194,local_190,local_18c,local_188);
        }
        uVar3 = 0;
        if (local_184[0x70] != '\0') {
          for (; uVar3 < 0x80; uVar3 = uVar3 + 1) {
            local_2a8[uVar3 + 0x70] = local_184[uVar3 + 0x70];
          }
          local_1b8 = local_60[0];
          local_1b4 = local_40;
          local_1b0 = local_3c;
          local_1ac = local_38;
          local_1a8 = 2;
          local_1a4 = 2;
          for (uVar3 = 0; uVar3 < 0x70; uVar3 = uVar3 + 1) {
            local_2a8[uVar3] = local_184[uVar3];
          }
          FUN_00416a5c(local_194,local_190,local_18c,local_188);
          goto LAB_0041944c;
        }
      }
LAB_004193d4:
      iVar1 = iVar1 + 1;
      piVar8 = piVar8 + 1;
    }
    iVar2 = wportal_db_ssid_rdt_get(iVar2,&local_194);
    if (iVar2 == 0) {
      wportal_db_ssid_rdt_del(*piVar8);
      wserv_db_entry_for_each_rd(local_60[0],_wportal_wserv_del_rdt_ftt,&local_194);
      local_198 = 0;
      wserv_db_entry_for_each_rd(local_60[0],_wportal_wserv_modify_rdt,&local_198);
    }
    else {
      if ((wportal_debug_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_004193d4;
      printf("[WPORTAL_DBG]%s()/%d Not get ssid for del rdt: %d\n\n","_wportal_page_del",0x1f78,
             *piVar8);
    }
LAB_0041944c:
    iVar1 = iVar1 + 1;
    piVar8 = piVar8 + 1;
  } while( true );
}

