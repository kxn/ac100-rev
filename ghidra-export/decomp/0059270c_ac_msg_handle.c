// func ac_msg_handle @ 0059270c size=6748

undefined4 ac_msg_handle(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar9;
  int iVar5;
  undefined1 *puVar6;
  void *__src;
  char *pcVar7;
  ushort *puVar8;
  int extraout_v1;
  void *extraout_v1_00;
  int extraout_v1_01;
  int extraout_v1_02;
  int extraout_v1_03;
  int extraout_v1_04;
  int extraout_v1_05;
  int extraout_v1_06;
  char *pcVar10;
  char cVar11;
  undefined4 uVar12;
  void *pvVar13;
  uint uVar14;
  int iVar15;
  undefined8 uVar16;
  int local_220;
  undefined4 local_21c;
  void *local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined1 auStack_208 [16];
  undefined1 auStack_1f8 [20];
  undefined2 local_1e4;
  undefined1 auStack_1d4 [16];
  undefined1 auStack_1c4 [20];
  undefined2 local_1b0;
  undefined1 auStack_1a0 [6];
  undefined1 auStack_19a [6];
  undefined1 local_194;
  undefined1 auStack_190 [20];
  undefined2 local_17c;
  undefined1 auStack_16c [16];
  undefined1 auStack_15c [20];
  undefined2 local_148;
  undefined1 auStack_138 [16];
  undefined1 auStack_128 [20];
  undefined2 local_114;
  undefined1 auStack_104 [16];
  undefined1 auStack_f4 [20];
  undefined1 auStack_e0 [4];
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined1 auStack_d0 [6];
  undefined1 auStack_ca [6];
  undefined1 local_c4;
  undefined1 auStack_c0 [12];
  undefined1 auStack_b4 [8];
  undefined2 local_ac;
  undefined1 auStack_98 [28];
  undefined1 auStack_7c [36];
  undefined1 *local_58;
  void *local_54;
  void *local_50;
  int local_4c;
  void *local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  void *local_30;
  
  local_21c = 0;
  local_218 = (void *)0x0;
  memset(auStack_138,0,0x34);
  local_214 = 0;
  local_210 = 0;
  local_20c = 0;
  local_220 = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    pcVar10 = "[CW_ERROR]%32s():%4d input parameter is null\n";
    uVar12 = 0x2fe;
    goto LAB_00592c80;
  }
  if ((((capwap_packet_switch != 0) || (capwap_recv_packet_switch != 0)) &&
      ((debug_ip == 0 ||
       ((*(char *)(param_2 + 0x2c) == '\x01' && (debug_ip == *(int *)(param_2 + 0x30))))))) &&
     ((debug_port == 0 || (*(short *)(param_2 + 0x40) == debug_port)))) {
    iVar5 = ac_packet_debug_is_open(*(undefined4 *)(param_3 + 0x10));
    if (iVar5 != 0) {
      memset(auStack_98,0,0x40);
      FUN_00408190(*(undefined4 *)(param_2 + 0x2c),*(undefined4 *)(param_2 + 0x30),
                   *(undefined4 *)(param_2 + 0x34),*(undefined4 *)(param_2 + 0x38),
                   *(undefined4 *)(param_2 + 0x3c),auStack_98,0x40,"---");
      printf("receive packet from AP[%s/%d]:\n",auStack_98,(uint)*(ushort *)(param_2 + 0x40));
      capwap_parsed_packet_dump(param_3);
    }
  }
  iVar5 = ac_packet_is_request(param_3);
  if (iVar5 == 0) {
    iVar2 = 0;
    iVar5 = is_store_snapshot();
    if (iVar5 == 0) {
      cVar11 = *(char *)(param_3 + 0x14);
    }
    else {
      iVar2 = create_new_pkt_snapshot(2,param_1);
      get_pkt_info(iVar2,param_3);
      cVar11 = *(char *)(param_3 + 0x14);
    }
    if ((cVar11 == *(char *)(param_2 + 0xa8)) &&
       (local_4c = param_2 + 0xf8, iVar5 = FUN_00407fe0(param_2 + 0xf8), iVar5 != 0)) {
      memset(auStack_104,0,0x34);
      cw_ac_session_get_ip(param_2,auStack_f4);
      cw_ac_session_get_port(param_2,auStack_e0);
      local_dc = *(undefined4 *)(param_2 + 0x44);
      local_d8 = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x10);
      local_d4 = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x14);
      if (*(int *)(param_2 + 0x10) != 0) {
        memcpy(auStack_104,(void *)(param_2 + 0x14),6);
      }
      FUN_00524078();
      iVar5 = serv_mngr_handle(param_3,auStack_104,0);
      if (iVar5 == -1) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        pcVar10 = "[CW_ERROR]%32s():%4d service manager handled the packet failed\n";
        uVar12 = 0x3f1;
      }
      else {
        iVar5 = is_store_snapshot();
        if ((iVar5 != 0) && (iVar2 != 0)) {
          FUN_00524078();
          iVar5 = *(int *)(param_3 + 0x2c);
          if (*(undefined1 **)(iVar2 + 0x54) != (undefined1 *)0x0) {
            **(undefined1 **)(iVar2 + 0x54) = 0;
            *(undefined1 *)(*(int *)(iVar2 + 0x54) + 1) = 0;
            *(undefined1 *)(*(int *)(iVar2 + 0x54) + 2) = 0;
            *(undefined4 *)(*(int *)(iVar2 + 0x54) + 4) = *(undefined4 *)(param_3 + 0x30);
            *(int *)(*(int *)(iVar2 + 0x54) + 8) = extraout_v1_05 - extraout_v1_02;
            *(int *)(*(int *)(iVar2 + 0x54) + 0xc) = extraout_v1_05 - iVar5;
          }
          uVar12 = *(undefined4 *)(param_3 + 0x28);
          *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_3 + 0x2c);
          *(undefined4 *)(iVar2 + 0x10) = uVar12;
          memcpy((void *)(iVar2 + 0x2c),(void *)(param_2 + 0x14),6);
        }
        iVar5 = cw_ac_retransmit_timer_stop(param_2);
        if (iVar5 == -1) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            return 0xffffffff;
          }
          pcVar10 = "[CW_ERROR]%32s():%4d retransmit timer stop failed\n";
          uVar12 = 0x401;
        }
        else {
          iVar5 = FUN_004081b0(local_4c);
          if ((iVar5 != 0) &&
             (iVar2 = ac_send_packet_response_need(*(undefined4 *)(iVar5 + 0x10)), iVar2 != 0)) {
            FUN_00408500(iVar5);
            cw_send_pkt_destroy(*(undefined4 *)(iVar5 + 0x10));
            *(undefined4 *)(iVar5 + 0x10) = 0;
            FUN_00407df0(iVar5);
            pvVar13 = (void *)FUN_00407fe0(local_4c);
joined_r0x00593538:
            if (pvVar13 != (void *)0x0) {
              do {
                while( true ) {
                  iVar5 = FUN_004081b0(local_4c);
                  if (iVar5 == 0) goto LAB_0059335c;
                  if (*(char *)(iVar5 + 0xc) != '\0') break;
                  bVar1 = false;
                  pvVar13 = (void *)cw_control_header_msg_type_get
                                              (*(undefined4 *)(*(int *)(iVar5 + 0x10) + 0x10));
                  if ((*(char *)(*(int *)(iVar5 + 0x10) + 0x38) != '\0') &&
                     ((pvVar13 == (void *)0x11 || (pvVar13 == (void *)0xf)))) {
                    bVar1 = pvVar13 == (void *)0x11;
                    pvVar13 = (void *)0x7;
                  }
                  local_21c = 0xb;
                  local_218 = pvVar13;
                  iVar2 = ac_send_packet_response_need();
                  if (iVar2 == 0) {
                    iVar2 = cw_fsm_ac_process_event(param_2,&local_21c);
                    if (iVar2 == 0) {
                      cVar11 = '\x01';
                      if (*(char *)(param_2 + 0xa4) != -1) {
                        cVar11 = *(char *)(param_2 + 0xa4) + '\x01';
                      }
                      *(char *)(param_2 + 0xa4) = cVar11;
                      cw_control_header_seq_num_set(*(undefined4 *)(*(int *)(iVar5 + 0x10) + 0x10));
                      iVar2 = ac_packet_buf_send(param_2,*(int *)(iVar5 + 0x10) + 0x10);
                      if (iVar2 == 0) {
                        iVar2 = is_store_snapshot();
                        if (iVar2 != 0) {
                          FUN_00524078();
                          local_50 = *(void **)(*(int *)(iVar5 + 0x10) + 0x44);
                          iVar2 = create_new_pkt_snapshot(3,param_1);
                          get_pkt_info_by_buf(iVar2,*(int *)(iVar5 + 0x10) + 0x10,param_2 + 0xdc);
                          if (iVar2 != 0) {
                            if (*(undefined4 **)(iVar2 + 0x58) != (undefined4 *)0x0) {
                              **(undefined4 **)(iVar2 + 0x58) = 0;
                              *(undefined1 *)(*(int *)(iVar2 + 0x58) + 4) = 0;
                              *(int *)(*(int *)(iVar2 + 0x58) + 8) = extraout_v1_06 - (int)local_50;
                            }
                            uVar16 = FUN_00524078();
                            *(undefined8 *)(iVar2 + 0x10) = uVar16;
                            memcpy((void *)(iVar2 + 0x2c),(void *)(param_2 + 0x14),6);
                          }
                        }
                        if (bVar1) {
                          memset(auStack_98,0,0x38);
                          local_58 = auStack_d0;
                          memset(local_58,0,0x34);
                          iVar3 = *(int *)(iVar5 + 0x10);
                          FUN_0051ad88(auStack_7c);
                          *(undefined2 *)(iVar3 + 0x16) = 0;
                          iVar2 = capwap_packet_parse(iVar3 + 0x10,auStack_98,0,0,param_2 + 0xdc);
                          if (iVar2 == 0) {
                            uVar14 = 0;
                            puVar8 = (ushort *)cw_msg_ele_priv_val_get_from_pkt(auStack_98,0x75);
                            if (puVar8 != (ushort *)0x0) {
                              local_50 = (void *)(param_2 + 0x2c);
                              local_48 = (void *)(param_2 + 0x14);
                              for (; uVar14 < *puVar8; uVar14 = uVar14 + 1) {
                                memcpy(auStack_c0,local_50,0x14);
                                local_ac = *(undefined2 *)(param_2 + 0x40);
                                local_c4 = 1;
                                memcpy(auStack_ca,local_48,6);
                                memcpy(auStack_d0,(void *)(*(int *)(puVar8 + 2) + uVar14 * 6),6);
                                serv_ent_handle(2,auStack_d0,0,0);
                              }
                            }
                          }
                          *(undefined2 *)(iVar3 + 0x16) = 0;
                          capwap_parsed_packet_free(auStack_98);
                        }
                        if (pvVar13 == (void *)0x11) goto LAB_00593a10;
                        local_21c = 0xc;
                        local_218 = pvVar13;
                        cw_fsm_ac_process_event(param_2,&local_21c);
                      }
                    }
                    else if (pvVar13 == (void *)0x11) {
                      memset(auStack_16c,0,0x34);
                      memcpy(auStack_15c,(void *)(param_2 + 0x2c),0x14);
                      local_148 = *(undefined2 *)(param_2 + 0x40);
                      memcpy(auStack_16c,(void *)(param_2 + 0x14),6);
                      puVar6 = auStack_16c;
LAB_00593a04:
                      serv_ent_handle(2,puVar6,0,0);
LAB_00593a10:
                      cw_fsm_ac_teardown(param_2);
                      return 0;
                    }
                  }
                  else {
                    iVar2 = cw_fsm_ac_process_event(param_2,&local_21c);
                    if (iVar2 == 0) {
                      cVar11 = '\x01';
                      if (*(char *)(param_2 + 0xa4) != -1) {
                        cVar11 = *(char *)(param_2 + 0xa4) + '\x01';
                      }
                      *(char *)(param_2 + 0xa4) = cVar11;
                      cw_control_header_seq_num_set(*(undefined4 *)(*(int *)(iVar5 + 0x10) + 0x10));
                      iVar2 = ac_packet_buf_send(param_2,*(int *)(iVar5 + 0x10) + 0x10);
                      if (iVar2 == 0) {
                        uVar16 = FUN_00524078();
                        iVar2 = is_store_snapshot();
                        iVar3 = *(int *)(iVar5 + 0x10);
                        if (iVar2 != 0) {
                          iVar3 = *(int *)(iVar3 + 0x44);
                          iVar2 = create_new_pkt_snapshot(3,param_1);
                          get_pkt_info_by_buf(iVar2,*(int *)(iVar5 + 0x10) + 0x10,param_2 + 0xdc);
                          if (iVar2 == 0) {
                            iVar3 = *(int *)(iVar5 + 0x10);
                          }
                          else {
                            if (*(undefined4 **)(iVar2 + 0x58) != (undefined4 *)0x0) {
                              **(undefined4 **)(iVar2 + 0x58) = 0;
                              *(undefined1 *)(*(int *)(iVar2 + 0x58) + 4) = 0;
                              *(int *)(*(int *)(iVar2 + 0x58) + 8) = (int)uVar16 - iVar3;
                            }
                            *(undefined8 *)(iVar2 + 0x10) = uVar16;
                            memcpy((void *)(iVar2 + 0x2c),(void *)(param_2 + 0x14),6);
                            iVar3 = *(int *)(iVar5 + 0x10);
                          }
                        }
                        *(undefined8 *)(iVar3 + 0x40) = uVar16;
                        if (bVar1) {
                          memset(auStack_d0,0,0x38);
                          memset(auStack_1a0,0,0x34);
                          iVar3 = *(int *)(iVar5 + 0x10);
                          *(undefined2 *)(iVar3 + 0x16) = 0;
                          FUN_0051ad88(auStack_b4);
                          iVar2 = capwap_packet_parse(iVar3 + 0x10,auStack_d0,0,0,param_2 + 0xdc);
                          if (iVar2 == 0) {
                            uVar14 = 0;
                            puVar8 = (ushort *)cw_msg_ele_priv_val_get_from_pkt(auStack_d0,0x75);
                            if (puVar8 != (ushort *)0x0) {
                              local_54 = (void *)(param_2 + 0x14);
                              uVar9 = *puVar8;
                              for (; uVar14 < uVar9; uVar14 = uVar14 + 1) {
                                memcpy(auStack_190,(void *)(param_2 + 0x2c),0x14);
                                local_17c = *(undefined2 *)(param_2 + 0x40);
                                local_194 = 1;
                                memcpy(auStack_19a,local_54,6);
                                memcpy(auStack_1a0,(void *)(*(int *)(puVar8 + 2) + uVar14 * 6),6);
                                serv_ent_handle(2,auStack_1a0,0,0);
                                uVar9 = *puVar8;
                              }
                            }
                          }
                          *(undefined2 *)(iVar3 + 0x16) = 0;
                          capwap_parsed_packet_free(auStack_d0);
                          uVar12 = *(undefined4 *)(iVar5 + 0x10);
                        }
                        else {
                          uVar12 = *(undefined4 *)(iVar5 + 0x10);
                        }
                        cw_ac_pkt_retransmit_para_fixed(uVar12,param_2);
                        cw_ac_retransmit_timer_start
                                  (param_2,*(undefined4 *)(*(int *)(iVar5 + 0x10) + 4));
                        *(undefined1 *)(param_2 + 0xa8) = *(undefined1 *)(param_2 + 0xa4);
                        local_21c = 0xc;
                        local_218 = pvVar13;
                        cw_fsm_ac_process_event(param_2,&local_21c);
                      }
                      goto LAB_0059335c;
                    }
                    if (pvVar13 == (void *)0x11) {
                      memset(auStack_1d4,0,0x34);
                      memcpy(auStack_1c4,(void *)(param_2 + 0x2c),0x14);
                      local_1b0 = *(undefined2 *)(param_2 + 0x40);
                      memcpy(auStack_1d4,(void *)(param_2 + 0x14),6);
                      puVar6 = auStack_1d4;
                      goto LAB_00593a04;
                    }
                  }
                  FUN_00408500(iVar5);
                  cw_send_pkt_destroy(*(undefined4 *)(iVar5 + 0x10));
                  *(undefined4 *)(iVar5 + 0x10) = 0;
LAB_00593620:
                  FUN_00407df0(iVar5);
                }
                memcpy(auStack_128,(void *)(param_2 + 0x2c),0x14);
                local_114 = *(undefined2 *)(param_2 + 0x40);
                memcpy(auStack_138,(void *)(param_2 + 0x14),6);
                FUN_0051ad88(&local_214);
                iVar2 = (**(code **)(*(int *)(iVar5 + 0x14) + 4))(auStack_138,&local_214);
                if (iVar2 == 0) {
LAB_0059398c:
                  if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    uVar12 = 0x4c5;
                    pcVar10 = "[CW_DEBUG]%32s():%4d session[%p]\'s cb is called failed\n";
LAB_00593b70:
                    printf(pcVar10,"ac_msg_handle",uVar12,param_2);
                  }
LAB_00593994:
                  FUN_00408500(iVar5);
                  cw_user_defined_send_pkt_destroy(*(undefined4 *)(iVar5 + 0x14));
                  *(undefined4 *)(iVar5 + 0x14) = 0;
                  goto LAB_00593620;
                }
                if (iVar2 == 1) {
                  iVar2 = FUN_00407fe0(&local_214);
                  if (iVar2 == 0) goto LAB_0059398c;
                  goto LAB_00593694;
                }
                if (iVar2 != 3) goto LAB_00593694;
                iVar2 = cw_ac_manager_data_create(0,3,*(undefined4 *)(iVar5 + 0x14));
                if (iVar2 == 0) {
                  if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    pcVar10 = 
                    "[CW_DEBUG]%32s():%4d session[%p]\'s cw_ac_manager_data_create is called failed\n"
                    ;
                    uVar12 = 0x4d2;
                    goto LAB_00593b70;
                  }
                  goto LAB_00593994;
                }
                iVar3 = cw_ac_manager_data_add
                                  (iVar2,*(undefined4 *)(param_2 + 0x2c),
                                   *(undefined4 *)(param_2 + 0x30),*(undefined4 *)(param_2 + 0x34),
                                   *(undefined4 *)(param_2 + 0x38),*(undefined4 *)(param_2 + 0x3c),
                                   *(undefined2 *)(param_2 + 0x40));
                if (iVar3 == 0) {
                  uVar12 = ip_to_ac_data(*(undefined4 *)(param_2 + 0x2c),
                                         *(undefined4 *)(param_2 + 0x30),
                                         *(undefined4 *)(param_2 + 0x34),
                                         *(undefined4 *)(param_2 + 0x38),
                                         *(undefined4 *)(param_2 + 0x3c),
                                         *(undefined2 *)(param_2 + 0x40));
                  iVar3 = cw_ac_manager_event_add(uVar12,iVar2);
                  if (iVar3 == 0) {
                    FUN_00408500(iVar5);
                    *(undefined4 *)(iVar5 + 0x14) = 0;
                    goto LAB_00593620;
                  }
                  if ((capwap_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                    pcVar10 = 
                    "[CW_DEBUG]%32s():%4d session[%p]\'s cw_ac_manager_event_add is called failed\n"
                    ;
                    uVar12 = 0x4e7;
                    goto LAB_005940bc;
                  }
                }
                else if (capwap_debug_switch != 0) {
                  iVar3 = is_target_debug_ap();
                  uVar12 = 0x4dc;
                  if (iVar3 != 0) {
                    pcVar10 = 
                    "[CW_DEBUG]%32s():%4d session[%p]\'s cw_ac_manager_data_add is called failed\n";
LAB_005940bc:
                    printf(pcVar10,"ac_msg_handle",uVar12,param_2);
                  }
                }
                FUN_00408500(iVar5);
                cw_user_defined_send_pkt_destroy(*(undefined4 *)(iVar5 + 0x14));
                *(undefined4 *)(iVar5 + 0x14) = 0;
                FUN_00407df0(iVar5);
                cw_ac_manager_data_destroy(iVar2);
              } while( true );
            }
          }
