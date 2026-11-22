// func FUN_006038e0 @ 006038e0 size=10400

int FUN_006038e0(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar15;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  int iVar13;
  size_t sVar14;
  int *piVar16;
  int iVar17;
  char *pcVar18;
  undefined4 uVar19;
  int iVar20;
  size_t sVar21;
  void *pvVar22;
  FILE *__s;
  int iVar23;
  int iVar24;
  undefined8 uVar25;
  undefined1 *puVar26;
  char *local_1a0;
  char *local_19c;
  char *local_198;
  int local_194;
  char local_190 [12];
  char local_184 [36];
  char acStack_160 [200];
  void *local_98;
  int local_94;
  void *local_90;
  undefined4 local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  
  local_58 = FUN_005fc534();
  if (local_58 == 0) {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : Not get nego db, create default\n\n",
             "_apdb_load_json_nego_db",0x1098);
    }
    _apdb_init_json_mem();
    return 0;
  }
  local_94 = cJSON_Parse(local_58);
  if (local_94 == 0) {
    if (apdb_err_switch == 0) goto LAB_00603b68;
    pcVar18 = "[APDB_ERROR]%s()/line %d : Fail to parse JSON.\n";
    uVar19 = 0x1008;
LAB_00603b60:
    printf(pcVar18,"_apdb_init_nego_db",uVar19);
LAB_00603b68:
    iVar3 = _apdb_init_json_mem();
    if (local_94 != 0) {
      cJSON_Delete(local_94);
    }
    if (iVar3 == 0) goto LAB_00603c40;
    if (apdb_err_switch == 0) goto LAB_00603b9c;
    pcVar18 = "[APDB_ERROR]%s()/line %d : Failed to initialize apdb.\n";
    uVar19 = 0x10a1;
  }
  else {
    iVar3 = cJSON_GetObjectItem(local_94,"ap_item_list");
    if (iVar3 == 0) {
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : Fail to parse new JSON.\n","_apdb_init_nego_db",0x1010);
      }
      iVar3 = cJSON_GetObjectItem(local_94,"ap_list");
      if (iVar3 == 0) {
        if (apdb_debug_switch != 0) {
          pcVar18 = "[APDB_DEBUG]%s()/line %d : Fail to parse old JSON\n";
          uVar19 = 0x1015;
          goto LAB_00603b60;
        }
        goto LAB_00603b68;
      }
      iVar3 = cJSON_GetArraySize(iVar3);
      local_194 = 0;
      iVar5 = cJSON_GetObjectItem(local_94,"ap_list");
      if (iVar5 != 0) {
        iVar6 = cJSON_GetArraySize(iVar5);
        pvVar7 = (void *)FUN_00408450(iVar6 * 0x58,0xf97);
        if (pvVar7 == (void *)0x0) {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : Failed to malloc memory for apdb_ap_item.\n",
                   "convert_old_json_to_new",0xf9a);
          }
        }
        else {
          memset(pvVar7,0,iVar6 * 0x58);
          iVar5 = _apdb_ap_list_parse(iVar5,pvVar7,1);
          if (iVar5 == -1) {
            iVar5 = local_94;
            if (apdb_err_switch != 0) {
              printf("[APDB_ERROR]%s()/line %d : apdb parse item list error\n",
                     "convert_old_json_to_new",0xfa2);
              iVar5 = local_94;
            }
LAB_00605828:
            cJSON_Delete(iVar5);
            iVar5 = -1;
          }
          else {
            cJSON_Delete(local_94);
            iVar5 = cJSON_CreateObject();
            if (iVar5 != 0) {
              iVar8 = cJSON_CreateArray();
              if (iVar8 == 0) {
                if (apdb_err_switch != 0) {
                  pcVar18 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
                  uVar19 = 0xfb8;
LAB_00605950:
                  printf(pcVar18,"convert_old_json_to_new",uVar19);
                }
              }
              else {
                uVar25 = __floatsidf(vendor_type);
                iVar9 = cJSON_CreateNumber((int)((ulonglong)uVar25 >> 0x20),(int)uVar25);
                if (iVar9 == 0) {
                  if (apdb_err_switch != 0) {
                    pcVar18 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
                    uVar19 = 0xfc1;
                    goto LAB_00605950;
                  }
                }
                else {
                  cJSON_AddItemToObject(iVar5,"vendor",iVar9);
                  cJSON_AddItemToObject(iVar5,"ap_item_list",iVar8);
                  iVar8 = cJSON_GetObjectItem(iVar5,"ap_item_list");
                  if (iVar8 != 0) {
                    pvVar22 = pvVar7;
                    for (iVar5 = 0; iVar5 < iVar6; iVar5 = iVar5 + 1) {
                      _apdb_add_item_to_list(&local_194,pvVar22);
                      pvVar22 = (void *)((int)pvVar22 + 0x58);
                      cJSON_AddItemToArray(iVar8,local_194);
                      local_194 = 0;
                    }
                    iVar5 = 0;
                    goto LAB_0060488c;
                  }
                  if (apdb_err_switch != 0) {
                    pcVar18 = "[APDB_ERROR]%s()/line %d : get apdb item json failed\n";
                    uVar19 = 0xfce;
                    goto LAB_00605950;
                  }
                }
              }
              goto LAB_00605828;
            }
            if (apdb_err_switch == 0) {
              iVar5 = -1;
            }
            else {
              printf("[APDB_ERROR]%s()/line %d : Failed create root obj.\n",
                     "convert_old_json_to_new",0xfb0);
              iVar5 = -1;
            }
          }
LAB_0060488c:
          FUN_00407df0(pvVar7);
          if (iVar5 == 0) goto LAB_00603954;
        }
      }
      if (apdb_err_switch != 0) {
        pcVar18 = "[APDB_ERROR]%s()/line %d : Fail to convert JSON.\n";
        uVar19 = 0x101c;
        goto LAB_00603b60;
      }
      goto LAB_00603b68;
    }
    iVar3 = cJSON_GetArraySize(iVar3);
LAB_00603954:
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : max ap count is : %d \n","_apdb_init_nego_db",0x1026,iVar3)
      ;
      if (0 < iVar3) goto LAB_00603964;
      goto LAB_00603b68;
    }
    if (iVar3 < 1) goto LAB_00603b68;
LAB_00603964:
    local_54 = cJSON_GetObjectItem(local_94,"ap_item_list");
    if (local_54 == 0) {
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : ap list null\n","_apdb_nego_json_parse",0xdea);
      }
