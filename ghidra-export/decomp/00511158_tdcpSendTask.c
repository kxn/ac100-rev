// func tdcpSendTask @ 00511158 size=600

void tdcpSendTask(void)

{
  int iVar1;
  void *__s;
  int iVar2;
  undefined4 extraout_v1;
  uint uVar3;
  undefined2 uVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  FUN_0051ad88(&local_38);
  do {
    FUN_004082d0(tdcp_to_ap_mutex,0xffffffff);
    while (iVar1 = FUN_004081b0(&g_tdcp_to_ap_list), iVar1 == 0) {
      FUN_004086c0(tdcp_to_ap_cond,tdcp_to_ap_mutex,0xffffffff);
    }
    FUN_004082c0(&local_38,&g_tdcp_to_ap_list);
    FUN_00407f30(tdcp_to_ap_mutex);
    while (iVar1 = FUN_004081b0(&local_38), iVar1 != 0) {
      FUN_00408500(iVar1);
      if (tdcp_debug_switch != 0) {
        printf("[TDCP_DEBUG]%s()/%d enter handle_tdcp_to_ap_node\n","handle_tdcp_to_ap_node",0x316);
      }
      if (tdcp_debug_switch == 0) {
        iVar2 = *(int *)(iVar1 + 0x14);
      }
      else {
        printf("[TDCP_DEBUG]%s()/%d is_reuqest:%d,need_result:%d\n","handle_tdcp_to_ap_node",0x318,
               *(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x10));
        iVar2 = *(int *)(iVar1 + 0x14);
      }
      if (iVar2 == 0) {
        uVar3 = (uint)*(byte *)(iVar1 + 0xf);
LAB_0051124c:
        iVar2 = *(int *)(iVar1 + 0x103c);
LAB_00511250:
        if (iVar2 != 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(undefined2 *)(iVar1 + 0x1038);
        }
        _tdcp_send_pkt_to_ap
                  (*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),iVar1 + 0x38,uVar3,
                   uVar4,iVar2 != 0);
      }
      else {
        uVar3 = 0;
        if (*(int *)(iVar1 + 0x10) == 0) goto LAB_0051124c;
        FUN_004082d0(tdcp_send_request_id_mutex,0xffffffff);
        g_send_tdcp_request_id = g_send_tdcp_request_id + 1;
        if (g_send_tdcp_request_id == 0) {
          g_send_tdcp_request_id = 1;
        }
        uVar3 = (uint)g_send_tdcp_request_id;
        FUN_00407f30(tdcp_send_request_id_mutex);
        __s = (void *)FUN_00408450(0x38,0x31c);
        if (__s != (void *)0x0) {
          memset(__s,0,0x38);
          *(uint *)((int)__s + 0xc) = uVar3;
          FUN_00407e70();
          *(undefined4 *)((int)__s + 0x10) = extraout_v1;
          *(undefined4 *)((int)__s + 0x34) = *(undefined4 *)(iVar1 + 0x1040);
          memcpy((void *)((int)__s + 0x14),(void *)(iVar1 + 0x18),0x20);
          FUN_004082d0(tdcp_waiting_response_mutex,0xffffffff);
          FUN_004086b0(&g_tdcp_waitting_response_list,__s);
          FUN_00407f30(tdcp_waiting_response_mutex);
          iVar2 = *(int *)(iVar1 + 0x103c);
          goto LAB_00511250;
        }
        if (tdcp_err_switch != 0) {
          printf("[TDCP_ERROR]%s()/%d malloc error.\n","handle_tdcp_to_ap_node",0x31e);
        }
      }
      FUN_00407df0(iVar1);
    }
  } while( true );
}