LAB_0059335c:
          local_21c = 3;
          local_218 = *(void **)(param_3 + 0x10);
          iVar5 = cw_fsm_ac_process_event(param_2,&local_21c);
          if (iVar5 != -1) {
            return 0;
          }
          if (capwap_warning_switch == 0) {
            return 0xffffffff;
          }
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            return 0xffffffff;
          }
          pcVar10 = "[CW_WARNING]%32s():%4d failed to process fsm event\n";
          uVar12 = 0x5a7;
        }
      }
    }
    else {
      local_21c = 3;
      local_218 = *(void **)(param_3 + 0x10);
      iVar5 = cw_fsm_ac_process_event(param_2,&local_21c);
      if (iVar5 != -1) {
        iVar5 = is_store_snapshot();
        if ((iVar5 != 0) && (iVar2 != 0)) {
          FUN_00524078();
          iVar5 = *(int *)(param_3 + 0x2c);
          if (*(undefined1 **)(iVar2 + 0x54) != (undefined1 *)0x0) {
            **(undefined1 **)(iVar2 + 0x54) = 0;
            *(undefined1 *)(*(int *)(iVar2 + 0x54) + 1) = 0;
            *(undefined1 *)(*(int *)(iVar2 + 0x54) + 2) = 0;
            *(undefined4 *)(*(int *)(iVar2 + 0x54) + 4) = *(undefined4 *)(param_3 + 0x30);
            *(undefined4 *)(*(int *)(iVar2 + 0x54) + 8) = 0;
            *(int *)(*(int *)(iVar2 + 0x54) + 0xc) = extraout_v1_01 - iVar5;
          }
          uVar12 = *(undefined4 *)(param_3 + 0x28);
          *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_3 + 0x2c);
          *(undefined4 *)(iVar2 + 0x10) = uVar12;
          memcpy((void *)(iVar2 + 0x2c),(void *)(param_2 + 0x14),6);
        }
        memset(auStack_98,0,0x40);
        FUN_00408190(*(undefined4 *)(param_2 + 0x2c),*(undefined4 *)(param_2 + 0x30),
                     *(undefined4 *)(param_2 + 0x34),*(undefined4 *)(param_2 + 0x38),
                     *(undefined4 *)(param_2 + 0x3c),auStack_98,0x40,"---");
        if (capwap_debug_switch != 0) {
          iVar5 = is_target_debug_ap();
          if (iVar5 != 0) {
            printf("[CW_DEBUG]%32s():%4d [%s:%d]receive response packet[%d/%d]\n","ac_msg_handle",
                   0x5be,auStack_98,(uint)*(ushort *)(param_2 + 0x40),
                   *(undefined4 *)(param_3 + 0x10),(uint)*(byte *)(param_3 + 0x14));
            return 0;
          }
          return 0;
        }
        return 0;
      }
      if (capwap_warning_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      pcVar10 = "[CW_WARNING]%32s():%4d failed to process fsm event\n";
      uVar12 = 0x5b1;
    }
    goto LAB_00592c80;
  }
  iVar5 = is_store_snapshot();
  if (iVar5 == 0) {
    pvVar13 = (void *)0x0;
    iVar5 = 0;
  }
  else {
    pvVar13 = (void *)(param_2 + 0x14);
    if (*(int *)(param_2 + 0x10) == 0) {
      pvVar13 = (void *)get_mac(param_3);
    }
    iVar5 = create_new_pkt_snapshot(1,param_1);
    get_pkt_info(iVar5,param_3);
  }
  iVar2 = ac_packet_is_right(param_3,&local_220);
  if (iVar2 == 0) {
    local_21c = 2;
    local_218 = *(void **)(param_3 + 0x10);
    iVar5 = cw_fsm_ac_process_event(param_2,&local_21c);
    if (iVar5 != -1) {
      return 0;
    }
    if (capwap_warning_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    pcVar10 = "[CW_WARNING]%32s():%4d failed to process fsm event\n";
    uVar12 = 0x322;
    goto LAB_00592c80;
  }
  if (*(ushort *)(param_2 + 0xa6) == 0xffff) {
    iVar2 = *(int *)(param_3 + 0x10);
  }
  else {
    if (((ushort)*(byte *)(param_3 + 0x14) == *(ushort *)(param_2 + 0xa6)) &&
       (*(int *)(param_2 + 0xd4) != 0)) {
      if (capwap_debug_switch == 0) {
        uVar12 = *(undefined4 *)(param_2 + 0xd4);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          uVar12 = *(undefined4 *)(param_2 + 0xd4);
        }
        else {
          printf("[CW_DEBUG]%32s():%4d receive request packet with same sequence number(%d) of last request packet, send last send response\n"
                 ,"ac_msg_handle",0x329,(int)*(short *)(param_2 + 0xa6));
          uVar12 = *(undefined4 *)(param_2 + 0xd4);
        }
      }
      iVar2 = ac_packet_buf_send(param_2,uVar12);
      if (iVar2 != -1) {
        iVar2 = is_store_snapshot();
        if (iVar2 == 0) {
          return 0;
        }
        FUN_00524078();
        iVar2 = *(int *)(param_3 + 0x2c);
        if ((iVar5 != 0) && (pvVar13 != (void *)0x0)) {
          if (*(undefined1 **)(iVar5 + 0x54) != (undefined1 *)0x0) {
            **(undefined1 **)(iVar5 + 0x54) = 0;
            *(undefined1 *)(*(int *)(iVar5 + 0x54) + 1) = 1;
            *(undefined1 *)(*(int *)(iVar5 + 0x54) + 2) = 0;
            *(undefined4 *)(*(int *)(iVar5 + 0x54) + 4) = *(undefined4 *)(param_3 + 0x30);
            *(undefined4 *)(*(int *)(iVar5 + 0x54) + 8) = 0;
            *(int *)(*(int *)(iVar5 + 0x54) + 0xc) = extraout_v1_04 - iVar2;
          }
          uVar12 = *(undefined4 *)(param_3 + 0x28);
          *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(param_3 + 0x2c);
          *(undefined4 *)(iVar5 + 0x10) = uVar12;
          memcpy((void *)(iVar5 + 0x2c),pvVar13,6);
        }
        iVar5 = create_new_pkt_snapshot(4,param_1);
        get_pkt_info_by_buf(iVar5,*(undefined4 *)(param_2 + 0xd4),param_2 + 0xdc);
        if (iVar5 != 0) {
          if (pvVar13 != (void *)0x0) {
            if (*(undefined4 **)(iVar5 + 0x58) != (undefined4 *)0x0) {
              **(undefined4 **)(iVar5 + 0x58) = 0;
              *(undefined1 *)(*(int *)(iVar5 + 0x58) + 4) = 0;
              *(undefined4 *)(*(int *)(iVar5 + 0x58) + 8) = 0;
            }
            uVar16 = FUN_00524078();
            *(undefined8 *)(iVar5 + 0x10) = uVar16;
            memcpy((void *)(iVar5 + 0x2c),pvVar13,6);
            return 0;
          }
          return 0;
        }
        return 0;
      }
      if (capwap_warning_switch == 0) {
        return 0xffffffff;
      }
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      pcVar10 = "[CW_WARNING]%32s():%4d send packet failed\n";
      uVar12 = 0x32c;
      goto LAB_00592c80;
    }
    iVar2 = *(int *)(param_3 + 0x10);
  }
  if (iVar2 == 3) {
    if (*(int *)(param_2 + 0x10) == 0) {
      iVar2 = cw_sub_msg_ele_get(param_3,0x26,4);
      if (iVar2 == 0) goto LAB_00592e1c;
      memcpy((void *)(param_2 + 0x14),*(void **)(iVar2 + 0x10),6);
      *(undefined4 *)(param_2 + 0x10) = 1;
      if (capwap_debug_switch == 0) {
        iVar2 = *(int *)(param_2 + 0xd8);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_2 + 0xd8);
        }
        else {
          printf("[CW_DEBUG]%32s():%4d find session\'s mac address: %02x-%02x-%02x-%02x-%02x-%02x\n"
                 ,"ac_msg_handle",0x34c,(uint)*(byte *)(param_2 + 0x14),
                 (uint)*(byte *)(param_2 + 0x15),(uint)*(byte *)(param_2 + 0x16),
                 (uint)*(byte *)(param_2 + 0x17),(uint)*(byte *)(param_2 + 0x18),
                 (uint)*(byte *)(param_2 + 0x19));
          iVar2 = *(int *)(param_2 + 0xd8);
        }
      }
    }
    else {
LAB_00592e1c:
      iVar2 = *(int *)(param_2 + 0xd8);
    }
    if (iVar2 == 0) {
      __src = (void *)cw_msg_ele_val_get(param_3,0x32);
      if (__src != (void *)0x0) {
        memcpy((void *)(param_2 + 0xdc),__src,0x10);
        if ((capwap_debug_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
          *(undefined4 *)(param_2 + 0xd8) = 1;
        }
        else {
          if ((*(uint *)(param_2 + 0xdc) & 0x800) == 0) {
            pcVar10 = "not support";
          }
          else {
            pcVar10 = "support";
          }
          if ((*(uint *)(param_2 + 0xdc) & 0x40) == 0) {
            pcVar7 = "not support";
          }
          else {
            pcVar7 = "support";
          }
          printf("[CW_DEBUG]%32s():%4d find session\'s capacity: retransmit(%s) sta assoc with rssi(%s)\n"
                 ,"ac_msg_handle",0x356,pcVar10,pcVar7);
          *(undefined4 *)(param_2 + 0xd8) = 1;
        }
      }
    }
    puVar6 = (undefined1 *)cw_msg_ele_priv_val_get_from_pkt(param_3,0x86);
    if (puVar6 != (undefined1 *)0x0) {
      *(undefined2 *)(param_2 + 0xf0) = *(undefined2 *)(puVar6 + 2);
      *(undefined1 *)(param_2 + 0xf7) = *puVar6;
      *(undefined1 *)(param_2 + 0xf2) = puVar6[4];
    }
  }
  iVar2 = ac_parsed_packet_create(param_3);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    pcVar10 = "[CW_ERROR]%32s():%4d failed to create parsed packet\n";
    uVar12 = 0x364;
