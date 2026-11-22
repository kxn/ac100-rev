// func _uac_dhcpdef_jcs_svr_del @ 0046541c size=2232

void _uac_dhcpdef_jcs_svr_del(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char *__dest;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  FILE *__s;
  size_t sVar10;
  char *pcVar11;
  int iVar12;
  undefined4 *puVar13;
  int local_38;
  int local_34;
  undefined4 *local_30;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_jcs_svr_del",0x393,
           "_uac_dhcpdef_jcs_svr_del");
  }
  iVar1 = FUN_004082a0(1000,4,0x395);
  if (iVar1 == 0) {
    if (g_dhcpdef_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend","_uac_dhcpdef_jcs_svr_del"
           ,0x398);
    return;
  }
  __dest = (char *)FUN_00408450(0x1771,0x39c);
  if (__dest == (char *)0x0) {
    puVar5 = (undefined4 *)0x0;
    if (g_dhcpdef_error == 0) goto LAB_0046563c;
    iVar2 = is_target_debug_ap();
    puVar5 = (undefined4 *)0x0;
    if (iVar2 == 0) goto LAB_0046563c;
    pcVar11 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
    uVar9 = 0x39f;
  }
  else {
    iVar2 = json_object_object_get(param_1,"svr_id");
    if (iVar2 == 0) {
      puVar5 = (undefined4 *)0x0;
      if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n","dhcp_defend",
               "_uac_dhcpdef_jcs_svr_del",0x3a4,"svr_id");
      }
      goto LAB_0046563c;
    }
    memset(__dest,0,0x1771);
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 6) {
      pcVar11 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_dhcpdef_jcs_svr_del",0x3a6);
      }
      pcVar11 = "";
    }
    strncpy(__dest,pcVar11,6000);
    __dest[6000] = '\0';
    iVar2 = dhcpdef_util_str_split(__dest,&DAT_00678b90,iVar1,1000);
    if (iVar2 < 1) {
      puVar5 = (undefined4 *)0x0;
      if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0046563c;
      pcVar11 = "\x1b[31;49m[%s]<%s():%d> no server is selected!\x1b[0m\r\n";
      uVar9 = 0x3ab;
    }
    else {
      puVar4 = (undefined4 *)FUN_004082a0(iVar2,4,0x3ae);
      if (puVar4 != (undefined4 *)0x0) {
        puVar5 = (undefined4 *)FUN_004082a0(iVar2,4,0x3b4);
        if (puVar5 == (undefined4 *)0x0) {
          if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            uVar9 = 0x3b7;
LAB_00465a7c:
            printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
                   "_uac_dhcpdef_jcs_svr_del",uVar9);
          }
        }
        else {
          iVar3 = 0;
          iVar12 = 0;
          do {
            iVar12 = iVar12 + 1;
            iVar6 = atoi(*(char **)(iVar1 + iVar3));
            *(int *)((int)puVar4 + iVar3) = iVar6;
            puVar7 = (undefined4 *)((int)puVar5 + iVar3);
            iVar3 = iVar3 + 4;
            *puVar7 = 0;
          } while (iVar12 != iVar2);
          iVar3 = dhcpdef_db_apbind_entry_count();
          if (iVar3 < 1) {
            if ((g_dhcpdef_warn != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("\x1b[33;49m[%s]<%s():%d> no ap on the system, delete server entry directly!\x1b[0m\r\n"
                     ,"dhcp_defend","_uac_dhcpdef_jcs_svr_del",0x3c3);
            }
            puVar7 = (undefined4 *)0x0;
            iVar12 = 0;
LAB_00465888:
            local_34 = 0;
            local_38 = 0;
            puVar8 = puVar4;
            puVar13 = puVar5;
            do {
              iVar3 = dhcpdef_db_svr_entry_del(*puVar8);
              if (iVar3 == 0) {
                if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  printf("[%s]<%s():%d> delete server entry[%d] success.\r\n","dhcp_defend",
                         "_uac_dhcpdef_jcs_svr_del",0x3f1,*puVar8);
                }
                *puVar13 = 1;
                local_38 = local_38 + 1;
              }
              else if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                printf("\x1b[31;49m[%s]<%s():%d> delete server entry[%d] fail!\x1b[0m\r\n",
                       "dhcp_defend","_uac_dhcpdef_jcs_svr_del",0x3ed,*puVar8);
              }
              puVar8 = puVar8 + 1;
              puVar13 = puVar13 + 1;
              local_34 = local_34 + 1;
            } while (local_34 != iVar2);
            iVar6 = 0;
            iVar3 = json_object_new_array();
            local_30 = puVar5;
            if (iVar3 == 0) {
              if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                pcVar11 = "\x1b[31;49m[%s]<%s():%d> JSON_ARRAY_CREATE() fail!\x1b[0m\r\n";
                uVar9 = 0x3fd;
LAB_00465afc:
                printf(pcVar11,"dhcp_defend","_uac_dhcpdef_jcs_svr_del",uVar9);
              }
            }
            else {
              do {
                iVar6 = iVar6 + 1;
                uVar9 = json_object_new_int(*local_30);
                json_object_array_add(iVar3,uVar9);
                local_30 = local_30 + 1;
              } while (iVar6 != iVar2);
              __s = fopen("/tmp/dhcpdef_del_svr","w+");
              if (__s == (FILE *)0x0) {
                if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("\x1b[31;49m[%s]<%s():%d> open file[%s] fail!\x1b[0m\r\n","dhcp_defend",
                         "_uac_dhcpdef_jcs_svr_del",0x409,"/tmp/dhcpdef_del_svr");
                }
              }
              else {
                pcVar11 = (char *)json_object_to_json_string_ext(iVar3,0);
                if (pcVar11 == (char *)0x0) {
                  if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    pcVar11 = "\x1b[31;49m[%s]<%s():%d> JSON_STRING_FROM_OBJ() fail!\x1b[0m\r\n";
                    uVar9 = 0x410;
LAB_00465c08:
                    printf(pcVar11,"dhcp_defend","_uac_dhcpdef_jcs_svr_del",uVar9);
                  }
                }
                else {
                  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    printf("[%s]<%s():%d> out_arr: %s\r\n","dhcp_defend","_uac_dhcpdef_jcs_svr_del",
                           0x413,pcVar11);
                  }
                  sVar10 = strlen(pcVar11);
                  sVar10 = fwrite(pcVar11,sVar10,1,__s);
                  if (sVar10 == 1) {
                    uVar9 = json_object_new_string("/tmp/dhcpdef_del_svr");
                    json_object_object_add(param_2,"file_name",uVar9);
                    uVar9 = json_object_new_int(local_38);
                    json_object_object_add(param_2,"succ_num",uVar9);
                  }
                  else if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    pcVar11 = "\x1b[31;49m[%s]<%s():%d> write result to file fail!\x1b[0m\r\n";
                    uVar9 = 0x418;
                    goto LAB_00465c08;
                  }
                }
              }
              json_object_put(iVar3);
              if (__s != (FILE *)0x0) {
                fclose(__s);
              }
            }
          }
          else {
            iVar12 = FUN_004082a0(iVar3,4,0x3c6);
            if (iVar12 == 0) {
              if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                uVar9 = 0x3c9;
                goto LAB_00465a7c;
              }
              goto LAB_0046562c;
            }
            iVar6 = dhcpdef_db_apbind_entry_get_all_ids(iVar12,iVar3);
            puVar7 = (undefined4 *)0x0;
            if (iVar6 == 0) {
              puVar7 = (undefined4 *)FUN_004082a0(iVar3,4,0x3d2);
              if (puVar7 == (undefined4 *)0x0) {
                if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  pcVar11 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
                  uVar9 = 0x3d5;
                  goto LAB_00465afc;
                }
              }
              else {
                iVar6 = 0;
                puVar8 = puVar7;
                do {
                  iVar6 = iVar6 + 1;
                  *puVar8 = 0;
                  puVar8 = puVar8 + 1;
                } while (iVar6 != iVar3);
                iVar3 = dhcpdef_db_batch_unbind(iVar12,iVar6,puVar4,iVar2,puVar7);
                if ((iVar3 == 0) &&
                   (iVar3 = _uac_dhcpdef_batch_firm_and_notify(1,iVar12,iVar6,puVar7), iVar3 == 0))
                goto LAB_00465888;
              }
            }
          }
          if (iVar12 != 0) {
            FUN_00407df0(iVar12);
          }
          if (puVar7 != (undefined4 *)0x0) {
            FUN_00407df0(puVar7);
          }
        }
LAB_0046562c:
        if (puVar4 != (undefined4 *)0x0) {
          FUN_00407df0(puVar4);
        }
        goto LAB_0046563c;
      }
      puVar5 = (undefined4 *)0x0;
      if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0046563c;
      pcVar11 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
      uVar9 = 0x3b1;
    }
  }
  puVar5 = (undefined4 *)0x0;
  printf(pcVar11,"dhcp_defend","_uac_dhcpdef_jcs_svr_del",uVar9);
LAB_0046563c:
  if (iVar1 != 0) {
    FUN_00407df0(iVar1);
  }
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  if (puVar5 == (undefined4 *)0x0) {
    return;
  }
  FUN_00407df0(puVar5);
  return;
}

