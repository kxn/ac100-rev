// func _apdb_add_ap_to_aplist @ 005fd714 size=6744

undefined4 _apdb_add_ap_to_aplist(undefined4 *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char cVar6;
  int iVar4;
  int iVar5;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  short *psVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  undefined8 uVar15;
  char local_160 [12];
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined1 auStack_144 [36];
  char local_120 [8];
  uint local_118;
  undefined4 local_114;
  undefined4 local_110;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  
  local_154 = 0;
  local_150 = 0;
  local_14c = 0;
  local_148 = 0;
  memset(auStack_144,0,0x21);
  iVar2 = cJSON_CreateObject();
  if (iVar2 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    uVar10 = 0x1ba8;
  }
  else {
    if (*(char *)(param_2 + 0x11b) != '\0') {
      iVar3 = cJSON_CreateString(param_2 + 0x11b);
      if (iVar3 == 0) {
        if (apdb_err_switch == 0) {
          return 0xffffffff;
        }
        uVar10 = 0x1bb2;
        goto LAB_005fdc00;
      }
      cJSON_AddItemToObject(iVar2,"ap_nickname",iVar3);
    }
    iVar3 = cJSON_CreateString(param_2 + 0xda);
    if (iVar3 == 0) {
      if (apdb_err_switch == 0) {
        return 0xffffffff;
      }
      uVar10 = 0x1bbd;
    }
    else {
      cJSON_AddItemToObject(iVar2,"ap_name",iVar3);
      if (*(char *)(param_2 + 0x98) == '\0') {
        cVar6 = *(char *)(param_2 + 0xb9);
      }
      else {
        iVar3 = cJSON_CreateString(param_2 + 0x98);
        if (iVar3 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          uVar10 = 0x1bc9;
          goto LAB_005fdc00;
        }
        cJSON_AddItemToObject(iVar2,"device_type",iVar3);
        cVar6 = *(char *)(param_2 + 0xb9);
      }
      if (cVar6 != '\0') {
        iVar3 = cJSON_CreateString(param_2 + 0xb9);
        if (iVar3 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          uVar10 = 0x1bd6;
          goto LAB_005fdc00;
        }
        cJSON_AddItemToObject(iVar2,"sales_method",iVar3);
      }
      uVar15 = __floatsidf(*(undefined4 *)(param_2 + 0x15c));
      iVar3 = cJSON_CreateNumber((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
      if (iVar3 == 0) {
        if (apdb_err_switch == 0) {
          return 0xffffffff;
        }
        uVar10 = 0x1be1;
      }
      else {
        cJSON_AddItemToObject(iVar2,"version",iVar3);
        uVar15 = __floatsidf(*(undefined4 *)(param_2 + 0x10));
        iVar3 = cJSON_CreateNumber((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
        if (iVar3 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          uVar10 = 0x1bec;
        }
        else {
          cJSON_AddItemToObject(iVar2,"id",iVar3);
          uVar15 = __floatsidf(*(undefined4 *)(param_2 + 0x18));
          iVar3 = cJSON_CreateNumber((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
          if (iVar3 == 0) {
            if (apdb_err_switch == 0) {
              return 0xffffffff;
            }
            uVar10 = 0x1bf7;
          }
          else {
            cJSON_AddItemToObject(iVar2,"vendor",iVar3);
            if (*(int *)(param_2 + 0x70) == 0) {
              iVar3 = *(int *)(param_2 + 0x74);
            }
            else {
              iVar3 = cJSON_CreateBool(1);
              if (iVar3 == 0) {
                if (apdb_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar10 = 0x1c04;
                goto LAB_005fdc00;
              }
              cJSON_AddItemToObject(iVar2,"support_ap_trunk",iVar3);
              iVar3 = *(int *)(param_2 + 0x74);
            }
            if (iVar3 == 1) {
              iVar3 = cJSON_CreateBool(1);
              if (iVar3 == 0) {
                if (apdb_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar10 = 0x1c11;
                goto LAB_005fdc00;
              }
              cJSON_AddItemToObject(iVar2,"support_cloud_upgrade",iVar3);
              iVar3 = *(int *)(param_2 + 0x78);
            }
            else {
              iVar3 = *(int *)(param_2 + 0x78);
            }
            if (iVar3 == 1) {
              iVar3 = cJSON_CreateBool(1);
              if (iVar3 == 0) {
                if (apdb_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar10 = 0x1c1e;
                goto LAB_005fdc00;
              }
              cJSON_AddItemToObject(iVar2,"support_large_fw_upgrade",iVar3);
              iVar3 = *(int *)(param_2 + 0x7c);
            }
            else {
              iVar3 = *(int *)(param_2 + 0x7c);
            }
            if (iVar3 == 1) {
              iVar3 = cJSON_CreateBool(1);
              if (iVar3 == 0) {
                if (apdb_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar10 = 0x1c2b;
                goto LAB_005fdc00;
              }
              cJSON_AddItemToObject(iVar2,"is_mesh_device",iVar3);
              iVar3 = *(int *)(param_2 + 0x80);
            }
            else {
              iVar3 = *(int *)(param_2 + 0x80);
            }
            if (iVar3 != 0) {
              uVar15 = __floatsidf();
              iVar3 = cJSON_CreateNumber((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
              if (iVar3 == 0) {
                if (apdb_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar10 = 0x1c38;
                goto LAB_005fdc00;
              }
              cJSON_AddItemToObject(iVar2,"product_type",iVar3);
            }
            iVar3 = memcmp((void *)(param_2 + 0x84),&local_154,0x10);
            if (iVar3 == 0) {
              iVar3 = *(int *)(param_2 + 0x14);
            }
            else {
              FUN_004084f0((void *)(param_2 + 0x84),0x10,auStack_144);
              iVar3 = cJSON_CreateString(auStack_144);
              if (iVar3 == 0) {
                if (apdb_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar10 = 0x1c46;
                goto LAB_005fdc00;
              }
              cJSON_AddItemToObject(iVar2,"hardware_id",iVar3);
              iVar3 = *(int *)(param_2 + 0x14);
            }
            if (iVar3 < 1) {
              iVar3 = *(int *)(param_2 + 0x1c);
            }
            else {
              uVar15 = __floatsidf();
              iVar3 = cJSON_CreateNumber((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
              if (iVar3 == 0) {
                if (apdb_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar10 = 0x1c53;
                goto LAB_005fdc00;
              }
              cJSON_AddItemToObject(iVar2,"ext_wire_phy",iVar3);
              iVar3 = *(int *)(param_2 + 0x1c);
            }
            if (iVar3 == 1) {
              iVar3 = cJSON_CreateBool(1);
              if (iVar3 == 0) {
                if (apdb_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar10 = 0x1c60;
                goto LAB_005fdc00;
              }
              cJSON_AddItemToObject(iVar2,"is_hd_ap",iVar3);
            }
            iVar3 = 0;
            bVar1 = false;
            do {
              iVar9 = param_2 + iVar3;
              iVar3 = iVar3 + 4;
              if (*(int *)(iVar9 + 0x20) == 1) {
                bVar1 = true;
              }
            } while (iVar3 != 0x28);
            if (bVar1) {
              _apdb_construct_linked_modify_items(param_2 + 0x20,local_120,0x80);
              iVar3 = cJSON_CreateString(local_120);
              if (iVar3 == 0) {
                if (apdb_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar10 = 0x1c77;
                goto LAB_005fdc00;
              }
              cJSON_AddItemToObject(iVar2,"linked_modify_2.4G",iVar3);
            }
            iVar3 = 0;
            bVar1 = false;
            do {
              iVar9 = param_2 + iVar3;
              iVar3 = iVar3 + 4;
              if (*(int *)(iVar9 + 0x48) == 1) {
                bVar1 = true;
              }
            } while (iVar3 != 0x28);
            if (bVar1) {
              _apdb_construct_linked_modify_items(param_2 + 0x48,local_120,0x80);
              iVar3 = cJSON_CreateString(local_120);
              if (iVar3 == 0) {
                if (apdb_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar10 = 0x1c8f;
                goto LAB_005fdc00;
              }
              cJSON_AddItemToObject(iVar2,"linked_modify_5.0G",iVar3);
            }
            local_38 = cJSON_CreateArray();
            if (local_38 != 0) {
              cJSON_AddItemToObject(iVar2,"models",local_38);
              local_4c = 0;
              local_34 = iVar2;
              do {
                iVar2 = local_34;
                if (*(int *)(param_2 + 0x160) <= local_4c) {
LAB_005fe95c:
                  cJSON_AddItemToArray(*param_1,iVar2);
                  return 0;
                }
                local_160[0] = '\0';
                local_160[1] = '\0';
                local_160[2] = '\0';
                local_160[3] = '\0';
                local_160[4] = '\0';
                local_160[5] = '\0';
                local_160[6] = '\0';
                local_160[7] = '\0';
                local_160[8] = '\0';
                local_160[9] = '\0';
                local_160[10] = 0;
                local_50 = cJSON_CreateObject();
                if (local_50 == 0) {
                  iVar2 = local_34;
                  if (apdb_err_switch != 0) {
                    pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json_ptn.\n";
                    uVar10 = 0x1996;
LAB_005fe998:
                    iVar2 = local_34;
                    printf(pcVar7,"_apdb_add_model_to_ap",uVar10);
                  }
                  goto LAB_005fe95c;
                }
                cJSON_AddItemToArray(local_38,local_50);
                local_58 = local_4c * 0x38;
                psVar11 = (short *)(*(int *)(param_2 + 0x164) + local_58);
                snprintf(local_160,0xb,"%d.%d",(int)*psVar11,(int)psVar11[1]);
                iVar2 = cJSON_CreateString(local_160);
                if (iVar2 == 0) {
                  iVar2 = local_34;
                  if (apdb_err_switch != 0) {
                    pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
                    uVar10 = 0x19a2;
                    goto LAB_005fe998;
                  }
                  goto LAB_005fe95c;
                }
                cJSON_AddItemToObject(local_50,"hwver",iVar2);
                local_120[0] = '\0';
                local_120[1] = '\0';
                local_120[2] = '\0';
                local_120[3] = '\0';
                local_120[4] = '\0';
                local_120[5] = '\0';
                local_120[6] = '\0';
                local_120[7] = '\0';
                local_118 = local_118 & 0xffff;
                iVar2 = cJSON_CreateObject();
                if (iVar2 == 0) {
                  iVar2 = -1;
                  if (apdb_err_switch != 0) {
                    pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json_radio_obj.\n";
                    uVar10 = 0x15e0;
LAB_005fddd8:
                    iVar2 = -1;
                    printf(pcVar7,"_apdb_add_radios_to_model",uVar10);
                  }
                }
                else {
                  iVar9 = 0;
                  cJSON_AddItemToObject(local_50,"radios",iVar2);
                  iVar3 = *(int *)(psVar11 + 8);
                  while (iVar9 < iVar3) {
                    iVar14 = *(int *)(psVar11 + 0x14);
                    iVar3 = cJSON_CreateObject();
                    if (iVar3 == 0) {
                      iVar2 = -1;
                      if (apdb_err_switch == 0) goto LAB_005fdcd4;
                      pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json_freq_obj.\n";
                      uVar10 = 0x15ee;
                      goto LAB_005fddd8;
                    }
                    piVar13 = (int *)(iVar14 + iVar9 * 0x114);
                    iVar14 = *piVar13;
                    if (iVar14 == 0) {
                      pcVar7 = "2.4G_%d";
                    }
                    else {
                      if (iVar14 != 1) {
                        cJSON_Delete(iVar3);
                        iVar2 = -1;
                        if (apdb_err_switch == 0) goto LAB_005fdcd4;
                        pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json_ptn.\n";
                        uVar10 = 0x15fe;
                        goto LAB_005fddd8;
                      }
                      pcVar7 = "5.0G_%d";
                    }
                    snprintf(local_120,10,pcVar7,iVar9 + 1);
                    cJSON_AddItemToObject(iVar2,local_120,iVar3);
                    iVar3 = _apdb_add_paras_to_radios(iVar3,piVar13);
                    iVar9 = iVar9 + 1;
                    if (iVar3 != 0) break;
                    iVar3 = *(int *)(psVar11 + 8);
                  }
                  iVar2 = 0;
                }
LAB_005fdcd4:
                iVar3 = *(int *)(param_2 + 0x164) + local_58;
                if (*(char *)(iVar3 + 0x14) == '\0') {
                  if (apdb_debug_switch == 0) {
                    iVar3 = *(int *)(param_2 + 0x164);
                  }
                  else {
                    pcVar7 = "[APDB_DEBUG]%s()/line %d : phy_num=%d\n";
                    pcVar8 = "_apdb_add_model_to_ap";
                    uVar10 = 0x19b9;
LAB_005fdd78:
                    printf(pcVar7,pcVar8,uVar10,0);
                    iVar3 = *(int *)(param_2 + 0x164);
                  }
                }
                else {
                  if (iVar2 == 0) {
                    if (apdb_debug_switch != 0) {
                      printf("[APDB_DEBUG]%s()/line %d : apdb_add_port_info_to_model ENTER\n",
                             "_apdb_add_port_info_to_model",0x1618);
                    }
                    local_120[0] = '\0';
                    local_120[1] = '\0';
                    local_120[2] = '\0';
                    local_120[3] = '\0';
                    local_120[4] = '\0';
                    local_120[5] = '\0';
                    local_120[6] = '\0';
                    local_120[7] = '\0';
                    local_118 = 0;
                    local_114 = 0;
                    local_110 = 0;
                    if (*(char *)(iVar3 + 0x14) != '\0') {
                      iVar14 = 0;
                      iVar9 = cJSON_CreateArray();
                      if (iVar9 == 0) {
                        iVar2 = -1;
                        if (apdb_err_switch == 0) goto LAB_005fdcf8;
                        pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json_phy_array_obj.\n";
                        pcVar8 = "_apdb_add_port_info_to_model";
                        uVar10 = 0x162e;
                      }
                      else {
                        for (; local_54 = iVar2, iVar2 = local_54,
                            iVar14 < (int)(uint)*(byte *)(iVar3 + 0x14); iVar14 = iVar14 + 1) {
                          iVar2 = cJSON_CreateObject();
                          if (iVar2 == 0) {
                            if (apdb_err_switch != 0) {
                              printf("[APDB_ERROR]%s()/line %d : Failed create json_region_array_item_obj.\n"
                                     ,"_apdb_add_port_info_to_model",0x1637);
                            }
LAB_005fed2c:
                            cJSON_Delete(iVar9);
                            goto LAB_005fdcf8;
                          }
                          local_120[0] = '\0';
                          local_120[1] = '\0';
                          local_120[2] = '\0';
                          local_120[3] = '\0';
                          iVar5 = iVar14 * 8;
                          local_120[4] = '\0';
                          local_120[5] = '\0';
                          local_120[6] = '\0';
                          local_120[7] = '\0';
                          local_118 = 0;
                          local_114 = 0;
                          local_110 = 0;
                          snprintf(local_120,0x14,"%d",
                                   (uint)*(byte *)(*(int *)(iVar3 + 0x2c) + iVar5));
                          iVar4 = cJSON_CreateString(local_120);
                          if (iVar4 == 0) {
                            if (apdb_err_switch != 0) {
                              pcVar7 = 
                              "[APDB_ERROR]%s()/line %d : Failed create json obj of phy_index.\n";
                              uVar10 = 0x1640;
LAB_005fed58:
                              printf(pcVar7,"_apdb_add_port_info_to_model",uVar10);
                            }
LAB_005fed24:
                            cJSON_Delete(iVar2);
                            goto LAB_005fed2c;
                          }
                          cJSON_AddItemToObject(iVar2,"phy_index",iVar4);
                          local_120[0] = '\0';
                          local_120[1] = '\0';
                          local_120[2] = '\0';
                          local_120[3] = '\0';
                          local_120[4] = '\0';
                          local_120[5] = '\0';
                          local_120[6] = '\0';
                          local_120[7] = '\0';
                          local_118 = 0;
                          local_114 = 0;
                          local_110 = 0;
                          snprintf(local_120,0x14,"%d",
                                   (uint)*(byte *)(*(int *)(iVar3 + 0x2c) + iVar5 + 1));
                          iVar4 = cJSON_CreateString(local_120);
                          if (iVar4 == 0) {
                            if (apdb_err_switch != 0) {
                              pcVar7 = 
                              "[APDB_ERROR]%s()/line %d : Failed create json obj of type.\n";
                              uVar10 = 0x164c;
                              goto LAB_005fed58;
                            }
                            goto LAB_005fed24;
                          }
                          cJSON_AddItemToObject(iVar2,"phy_type",iVar4);
                          local_120[0] = '\0';
                          local_120[1] = '\0';
                          local_120[2] = '\0';
                          local_120[3] = '\0';
                          local_120[4] = '\0';
                          local_120[5] = '\0';
                          local_120[6] = '\0';
                          local_120[7] = '\0';
                          local_118 = 0;
                          local_114 = 0;
                          local_110 = 0;
                          snprintf(local_120,0x14,"%d",
                                   *(undefined4 *)(*(int *)(iVar3 + 0x2c) + iVar5 + 4));
                          iVar4 = cJSON_CreateString(local_120);
                          if (iVar4 == 0) {
                            if (apdb_err_switch != 0) {
                              pcVar7 = 
                              "[APDB_ERROR]%s()/line %d : Failed create json obj of speed.\n";
                              uVar10 = 0x1658;
                              goto LAB_005fed58;
                            }
                            goto LAB_005fed24;
                          }
                          cJSON_AddItemToObject(iVar2,"phy_speed",iVar4);
                          cJSON_AddItemToArray(iVar9,iVar2);
                          iVar2 = local_54;
                        }
                        cJSON_AddItemToObject(local_50,"port_info",iVar9);
                        if (apdb_debug_switch == 0) {
                          iVar3 = *(int *)(param_2 + 0x164);
                          goto LAB_005fdcfc;
                        }
                        pcVar7 = 
                        "[APDB_DEBUG]%s()/line %d : apdb_add_port_info_list_to_model success EXIT\n"
                        ;
                        pcVar8 = "_apdb_add_port_info_to_model";
                        uVar10 = 0x1666;
                      }
LAB_005fe3c0:
                      printf(pcVar7,pcVar8,uVar10);
                      iVar3 = *(int *)(param_2 + 0x164);
                      goto LAB_005fdcfc;
                    }
                    iVar2 = -1;
                    if (apdb_err_switch != 0) {
                      pcVar7 = "[APDB_ERROR]%s()/line %d : ap_model->phy_num=%d, invalid\n";
                      pcVar8 = "_apdb_add_port_info_to_model";
                      uVar10 = 0x1626;
                      goto LAB_005fdd78;
                    }
                  }
                  else {
                    iVar2 = -1;
                    if (apdb_debug_switch != 0) {
                      pcVar7 = 
                      "[APDB_DEBUG]%s()/line %d : no port info,no need to add port info to model\n";
                      pcVar8 = "_apdb_add_model_to_ap";
                      uVar10 = 0x19b4;
                      goto LAB_005fe3c0;
                    }
                  }
LAB_005fdcf8:
                  iVar2 = -1;
                  iVar3 = *(int *)(param_2 + 0x164);
                }
LAB_005fdcfc:
                iVar3 = iVar3 + local_58;
                if (*(char *)(iVar3 + 0x15) == '\0') {
                  if (apdb_debug_switch == 0) {
                    iVar3 = *(int *)(param_2 + 0x164);
                  }
                  else {
                    pcVar7 = "[APDB_DEBUG]%s()/line %d : region_cnt=%d\n";
                    pcVar8 = "_apdb_add_model_to_ap";
                    uVar10 = 0x19ca;
LAB_005fdda4:
                    printf(pcVar7,pcVar8,uVar10,0);
                    iVar3 = *(int *)(param_2 + 0x164);
                  }
                }
                else {
                  if (iVar2 == 0) {
                    if (apdb_debug_switch != 0) {
                      printf("[APDB_DEBUG]%s()/line %d : apdb_add_region_list_to_model ENTER\n",
                             "_apdb_add_region_list_to_model",0x1907);
                    }
                    memset(local_120,0,200);
                    if (*(char *)(iVar3 + 0x15) != '\0') {
                      iVar14 = 0;
                      iVar9 = cJSON_CreateArray();
                      if (iVar9 == 0) {
                        iVar2 = -1;
                        if (apdb_err_switch == 0) goto LAB_005fdd20;
                        pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json_region_array_obj.\n"
                        ;
                        pcVar8 = "_apdb_add_region_list_to_model";
                        uVar10 = 0x191d;
                      }
                      else {
                        for (; local_54 = iVar2, iVar2 = local_54,
                            iVar14 < (int)(uint)*(byte *)(iVar3 + 0x15); iVar14 = iVar14 + 1) {
                          iVar2 = cJSON_CreateObject();
                          if (iVar2 == 0) {
                            if (apdb_err_switch != 0) {
                              printf("[APDB_ERROR]%s()/line %d : Failed create json_region_array_item_obj.\n"
                                     ,"_apdb_add_region_list_to_model",0x1926);
                            }
LAB_005fee3c:
                            cJSON_Delete(iVar9);
                            goto LAB_005fdd20;
                          }
                          iVar5 = iVar14 * 0xc3;
                          memset(local_120,0,200);
                          snprintf(local_120,200,"%d",
                                   (uint)*(byte *)(*(int *)(iVar3 + 0x30) + iVar5));
                          iVar4 = cJSON_CreateString(local_120);
                          if (iVar4 == 0) {
                            if (apdb_err_switch != 0) {
                              pcVar7 = 
                              "[APDB_ERROR]%s()/line %d : Failed create json obj of code.\n";
                              uVar10 = 0x1930;
LAB_005fee68:
                              printf(pcVar7,"_apdb_add_region_list_to_model",uVar10);
                            }
LAB_005fee34:
                            cJSON_Delete(iVar2);
                            goto LAB_005fee3c;
                          }
                          cJSON_AddItemToObject(iVar2,"region_code",iVar4);
                          memset(local_120,0,200);
                          snprintf(local_120,200,"%d",
                                   (uint)*(byte *)(*(int *)(iVar3 + 0x30) + iVar5 + 1));
                          iVar4 = cJSON_CreateString(local_120);
                          if (iVar4 == 0) {
                            if (apdb_err_switch != 0) {
                              pcVar7 = 
                              "[APDB_ERROR]%s()/line %d : Failed create json obj of name_len.\n";
                              uVar10 = 0x193c;
                              goto LAB_005fee68;
                            }
                            goto LAB_005fee34;
                          }
                          cJSON_AddItemToObject(iVar2,"name_len",iVar4);
                          memset(local_120,0,200);
                          snprintf(local_120,200,"%d",
                                   (uint)*(byte *)(*(int *)(iVar3 + 0x30) + iVar5 + 2));
                          iVar4 = cJSON_CreateString(local_120);
                          if (iVar4 == 0) {
                            if (apdb_err_switch != 0) {
                              pcVar7 = 
                              "[APDB_ERROR]%s()/line %d : Failed create json obj of ch_lst_len.\n";
                              uVar10 = 0x1948;
                              goto LAB_005fee68;
                            }
                            goto LAB_005fee34;
                          }
                          cJSON_AddItemToObject(iVar2,"ch_lst_len",iVar4);
                          memset(local_120,0,200);
                          strncpy(local_120,(char *)(*(int *)(iVar3 + 0x30) + iVar5 + 3),0x40);
                          iVar4 = cJSON_CreateString(local_120);
                          if (iVar4 == 0) {
                            if (apdb_err_switch != 0) {
                              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create name.\n";
                              uVar10 = 0x1954;
                              goto LAB_005fee68;
                            }
                            goto LAB_005fee34;
                          }
                          cJSON_AddItemToObject(iVar2,"region_name",iVar4);
                          memset(local_120,0,200);
                          strncpy(local_120,(char *)(*(int *)(iVar3 + 0x30) + iVar5 + 0x43),0x80);
                          iVar4 = cJSON_CreateString(local_120);
                          if (iVar4 == 0) {
                            if (apdb_err_switch != 0) {
                              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create name.\n";
                              uVar10 = 0x1961;
                              goto LAB_005fee68;
                            }
                            goto LAB_005fee34;
                          }
                          cJSON_AddItemToObject(iVar2,"region_ch_lst",iVar4);
                          cJSON_AddItemToArray(iVar9,iVar2);
                          iVar2 = local_54;
                        }
                        cJSON_AddItemToObject(local_50,"region_list",iVar9);
                        if (apdb_debug_switch == 0) {
                          iVar3 = *(int *)(param_2 + 0x164);
                          goto LAB_005fdd24;
                        }
                        pcVar7 = 
                        "[APDB_DEBUG]%s()/line %d : apdb_add_region_list_to_model success EXIT\n";
                        pcVar8 = "_apdb_add_region_list_to_model";
                        uVar10 = 0x196e;
                      }
LAB_005fe39c:
                      printf(pcVar7,pcVar8,uVar10);
                      iVar3 = *(int *)(param_2 + 0x164);
                      goto LAB_005fdd24;
                    }
                    iVar2 = -1;
                    if (apdb_err_switch != 0) {
                      pcVar7 = "[APDB_ERROR]%s()/line %d : ap_model->region_cnt=%d, invalid\n";
                      pcVar8 = "_apdb_add_region_list_to_model";
                      uVar10 = 0x1915;
                      goto LAB_005fdda4;
                    }
                  }
                  else {
                    iVar2 = -1;
                    if (apdb_debug_switch != 0) {
                      pcVar7 = 
                      "[APDB_DEBUG]%s()/line %d : no region list,no need to add region list to model\n"
                      ;
                      pcVar8 = "_apdb_add_model_to_ap";
                      uVar10 = 0x19c5;
                      goto LAB_005fe39c;
                    }
                  }
LAB_005fdd20:
                  iVar2 = -1;
                  iVar3 = *(int *)(param_2 + 0x164);
                }
LAB_005fdd24:
                iVar9 = iVar3 + local_58;
                if (*(int *)(iVar9 + 4) < 1) {
                  if (apdb_debug_switch != 0) {
                    iVar2 = *(int *)(iVar3 + 4);
                    pcVar7 = "[APDB_DEBUG]%s()/line %d : rrst_row_cnt=%d\n";
                    pcVar8 = "_apdb_add_model_to_ap";
                    uVar10 = 0x19db;
LAB_005fde08:
                    printf(pcVar7,pcVar8,uVar10,iVar2);
                  }
                }
                else if (iVar2 == 0) {
                  if (apdb_debug_switch != 0) {
                    printf("[APDB_DEBUG]%s()/line %d : _apdb_add_rrst_to_model ENTER\n",
                           "_apdb_add_rrst_to_model",0x17eb);
                  }
                  memset(local_120,0,200);
                  iVar2 = *(int *)(iVar9 + 4);
                  if (iVar2 < 1) {
                    if (apdb_err_switch != 0) {
                      pcVar7 = "[APDB_ERROR]%s()/line %d : ap_model->rrst_row_cnt=%d, invalid\n";
                      pcVar8 = "_apdb_add_rrst_to_model";
                      uVar10 = 0x1801;
                      goto LAB_005fde08;
                    }
                  }
                  else {
                    local_48 = cJSON_CreateArray();
                    local_44 = 0;
                    if (local_48 == 0) {
                      if (apdb_err_switch != 0) {
                        pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json_radio_obj.\n";
                        pcVar8 = "_apdb_add_rrst_to_model";
                        uVar10 = 0x1809;
                        goto LAB_005fe2b4;
                      }
                    }
                    else {
                      for (; local_44 < *(int *)(iVar9 + 4); local_44 = local_44 + 1) {
                        iVar2 = cJSON_CreateObject();
                        if (iVar2 == 0) {
                          if (apdb_err_switch != 0) {
                            printf("[APDB_ERROR]%s()/line %d : Failed create json_feature_involved_obj.\n"
                                   ,"_apdb_add_rrst_to_model",0x1812);
                          }
LAB_005febe8:
                          cJSON_Delete(local_48);
                          goto LAB_005fdd4c;
                        }
                        memset(local_120,0,200);
                        iVar14 = local_44 * 0x1fc;
                        snprintf(local_120,200,"%d",*(undefined4 *)(*(int *)(iVar9 + 0x34) + iVar14)
                                );
                        iVar3 = cJSON_CreateString(local_120);
                        if (iVar3 == 0) {
                          if (apdb_err_switch != 0) {
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json obj of feature_involved.\n"
                            ;
                            uVar10 = 0x181c;
LAB_005ff078:
                            printf(pcVar7,"_apdb_add_rrst_to_model",uVar10);
                          }
LAB_005febd8:
                          if (iVar2 != 0) {
                            cJSON_Delete(iVar2);
                          }
                          goto LAB_005febe8;
                        }
                        cJSON_AddItemToObject(iVar2,"feature_involved",iVar3);
                        memset(local_120,0,200);
                        iVar3 = _apdb_parse_rrst_region_code_list_from_apdb
                                          (local_120,*(int *)(iVar9 + 0x34) + iVar14 + 9);
                        if (iVar3 != 0) {
                          if (apdb_err_switch != 0) {
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed parse region_list from apdb.\n";
                            uVar10 = 0x1826;
                            goto LAB_005ff078;
                          }
                          goto LAB_005febd8;
                        }
                        iVar3 = cJSON_CreateString(local_120);
                        if (iVar3 == 0) {
                          if (apdb_err_switch != 0) {
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json obj of region_list2.\n";
                            uVar10 = 0x182c;
                            goto LAB_005ff078;
                          }
                          goto LAB_005febd8;
                        }
                        cJSON_AddItemToObject(iVar2,"region_list",iVar3);
                        memset(local_120,0,200);
                        snprintf(local_120,200,"%d",
                                 *(undefined4 *)(*(int *)(iVar9 + 0x34) + iVar14 + 4));
                        iVar3 = cJSON_CreateString(local_120);
                        if (iVar3 == 0) {
                          if (apdb_err_switch != 0) {
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json obj of table_index.\n";
                            uVar10 = 0x1838;
                            goto LAB_005ff078;
                          }
                          goto LAB_005febd8;
                        }
                        cJSON_AddItemToObject(iVar2,"table_index",iVar3);
                        memset(local_120,0,200);
                        snprintf(local_120,200,"%d",
                                 (uint)*(byte *)(*(int *)(iVar9 + 0x34) + iVar14 + 8));
                        iVar3 = cJSON_CreateString(local_120);
                        if (iVar3 == 0) {
                          if (apdb_err_switch != 0) {
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json obj of radio_num.\n";
                            uVar10 = 0x1844;
                            goto LAB_005ff078;
                          }
                          goto LAB_005febd8;
                        }
                        cJSON_AddItemToObject(iVar2,"radio_num",iVar3);
                        local_40 = cJSON_CreateArray();
                        if (local_40 == 0) {
                          if (apdb_err_switch != 0) {
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json_radio_id_array_obj.\n";
                            uVar10 = 0x184e;
                            goto LAB_005ff078;
                          }
                          goto LAB_005febd8;
                        }
                        local_54 = cJSON_CreateArray();
                        if (local_54 == 0) {
                          if (apdb_err_switch != 0) {
                            printf("[APDB_ERROR]%s()/line %d : Failed create json_radio_abs_status_array_obj.\n"
                                   ,"_apdb_add_rrst_to_model",0x1855);
                          }
                          iVar3 = 0;
                          iVar5 = 0;
                          iVar4 = 0;
LAB_005feb8c:
                          cJSON_Delete(local_40);
                          if (local_54 != 0) {
                            cJSON_Delete(local_54);
                          }
                          if (iVar4 != 0) {
                            cJSON_Delete(iVar4);
                          }
                          if (iVar5 != 0) {
                            cJSON_Delete(iVar5);
                          }
                          if (iVar3 != 0) {
                            cJSON_Delete(iVar3);
                          }
                          goto LAB_005febd8;
                        }
                        iVar4 = cJSON_CreateArray();
                        if (iVar4 == 0) {
                          if (apdb_err_switch == 0) {
                            iVar3 = 0;
                            iVar5 = 0;
                          }
                          else {
                            iVar3 = 0;
                            printf("[APDB_ERROR]%s()/line %d : Failed create json_bind_id_array_obj.\n"
                                   ,"_apdb_add_rrst_to_model",0x185c);
                            iVar5 = 0;
                          }
                          goto LAB_005feb8c;
                        }
                        iVar5 = cJSON_CreateArray();
                        if (iVar5 == 0) {
                          iVar3 = 0;
                          if (apdb_err_switch != 0) {
                            printf("[APDB_ERROR]%s()/line %d : Failed create json_bandwidth_array_obj.\n"
                                   ,"_apdb_add_rrst_to_model",0x1863);
                            iVar3 = 0;
                          }
                          goto LAB_005feb8c;
                        }
                        iVar3 = cJSON_CreateArray();
                        if (iVar3 == 0) {
                          if (apdb_err_switch != 0) {
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json_channel_array_obj.\n";
                            uVar10 = 0x186a;
LAB_005fec1c:
                            printf(pcVar7,"_apdb_add_rrst_to_model",uVar10);
                          }
                          goto LAB_005feb8c;
                        }
                        local_58 = iVar2;
                        for (local_3c = 0; iVar2 = local_58,
                            local_3c < (int)(uint)*(byte *)(*(int *)(iVar9 + 0x34) + iVar14 + 8);
                            local_3c = local_3c + 1) {
                          memset(local_120,0,200);
                          iVar12 = local_3c * 0x74;
                          snprintf(local_120,200,"%d",
                                   (uint)*(byte *)(*(int *)(iVar9 + 0x34) + iVar14 + iVar12 + 0x98))
                          ;
                          iVar2 = cJSON_CreateString(local_120);
                          if (iVar2 == 0) {
                            iVar2 = local_58;
                            if (apdb_err_switch == 0) goto LAB_005feb8c;
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json obj of radio_id.\n";
                            uVar10 = 0x1876;
                            goto LAB_005fec1c;
                          }
                          cJSON_AddItemToArray(local_40,iVar2);
                          memset(local_120,0,200);
                          snprintf(local_120,200,"%d",
                                   (uint)*(byte *)(*(int *)(iVar9 + 0x34) + iVar14 + iVar12 + 0x9a))
                          ;
                          iVar2 = cJSON_CreateString(local_120);
                          if (iVar2 == 0) {
                            iVar2 = local_58;
                            if (apdb_err_switch == 0) goto LAB_005feb8c;
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json obj of bind_id.\n";
                            uVar10 = 0x1882;
                            goto LAB_005fec1c;
                          }
                          cJSON_AddItemToArray(iVar4,iVar2);
                          memset(local_120,0,200);
                          snprintf(local_120,200,"%d",
                                   *(undefined4 *)(*(int *)(iVar9 + 0x34) + iVar14 + iVar12 + 0x2c))
                          ;
                          iVar2 = cJSON_CreateString(local_120);
                          if (iVar2 == 0) {
                            iVar2 = local_58;
                            if (apdb_err_switch == 0) goto LAB_005feb8c;
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json obj of radio_abstract_status.\n"
                            ;
                            uVar10 = 0x188e;
                            goto LAB_005fec1c;
                          }
                          cJSON_AddItemToArray(local_54,iVar2);
                          memset(local_120,0,200);
                          iVar2 = _apdb_parse_rrst_bandwidth_from_apdb
                                            (local_120,
                                             *(undefined1 *)
                                              (*(int *)(iVar9 + 0x34) + iVar14 + iVar12 + 0x99));
                          if (iVar2 == -1) {
                            iVar2 = local_58;
                            if (apdb_err_switch == 0) goto LAB_005feb8c;
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : parse_rrst_bandwidth_from_apdb fail\n";
                            uVar10 = 0x1898;
                            goto LAB_005fec1c;
                          }
                          iVar2 = cJSON_CreateString(local_120);
                          if (iVar2 == 0) {
                            iVar2 = local_58;
                            if (apdb_err_switch == 0) goto LAB_005feb8c;
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json obj of bandwidth.\n";
                            uVar10 = 0x189e;
                            goto LAB_005fec1c;
                          }
                          cJSON_AddItemToArray(iVar5,iVar2);
                          iVar2 = *(int *)(iVar9 + 0x34) + iVar14 + iVar12;
                          local_30 = *(undefined4 *)(iVar2 + 0x9c);
                          local_2c = (int)*(short *)(iVar2 + 0x30);
                          memset(local_120,0,200);
                          iVar2 = _apdb_parse_rrst_channel_from_apdb
                                            (local_120,
                                             iVar12 + *(int *)(iVar9 + 0x34) + iVar14 + 0x32,
                                             local_2c,local_30);
                          if (iVar2 == -1) {
                            iVar2 = local_58;
                            if (apdb_err_switch == 0) goto LAB_005feb8c;
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : parse_rrst_channel_from_apdb fail\n";
                            uVar10 = 0x18aa;
                            goto LAB_005fec1c;
                          }
                          iVar2 = cJSON_CreateString(local_120);
                          if (iVar2 == 0) {
                            iVar2 = local_58;
                            if (apdb_err_switch == 0) goto LAB_005feb8c;
                            pcVar7 = 
                            "[APDB_ERROR]%s()/line %d : Failed create json obj of channel.\n";
                            uVar10 = 0x18b0;
                            goto LAB_005fec1c;
                          }
                          cJSON_AddItemToArray(iVar3,iVar2);
                        }
                        cJSON_AddItemToObject(local_58,"radio_id",local_40);
                        cJSON_AddItemToObject(iVar2,"radio_abstract_status",local_54);
                        cJSON_AddItemToObject(iVar2,"bind_id",iVar4);
                        cJSON_AddItemToObject(iVar2,"bandwidth",iVar5);
                        cJSON_AddItemToObject(iVar2,"channel",iVar3);
                        cJSON_AddItemToArray(local_48,iVar2);
                      }
                      cJSON_AddItemToObject(local_50,"radioLinkageTable",local_48);
                      if (apdb_debug_switch != 0) {
                        pcVar7 = "[APDB_DEBUG]%s()/line %d : _apdb_add_rrst_to_model success EXIT\n"
                        ;
                        pcVar8 = "_apdb_add_rrst_to_model";
                        uVar10 = 0x18ce;
LAB_005fe2b4:
                        printf(pcVar7,pcVar8,uVar10);
                      }
                    }
                  }
                }
                else if (apdb_debug_switch != 0) {
                  pcVar7 = "[APDB_DEBUG]%s()/line %d : no rrst,no need to add rrst to model\n";
                  pcVar8 = "_apdb_add_model_to_ap";
                  uVar10 = 0x19d6;
                  goto LAB_005fe2b4;
                }
LAB_005fdd4c:
                local_4c = local_4c + 1;
              } while( true );
            }
            if (apdb_err_switch == 0) {
              return 0xffffffff;
            }
            uVar10 = 0x1c9a;
            local_38 = 0;
          }
        }
      }
    }
  }
LAB_005fdc00:
  printf("[APDB_ERROR]%s()/line %d : Failed create json obj.\n","_apdb_add_ap_to_aplist",uVar10);
  return 0xffffffff;
}

