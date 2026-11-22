// func _apdb_ap_list_parse @ 00600a58 size=3468

int _apdb_ap_list_parse(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  size_t sVar5;
  int *piVar6;
  char *pcVar7;
  char *__format;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  undefined1 *puVar15;
  char local_68 [16];
  undefined4 *local_58;
  int local_54;
  void *local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  iVar14 = 0;
  local_3c = cJSON_GetArraySize();
  local_54 = 0;
  local_4c = param_2;
LAB_00600ae4:
  if (local_3c <= local_54) {
    return iVar14;
  }
  puVar12 = (undefined4 *)(param_2 + iVar14 * 0x58);
  iVar1 = _apdb_fwid_hash_init(puVar12 + 0x14);
  if (iVar1 == 0) {
    local_50 = (void *)FUN_00408450(0x14,0xd54);
    if (local_50 == (void *)0x0) {
      if (apdb_err_switch != 0) {
        pcVar7 = "[APDB_ERROR]%s()/line %d : malloc error\n";
        uVar2 = 0xd57;
        goto LAB_00601184;
      }
      iVar1 = puVar12[0x15];
    }
    else {
      uVar2 = cJSON_GetArrayItem(param_1,local_54);
      pvVar3 = (void *)FUN_00408450(0x168,0xd5f);
      puVar12[0x15] = pvVar3;
      if (pvVar3 == (void *)0x0) {
        if (apdb_err_switch != 0) {
          pcVar7 = "[APDB_ERROR]%s()/line %d : malloc error\n";
          uVar2 = 0xd63;
          goto LAB_00601184;
        }
        iVar1 = puVar12[0x15];
      }
      else {
        memset(pvVar3,0,0x168);
        iVar10 = puVar12[0x15];
        local_68[0] = '\0';
        local_68[1] = '\0';
        local_68[2] = '\0';
        local_68[3] = '\0';
        local_68[4] = '\0';
        local_68[5] = '\0';
        local_68[6] = '\0';
        local_68[7] = '\0';
        local_68[8] = '\0';
        local_68[9] = '\0';
        local_68[10] = 0;
        iVar1 = cJSON_GetObjectItem(uVar2,"vendor");
        if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 3)) {
          if (apdb_err_switch == 0) goto LAB_00601240;
          pcVar7 = "[APDB_ERROR]%s()/line %d : parse vendor failed.\n";
          uVar2 = 0x785;
          goto LAB_006012a0;
        }
        if (vendor_type != *(int *)(iVar1 + 0x14)) {
          if (apdb_debug_switch != 0) {
            pcVar7 = "[APDB_DEBUG]%s()/line %d : unknown vendor.\n";
            uVar2 = 0x78a;
            goto LAB_006012a0;
          }
          goto LAB_00601240;
        }
        pcVar7 = (char *)(iVar10 + 0xb9);
        *(int *)(iVar10 + 0x18) = vendor_type;
        memset(pcVar7,0,0x21);
        iVar1 = cJSON_GetObjectItem(uVar2,"sales_method");
        if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 4)) {
          strncpy(pcVar7,*(char **)(iVar1 + 0x10),0x20);
        }
        iVar1 = _apdb_sales_method_match(pcVar7);
        if (iVar1 == 0) {
          if (apdb_debug_switch == 0) goto LAB_00601240;
          __format = "[APDB_DEBUG]%s()/line %d : Saled method(%s:%s) not match.\n";
          puVar15 = &sales_method;
          uVar2 = 0x79a;
LAB_0060155c:
          printf(__format,"_apdb_apdb_parse",uVar2,pcVar7,puVar15);
        }
        else {
          iVar1 = cJSON_GetObjectItem(uVar2,"id");
          if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 3)) {
            if (apdb_err_switch != 0) {
              pcVar7 = "[APDB_ERROR]%s()/line %d : parse ap model id failed.\n";
              uVar2 = 0x7a2;
              goto LAB_006012a0;
            }
          }
          else {
            *(undefined4 *)(iVar10 + 0x10) = *(undefined4 *)(iVar1 + 0x14);
            iVar1 = cJSON_GetObjectItem(uVar2,"version");
            if (iVar1 == 0) {
              *(undefined4 *)(iVar10 + 0x15c) = 0;
            }
            else if (*(int *)(iVar1 + 0xc) == 3) {
              *(undefined4 *)(iVar10 + 0x15c) = *(undefined4 *)(iVar1 + 0x14);
            }
            else {
              *(undefined4 *)(iVar10 + 0x15c) = 0;
            }
            iVar1 = cJSON_GetObjectItem(uVar2,"ap_name");
            if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 4)) {
              if (apdb_err_switch != 0) {
                pcVar7 = "[APDB_ERROR]%s()/line %d : Fail to parse ap_name from json\n";
                uVar2 = 0x7b9;
                goto LAB_006012a0;
              }
            }
            else {
              pcVar7 = (char *)(iVar10 + 0xda);
              strncpy(pcVar7,*(char **)(iVar1 + 0x10),0x40);
              iVar1 = FUN_00408710(pcVar7,0x41);
              if (iVar1 == 0) {
                iVar1 = cJSON_CreateString(pcVar7);
                if (iVar1 == 0) {
                  if (apdb_err_switch != 0) {
                    pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
                    uVar2 = 0x7c4;
                    goto LAB_006012a0;
                  }
                  goto LAB_00601240;
                }
                cJSON_ReplaceItemInObject(uVar2,"ap_name",iVar1);
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"ap_nickname");
              if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 4)) {
                pcVar7 = (char *)(iVar10 + 0x11b);
                strncpy(pcVar7,*(char **)(iVar1 + 0x10),0x40);
                iVar1 = FUN_00408710(pcVar7,0x41);
                if (iVar1 == 0) {
                  iVar1 = cJSON_CreateString(pcVar7);
                  if (iVar1 == 0) {
                    if (apdb_err_switch != 0) {
                      pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
                      uVar2 = 0x7d6;
                      goto LAB_006012a0;
                    }
                    goto LAB_00601240;
                  }
                  cJSON_ReplaceItemInObject(uVar2,"ap_nickname",iVar1);
                }
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"device_type");
              if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 4)) {
                strncpy((char *)(iVar10 + 0x98),*(char **)(iVar1 + 0x10),0x20);
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"ext_wire_phy");
              if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 3)) {
                *(undefined4 *)(iVar10 + 0x14) = 0;
              }
              else {
                *(undefined4 *)(iVar10 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"linked_modify_2.4G");
              if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 4)) {
                pvVar3 = (void *)(iVar10 + 0x20);
LAB_00600d54:
                memset(pvVar3,0,0x28);
              }
              else {
                sVar5 = strlen(*(char **)(iVar1 + 0x10));
                pcVar7 = (char *)FUN_00408450(sVar5 + 1,0x7fa);
                if (pcVar7 == (char *)0x0) {
                  pvVar3 = (void *)(iVar10 + 0x48);
                  goto LAB_00600d54;
                }
                snprintf(pcVar7,sVar5 + 1,"%s",*(undefined4 *)(iVar1 + 0x10));
                _apdb_parse_linked_modify_items(pcVar7,iVar10 + 0x20);
                FUN_00407df0(pcVar7);
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"linked_modify_5.0G");
              if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 4)) {
LAB_00600d88:
                memset((void *)(iVar10 + 0x48),0,0x28);
              }
              else {
                sVar5 = strlen(*(char **)(iVar1 + 0x10));
                pcVar7 = (char *)FUN_00408450(sVar5 + 1,0x813);
                if (pcVar7 == (char *)0x0) goto LAB_00600d88;
                snprintf(pcVar7,sVar5 + 1,"%s",*(undefined4 *)(iVar1 + 0x10));
                _apdb_parse_linked_modify_items(pcVar7,iVar10 + 0x48);
                FUN_00407df0(pcVar7);
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"is_hd_ap");
              if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 1)) {
                *(undefined4 *)(iVar10 + 0x1c) = 0;
              }
              else {
                *(undefined4 *)(iVar10 + 0x1c) = 1;
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"support_ap_trunk");
              if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 1)) {
                *(undefined4 *)(iVar10 + 0x70) = 0;
              }
              else {
                *(undefined4 *)(iVar10 + 0x70) = 1;
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"support_cloud_upgrade");
              if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 1)) {
                *(undefined4 *)(iVar10 + 0x74) = 0;
              }
              else {
                *(undefined4 *)(iVar10 + 0x74) = 1;
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"support_large_fw_upgrade");
              if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 1)) {
                *(undefined4 *)(iVar10 + 0x78) = 0;
              }
              else {
                *(undefined4 *)(iVar10 + 0x78) = 1;
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"is_mesh_device");
              if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 1)) {
                *(undefined4 *)(iVar10 + 0x7c) = 0;
              }
              else {
                *(undefined4 *)(iVar10 + 0x7c) = 1;
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"product_type");
              if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 3)) {
                *(undefined4 *)(iVar10 + 0x80) = 0;
              }
              else {
                pcVar7 = *(char **)(iVar1 + 0x14);
                if ((char *)0x3 < pcVar7) {
                  if (apdb_err_switch != 0) {
                    puVar15 = (undefined1 *)0xffffffff;
                    __format = 
                    "[APDB_ERROR]%s()/line %d : Illegal product type %d, need to in (%d, %d)\n";
                    uVar2 = 0x862;
                    goto LAB_0060155c;
                  }
                  goto LAB_00601240;
                }
                *(char **)(iVar10 + 0x80) = pcVar7;
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"hardware_id");
              memset((void *)(iVar10 + 0x84),0,0x10);
              if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 4)) {
                pcVar7 = *(char **)(iVar1 + 0x10);
                sVar5 = strlen(pcVar7);
                FUN_00408280((void *)(iVar10 + 0x84),pcVar7,sVar5);
              }
              iVar1 = cJSON_GetObjectItem(uVar2,"models");
              if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 5)) {
                if (apdb_err_switch != 0) {
                  pcVar7 = "[APDB_ERROR]%s()/line %d : Fail to get models from json\n";
                  uVar2 = 0x873;
LAB_006012a0:
                  printf(pcVar7,"_apdb_apdb_parse",uVar2);
                }
              }
              else {
                *(undefined4 *)(iVar10 + 0x94) = param_3;
                iVar4 = cJSON_GetArraySize(iVar1);
                *(int *)(iVar10 + 0x160) = iVar4;
                if (iVar4 - 1U < 5) {
                  pvVar3 = (void *)FUN_00408450(iVar4 * 0x38,0x87f);
                  *(void **)(iVar10 + 0x164) = pvVar3;
                  if (pvVar3 == (void *)0x0) {
                    if (apdb_err_switch != 0) {
                      pcVar7 = "[APDB_ERROR]%s()/line %d : Malloc failed\n";
                      uVar2 = 0x882;
                      goto LAB_006012a0;
                    }
                  }
                  else {
                    iVar4 = 0;
                    memset(pvVar3,0,*(int *)(iVar10 + 0x160) * 0x38);
                    local_58 = puVar12;
                    local_38 = iVar1;
                    while( true ) {
                      puVar12 = local_58;
                      if (*(int *)(iVar10 + 0x160) <= iVar4) goto LAB_0060165c;
                      uVar2 = cJSON_GetArrayItem(local_38,iVar4);
                      iVar1 = cJSON_GetObjectItem(uVar2,"hwver");
                      if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 4)) break;
                      iVar11 = iVar4 * 0x38;
                      strncpy(local_68,*(char **)(iVar1 + 0x10),10);
                      _apdb_parse_hwver(local_68,*(int *)(iVar10 + 0x164) + iVar11);
                      *(undefined4 *)(*(int *)(iVar10 + 0x164) + iVar11 + 0x24) = param_3;
                      iVar1 = cJSON_GetObjectItem(uVar2,"port_info");
                      if (iVar1 != 0) {
                        if (apdb_debug_switch == 0) {
                          iVar8 = *(int *)(iVar10 + 0x164);
                        }
                        else {
                          printf("[APDB_DEBUG]%s()/line %d : FIND port_info field,model_id=%d\n",
                                 "_apdb_apdb_parse",0x8a2,*(undefined4 *)(iVar10 + 0x10));
                          iVar8 = *(int *)(iVar10 + 0x164);
                        }
                        iVar1 = _apdb_port_info_prase_from_json(iVar1,iVar8 + iVar11);
                        puVar12 = local_58;
                        if (iVar1 == -1) {
                          if (apdb_err_switch != 0) {
                            printf("[APDB_ERROR]%s()/line %d : _apdb_port_info_prase_from_json fail\n"
                                   ,"_apdb_apdb_parse",0x8a5);
                          }
                          goto LAB_00601248;
                        }
                      }
                      iVar1 = cJSON_GetObjectItem(uVar2,"radios");
                      if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 6)) {
                        puVar12 = local_58;
                        if (apdb_err_switch != 0) {
                          pcVar7 = "[APDB_ERROR]%s()/line %d : Fail to get radios\n";
                          uVar2 = 0x8ad;
                          goto LAB_00601444;
                        }
                        goto LAB_00601450;
                      }
                      iVar8 = *(int *)(iVar10 + 0x164);
                      uVar2 = cJSON_GetArraySize(iVar1);
                      puVar12 = local_58;
                      *(undefined4 *)(iVar8 + iVar11 + 0x10) = uVar2;
                      iVar9 = *(int *)(iVar10 + 0x164) + iVar11;
                      iVar8 = *(int *)(iVar9 + 0x10);
                      if (7 < iVar8 - 1U) {
                        if (apdb_err_switch != 0) {
                          printf("[APDB_ERROR]%s()/line %d : Radio cnt %d exceeds or zero\n",
                                 "_apdb_apdb_parse",0x8b4);
                        }
                        goto LAB_00601450;
                      }
                      uVar2 = FUN_00408450(iVar8 * 0x114,0x8b7);
                      *(undefined4 *)(iVar9 + 0x28) = uVar2;
                      iVar8 = *(int *)(iVar10 + 0x164) + iVar11;
                      pvVar3 = *(void **)(iVar8 + 0x28);
                      if (pvVar3 == (void *)0x0) {
                        puVar12 = local_58;
                        if (apdb_err_switch != 0) {
                          pcVar7 = "[APDB_ERROR]%s()/line %d : Malloc failed\n";
                          uVar2 = 0x8ba;
                          goto LAB_00601444;
                        }
                        goto LAB_00601450;
                      }
                      iVar13 = 0;
                      iVar9 = 0;
                      memset(pvVar3,0,*(int *)(iVar8 + 0x10) * 0x114);
                      local_40 = 0;
                      local_44 = 0;
                      local_48 = 0;
                      local_34 = iVar4;
                      local_30 = iVar1;
                      while (iVar1 = *(int *)(iVar10 + 0x164) + iVar11,
                            iVar9 < *(int *)(iVar1 + 0x10)) {
                        iVar1 = cJSON_GetArrayItem(local_30,iVar9);
                        puVar12 = local_58;
                        if (iVar1 == 0) {
                          if (apdb_err_switch != 0) {
                            printf("[APDB_ERROR]%s()/line %d : get radio failed.\n",
                                   "_apdb_apdb_parse",0x8c5);
                          }
LAB_006013d4:
                          iVar1 = 0;
                          while (iVar1 < iVar9) {
                            iVar8 = iVar1 * 0x114;
                            iVar4 = *(int *)(*(int *)(*(int *)(iVar10 + 0x164) + iVar11 + 0x28) +
                                             iVar8 + 0x110);
                            iVar1 = iVar1 + 1;
                            if (iVar4 != 0) {
                              FUN_00407df0(iVar4,1);
                              *(undefined4 *)
                               (*(int *)(*(int *)(iVar10 + 0x164) + iVar11 + 0x28) + iVar8 + 0x110)
                                   = 0;
                            }
                          }
                          goto LAB_00601450;
                        }
                        iVar4 = _apdb_radio_freq_string_to_enum(*(undefined4 *)(iVar1 + 0x20));
                        iVar8 = iVar9 * 0x114;
                        *(int *)(*(int *)(*(int *)(iVar10 + 0x164) + iVar11 + 0x28) + iVar8) = iVar4
                        ;
                        iVar1 = _apdb_parse_radio(iVar1,*(int *)(*(int *)(iVar10 + 0x164) + iVar11 +
                                                                0x28) + iVar8);
                        puVar12 = local_58;
                        if (iVar1 == -1) {
                          if (apdb_err_switch != 0) {
                            printf("[APDB_ERROR]%s()/line %d : parse radio for ap(0x%x)\n",
                                   "_apdb_apdb_parse",0x8ce,*(undefined4 *)(iVar10 + 0x10));
                          }
                          goto LAB_006013d4;
                        }
                        piVar6 = *(int **)(*(int *)(*(int *)(iVar10 + 0x164) + iVar11 + 0x28) +
                                           iVar8 + 0x110);
                        iVar1 = -1;
                        if (piVar6 != (int *)0x0) {
                          iVar1 = *piVar6;
                        }
                        if ((iVar4 == 0) || (iVar1 == 0)) {
                          iVar9 = iVar9 + 1;
                          local_44 = 1;
                          local_48 = local_48 + 1;
                        }
                        else if ((iVar4 == 1) || (iVar1 == 1)) {
                          iVar13 = iVar13 + 1;
                          local_40 = 1;
                          iVar9 = iVar9 + 1;
                        }
                        else {
                          iVar9 = iVar9 + 1;
                        }
                      }
                      *(int *)(iVar1 + 8) = local_48;
                      iVar4 = local_34 + 1;
                      *(int *)(*(int *)(iVar10 + 0x164) + iVar11 + 0xc) = iVar13;
                      *(undefined4 *)(*(int *)(iVar10 + 0x164) + iVar11 + 0x1c) = local_44;
                      *(undefined4 *)(*(int *)(iVar10 + 0x164) + iVar11 + 0x18) = local_40;
                    }
                    puVar12 = local_58;
                    if (apdb_err_switch != 0) {
                      pcVar7 = "[APDB_ERROR]%s()/line %d : Failed to get hwver\n";
                      uVar2 = 0x893;
LAB_00601444:
                      puVar12 = local_58;
                      printf(pcVar7,"_apdb_apdb_parse",uVar2);
                    }
