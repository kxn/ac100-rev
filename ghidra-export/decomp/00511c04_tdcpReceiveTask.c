// func tdcpReceiveTask @ 00511c04 size=936

void tdcpReceiveTask(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  char *pcVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  char *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  FUN_0051ad88(&local_34);
  do {
    FUN_004082d0(tdcp_from_ap_mutex,0xffffffff);
    while (iVar2 = FUN_004081b0(&g_tdcp_from_ap_list), iVar2 == 0) {
      FUN_004086c0(tdcp_from_ap_cond,tdcp_from_ap_mutex,0xffffffff);
    }
    FUN_004082c0(&local_34,&g_tdcp_from_ap_list);
    FUN_00407f30(tdcp_from_ap_mutex);
    while (iVar2 = FUN_004081b0(&local_34), iVar2 != 0) {
      FUN_00408500(iVar2);
      if (tdcp_debug_switch == 0) {
        iVar3 = *(int *)(iVar2 + 0x14);
      }
      else {
        printf("[TDCP_DEBUG]%s()/%d enter handle_tdcp_from_ap_node\n","handle_tdcp_from_ap_node",
               0x33e);
        iVar3 = *(int *)(iVar2 + 0x14);
      }
      local_38 = 0;
      local_3c = 0;
      local_40 = (char *)0x0;
      if (iVar3 == 0) {
        FUN_004082d0(tdcp_waiting_response_mutex,0xffffffff);
        for (iVar3 = FUN_004081b0(&g_tdcp_waitting_response_list); iVar3 != 0;
            iVar3 = FUN_00408680(iVar3)) {
          if (*(int *)(iVar3 + 0xc) == *(int *)(iVar2 + 0xc)) {
            if (tdcp_debug_switch != 0) {
              printf("[TDCP_DEBUG]%s()/%d find waiting node,handle...\n","handle_tdcp_from_ap_node",
                     0x36e);
            }
            iVar6 = 0;
            piVar7 = &DAT_00731bb0;
            goto LAB_00511e3c;
          }
        }
LAB_00511da4:
        FUN_00407f30(tdcp_waiting_response_mutex);
      }
      else {
        iVar3 = pre_handle_tdcp_request(iVar2 + 0x38,&local_3c,&local_40,&local_38);
        if (iVar3 == 0) {
          iVar3 = 0;
          piVar7 = &DAT_00731bb0;
          while (iVar6 = *piVar7, iVar6 != -1) {
            piVar7 = piVar7 + 0x15;
            iVar4 = strcmp(local_40,s_notify_proxy_url_info_00731b84 + iVar3 * 0x54);
            if (iVar4 == 0) {
              if (iVar6 == 0) {
                if ((code *)(&PTR__notify_proxy_url_info_parse_00731ba4)[iVar3 * 0x15] !=
                    (code *)0x0) {
                  (*(code *)(&PTR__notify_proxy_url_info_parse_00731ba4)[iVar3 * 0x15])
                            (local_3c,*(undefined1 *)(iVar2 + 0x13),*(undefined2 *)(iVar2 + 0x1038),
                             local_38);
                }
              }
              else {
                iVar3 = *(int *)(iVar2 + 0x10);
                uVar8 = *(undefined4 *)(iVar2 + 0xc);
                uVar1 = *(undefined2 *)(iVar2 + 0x1038);
                if (tdcp_debug_switch != 0) {
                  printf("[TDCP_DEBUG]%s()/%d enter tdcp_request_parsed_by_luci \n",
                         "tdcp_request_parsed_by_luci",0x2cb);
                }
                iVar6 = tdcpRequest(iVar2 + 0x38);
                if (iVar6 == 0) {
                  if (tdcp_err_switch != 0) {
                    __format = "[TDCP_ERROR]%s()/%d the resp is NULL\n";
                    uVar8 = 0x2d3;
                    pcVar5 = "tdcp_request_parsed_by_luci";
                    goto LAB_00511de8;
                  }
                }
                else {
                  if (tdcp_debug_switch != 0) {
                    printf("[TDCP_DEBUG]%s()/%d the response is %s\n","tdcp_request_parsed_by_luci",
                           0x2d7,iVar6);
                  }
                  if (((iVar3 != 0) &&
                      (iVar3 = tdcp_send_response_to_ap(uVar8,iVar6,uVar1), iVar3 != 0)) &&
                     (tdcp_err_switch != 0)) {
                    printf("[TDCP_ERROR]%s()/%d tdcp_send_to_ap_by_id failed!\n",
                           "tdcp_request_parsed_by_luci",0x2db);
                  }
                  FUN_00407df0(iVar6);
                }
              }
              break;
            }
            iVar3 = iVar3 + 1;
          }
        }
        else if (tdcp_err_switch != 0) {
          uVar8 = 0x34b;
          __format = "[TDCP_ERROR]%s()/%d pre_handle_tdcp_request failed!\n";
          pcVar5 = "handle_tdcp_from_ap_node";
LAB_00511de8:
          printf(__format,pcVar5,uVar8);
        }
      }
      FUN_00407df0(iVar2);
    }
  } while( true );
LAB_00511e3c:
  if (*piVar7 == -1) goto LAB_00511da4;
  piVar7 = piVar7 + 0x15;
  iVar4 = strcmp((char *)(iVar3 + 0x14),s_notify_proxy_url_info_00731b84 + iVar6 * 0x54);
  if (iVar4 == 0) {
    if ((code *)(&DAT_00731ba8)[iVar6 * 0x15] != (code *)0x0) {
      (*(code *)(&DAT_00731ba8)[iVar6 * 0x15])(iVar2 + 0x38,*(undefined4 *)(iVar3 + 0x34));
    }
    goto LAB_00511da4;
  }
  iVar6 = iVar6 + 1;
  goto LAB_00511e3c;
}

