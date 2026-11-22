// func _uac_wserv_jcs_rd_op @ 005d9db4 size=2972

void _uac_wserv_jcs_rd_op(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  char *__dest;
  int iVar4;
  int iVar5;
  undefined2 uVar8;
  uint uVar6;
  uint uVar7;
  char *pcVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined1 *puVar14;
  char *pcVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  uint *puVar18;
  undefined8 uVar19;
  int local_350;
  undefined4 local_34c;
  code *local_348;
  code *local_344;
  int local_340;
  int *local_33c;
  char acStack_338 [32];
  undefined1 auStack_318 [16];
  undefined2 local_308;
  int local_304;
  undefined1 auStack_2ca [650];
  int local_40;
  int local_3c;
  int local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  
  memset(acStack_338,0,0x20);
  local_350 = 0;
  local_34c = 0;
  local_348 = (code *)0x0;
  local_344 = (code *)0x0;
  local_340 = 0;
  local_33c = (int *)0x0;
  iVar1 = apmngr_db_get_ap_max();
  uVar2 = apmngr_db_get_ap_max();
  local_38 = FUN_004082a0((iVar1 >> 5) + (uint)((uVar2 & 0x1f) != 0),4,0xc6e);
  if (local_38 == 0) {
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[error]%s(): %d  -> wserv_calloc() fail\r\n","_uac_wserv_jcs_rd_op",0xc71);
    }
    puVar16 = (undefined4 *)0x0;
    puVar3 = (undefined4 *)0x0;
    __dest = (char *)0x0;
    pcVar15 = (char *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_004082a0(0x3e9,4,0xc75);
    if (puVar3 == (undefined4 *)0x0) {
      if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[error]%s(): %d  -> no memory!\r\n","_uac_wserv_jcs_rd_op",0xc78);
      }
      puVar16 = (undefined4 *)0x0;
      __dest = (char *)0x0;
      pcVar15 = (char *)0x0;
    }
    else {
      __dest = (char *)FUN_00408450(0x1c16,0xc7c);
      if (__dest == (char *)0x0) {
        puVar16 = (undefined4 *)0x0;
        if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[error]%s(): %d  -> no memory!\r\n","_uac_wserv_jcs_rd_op",0xc7f);
          goto LAB_005da4b0;
        }
LAB_005da4ac:
        puVar16 = (undefined4 *)0x0;
LAB_005da4b0:
        pcVar15 = (char *)0x0;
      }
      else {
        iVar1 = json_object_object_get(param_1,"serv_id");
        if (iVar1 == 0) {
          puVar16 = (undefined4 *)0x0;
          if (g_wserv_error == 0) goto LAB_005da4ac;
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) goto LAB_005da4b0;
          uVar13 = 0xc84;
          pcVar15 = "serv_id";
LAB_005da62c:
          puVar16 = (undefined4 *)0x0;
          printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_rd_op",uVar13,
                 pcVar15);
          pcVar15 = (char *)0x0;
        }
        else {
          iVar4 = json_object_get_type(iVar1);
          if (iVar4 == 3) {
            uVar13 = json_object_get_int(iVar1);
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 == 2) {
              uVar19 = json_object_get_double(iVar1);
              uVar13 = __fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
            }
            else {
              uVar13 = 0xffffffff;
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_uac_wserv_jcs_rd_op",0xc85);
              }
            }
          }
          if (param_3 == 0) {
            iVar1 = 0;
            puVar16 = (undefined4 *)0x0;
            pcVar15 = (char *)0x0;
LAB_005d9ed8:
            iVar4 = json_object_object_get(param_1,"radio_id");
            if (iVar4 == 0) {
              if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_rd_op",0xca3,
                       "radio_id");
              }
            }
            else {
              memset(__dest,0,0x1c16);
              iVar5 = json_object_get_type(iVar4);
              if (iVar5 == 6) {
                pcVar10 = (char *)json_object_get_string(iVar4);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_uac_wserv_jcs_rd_op",0xca6);
                }
                pcVar10 = "";
              }
              strncpy(__dest,pcVar10,0x1c15);
              __dest[0x1c15] = '\0';
              local_34 = (undefined4 *)FUN_005d9d1c(__dest,puVar3,1000);
              if ((int)local_34 < 1) {
                if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  uVar13 = 0xcab;
                  pcVar10 = __dest;
LAB_005da3a0:
                  printf("<wserv>[error]%s(): %d  -> _uac_wserv_util_str_split() fail, str: %s!\r\n"
                         ,"_uac_wserv_jcs_rd_op",uVar13,pcVar10);
                }
              }
              else {
                if ((param_3 == 0) || (local_34 == (undefined4 *)iVar1)) {
                  local_3c = -1;
                  iVar1 = -1;
                  iVar4 = 0;
                  puVar17 = puVar3;
                  local_30 = puVar16;
                  do {
                    uVar2 = atoi((char *)*puVar17);
                    uVar8 = rdmngr_db_generate_ap_id(uVar2);
                    iVar5 = apmngr_db_entry_get_by_id(uVar8,auStack_318);
                    if (iVar5 == -1) {
                      if ((g_wserv_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                        iVar5 = rdmngr_db_generate_ap_id(uVar2);
                        pcVar10 = 
                        "<wserv>[error]%s(): %d  -> apmngr_db_entry_get_by_id() fail, ap_id=%d.\r\n"
                        ;
                        uVar13 = 0xcb9;
LAB_005da5a8:
                        printf(pcVar10,"_uac_wserv_jcs_rd_op",uVar13,iVar5);
                      }
                      break;
                    }
                    if (param_3 == 0) {
                      iVar1 = wserv_db_rd_unbind(uVar2,uVar13,_uac_wserv_del_cb);
                      if (((iVar1 == 0) && (g_wserv_debug != 0)) &&
                         (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                        uVar12 = *puVar17;
                        pcVar10 = "<wserv>[debug]%s(): %d  -> unbind rd_id[%s], wserv_id[%d].\r\n";
                        uVar11 = 0xcf4;
LAB_005da0cc:
                        printf(pcVar10,"_uac_wserv_jcs_rd_op",uVar11,uVar12,uVar13);
                      }
                    }
                    else {
                      local_3c = atoi((char *)*local_30);
                      local_40 = rdmngr_db_rd_entry_max_ssid_get(uVar2);
                      if (local_40 < 0) {
                        uVar2 = 0;
                        if (g_wserv_error != 0) {
                          iVar5 = is_target_debug_ap();
                          if (iVar5 != 0) {
                            pcVar10 = 
                            "<wserv>[error]%s(): %d  -> rdmngr_db_rd_entry_max_ssid_get() fail, max_ssid=%d.\r\n"
                            ;
                            uVar13 = 0xcc5;
                            iVar5 = local_40;
                            goto LAB_005da5a8;
                          }
                          puVar14 = (undefined1 *)0x0;
                          goto LAB_005da104;
                        }
                        break;
                      }
                      iVar1 = wserv_db_rd_wlan_binded_other_num(uVar2,uVar13);
                      if (local_40 <= iVar1) {
                        if ((g_wserv_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                          printf("<wserv>[error]%s(): %d  -> reach max ssid, wlan_cnt=%d, max_ssid=%d.\r\n"
                                 ,"_uac_wserv_jcs_rd_op",0xccb,iVar1,local_40);
                        }
                        uVar13 = rdmngr_db_get_rd_freq_band(uVar2);
                        pcVar10 = (char *)apdb_get_radio_freq_name_by_freq(uVar13);
                        if (pcVar10 == (char *)0x0) {
                          pcVar10 = "---";
                        }
                        snprintf(acStack_338,0x20,"(%s)",pcVar10);
                        uVar2 = uVar2 & 0xf;
                        puVar14 = auStack_2ca;
                        iVar1 = -0xd809;
                        goto LAB_005da104;
                      }
                      if ((g_wserv_debug != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                        printf("<wserv>[debug]%s(): %d  -> wlan_cnt=%d, max_ssid=%d.\r\n",
                               "_uac_wserv_jcs_rd_op",0xcdb,iVar1,local_40);
                      }
                      iVar1 = wserv_db_rd_bind(uVar2,uVar13,local_3c,_uac_wserv_add_cb);
                      if (((iVar1 == 0) && (g_wserv_debug != 0)) &&
                         (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                        uVar12 = *puVar17;
                        pcVar10 = 
                        "<wserv>[debug]%s(): %d  -> bind rd_id[%s], wserv_id[%d], vlan_id[%d].\r\n";
                        uVar11 = 0xcec;
                        goto LAB_005da0cc;
                      }
                    }
                    if (((local_304 == 1) || (local_304 == 3)) || (local_304 == 2)) {
                      local_34c = CONCAT22(local_308,local_34c._2_2_);
                      local_348 = _uac_wserv_add_cb;
                      local_344 = _uac_wserv_del_cb;
                      local_340 = local_38;
                      local_33c = &local_350;
                      wserv_db_sync_wlan_to_re(&local_34c);
                    }
                    if (iVar1 == -1) {
                      uVar2 = 0;
                      if (g_wserv_warning != 0) {
                        iVar5 = is_target_debug_ap();
                        if (iVar5 == 0) {
                          puVar14 = (undefined1 *)0x0;
                          goto LAB_005da104;
                        }
                        printf("<wserv>[warning]%s(): %d  -> wserv_db_rd_bind/unbind fail. rd_id[%s], wserv_id[%d], vlan_id[%d]\r\n"
                               ,"_uac_wserv_jcs_rd_op",0xd04,*puVar17,uVar13,local_3c);
                      }
                      break;
                    }
                    iVar4 = iVar4 + 1;
                    puVar17 = puVar17 + 1;
                    local_30 = local_30 + 1;
                  } while ((undefined4 *)iVar4 != local_34);
                  uVar2 = 0;
                  puVar14 = (undefined1 *)0x0;
                  goto LAB_005da104;
                }
                if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar9 = "<wserv>[error]%s(): %d  -> rd and vlan cnt not match!\r\n";
                  uVar13 = 0xcb0;
                  pcVar10 = pcVar15;
LAB_005da67c:
                  printf(pcVar9,"_uac_wserv_jcs_rd_op",uVar13);
                  pcVar15 = pcVar10;
                }
              }
            }
          }
          else {
            iVar1 = json_object_object_get(param_1,"vlan_id");
            if (iVar1 == 0) {
              puVar16 = (undefined4 *)0x0;
              if (g_wserv_error == 0) goto LAB_005da4ac;
              iVar1 = is_target_debug_ap();
              if (iVar1 != 0) {
                uVar13 = 0xc8a;
                pcVar15 = "vlan_id";
                goto LAB_005da62c;
              }
              goto LAB_005da4b0;
            }
            puVar16 = (undefined4 *)FUN_004082a0(0x3e9,4,0xc8c);
            if (puVar16 == (undefined4 *)0x0) {
              pcVar15 = (char *)0x0;
              if (g_wserv_error == 0) goto LAB_005da4b0;
              iVar1 = is_target_debug_ap();
              if (iVar1 != 0) {
                printf("<wserv>[error]%s(): %d  -> no memory!\r\n","_uac_wserv_jcs_rd_op",0xc8f);
              }
            }
            else {
              pcVar10 = (char *)FUN_00408450(0x1c16,0xc92);
              pcVar15 = pcVar10;
              if (pcVar10 == (char *)0x0) {
                if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  pcVar9 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                  uVar13 = 0xc95;
                  goto LAB_005da67c;
                }
              }
              else {
                memset(pcVar10,0,0x1c16);
                iVar4 = json_object_get_type(iVar1);
                if (iVar4 == 6) {
                  pcVar9 = (char *)json_object_get_string(iVar1);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_uac_wserv_jcs_rd_op",0xc99);
                  }
                  pcVar9 = "";
                }
                strncpy(pcVar10,pcVar9,0x1c15);
                pcVar10[0x1c15] = '\0';
                iVar1 = FUN_005d9d1c(pcVar10,puVar16,1000);
                if (0 < iVar1) goto LAB_005d9ed8;
                if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  uVar13 = 0xc9d;
                  goto LAB_005da3a0;
                }
              }
            }
          }
        }
      }
    }
  }
  uVar2 = 0;
  iVar1 = -1;
  puVar14 = (undefined1 *)0x0;
  iVar4 = 0;