LAB_00601450:
                    _apdb_ap_model_free(iVar10,1);
                  }
                }
                else if (apdb_err_switch != 0) {
                  printf("[APDB_ERROR]%s()/line %d : Model cnt %d exceeds or zero\n",
                         "_apdb_apdb_parse",0x87c,iVar4);
                }
              }
            }
          }
        }
LAB_00601240:
        _apdb_ap_model_free(iVar10,1);
LAB_00601248:
        if (apdb_err_switch != 0) {
          pcVar7 = "[APDB_ERROR]%s()/line %d : parse apdb_list failed \n";
          uVar2 = 0xd6d;
          goto LAB_00601184;
        }
        iVar1 = puVar12[0x15];
      }
    }
  }
  else {
    if (apdb_err_switch == 0) {
      iVar1 = puVar12[0x15];
      goto LAB_00600abc;
    }
    pcVar7 = "[APDB_ERROR]%s()/line %d : init hash failed!\n";
    uVar2 = 0xd4f;
LAB_00601184:
    printf(pcVar7,"_apdb_ap_list_parse",uVar2);
    iVar1 = puVar12[0x15];
  }
LAB_00600abc:
  if (iVar1 != 0) {
    _apdb_ap_free(iVar1,puVar12[0x13]);
  }
  goto LAB_00600ad0;
LAB_0060165c:
  if (apdb_debug_switch == 0) {
    iVar1 = local_58[0x15];
  }
  else {
    printf("[APDB_DEBUG]%s()/line %d : parse one aps.\n","_apdb_apdb_parse",0x8ed);
    iVar1 = puVar12[0x15];
  }
  puVar12[0x13] = 1;
  iVar14 = iVar14 + 1;
  *puVar12 = *(undefined4 *)(iVar1 + 0x10);
  memcpy(puVar12 + 2,(void *)(iVar1 + 0xda),0x40);
  memset(local_50,0xff,0x10);
  *(undefined4 *)((int)local_50 + 0x10) = 0;
  FUN_00408380(*(undefined4 *)(local_4c + 0x50),local_50);
LAB_00600ad0:
  local_54 = local_54 + 1;
  local_4c = local_4c + 0x58;
  goto LAB_00600ae4;
}