LAB_00604b64:
      if (apdb_err_switch != 0) {
        pcVar18 = "[APDB_ERROR]%s()/line %d : get json information failed.\n";
        uVar19 = 0x1031;
        goto LAB_00603b60;
      }
      goto LAB_00603b68;
    }
    iVar3 = cJSON_GetObjectItem(local_94,"vendor");
    if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 3)) {
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : apdb vendor error.\n","_apdb_nego_json_parse",0xdf4);
      }
    }
    else if (vendor_type != *(int *)(iVar3 + 0x14)) {
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : apdb vendor not match[%d/%d].\n","_apdb_nego_json_parse",
               0xdf8,*(int *)(iVar3 + 0x14),vendor_type);
      }
      goto LAB_00604b64;
    }
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : enter _apdb_ap_item_list_parse\n",
             "_apdb_ap_item_list_parse",0xcbb);
    }
    local_184[0] = '\0';
    local_184[1] = '\0';
    local_184[2] = '\0';
    local_184[3] = '\0';
    local_184[4] = '\0';
    local_184[5] = '\0';
    local_184[6] = '\0';
    local_184[7] = '\0';
    local_184[8] = '\0';
    local_184[9] = '\0';
    local_184[10] = '\0';
    local_184[0xb] = '\0';
    local_184[0xc] = '\0';
    local_184[0xd] = '\0';
    local_184[0xe] = '\0';
    local_184[0xf] = '\0';
    local_3c = cJSON_GetArraySize(local_54);
    local_74 = 0;
    local_70 = 0;
    local_90 = (void *)0x0;
    for (local_7c = 0; local_7c < local_3c; local_7c = local_7c + 1) {
      local_50 = cJSON_GetArrayItem(local_54,local_7c);
      iVar3 = cJSON_GetObjectItem(local_50,"id");
      if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 3)) {
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : parse ap model id failed.\n","_apdb_ap_item_list_parse"
                 ,0xcd9);
        }
        if (local_90 != (void *)0x0) {
          _apdb_ap_free(local_90,local_74);
        }
        goto LAB_00604b64;
      }
      local_38 = *(undefined4 *)(iVar3 + 0x14);
      local_78 = cJSON_GetObjectItem(local_50,"ap_list");
      if (local_78 == 0) {
LAB_006041ec:
        iVar3 = cJSON_GetObjectItem(local_50,"fwid_list");
        if (iVar3 == 0) {
          if (apdb_debug_switch != 0) {
            pcVar18 = "[APDB_DEBUG]%s()/line %d : prase ap failed \n";
            uVar19 = 0xcf9;
LAB_006042fc:
            printf(pcVar18,"_apdb_ap_item_list_parse",uVar19);
          }
        }
        else {
          iVar5 = cJSON_GetArraySize(iVar3);
          for (iVar6 = 0; iVar6 < iVar5; iVar6 = iVar6 + 1) {
            uVar19 = cJSON_GetArrayItem(iVar3,iVar6);
            iVar8 = cJSON_GetObjectItem(uVar19,&DAT_006fc224);
            iVar9 = cJSON_GetObjectItem(uVar19,"ap_index");
            if ((iVar8 == 0) || (iVar9 == 0)) {
              if (apdb_debug_switch == 0) goto LAB_006042bc;
              pcVar18 = "[APDB_DEBUG]%s()/line %d : the fwid_json or ap_index_json is NULL \n";
              uVar19 = 0xd0b;
              goto LAB_006042fc;
            }
            pcVar18 = *(char **)(iVar8 + 0x10);
            sVar21 = strlen(pcVar18);
            FUN_00408280(local_184,pcVar18,sVar21);
            _apdb_add_ap_to_item_list
                      (local_38,local_184,(void *)((int)local_90 + *(int *)(iVar9 + 0x14) * 0x168),1
                      );
          }
          local_70 = local_70 + 1;
          if (apdb_debug_switch != 0) {
            printf("[APDB_DEBUG]%s()/line %d : parse %d apitems.\n","_apdb_ap_item_list_parse",0xd1c
                   ,local_70);
          }
        }
LAB_006042bc:
        if (local_90 != (void *)0x0) {
          _apdb_ap_free(local_90,local_74);
        }
      }
      else {
        local_74 = cJSON_GetArraySize(local_78);
        sVar21 = local_74 * 0x168;
        local_90 = (void *)FUN_00408450(sVar21,0xce7);
        if (local_90 != (void *)0x0) {
          memset(local_90,0,sVar21);
          local_190[0] = '\0';
          local_190[1] = '\0';
          local_190[2] = '\0';
          local_190[3] = '\0';
          local_190[4] = '\0';
          local_190[5] = '\0';
          local_190[6] = '\0';
          local_190[7] = '\0';
          local_190[8] = '\0';
          local_190[9] = '\0';
          local_190[10] = 0;
          local_194 = 0;
          local_34 = cJSON_GetArraySize(local_78);
          local_84 = 0;
          local_6c = 0;
LAB_00603ab8:
          if (local_6c < local_34) {
            uVar19 = cJSON_GetArrayItem(local_78,local_6c);
            iVar3 = cJSON_GetObjectItem(uVar19,"vendor");
            iVar5 = FUN_00407e10(iVar3,&local_194);
            if ((iVar5 != 0) || (vendor_type != local_194)) {
              if (apdb_debug_switch != 0) {
                printf("[APDB_DEBUG]%s()/line %d : parse vendor failed or unknown vendor.\n",
                       "_apdb_aplist_parse",0xb34);
              }
              goto LAB_00603ab0;
            }
            pvVar7 = (void *)((int)local_90 + local_84 * 0x168);
            pvVar22 = (void *)((int)pvVar7 + 0xb9);
            *(undefined4 *)((int)pvVar7 + 0x18) = *(undefined4 *)(iVar3 + 0x14);
            memset(pvVar22,0,0x21);
            uVar4 = cJSON_GetObjectItem(uVar19,"sales_method");
            iVar3 = FUN_00407ef0(uVar4,pvVar22,0x20);
            if ((iVar3 != 0) && (apdb_debug_switch != 0)) {
              printf("[APDB_DEBUG]%s()/line %d : Fail to parse saled method from json\n",
                     "_apdb_aplist_parse",0xb40);
            }
            iVar3 = _apdb_sales_method_match(pvVar22);
            if (iVar3 == 0) {
              if (apdb_debug_switch == 0) goto LAB_00603ab0;
              pcVar18 = "[APDB_DEBUG]%s()/line %d : Saled method(%s:%s) not match.\n";
              puVar26 = &sales_method;
              uVar19 = 0xb44;
LAB_00603d54:
              printf(pcVar18,"_apdb_aplist_parse",uVar19,pvVar22,puVar26);
              goto LAB_00603ab0;
            }
            uVar4 = cJSON_GetObjectItem(uVar19,"id");
            iVar3 = FUN_00407e10(uVar4,(int)pvVar7 + 0x10);
            if (iVar3 != 0) {
              if (apdb_err_switch != 0) {
                pcVar18 = "[APDB_ERROR]%s()/line %d : Fail to parse id from json\n";
                uVar19 = 0xb4c;
LAB_006059ac:
                printf(pcVar18,"_apdb_aplist_parse",uVar19);
              }
LAB_006041e0:
              _apdb_ap_model_free(local_90,local_84);
              goto LAB_006041ec;
            }
            uVar4 = cJSON_GetObjectItem(uVar19,"version");
            iVar3 = FUN_00407e10(uVar4,(int)pvVar7 + 0x15c);
            if (iVar3 != 0) {
              if (apdb_debug_switch == 0) {
                *(undefined4 *)((int)pvVar7 + 0x15c) = 0;
              }
              else {
                printf("[APDB_DEBUG]%s()/line %d : Fail to parse version from json\n",
                       "_apdb_aplist_parse",0xb54);
                *(undefined4 *)((int)pvVar7 + 0x15c) = 0;
              }
            }
            iVar5 = (int)pvVar7 + 0xda;
            uVar4 = cJSON_GetObjectItem(uVar19,"ap_name");
            iVar3 = FUN_00407ef0(uVar4,iVar5,0x40);
            if ((iVar3 == 0) && (iVar3 = FUN_00408710(iVar5,0x41), iVar3 == 0)) {
              iVar3 = cJSON_CreateString(iVar5);
              if (iVar3 == 0) {
                if (apdb_err_switch != 0) {
                  pcVar18 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
                  uVar19 = 0xb61;
                  goto LAB_006059ac;
                }
                goto LAB_006041e0;
              }
              cJSON_ReplaceItemInObject(uVar19,"ap_name",iVar3);
            }
            iVar5 = (int)pvVar7 + 0x11b;
            uVar4 = cJSON_GetObjectItem(uVar19,"ap_nickname");
            iVar3 = FUN_00407ef0(uVar4,iVar5,0x40);
            if ((iVar3 == 0) && (iVar3 = FUN_00408710(iVar5,0x41), iVar3 == 0)) {
              iVar3 = cJSON_CreateString(iVar5);
              if (iVar3 == 0) {
                if (apdb_err_switch != 0) {
                  pcVar18 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
                  uVar19 = 0xb72;
                  goto LAB_006059ac;
                }
                goto LAB_006041e0;
              }
              cJSON_ReplaceItemInObject(uVar19,"ap_nickname",iVar3);
            }
            uVar4 = cJSON_GetObjectItem(uVar19,"device_type");
            FUN_00407ef0(uVar4,(int)pvVar7 + 0x98,0x20);
            uVar4 = cJSON_GetObjectItem(uVar19,"ext_wire_phy");
            iVar3 = FUN_00407e10(uVar4,(int)pvVar7 + 0x14);
            if (iVar3 != 0) {
              *(undefined4 *)((int)pvVar7 + 0x14) = 0;
            }
            iVar3 = cJSON_GetObjectItem(uVar19,"linked_modify_2.4G");
            if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 4)) {
              pvVar22 = (void *)((int)pvVar7 + 0x20);
LAB_00603ec0:
              memset(pvVar22,0,0x28);
            }
            else {
              sVar21 = strlen(*(char **)(iVar3 + 0x10));
              pcVar18 = (char *)FUN_00408450(sVar21 + 1,0xb8f);
              if (pcVar18 == (char *)0x0) {
                pvVar22 = (void *)((int)pvVar7 + 0x48);
                goto LAB_00603ec0;
              }
              snprintf(pcVar18,sVar21 + 1,"%s",*(undefined4 *)(iVar3 + 0x10));
              _apdb_parse_linked_modify_items(pcVar18,(int)pvVar7 + 0x20);
              FUN_00407df0(pcVar18);
            }
            iVar3 = cJSON_GetObjectItem(uVar19,"linked_modify_5.0G");
            if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 4)) {
LAB_00603ef4:
              memset((void *)((int)pvVar7 + 0x48),0,0x28);
            }
            else {
              sVar21 = strlen(*(char **)(iVar3 + 0x10));
              pcVar18 = (char *)FUN_00408450(sVar21 + 1,0xba8);
              if (pcVar18 == (char *)0x0) goto LAB_00603ef4;
              snprintf(pcVar18,sVar21 + 1,"%s",*(undefined4 *)(iVar3 + 0x10));
              _apdb_parse_linked_modify_items(pcVar18,(int)pvVar7 + 0x48);
              FUN_00407df0(pcVar18);
            }
            iVar3 = cJSON_GetObjectItem(uVar19,"is_hd_ap");
            if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 1)) {
              *(undefined4 *)((int)pvVar7 + 0x1c) = 0;
            }
            else {
              *(undefined4 *)((int)pvVar7 + 0x1c) = 1;
            }
            iVar3 = cJSON_GetObjectItem(uVar19,"support_ap_trunk");
            if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 1)) {
              *(undefined4 *)((int)pvVar7 + 0x70) = 0;
            }
            else {
              *(undefined4 *)((int)pvVar7 + 0x70) = 1;
            }
            iVar3 = cJSON_GetObjectItem(uVar19,"support_cloud_upgrade");
            if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 1)) {
              *(undefined4 *)((int)pvVar7 + 0x74) = 0;
            }
            else {
              *(undefined4 *)((int)pvVar7 + 0x74) = 1;
            }
            iVar3 = cJSON_GetObjectItem(uVar19,"support_large_fw_upgrade");
            if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 1)) {
              *(undefined4 *)((int)pvVar7 + 0x78) = 0;
            }
            else {
              *(undefined4 *)((int)pvVar7 + 0x78) = 1;
            }
            iVar3 = cJSON_GetObjectItem(uVar19,"is_mesh_device");
            if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 1)) {
              *(undefined4 *)((int)pvVar7 + 0x7c) = 0;
            }
            else {
              *(undefined4 *)((int)pvVar7 + 0x7c) = 1;
            }
            iVar3 = cJSON_GetObjectItem(uVar19,"product_type");
            if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 3)) {
              *(undefined4 *)((int)pvVar7 + 0x80) = 0;
            }
            else {
              pvVar22 = *(void **)(iVar3 + 0x14);
              if ((void *)0x3 < pvVar22) {
                if (apdb_err_switch == 0) goto LAB_00603ab0;
                puVar26 = (undefined1 *)0xffffffff;
                pcVar18 = 
                "[APDB_ERROR]%s()/line %d : Illegal product type %d, need to in (%d, %d)\n";
                uVar19 = 0xbf7;
                goto LAB_00603d54;
              }
              *(void **)((int)pvVar7 + 0x80) = pvVar22;
            }
            iVar3 = cJSON_GetObjectItem(uVar19,"hardware_id");
            memset((void *)((int)pvVar7 + 0x84),0,0x10);
            if ((iVar3 != 0) && (*(int *)(iVar3 + 0xc) == 4)) {
              pcVar18 = *(char **)(iVar3 + 0x10);
              sVar21 = strlen(pcVar18);
              FUN_00408280((void *)((int)pvVar7 + 0x84),pcVar18,sVar21);
            }
            local_68 = cJSON_GetObjectItem(uVar19,"models");
            if ((local_68 == 0) || (*(int *)(local_68 + 0xc) != 5)) {
              if (apdb_err_switch != 0) {
                pcVar18 = "[APDB_ERROR]%s()/line %d : Fail to get models from json\n";
                uVar19 = 0xc08;
                goto LAB_006059ac;
              }
            }
            else {
              *(undefined4 *)((int)pvVar7 + 0x94) = 1;
              iVar3 = cJSON_GetArraySize(local_68);
              *(int *)((int)pvVar7 + 0x160) = iVar3;
              if (iVar3 - 1U < 5) {
                pvVar22 = (void *)FUN_00408450(iVar3 * 0x38,0xc14);
                *(void **)((int)pvVar7 + 0x164) = pvVar22;
                if (pvVar22 == (void *)0x0) {
                  if (apdb_err_switch != 0) {
                    pcVar18 = "[APDB_ERROR]%s()/line %d : Malloc failed\n";
                    uVar19 = 0xc17;
                    goto LAB_006059ac;
                  }
                }
                else {
                  memset(pvVar22,0,*(int *)((int)pvVar7 + 0x160) * 0x38);
                  local_80 = 0;
LAB_006040a8:
                  if (*(int *)((int)pvVar7 + 0x160) <= local_80) goto LAB_00605a54;
                  local_8c = cJSON_GetArrayItem(local_68,local_80);
                  iVar3 = cJSON_GetObjectItem(local_8c,"hwver");
                  if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 4)) {
                    if (apdb_err_switch != 0) {
                      pcVar18 = "[APDB_ERROR]%s()/line %d : Failed to get hwver\n";
                      uVar19 = 0xc28;
LAB_0060453c:
                      printf(pcVar18,"_apdb_aplist_parse",uVar19);
                    }
                    goto LAB_006041d4;
                  }
                  strncpy(local_190,*(char **)(iVar3 + 0x10),10);
                  iVar3 = local_80 * 0x38;
                  _apdb_parse_hwver(local_190,*(int *)((int)pvVar7 + 0x164) + iVar3);
                  *(undefined4 *)(*(int *)((int)pvVar7 + 0x164) + iVar3 + 0x24) = 1;
                  iVar5 = cJSON_GetObjectItem(local_8c,"port_info");
                  if (iVar5 != 0) {
                    if (apdb_debug_switch == 0) {
                      iVar6 = *(int *)((int)pvVar7 + 0x164);
                    }
                    else {
                      printf("[APDB_DEBUG]%s()/line %d : FIND port_info field,model_id=%d\n",
                             "_apdb_aplist_parse",0xc37,*(undefined4 *)((int)pvVar7 + 0x10));
                      iVar6 = *(int *)((int)pvVar7 + 0x164);
                    }
                    iVar5 = _apdb_port_info_prase_from_json(iVar5,iVar6 + iVar3);
                    if (iVar5 == -1) {
                      if (apdb_err_switch != 0) {
                        pcVar18 = 
                        "[APDB_ERROR]%s()/line %d : _apdb_port_info_prase_from_json fail\n";
                        uVar19 = 0xc3a;
                        goto LAB_0060453c;
                      }
                      goto LAB_006041d4;
                    }
                  }
                  iVar5 = cJSON_GetObjectItem(local_8c,"region_list");
                  if (iVar5 != 0) {
                    if (apdb_debug_switch != 0) {
                      printf("[APDB_DEBUG]%s()/line %d : FIND region list field,model_id=%d\n",
                             "_apdb_aplist_parse",0xc42,*(undefined4 *)((int)pvVar7 + 0x10));
                    }
                    iVar6 = *(int *)((int)pvVar7 + 0x164);
                    if (apdb_debug_switch == 0) {
                      iVar8 = *(int *)(iVar5 + 0xc);
                    }
                    else {
                      printf("[APDB_DEBUG]%s()/line %d : _apdb_region_list_parse_from_json ENTER\n",
                             "_apdb_region_list_parse_from_json",0xab0);
                      iVar8 = *(int *)(iVar5 + 0xc);
                    }
                    if ((iVar8 != 5) || (iVar6 = iVar6 + iVar3, iVar6 == 0)) {
                      if (apdb_err_switch != 0) {
                        pcVar18 = "[APDB_ERROR]%s()/line %d : input invalid\n";
                        uVar19 = 0xab3;
LAB_00604bcc:
                        printf(pcVar18,"_apdb_region_list_parse_from_json",uVar19);
                      }
LAB_006041c4:
                      if (apdb_err_switch != 0) {
                        pcVar18 = 
                        "[APDB_ERROR]%s()/line %d : apdb_region_list_parse_from_json fail\n";
                        uVar19 = 0xc45;
                        goto LAB_0060453c;
                      }
                      goto LAB_006041d4;
                    }
                    uVar15 = cJSON_GetArraySize(iVar5);
                    bVar1 = apdb_debug_switch == 0;
                    *(undefined1 *)(iVar6 + 0x15) = uVar15;
                    if (bVar1) {
                      bVar2 = *(byte *)(iVar6 + 0x15);
                    }
                    else {
                      printf("[APDB_DEBUG]%s()/line %d : dest_model->region_cnt=%d\n",
                             "_apdb_region_list_parse_from_json",0xab8);
                      bVar2 = *(byte *)(iVar6 + 0x15);
                    }
                    if (bVar2 != 0) {
                      pvVar22 = (void *)FUN_00408450((uint)bVar2 * 0xc3,0xabd);
                      *(void **)(iVar6 + 0x30) = pvVar22;
                      if (pvVar22 == (void *)0x0) {
                        if (apdb_debug_switch != 0) {
                          pcVar18 = 
                          "[APDB_DEBUG]%s()/line %d : dest_model->region_list mem_malloc fail\n";
                          uVar19 = 0xac0;
                          goto LAB_00604bcc;
                        }
                        goto LAB_006041c4;
                      }
                      memset(pvVar22,0,(uint)*(byte *)(iVar6 + 0x15) * 0xc3);
                      bVar2 = *(byte *)(iVar6 + 0x15);
                      for (iVar8 = 0; iVar8 < (int)(uint)bVar2; iVar8 = iVar8 + 1) {
                        iVar9 = cJSON_GetArrayItem(iVar5,iVar8);
                        if (iVar9 == 0) {
                          if (apdb_err_switch == 0) goto LAB_00605cc8;
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : Fail to parse region_array_item from json\n";
                          uVar19 = 0xacc;
LAB_00605d04:
                          printf(pcVar18,"_apdb_region_list_parse_from_json",uVar19);
                          iVar3 = *(int *)(iVar6 + 0x30);
LAB_00605ccc:
                          if (iVar3 != 0) {
                            FUN_00407df0();
                            *(undefined4 *)(iVar6 + 0x30) = 0;
                          }
                          goto LAB_006041c4;
                        }
                        iVar24 = iVar8 * 0xc3;
                        uVar19 = cJSON_GetObjectItem(iVar9,"region_code");
                        iVar23 = FUN_00407f50(uVar19,*(int *)(iVar6 + 0x30) + iVar24);
                        if (iVar23 != 0) {
                          if (apdb_err_switch != 0) {
                            pcVar18 = 
                            "[APDB_ERROR]%s()/line %d : Fail to parse region_code_obj from json\n";
                            uVar19 = 0xad4;
                            goto LAB_00605d04;
                          }
LAB_00605cc8:
                          iVar3 = *(int *)(iVar6 + 0x30);
                          goto LAB_00605ccc;
                        }
                        uVar19 = cJSON_GetObjectItem(iVar9,"name_len");
                        iVar23 = FUN_00407f50(uVar19,*(int *)(iVar6 + 0x30) + iVar24 + 1);
                        if (iVar23 != 0) {
                          if (apdb_err_switch != 0) {
                            pcVar18 = 
                            "[APDB_ERROR]%s()/line %d : Fail to parse region_name_len_obj from json\n"
                            ;
                            uVar19 = 0xadc;
                            goto LAB_00605d04;
                          }
                          goto LAB_00605cc8;
                        }
                        uVar19 = cJSON_GetObjectItem(iVar9,"ch_lst_len");
                        iVar23 = FUN_00407f50(uVar19,*(int *)(iVar6 + 0x30) + iVar24 + 2);
                        if (iVar23 != 0) {
                          if (apdb_err_switch != 0) {
                            pcVar18 = 
                            "[APDB_ERROR]%s()/line %d : Fail to parse region_channel_len_obj from json\n"
                            ;
                            uVar19 = 0xae4;
                            goto LAB_00605d04;
                          }
                          goto LAB_00605cc8;
                        }
                        uVar19 = cJSON_GetObjectItem(iVar9,"region_name");
                        iVar23 = FUN_00407ef0(uVar19,*(int *)(iVar6 + 0x30) + iVar24 + 3,0x40);
                        if (iVar23 != 0) {
                          if (apdb_err_switch != 0) {
                            pcVar18 = 
                            "[APDB_ERROR]%s()/line %d : Fail to parse region_name_obj from json\n";
                            uVar19 = 0xaec;
                            goto LAB_00605d04;
                          }
                          goto LAB_00605cc8;
                        }
                        uVar19 = cJSON_GetObjectItem(iVar9,"region_ch_lst");
                        iVar9 = FUN_00407ef0(uVar19,*(int *)(iVar6 + 0x30) + iVar24 + 0x43,0x80);
                        if (iVar9 != 0) {
                          if (apdb_err_switch != 0) {
                            pcVar18 = 
                            "[APDB_ERROR]%s()/line %d : Fail to parse region_channel_list_obj from json\n"
                            ;
                            uVar19 = 0xaf4;
                            goto LAB_00605d04;
                          }
                          goto LAB_00605cc8;
                        }
                        bVar2 = *(byte *)(iVar6 + 0x15);
                      }
                    }
                  }
                  local_64 = cJSON_GetObjectItem(local_8c,"radioLinkageTable");
                  if (local_64 == 0) {
LAB_00604550:
                    iVar5 = cJSON_GetObjectItem(local_8c,"radios");
                    if ((iVar5 == 0) || (*(int *)(iVar5 + 0xc) != 6)) {
                      if (apdb_err_switch != 0) {
                        pcVar18 = "[APDB_ERROR]%s()/line %d : Fail to get radios\n";
                        uVar19 = 0xc59;
                        goto LAB_0060453c;
                      }
                      goto LAB_006041d4;
                    }
                    iVar6 = *(int *)((int)pvVar7 + 0x164);
                    uVar19 = cJSON_GetArraySize(iVar5);
                    *(undefined4 *)(iVar6 + iVar3 + 0x10) = uVar19;
                    iVar8 = *(int *)((int)pvVar7 + 0x164) + iVar3;
                    iVar6 = *(int *)(iVar8 + 0x10);
                    if (7 < iVar6 - 1U) {
                      if (apdb_err_switch != 0) {
                        printf("[APDB_ERROR]%s()/line %d : Radio cnt %d exceeds or zero\n",
                               "_apdb_aplist_parse",0xc60);
                      }
                      goto LAB_006041d4;
                    }
                    uVar19 = FUN_00408450(iVar6 * 0x114,0xc63);
                    *(undefined4 *)(iVar8 + 0x28) = uVar19;
                    iVar6 = *(int *)((int)pvVar7 + 0x164) + iVar3;
                    pvVar22 = *(void **)(iVar6 + 0x28);
                    if (pvVar22 == (void *)0x0) {
                      if (apdb_err_switch != 0) {
                        pcVar18 = "[APDB_ERROR]%s()/line %d : Malloc failed\n";
                        uVar19 = 0xc66;
                        goto LAB_0060453c;
                      }
                      goto LAB_006041d4;
                    }
                    iVar9 = 0;
                    iVar23 = 0;
                    iVar8 = 0;
                    memset(pvVar22,0,*(int *)(iVar6 + 0x10) * 0x114);
                    local_8c = 0;
                    local_98 = (void *)0x0;
                    local_88 = iVar5;
                    while (iVar5 = *(int *)((int)pvVar7 + 0x164) + iVar3,
                          iVar8 < *(int *)(iVar5 + 0x10)) {
                      iVar5 = cJSON_GetArrayItem(local_88,iVar8);
                      if (iVar5 == 0) {
                        if (apdb_err_switch != 0) {
                          printf("[APDB_ERROR]%s()/line %d : get radio failed.\n",
                                 "_apdb_aplist_parse",0xc71);
                        }
LAB_00604940:
                        iVar5 = 0;
                        while (iVar5 < iVar8) {
                          iVar9 = iVar5 * 0x114;
                          iVar6 = *(int *)(*(int *)(*(int *)((int)pvVar7 + 0x164) + iVar3 + 0x28) +
                                           iVar9 + 0x110);
                          iVar5 = iVar5 + 1;
                          if (iVar6 != 0) {
                            FUN_00407df0(iVar6,1);
                            *(undefined4 *)
                             (*(int *)(*(int *)((int)pvVar7 + 0x164) + iVar3 + 0x28) + iVar9 + 0x110
                             ) = 0;
                          }
                        }
                        goto LAB_006041d4;
                      }
                      iVar6 = _apdb_radio_freq_string_to_enum(*(undefined4 *)(iVar5 + 0x20));
                      iVar24 = iVar8 * 0x114;
                      *(int *)(*(int *)(*(int *)((int)pvVar7 + 0x164) + iVar3 + 0x28) + iVar24) =
                           iVar6;
                      iVar5 = _apdb_parse_radio(iVar5,*(int *)(*(int *)((int)pvVar7 + 0x164) + iVar3
                                                              + 0x28) + iVar24);
                      if (iVar5 == -1) {
                        if (apdb_err_switch != 0) {
                          printf("[APDB_ERROR]%s()/line %d : parse radio for ap(0x%x)\n",
                                 "_apdb_aplist_parse",0xc7a,*(undefined4 *)((int)pvVar7 + 0x10));
                        }
                        goto LAB_00604940;
                      }
                      piVar16 = *(int **)(*(int *)(*(int *)((int)pvVar7 + 0x164) + iVar3 + 0x28) +
                                          iVar24 + 0x110);
                      iVar5 = -1;
                      if (piVar16 != (int *)0x0) {
                        iVar5 = *piVar16;
                      }
                      if ((iVar6 == 0) || (iVar5 == 0)) {
                        iVar23 = iVar23 + 1;
                        local_98 = (void *)0x1;
                        iVar8 = iVar8 + 1;
                      }
                      else if ((iVar6 == 1) || (iVar5 == 1)) {
                        iVar9 = iVar9 + 1;
                        local_8c = 1;
                        iVar8 = iVar8 + 1;
                      }
                      else {
                        iVar8 = iVar8 + 1;
                      }
                    }
                    *(int *)(iVar5 + 8) = iVar23;
                    *(int *)(*(int *)((int)pvVar7 + 0x164) + iVar3 + 0xc) = iVar9;
                    *(void **)(*(int *)((int)pvVar7 + 0x164) + iVar3 + 0x1c) = local_98;
                    local_80 = local_80 + 1;
                    *(undefined4 *)(*(int *)((int)pvVar7 + 0x164) + iVar3 + 0x18) = local_8c;
                    goto LAB_006040a8;
                  }
                  if (apdb_debug_switch != 0) {
                    printf("[APDB_DEBUG]%s()/line %d : FIND radioLinkageTable field,model_id=%d\n",
                           "_apdb_aplist_parse",0xc4e,*(undefined4 *)((int)pvVar7 + 0x10));
                  }
                  iVar5 = *(int *)((int)pvVar7 + 0x164);
                  memset(acStack_160,0,200);
                  if (apdb_debug_switch != 0) {
                    printf("[APDB_DEBUG]%s()/line %d : _apdb_rrst_parse_from_json ENTER\n",
                           "_apdb_rrst_parse_from_json",0x9f9);
                  }
                  if ((*(int *)(local_64 + 0xc) == 5) && (iVar5 = iVar5 + iVar3, iVar5 != 0)) {
                    uVar19 = cJSON_GetArraySize(local_64);
                    bVar1 = apdb_debug_switch == 0;
                    *(undefined4 *)(iVar5 + 4) = uVar19;
                    if (bVar1) {
                      iVar6 = *(int *)(iVar5 + 4);
                    }
                    else {
                      printf("[APDB_DEBUG]%s()/line %d : dest_model->rrst_row_cnt=%d\n",
                             "_apdb_rrst_parse_from_json",0xa01,uVar19);
                      iVar6 = *(int *)(iVar5 + 4);
                    }
                    if (0 < iVar6) {
                      pvVar22 = (void *)FUN_00408450(iVar6 * 0x1fc,0xa06);
                      *(void **)(iVar5 + 0x34) = pvVar22;
                      if (pvVar22 == (void *)0x0) {
                        if (apdb_debug_switch != 0) {
                          pcVar18 = "[APDB_DEBUG]%s()/line %d : dest_model->rrst mem_malloc fail\n";
                          uVar19 = 0xa09;
                          goto LAB_00604bec;
                        }
                        goto LAB_0060451c;
                      }
                      memset(pvVar22,0,*(int *)(iVar5 + 4) * 0x1fc);
                      local_98 = pvVar7;
                      local_30 = iVar3;
                      for (local_88 = 0; pvVar7 = local_98, iVar3 = local_30,
                          local_88 < *(int *)(iVar5 + 4); local_88 = local_88 + 1) {
                        iVar3 = cJSON_GetArrayItem(local_64,local_88);
                        if (iVar3 == 0) {
                          pvVar7 = local_98;
                          if (apdb_err_switch != 0) {
                            pcVar18 = 
                            "[APDB_ERROR]%s()/line %d : Fail to parse rrst_array_item from json\n";
                            uVar19 = 0xa15;
                            goto LAB_006057d8;
                          }
LAB_00605784:
                          iVar3 = *(int *)(iVar5 + 0x34);
LAB_00605788:
                          if (iVar3 != 0) {
                            FUN_00407df0();
                            *(undefined4 *)(iVar5 + 0x34) = 0;
                          }
                          goto LAB_0060451c;
                        }
                        uVar19 = cJSON_GetObjectItem(iVar3,"feature_involved");
                        iVar8 = local_88 * 0x1fc;
                        iVar6 = FUN_00408470(uVar19,*(int *)(iVar5 + 0x34) + iVar8);
                        if (iVar6 != 0) {
                          pvVar7 = local_98;
                          if (apdb_err_switch == 0) goto LAB_00605784;
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : Fail to parse rrst_feature_involved_obj from json\n"
                          ;
                          uVar19 = 0xa1d;
LAB_006057d8:
                          printf(pcVar18,"_apdb_rrst_parse_from_json",uVar19);
                          iVar3 = *(int *)(iVar5 + 0x34);
                          goto LAB_00605788;
                        }
                        uVar19 = cJSON_GetObjectItem(iVar3,"region_list");
                        memset(acStack_160,0,200);
                        memset((void *)(*(int *)(iVar5 + 0x34) + iVar8 + 9),0xff,0x20);
                        iVar6 = FUN_00407ef0(uVar19,acStack_160,200);
                        if (iVar6 != 0) {
                          pvVar7 = local_98;
                          if (apdb_err_switch == 0) goto LAB_00605784;
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : Fail to parse region_code_list_obj from json\n"
                          ;
                          uVar19 = 0xa27;
                          goto LAB_006057d8;
                        }
                        iVar9 = *(int *)(iVar5 + 0x34);
                        local_198 = (char *)0x0;
                        iVar6 = 0;
                        pcVar18 = strtok_r(acStack_160," ",&local_198);
                        while ((pcVar18 != (char *)0x0 && (iVar6 < 0x20))) {
                          uVar10 = atoi(pcVar18);
                          if (uVar10 < 0x20) {
                            iVar6 = iVar6 + 1;
                            *(undefined1 *)(iVar9 + iVar8 + uVar10 + 9) = 1;
                          }
                          pcVar18 = strtok_r((char *)0x0," ",&local_198);
                        }
                        uVar19 = cJSON_GetObjectItem(iVar3,"table_index");
                        iVar6 = FUN_00408470(uVar19,*(int *)(iVar5 + 0x34) + iVar8 + 4);
                        if (iVar6 != 0) {
                          pvVar7 = local_98;
                          if (apdb_err_switch == 0) goto LAB_00605784;
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : Fail to parse table_index_obj from json\n";
                          uVar19 = 0xa30;
                          goto LAB_006057d8;
                        }
                        uVar19 = cJSON_GetObjectItem(iVar3,"radio_num");
                        iVar6 = FUN_00407f50(uVar19,*(int *)(iVar5 + 0x34) + iVar8 + 8);
                        if (iVar6 != 0) {
                          pvVar7 = local_98;
                          if (apdb_err_switch == 0) goto LAB_00605784;
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : Fail to parse radio_num_obj from json\n";
                          uVar19 = 0xa38;
                          goto LAB_006057d8;
                        }
                        iVar6 = *(int *)(iVar5 + 0x34) + iVar8;
                        if (4 < *(byte *)(iVar6 + 8)) {
                          *(undefined1 *)(iVar6 + 8) = 4;
                        }
                        local_4c = cJSON_GetObjectItem(iVar3,"radio_id");
                        if ((local_4c == 0) || (*(int *)(local_4c + 0xc) != 5)) {
                          pvVar7 = local_98;
                          if (apdb_err_switch == 0) goto LAB_00605784;
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : Fail to parse radio_id_array_obj from json\n";
                          uVar19 = 0xa43;
                          goto LAB_006057d8;
                        }
                        local_48 = cJSON_GetObjectItem(iVar3,"radio_abstract_status");
                        if ((local_48 == 0) || (*(int *)(local_48 + 0xc) != 5)) {
                          pvVar7 = local_98;
                          if (apdb_err_switch == 0) goto LAB_00605784;
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : Fail to parse radio_abs_status_array_obj from json\n"
                          ;
                          uVar19 = 0xa4a;
                          goto LAB_006057d8;
                        }
                        local_44 = cJSON_GetObjectItem(iVar3,"bind_id");
                        if ((local_44 == 0) || (*(int *)(local_44 + 0xc) != 5)) {
                          pvVar7 = local_98;
                          if (apdb_err_switch == 0) goto LAB_00605784;
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : Fail to parse band_id_array_obj from json\n";
                          uVar19 = 0xa51;
                          goto LAB_006057d8;
                        }
                        local_40 = cJSON_GetObjectItem(iVar3,"bandwidth");
                        if ((local_40 == 0) || (*(int *)(local_40 + 0xc) != 5)) {
                          pvVar7 = local_98;
                          if (apdb_err_switch == 0) goto LAB_00605784;
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : Fail to parse bandwidth_array_obj from json\n"
                          ;
                          uVar19 = 0xa58;
                          goto LAB_006057d8;
                        }
                        iVar3 = cJSON_GetObjectItem(iVar3,"channel");
                        if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 5)) {
                          pvVar7 = local_98;
                          if (apdb_err_switch == 0) goto LAB_00605784;
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : Fail to parse channel_array_obj from json\n";
                          uVar19 = 0xa5f;
                          goto LAB_006057d8;
                        }
                        iVar6 = 0;
LAB_00605310:
                        if (iVar6 < (int)(uint)*(byte *)(*(int *)(iVar5 + 0x34) + iVar8 + 8)) {
                          uVar19 = cJSON_GetArrayItem(local_4c,iVar6);
                          iVar23 = iVar6 * 0x74 + 0x90;
                          iVar9 = FUN_00407f50(uVar19,*(int *)(iVar5 + 0x34) + iVar8 + iVar23 + 8);
                          if (iVar9 != 0) {
                            pvVar7 = local_98;
                            if (apdb_err_switch == 0) goto LAB_00605784;
                            pcVar18 = 
                            "[APDB_ERROR]%s()/line %d : Fail to parse radio_id from json\n";
                            uVar19 = 0xa6a;
                            goto LAB_006057d8;
                          }
                          iVar24 = iVar6 * 0x74 + 0x28;
                          uVar19 = cJSON_GetArrayItem(local_48,iVar6);
                          iVar9 = FUN_00408470(uVar19,*(int *)(iVar5 + 0x34) + iVar8 + iVar24 + 4);
                          if (iVar9 != 0) {
                            pvVar7 = local_98;
                            if (apdb_err_switch == 0) goto LAB_00605784;
                            pcVar18 = 
                            "[APDB_ERROR]%s()/line %d : Fail to parse radio_abstract_status from json\n"
                            ;
                            uVar19 = 0xa72;
                            goto LAB_006057d8;
                          }
                          uVar19 = cJSON_GetArrayItem(local_44,iVar6);
                          iVar9 = FUN_00407f50(uVar19,*(int *)(iVar5 + 0x34) + iVar8 + iVar23 + 10);
                          if (iVar9 != 0) {
                            pvVar7 = local_98;
                            if (apdb_err_switch == 0) goto LAB_00605784;
                            pcVar18 = "[APDB_ERROR]%s()/line %d : Fail to parse bind_id from json\n"
                            ;
                            uVar19 = 0xa7a;
                            goto LAB_006057d8;
                          }
                          uVar19 = cJSON_GetArrayItem(local_40,iVar6);
                          memset(acStack_160,0,200);
                          iVar9 = FUN_00407ef0(uVar19,acStack_160,200);
                          pvVar7 = local_98;
                          if (iVar9 != 0) {
                            if (apdb_err_switch == 0) goto LAB_00605784;
                            pcVar18 = 
                            "[APDB_ERROR]%s()/line %d : Fail to parse bandwidth from json\n";
                            uVar19 = 0xa83;
                            goto LAB_006057d8;
                          }
                          iVar24 = *(int *)(iVar5 + 0x34) + iVar8 + iVar24;
                          local_198 = (char *)0x0;
                          if (iVar24 == -4) {
                            if (apdb_err_switch != 0) {
                              printf("[APDB_ERROR]%s()/line %d : _apdb_rrst_bandwidth_parse_from_json input str null.\n"
                                     ,"_apdb_rrst_bandwidth_parse_from_json",0x945);
                            }
                            if (apdb_err_switch == 0) goto LAB_00605784;
                            pcVar18 = 
                            "[APDB_ERROR]%s()/line %d : _apdb_rrst_bandwidth_parse_from_json fail.\n"
                            ;
                            uVar19 = 0xa88;
                            goto LAB_006057d8;
                          }
                          uVar10 = 0;
                          pcVar18 = strtok_r(acStack_160," ",&local_198);
                          while (pcVar18 != (char *)0x0) {
                            uVar11 = get_apdb_flag_bit(pcVar18);
                            if (uVar11 == 0xffffffff) {
                              if (apdb_warning_switch != 0) {
                                printf("[APDB_WARNING]%s()/line %d : parse bandwidth:undefined number.\n\n"
                                       ,"_apdb_rrst_bandwidth_parse_from_json",0x953);
                              }
                            }
                            else {
                              uVar10 = 1 << (uVar11 & 0x1f) & 0xffU | uVar10;
                            }
                            pcVar18 = strtok_r((char *)0x0," ",&local_198);
                          }
                          *(char *)(iVar24 + 0x71) = (char)uVar10;
                          uVar19 = cJSON_GetArrayItem(iVar3,iVar6);
                          memset(acStack_160,0,200);
                          iVar9 = FUN_00407ef0(uVar19,acStack_160,200);
                          pvVar7 = local_98;
                          if (iVar9 != 0) {
                            if (apdb_err_switch == 0) goto LAB_00605784;
                            pcVar18 = "[APDB_ERROR]%s()/line %d : Fail to parse channel from json\n"
                            ;
                            uVar19 = 0xa91;
                            goto LAB_006057d8;
                          }
                          local_19c = (char *)0x0;
                          local_198 = (char *)0x0;
                          iVar9 = *(int *)(iVar5 + 0x34) + iVar8 + iVar6 * 0x74;
                          iVar23 = iVar9 + 0x2c;
                          local_1a0 = (char *)0x0;
                          if (iVar23 != 0) {
                            pcVar18 = strtok_r(acStack_160," ",&local_198);
LAB_00605514:
                            if (pcVar18 == (char *)0x0) goto LAB_0060575c;
                            iVar24 = strcmp(pcVar18,"0");
                            if (iVar24 == 0) {
                              iVar24 = 0;
                              iVar17 = iVar23;
                              do {
                                if (*(short *)(iVar17 + 6) == 0) {
                                  *(undefined2 *)(iVar23 + iVar24 * 2 + 6) = 0xffff;
                                  break;
                                }
                                iVar24 = iVar24 + 1;
                                iVar17 = iVar17 + 2;
                              } while (iVar24 != 0x33);
                            }
                            else {
                              iVar24 = strcmp(pcVar18,"equal");
                              if (iVar24 == 0) {
                                *(undefined4 *)(iVar9 + 0x9c) = 1;
                                goto LAB_00605568;
                              }
                              pcVar12 = strstr(pcVar18,"default");
                              if (pcVar12 == (char *)0x0) {
                                pcVar12 = strchr(pcVar18,0x2d);
                                if (pcVar12 == (char *)0x0) {
                                  iVar17 = 0;
                                  iVar24 = iVar23;
                                  do {
                                    if (*(short *)(iVar24 + 6) == 0) {
                                      iVar24 = atoi(pcVar18);
                                      iVar20 = (int)(short)iVar24;
                                      if (iVar20 == 0) {
                                        *(undefined2 *)(iVar23 + iVar17 * 2 + 6) = 0xffff;
                                      }
                                      else {
                                        if (iVar20 < 1) {
                                          pvVar7 = local_98;
                                          if (apdb_err_switch == 0) goto LAB_006057b8;
                                          pcVar18 = 
                                          "[APDB_ERROR]%s()/line %d : channel number error when parse from json:%d.\n"
                                          ;
                                          uVar19 = 0x9da;
                                          goto LAB_00605c50;
                                        }
                                        iVar20 = _apdb_is_chnl_legal(iVar20);
                                        if (iVar20 == 1) {
                                          *(short *)(iVar23 + iVar17 * 2 + 6) = (short)iVar24;
                                        }
                                      }
                                      break;
                                    }
                                    iVar17 = iVar17 + 1;
                                    iVar24 = iVar24 + 2;
                                  } while (iVar17 != 0x33);
                                }
                                else {
                                  pcVar18 = strtok_r(pcVar18,"-",&local_19c);
                                  iVar24 = atoi(pcVar18);
                                  local_60 = (int)(short)iVar24;
                                  pcVar18 = strtok_r((char *)0x0,"-",&local_19c);
                                  iVar17 = atoi(pcVar18);
                                  pvVar7 = local_98;
                                  local_5c = (int)(short)iVar17;
                                  if (((local_5c < local_60) || (local_60 < 0)) || (local_5c < 0)) {
                                    if (apdb_err_switch != 0) {
                                      printf("[APDB_ERROR]%s()/line %d : input channel error %d-%d when parse from json.\n\n"
                                             ,"_apdb_rrst_channel_parse_from_json",0x9a6,local_60,
                                             local_5c);
                                    }
                                    goto LAB_006057b8;
                                  }
                                  iVar20 = 0;
                                  iVar17 = iVar23;
                                  do {
                                    if (*(short *)(iVar17 + 6) == 0) {
                                      iVar17 = 0;
                                      goto LAB_006056a4;
                                    }
                                    iVar20 = iVar20 + 1;
                                    iVar17 = iVar17 + 2;
                                  } while (iVar20 != 0x33);
                                }
                              }
                              else {
                                strtok_r(pcVar18,":",&local_1a0);
                                pcVar18 = strtok_r((char *)0x0,":",&local_1a0);
                                iVar24 = atoi(pcVar18);
                                iVar20 = (int)(short)iVar24;
                                if (iVar20 == 0) {
                                  *(undefined2 *)(iVar9 + 0x30) = 0xffff;
                                }
                                else {
                                  if (iVar20 < 1) {
                                    pvVar7 = local_98;
                                    if (apdb_err_switch != 0) {
                                      pcVar18 = 
                                      "[APDB_ERROR]%s()/line %d : default channel error when parse from json,the defalut channel is:%d.\n"
                                      ;
                                      uVar19 = 0x99c;
LAB_00605c50:
                                      pvVar7 = local_98;
                                      printf(pcVar18,"_apdb_rrst_channel_parse_from_json",uVar19,
                                             iVar20);
                                    }
                                    goto LAB_006057b8;
                                  }
                                  *(short *)(iVar9 + 0x30) = (short)iVar24;
                                }
                              }
                            }
                            goto LAB_00605568;
                          }
                          if (apdb_err_switch != 0) {
                            pcVar18 = "[APDB_ERROR]%s()/line %d :  input str null.\n";
                            uVar19 = 0x976;
LAB_0060580c:
                            pvVar7 = local_98;
                            printf(pcVar18,"_apdb_rrst_channel_parse_from_json",uVar19);
                          }
LAB_006057b8:
                          if (apdb_err_switch == 0) {
                            iVar3 = *(int *)(iVar5 + 0x34);
                            goto LAB_00605788;
                          }
                          pcVar18 = 
                          "[APDB_ERROR]%s()/line %d : _apdb_rrst_channel_parse_from_json fail.\n";
                          uVar19 = 0xa96;
                          goto LAB_006057d8;
                        }
                      }
                    }
                    goto LAB_00604550;
                  }
                  if (apdb_err_switch != 0) {
                    pcVar18 = "[APDB_ERROR]%s()/line %d : input invalid\n";
                    uVar19 = 0x9fc;
LAB_00604bec:
                    printf(pcVar18,"_apdb_rrst_parse_from_json",uVar19);
                  }
