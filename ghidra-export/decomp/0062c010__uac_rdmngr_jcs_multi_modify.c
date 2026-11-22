// func _uac_rdmngr_jcs_multi_modify @ 0062c010 size=11756

void _uac_rdmngr_jcs_multi_modify(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__s;
  uint uVar6;
  undefined2 uVar10;
  size_t sVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined1 uVar11;
  char *pcVar12;
  char cVar13;
  uint uVar14;
  undefined8 uVar15;
  uint local_548;
  int local_544;
  undefined1 auStack_4f8 [8];
  char local_4f0;
  short local_4ec;
  undefined4 local_4a4;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 local_498;
  undefined2 local_494;
  undefined2 local_492;
  undefined2 local_48e;
  undefined1 local_48c;
  undefined1 local_48b;
  ushort local_48a;
  undefined1 local_488;
  undefined2 local_486;
  undefined2 local_484;
  undefined2 local_482;
  undefined2 local_480;
  undefined1 local_47e;
  undefined1 local_47d;
  undefined1 local_47c;
  undefined1 local_47b;
  undefined1 local_47a;
  undefined1 local_479;
  undefined1 local_478;
  undefined1 local_477;
  undefined1 local_476;
  undefined1 local_475;
  undefined1 local_474;
  undefined1 local_473;
  undefined1 local_472;
  undefined1 local_471;
  undefined1 local_470;
  undefined1 local_46f;
  undefined1 local_46e;
  undefined1 local_46d;
  undefined1 local_46c;
  undefined1 local_46b;
  undefined1 local_463;
  undefined1 local_462;
  undefined1 local_461;
  undefined1 local_460;
  undefined2 local_45e;
  char local_45c;
  char local_45b;
  undefined1 auStack_450 [4];
  int local_44c;
  int local_448;
  int local_444;
  int local_43c;
  short local_432;
  undefined1 auStack_338 [16];
  undefined2 local_328;
  int local_324;
  undefined4 local_2f8;
  undefined1 auStack_120 [128];
  undefined2 local_a0;
  char *local_60;
  uint *local_5c;
  int local_58;
  int local_54;
  uint *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  memset(&local_4a4,0,0x54);
  memset(auStack_4f8,0,0x54);
  memset(auStack_338,0,0x2d8);
  memset(auStack_450,0,0x114);
  iVar2 = rdmngr_profile_get_max_rd_per_ap();
  iVar3 = apmngr_db_get_ap_max();
  iVar4 = apmngr_db_get_template_max();
  iVar5 = apmngr_db_get_sensor_max();
  local_50 = (uint *)FUN_004082a0((iVar3 + iVar4 + iVar5) * iVar2,4,0x6e5);
  if (local_50 == (uint *)0x0) {
    iVar2 = -1;
    if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) {
      __s = (char *)0x0;
    }
    else {
      printf("[RDMNGR_ERROR]%s()/%d no memory!\n","_uac_rdmngr_jcs_multi_modify",0x6e8);
      __s = (char *)0x0;
    }
    goto LAB_0062c2c8;
  }
  local_60 = (char *)FUN_00408450(0x1c16,0x6ec);
  if (local_60 == (char *)0x0) {
    if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d no memory!\n","_uac_rdmngr_jcs_multi_modify",0x6ef);
    }
    __s = (char *)0x0;
    iVar2 = -1;
  }
  else {
    __s = (char *)FUN_00408450(0x1c16,0x6f3);
    if (__s == (char *)0x0) {
      iVar2 = -1;
      if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        pcVar12 = "[RDMNGR_ERROR]%s()/%d no memory!\n";
        uVar8 = 0x6f6;
LAB_0062c694:
        iVar2 = -1;
        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",uVar8);
      }
    }
    else {
      memset(__s,0,0x1c16);
      iVar2 = json_object_object_get(param_1,"multi_id_list");
      if (iVar2 == 0) {
        iVar2 = -1;
        if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          pcVar12 = "[RDMNGR_ERROR]%s()/%d multi_id_list not found!\n";
          uVar8 = 0x6fe;
          goto LAB_0062c694;
        }
      }
      else {
        memset(local_60,0,0x1c16);
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 6) {
          pcVar12 = (char *)json_object_get_string(iVar2);
          strncpy(local_60,pcVar12,0x1c15);
          local_60[0x1c15] = '\0';
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_rdmngr_jcs_multi_modify",0x703);
          }
          strncpy(local_60,"",0x1c15);
          local_60[0x1c15] = '\0';
        }
        iVar2 = rdmngr_profile_get_max_rd_per_ap();
        iVar3 = apmngr_db_get_ap_max();
        iVar4 = apmngr_db_get_template_max();
        iVar5 = apmngr_db_get_sensor_max();
        local_40 = FUN_0062784c(local_60,local_50,(iVar3 + iVar4 + iVar5) * iVar2);
        if (local_40 < 1) {
          iVar2 = -1;
          if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[RDMNGR_ERROR]%s()/%d _uac_rdmngr_util_str_split() fail, str: %s!\n",
                   "_uac_rdmngr_jcs_multi_modify",0x708,local_60);
          }
        }
        else {
          local_44 = 0;
          local_54 = -2;
          iVar2 = -1;
          local_5c = local_50;
          local_58 = -2;
          do {
            uVar6 = atoi((char *)*local_5c);
            memset(&local_4a4,0,0x54);
            memset(auStack_338,0,0x2d8);
            iVar3 = rdmngr_db_rd_entry_get(uVar6,&local_4a4);
            if (iVar3 == 0) {
              uVar10 = rdmngr_db_generate_ap_id(uVar6);
              iVar3 = apmngr_db_entry_get_by_id(uVar10,auStack_338);
              if (iVar3 == 0) {
                memcpy(auStack_4f8,&local_4a4,0x54);
                iVar3 = json_object_object_get(param_1,"freq_band");
                if (iVar3 != 0) {
                  iVar4 = json_object_get_type(iVar3);
                  if (iVar4 == 3) {
                    uVar11 = json_object_get_int(iVar3);
                    local_49c = CONCAT13(uVar11,local_49c._1_3_);
                  }
                  else {
                    iVar4 = json_object_get_type();
                    if (iVar4 == 2) {
                      uVar15 = json_object_get_double(iVar3);
                      uVar11 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      local_49c = CONCAT13(uVar11,local_49c._1_3_);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                               ,"_uac_rdmngr_jcs_multi_modify",0x721);
                      }
                      local_49c = CONCAT13(0xff,local_49c._1_3_);
                    }
                  }
                }
                if (local_49c._0_1_ != local_4f0) {
                  iVar3 = apdb_support_multi_radio_by_id(local_2f8,auStack_120,uVar6 & 0xf);
                  if (iVar3 == 0) {
                    iVar2 = 0;
                    if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                      pcVar12 = 
                      "[RDMNGR_DEBUG]%s()/%d radio %d not support multi radio, can not change.\n";
                      uVar8 = 0x725;
                      uVar14 = uVar6;
                      goto LAB_0062c288;
                    }
                    goto LAB_0062c1d4;
                  }
                }
                if (local_49c._0_1_ != local_4f0) {
                  _uac_rdmngr_para_adjust_by_freq(&local_4a4,local_2f8);
                }
                local_3c = uVar6 & 0xf;
                local_548 = (uint)local_49c._0_1_;
                iVar3 = apdb_get_radio_by_id(local_2f8,auStack_120,local_3c,auStack_450);
                if (iVar3 == 0) {
                  local_4c = local_44c;
                  local_38 = local_448;
                  local_34 = local_43c;
                  local_30 = local_444;
                  local_48 = (int)local_432;
                  iVar2 = json_object_object_get(param_1,"mode");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      uVar11 = json_object_get_int(iVar2);
                      local_49c._1_3_ = CONCAT12(uVar11,local_49c._2_2_);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        uVar11 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                        local_49c._1_3_ = CONCAT12(uVar11,local_49c._2_2_);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x739);
                        }
                        local_49c._1_3_ = CONCAT12(0xff,local_49c._2_2_);
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"bandwidth");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      uVar11 = json_object_get_int(iVar2);
                      local_49c._2_2_ = CONCAT11(uVar11,(byte)local_49c);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        uVar11 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                        local_49c._2_2_ = CONCAT11(uVar11,(byte)local_49c);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x73c);
                        }
                        local_49c._2_2_ = CONCAT11(0xff,(byte)local_49c);
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"channel");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      uVar10 = json_object_get_int(iVar2);
                      local_498 = CONCAT22(uVar10,local_498._2_2_);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        uVar10 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                        local_498 = CONCAT22(uVar10,local_498._2_2_);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x73f);
                        }
                        local_498 = CONCAT22(0xffff,local_498._2_2_);
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"power_level");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_48b = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_48b = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x742);
                        }
                        local_48b = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"max_usr");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_48a = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_48a = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x745);
                        }
                        local_48a = 0xffff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"antenna");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_488 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_488 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x748);
                        }
                        local_488 = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"frag_thr");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_486 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_486 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x74b);
                        }
                        local_486 = 0xffff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"bcn_intvl");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_484 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_484 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x74e);
                        }
                        local_484 = 0xffff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"manage_frame_rate");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_47b = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_47b = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x751);
                        }
                        local_47b = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"rts_thr");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_480 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_480 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x754);
                        }
                        local_480 = 0xffff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"dtim_prd");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_47e = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_47e = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x757);
                        }
                        local_47e = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,&DAT_006fe1c0);
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    iVar4 = 0;
                    if (iVar3 == 6) {
                      do {
                        while( true ) {
                          if (onoff_map <= iVar4) {
                            if (jcs_err_switch == 0) goto LAB_0062cad4;
                            pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
                            goto LAB_0062e068;
                          }
                          iVar3 = iVar4 * 0x10;
                          pcVar12 = *(char **)(PTR__mt_onoff_00731f8c + iVar3);
                          if (pcVar12 != (char *)0x0) break;
                          iVar4 = iVar4 + 1;
                        }
                        pcVar9 = (char *)json_object_get_string(iVar2);
                        iVar5 = strcmp(pcVar12,pcVar9);
                        iVar4 = iVar4 + 1;
                      } while (iVar5 != 0);
                      local_47d = (undefined1)*(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 + 0xc);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_0062e068:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x75a);
                      }
