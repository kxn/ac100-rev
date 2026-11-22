// func _radius_thread @ 0044656c size=4348

undefined4 _radius_thread(int *param_1)

{
  char cVar1;
  bool bVar2;
  int __epfd;
  ssize_t sVar3;
  size_t __n;
  int iVar4;
  int extraout_v1;
  int extraout_v1_00;
  char *__format;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  void *pvVar13;
  code *pcVar14;
  undefined8 uVar15;
  int local_a8;
  socklen_t local_a4;
  int local_a0;
  int local_9c;
  epoll_event local_90;
  epoll_event local_80;
  undefined1 auStack_70 [8];
  undefined4 local_68;
  undefined8 local_48;
  int local_40;
  epoll_event *local_3c;
  int *local_38;
  char *local_34;
  int local_30;
  void *local_2c;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar7 = *param_1;
  uac_mem_free_my();
  iVar11 = threads;
  __epfd = epoll_create(0x41);
  iVar11 = iVar11 + iVar7 * 0x30;
  if (__epfd == -1) {
    if (radius_err_switch != 0) {
      uVar6 = 0xa6f;
      pcVar5 = "[RADIUS_ERR]%s()/%d Create epoll error\n";
      goto LAB_004475f8;
    }
  }
  else {
    local_80.data.ptr = (void *)*(undefined4 *)(iVar11 + 4);
    local_80.events = 1;
    iVar7 = epoll_ctl(__epfd,1,*(int *)(iVar11 + 4),&local_80);
    if ((iVar7 < 0) && (radius_err_switch != 0)) {
      printf("[RADIUS_ERR]%s()/%d Add epoll error\n\n","_radius_thread",0xa77);
    }
    local_3c = (epoll_event *)uac_mem_calloc_my(0x41,0x10,0xa7a);
    if (local_3c != (epoll_event *)0x0) {
      do {
        local_30 = epoll_wait(__epfd,local_3c,0x41,1000);
        local_48._0_4_ = local_3c;
        for (local_40 = 0; local_40 < local_30; local_40 = local_40 + 1) {
          if (((local_48._0_4_)->events & 0x19) == 1) {
            piVar10 = (int *)((local_48._0_4_)->data).fd;
            if (*(int **)(iVar11 + 4) == piVar10) {
              _radius_msgq_manage(__epfd,iVar11);
            }
            else if (((local_48._0_4_)->events & 1) != 0) {
              if (piVar10 == (int *)0x0) {
                if (radius_debug_switch != 0) {
                  uVar6 = 0xa9b;
                  pcVar5 = "[RADIUS_DEBUG]%s()/%d No data ptr\n";
                  goto LAB_00446a10;
                }
              }
              else {
                uac_mutex_take(*(undefined4 *)(iVar11 + 0xc),0xffffffff);
                local_38 = piVar10 + 0x16c;
                memset(local_38,0,0x28);
                local_a4 = 0x10;
                sVar3 = recvfrom(piVar10[0x17a],*(void **)(iVar11 + 0x10),0x7fe,0x40,
                                 (sockaddr *)&local_90,&local_a4);
                iVar7 = piVar10[0x17a];
                if (sVar3 < 1) {
                  iVar8 = -1;
                  if (iVar7 == -1) {
LAB_00447108:
                    bVar2 = false;
                    iVar8 = -1;
                  }
                  else {
                    bVar2 = false;
                    close(iVar7);
                    piVar10[0x17a] = -1;
                  }
                }
                else {
                  if (iVar7 != -1) {
                    close(iVar7);
                    piVar10[0x17a] = -1;
                  }
                  pcVar5 = *(char **)(iVar11 + 0x10);
                  if ((sVar3 < 0x14) ||
                     (uVar12 = (uint)*(ushort *)(pcVar5 + 2), sVar3 < (int)uVar12)) {
                    if (radius_debug_switch != 0) {
                      uVar6 = 0x789;
                      pcVar5 = "[RADIUS_DEBUG]%s()/%d Radius length check fail\n";
LAB_004469f0:
                      printf(pcVar5,"_radius_check_receive",uVar6);
                    }
LAB_004468a4:
                    iVar7 = -1;
                    iVar8 = 0;
                  }
                  else {
                    local_2c = (void *)((int)piVar10 + 0x4e6);
                    cVar1 = *(char *)((int)piVar10 + 0x5fb);
                    local_34 = (char *)(*piVar10 + 0xff);
                    __n = strlen(local_34);
                    if (((0xfec < uVar12 - 0x14) || (0x7fe < (int)(uVar12 + __n))) ||
                       (pcVar5[1] != cVar1)) {
LAB_004471f8:
                      if (radius_debug_switch != 0) {
                        uVar6 = 0x791;
                        pcVar5 = "[RADIUS_DEBUG]%s()/%d Radius _radius_check_reply fail\n";
                        goto LAB_004469f0;
                      }
                      goto LAB_004468a4;
                    }
                    memcpy(&local_a0,pcVar5 + 4,0x10);
                    memcpy(pcVar5 + 4,local_2c,0x10);
                    memcpy(pcVar5 + uVar12,local_34,__n);
                    _ac_md5_calc(auStack_70,pcVar5,uVar12 + __n);
                    iVar7 = memcmp(&local_a0,auStack_70,0x10);
                    if (iVar7 != 0) {
                      if (radius_debug_switch != 0) {
                        printf("[RADIUS_DEBUG]%s()/%d _ac_md5_calc check failed\n",
                               "_radius_check_reply",0x2c3);
                      }
                      goto LAB_004471f8;
                    }
                    cVar1 = *pcVar5;
                    iVar7 = 0;
                    if (((cVar1 != '\x02') && (iVar7 = 0, cVar1 != '\b')) && (cVar1 != '\x05')) {
                      if ((cVar1 == '\x03') || (cVar1 == '\t')) {
                        iVar7 = 3;
                        if (radius_debug_switch != 0) {
                          uVar6 = 0x79f;
                          __format = "[RADIUS_DEBUG]%s()/%d Radius response reject\n";
                          goto LAB_00447574;
                        }
                      }
                      else {
                        iVar7 = -1;
                        if (radius_debug_switch != 0) {
                          uVar6 = 0x7a4;
                          __format = "[RADIUS_DEBUG]%s()/%d Radius response error\n";
LAB_00447574:
                          printf(__format,"_radius_check_receive",uVar6);
                        }
                      }
                    }
                    iVar8 = *(ushort *)(pcVar5 + 2) - 0x14;
                    if (radius_info_switch == 0) {
                      if (iVar8 < 1) goto LAB_00447290;
LAB_004472fc:
                      iVar8 = radius_pair_gen2(rh,pcVar5 + 0x14,iVar8);
                      if (iVar8 == 0) goto LAB_00447290;
                      iVar4 = radius_pair_get(iVar8,0x1b,0);
                      if (iVar4 == 0) {
                        piVar10[0x16f] = piVar10[0x176];
                      }
                      else {
                        piVar10[0x16f] = *(int *)(iVar4 + 0x4c);
                        piVar10[0x176] = *(int *)(iVar4 + 0x4c);
                        if (radius_debug_switch != 0) {
                          printf("[RADIUS_DEBUG]%s()/%d Get response session timeout: %u\n",
                                 "_radius_check_receive",0x7b8);
                        }
                      }
                      iVar4 = radius_pair_get(iVar8,0x55,0);
                      if ((iVar4 != 0) &&
                         (piVar10[0x177] = *(int *)(iVar4 + 0x4c), radius_debug_switch != 0)) {
                        printf("[RADIUS_DEBUG]%s()/%d Get response acct update time: %u\n",
                               "_radius_check_receive",0x7c2);
                      }
                      iVar4 = radius_pair_get(iVar8,2,0x2766);
                      if ((iVar4 != 0) &&
                         (piVar10[0x178] = *(int *)(iVar4 + 0x4c), radius_debug_switch != 0)) {
                        printf("[RADIUS_DEBUG]%s()/%d Get natshell input rate: %u\n",
                               "_radius_check_receive",0x7c9);
                      }
                      iVar4 = radius_pair_get(iVar8,1,0x2766);
                      if ((iVar4 != 0) &&
                         (piVar10[0x179] = *(int *)(iVar4 + 0x4c), radius_debug_switch != 0)) {
                        printf("[RADIUS_DEBUG]%s()/%d Get natshell output rate: %u\n",
                               "_radius_check_receive",0x7ce);
                      }
                      iVar4 = radius_pair_get(iVar8,0x65,0);
                      if (iVar4 != 0) {
                        iVar4 = *(int *)(iVar4 + 0x4c);
                        if (radius_debug_switch == 0) {
                          piVar10[0x174] = iVar4;
                        }
                        else {
                          printf("[RADIUS_DEBUG]%s()/%d Get err_cause: %d\n","_radius_check_receive"
                                 ,0x7d4,iVar4);
                          piVar10[0x174] = iVar4;
                        }
                      }
                    }
                    else {
                      printf("[RADIUS_INFO]%s()/%d Receive packet attr len: %d\n",
                             "_radius_check_receive",0x7a8,iVar8);
                      if (0 < iVar8) goto LAB_004472fc;
LAB_00447290:
                      iVar8 = 0;
                      piVar10[0x16f] = piVar10[0x176];
                    }
                    if (*pcVar5 == '\x02') {
                      if (*(int *)(*piVar10 + 0x200) != 0) {
                        local_a8 = -1;
                        *(undefined1 *)((int)piVar10 + 0x62a) = 4;
                        piVar10[0x17b] = 0;
                        piVar10[0x17f] = 1;
                        memset(piVar10 + 0x169,0,8);
                        piVar10[0x17a] = -1;
                        iVar7 = _radius_send_to_server
                                          (0,piVar10,*(undefined4 *)(iVar11 + 0x10),&local_a8);
                        if ((iVar7 == 0) && (local_a8 != -1)) {
                          piVar10[0x17a] = local_a8;
                        }
                        else if (local_a8 != -1) {
                          close(local_a8);
                        }
                        piVar10[0x17d] = iVar7;
                        if (iVar8 != 0) {
                          radius_pair_free(iVar8);
                        }
                        goto LAB_00447108;
                      }
                      iVar4 = piVar10[0x177];
                    }
                    else if (*pcVar5 == '\x05') {
                      iVar4 = *(int *)(*piVar10 + 0x200);
                      if (iVar4 == 0) {
                        iVar4 = piVar10[0x177];
                      }
                      else {
                        piVar10[0x16d] = iVar4;
                        piVar10[0x173] = piVar10[0x15b];
                        piVar10[0x172] = piVar10[0x15a];
                        if ((uint)piVar10[0x177] < 0x3c) {
                          piVar10[0x177] = 0x3c;
                        }
                        if (radius_debug_switch != 0) {
                          printf("[RADIUS_DEBUG]%s()/%d Get account response\n",
                                 "_radius_check_receive",0x808);
                          goto LAB_004472b8;
                        }
                        iVar4 = piVar10[0x177];
                      }
                    }
                    else {
LAB_004472b8:
                      iVar4 = piVar10[0x177];
                    }
                    piVar10[0x170] = iVar4;
                    piVar10[0x16c] = *(int *)(*piVar10 + 0x208);
                  }
                  piVar10[0x16e] = iVar7;
                  if (iVar8 != 0) {
                    radius_pair_free(iVar8);
                  }
                  bVar2 = true;
                  if (iVar7 != 0) {
                    if (radius_debug_switch != 0) {
                      printf("[RADIUS_DEBUG]%s()/%d Radius ret_code is RET_FAIL send result to nginx\n"
                             ,"_radius_check_receive",0x81b);
                    }
                    bVar2 = false;
                    _radius_send_result_to_ngx(piVar10,local_38);
                  }
                  iVar8 = 0;
                }
                if (radius_debug_switch != 0) {
                  printf("[RADIUS_DEBUG]%s()/%d _radius_check_receive ret is %d\n","_radius_thread",
                         0xaab,iVar8);
                }
                if (iVar8 == 0) {
                  g_uac_receive_radius_pkt_ok_count = g_uac_receive_radius_pkt_ok_count + 1;
                  uac_list_remove(piVar10 + 0x15c);
                  if ((bVar2) && (iVar7 = uac_list_size(&g_radius_result_check_list), iVar7 != 0)) {
                    uVar6 = *(undefined4 *)(iVar11 + 0x1c);
                    pcVar14 = uac_list_insert_last;
                  }
                  else {
                    _radius_send_result_to_ngx(piVar10,local_38);
                    uVar6 = *(undefined4 *)(iVar11 + 0x14);
                    pcVar14 = uac_list_insert_first;
                  }
                  (*pcVar14)(uVar6,piVar10 + 0x15c);
                  if (radius_debug_switch != 0) {
                    printf("[RADIUS_DEBUG]%s()/%d entry->sockfd is %d\n","_radius_thread",0xaba,
                           piVar10[0x17a]);
                  }
                  if (piVar10[0x17a] != -1) {
                    close(piVar10[0x17a]);
                    piVar10[0x17a] = -1;
                  }
                }
                else {
                  piVar9 = piVar10 + 0x15c;
                  g_uac_receive_radius_pkt_fail_count = g_uac_receive_radius_pkt_fail_count + 1;
                  uac_list_remove(piVar9);
                  uac_list_insert_last(*(undefined4 *)(iVar11 + 0x18),piVar9);
                  if (piVar10[0x17a] != -1) {
                    local_80._4_4_ = 0;
                    local_80.data.u64._4_4_ = 0;
                    local_80.events = 1;
                    local_80.data._0_4_ = piVar10;
                    iVar7 = epoll_ctl(__epfd,1,piVar10[0x17a],&local_80);
                    if (iVar7 < 0) {
                      if (radius_debug_switch != 0) {
                        printf("[RADIUS_DEBUG]%s()/%d Add epoll error\n\n","_radius_thread",0xad0);
                      }
                      uac_list_remove(piVar9);
                      uac_list_insert_first(*(undefined4 *)(iVar11 + 0x14),piVar9);
                      close(piVar10[0x17a]);
                      piVar10[0x17a] = -1;
                    }
                  }
                }
                uac_mutex_give(*(undefined4 *)(iVar11 + 0xc));
              }
            }
          }
          else if (radius_debug_switch != 0) {
            uVar6 = 0xa8e;
            pcVar5 = "[RADIUS_DEBUG]%s()/%d Epoll error\n";
LAB_00446a10:
            printf(pcVar5,"_radius_thread",uVar6);
          }
          local_48._0_4_ = local_48._0_4_ + 1;
        }
        if (radius_info_switch != 0) {
          printf("[RADIUS_INFO]%s()/%d before _radius_check_timer\n","_radius_thread",0xae1);
        }
        uac_mutex_take(*(undefined4 *)(iVar11 + 0xc),0xffffffff);
        iVar8 = uac_list_first(*(undefined4 *)(iVar11 + 0x18));
        for (iVar7 = 0; (iVar8 != 0 && (iVar7 != 0x20)); iVar7 = iVar7 + 1) {
          pvVar13 = (void *)(iVar8 + -0x570);
          local_40 = uac_list_next(iVar8);
          local_a0 = 0;
          local_a8 = -1;
          local_9c = 0;
          memset(auStack_70,0,0x28);
          uVar15 = uac_time_usecs();
          local_48 = uVar15;
          __udivdi3((int)((ulonglong)uVar15 >> 0x20),(int)uVar15,0,1000000);
          local_a0 = extraout_v1;
          __umoddi3(local_48._0_4_,local_48._4_4_,0,1000000);
          local_9c = extraout_v1_00;
          if ((extraout_v1 < *(int *)(iVar8 + 0x34)) ||
             ((extraout_v1 == *(int *)(iVar8 + 0x34) && (extraout_v1_00 < *(int *)(iVar8 + 0x38)))))
          {
            iVar4 = -1;
            if (radius_debug_switch != 0) {
              uVar6 = 0x6f2;
              pcVar5 = "[RADIUS_DEBUG]%s()/%d time less than expire\n";
LAB_00446d50:
              printf(pcVar5,"_radius_retry",uVar6);
            }
          }
          else {
            if (radius_debug_switch != 0) {
              printf("[RADIUS_DEBUG]%s()/%d entry->sockfd is %d\n","_radius_retry",0x6f6,
                     *(undefined4 *)(iVar8 + 0x78));
            }
            if (*(int *)(iVar8 + 0x78) != -1) {
              close(*(int *)(iVar8 + 0x78));
              *(undefined4 *)(iVar8 + 0x78) = 0xffffffff;
            }
            if (*(char *)(iVar8 + 0xbb) == '\x01') {
              if (*(int *)(iVar8 + 0x8c) == 3) {
                iVar4 = 0;
                if (radius_debug_switch != 0) {
                  uVar6 = 0x6fe;
                  pcVar5 = "[RADIUS_DEBUG]%s()/%d account ok return\n";
                  goto LAB_00446d50;
                }
                goto LAB_00446bdc;
              }
              iVar4 = *(int *)(iVar8 + -0x570);
            }
            else {
              iVar4 = *(int *)(iVar8 + -0x570);
            }
            if (*(int *)(iVar8 + 0x7c) < *(short *)(iVar4 + 0x204) + 1) {
              if (radius_debug_switch == 0) {
                piVar10 = &g_uac_retry_radius_pkt_count;
              }
              else {
                printf("[RADIUS_DEBUG]%s()/%d _radius_send_to_server retry\n","_radius_retry",0x704)
                ;
                piVar10 = &g_uac_retry_radius_pkt_count;
              }
            }
            else {
              if ((iVar4 != iVar8 + -0x56c) || (*(char *)(iVar8 + -0x360) == '\0')) {
                local_68 = 2;
                if (radius_debug_switch != 0) {
                  printf("[RADIUS_DEBUG]%s()/%d timeout _radius_send_result_to_ngx\n",
                         "_radius_retry",0x73d);
                }
                g_uac_timeout_radius_pkt_count = g_uac_timeout_radius_pkt_count + 1;
                iVar4 = 0;
                _radius_send_result_to_ngx(pvVar13,auStack_70);
                goto LAB_00446bdc;
              }
              *(undefined4 *)(iVar8 + 0x7c) = 0;
              *(int *)(iVar8 + -0x570) = iVar8 + -0x360;
              memset((void *)(iVar8 + 0x34),0,8);
              *(undefined4 *)(iVar8 + 0x78) = 0xffffffff;
              *(undefined4 *)(iVar8 + 0x94) = 1;
              if (radius_debug_switch != 0) {
                printf("[RADIUS_DEBUG]%s()/%d _radius_send_to_server use back server retry\n",
                       "_radius_retry",0x729);
              }
              piVar10 = &g_uac_retry_backup_radius_pkt_count;
            }
            *piVar10 = *piVar10 + 1;
            iVar4 = _radius_send_to_server(0,pvVar13,*(undefined4 *)(iVar11 + 0x10),&local_a8);
            if (iVar4 == 0) {
              if (local_a8 != -1) {
                *(int *)(iVar8 + 0x78) = local_a8;
              }
            }
            else if (local_a8 != -1) {
              close(local_a8);
              *(int *)(iVar8 + 0x84) = iVar4;
              iVar4 = -1;
              goto LAB_00446bdc;
            }
            *(int *)(iVar8 + 0x84) = iVar4;
            iVar4 = -1;
          }
LAB_00446bdc:
          if (radius_debug_switch == 0) {
            if (iVar4 == 0) goto LAB_00446ca0;
LAB_00446bf4:
            if (*(int *)(iVar8 + 0x78) != -1) {
              local_90._4_4_ = 0;
              local_90.data.u64._4_4_ = 0;
              local_90.events = 1;
              local_90.data.ptr = pvVar13;
              iVar8 = epoll_ctl(__epfd,1,*(int *)(iVar8 + 0x78),&local_90);
              if ((iVar8 < 0) && (radius_debug_switch != 0)) {
                printf("[RADIUS_DEBUG]%s()/%d Add epoll dup\n\n","_radius_check_timer",0x875);
              }
            }
          }
          else {
            printf("[RADIUS_DEBUG]%s()/%d _radius_retry is %d manage_count is %d\n",
                   "_radius_check_timer",0x863,iVar4,iVar7);
            if (iVar4 != 0) goto LAB_00446bf4;
LAB_00446ca0:
            uac_list_remove(iVar8);
            uac_list_insert_first(*(undefined4 *)(iVar11 + 0x14),iVar8);
            if (*(int *)(iVar8 + 0x78) != -1) {
              close(*(int *)(iVar8 + 0x78));
              *(undefined4 *)(iVar8 + 0x78) = 0xffffffff;
            }
          }
          iVar8 = local_40;
        }
        uac_mutex_give(*(undefined4 *)(iVar11 + 0xc));
        if (radius_info_switch != 0) {
          printf("[RADIUS_INFO]%s()/%d before _radius_result_check_timer\n","_radius_thread",0xae3);
        }
        _radius_result_check_timer(iVar11);
      } while( true );
    }
    local_3c = (epoll_event *)0x0;
    if (radius_err_switch == 0) {
      iVar7 = *(int *)(iVar11 + 0x10);
      goto LAB_00446600;
    }
    uVar6 = 0xa7d;
    pcVar5 = "[RADIUS_ERR]%s()/%d Malloc events error\n\n";
LAB_004475f8:
    printf(pcVar5,"_radius_thread",uVar6);
  }
  iVar7 = *(int *)(iVar11 + 0x10);
LAB_00446600:
  if (iVar7 != 0) {
    uac_mem_free_my();
    *(undefined4 *)(iVar11 + 0x10) = 0;
  }
  iVar7 = *(int *)(iVar11 + 0x14);
  if (iVar7 != 0) {
    while (iVar7 = uac_list_first(iVar7), iVar7 != 0) {
      uac_list_remove(iVar7);
      if (iVar7 != 0x570) {
        uac_mem_free_my();
      }
      iVar7 = *(int *)(iVar11 + 0x14);
    }
  }
  uac_mem_free_my(*(undefined4 *)(iVar11 + 0x14));
  uac_mem_free_my(*(undefined4 *)(iVar11 + 0x18));
  uac_mem_free_my(*(undefined4 *)(iVar11 + 0x1c));
  if (__epfd != -1) {
    close(__epfd);
  }
  return 0;
}

