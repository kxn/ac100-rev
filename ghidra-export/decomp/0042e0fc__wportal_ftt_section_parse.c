// func _wportal_ftt_section_parse @ 0042e0fc size=3364

int _wportal_ftt_section_parse(int param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  size_t sVar12;
  char *pcVar13;
  uint uVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  uint uVar21;
  undefined1 *puVar22;
  size_t sVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 *puVar28;
  char *pcVar29;
  char *pcVar30;
  int iVar31;
  char *pcVar32;
  int iVar33;
  int iVar34;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined2 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined2 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined2 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  uint local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  uint local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined1 auStack_19c [4];
  undefined1 auStack_198 [4];
  undefined1 auStack_194 [4];
  undefined1 auStack_190 [4];
  undefined1 auStack_18c [44];
  undefined1 auStack_160 [64];
  char acStack_120 [64];
  char acStack_e0 [152];
  int local_48;
  uint local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  
  memset(acStack_120,0,0x40);
  memset(acStack_e0,0,0x97);
  local_1b4 = 0;
  local_1b0 = 0;
  local_1ac = 0;
  local_1a8 = 0;
  local_1a4 = 0;
  local_22c = 0;
  local_228 = 0;
  local_224 = 0;
  local_220 = 0;
  local_21c = 0;
  local_240 = 0;
  local_23c = 0;
  local_244 = 0;
  local_248 = 0;
  local_24c = 0;
  local_250 = 0;
  local_1c8 = 0;
  local_1c4 = 0;
  local_1c0 = 0;
  local_1bc = 0;
  local_1b8 = 0;
  local_238 = 0;
  local_234 = 0;
  local_230 = 0;
  local_1dc = 0;
  local_1d8 = 0;
  local_1d4 = 0;
  local_1d0 = 0;
  local_1cc = 0;
  if (param_1 == 0) {
    if (wportal_err_switch == 0) {
      return -1;
    }
    iVar31 = is_target_debug_ap();
    if (iVar31 == 0) {
      return -1;
    }
    pcVar9 = "[WPORTAL_ERR]%s()/%d Wportal free strategy config is empty.\n";
    uVar24 = 0x470;
  }
  else {
    pcVar9 = (char *)FUN_00408450(0x4080,0x474);
    if (pcVar9 != (char *)0x0) {
      *pcVar9 = '\0';
      pcVar9[1] = '\0';
      bVar1 = false;
      pcVar9[2] = '\0';
      iVar31 = 0;
      pcVar9[3] = '\0';
      iVar34 = 0;
      iVar10 = FUN_004081b0(param_1);
      iVar33 = 0;
      local_48 = 0;
      local_3c = 0;
      local_40 = 0;
      local_44 = 0;
      while (iVar10 != 0) {
        pcVar29 = (char *)(iVar10 + 0x10);
        iVar11 = strcmp(pcVar29,"name");
        if (iVar11 == 0) {
          strncpy(acStack_e0,(char *)(iVar10 + 0x90),0x96);
        }
        else {
          iVar11 = strcmp(pcVar29,"match_type");
          if (iVar11 == 0) {
            iVar11 = strcmp((char *)(iVar10 + 0x90),"quintuple");
            local_44 = (uint)(iVar11 != 0);
          }
          else {
            iVar11 = strcmp(pcVar29,"src_ip_set");
            if (iVar11 == 0) {
              memset(acStack_120,0,0x40);
              strncpy(acStack_120,(char *)(iVar10 + 0x90),0x3f);
              iVar11 = strcmp(acStack_120,"null");
              if (iVar11 != 0) {
                pcVar29 = strtok(acStack_120,"/");
                pcVar13 = strtok((char *)0x0,"/");
                FUN_0051a7a8(pcVar29,&local_1b4);
                iVar31 = atoi(pcVar13);
              }
            }
            else {
              iVar11 = strcmp(pcVar29,"dst_ip_set");
              if (iVar11 == 0) {
                memset(acStack_120,0,0x40);
                strncpy(acStack_120,(char *)(iVar10 + 0x90),0x3f);
                iVar11 = strcmp(acStack_120,"null");
                if (iVar11 != 0) {
                  pcVar29 = strtok(acStack_120,"/");
                  pcVar13 = strtok((char *)0x0,"/");
                  FUN_0051a7a8(pcVar29,&local_1c8);
                  local_40 = atoi(pcVar13);
                }
              }
              else {
                iVar11 = strcmp(pcVar29,"src_mac");
                if (iVar11 == 0) {
                  strncpy((char *)&local_22c,(char *)(iVar10 + 0x90),0x11);
                  if (local_22c._0_1_ != '\0') {
                    sscanf((char *)&local_22c,"%2X-%2X-%2X-%2X-%2X-%2X",&local_1a0,auStack_19c,
                           auStack_198,auStack_194,auStack_190,auStack_18c);
                    puVar15 = &local_1a0;
                    iVar11 = 0;
                    do {
                      puVar22 = (undefined1 *)((int)&local_240 + iVar11);
                      uVar24 = *puVar15;
                      iVar11 = iVar11 + 1;
                      puVar15 = puVar15 + 1;
                      *puVar22 = (char)uVar24;
                    } while (iVar11 != 6);
                  }
                }
                else {
                  iVar11 = strcmp(pcVar29,"src_vlan");
                  if (iVar11 == 0) {
                    iVar11 = atoi((char *)(iVar10 + 0x90));
                    iVar33 = 0xfff;
                    if (iVar11 != 0) {
                      iVar33 = iVar11;
                    }
                  }
                  else {
                    iVar11 = strcmp(pcVar29,"src_port");
                    if (iVar11 == 0) {
                      local_1dc = 0;
                      local_1d8 = 0;
                      local_1d4 = 0;
                      local_1d0 = 0;
                      local_1cc = 0;
                      strncpy((char *)&local_1dc,(char *)(iVar10 + 0x90),0x13);
                      puVar15 = &local_244;
                      puVar28 = &local_248;
                    }
                    else {
                      iVar11 = strcmp(pcVar29,"dst_port");
                      if (iVar11 != 0) {
                        iVar11 = strcmp(pcVar29,"protocol");
                        if (iVar11 == 0) {
                          strncpy((char *)&local_238,(char *)(iVar10 + 0x90),9);
                          iVar11 = strcmp((char *)&local_238,"udp");
                          if (iVar11 == 0) {
                            local_3c = 0x11;
                          }
                          else {
                            iVar11 = strcmp((char *)&local_238,"tcp");
                            if (iVar11 == 0) {
                              local_3c = 6;
                            }
                          }
                        }
                        else {
                          iVar11 = strcmp(pcVar29,"enable");
                          if (iVar11 == 0) {
                            iVar11 = strcmp((char *)(iVar10 + 0x90),"on");
                            bVar1 = iVar11 == 0;
                          }
                          else {
                            iVar11 = strcmp(pcVar29,"id");
                            if (iVar11 == 0) {
                              local_48 = atoi((char *)(iVar10 + 0x90));
                            }
                            else {
                              iVar11 = strcmp(pcVar29,"url");
                              if (iVar11 == 0) {
                                sVar23 = strlen((char *)(iVar10 + 0x90));
                                iVar11 = iVar34 * 0x81;
                                sVar12 = 0x80;
                                if (sVar23 < 0x81) {
                                  sVar12 = sVar23;
                                }
                                iVar34 = iVar34 + 1;
                                memcpy(pcVar9 + iVar11,(char *)(iVar10 + 0x90),sVar12);
                                pcVar9[iVar11 + sVar12] = '\0';
                              }
                            }
                          }
                        }
                        goto LAB_0042e264;
                      }
                      local_1dc = 0;
                      local_1d8 = 0;
                      local_1d4 = 0;
                      local_1d0 = 0;
                      local_1cc = 0;
                      strncpy((char *)&local_1dc,(char *)(iVar10 + 0x90),0x13);
                      puVar15 = &local_24c;
                      puVar28 = &local_250;
                    }
                    sscanf((char *)&local_1dc,"%d-%d",puVar15,puVar28);
                  }
                }
              }
            }
          }
        }
LAB_0042e264:
        iVar10 = FUN_00408680(iVar10);
      }
      iVar10 = 0;
      if (bVar1) {
        local_1b4._0_1_ = (char)((uint)local_1b4 >> 0x18);
        local_1c8._0_1_ = (char)((uint)local_1c8 >> 0x18);
        if (local_1b4._0_1_ == '\x01') {
          bVar1 = local_1c8._0_1_ == '\x02';
          if (bVar1) goto LAB_0042e604;
        }
        else if ((local_1b4._0_1_ == '\x02') && (bVar1 = local_1c8._0_1_ == '\x01', bVar1))
        goto LAB_0042e604;
        local_38 = 0;
        if (iVar34 == 0) {
          iVar34 = 1;
        }
        local_34 = -1 << (0x20U - iVar31 & 0x1f);
        iVar10 = 0;
        local_30 = -1 << (0x20U - local_40 & 0x1f);
        pcVar29 = pcVar9;
        for (; local_38 < iVar34; local_38 = local_38 + 1) {
          pcVar13 = (char *)FUN_00408450(0x144,0x4fc);
          if (pcVar13 == (char *)0x0) {
            iVar10 = 0;
            break;
          }
          memset(pcVar13,0,0x144);
          if (local_1b4._0_1_ == '\x02') {
            pcVar13[0x98] = '\0';
            pcVar13[0x99] = '\0';
            pcVar13[0x9a] = '\0';
            pcVar13[0x9b] = '\x02';
          }
          else {
            uVar24 = 2;
            if (local_1c8._0_1_ == '\x02') {
LAB_0042e2fc:
              *(undefined4 *)(pcVar13 + 0x98) = uVar24;
            }
            else if (local_1b4._0_1_ == '\x01') {
              pcVar13[0x98] = '\0';
              pcVar13[0x99] = '\0';
              pcVar13[0x9a] = '\0';
              pcVar13[0x9b] = '\x01';
            }
            else {
              if (local_1c8._0_1_ != '\x01') {
                uVar24 = 3;
                goto LAB_0042e2fc;
              }
              pcVar13[0x98] = '\0';
              pcVar13[0x99] = '\0';
              pcVar13[0x9a] = '\0';
              pcVar13[0x9b] = '\x01';
            }
          }
          if ((*(int *)(pcVar13 + 0x98) == 1) || (*(int *)(pcVar13 + 0x98) == 3)) {
            pcVar13[0xa0] = (char)local_44;
            *(int *)(pcVar13 + 0x9c) = local_48;
            if (local_44 == 0) {
              strncpy(pcVar13,acStack_e0,0x96);
              uVar14 = local_34;
              if (iVar31 == 0) {
                uVar14 = 0;
              }
              uVar21 = local_30;
              if (local_40 == 0) {
                uVar21 = 0;
              }
              *(uint *)(pcVar13 + 0xa8) = uVar14;
              *(uint *)(pcVar13 + 0xbc) = uVar21;
              *(uint *)(pcVar13 + 0xa4) = uVar14 & local_1b0;
              *(uint *)(pcVar13 + 0xb8) = uVar21 & local_1c4;
              memcpy(pcVar13 + 0xb0,&local_240,6);
              *(int *)(pcVar13 + 0xac) = iVar33;
              *(undefined4 *)(pcVar13 + 0xc0) = local_244;
              *(undefined4 *)(pcVar13 + 0xd0) = local_3c;
              *(undefined4 *)(pcVar13 + 0xc4) = local_248;
              *(undefined4 *)(pcVar13 + 200) = local_24c;
              *(undefined4 *)(pcVar13 + 0xcc) = local_250;
              if ((wportal_info_switch != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
                bVar2 = pcVar13[0xa0];
                pcVar32 = 
                "[WPORTAL_INFO]%s()/%d Add ftt tuple entry: %s type: %d src_ip: %x/%x dst_ip: %x/%x mac: %x:%x:%x:%x:%x:%x vlan: %d src_port: %d-%d dst_port: %d-%d protocol: %d\n\n"
                ;
                puVar22 = *(undefined1 **)(pcVar13 + 0xa4);
                uVar26 = 0x551;
                uVar24 = *(undefined4 *)(pcVar13 + 0xa8);
                puVar15 = *(undefined4 **)(pcVar13 + 0xb8);
                uVar25 = *(undefined4 *)(pcVar13 + 0xbc);
                bVar3 = pcVar13[0xb0];
                bVar4 = pcVar13[0xb1];
                bVar5 = pcVar13[0xb2];
                bVar6 = pcVar13[0xb3];
                bVar7 = pcVar13[0xb4];
                bVar8 = pcVar13[0xb5];
                uVar27 = *(undefined4 *)(pcVar13 + 0xac);
                uVar16 = *(undefined4 *)(pcVar13 + 0xc0);
                uVar17 = *(undefined4 *)(pcVar13 + 0xc4);
                uVar18 = *(undefined4 *)(pcVar13 + 200);
                uVar19 = *(undefined4 *)(pcVar13 + 0xcc);
                uVar20 = *(undefined4 *)(pcVar13 + 0xd0);
LAB_0042ec84:
                printf(pcVar32,"_wportal_ftt_section_parse",uVar26,pcVar13,(uint)bVar2,puVar22,
                       uVar24,puVar15,uVar25,(uint)bVar3,(uint)bVar4,(uint)bVar5,(uint)bVar6,
                       (uint)bVar7,(uint)bVar8,uVar27,uVar16,uVar17,uVar18,uVar19,uVar20);
              }
            }
            else {
              snprintf(pcVar13,0x96,"%s#%d",acStack_e0,local_38 + 1);
              pcVar32 = pcVar13 + 0xb6;
              *(uint *)(pcVar13 + 0xa4) = local_1b0;
              uVar14 = local_34;
              if (iVar31 == 0) {
                uVar14 = 0;
              }
              *(uint *)(pcVar13 + 0xa8) = uVar14;
              sVar12 = strlen(pcVar29);
              memcpy(pcVar32,pcVar29,sVar12 + 1);
              memcpy(pcVar13 + 0xb0,&local_240,6);
              *(int *)(pcVar13 + 0xac) = iVar33;
              *(uint *)(pcVar13 + 0xa4) = *(uint *)(pcVar13 + 0xa4) & *(uint *)(pcVar13 + 0xa8);
              if ((wportal_info_switch != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
                bVar2 = pcVar13[0xa0];
                uVar27 = 0x55d;
                pcVar30 = 
                "[WPORTAL_INFO]%s()/%d Add ftt url entry: %s type: %d src_ip: %x/%x mac: %x:%x:%x:%x:%x:%x vlan: %d  url: %s\n\n"
                ;
                puVar15 = *(undefined4 **)(pcVar13 + 0xa4);
                uVar24 = *(undefined4 *)(pcVar13 + 0xa8);
                bVar3 = pcVar13[0xb0];
                bVar4 = pcVar13[0xb1];
                bVar5 = pcVar13[0xb2];
                bVar6 = pcVar13[0xb3];
                bVar7 = pcVar13[0xb4];
                bVar8 = pcVar13[0xb5];
                uVar25 = *(undefined4 *)(pcVar13 + 0xac);
LAB_0042e910:
                printf(pcVar30,"_wportal_ftt_section_parse",uVar27,pcVar13,(uint)bVar2,puVar15,
                       uVar24,(uint)bVar3,(uint)bVar4,(uint)bVar5,(uint)bVar6,(uint)bVar7,
                       (uint)bVar8,uVar25,pcVar32);
              }
            }
          }
          else {
            pcVar13[0xa0] = (char)local_44;
            *(int *)(pcVar13 + 0x9c) = local_48;
            if (local_44 == 0) {
              pcVar32 = pcVar13 + 0xa4;
              strncpy(pcVar13,acStack_e0,0x96);
              pcVar30 = pcVar13 + 0xc2;
              memcpy(pcVar32,&local_1b0,0x10);
              *(int *)(pcVar13 + 0xb4) = iVar31;
              memcpy(pcVar30,&local_1c4,0x10);
              *(int *)(pcVar13 + 0xd4) = local_40;
              FUN_00408480(pcVar32,iVar31,pcVar32);
              FUN_00408480(pcVar30,local_40,pcVar30);
              memcpy(pcVar13 + 0xbc,&local_240,6);
              *(int *)(pcVar13 + 0xb8) = iVar33;
              *(undefined4 *)(pcVar13 + 0xd8) = local_244;
              *(undefined4 *)(pcVar13 + 0xdc) = local_248;
              *(undefined4 *)(pcVar13 + 0xe0) = local_24c;
              *(undefined4 *)(pcVar13 + 0xe4) = local_250;
              *(undefined4 *)(pcVar13 + 0xe8) = local_3c;
              memset(auStack_160,0,0x40);
              memset(&local_1a0,0,0x40);
              local_1f0 = 0;
              local_1ec = 0;
              local_1e8 = 0;
              local_1e4 = 0;
              local_1e0 = 0;
              local_204 = 0;
              local_200 = 0;
              local_1fc = 0;
              local_1f8 = 0;
              local_1f4 = 0;
              FUN_00408560(pcVar32,2,&local_1f0);
              FUN_00408560(pcVar30,2,&local_204);
              FUN_00408190(local_1f0,local_1ec,local_1e8,local_1e4,local_1e0,auStack_160,0x40,"---")
              ;
              FUN_00408190(local_204,local_200,local_1fc,local_1f8,local_1f4,&local_1a0,0x40,"---");
              if (wportal_info_switch != 0) {
                iVar10 = is_target_debug_ap();
                puVar22 = auStack_160;
                if (iVar10 != 0) {
                  bVar2 = pcVar13[0xa0];
                  puVar15 = &local_1a0;
                  uVar24 = *(undefined4 *)(pcVar13 + 0xb4);
                  pcVar32 = 
                  "[WPORTAL_INFO]%s()/%d Add ftt tuple entry: %s type: %d src_ip: %s/%x dst_ip: %s/%x mac: %x:%x:%x:%x:%x:%x vlan: %d src_port: %d-%d dst_port: %d-%d protocol: %d\n\n"
                  ;
                  uVar26 = 0x59a;
                  uVar25 = *(undefined4 *)(pcVar13 + 0xd4);
                  bVar3 = pcVar13[0xbc];
                  bVar4 = pcVar13[0xbd];
                  bVar5 = pcVar13[0xbe];
                  bVar6 = pcVar13[0xbf];
                  bVar7 = pcVar13[0xc0];
                  bVar8 = pcVar13[0xc1];
                  uVar27 = *(undefined4 *)(pcVar13 + 0xb8);
                  uVar16 = *(undefined4 *)(pcVar13 + 0xd8);
                  uVar17 = *(undefined4 *)(pcVar13 + 0xdc);
                  uVar18 = *(undefined4 *)(pcVar13 + 0xe0);
                  uVar19 = *(undefined4 *)(pcVar13 + 0xe4);
                  uVar20 = *(undefined4 *)(pcVar13 + 0xe8);
                  goto LAB_0042ec84;
                }
              }
            }
            else {
              pcVar30 = pcVar13 + 0xa4;
              pcVar32 = pcVar13 + 0xc2;
              snprintf(pcVar13,0x96,"%s#%d",acStack_e0,local_38);
              memcpy(pcVar30,&local_1b0,0x10);
              *(int *)(pcVar13 + 0xb4) = iVar31;
              sVar12 = strlen(pcVar29);
              memcpy(pcVar32,pcVar29,sVar12 + 1);
              memcpy(pcVar13 + 0xbc,&local_240,6);
              *(int *)(pcVar13 + 0xb8) = iVar33;
              FUN_00408480(pcVar30,iVar31,pcVar30);
              memset(&local_1a0,0,0x40);
              local_218 = 0;
              local_214 = 0;
              local_210 = 0;
              local_20c = 0;
              local_208 = 0;
              FUN_00408560(pcVar30,2,&local_218);
              FUN_00408190(local_218,local_214,local_210,local_20c,local_208,&local_1a0,0x40,"---");
              if (wportal_info_switch != 0) {
                iVar10 = is_target_debug_ap();
                puVar15 = &local_1a0;
                if (iVar10 != 0) {
                  bVar2 = pcVar13[0xa0];
                  uVar24 = *(undefined4 *)(pcVar13 + 0xb4);
                  pcVar30 = 
                  "[WPORTAL_INFO]%s()/%d Add ftt url entry: %s type: %d src_ip: %s/%x mac: %x:%x:%x:%x:%x:%x vlan: %d  url: %s\n\n"
                  ;
                  uVar27 = 0x5aa;
                  bVar3 = pcVar13[0xbc];
                  bVar4 = pcVar13[0xbd];
                  bVar5 = pcVar13[0xbe];
                  bVar6 = pcVar13[0xbf];
                  bVar7 = pcVar13[0xc0];
                  bVar8 = pcVar13[0xc1];
                  uVar25 = *(undefined4 *)(pcVar13 + 0xb8);
                  goto LAB_0042e910;
                }
              }
            }
          }
          iVar10 = wportal_db_ftt_add(pcVar13);
          if (iVar10 != 0) {
            FUN_00407df0(pcVar13);
          }
          pcVar29 = pcVar29 + 0x81;
          local_48 = local_48 + 1;
        }
      }
LAB_0042e604:
      FUN_00407df0(pcVar9);
      return iVar10;
    }
    if (wportal_err_switch == 0) {
      return -1;
    }
    iVar31 = is_target_debug_ap();
    if (iVar31 == 0) {
      return -1;
    }
    pcVar9 = "[WPORTAL_ERR]%s()/%d url malloc error.\n";
    uVar24 = 0x477;
  }
  printf(pcVar9,"_wportal_ftt_section_parse",uVar24);
  return -1;
}