LAB_0062cad4:
                      if (jcs_err_switch == 0) {
                        local_47d = 0xff;
                      }
                      else {
                        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                               "_uac_rdmngr_jcs_multi_modify",0x75a);
                        local_47d = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"brd_probe");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < onoff_map) {
                        pcVar12 = *(char **)(PTR__mt_onoff_00731f8c + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_47c = (undefined1)
                                        *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 * 0x10 + 0xc)
                            ;
                            goto LAB_0062cb3c;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062e014:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x75d);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062e014;
                    }
                    if (jcs_err_switch == 0) {
                      local_47c = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x75d);
                      local_47c = 0xff;
                    }
                  }
LAB_0062cb3c:
                  iVar2 = json_object_object_get(param_1,"short_gi");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < onoff_map) {
                        pcVar12 = *(char **)(PTR__mt_onoff_00731f8c + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_47a = (undefined1)
                                        *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 * 0x10 + 0xc)
                            ;
                            goto LAB_0062cb90;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062e030:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x760);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062e030;
                    }
                    if (jcs_err_switch == 0) {
                      local_47a = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x760);
                      local_47a = 0xff;
                    }
                  }
LAB_0062cb90:
                  iVar2 = json_object_object_get(param_1,"rssi_restrict");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < onoff_map) {
                        pcVar12 = *(char **)(PTR__mt_onoff_00731f8c + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_479 = (undefined1)
                                        *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 * 0x10 + 0xc)
                            ;
                            goto LAB_0062cbe4;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062e04c:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x763);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062e04c;
                    }
                    if (jcs_err_switch == 0) {
                      local_479 = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x763);
                      local_479 = 0xff;
                    }
                  }
