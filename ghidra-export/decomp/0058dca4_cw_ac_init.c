// func cw_ac_init @ 0058dca4 size=5724

undefined4 cw_ac_init(void)

{
  int *piVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  char acStack_50 [32];
  undefined4 local_30;
  
  pvVar2 = (void *)FUN_00408450(0xcc48,0xa97);
  ac = pvVar2;
  if (pvVar2 == (void *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d Failed to allloc ac, %d bytes needed.\n","cw_ac_init",0xa9a,0xa0);
    return 0xffffffff;
  }
  memset(pvVar2,0,0xcc48);
  FUN_0051ad88((int)pvVar2 + 0xcc24);
  FUN_0051ad88((int)ac + 0xcc30);
  FUN_0051ad88((int)ac + 0xcc3c);
  puVar3 = (undefined4 *)FUN_00408450(0x148,0xcb);
  l_profile = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d malloc failed.\n","cw_ac_profile_init",0xce);
    }
  }
  else {
    memset(puVar3,0,0x148);
    iVar4 = FUN_0051eb48("ac_capwap","frag_enable",puVar3);
    if (iVar4 == -1) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        uVar8 = 0xd6;
LAB_0058e270:
        printf("[CW_ERROR]%32s():%4d read profile failed.\n","cw_ac_profile_init",uVar8);
      }
    }
    else {
      iVar4 = FUN_0051eb48("ac_capwap","frag_mtu",l_profile + 1);
      if (iVar4 == -1) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          uVar8 = 0xdb;
          goto LAB_0058e270;
        }
      }
      else {
        iVar4 = FUN_0051eb48("ac_capwap","session_num",l_profile + 2);
        if (iVar4 == -1) {
          if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            uVar8 = 0xe0;
            goto LAB_0058e270;
          }
        }
        else {
          iVar4 = FUN_0051eb48("ac_capwap","pkt_queue_size",l_profile + 3);
          if (iVar4 == -1) {
            if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              uVar8 = 0xe5;
              goto LAB_0058e270;
            }
          }
          else {
            iVar4 = FUN_0051eb48("ac_capwap","mngr_queue_size",l_profile + 4);
            if (iVar4 == -1) {
              if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                uVar8 = 0xea;
                goto LAB_0058e270;
              }
            }
            else {
              iVar4 = FUN_0051eb48("ac_capwap","timer_size",l_profile + 5);
              if (iVar4 == -1) {
                if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                  uVar8 = 0xef;
                  goto LAB_0058e270;
                }
              }
              else {
                iVar4 = FUN_0051eb48("ac_capwap","timer_max_time",l_profile + 6);
                if (iVar4 == -1) {
                  if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                    uVar8 = 0xf4;
                    goto LAB_0058e270;
                  }
                }
                else {
                  iVar4 = FUN_0051eb48("ac_capwap","timer_process_num",l_profile + 7);
                  if (iVar4 == -1) {
                    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                      uVar8 = 0xf9;
                      goto LAB_0058e270;
                    }
                  }
                  else {
                    iVar4 = FUN_0051eb48("ac_capwap","mngr_process_num",l_profile + 8);
                    if (iVar4 == -1) {
                      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                        uVar8 = 0xfe;
                        goto LAB_0058e270;
                      }
                    }
                    else {
                      iVar4 = FUN_0051eb48("ac_capwap","pkt_process_num",l_profile + 9);
                      if (iVar4 == -1) {
                        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0))
                        {
                          uVar8 = 0x103;
                          goto LAB_0058e270;
                        }
                      }
                      else {
                        iVar4 = FUN_0051eb48("ac_capwap","thread_size",l_profile + 10);
                        if (iVar4 == -1) {
                          if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)
                             ) {
                            uVar8 = 0x108;
                            goto LAB_0058e270;
                          }
                        }
                        else {
                          iVar4 = FUN_00407f90("ac_capwap","cacert_file_path",l_profile + 0xb,0x80);
                          if (iVar4 == -1) {
                            if ((capwap_err_switch != 0) &&
                               (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                              uVar8 = 0x10d;
                              goto LAB_0058e270;
                            }
                          }
                          else {
                            iVar4 = FUN_00407f90("ac_capwap","privkey_file_path",l_profile + 0x2b,
                                                 0x80);
                            if (iVar4 == -1) {
                              if ((capwap_err_switch != 0) &&
                                 (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                uVar8 = 0x112;
                                goto LAB_0058e270;
                              }
                            }
                            else {
                              iVar4 = FUN_0051eb48("ac_capwap","socket_recv_buffer_size",
                                                   l_profile + 0x4b);
                              if (iVar4 == -1) {
                                if ((capwap_err_switch != 0) &&
                                   (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                  uVar8 = 0x117;
                                  goto LAB_0058e270;
                                }
                              }
                              else {
                                iVar4 = FUN_0051eb48("ac_capwap","socket_send_buffer_size",
                                                     l_profile + 0x4c);
                                if (iVar4 == -1) {
                                  if ((capwap_err_switch != 0) &&
                                     (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                    uVar8 = 0x11c;
                                    goto LAB_0058e270;
                                  }
                                }
                                else {
                                  iVar4 = FUN_0051eb48("ac_capwap","default_retransmit_time",
                                                       l_profile + 0x4e);
                                  if (iVar4 == -1) {
                                    if ((capwap_err_switch != 0) &&
                                       (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                      uVar8 = 0x121;
                                      goto LAB_0058e270;
                                    }
                                  }
                                  else {
                                    iVar4 = FUN_0051eb48("ac_capwap","retransmit_max_retries",
                                                         l_profile + 0x4f);
                                    if (iVar4 == -1) {
                                      if ((capwap_err_switch != 0) &&
                                         (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                        uVar8 = 0x126;
                                        goto LAB_0058e270;
                                      }
                                    }
                                    else {
                                      iVar4 = FUN_0051eb48("ac_capwap","max_session_num",
                                                           l_profile + 0x50);
                                      if (iVar4 == -1) {
                                        if ((capwap_err_switch != 0) &&
                                           (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                          uVar8 = 299;
                                          goto LAB_0058e270;
                                        }
                                      }
                                      else {
                                        iVar4 = FUN_0051eb48("ac_capwap","max_pkt_snapshot_mem_size"
                                                             ,l_profile + 0x51);
                                        if (iVar4 != -1) {
                                          iVar4 = serv_msg_mngr_init();
                                          if ((iVar4 != 0) ||
                                             (iVar4 = serv_ent_mngr_init(), iVar4 != 0))
                                          goto LAB_0058dfdc;
                                          if ((capwap_debug_switch != 0) &&
                                             (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                            printf("[CW_DEBUG]%32s():%4d init network\n",
                                                   "cw_ac_init",0xacb);
                                          }
                                          pvVar2 = ac;
                                          if (ac == (void *)0x0) {
                                            printf("[ASSERT]%32s():%4d assert(%s) failed\n",
                                                   "cw_ac_network_init",0x449,"ac");
                                          }
                                          else {
                                            *(undefined4 *)((int)ac + 4) = 0;
                                            *(undefined2 *)((int)pvVar2 + 8) = 0x147e;
                                            iVar4 = capwap_socket_init((int)pvVar2 + 0xc);
                                            if (iVar4 == 0) {
                                              iVar4 = capwap_socket_recvbuffer_set
                                                                (*(undefined4 *)((int)ac + 0xc),
                                                                 l_profile[0x4b]);
                                              if (iVar4 == 0) {
                                                iVar4 = capwap_socket_sendbuffer_set
                                                                  (*(undefined4 *)((int)ac + 0xc),
                                                                   l_profile[0x4c]);
                                                pvVar2 = ac;
                                                if (iVar4 == 0) {
                                                  *(undefined4 *)((int)ac + 0x10) = 0xffffffff;
                                                  *(undefined4 *)((int)pvVar2 + 0x14) = 0xffffffff;
                                                  iVar4 = capwap_ipv6_socket_init
                                                                    ((int)pvVar2 + 0x10);
                                                  if (iVar4 == 0) {
                                                    iVar4 = capwap_socket_recvbuffer_set
                                                                      (*(undefined4 *)
                                                                        ((int)ac + 0x10),
                                                                       l_profile[0x4b]);
                                                    if (iVar4 == 0) {
                                                      iVar4 = capwap_socket_sendbuffer_set
                                                                        (*(undefined4 *)
                                                                          ((int)ac + 0x10),
                                                                         l_profile[0x4c]);
                                                      if (iVar4 == 0) {
                                                        iVar4 = capwap_netlink_socket_init
                                                                          ((int)ac + 0x14);
                                                        if (iVar4 == 0) {
                                                          capwap_dtls_global_init();
                                                          if ((capwap_debug_switch != 0) &&
                                                             (iVar4 = is_target_debug_ap(),
                                                             iVar4 != 0)) {
                                                            printf(
                                                  "[CW_DEBUG]%32s():%4d init network finished.\n",
                                                  "cw_ac_network_init",0x484);
                                                  }
                                                  if ((capwap_debug_switch != 0) &&
                                                     (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                    printf(
                                                  "[CW_DEBUG]%32s():%4d init ac-data array\n",
                                                  "cw_ac_init",0xad4);
                                                  }
                                                  if (ac == (void *)0x0) {
                                                    printf("[ASSERT]%32s():%4d assert(%s) failed\n",
                                                           "cw_ac_data_array_init",0x402,"ac");
                                                  }
                                                  else {
                                                    if ((capwap_debug_switch != 0) &&
                                                       (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                      printf(
                                                  "[CW_DEBUG]%32s():%4d init ac\'s ac_data array\n",
                                                  "cw_ac_data_array_init",0x405);
                                                  }
                                                  pvVar2 = ac;
                                                  iVar4 = l_profile[10];
                                                  *(int *)((int)ac + 0x18) = iVar4;
                                                  uVar8 = FUN_00408450(iVar4 * 0xa0,0x407);
                                                  *(undefined4 *)((int)pvVar2 + 0x1c) = uVar8;
                                                  if (*(void **)((int)ac + 0x1c) == (void *)0x0) {
                                                    if ((capwap_err_switch != 0) &&
                                                       (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                      pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d malloc ac data array failed\n"
                                                  ;
                                                  uVar8 = 0x40a;
LAB_0058ee8c:
                                                  printf(pcVar7,"cw_ac_data_array_init",uVar8);
                                                  }
                                                  }
                                                  else {
                                                    memset(*(void **)((int)ac + 0x1c),0,
                                                           *(int *)((int)ac + 0x18) * 0xa0);
                                                    uVar9 = 0;
LAB_0058e844:
                                                    do {
                                                      uVar10 = uVar9;
                                                      pvVar2 = ac;
                                                      if (*(uint *)((int)ac + 0x18) <= uVar10) {
                                                        uVar8 = FUN_00408450(*(uint *)((int)ac +
                                                                                      0x18) << 2,
                                                                             0x41b);
                                                        *(undefined4 *)((int)pvVar2 + 0x20) = uVar8;
                                                        pvVar2 = ac;
                                                        if (*(void **)((int)ac + 0x20) ==
                                                            (void *)0x0) {
                                                          if ((capwap_err_switch == 0) ||
                                                             (iVar4 = is_target_debug_ap(),
                                                             iVar4 == 0)) goto LAB_0058e978;
                                                          pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d malloc ac data thread id failed\n"
                                                  ;
                                                  uVar8 = 0x41e;
                                                  }
                                                  else {
                                                    memset(*(void **)((int)ac + 0x20),0,
                                                           *(int *)((int)ac + 0x18) << 2);
                                                    uVar9 = 0;
                                                    if (*(int *)((int)pvVar2 + 0x1c) != 0)
                                                    goto LAB_0058ee00;
                                                    if ((capwap_err_switch == 0) ||
                                                       (iVar4 = is_target_debug_ap(), iVar4 == 0))
                                                    goto LAB_0058e978;
                                                    pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d init  ac_data snapshot list failed\n"
                                                  ;
                                                  uVar8 = 0x426;
                                                  }
                                                  goto LAB_0058ee8c;
                                                  }
                                                  uVar9 = uVar10 + 1;
                                                  *(uint *)(*(int *)((int)ac + 0x1c) + uVar10 * 0xa0
                                                           + 4) = uVar9;
                                                  puVar3 = l_profile;
                                                  iVar4 = *(int *)((int)pvVar2 + 0x1c) +
                                                          uVar10 * 0xa0;
                                                  local_30 = *(undefined4 *)((int)pvVar2 + 0xc);
                                                  uVar8 = *(undefined4 *)((int)pvVar2 + 0x10);
                                                  if (iVar4 == 0) {
                                                    printf("[ASSERT]%32s():%4d assert(%s) failed\n",
                                                           "cw_ac_data_init",0x3b4,&DAT_006de7a4);
                                                    break;
                                                  }
                                                  *(undefined4 *)(iVar4 + 0xc) = l_profile[1];
                                                  *(undefined4 *)(iVar4 + 8) = *puVar3;
                                                  if ((capwap_debug_switch != 0) &&
                                                     (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                    printf("[CW_DEBUG]%32s():%4d init session.\n",
                                                           "cw_ac_data_init",0x3ba);
                                                  }
                                                  *(undefined4 *)(iVar4 + 0x48) = l_profile[2];
                                                  FUN_0051ad88(iVar4 + 0x4c);
                                                  iVar5 = capwap_ac_session_hash_create
                                                                    (*(int *)(iVar4 + 0x48) << 1);
                                                  *(int *)(iVar4 + 0x58) = iVar5;
                                                  if (iVar5 == 0) {
                                                    if ((capwap_err_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf(
                                                  "[CW_ERROR]%32s():%4d init ac session hash failed.\n"
                                                  ,"cw_ac_data_session_init",0x333);
                                                  }
                                                  iVar5 = -1;
                                                  if ((capwap_err_switch == 0) ||
                                                     (iVar6 = is_target_debug_ap(), iVar6 == 0))
                                                  goto LAB_0058e930;
                                                  pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d Failed to init session.\n";
                                                  uVar8 = 0x3be;
LAB_0058eb10:
                                                  printf(pcVar7,"cw_ac_data_init",uVar8);
                                                  }
                                                  else {
                                                    if ((capwap_debug_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf("[CW_DEBUG]%32s():%4d init manager.\n",
                                                             "cw_ac_data_init",0x3c3);
                                                    }
                                                    memset(acStack_50,0,0x1e);
                                                    if ((capwap_debug_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf(
                                                  "[CW_DEBUG]%32s():%4d init ac_data\'s manager pipe\n"
                                                  ,"cw_ac_data_manager_init",0x379);
                                                  }
                                                  iVar5 = pipe((int *)(iVar4 + 0x30));
                                                  if (iVar5 == 0) {
                                                    if ((capwap_debug_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf(
                                                  "[CW_DEBUG]%32s():%4d init manager message queue\n"
                                                  ,"cw_ac_data_manager_init",0x381);
                                                  }
                                                  *(undefined4 *)(iVar4 + 0x3c) = l_profile[4];
                                                  snprintf(acStack_50,0x1e,"%s%d",
                                                           "capwap_manager_queue_",
                                                           *(undefined4 *)(iVar4 + 4));
                                                  iVar5 = cw_packet_queue_create
                                                                    (*(undefined4 *)(iVar4 + 0x3c),
                                                                     *(undefined4 *)(iVar4 + 0x30),
                                                                     *(undefined4 *)(iVar4 + 0x34),
                                                                     acStack_50);
                                                  *(int *)(iVar4 + 0x38) = iVar5;
                                                  if (iVar5 == 0) {
                                                    if ((capwap_err_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d create manager queue failed.\n"
                                                  ;
                                                  uVar8 = 0x386;
                                                  goto LAB_0058ec3c;
                                                  }
                                                  goto LAB_0058e924;
                                                  }
                                                  if ((capwap_debug_switch != 0) &&
                                                     (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                    printf("[CW_DEBUG]%32s():%4d init event.\n",
                                                           "cw_ac_data_init",0x3cc);
                                                  }
                                                  iVar5 = socket(2,1,0);
                                                  *(int *)(iVar4 + 0x40) = iVar5;
                                                  if (iVar5 < 0) {
                                                    if ((capwap_err_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf(
                                                  "[CW_ERROR]%32s():%4d create event fd failed.\n",
                                                  "cw_ac_data_event_init",0x39e);
                                                  }
                                                  iVar5 = -1;
                                                  if ((capwap_err_switch != 0) &&
                                                     (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                                                    pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d Failed to init event.\n";
                                                  uVar8 = 0x3d0;
                                                  goto LAB_0058eb10;
                                                  }
                                                  }
                                                  else {
                                                    if ((capwap_debug_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf("[CW_DEBUG]%32s():%4d init network.\n",
                                                             "cw_ac_data_init",0x3d5);
                                                    }
                                                    memset(acStack_50,0,0x1e);
                                                    if ((capwap_debug_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf(
                                                  "[CW_DEBUG]%32s():%4d init ac_data\'s queue pipe\n"
                                                  ,"cw_ac_data_network_init",0x349);
                                                  }
                                                  iVar5 = pipe((int *)(iVar4 + 0x18));
                                                  if (iVar5 == 0) {
                                                    if ((capwap_debug_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf("[CW_DEBUG]%32s():%4d bind socket\n",
                                                             "cw_ac_data_network_init",0x34f);
                                                    }
                                                    *(undefined4 *)(iVar4 + 0x14) = uVar8;
                                                    *(undefined4 *)(iVar4 + 0x10) = local_30;
                                                    if ((capwap_debug_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf(
                                                  "[CW_DEBUG]%32s():%4d init dtls config.\n",
                                                  "cw_ac_data_network_init",0x355);
                                                  }
                                                  iVar5 = capwap_dtls_cfg_init
                                                                    (1,l_profile + 0xb,
                                                                     l_profile + 0x2b);
                                                  *(int *)(iVar4 + 0x28) = iVar5;
                                                  if (iVar5 == 0) {
                                                    if ((capwap_err_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d init dtls config failed.\n";
                                                  uVar8 = 0x359;
                                                  goto LAB_0058f050;
                                                  }
                                                  }
                                                  else {
                                                    if ((capwap_debug_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf(
                                                  "[CW_DEBUG]%32s():%4d init capwap packet queue\n",
                                                  "cw_ac_data_network_init",0x35c);
                                                  }
                                                  *(undefined4 *)(iVar4 + 0x24) = l_profile[3];
                                                  snprintf(acStack_50,0x1e,"%s%d",
                                                           "capwap_packet_queue_",
                                                           *(undefined4 *)(iVar4 + 4));
                                                  iVar5 = cw_packet_queue_create
                                                                    (*(undefined4 *)(iVar4 + 0x24),
                                                                     *(undefined4 *)(iVar4 + 0x18),
                                                                     *(undefined4 *)(iVar4 + 0x1c),
                                                                     acStack_50);
                                                  *(int *)(iVar4 + 0x20) = iVar5;
                                                  if (iVar5 != 0) {
                                                    if ((capwap_debug_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      printf("[CW_DEBUG]%32s():%4d init timer.\n",
                                                             "cw_ac_data_init",0x3de);
                                                    }
                                                    iVar5 = cw_timer_create(l_profile[5],
                                                                            l_profile[6],
                                                                            l_profile[7]);
                                                    *(int *)(iVar4 + 0x44) = iVar5;
                                                    if (iVar5 == 0) {
                                                      iVar5 = 0;
                                                      if ((capwap_err_switch != 0) &&
                                                         (iVar6 = is_target_debug_ap(), iVar6 != 0))
                                                      {
                                                        pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d Failed to init AC Timer.\n";
                                                  uVar8 = 0x3e2;
                                                  goto LAB_0058eb10;
                                                  }
                                                  goto LAB_0058e930;
                                                  }
                                                  if ((capwap_debug_switch != 0) &&
                                                     (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                    printf(
                                                  "[CW_DEBUG]%32s():%4d ac_data[%p] allocated.\n",
                                                  "cw_ac_data_init",0x3e6,iVar4);
                                                  }
                                                  goto LAB_0058e844;
                                                  }
                                                  if ((capwap_err_switch != 0) &&
                                                     (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                    pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d packet queue init failed.\n"
                                                  ;
                                                  uVar8 = 0x363;
                                                  goto LAB_0058f050;
                                                  }
                                                  }
                                                  }
                                                  else if ((capwap_err_switch != 0) &&
                                                          (iVar5 = is_target_debug_ap(), iVar5 != 0)
                                                          ) {
                                                    pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d packet queue pipe create failed.\n"
                                                  ;
                                                  uVar8 = 0x34c;
LAB_0058f050:
                                                  printf(pcVar7,"cw_ac_data_network_init",uVar8);
                                                  }
                                                  iVar5 = -1;
                                                  if ((capwap_err_switch != 0) &&
                                                     (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                                                    uVar8 = 0x3d9;
                                                    pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d Failed to init ac_data\'s network.\n"
                                                  ;
                                                  goto LAB_0058eb10;
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    if ((capwap_err_switch != 0) &&
                                                       (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                                                      pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d create manager pipe failed.\n"
                                                  ;
                                                  uVar8 = 0x37c;
LAB_0058ec3c:
                                                  printf(pcVar7,"cw_ac_data_manager_init",uVar8);
                                                  }
LAB_0058e924:
                                                  iVar5 = -1;
                                                  if ((capwap_err_switch != 0) &&
                                                     (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                                                    pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d Failed to init manager.\n";
                                                  uVar8 = 0x3c7;
                                                  goto LAB_0058eb10;
                                                  }
                                                  }
                                                  }
LAB_0058e930:
                                                  cw_ac_data_destroy(iVar4);
                                                  } while (iVar5 == 0);
                                                  if ((capwap_err_switch != 0) &&
                                                     (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                    printf(
                                                  "[CW_ERROR]%32s():%4d init ac_data[%d] failed\n",
                                                  "cw_ac_data_array_init",0x415,uVar10);
                                                  }
                                                  }
LAB_0058e978:
                                                  piVar1 = (int *)((int)ac + 0x1c);
                                                  *(undefined4 *)((int)ac + 0x18) = 0;
                                                  if (*piVar1 != 0) {
                                                    cw_ac_data_destroy();
                                                    *(undefined4 *)((int)ac + 0x1c) = 0;
                                                  }
                                                  if (*(int *)((int)ac + 0x20) != 0) {
                                                    FUN_00407df0();
                                                    *(undefined4 *)((int)ac + 0x20) = 0;
                                                  }
                                                  }
                                                  if ((capwap_err_switch == 0) ||
                                                     (iVar4 = is_target_debug_ap(), iVar4 == 0))
                                                  goto LAB_0058dfdc;
                                                  pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d failed to init ac-data array.\n"
                                                  ;
                                                  uVar8 = 0xad8;
                                                  goto LAB_0058e158;
                                                  }
                                                  if ((capwap_err_switch != 0) &&
                                                     (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                    pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d init socket failed.\n";
                                                  uVar8 = 0x47e;
                                                  goto LAB_0058e214;
                                                  }
                                                  }
                                                  else {
                                                    capwap_socket_destroy
                                                              (*(undefined4 *)((int)ac + 0x10));
                                                    if ((capwap_err_switch != 0) &&
                                                       (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                      pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d socket send buffer size set failed.\n"
                                                  ;
                                                  uVar8 = 0x478;
                                                  goto LAB_0058e214;
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    capwap_socket_destroy
                                                              (*(undefined4 *)((int)ac + 0x10));
                                                    if ((capwap_err_switch != 0) &&
                                                       (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                      pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d socket receive buffer size set failed.\n"
                                                  ;
                                                  uVar8 = 0x471;
                                                  goto LAB_0058e214;
                                                  }
                                                  }
                                                  }
                                                  else if ((capwap_err_switch != 0) &&
                                                          (iVar4 = is_target_debug_ap(), iVar4 != 0)
                                                          ) {
                                                    pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d init socket failed.\n";
                                                  uVar8 = 0x46a;
                                                  goto LAB_0058e214;
                                                  }
                                                }
                                                else {
                                                  capwap_socket_destroy
                                                            (*(undefined4 *)((int)ac + 0xc));
                                                  if ((capwap_err_switch != 0) &&
                                                     (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                    pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d socket send buffer size set failed.\n"
                                                  ;
                                                  uVar8 = 0x461;
                                                  goto LAB_0058e214;
                                                  }
                                                }
                                              }
                                              else {
                                                capwap_socket_destroy
                                                          (*(undefined4 *)((int)ac + 0xc));
                                                if ((capwap_err_switch != 0) &&
                                                   (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                  pcVar7 = 
                                                  "[CW_ERROR]%32s():%4d socket receive buffer size set failed.\n"
                                                  ;
                                                  uVar8 = 0x45a;
                                                  goto LAB_0058e214;
                                                }
                                              }
                                            }
                                            else if ((capwap_err_switch != 0) &&
                                                    (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                              pcVar7 = "[CW_ERROR]%32s():%4d init socket failed.\n";
                                              uVar8 = 0x453;
LAB_0058e214:
                                              printf(pcVar7,"cw_ac_network_init",uVar8);
                                            }
                                          }
                                          if ((capwap_err_switch == 0) ||
                                             (iVar4 = is_target_debug_ap(), iVar4 == 0))
                                          goto LAB_0058dfdc;
                                          pcVar7 = 
                                          "[CW_ERROR]%32s():%4d failed to init ac network.\n";
                                          uVar8 = 0xacf;
                                          goto LAB_0058e158;
                                        }
                                        if ((capwap_err_switch != 0) &&
                                           (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                          uVar8 = 0x132;
                                          goto LAB_0058e270;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    FUN_00407df0(l_profile);
    l_profile = (undefined4 *)0x0;
  }
  if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0058dfdc;
  pcVar7 = "[CW_ERROR]%32s():%4d read profile failed.\n";
  uVar8 = 0xaa8;
LAB_0058e158:
  printf(pcVar7,"cw_ac_init",uVar8);
LAB_0058dfdc:
  if (ac != (void *)0x0) {
    cw_ac_destroy();
    ac = (void *)0x0;
  }
  return 0xffffffff;
LAB_0058ee00:
  for (; uVar9 < (uint)l_profile[10]; uVar9 = uVar9 + 1) {
    FUN_0051ad88(*(int *)((int)ac + 0x1c) + uVar9 * 0xa0 + 0x94);
  }
  iVar4 = ac_session_global_init();
  if (iVar4 == 0) {
    iVar4 = msg_ele_test_init();
    if (iVar4 == 0) {
      if ((capwap_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_DEBUG]%32s():%4d ac[%p] allocated.\n","cw_ac_init",0xae9,ac);
      }
      udbg_help_register("protocol","protocol_debug_help()");
      iVar4 = write_snapshot_thread_data_init();
      if (iVar4 == 0) {
        return 0;
      }
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0058dfdc;
      pcVar7 = "[CW_ERROR]%32s():%4d failed to init write snapshot thread data.\n";
      uVar8 = 0xaf1;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0058dfdc;
      pcVar7 = "[CW_ERROR]%32s():%4d failed to init msg ele test.\n";
      uVar8 = 0xae5;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0058dfdc;
    pcVar7 = "[CW_ERROR]%32s():%4d failed to init session global configure.\n";
    uVar8 = 0xade;
  }
  goto LAB_0058e158;
}

