// func _uac_wserv_ip_jcs_set @ 005e6390 size=2408

void _uac_wserv_ip_jcs_set(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 uVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined8 uVar12;
  uint local_a8;
  uint local_a4;
  undefined1 auStack_a0 [28];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  char acStack_68 [63];
  undefined1 local_29;
  
  local_a4 = 0;
  memset(acStack_68,0,0x40);
  if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ip_jcs_set() begin.\r\n","_uac_wserv_ip_jcs_set",
           0xfa8);
  }
  iVar2 = json_object_object_get(param_1,"is_set_enable");
  if (iVar2 == 0) {
    iVar2 = -1;
    if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005e64c0;
    uVar10 = 0xfab;
    pcVar8 = "is_set_enable";
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      iVar2 = json_object_get_int(iVar2);
LAB_005e67b4:
      if (iVar2 == 1) {
        local_a8 = 0;
        puVar4 = (undefined4 *)FUN_004082a0(0x20,4,0xf4a);
        if (puVar4 == (undefined4 *)0x0) {
          pcVar8 = (char *)0x0;
          if (g_wserv_error != 0) {
            iVar2 = is_target_debug_ap();
            pcVar8 = (char *)0x0;
            if (iVar2 != 0) {
              uVar10 = 0xf4d;
              goto LAB_005e6a54;
            }
          }
LAB_005e6960:
          uVar10 = json_object_new_int(0xffffffff);
          json_object_object_add(param_2,"result",uVar10);
          if (puVar4 == (undefined4 *)0x0) goto LAB_005e698c;
        }
        else {
          pcVar8 = (char *)FUN_00408450(0x100,0xf51);
          if (pcVar8 == (char *)0x0) {
            if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              uVar10 = 0xf54;
LAB_005e6a54:
              printf("<wserv>[error]%s(): %d  -> no memory!\r\n","_uac_wserv_ip_jcs_op",uVar10);
            }
            goto LAB_005e6960;
          }
          if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ip_jcs_op() begin.\r\n",
                   "_uac_wserv_ip_jcs_op",0xf58);
          }
          iVar2 = json_object_object_get(param_1,"id");
          if (iVar2 == 0) {
            if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              uVar10 = 0xf5b;
              pcVar9 = "id";
LAB_005e6ab4:
              printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_ip_jcs_op",uVar10,
                     pcVar9);
            }
          }
          else {
            memset(pcVar8,0,0x100);
            iVar3 = json_object_get_type(iVar2);
            if (iVar3 == 6) {
              pcVar9 = (char *)json_object_get_string(iVar2);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_uac_wserv_ip_jcs_op",0xf5e);
              }
              pcVar9 = "";
            }
            strncpy(pcVar8,pcVar9,0xff);
            pcVar8[0xff] = '\0';
            iVar2 = FUN_005d9d1c(pcVar8,puVar4,0x20);
            if (iVar2 < 1) {
              if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("<wserv>[error]%s(): %d  -> _uac_wserv_util_str_split() fail, str: %s!\r\n",
                       "_uac_wserv_ip_jcs_op",0xf63,pcVar8);
              }
              goto LAB_005e6960;
            }
            iVar3 = json_object_object_get(param_1,"enable");
            if (iVar3 == 0) {
              if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                uVar10 = 0xf68;
                pcVar9 = "enable";
                goto LAB_005e6ab4;
              }
            }
            else {
              iVar5 = json_object_get_type(iVar3);
              if (iVar5 == 6) {
                pcVar9 = (char *)json_object_get_string(iVar3);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_uac_wserv_ip_jcs_op",0xf69);
                }
                pcVar9 = "";
              }
              bVar1 = false;
              strncpy((char *)&local_a8,pcVar9,3);
              local_a8 = local_a8 & 0xffffff00;
              iVar5 = 0;
              iVar3 = strcmp((char *)&local_a8,"on");
              puVar11 = puVar4;
              do {
                pcVar9 = (char *)*puVar11;
                iVar5 = iVar5 + 1;
                puVar11 = puVar11 + 1;
                iVar6 = atoi(pcVar9);
                iVar6 = wserv_db_ip_set_status(iVar6,iVar3 == 0);
                if (iVar6 == 0) {
                  bVar1 = true;
                }
              } while (iVar5 != iVar2);
              if (bVar1) {
                uac_wservice_igmp_white_list_change(1);
              }
              uVar10 = json_object_new_int(!bVar1);
              json_object_object_add(param_2,"result",uVar10);
            }
          }
        }
        FUN_00407df0(puVar4);