LAB_0062cbe4:
                  iVar2 = json_object_object_get(param_1,"rssi_restrict_val");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_478 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_478 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x766);
                        }
                        local_478 = 0xff;
                      }
                    }
                  }
                  iVar2 = rdmngr_profile_support_rssi_kick();
                  if (iVar2 != 0) {
                    iVar2 = json_object_object_get(param_1,"rssi_kick");
                    if (iVar2 != 0) {
                      iVar3 = json_object_get_type(iVar2);
                      iVar4 = 0;
                      if (iVar3 == 6) {
                        do {
                          while( true ) {
                            if (onoff_map <= iVar4) {
                              if (jcs_err_switch == 0) goto LAB_0062ddc4;
                              pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
                              goto LAB_0062eb70;
                            }
                            iVar3 = iVar4 * 0x10;
                            pcVar12 = *(char **)(PTR__mt_onoff_00731f8c + iVar3);
                            if (pcVar12 != (char *)0x0) break;
                            iVar4 = iVar4 + 1;
                          }
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar5 = strcmp(pcVar12,pcVar9);
                          iVar4 = iVar4 + 1;
                        } while (iVar5 != 0);
                        local_477 = (undefined1)
                                    *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 + 0xc);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n"
                          ;
LAB_0062eb70:
                          printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x76a);
                        }
LAB_0062ddc4:
                        if (jcs_err_switch == 0) {
                          local_477 = 0xff;
                        }
                        else {
                          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                                 "_uac_rdmngr_jcs_multi_modify",0x76a);
                          local_477 = 0xff;
                        }
                      }
                    }
                    iVar2 = json_object_object_get(param_1,"rssi_kick_val");
                    if (iVar2 != 0) {
                      iVar3 = json_object_get_type(iVar2);
                      if (iVar3 == 3) {
                        local_476 = json_object_get_int(iVar2);
                      }
                      else {
                        iVar3 = json_object_get_type();
                        if (iVar3 == 2) {
                          uVar15 = json_object_get_double(iVar2);
                          local_476 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                        }
                        else {
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                   ,"_uac_rdmngr_jcs_multi_modify",0x76d);
                          }
                          local_476 = 0xff;
                        }
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"chLock");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_463 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_463 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x770);
                        }
                        local_463 = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"pwrLock");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_462 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_462 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x773);
                        }
                        local_462 = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"scanMode");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_461 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_461 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x776);
                        }
                        local_461 = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"scanType");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_460 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_460 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x779);
                        }
                        local_460 = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"scanIntvl");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_45e = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_45e = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x77c);
                        }
                        local_45e = 0xffff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"airtime");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < onoff_map) {
                        pcVar12 = *(char **)(PTR__mt_onoff_00731f8c + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_482 = (undefined2)
                                        *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 * 0x10 + 0xc)
                            ;
                            goto LAB_0062ce58;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062dfc0:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x782);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062dfc0;
                    }
                    if (jcs_err_switch == 0) {
                      local_482 = 0xffff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x782);
                      local_482 = 0xffff;
                    }
                  }
