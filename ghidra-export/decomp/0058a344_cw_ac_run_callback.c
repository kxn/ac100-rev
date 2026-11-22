// func cw_ac_run_callback @ 0058a344 size=1532

void cw_ac_run_callback(void)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  uint *__buf;
  short sVar5;
  uint uVar4;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  uint *puVar11;
  int iVar12;
  timeval local_b0;
  fd_set local_a8;
  
  iVar12 = 0;
  if (ac == (int *)0x0) {
    pcVar10 = "[ASSERT]%32s():%4d assert(%s) failed\n";
    uVar9 = 0x9ea;
    piVar3 = (int *)0x6aa958;
  }
  else {
    while (piVar3 = ac, *ac != 0) {
      local_b0.tv_usec = 0;
      local_b0.tv_sec = 5;
      iVar2 = 0;
      do {
        puVar8 = (undefined4 *)((int)local_a8.fds_bits + iVar2);
        iVar2 = iVar2 + 4;
        *puVar8 = 0;
      } while (iVar2 != 0x80);
      uVar6 = (uint)ac[3] >> 5;
      local_a8.fds_bits[uVar6] = local_a8.fds_bits[uVar6] | 1 << (ac[3] & 0x1fU);
      iVar7 = ac[3];
      uVar6 = (uint)ac[4] >> 5;
      local_a8.fds_bits[uVar6] = local_a8.fds_bits[uVar6] | 1 << (ac[4] & 0x1fU);
      uVar6 = (uint)ac[5] >> 5;
      local_a8.fds_bits[uVar6] = local_a8.fds_bits[uVar6] | 1 << (ac[5] & 0x1fU);
      iVar2 = ac[4];
      if (ac[4] < iVar7) {
        iVar2 = iVar7;
      }
      if (iVar2 < ac[5]) {
        iVar2 = ac[5];
      }
      if (iVar12 < iVar2) {
        iVar12 = iVar2;
      }
      iVar2 = select(iVar12 + 1,&local_a8,(fd_set *)0x0,(fd_set *)0x0,&local_b0);
      if (iVar2 != 0) {
        if (iVar2 < 1) {
          if ((capwap_err_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
            piVar3 = __errno_location();
            printf("[CW_ERROR]%32s():%4d select failed, ret=%d, errno=%d.\n","cw_ac_run_callback",
                   0xa2c,iVar2,*piVar3);
          }
        }
        else {
          uVar9 = 0;
          if ((((uint)local_a8.fds_bits[(uint)ac[3] >> 5] >> (ac[3] & 0x1fU) & 1) == 0) &&
             (uVar9 = 1, ((uint)local_a8.fds_bits[(uint)ac[4] >> 5] >> (ac[4] & 0x1fU) & 1) == 0)) {
            if (((uint)local_a8.fds_bits[(uint)ac[5] >> 5] >> (ac[5] & 0x1fU) & 1) == 0) {
              if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[CW_ERROR]%32s():%4d unknown fd selected, should never happen!\n",
                       "cw_ac_run_callback",0xa26);
              }
            }
            else {
              __buf = (uint *)FUN_00408450(0x10000,0x992);
              if (__buf != (uint *)0x0) {
                uVar6 = recv(ac[5],__buf,0x10000,0);
                if (0 < (int)uVar6) {
                  puVar11 = __buf;
                  if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    printf("[CW_DEBUG]%32s():%4d =====>Receive Netlink message, len=%d.\n",
                           "cw_ac_netlink_event_process",0x99e,uVar6);
                  }
                  do {
                    if (((((int)uVar6 < 0x10) || (*puVar11 < 0x10)) || (uVar6 < *puVar11)) ||
                       (uVar1 = *(ushort *)(puVar11 + 1), uVar1 == 3)) goto LAB_0058a7bc;
                    if (capwap_debug_switch == 0) {
                      sVar5 = *(short *)(puVar11 + 1);
                    }
                    else {
                      iVar2 = is_target_debug_ap();
                      if (iVar2 == 0) {
                        sVar5 = *(short *)(puVar11 + 1);
                      }
                      else {
                        printf("[CW_DEBUG]%32s():%4d msgtype: %d\n","cw_ac_netlink_event_process",
                               0x9a3,(uint)uVar1);
                        sVar5 = *(short *)(puVar11 + 1);
                      }
                    }
                    if (sVar5 == 0x14) {
                      if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0))
                      {
                        printf("[CW_DEBUG]%32s():%4d msgtype: RTM_NEWADDR\n",
                               "cw_ac_netlink_event_process",0x9a6);
                      }
                      uVar9 = 1;
LAB_0058a6d0:
                      cw_ac_handle_addrchange(puVar11,uVar9);
                      uVar4 = *puVar11;
                    }
                    else {
                      if (sVar5 == 0x15) {
                        if ((capwap_debug_switch == 0) ||
                           (iVar2 = is_target_debug_ap(puVar11), iVar2 == 0)) {
                          uVar9 = 0;
                        }
                        else {
                          printf("[CW_DEBUG]%32s():%4d msgtype: RTM_DELADDR\n",
                                 "cw_ac_netlink_event_process",0x9ab);
                          uVar9 = 0;
                        }
                        goto LAB_0058a6d0;
                      }
                      if (sVar5 == 0x10) {
                        if (capwap_debug_switch == 0) {
                          uVar4 = *puVar11;
                        }
                        else {
                          iVar2 = is_target_debug_ap();
                          if (iVar2 == 0) {
                            uVar4 = *puVar11;
                          }
                          else {
                            uVar9 = 0x9b0;
                            pcVar10 = "[CW_DEBUG]%32s():%4d msgtype: RTM_NEWLINK\n";
LAB_0058a744:
                            printf(pcVar10,"cw_ac_netlink_event_process",uVar9);
                            uVar4 = *puVar11;
                          }
                        }
                      }
                      else {
                        if (sVar5 == 0x11) {
                          if (capwap_debug_switch == 0) {
                            uVar4 = *puVar11;
                          }
                          else {
                            iVar2 = is_target_debug_ap();
                            if (iVar2 == 0) {
                              uVar4 = *puVar11;
                            }
                            else {
                              printf("[CW_DEBUG]%32s():%4d msgtype: RTM_DELLINK\n",
                                     "cw_ac_netlink_event_process",0x9b4);
                              uVar4 = *puVar11;
                            }
                          }
                          if (uVar4 - 0x10 < 0x10) {
                            if ((capwap_debug_switch == 0) ||
                               (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0058a7bc;
                            pcVar10 = 
                            "[CW_DEBUG]%32s():%4d RTM_NEWLINK message too short, just return.\n";
                            uVar9 = 0x9ba;
                          }
                          else {
                            if ((puVar11[6] & 8) == 0) {
                              capwap_ipv6_socket_join_or_leave_group(ac[4],puVar11[5],0);
                              uVar4 = *puVar11;
                              goto LAB_0058a644;
                            }
                            if ((capwap_debug_switch == 0) ||
                               (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0058a7bc;
                            uVar9 = 0x9c1;
                            pcVar10 = 
                            "[CW_DEBUG]%32s():%4d Got message of loopback interface, just return.\n"
                            ;
                          }
                          printf(pcVar10,"cw_ac_netlink_event_process",uVar9);
                          goto LAB_0058a7bc;
                        }
                        if (capwap_debug_switch == 0) {
                          uVar4 = *puVar11;
                        }
                        else {
                          iVar2 = is_target_debug_ap();
                          if (iVar2 != 0) {
                            uVar9 = 0x9c8;
                            pcVar10 = "[CW_DEBUG]%32s():%4d msgtype: UNKOWN\n";
                            goto LAB_0058a744;
                          }
                          uVar4 = *puVar11;
                        }
                      }
                    }
LAB_0058a644:
                    uVar4 = uVar4 + 3 & 0xfffffffc;
                    uVar6 = uVar6 - uVar4;
                    puVar11 = (uint *)((int)puVar11 + uVar4);
                  } while( true );
                }
                if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[CW_ERROR]%32s():%4d Receive Invalid message, len=%d, just ignore!\n",
                         "cw_ac_netlink_event_process",0x99a,uVar6);
                }
LAB_0058a7bc:
                FUN_00407df0(__buf);
              }
            }
          }
          else {
            cw_ac_network_process(uVar9);
          }
        }
      }
    }
    if (capwap_debug_switch == 0) {
      return;
    }
    iVar12 = is_target_debug_ap();
    if (iVar12 == 0) {
      return;
    }
    pcVar10 = "[CW_DEBUG]%32s():%4d ac[%p] exit run\n";
    uVar9 = 0xa31;
  }
  printf(pcVar10,"cw_ac_run_callback",uVar9,piVar3);
  return;
}

