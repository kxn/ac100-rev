// func rdmngr_working_channel_send_by_ap_id @ 00613fe8 size=968

undefined4 rdmngr_working_channel_send_by_ap_id(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_58);
  if (iVar1 == -1) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[RDMNGR_ERROR]%s()/%d init serv argv failed.\n","rdmngr_working_channel_send_by_ap_id",
           0x8d1);
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_58,1,1,0x15f0000,1,0x19);
  if (iVar1 == -1) {
    iVar1 = 0;
    if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d get serv argv failed.\n","rdmngr_working_channel_send_by_ap_id",
             0x8d7);
    }
  }
  else {
    if (local_50 == 0) {
      if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(&local_58), iVar1 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d no wtp need send rdmngr pakcet.\n",
               "rdmngr_working_channel_send_by_ap_id",0x8de);
      }
      serv_wtp_address_arg_destroy(&local_58);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 == 0) {
        uVar5 = 0xffffffff;
        if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_0061411c;
        __format = "[RDMNGR_ERROR]%s()/%d no memory\n";
        uVar4 = 0x8ed;
      }
      else {
        FUN_0051ad88(&local_40);
        FUN_004082d0(l_working_channel_mutex,0xffffffff);
        memcpy(&local_34,&rdmngr_working_channel_set,0x18);
        FUN_00407f30(l_working_channel_mutex);
        iVar3 = cw_service_msg_add(iVar2,0x25,&local_48,1,0x66,&local_34);
        if (iVar3 == 0) {
          rdmngr_pkt_dump(iVar2);
          iVar3 = capwap_packet_assemble(iVar1,iVar2);
          if (iVar3 == 0) {
            iVar3 = serv_packet_send(&local_58,iVar1,0);
            if (iVar3 == 0) {
              uVar5 = 0;
              if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                printf("[RDMNGR_DEBUG]%s()/%d pkt_buf is null : %s\n",
                       "rdmngr_working_channel_send_by_ap_id",0x90e,&DAT_00691368);
              }
              goto LAB_0061411c;
            }
            uVar5 = 0xffffffff;
            if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_0061411c;
            __format = "[RDMNGR_ERROR]%s()/%d serv_packet_send() failed.\n";
            uVar4 = 0x909;
          }
          else {
            uVar5 = 0xffffffff;
            if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_0061411c;
            __format = "[RDMNGR_ERROR]%s()/%d rdmngr capwap_packet_assemble() failed.\n";
            uVar4 = 0x904;
          }
        }
        else {
          uVar5 = 0xffffffff;
          if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_0061411c;
          __format = "[RDMNGR_ERROR]%s()/%d vendor specific payload cw_service_msg_add() failed.\n";
          uVar4 = 0x8fc;
        }
      }
      uVar5 = 0xffffffff;
      printf(__format,"rdmngr_working_channel_send_by_ap_id",uVar4);
      goto LAB_0061411c;
    }
    iVar2 = 0;
    if (rdmngr_err_switch != 0) {
      iVar3 = is_target_debug_ap();
      uVar5 = 0xffffffff;
      if (iVar3 == 0) goto LAB_0061411c;
      printf("[RDMNGR_ERROR]%s()/%d cw_pkt_buf_create() failed.\n",
             "rdmngr_working_channel_send_by_ap_id",0x8e7);
    }
  }
  iVar2 = 0;
  uVar5 = 0xffffffff;
LAB_0061411c:
  serv_wtp_address_arg_destroy(&local_58);
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  return uVar5;
}