LAB_0062ce58:
                  iVar2 = json_object_object_get(param_1,&DAT_00707dbc);
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      uVar11 = json_object_get_int(iVar2);
                      local_498._2_2_ = CONCAT11(uVar11,(undefined1)local_498);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        uVar11 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                        local_498._2_2_ = CONCAT11(uVar11,(undefined1)local_498);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x785);
                        }
                        local_498._2_2_ = CONCAT11(0xff,(undefined1)local_498);
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"rf_chnl_reselect");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_45b = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_45b = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x788);
                        }
                        local_45b = -1;
                      }
                    }
                  }
                  if (local_498._2_1_ == '\0') {
                    iVar2 = json_object_object_get(param_1,"rf_online_switch");
                    if (iVar2 != 0) {
                      iVar3 = json_object_get_type(iVar2);
                      iVar4 = 0;
                      if (iVar3 == 6) {
                        do {
                          while( true ) {
                            if (onoff_map <= iVar4) {
                              if (jcs_err_switch == 0) goto LAB_0062dbf8;
                              pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
                              goto LAB_0062eaf8;
                            }
                            iVar3 = iVar4 * 0x10;
                            pcVar12 = *(char **)(PTR__mt_onoff_00731f8c + iVar3);
                            if (pcVar12 != (char *)0x0) break;
                            iVar4 = iVar4 + 1;
                          }
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar5 = strcmp(pcVar12,pcVar9);
                          iVar4 = iVar4 + 1;
                        } while (iVar5 != 0);
                        local_48c = (undefined1)
                                    *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 + 0xc);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n"
                          ;
LAB_0062eaf8:
                          printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x78d);
                        }
LAB_0062dbf8:
                        if (jcs_err_switch == 0) {
                          local_48c = 0xff;
                        }
                        else {
                          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                                 "_uac_rdmngr_jcs_multi_modify",0x78d);
                          local_48c = 0xff;
                        }
                      }
                    }
                    iVar2 = json_object_object_get(param_1,"rf_check_circle");
                    if (iVar2 != 0) {
                      iVar3 = json_object_get_type(iVar2);
                      if (iVar3 == 3) {
                        local_494 = json_object_get_int(iVar2);
                      }
                      else {
                        iVar3 = json_object_get_type();
                        if (iVar3 == 2) {
                          uVar15 = json_object_get_double(iVar2);
                          local_494 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                        }
                        else {
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                   ,"_uac_rdmngr_jcs_multi_modify",0x790);
                          }
                          local_494 = 0xffff;
                        }
                      }
                    }
                    iVar2 = json_object_object_get(param_1,"rf_chnl_occup_threshold");
                    if (iVar2 != 0) {
                      iVar3 = json_object_get_type(iVar2);
                      if (iVar3 == 3) {
                        local_492 = json_object_get_int(iVar2);
                      }
                      else {
                        iVar3 = json_object_get_type();
                        if (iVar3 == 2) {
                          uVar15 = json_object_get_double(iVar2);
                          local_492 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                        }
                        else {
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                   ,"_uac_rdmngr_jcs_multi_modify",0x793);
                          }
                          local_492 = 0xffff;
                        }
                      }
                    }
                    iVar2 = json_object_object_get(param_1,"rf_chnl_tolerance");
                    if (iVar2 != 0) {
                      iVar3 = json_object_get_type(iVar2);
                      if (iVar3 == 3) {
                        local_48e = json_object_get_int(iVar2);
                      }
                      else {
                        iVar3 = json_object_get_type();
                        if (iVar3 == 2) {
                          uVar15 = json_object_get_double(iVar2);
                          local_48e = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                        }
                        else {
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                   ,"_uac_rdmngr_jcs_multi_modify",0x796);
                          }
                          local_48e = 0xffff;
                        }
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"reject_limit");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_475 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_475 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x79c);
                        }
                        local_475 = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"reject_enable");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < onoff_map) {
                        pcVar12 = *(char **)(PTR__mt_onoff_00731f8c + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_474 = (undefined1)
                                        *(undefined4 *)(PTR__mt_onoff_00731f8c + iVar3 * 0x10 + 0xc)
                            ;
                            goto LAB_0062cfc0;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062dfa4:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x79f);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062dfa4;
                    }
                    if (jcs_err_switch == 0) {
                      local_474 = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x79f);
                      local_474 = 0xff;
                    }
                  }