LAB_00592c80:
    printf(pcVar10,"ac_msg_handle",uVar12);
    return 0xffffffff;
  }
  memset(auStack_104,0,0x34);
  cw_ac_session_get_ip(param_2,auStack_f4);
  cw_ac_session_get_port(param_2,auStack_e0);
  local_dc = *(undefined4 *)(param_2 + 0x44);
  local_d8 = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x10);
  local_d4 = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x14);
  if (*(int *)(param_2 + 0x10) != 0) {
    memcpy(auStack_104,(void *)(param_2 + 0x14),6);
  }
  FUN_00524078();
  local_4c = extraout_v1;
  iVar3 = serv_mngr_handle(param_3,auStack_104,iVar2);
  if (iVar3 == -1) {
    if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_00593028;
    pcVar10 = "[CW_ERROR]%32s():%4d service manager handled the packet failed\n";
    uVar12 = 0x379;
  }
  else {
    FUN_00524078();
    local_50 = extraout_v1_00;
    if ((*(int *)(param_3 + 0x10) == 3) &&
       (iVar3 = ac_packet_is_right(iVar2,&local_220), iVar3 == 0)) {
      if (local_220 == 7) {
        if ((capwap_warning_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
        goto LAB_00593028;
        pcVar10 = "[CW_WARNING]%32s():%4d Already joined,please wait for a minute\n";
        uVar12 = 0x38b;
      }
      else {
        cw_fsm_ac_teardown(param_2);
        if ((capwap_warning_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
        goto LAB_00593028;
        pcVar10 = "[CW_WARNING]%32s():%4d not allowed to join the AC\n";
        uVar12 = 0x387;
      }
    }
    else {
      iVar3 = cw_msg_eles_length_update(iVar2);
      if (iVar3 == -1) {
        if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
        goto LAB_00593028;
        pcVar10 = "[CW_ERROR]%32s():%4d update packet\'s length failed\n";
        uVar12 = 0x393;
      }
      else {
        iVar3 = cw_pkt_buf_create(0xfa);
        if (iVar3 != 0) {
          iVar4 = (**(code **)(*(int *)(param_2 + 0xb0) + 4))(iVar3,iVar2);
          if (iVar4 == -1) {
            if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
            goto LAB_00593434;
            pcVar10 = "[CW_ERROR]%32s():%4d create response pkt buffer failed\n";
            uVar12 = 0x3a0;
          }
          else {
            iVar4 = ac_packet_buf_send(param_2,iVar3);
            if (iVar4 != -1) {
              iVar4 = is_store_snapshot();
              if (iVar4 == 0) {
                uVar9 = (ushort)*(byte *)(param_3 + 0x14);
              }
              else {
                FUN_00524078();
                iVar15 = *(int *)(param_3 + 0x2c);
                iVar4 = create_new_pkt_snapshot(4,param_1);
                get_pkt_info(iVar4,iVar2);
                if ((iVar4 != 0) && (pvVar13 != (void *)0x0)) {
                  if (*(undefined4 **)(iVar4 + 0x58) != (undefined4 *)0x0) {
                    **(undefined4 **)(iVar4 + 0x58) = 0;
                    *(undefined1 *)(*(int *)(iVar4 + 0x58) + 4) = 0;
                    *(undefined4 *)(*(int *)(iVar4 + 0x58) + 8) = 0;
                  }
                  uVar16 = FUN_00524078();
                  *(undefined8 *)(iVar4 + 0x10) = uVar16;
                  memcpy((void *)(iVar4 + 0x2c),pvVar13,6);
                }
                if (iVar5 == 0) {
                  uVar9 = (ushort)*(byte *)(param_3 + 0x14);
                }
                else if (pvVar13 == (void *)0x0) {
                  uVar9 = (ushort)*(byte *)(param_3 + 0x14);
                }
                else {
                  if (*(undefined1 **)(iVar5 + 0x54) != (undefined1 *)0x0) {
                    **(undefined1 **)(iVar5 + 0x54) = 0;
                    *(undefined1 *)(*(int *)(iVar5 + 0x54) + 1) = 0;
                    *(undefined1 *)(*(int *)(iVar5 + 0x54) + 2) = 0;
                    *(undefined4 *)(*(int *)(iVar5 + 0x54) + 4) = *(undefined4 *)(param_3 + 0x30);
                    *(int *)(*(int *)(iVar5 + 0x54) + 8) = (int)local_50 - local_4c;
                    *(int *)(*(int *)(iVar5 + 0x54) + 0xc) = extraout_v1_03 - iVar15;
                  }
                  uVar12 = *(undefined4 *)(param_3 + 0x28);
                  *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(param_3 + 0x2c);
                  *(undefined4 *)(iVar5 + 0x10) = uVar12;
                  memcpy((void *)(iVar5 + 0x2c),pvVar13,6);
                  uVar9 = (ushort)*(byte *)(param_3 + 0x14);
                }
              }
              *(ushort *)(param_2 + 0xa6) = uVar9;
              if (*(int *)(param_2 + 0xd4) != 0) {
                cw_pkt_buf_destroy();
              }
              *(int *)(param_2 + 0xd4) = iVar3;
              iVar5 = ac_packet_is_right(iVar2,&local_220);
              local_21c = 3;
              if (iVar5 == 0) {
                local_21c = 2;
              }
              local_218 = *(void **)(param_3 + 0x10);
              iVar5 = cw_fsm_ac_process_event(param_2,&local_21c);
              if (iVar5 != -1) {
                cw_parsed_pkt_destroy(iVar2);
                return 0;
              }
              if ((capwap_warning_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
              goto LAB_00593028;
              pcVar10 = "[CW_WARNING]%32s():%4d failed to process fsm event\n";
              uVar12 = 0x3cc;
              goto LAB_005933e8;
            }
            if ((capwap_warning_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
            goto LAB_00593434;
            pcVar10 = "[CW_WARNING]%32s():%4d failed to send packet\n";
            uVar12 = 0x3ac;
          }
          printf(pcVar10,"ac_msg_handle",uVar12);
LAB_00593434:
          cw_parsed_pkt_destroy(iVar2);
          cw_pkt_buf_destroy(iVar3);
          return 0xffffffff;
        }
        if ((capwap_err_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
        goto LAB_00593028;
        pcVar10 = "[CW_ERROR]%32s():%4d create response pkt buffer failed\n";
        uVar12 = 0x39a;
      }
    }
  }
LAB_005933e8:
  printf(pcVar10,"ac_msg_handle",uVar12);
LAB_00593028:
  cw_parsed_pkt_destroy(iVar2);
  return 0xffffffff;
LAB_00593694:
  local_34 = param_2 + 0xdc;
  local_48 = (void *)0x0;
  local_30 = (void *)(param_2 + 0x14);
  pvVar13 = (void *)0x0;
  while (iVar2 = FUN_004081b0(&local_214), iVar2 != 0) {
    FUN_00408500(iVar2);
    iVar3 = *(int *)(iVar2 + 0xc);
    if (iVar3 == 0) {
LAB_0059388c:
      FUN_00407df0(iVar2);
    }
    else {
      *(undefined4 *)(iVar3 + 8) = 1;
      if (local_48 == (void *)0x0) {
        local_218 = (void *)cw_control_header_msg_type_get(*(undefined4 *)(iVar3 + 0x10));
        local_21c = 0xb;
        local_50 = local_218;
        iVar4 = cw_fsm_ac_process_event(param_2,&local_21c);
        if (iVar4 == 0) {
          cVar11 = '\x01';
          if (*(char *)(param_2 + 0xa4) != -1) {
            cVar11 = *(char *)(param_2 + 0xa4) + '\x01';
          }
          *(char *)(param_2 + 0xa4) = cVar11;
          cw_control_header_seq_num_set(*(undefined4 *)(iVar3 + 0x10));
          local_40 = iVar3 + 0x10;
          iVar4 = ac_packet_buf_send(param_2,local_40);
          if (iVar4 == 0) {
            uVar16 = FUN_00524078();
            local_3c = (undefined4)((ulonglong)uVar16 >> 0x20);
            local_44 = (int)uVar16;
            iVar4 = is_store_snapshot();
            if (iVar4 != 0) {
              local_38 = *(int *)(*(int *)(iVar5 + 0x14) + 0xc);
              iVar4 = create_new_pkt_snapshot(3,param_1);
              get_pkt_info_by_buf(iVar4,local_40,local_34);
              if (iVar4 != 0) {
                if (*(undefined4 **)(iVar4 + 0x58) != (undefined4 *)0x0) {
                  **(undefined4 **)(iVar4 + 0x58) = 0;
                  *(undefined1 *)(*(int *)(iVar4 + 0x58) + 4) = 0;
                  *(int *)(*(int *)(iVar4 + 0x58) + 8) = local_44 - local_38;
                }
                *(undefined4 *)(iVar4 + 0x10) = local_3c;
                *(int *)(iVar4 + 0x14) = local_44;
                memcpy((void *)(iVar4 + 0x2c),local_30,6);
              }
            }
            *(undefined4 *)(iVar3 + 0x40) = local_3c;
            *(int *)(iVar3 + 0x44) = local_44;
            if ((local_50 == (void *)0x11) &&
               (iVar4 = ac_send_packet_response_need(iVar3), iVar4 == 0)) goto LAB_005938f4;
            local_21c = 0xc;
            local_218 = local_50;
            iVar4 = cw_fsm_ac_process_event(param_2,&local_21c);
            if (iVar4 != -1) {
              iVar4 = ac_send_packet_response_need(iVar3);
              if (iVar4 != 0) {
                pvVar13 = (void *)FUN_00408450(0x18,0x534);
                if (pvVar13 != (void *)0x0) {
                  memset(pvVar13,0,0x18);
                  *(int *)((int)pvVar13 + 0x10) = iVar3;
                  *(undefined4 *)(iVar2 + 0xc) = 0;
                  cw_ac_pkt_retransmit_para_fixed(iVar3,param_2);
                  iVar3 = cw_ac_retransmit_timer_start(param_2,*(undefined4 *)(iVar3 + 4));
                  if (iVar3 == 0) {
                    FUN_00408170(iVar5,pvVar13);
                    local_48 = (void *)0x1;
                    *(undefined1 *)(param_2 + 0xa8) = *(undefined1 *)(param_2 + 0xa4);
                    goto LAB_0059381c;
                  }
                }
                goto LAB_00593d08;
              }
              goto LAB_00593884;
            }
            iVar5 = -1;
            if ((capwap_warning_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              pcVar10 = "[CW_WARNING]%32s():%4d session[%p] process fsm failed\n";
              uVar12 = 0x52e;
              goto LAB_00593d38;
            }
          }
          else {
            iVar5 = -1;
            if ((capwap_warning_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              uVar12 = 0x50e;
              pcVar10 = "[CW_WARNING]%32s():%4d session[%p] sends packet failed\n";
LAB_00593d38:
              iVar5 = -1;
              printf(pcVar10,"ac_msg_handle",uVar12,param_2);
            }
          }
        }
        else {
          if (local_50 != (void *)0x11) {
LAB_00593884:
            cw_send_pkt_destroy(*(undefined4 *)(iVar2 + 0xc));
            goto LAB_0059388c;
          }
          memset(auStack_208,0,0x34);
          memcpy(auStack_1f8,(void *)(param_2 + 0x2c),0x14);
          local_1e4 = *(undefined2 *)(param_2 + 0x40);
          memcpy(auStack_208,(void *)(param_2 + 0x14),6);
          serv_ent_handle(2,auStack_208,0,0);
LAB_005938f4:
          iVar5 = 0;
          cw_fsm_ac_teardown(param_2);
        }
LAB_005938fc:
        cw_user_send_pkt_node_destroy(iVar2);
        if (pvVar13 != (void *)0x0) {
          FUN_00407df0(pvVar13);
        }
        goto LAB_00593918;
      }
      pvVar13 = (void *)FUN_00408450(0x18,0x563);
      if (pvVar13 == (void *)0x0) {
LAB_00593d08:
        iVar5 = -1;
        goto LAB_005938fc;
      }
      memset(pvVar13,0,0x18);
      *(int *)((int)pvVar13 + 0x10) = iVar3;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      iVar4 = *(int *)(iVar5 + 0x14);
      if (iVar4 != 0) {
        uVar12 = *(undefined4 *)(iVar4 + 8);
        *(undefined4 *)(iVar3 + 0x44) = *(undefined4 *)(iVar4 + 0xc);
        *(undefined4 *)(iVar3 + 0x40) = uVar12;
      }
      FUN_00408170(iVar5,pvVar13);
LAB_0059381c:
      cw_user_send_pkt_node_destroy(iVar2);
    }
  }
  iVar5 = -1;
  FUN_0051ad88(&local_214);
LAB_00593918:
  iVar2 = FUN_00407fe0(&local_214);
  if (iVar2 != 0) {
    while (iVar2 = FUN_004081b0(&local_214), iVar2 != 0) {
      FUN_00408500(iVar2);
      if (*(int *)(iVar2 + 0xc) != 0) {
        *(undefined4 *)(*(int *)(iVar2 + 0xc) + 8) = 1;
      }
      cw_user_send_pkt_node_destroy(iVar2);
    }
  }
  pvVar13 = local_48;
  if (iVar5 == 0) {
    return 0;
  }
  goto joined_r0x00593538;
}

