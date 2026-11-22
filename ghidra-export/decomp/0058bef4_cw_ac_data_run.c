// func cw_ac_data_run @ 0058bef4 size=3496

void cw_ac_data_run(int *param_1)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  void *__s;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 extraout_v1;
  undefined4 *puVar10;
  char *pcVar11;
  code *pcVar12;
  undefined4 uVar13;
  char *pcVar14;
  int *piVar15;
  uint uVar16;
  int iVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined1 *puVar20;
  timeval local_158;
  undefined4 local_150;
  undefined4 local_14c;
  undefined1 auStack_144 [12];
  undefined1 auStack_138 [16];
  undefined1 auStack_128 [20];
  undefined2 local_114;
  undefined4 local_110;
  int local_10c;
  int local_108;
  undefined1 auStack_f8 [64];
  fd_set local_b8;
  undefined8 local_38;
  undefined8 local_30;
  
  if (param_1 == (int *)0x0) {
    pcVar14 = "[ASSERT]%32s():%4d assert(%s) failed\n";
    uVar13 = 0x857;
    param_1 = (int *)&DAT_006de7a4;
LAB_0058c754:
    printf(pcVar14,"cw_ac_data_run",uVar13,param_1);
    return;
  }
  if ((capwap_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[CW_DEBUG]%32s():%4d ac_data[%p] enter run\n","cw_ac_data_run",0x859,param_1);
  }
  *param_1 = 1;
  local_38 = FUN_00524078();
  local_30 = local_38;
  uVar16 = 0;
  uVar18 = local_38;
LAB_0058bf58:
  iVar3 = *param_1;
  local_30 = uVar18;
  do {
    if (iVar3 == 0) {
      if (capwap_debug_switch == 0) {
        return;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return;
      }
      pcVar14 = "[CW_DEBUG]%32s():%4d ac[%p] exit run\n";
      uVar13 = 0x8be;
      goto LAB_0058c754;
    }
    local_158.tv_usec = 0;
    local_158.tv_sec = 1;
    iVar3 = 0;
    do {
      puVar10 = (undefined4 *)((int)local_b8.fds_bits + iVar3);
      iVar3 = iVar3 + 4;
      *puVar10 = 0;
    } while (iVar3 != 0x80);
    uVar4 = param_1[6];
    local_b8.fds_bits[uVar4 >> 5] = local_b8.fds_bits[uVar4 >> 5] | 1 << (uVar4 & 0x1f);
    uVar9 = param_1[0xc];
    local_b8.fds_bits[uVar9 >> 5] = local_b8.fds_bits[uVar9 >> 5] | 1 << (uVar9 & 0x1f);
    if ((int)uVar4 <= (int)uVar9) {
      uVar4 = uVar9;
    }
    iVar3 = select(uVar4 + 1,&local_b8,(fd_set *)0x0,(fd_set *)0x0,&local_158);
    if (iVar3 != 0) {
      if (iVar3 < 1) {
        if (capwap_err_switch != 0) {
          iVar17 = is_target_debug_ap();
          if (iVar17 != 0) {
            piVar15 = __errno_location();
            printf("[CW_ERROR]%32s():%4d select failed, ret=%d, errno=%d\n","cw_ac_data_run",0x899,
                   iVar3,*piVar15);
          }
        }
      }
      else {
        if (((uint)local_b8.fds_bits[(uint)param_1[6] >> 5] >> (param_1[6] & 0x1fU) & 1) == 0) {
LAB_0058c028:
          uVar4 = param_1[0xc];
        }
        else {
          local_150 = 0;
          local_14c = 0;
          if (param_1[4] == -1) {
            uVar13 = 0x785;
            pcVar14 = "-1 != this->network_fd";
          }
          else if (param_1[5] == -1) {
            uVar13 = 0x787;
            pcVar14 = "-1 != this->network6_fd";
          }
          else {
            if (param_1[8] != 0) {
              iVar3 = cw_packet_queue_is_empty();
              if (iVar3 == 0) {
                FUN_0051ad88(auStack_144);
                iVar3 = cw_packet_queue_pop_head_with_size
                                  (param_1[8],*(undefined4 *)(l_profile + 0x24),auStack_144);
                if (iVar3 != -1) {
                  while( true ) {
                    iVar3 = FUN_004081b0(auStack_144);
                    if (iVar3 == 0) break;
                    iVar17 = *(int *)(*(int *)(iVar3 + 0xc) + 0x38);
                    if (iVar17 != 0) {
                      uVar18 = FUN_00524078();
                      *(undefined8 *)(iVar17 + 0x18) = uVar18;
                    }
                    FUN_00408500(iVar3);
                    pcVar14 = *(char **)(iVar3 + 0xc);
                    if (pcVar14 == (char *)0x0) {
                      if (capwap_err_switch != 0) {
                        iVar17 = is_target_debug_ap();
                        if (iVar17 != 0) {
                          pcVar11 = "[CW_ERROR]%32s():%4d pop packet failed.\n";
                          uVar13 = 0x7a4;
                          goto LAB_0058c71c;
                        }
                      }
                    }
                    else {
                      memcpy(param_1 + 0x1f,pcVar14,0x14);
                      *(undefined2 *)(param_1 + 0x24) = *(undefined2 *)(pcVar14 + 0x14);
                      iVar17 = is_cw_discovery_request(**(undefined4 **)(pcVar14 + 0x38));
                      if (iVar17 == 1) {
                        capwap_ac_discovery_handle
                                  (param_1,*(undefined4 *)(pcVar14 + 0x38),pcVar14,pcVar14 + 0x1c);
                      }
                      else {
                        iVar17 = cw_ac_session_get(param_1,pcVar14);
                        if (iVar17 == 0) {
                          if (capwap_dtls_enable_switch == 0) {
                            iVar6 = 0;
                            iVar17 = is_cw_join_request(**(undefined4 **)(pcVar14 + 0x38));
                            if (iVar17 == 0) {
                              if (capwap_debug_switch != 0) {
                                iVar17 = is_target_debug_ap();
                                if (iVar17 != 0) {
                                  pcVar11 = 
                                  "[CW_DEBUG]%32s():%4d not join request packet,don\'t need to allocate session\n"
                                  ;
                                  uVar13 = 0x7c2;
                                  goto LAB_0058c71c;
                                }
                              }
                              goto LAB_0058c2f8;
                            }
LAB_0058c98c:
                            iVar17 = capwap_ac_session_exceed_max_num
                                               (*(undefined4 *)(l_profile + 0x140));
                            if (iVar17 != 0) {
                              if (capwap_debug_switch != 0) {
                                iVar17 = is_target_debug_ap();
                                if (iVar17 != 0) {
                                  pcVar11 = 
                                  "[CW_DEBUG]%32s():%4d exceed max session num,just ignore it\n";
                                  uVar13 = 0x7c8;
                                  goto LAB_0058c71c;
                                }
                              }
                              goto LAB_0058c2f8;
                            }
                            iVar17 = capwap_ac_session_create
                                               (*(undefined4 *)(l_profile + 0x138),
                                                *(undefined4 *)(l_profile + 0x13c));
                            if (iVar17 == 0) {
                              if (capwap_err_switch != 0) {
                                iVar17 = is_target_debug_ap();
                                if (iVar17 != 0) {
                                  printf("[CW_ERROR]%32s():%4d ac_data[%p] failed to alloc session\n"
                                         ,"cw_ac_data_network_process",1999,param_1);
                                }
                              }
                              goto LAB_0058c2f8;
                            }
                            if (capwap_debug_switch == 0) {
                              *(int **)(iVar17 + 0xc) = param_1;
                            }
                            else {
                              iVar7 = is_target_debug_ap();
                              if (iVar7 == 0) {
                                *(int **)(iVar17 + 0xc) = param_1;
                              }
                              else {
                                printf("[CW_DEBUG]%32s():%4d ac_data[%p] create session[%p]\n",
                                       "cw_ac_data_network_process",0x7d2,param_1,iVar17);
                                *(int **)(iVar17 + 0xc) = param_1;
                              }
                            }
                            if (*pcVar14 == '\x01') {
                              iVar7 = param_1[4];
                            }
                            else {
                              iVar7 = param_1[5];
                            }
                            iVar6 = capwap_network_session_init
                                              (iVar17 + 0x2c,iVar7,1,pcVar14,pcVar14 + 0x1c,iVar6,
                                               param_1[10]);
                            if (iVar6 == 0) {
                              cw_fsm_ac_setup(iVar17);
                              iVar6 = cw_frag_session_create(param_1[3],param_1[0x11]);
                              *(int *)(iVar17 + 0xac) = iVar6;
                              if (iVar6 == 0) {
                                if (capwap_err_switch != 0) {
                                  iVar17 = is_target_debug_ap();
                                  if (iVar17 != 0) {
                                    pcVar11 = "[CW_ERROR]%32s():%4d frag mngr init failed\n";
                                    uVar13 = 0x7e1;
                                    goto LAB_0058c71c;
                                  }
                                }
                              }
                              else {
                                iVar6 = cw_pkt_mngr_create();
                                *(int *)(iVar17 + 0xb0) = iVar6;
                                if (iVar6 != 0) {
                                  local_150 = 8;
                                  if (capwap_dtls_enable_switch != 0) {
                                    local_150 = 7;
                                  }
                                  cw_fsm_ac_process_event(iVar17,&local_150);
                                  cw_ac_session_add(param_1,iVar17);
                                  goto LAB_0058c2ac;
                                }
                                if (capwap_err_switch != 0) {
                                  iVar17 = is_target_debug_ap();
                                  if (iVar17 != 0) {
                                    pcVar11 = "[CW_ERROR]%32s():%4d pkt mngr create failed\n";
                                    uVar13 = 0x7e6;
                                    goto LAB_0058c71c;
                                  }
                                }
                              }
                              goto LAB_0058c2f8;
                            }
                            memset(auStack_f8,0,0x40);
                            FUN_00408190(*(undefined4 *)pcVar14,*(undefined4 *)(pcVar14 + 4),
                                         *(undefined4 *)(pcVar14 + 8),*(undefined4 *)(pcVar14 + 0xc)
                                         ,*(undefined4 *)(pcVar14 + 0x10),auStack_f8,0x40,"---");
                            if (capwap_err_switch == 0) goto LAB_0058c2f8;
                            iVar17 = is_target_debug_ap();
                            if (iVar17 == 0) goto LAB_0058c2f8;
                            if (*pcVar14 == '\x01') {
                              iVar17 = param_1[4];
                            }
                            else {
                              iVar17 = param_1[5];
                            }
                            puVar20 = auStack_f8;
                            uVar1 = *(ushort *)(pcVar14 + 0x14);
                            pcVar11 = 
                            "[CW_ERROR]%32s():%4d socket[%d] <%s:%d> failed to init network session.\n"
                            ;
                            uVar13 = 0x7db;
LAB_0058c864:
                            printf(pcVar11,"cw_ac_data_network_process",uVar13,iVar17,puVar20,
                                   (uint)uVar1);
                          }
                          else {
                            iVar6 = capwap_packet_is_clienthello(**(undefined4 **)(pcVar14 + 0x38));
                            if (iVar6 != 0) goto LAB_0058c98c;
                            if (capwap_debug_switch == 0) goto LAB_0058c2f8;
                            iVar17 = is_target_debug_ap();
                            if (iVar17 == 0) goto LAB_0058c2f8;
                            pcVar11 = 
                            "[CW_DEBUG]%32s():%4d not client hello packet,don\'t need to allocate session\n"
                            ;
                            uVar13 = 0x7ba;
LAB_0058c71c:
                            printf(pcVar11,"cw_ac_data_network_process",uVar13);
                          }
                        }
                        else {
                          bVar2 = false;
                          iVar6 = *(int *)(iVar17 + 0x7c);
                          if (*(int *)(iVar17 + 0x44) != *(int *)(pcVar14 + 0x18)) {
                            *(int *)(iVar17 + 0x44) = *(int *)(pcVar14 + 0x18);
                            bVar2 = true;
                            if (iVar6 != 0) {
                              *(undefined4 *)(iVar6 + 0x20) = *(undefined4 *)(pcVar14 + 0x18);
                            }
                          }
                          if (*(int *)(iVar17 + 0x60) == *(int *)(pcVar14 + 0x34)) {
                            if (bVar2) {
                              iVar6 = *(int *)(iVar17 + 0x10);
                              goto LAB_0058c2a0;
                            }
                          }
                          else {
                            *(int *)(iVar17 + 0x60) = *(int *)(pcVar14 + 0x34);
                            if (iVar6 != 0) {
                              *(undefined4 *)(iVar6 + 0x3c) = *(undefined4 *)(pcVar14 + 0x34);
                            }
                            iVar6 = *(int *)(iVar17 + 0x10);
LAB_0058c2a0:
                            if (iVar6 != 0) {
                              memset(auStack_138,0,0x34);
                              memcpy(auStack_128,(void *)(iVar17 + 0x2c),0x14);
                              local_114 = *(undefined2 *)(iVar17 + 0x40);
                              memcpy(auStack_138,(void *)(iVar17 + 0x14),6);
                              local_10c = param_1[4];
                              local_108 = param_1[5];
                              local_110 = *(undefined4 *)(pcVar14 + 0x34);
                              serv_ent_handle(3,auStack_138,0,0);
                            }
                          }
LAB_0058c2ac:
                          __s = (void *)FUN_00408450(0x10,0x815);
                          if (__s == (void *)0x0) {
                            if (capwap_err_switch != 0) {
                              iVar17 = is_target_debug_ap();
                              if (iVar17 != 0) {
                                uVar13 = 0x818;
                                pcVar11 = "[CW_ERROR]%32s():%4d memory out\n";
                                goto LAB_0058c71c;
                              }
                            }
                          }
                          else {
                            memset(__s,0,0x10);
                            *(undefined4 *)((int)__s + 0xc) = *(undefined4 *)(pcVar14 + 0x38);
                            pcVar14[0x38] = '\0';
                            pcVar14[0x39] = '\0';
                            pcVar14[0x3a] = '\0';
                            pcVar14[0x3b] = '\0';
                            FUN_004086b0(iVar17 + 0x84,__s);
                            iVar17 = capwap_ac_session_handle(param_1,iVar17);
                            if (iVar17 != 0) {
                              memset(auStack_138,0,0x40);
                              FUN_00408190(*(undefined4 *)pcVar14,*(undefined4 *)(pcVar14 + 4),
                                           *(undefined4 *)(pcVar14 + 8),
                                           *(undefined4 *)(pcVar14 + 0xc),
                                           *(undefined4 *)(pcVar14 + 0x10),auStack_138,0x40,"---");
                              if (capwap_warning_switch != 0) {
                                iVar17 = is_target_debug_ap();
                                if (iVar17 != 0) {
                                  if (*pcVar14 == '\x01') {
                                    iVar17 = param_1[4];
                                  }
                                  else {
                                    iVar17 = param_1[5];
                                  }
                                  puVar20 = auStack_138;
                                  uVar13 = 0x826;
                                  uVar1 = *(ushort *)(pcVar14 + 0x14);
                                  pcVar11 = 
                                  "[CW_WARNING]%32s():%4d socket[%d] <%s:%d> handle recv pkt failed.\n"
                                  ;
                                  goto LAB_0058c864;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
LAB_0058c2f8:
                    FUN_00407df0(iVar3);
                    if (pcVar14 != (char *)0x0) {
                      if (*(int *)(pcVar14 + 0x38) != 0) {
                        cw_pkt_buf_destroy();
                      }
                      FUN_00407df0(pcVar14);
                    }
                  }
                  goto LAB_0058c028;
                }
                uVar4 = param_1[0xc];
              }
              else {
                uVar4 = param_1[0xc];
              }
              goto LAB_0058c02c;
            }
            uVar13 = 0x789;
            pcVar14 = "NULL != this->capwap_queue";
          }
          printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_data_network_process",uVar13,
                 pcVar14);
          uVar4 = param_1[0xc];
        }
LAB_0058c02c:
        if (((uint)local_b8.fds_bits[uVar4 >> 5] >> (uVar4 & 0x1f) & 1) != 0) {
          if (param_1[0xe] == 0) {
            printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_data_manager_process",0x6b3,
                   "this->manager_queue");
          }
          else {
            iVar3 = cw_packet_queue_is_empty();
            if (iVar3 == 0) {
              FUN_0051ad88(&local_150);
              iVar3 = cw_packet_queue_pop_head_with_size
                                (param_1[0xe],*(undefined4 *)(l_profile + 0x20),&local_150);
              if (iVar3 != -1) {
                while( true ) {
                  iVar3 = FUN_004081b0(&local_150);
                  if (iVar3 == 0) break;
                  FUN_00408500(iVar3);
                  iVar17 = *(int *)(iVar3 + 0xc);
                  if (iVar17 == 0) {
                    if (capwap_err_switch != 0) {
                      iVar6 = is_target_debug_ap();
                      if (iVar6 != 0) {
                        printf("[CW_ERROR]%32s():%4d pop manager data failed or manager data is empty.\n"
                               ,"cw_ac_data_manager_process",0x6c4);
                      }
                    }
                  }
                  else {
                    iVar6 = *(int *)(iVar17 + 0x10);
                    if (iVar6 == 0) {
                      piVar15 = *(int **)(iVar17 + 0x14);
                      if (piVar15 != (int *)0x0) {
                        piVar15[2] = 0;
                        if (*(int *)(iVar17 + 0xc) == 0) {
                          while( true ) {
                            iVar6 = FUN_004081b0(iVar17);
                            if (iVar6 == 0) break;
                            FUN_00408500(iVar6);
                            iVar7 = cw_ac_session_get(param_1,iVar6 + 0xc);
                            if (iVar7 != 0) {
                              piVar15[2] = piVar15[2] + 1;
                              cw_ac_data_manager_packet_event_process(iVar7,piVar15);
                            }
                            FUN_00407df0(iVar6);
                          }
                          if (piVar15[2] != 0) goto LAB_0058c41c;
                        }
                        else {
                          iVar6 = FUN_00407fe0(param_1 + 0x13);
                          if (iVar6 != 0) {
                            iVar6 = FUN_00407fe0(param_1 + 0x13);
                            piVar15[2] = iVar6;
                            iVar6 = param_1[0x16];
                            pcVar12 = cw_ac_data_manager_packet_event_process;
                            goto LAB_0058c63c;
                          }
                        }
                        piVar15[2] = 1;
                        cw_send_pkt_destroy(piVar15);
                        *(undefined4 *)(iVar17 + 0x14) = 0;
                      }
                    }
                    else if (iVar6 == 3) {
                      piVar15 = *(int **)(iVar17 + 0x14);
                      if (piVar15 != (int *)0x0) {
                        *piVar15 = 0;
                        if (*(int *)(iVar17 + 0xc) == 0) {
                          while( true ) {
                            iVar6 = FUN_004081b0(iVar17);
                            if (iVar6 == 0) break;
                            FUN_00408500(iVar6);
                            iVar7 = cw_ac_session_get(param_1,iVar6 + 0xc);
                            if (iVar7 != 0) {
                              *piVar15 = *piVar15 + 1;
                              cw_ac_data_manager_user_packet_event_process(iVar7,piVar15);
                            }
                            FUN_00407df0(iVar6);
                          }
                          if (*piVar15 == 0) goto LAB_0058c5fc;
                        }
                        else {
                          iVar6 = FUN_00407fe0(param_1 + 0x13);
                          if (iVar6 == 0) {
LAB_0058c5fc:
                            *piVar15 = 1;
                            cw_user_defined_send_pkt_destroy(piVar15);
                            *(undefined4 *)(iVar17 + 0x14) = 0;
                          }
                          else {
                            iVar6 = FUN_00407fe0(param_1 + 0x13);
                            pcVar12 = cw_ac_data_manager_user_packet_event_process;
                            *piVar15 = iVar6;
                            iVar6 = param_1[0x16];
LAB_0058c63c:
                            FUN_00408570(iVar6,pcVar12,piVar15);
                          }
                        }
                      }
                    }
                    else if (iVar6 == 1) {
                      iVar6 = *(int *)(iVar17 + 0x14);
                      if (iVar6 != 0) {
                        if (*(int *)(iVar17 + 0xc) == 0) {
                          while( true ) {
                            iVar7 = FUN_004081b0(iVar17);
                            if (iVar7 == 0) break;
                            FUN_00408500(iVar7);
                            iVar8 = cw_ac_session_get(param_1,iVar7 + 0xc);
                            if (iVar8 != 0) {
                              cw_ac_data_manager_timer_event_process(iVar8,iVar6);
                            }
                            FUN_00407df0(iVar7);
                          }
                        }
                        else {
                          FUN_00408570(param_1[0x16],cw_ac_data_manager_timer_event_process,iVar6);
                        }
                        FUN_00407df0(iVar6);
                        *(undefined4 *)(iVar17 + 0x14) = 0;
                      }
                    }
                    else if (iVar6 == 2) {
                      if (*(int *)(iVar17 + 0xc) != 0) {
                        iVar6 = param_1[0x16];
                        piVar15 = (int *)0x0;
                        pcVar12 = cw_ac_data_manager_session_delete_process;
                        goto LAB_0058c63c;
                      }
                      while( true ) {
                        iVar6 = FUN_004081b0(iVar17);
                        if (iVar6 == 0) break;
                        FUN_00408500(iVar6);
                        iVar7 = cw_ac_session_get(param_1,iVar6 + 0xc);
                        if (iVar7 != 0) {
                          cw_ac_data_manager_session_delete_process(iVar7,0);
                        }
                        FUN_00407df0(iVar6);
                      }
                    }
                  }
LAB_0058c41c:
                  FUN_00407df0(iVar3);
                  if (iVar17 != 0) {
                    FUN_00407df0(iVar17);
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar18 = FUN_00524078();
    iVar3 = (int)((ulonglong)uVar18 >> 0x20);
    uVar9 = (uint)uVar18;
    uVar4 = uVar9 - local_38._4_4_;
    if ((iVar3 - local_38._0_4_ != (uint)(uVar9 < uVar4)) || (999999 < uVar4)) {
      cw_timer_process(param_1[0x11]);
      local_38 = uVar18;
    }
    move_all_pkt_snapshot(param_1 + 0x25,param_1[1]);
    uVar4 = uVar9 - local_30._4_4_;
    iVar3 = (iVar3 - local_30._0_4_) - (uint)(uVar9 < uVar4);
    if ((iVar3 != 0) || (1999999 < uVar4)) break;
    iVar3 = *param_1;
  } while( true );
  uVar5 = cw_packet_queue_proc_num_get(param_1[8]);
  uVar9 = -uVar16;
  if (uVar5 < uVar16) {
    uVar9 = ~uVar16;
  }
  if (capwap_packet_rate_switch != 0) {
    iVar17 = (uVar5 + uVar9) * 1000;
    uVar19 = __udivdi3(iVar3,uVar4,0,1000);
    iVar3 = param_1[1];
    __udivdi3(0,iVar17,(int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
    printf("Thread[%d]\'s packet process rate:\t%d/s(%d/%d)\n",iVar3,extraout_v1,iVar17,(int)uVar19)
    ;
  }
  local_30 = uVar18;
  uVar16 = uVar5;
  goto LAB_0058bf58;
}