LAB_0062cfc0:
                  iVar2 = json_object_object_get(param_1,"reject_diff");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_473 = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_473 = __fixunsdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x7a2);
                        }
                        local_473 = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"downlink_mumimo");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < switch_type_map) {
                        pcVar12 = *(char **)(PTR__mt_switch_type_00758b74 + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_472 = (undefined1)
                                        *(undefined4 *)
                                         (PTR__mt_switch_type_00758b74 + iVar3 * 0x10 + 0xc);
                            goto LAB_0062d06c;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062dfdc:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x7a5);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062dfdc;
                    }
                    if (jcs_err_switch == 0) {
                      local_472 = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x7a5);
                      local_472 = 0xff;
                    }
                  }
LAB_0062d06c:
                  iVar2 = json_object_object_get(param_1,"uplink_mumimo");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < switch_type_map) {
                        pcVar12 = *(char **)(PTR__mt_switch_type_00758b74 + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_471 = (undefined1)
                                        *(undefined4 *)
                                         (PTR__mt_switch_type_00758b74 + iVar3 * 0x10 + 0xc);
                            goto LAB_0062d0c0;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062dff8:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x7a7);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062dff8;
                    }
                    if (jcs_err_switch == 0) {
                      local_471 = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x7a7);
                      local_471 = 0xff;
                    }
                  }
LAB_0062d0c0:
                  iVar2 = json_object_object_get(param_1,"downlink_ofdma");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < switch_type_map) {
                        pcVar12 = *(char **)(PTR__mt_switch_type_00758b74 + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_470 = (undefined1)
                                        *(undefined4 *)
                                         (PTR__mt_switch_type_00758b74 + iVar3 * 0x10 + 0xc);
                            goto LAB_0062d114;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062df18:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x7aa);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062df18;
                    }
                    if (jcs_err_switch == 0) {
                      local_470 = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x7aa);
                      local_470 = 0xff;
                    }
                  }
LAB_0062d114:
                  iVar2 = json_object_object_get(param_1,"uplink_ofdma");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < switch_type_map) {
                        pcVar12 = *(char **)(PTR__mt_switch_type_00758b74 + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_46f = (undefined1)
                                        *(undefined4 *)
                                         (PTR__mt_switch_type_00758b74 + iVar3 * 0x10 + 0xc);
                            goto LAB_0062d168;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062df50:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x7ac);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062df50;
                    }
                    if (jcs_err_switch == 0) {
                      local_46f = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x7ac);
                      local_46f = 0xff;
                    }
                  }
LAB_0062d168:
                  iVar2 = json_object_object_get(param_1,&DAT_00707e84);
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < switch_type_map) {
                        pcVar12 = *(char **)(PTR__mt_switch_type_00758b74 + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_46e = (undefined1)
                                        *(undefined4 *)
                                         (PTR__mt_switch_type_00758b74 + iVar3 * 0x10 + 0xc);
                            goto LAB_0062d1bc;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062df88:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x7af);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062df88;
                    }
                    if (jcs_err_switch == 0) {
                      local_46e = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x7af);
                      local_46e = 0xff;
                    }
                  }
LAB_0062d1bc:
                  iVar2 = json_object_object_get(param_1,"gi_mode");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 3) {
                      local_46d = json_object_get_int(iVar2);
                    }
                    else {
                      iVar3 = json_object_get_type();
                      if (iVar3 == 2) {
                        uVar15 = json_object_get_double(iVar2);
                        local_46d = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_uac_rdmngr_jcs_multi_modify",0x7b2);
                        }
                        local_46d = 0xff;
                      }
                    }
                  }
                  iVar2 = json_object_object_get(param_1,"enable_6g");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < switch_type_map) {
                        pcVar12 = *(char **)(PTR__mt_switch_type_00758b74 + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_46c = (undefined1)
                                        *(undefined4 *)
                                         (PTR__mt_switch_type_00758b74 + iVar3 * 0x10 + 0xc);
                            goto LAB_0062d268;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062df6c:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x7b5);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062df6c;
                    }
                    if (jcs_err_switch == 0) {
                      local_46c = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x7b5);
                      local_46c = 0xff;
                    }
                  }