LAB_0060451c:
                  if (apdb_err_switch != 0) {
                    pcVar18 = "[APDB_ERROR]%s()/line %d : apdb_rrst_parse_from_json fail\n";
                    uVar19 = 0xc51;
                    goto LAB_0060453c;
                  }
LAB_006041d4:
                  _apdb_ap_model_free(pvVar7,1);
                }
              }
              else if (apdb_err_switch != 0) {
                printf("[APDB_ERROR]%s()/line %d : Model cnt %d exceeds or zero\n",
                       "_apdb_aplist_parse",0xc11,iVar3);
              }
            }
            goto LAB_006041e0;
          }
          if (apdb_debug_switch != 0) {
            printf("[APDB_DEBUG]%s()/line %d : success exit\n","_apdb_aplist_parse",0xc9b);
          }
          goto LAB_006041ec;
        }
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : malloc apdb_ap_new failed\n","_apdb_ap_item_list_parse"
                 ,0xceb);
        }
      }
    }
    if (local_70 == -1) goto LAB_00604b64;
    if (nego_ap_root != 0) {
      cJSON_Delete();
    }
    nego_ap_root = local_94;
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : init db success.\n","_apdb_init_nego_db",0x103c);
    }
    memset(local_184,0,0x21);
    if (nego_ap_root == 0) {
      if (apdb_err_switch != 0) {
        pcVar18 = "[APDB_ERROR]%s()/line %d : Nego ap list null\n";
        uVar19 = 0xf0c;
LAB_006050e8:
        printf(pcVar18,"_apdb_fix_json_mem",uVar19);
      }
    }
    else {
      iVar3 = cJSON_GetObjectItem(nego_ap_root,"ap_item_list");
      if (iVar3 == 0) {
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : ap list null.\n","_apdb_fix_json_mem",0xf13);
        }
        _apdb_init_json_mem();
      }
      else {
        local_94 = cJSON_GetArraySize(iVar3);
        local_98 = (void *)0x0;
        for (iVar5 = 0; iVar5 < local_94; iVar5 = iVar5 + 1) {
          uVar19 = cJSON_GetArrayItem(iVar3,iVar5);
          iVar6 = 0;
          uVar19 = cJSON_GetObjectItem(uVar19,"ap_list");
          iVar8 = 0;
          local_90 = (void *)cJSON_GetArraySize(uVar19);
          while (iVar8 < (int)local_90) {
            uVar4 = cJSON_GetArrayItem(uVar19,iVar6);
            iVar9 = cJSON_GetObjectItem(uVar4,"vendor");
            if ((iVar9 == 0) || (*(int *)(iVar9 + 0xc) != 3)) {
              if (apdb_err_switch == 0) goto LAB_00603c40;
              pcVar18 = "[APDB_ERROR]%s()/line %d : parse vendor failed.\n";
              uVar19 = 0xf28;
              goto LAB_006050e8;
            }
            if (vendor_type == *(int *)(iVar9 + 0x14)) {
              memset(local_184,0,0x21);
              iVar9 = cJSON_GetObjectItem(uVar4,"sales_method");
              if ((iVar9 != 0) && (*(int *)(iVar9 + 0xc) == 4)) {
                strncpy(local_184,*(char **)(iVar9 + 0x10),0x20);
              }
              iVar9 = _apdb_sales_method_match(local_184);
              if (iVar9 == 0) {
                if (apdb_debug_switch != 0) {
                  pcVar18 = 
                  "[APDB_DEBUG]%s()/line %d : Saled method(%s:%s) not match,delete item in json.\n";
                  puVar26 = &sales_method;
                  uVar4 = 0xf3a;
                  pcVar12 = local_184;
LAB_006050b4:
                  printf(pcVar18,"_apdb_fix_json_mem",uVar4,pcVar12,puVar26);
                }
                goto LAB_00605010;
              }
              iVar9 = cJSON_GetObjectItem(uVar4,"product_type");
              if (((iVar9 != 0) && (*(int *)(iVar9 + 0xc) == 3)) &&
                 (pcVar12 = *(char **)(iVar9 + 0x14), (char *)0x3 < pcVar12)) {
                if (apdb_debug_switch != 0) {
                  puVar26 = (undefined1 *)0xffffffff;
                  uVar4 = 0xf40;
                  pcVar18 = 
                  "[APDB_DEBUG]%s()/line %d : Illegal product type %d, need to in (%d, %d)\n";
                  goto LAB_006050b4;
                }
                goto LAB_00605010;
              }
              iVar6 = iVar6 + 1;
              iVar8 = iVar8 + 1;
            }
            else {
              if (apdb_debug_switch != 0) {
                printf("[APDB_DEBUG]%s()/line %d : vendor not match,delete item in json.\n",
                       "_apdb_fix_json_mem",0xf2d);
              }
LAB_00605010:
              cJSON_DeleteItemFromArray(uVar19,iVar6);
              iVar8 = iVar8 + 1;
              local_98 = (void *)0x1;
            }
          }
        }
        if (local_98 != (void *)0x0) {
          pcVar18 = (char *)cJSON_Print(nego_ap_root);
          if (pcVar18 == (char *)0x0) {
            if (apdb_debug_switch != 0) {
              pcVar18 = "[APDB_DEBUG]%s()/line %d : change to string error\n\n";
              uVar19 = 0xf6e;
              goto LAB_006050e8;
            }
          }
          else {
            sVar21 = strlen(pcVar18);
            if (((int)sVar21 < 0x100001) && (sVar21 != 0)) {
              __s = fopen("/etc/nouci_config/dbs/apdb_nego.db","w");
              if (__s == (FILE *)0x0) {
                if (apdb_err_switch != 0) {
                  printf("[APDB_ERROR]%s()/line %d : Failed to open file[%s]\n","_apdb_fix_json_mem"
                         ,0xf5c,"/etc/nouci_config/dbs/apdb_nego.db");
                }
              }
              else {
                sVar14 = fwrite(pcVar18,1,sVar21,__s);
                if (sVar21 == sVar14) {
                  if (apdb_debug_switch != 0) {
                    printf("[APDB_DEBUG]%s()/line %d : write file %d bytes success\n",
                           "_apdb_fix_json_mem",0xf67,sVar21);
                  }
                  _apdb_refresh_update_count(0);
                }
                else if (apdb_err_switch != 0) {
                  pcVar12 = "[APDB_ERROR]%s()/line %d : read apdb data failed.\n";
                  uVar19 = 0xf63;
                  goto LAB_00605fbc;
                }
              }
            }
            else {
              __s = (FILE *)0x0;
              if (apdb_err_switch != 0) {
                pcVar12 = "[APDB_ERROR]%s()/line %d : file is too large or zero.\n";
                uVar19 = 0xf55;
LAB_00605fbc:
                printf(pcVar12,"_apdb_fix_json_mem",uVar19);
              }
            }
            free(pcVar18);
            if (__s != (FILE *)0x0) {
              fclose(__s);
            }
          }
        }
      }
    }