LAB_005e698c:
        if (pcVar8 != (char *)0x0) {
          FUN_00407df0(pcVar8);
        }
        if (g_wserv_debug == 0) {
          return;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return;
        }
        printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ip_jcs_op() end.\r\n","_uac_wserv_ip_jcs_op",
               0xf97);
        return;
      }
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 == 2) {
        uVar12 = json_object_get_double(iVar2);
        iVar2 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
        goto LAB_005e67b4;
      }
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_uac_wserv_ip_jcs_set",0xfac);
      }
    }
    local_80 = 0;
    local_7c = 0;
    local_78 = 0;
    local_74 = 0;
    local_70 = 0;
    local_6c = 0;
    local_84 = 0xffffffff;
    iVar2 = json_object_object_get(param_1,"id");
    if (iVar2 == 0) {
      iVar2 = -1;
      if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005e64c0;
      uVar10 = 0xfb7;
      pcVar8 = "id";
    }
    else {
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
                   "_uac_wserv_ip_jcs_set",0xfb8);
          }
        }
      }
      local_84 = uVar10;
      iVar3 = wserv_db_ip_get_entry_by_id(uVar10,auStack_a0);
      iVar2 = -1;
      if (iVar3 != 0) goto LAB_005e64c0;
      iVar3 = json_object_object_get(param_1,"ip_addr");
      if (iVar3 == 0) {
        if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005e64c0;
        uVar10 = 0xfc1;
        pcVar8 = "ip_addr";
      }
      else {
        iVar2 = json_object_get_type(iVar3);
        if (iVar2 == 6) {
          pcVar8 = (char *)json_object_get_string(iVar3);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_wserv_ip_jcs_set",0xfc2);
          }
          pcVar8 = "";
        }
        strncpy(acStack_68,pcVar8,0x3f);
        local_29 = 0;
        FUN_0051a7a8(acStack_68,&local_80);
        iVar2 = json_object_object_get(param_1,"relay");
        if (iVar2 == 0) {
          iVar2 = -1;
          if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005e64c0;
          uVar10 = 0xfc6;
          pcVar8 = "relay";
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 3) {
            uVar7 = json_object_get_int(iVar2);
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 == 2) {
              uVar12 = json_object_get_double(iVar2);
              uVar7 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
            }
            else {
              uVar7 = 0xff;
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_uac_wserv_ip_jcs_set",0xfc7);
                uVar7 = 0xff;
              }
            }
          }
          local_6c = CONCAT13(uVar7,local_6c._1_3_);
          iVar2 = json_object_object_get(param_1,"enable");
          if (iVar2 != 0) {
            iVar3 = json_object_get_type(iVar2);
            if (iVar3 == 6) {
              pcVar8 = (char *)json_object_get_string(iVar2);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_uac_wserv_ip_jcs_set",0xfcc);
              }
              pcVar8 = "";
            }
            strncpy((char *)&local_a4,pcVar8,3);
            local_a4 = local_a4 & 0xffffff00;
            iVar2 = strcmp((char *)&local_a4,"on");
            if (iVar2 == 0) {
              local_6c._1_3_ = CONCAT12(1,local_6c._2_2_);
            }
            else {
              local_6c._1_3_ = (uint3)local_6c._2_2_;
            }
            iVar2 = wserv_db_ip_modify(&local_84);
            if (iVar2 == 0) {
              uac_wservice_igmp_white_list_change();
            }
            goto LAB_005e64c0;
          }
          iVar2 = -1;
          if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005e64c0;
          uVar10 = 0xfcb;
          pcVar8 = "enable";
        }
      }
    }
  }
  iVar2 = -1;
  printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_ip_jcs_set",uVar10,pcVar8);
LAB_005e64c0:
  if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ip_jcs_set() finish, id=%d.\r\n",
           "_uac_wserv_ip_jcs_set",0xfdd,local_84);
  }
  uVar10 = json_object_new_int(iVar2);
  json_object_object_add(param_2,"id",uVar10);
  return;
}