LAB_0062d268:
                  iVar2 = json_object_object_get(param_1,"enable_6g_psc");
                  if (iVar2 != 0) {
                    iVar3 = json_object_get_type(iVar2);
                    if (iVar3 == 6) {
                      iVar3 = 0;
                      while (iVar3 < switch_type_map) {
                        pcVar12 = *(char **)(PTR__mt_switch_type_00758b74 + iVar3 * 0x10);
                        if (pcVar12 == (char *)0x0) {
                          iVar3 = iVar3 + 1;
                        }
                        else {
                          pcVar9 = (char *)json_object_get_string(iVar2);
                          iVar4 = strcmp(pcVar12,pcVar9);
                          if (iVar4 == 0) {
                            local_46b = (undefined1)
                                        *(undefined4 *)
                                         (PTR__mt_switch_type_00758b74 + iVar3 * 0x10 + 0xc);
                            goto LAB_0062d2bc;
                          }
                          iVar3 = iVar3 + 1;
                        }
                      }
                      if (jcs_err_switch != 0) {
                        pcVar12 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_0062df34:
                        printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",0x7b7);
                      }
                    }
                    else if (jcs_err_switch != 0) {
                      pcVar12 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
                      goto LAB_0062df34;
                    }
                    if (jcs_err_switch == 0) {
                      local_46b = 0xff;
                    }
                    else {
                      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                             "_uac_rdmngr_jcs_multi_modify",0x7b7);
                      local_46b = 0xff;
                    }
                  }