LAB_00603c40:
    iVar3 = 0;
    if (apdb_debug_switch == 0) goto LAB_00603b9c;
    pcVar18 = "[APDB_DEBUG]%s()/line %d : load nego apdb success.\n";
    uVar19 = 0x10a5;
  }
  printf(pcVar18,"_apdb_load_json_nego_db",uVar19);
LAB_00603b9c:
  FUN_00407df0(local_58);
  return iVar3;
LAB_00605a54:
  local_84 = local_84 + 1;
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : parse %d aps.\n","_apdb_aplist_parse",0xc99,local_84);
  }
LAB_00603ab0:
  local_6c = local_6c + 1;
  goto LAB_00603ab8;
LAB_0060575c:
  iVar6 = iVar6 + 1;
  goto LAB_00605310;
LAB_006056a4:
  if (iVar17 + local_60 <= local_5c) {
    if (iVar20 == 0x33) {
      pvVar7 = local_98;
      if (apdb_err_switch == 0) goto LAB_006057b8;
      pcVar18 = 
      "[APDB_ERROR]%s()/line %d : channel counts invalid, more than max when parse from msgele.\n\n"
      ;
      uVar19 = 0x9b2;
      goto LAB_0060580c;
    }
    if (iVar17 + local_60 == 0) {
      *(undefined2 *)(iVar23 + iVar20 * 2 + 6) = 0xffff;
LAB_006056e0:
      iVar20 = iVar20 + 1;
      iVar17 = iVar17 + 1;
    }
    else {
      iVar13 = _apdb_is_chnl_legal();
      if (iVar13 == 1) {
        *(short *)(iVar23 + iVar20 * 2 + 6) = (short)iVar17 + (short)iVar24;
        goto LAB_006056e0;
      }
      iVar17 = iVar17 + 1;
    }
    goto LAB_006056a4;
  }
LAB_00605568:
  pcVar18 = strtok_r((char *)0x0," ",&local_198);
  goto LAB_00605514;
}

