// func cw_ac_data_manager_user_packet_event_process @ 0058b1b4 size=2052

void cw_ac_data_manager_user_packet_event_process(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *__s;
  int iVar4;
  char *pcVar5;
  char cVar6;
  undefined4 uVar7;
  int iVar8;
  void *__s_00;
  undefined8 uVar9;
  undefined4 local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 auStack_ac [16];
  undefined1 auStack_9c [20];
  undefined2 local_88;
  undefined1 auStack_78 [16];
  undefined1 auStack_68 [20];
  undefined2 local_54;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  memset(auStack_78,0,0x34);
  if (param_2 == (int *)0x0) {
    uVar7 = 0x58a;
    pcVar5 = "pkt";
  }
  else if (param_2[1] == 0) {
    uVar7 = 0x58b;
    pcVar5 = "pkt->cb";
  }
  else {
    if (param_1 != 0) {
      if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_DEBUG]%32s():%4d cw_ac_data_manager_user_packet_event_process start\n",
               "cw_ac_data_manager_user_packet_event_process",0x58d);
      }
      iVar4 = param_1 + 0xf8;
      iVar1 = FUN_00407fe0(iVar4);
      if (iVar1 == 0) {
        memcpy(auStack_68,(void *)(param_1 + 0x2c),0x14);
        __s_00 = (void *)0x0;
        local_54 = *(undefined2 *)(param_1 + 0x40);
        memcpy(auStack_78,(void *)(param_1 + 0x14),6);
LAB_0058b26c:
        FUN_0051ad88(&local_b8);
        iVar1 = (*(code *)param_2[1])(auStack_78,&local_b8);
        if (iVar1 == 0) {
LAB_0058b774:
          if (capwap_warning_switch == 0) {
            iVar1 = *param_2;
            goto LAB_0058b514;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            iVar1 = *param_2;
            goto LAB_0058b514;
          }
          pcVar5 = "[CW_WARNING]%32s():%4d session[%p]\'s cb is called failed\n";
          uVar7 = 0x5a2;
        }
        else {
          if (iVar1 == 1) {
            iVar1 = FUN_00407fe0(&local_b8);
            if (iVar1 != 0) goto LAB_0058b2a4;
            goto LAB_0058b774;
          }
          if (iVar1 != 3) {
LAB_0058b2a4:
            if (capwap_debug_switch == 0) {
              local_40 = 0;
            }
            else {
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                local_40 = 0;
              }
              else {
                uVar7 = FUN_00407fe0(&local_b8);
                printf("[CW_DEBUG]%32s():%4d packet size[%d]\n",
                       "cw_ac_data_manager_user_packet_event_process",0x5bf,uVar7);
                local_40 = 0;
              }
            }
            while (iVar1 = FUN_004081b0(&local_b8), iVar1 != 0) {
              FUN_00408500(iVar1);
              iVar8 = *(int *)(iVar1 + 0xc);
              if (iVar8 == 0) {
                FUN_00407df0(iVar1);
                if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  printf("[CW_DEBUG]%32s():%4d pkt_to_send is NULL\n",
                         "cw_ac_data_manager_user_packet_event_process",0x5c7);
                }
              }
              else {
                *(undefined4 *)(iVar8 + 8) = 1;
                iVar2 = FUN_00407fe0(iVar4);
                if (iVar2 != 0) {
                  __s_00 = (void *)FUN_00408450(0x18,0x626);
                  if (__s_00 != (void *)0x0) {
                    memset(__s_00,0,0x18);
                    *(int *)((int)__s_00 + 0x10) = iVar8;
                    *(undefined4 *)(iVar1 + 0xc) = 0;
                    iVar2 = param_2[2];
                    *(int *)(iVar8 + 0x44) = param_2[3];
                    *(int *)(iVar8 + 0x40) = iVar2;
                    FUN_004086b0(iVar4,__s_00);
                    goto LAB_0058b430;
                  }
LAB_0058b4e4:
                  cw_user_send_pkt_node_destroy(iVar1);
                  goto LAB_0058b4ec;
                }
                iVar2 = cw_control_header_msg_type_get(*(undefined4 *)(iVar8 + 0x10));
                local_c0 = 0xb;
                local_bc = iVar2;
                iVar3 = cw_fsm_ac_process_event(param_1,&local_c0);
                if (iVar3 != 0) {
                  if (iVar2 != 0x11) goto LAB_0058b430;
                  memset(auStack_ac,0,0x34);
                  memcpy(auStack_9c,(void *)(param_1 + 0x2c),0x14);
                  local_88 = *(undefined2 *)(param_1 + 0x40);
                  memcpy(auStack_ac,(void *)(param_1 + 0x14),6);
                  serv_ent_handle(2,auStack_ac,0,0);
LAB_0058b4dc:
                  cw_fsm_ac_teardown(param_1);
                  goto LAB_0058b4e4;
                }
                cVar6 = '\x01';
                if (*(char *)(param_1 + 0xa4) != -1) {
                  cVar6 = *(char *)(param_1 + 0xa4) + '\x01';
                }
                *(char *)(param_1 + 0xa4) = cVar6;
                cw_control_header_seq_num_set(*(undefined4 *)(iVar8 + 0x10));
                local_38 = iVar8 + 0x10;
                iVar3 = ac_packet_buf_send(param_1,local_38);
                if (iVar3 != 0) {
                  if ((capwap_warning_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                    pcVar5 = "[CW_WARNING]%32s():%4d session[%p] sends packet failed\n";
                    uVar7 = 0x5d7;
LAB_0058b844:
                    printf(pcVar5,"cw_ac_data_manager_user_packet_event_process",uVar7,param_1);
                  }
                  goto LAB_0058b4e4;
                }
                uVar9 = FUN_00524078();
                local_34 = (undefined4)((ulonglong)uVar9 >> 0x20);
                local_3c = (int)uVar9;
                if (open_store_snapshot != 0) {
                  local_30 = param_2[3];
                  iVar3 = create_new_pkt_snapshot(3,*(undefined4 *)(param_1 + 0xc));
                  get_pkt_info_by_buf(iVar3,local_38,param_1 + 0xdc);
                  uVar9 = CONCAT44(local_34,local_3c);
                  if (iVar3 != 0) {
                    if (*(undefined4 **)(iVar3 + 0x58) != (undefined4 *)0x0) {
                      **(undefined4 **)(iVar3 + 0x58) = 0;
                      *(undefined1 *)(*(int *)(iVar3 + 0x58) + 4) = 0;
                      *(int *)(*(int *)(iVar3 + 0x58) + 8) = local_3c - local_30;
                    }
                    *(undefined4 *)(iVar3 + 0x10) = local_34;
                    *(int *)(iVar3 + 0x14) = local_3c;
                    memcpy((void *)(iVar3 + 0x2c),(void *)(param_1 + 0x14),6);
                    uVar9 = CONCAT44(local_34,local_3c);
                  }
                }
                local_34 = (undefined4)((ulonglong)uVar9 >> 0x20);
                local_3c = (int)uVar9;
                *(undefined8 *)(iVar8 + 0x40) = uVar9;
                if (iVar2 == 0x11) {
                  iVar3 = ac_send_packet_response_need(iVar8);
                  uVar9 = CONCAT44(local_34,local_3c);
                  if (iVar3 == 0) goto LAB_0058b4dc;
                }
                local_34 = (undefined4)((ulonglong)uVar9 >> 0x20);
                local_3c = (int)uVar9;
                local_c0 = 0xc;
                local_bc = iVar2;
                iVar2 = cw_fsm_ac_process_event(param_1,&local_c0);
                if (iVar2 == -1) {
                  if ((capwap_warning_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                    pcVar5 = "[CW_WARNING]%32s():%4d session[%p] process fsm failed\n";
                    uVar7 = 0x5f4;
                    goto LAB_0058b844;
                  }
                  goto LAB_0058b4e4;
                }
                iVar2 = ac_send_packet_response_need(iVar8);
                if (iVar2 != 0) {
                  __s_00 = (void *)FUN_00408450(0x18,0x5fa);
                  if (__s_00 != (void *)0x0) {
                    memset(__s_00,0,0x18);
                    *(int *)((int)__s_00 + 0x10) = iVar8;
                    *(undefined4 *)(iVar1 + 0xc) = 0;
                    iVar2 = cw_ac_pkt_retransmit_para_fixed(iVar8,param_1);
                    if ((iVar2 == 0) &&
                       (iVar8 = cw_ac_retransmit_timer_start(param_1,*(undefined4 *)(iVar8 + 4)),
                       iVar8 == 0)) {
                      local_40 = local_40 + 1;
                      FUN_004086b0(iVar4,__s_00);
                      *(undefined1 *)(param_1 + 0xa8) = *(undefined1 *)(param_1 + 0xa4);
                      goto LAB_0058b430;
                    }
                  }
                  goto LAB_0058b4e4;
                }
LAB_0058b430:
                cw_user_send_pkt_node_destroy(iVar1);
              }
            }
            if (local_40 != 0) goto code_r0x0058b72c;
            goto LAB_0058b26c;
          }
          iVar1 = cw_ac_manager_data_create(0,3,param_2);
          if (iVar1 == 0) {
            if (capwap_warning_switch == 0) {
              iVar1 = *param_2;
              goto LAB_0058b514;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              iVar1 = *param_2;
              goto LAB_0058b514;
            }
            pcVar5 = "[CW_WARNING]%32s():%4d session[%p]\'s cw_ac_manager_data_create failed\n";
            uVar7 = 0x5ab;
          }
          else {
            iVar4 = cw_ac_manager_data_add
                              (iVar1,*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30)
                               ,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
                               *(undefined4 *)(param_1 + 0x3c),*(undefined2 *)(param_1 + 0x40));
            if (iVar4 == 0) {
              uVar7 = ip_to_ac_data(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
                                    *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
                                    *(undefined4 *)(param_1 + 0x3c),*(undefined2 *)(param_1 + 0x40))
              ;
              iVar4 = cw_ac_manager_event_add(uVar7,iVar1);
              if (iVar4 == 0) {
                return;
              }
              cw_ac_manager_data_destroy(iVar1);
              if (capwap_warning_switch == 0) {
                iVar1 = *param_2;
              }
              else {
                iVar1 = is_target_debug_ap();
                if (iVar1 != 0) {
                  pcVar5 = "[CW_WARNING]%32s():%4d session[%p]\'s cw_ac_manager_event_add failed\n";
                  uVar7 = 0x5b9;
                  goto LAB_0058b7a8;
                }
                iVar1 = *param_2;
              }
              goto LAB_0058b514;
            }
            cw_ac_manager_data_destroy(iVar1);
            if (capwap_warning_switch == 0) {
              iVar1 = *param_2;
              goto LAB_0058b514;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              iVar1 = *param_2;
              goto LAB_0058b514;
            }
            pcVar5 = "[CW_WARNING]%32s():%4d session[%p]\'s cw_ac_manager_data_add failed\n";
            uVar7 = 0x5b2;
          }
        }