LAB_0062d2bc:
                  iVar2 = _uac_rdmngr_check_rd_chnl(local_2f8,auStack_120,local_3c,&local_4a0);
                  if (iVar2 != 1) {
                    if ((rdmngr_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0))
                    {
                      local_544 = (int)local_4ec;
                      local_548 = uVar6;
                      printf("[RDMNGR_WARNING]%s()/%d channel(%d) of radioId(%d) is Invalid, remains as old value(%d).\n"
                             ,"_uac_rdmngr_jcs_multi_modify",0x7bd,(int)local_498._0_2_);
                    }
                    local_498 = CONCAT22(local_4ec,local_498._2_2_);
                  }
                  iVar2 = memcmp(auStack_4f8,&local_4a4,0x54);
                  if (iVar2 == 0) {
                    iVar2 = 0;
                    if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                      printf("[RDMNGR_DEBUG]%s()/%d no change.\n","_uac_rdmngr_jcs_multi_modify",
                             0x7c3);
                    }
                  }
                  else {
                    if (local_49c._1_1_ == '\t') {
                      cVar1 = '\t';
                      if (local_4c == 0) {
                        local_49c._1_3_ = CONCAT12(7,local_49c._2_2_);
                        goto LAB_0062d384;
                      }
                    }
                    else {
LAB_0062d384:
                      cVar1 = local_49c._1_1_;
                    }
                    if ((byte)(cVar1 - 10U) < 2) {
                      if (local_38 == 0) {
                        if (local_49c._0_1_ == '\0') {
                          local_49c._1_3_ = CONCAT12(6,local_49c._2_2_);
                          local_49c = (uint)local_49c._1_3_;
                        }
                        else {
                          if (local_49c._0_1_ != '\x01') goto LAB_0062d3a0;
                          uVar11 = 9;
                          if (local_4c == 0) {
                            uVar11 = 7;
                          }
                          local_49c._1_3_ = CONCAT12(uVar11,local_49c._2_2_);
                          local_49c = CONCAT13(1,local_49c._1_3_);
                        }
                        goto LAB_0062d39c;
                      }
                    }
                    else {
LAB_0062d39c:
                    }
LAB_0062d3a0:
                    cVar1 = local_49c._0_1_;
                    if ((byte)(local_49c._1_1_ - 0xc) < 2) {
                      cVar13 = local_49c._2_1_;
                      if (local_34 == 0) {
                        uVar11 = 10;
                        if (local_49c._0_1_ != '\0') {
                          if (local_49c._0_1_ != '\x01') goto LAB_0062d3bc;
                          if (local_38 == 0) {
                            uVar11 = 9;
                            if (local_4c == 0) {
                              local_49c._1_3_ = CONCAT12(7,local_49c._2_2_);
                              local_49c = CONCAT13(1,local_49c._1_3_);
                              goto LAB_0062d3b4;
                            }
                          }
                          else {
                            uVar11 = 0xb;
                          }
                        }
                        local_49c._1_3_ = CONCAT12(uVar11,local_49c._2_2_);
                        goto LAB_0062d3b4;
                      }
                    }
                    else {
LAB_0062d3b4:
                      cVar13 = local_49c._2_1_;
                    }
LAB_0062d3bc:
                    if (cVar13 == '\x03') {
                      if ((cVar1 == '\0') || (local_4c == 0)) {
                        local_49c._2_2_ = CONCAT11(2,(byte)local_49c);
                        goto LAB_0062d3c4;
                      }
                    }
                    else {
LAB_0062d3c4:
                    }
                    cVar1 = local_49c._0_1_;
                    if ((local_49c._2_1_ == '\x05') &&
                       ((local_49c._0_1_ == '\0' || (local_30 == 0)))) {
                      local_49c._2_2_ = CONCAT11(2,(byte)local_49c);
                    }
                    if (cVar1 == '\x01') {
                      if (((local_49c._1_1_ != '\0') && (local_49c._2_1_ != '\0')) &&
                         (local_498._0_2_ == 0xa5)) {
                        local_498 = CONCAT22(0xffff,local_498._2_2_);
                      }
                      if (local_49c._2_1_ == '\x05') {
                        if ((0x94 < local_498._0_2_) && (local_498._0_2_ < 0xa6)) {
                          local_498 = CONCAT22(0xffff,local_498._2_2_);
                        }
                      }
                    }
                    iVar2 = apdb_is_hdap_by_id(local_2f8,auStack_120);
                    if (iVar2 != 0) {
                      if (((int)local_498._0_2_ - 2U < 0xc) && (local_498._0_2_ != 0xb)) {
                        local_498 = CONCAT22(0xffff,local_498._2_2_);
                      }
                    }
                    if ((((((local_49c._1_1_ - 3 < 2) || (local_49c._1_1_ == 6)) ||
                          (local_49c._1_1_ == 7)) ||
                         ((local_49c._1_1_ == 8 || (local_49c._1_1_ == 9)))) ||
                        ((local_49c._1_1_ == 10 ||
                         ((local_49c._1_1_ == 0xb || (local_49c._1_1_ == 0xc)))))) ||
                       (local_49c._1_1_ == 0xd)) {
                      local_47d = 1;
                      local_486 = 0x92a;
                      if (local_49c._1_1_ - 10 < 2) {
                        local_47a = 1;
                      }
                    }
                    else {
                      local_47a = 0;
                      local_49c._2_2_ = CONCAT11(2,(byte)local_49c);
                    }
                    if ((0 < local_48) && (local_48 < (int)(uint)local_48a)) {
                      local_48a = (ushort)local_48;
                    }
                    if (local_49c._1_1_ == '\0') {
                      if (rdmngr_debug_switch == 0) {
                        local_49c._2_2_ = (ushort)(byte)local_49c;
                      }
                      else {
                        iVar2 = is_target_debug_ap();
                        if (iVar2 == 0) {
                          local_49c._2_2_ = (ushort)(byte)local_49c;
                        }
                        else {
                          printf("[RDMNGR_DEBUG]%s()/%d set 11a\'s bandwith to 20M.\n",
                                 "_uac_rdmngr_jcs_multi_modify",0x833);
                          local_49c._2_2_ = (ushort)(byte)local_49c;
                        }
                      }
                    }
                    iVar2 = rdmngr_db_rd_entry_set(&local_4a4);
                    if (iVar2 == 0) {
                      rdmngr_db_rd_update(uVar6,2);
                      rdmngr_callback_proc(2,uVar6,auStack_4f8,&local_4a4);
                    }
                    iVar3 = (int)local_498._0_2_;
                    if (local_45c != '\0') {
                      iVar3 = rdmngr_db_update_reinit_state(uVar6);
                      if (iVar3 != 0) {
                        iVar2 = -1;
                        if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
                        goto LAB_0062c2ac;
                        pcVar12 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_update_reinit_state() failed.\n";
                        uVar8 = 0x842;
                        goto LAB_0062c694;
                      }
                      iVar3 = apmngr_checksum_update(auStack_338,0);
                      if (iVar3 != 0) {
                        iVar2 = -1;
                        if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
                        goto LAB_0062c2ac;
                        pcVar12 = "[RDMNGR_ERROR]%s()/%d update md5 failed.\n";
                        uVar8 = 0x848;
                        goto LAB_0062c694;
                      }
                      uVar8 = rdmngr_db_generate_ap_id(uVar6);
                      iVar4 = rdmngr_wtp_pkt_send(uVar8,&local_4a4);
                      iVar3 = (int)local_498._0_2_;
                      if (iVar4 == 0) {
                        if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)
                           ) {
                          printf("[RDMNGR_DEBUG]%s()/%d shutdown radio %d OK.\n",
                                 "_uac_rdmngr_jcs_multi_modify",0x84e,uVar6);
                        }
                        rdmngr_callback_proc(0,uVar6,0,0);
                        uVar8 = rdmngr_db_generate_ap_id(uVar6);
                        iVar4 = rdmngr_wtp_pkt_send(uVar8,&local_4a4);
                        iVar3 = (int)local_498._0_2_;
                        if (iVar4 == 0) {
                          if ((rdmngr_debug_switch != 0) &&
                             (iVar3 = is_target_debug_ap(1), iVar3 != 0)) {
                            printf("[RDMNGR_DEBUG]%s()/%d open radio %d OK.\n",
                                   "_uac_rdmngr_jcs_multi_modify",0x852,uVar6);
                          }
                          rdmngr_callback_proc(1,uVar6,0,0);
                          iVar3 = (int)local_498._0_2_;
                        }
                      }
                    }
                    if (local_4ec != iVar3) {
                      if (local_49c._0_1_ == '\0') {
                        if (local_58 == -2) {
                          local_58 = iVar3;
                        }
                      }
                      else if ((local_49c._0_1_ == '\x01') && (local_54 == -2)) {
                        local_54 = iVar3;
                      }
                    }
                    sVar7 = strlen(__s);
                    iVar3 = atoi((char *)*local_5c);
                    sprintf(__s + sVar7,"%d,",iVar3);
                    for (uVar14 = 0; uVar14 < 0x44; uVar14 = uVar14 + 1) {
                      *(undefined1 *)((int)&local_548 + uVar14) =
                           *(undefined1 *)((int)&local_494 + uVar14);
                    }
                    iVar3 = FUN_006270b4(local_4a4,local_4a0,local_49c,local_498);
                    if (iVar3 != 0) {
                      iVar2 = -1;
                      if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
                      goto LAB_0062c2ac;
                      pcVar12 = "[RDMNGR_ERROR]%s()/%d _uac_rdmngr_linked_modify() failed.\n";
                      uVar8 = 0x865;
                      goto LAB_0062c694;
                    }
                    iVar3 = apdb_is_hdap_by_id(local_2f8,auStack_120);
                    if (iVar3 != 0) {
                      uVar8 = rdmngr_db_generate_rd_id(local_a0,uVar6 & 0xf);
                      sVar7 = strlen(__s);
                      sprintf(__s + sVar7,"%d,",uVar8);
                    }
                    if (local_45b != '\0') {
                      rdmngr_db_rd_entry_channel_reselect_reset(uVar6);
                    }
                    if (((local_324 == 1) || (local_324 == 3)) || (local_324 == 2)) {
                      _mesh_sync_rf_entry_to_re_handle(local_328);
                    }
                  }
                }
                else if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  pcVar12 = "[RDMNGR_ERROR]%s()/%d rd_id:%s, apdb_get_radio_by_id() failed.\n";
                  uVar8 = 0x730;
                  uVar14 = *local_5c;
                  goto LAB_0062c288;
                }
              }
              else if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                pcVar12 = "[RDMNGR_ERROR]%s()/%d rd_id:%s, apmngr_db_entry_get_by_id() failed.\n";
                uVar8 = 0x71a;
                uVar14 = *local_5c;
                goto LAB_0062c288;
              }
            }
            else if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              pcVar12 = "[RDMNGR_ERROR]%s()/%d rd_id:%s, rdmngr_db_rd_entry_get() failed.\n";
              uVar8 = 0x714;
              uVar14 = *local_5c;