LAB_005da104:
  local_34 = puVar3 + iVar4;
  local_40 = iVar4;
  for (local_3c = 0;
      (local_40 = local_40 + -1, local_40 != -1 &&
      (pcVar10 = *(char **)((int)local_34 + local_3c + -4), pcVar10 != (char *)0x0));
      local_3c = local_3c + -4) {
    iVar5 = atoi(pcVar10);
    uVar6 = rdmngr_db_generate_ap_id(iVar5);
    if ((-1 < (int)uVar6) && (iVar5 = apmngr_db_get_ap_max(), (int)uVar6 < iVar5)) {
      puVar18 = (uint *)(local_38 + ((int)uVar6 >> 5) * 4);
      uVar7 = *puVar18;
      if (((int)uVar7 >> (uVar6 & 0x1f) & 1U) == 0) {
        *puVar18 = uVar7 | 1 << (uVar6 & 0x1f);
        local_350 = local_350 + 1;
      }
    }
  }
  _uac_wserv_update_aps_md5(local_38,local_350);
  if (puVar3 != (undefined4 *)0x0) {
    FUN_00407df0(puVar3);
  }
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  if (puVar16 != (undefined4 *)0x0) {
    FUN_00407df0(puVar16);
  }
  if (pcVar15 != (char *)0x0) {
    FUN_00407df0(pcVar15);
  }
  if (local_38 != 0) {
    FUN_00407df0(local_38);
  }
  uVar13 = json_object_new_int(iVar1);
  json_object_object_add(param_2,"result",uVar13);
  if (iVar1 == -0xd809) {
    uVar13 = json_object_new_string(puVar14);
    json_object_object_add(param_2,"ap_name",uVar13);
    uVar13 = json_object_new_int(uVar2);
    json_object_object_add(param_2,"radio_id",uVar13);
    uVar13 = json_object_new_string(acStack_338);
    json_object_object_add(param_2,"freq_name",uVar13);
  }
  uVar13 = json_object_new_int(iVar4);
  json_object_object_add(param_2,"rd_num_binded",uVar13);
  return;
}