LAB_0058b7a8:
        printf(pcVar5,"cw_ac_data_manager_user_packet_event_process",uVar7,param_1);
        iVar1 = *param_2;
        goto LAB_0058b514;
      }
      __s = (void *)FUN_00408450(0x18,0x64c);
      if (__s == (void *)0x0) goto LAB_0058b500;
      memset(__s,0,0x18);
      *(int **)((int)__s + 0x14) = param_2;
      *(undefined1 *)((int)__s + 0xc) = 3;
      goto LAB_0058b698;
    }
    uVar7 = 0x58c;
    pcVar5 = "session";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_data_manager_user_packet_event_process",
         uVar7,pcVar5);
  return;
code_r0x0058b72c:
  __s = (void *)FUN_00408450(0x18,0x63c);
  if (__s == (void *)0x0) {
LAB_0058b4ec:
    if (__s_00 != (void *)0x0) {
      FUN_00407df0(__s_00);
    }
LAB_0058b500:
    iVar1 = FUN_00407fe0(&local_b8);
    if (iVar1 == 0) {
      iVar1 = *param_2;
    }
    else {
      FUN_004081b0(&local_b8);
      while (iVar1 = FUN_004081b0(&local_b8), iVar1 != 0) {
        FUN_00408500(iVar1);
        if (*(int *)(iVar1 + 0xc) != 0) {
          *(undefined4 *)(*(int *)(iVar1 + 0xc) + 8) = 1;
        }
        cw_user_send_pkt_node_destroy(iVar1);
      }
      iVar1 = *param_2;
    }
LAB_0058b514:
    *param_2 = iVar1 + -1;
    return;
  }
  memset(__s,0,0x18);
  *(int **)((int)__s + 0x14) = param_2;
  *(undefined1 *)((int)__s + 0xc) = 3;
LAB_0058b698:
  FUN_004086b0(iVar4,__s);
  return;
}