LAB_0062c288:
              printf(pcVar12,"_uac_rdmngr_jcs_multi_modify",uVar8,uVar14);
            }
LAB_0062c1d4:
            local_44 = local_44 + 1;
            local_5c = local_5c + 1;
          } while (local_44 != local_40);
          if (local_58 != -2) {
            local_498 = CONCAT22((short)local_58,local_498._2_2_);
            if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[RDMNGR_DEBUG]%s()/%d rd_entry.rd_cfg.chnl:%d\n",
                     "_uac_rdmngr_jcs_multi_modify",0x87b,(int)local_498._0_2_);
            }
            rdmngr_callback_proc(5,uVar6,auStack_4f8,&local_4a4);
          }
          if (local_54 != -2) {
            local_498 = CONCAT22((short)local_54,local_498._2_2_);
            if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[RDMNGR_DEBUG]%s()/%d rd_entry.rd_cfg.chnl:%d\n",
                     "_uac_rdmngr_jcs_multi_modify",0x881,(int)local_498._0_2_);
            }
            rdmngr_callback_proc(5,uVar6,auStack_4f8,&local_4a4);
          }
        }
      }
    }
  }
LAB_0062c2ac:
  FUN_00407df0(local_50);
  if (local_60 != (char *)0x0) {
    FUN_00407df0(local_60);
  }
LAB_0062c2c8:
  sVar7 = strlen(__s);
  if (1 < sVar7) {
    __s[sVar7 - 1] = '\0';
    uVar8 = json_object_new_string(__s);
    json_object_object_add(param_2,"success_id_list",uVar8);
  }
  if (__s != (char *)0x0) {
    FUN_00407df0(__s);
  }
  uVar8 = json_object_new_int(iVar2);
  json_object_object_add(param_2,"result",uVar8);
  if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_jcs_multi_modify() done, ret:%d.\n",
           "_uac_rdmngr_jcs_multi_modify",0x89c,iVar2);
  }
  return;
}

