// func rdmngr_wtp_pkt_send @ 006165c8 size=1208

undefined4 rdmngr_wtp_pkt_send(undefined2 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_2f8;
  undefined4 local_2f4;
  int local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [12];
  int local_2dc;
  
  memset(auStack_2e8,0,0x2d8);
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar6 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[RDMNGR_ERROR]%s()/%d inputs error.\n";
    uVar5 = 0x5e7;
LAB_0061668c:
    printf(pcVar3,"rdmngr_wtp_pkt_send",uVar5);
    return uVar6;
  }
  uVar6 = 0xffffffff;
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == -1) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id() failed.\n";
    uVar5 = 0x5ed;
    goto LAB_0061668c;
  }
  if (local_2dc == 0) {
    uVar6 = 0;
    if (rdmngr_debug_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar3 = "[RDMNGR_DEBUG]%s()/%d template do not need to send pkt.\n";
    uVar5 = 0x5f3;
    goto LAB_0061668c;
  }
  iVar1 = serv_wtp_address_arg_init(&local_2f8);
  if (iVar1 == -1) {
    uVar6 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[RDMNGR_ERROR]%s()/%d init serv argv failed.\n";
    uVar5 = 0x5fa;
    goto LAB_0061668c;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_2f8,1,1,0x15f0000,0);
  if (iVar1 == -1) {
    if ((rdmngr_err_switch == 0) || (iVar1 = is_target_debug_ap(&local_2f8), iVar1 == 0))
    goto LAB_00616808;
    pcVar3 = "[RDMNGR_ERROR]%s()/%d get serv argv failed.\n";
    uVar6 = 0x600;
  }
  else {
    if (local_2f0 == 0) {
      if ((rdmngr_debug_switch == 0) || (iVar1 = is_target_debug_ap(&local_2f8), iVar1 == 0))
      goto LAB_0061677c;
      pcVar3 = "[RDMNGR_DEBUG]%s()/%d no wtp need send rdmngr pakcet.\n";
      pcVar4 = "rdmngr_wtp_pkt_send";
      uVar6 = 0x607;
LAB_006167b0:
      printf(pcVar3,pcVar4,uVar6);
LAB_0061677c:
      serv_wtp_address_arg_destroy(&local_2f8);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 == 0) {
      if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d cw_pkt_buf_create() failed.\n","rdmngr_packet_send",0x5ac);
      }
    }
    else {
      iVar2 = rdmngr_db_init_all_radio_op(param_2);
      if (iVar2 == -1) {
        if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar3 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_init_all_radio_op() failed.\n";
          uVar6 = 0x5b2;
LAB_0061685c:
          printf(pcVar3,"rdmngr_packet_send",uVar6);
        }
      }
      else {
        iVar2 = rdmngr_packet_create(param_2 + 1,param_2 + 0x13,iVar1);
        if (iVar2 == 0) {
          if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(&local_2f8), iVar2 != 0)) {
            printf("[RDMNGR_DEBUG]%s()/%d send configure to ap, pkt_buf->len:%d\n",
                   "rdmngr_packet_send",0x5bd,(uint)*(ushort *)(iVar1 + 4));
          }
          iVar2 = serv_packet_send(&local_2f8,iVar1,1);
          if (iVar2 == 0) {
            iVar2 = rdmngr_db_update_radio_op(*param_2,*(undefined1 *)((int)param_2 + 0x4e));
            if (iVar2 == 0) {
              if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[RDMNGR_DEBUG]%s()/%d serv_packet_send() done.\n","rdmngr_packet_send",0x5cb
                      );
              }
              cw_pkt_buf_destroy(iVar1);
              if ((rdmngr_debug_switch == 0) || (iVar1 = is_target_debug_ap(&local_2f8), iVar1 == 0)
                 ) goto LAB_0061677c;
              pcVar3 = "[RDMNGR_DEBUG]%s()/%d cw_pkt_buf_destroy() done.\n";
              pcVar4 = "rdmngr_packet_send";
              uVar6 = 0x5cf;
              goto LAB_006167b0;
            }
            if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_update_radio_op() failed, rdState is %d.\n",
                     "rdmngr_packet_send",0x5c7,(uint)*(byte *)((int)param_2 + 0x4e));
            }
          }
          else if ((rdmngr_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            pcVar3 = "[RDMNGR_WARNING]%s()/%d serv_packet_send() failed.\n";
            uVar6 = 0x5c1;
            goto LAB_0061685c;
          }
        }
        else if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar3 = "[RDMNGR_ERROR]%s()/%d rdmngr_packet_create() failed.\n";
          uVar6 = 0x5b9;
          goto LAB_0061685c;
        }
      }
      cw_pkt_buf_destroy(iVar1);
    }
    if ((rdmngr_warning_switch == 0) || (iVar1 = is_target_debug_ap(&local_2f8), iVar1 == 0))
    goto LAB_00616808;
    pcVar3 = "[RDMNGR_WARNING]%s()/%d rdmngr_packet_send() failed.\n";
    uVar6 = 0x60f;
  }
  printf(pcVar3,"rdmngr_wtp_pkt_send",uVar6);
LAB_00616808:
  serv_wtp_address_arg_destroy(&local_2f8);
  return 0xffffffff;
}

