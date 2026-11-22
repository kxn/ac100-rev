// func rdmngr_working_channel_set_collect @ 00613b28 size=1124

undefined4 rdmngr_working_channel_set_collect(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
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
  
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  FUN_004082d0(l_working_channel_mutex,0xffffffff);
  iVar1 = memcmp(&rdmngr_working_channel_set_last,&rdmngr_working_channel_set,0x18);
  if (iVar1 == 0) {
    if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d channel is same, don\'t send\n",
             "rdmngr_working_channel_set_collect",0x92e);
    }
    FUN_00407f30(l_working_channel_mutex);
    return 0;
  }
  FUN_00407f30(l_working_channel_mutex);
  iVar1 = serv_wtp_address_arg_init(&local_60);
  if (iVar1 == -1) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[RDMNGR_ERROR]%s()/%d init serv argv failed.\n","rdmngr_working_channel_set_collect",
             0x937);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_all_addr_by_capacity(&local_60,1,1,0x15f0000,1,0x19);
  if (iVar1 == -1) {
    iVar1 = 0;
    if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d get serv argv failed.\n","rdmngr_working_channel_set_collect",
             0x93d);
    }
  }
  else {
    if (local_58 == 0) {
      if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d no wtp need send rdmngr pakcet.\n",
               "rdmngr_working_channel_set_collect",0x944);
      }
      serv_wtp_address_arg_destroy(&local_60);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 == 0) {
        uVar5 = 0xffffffff;
        if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_00613d18;
        __format = "[RDMNGR_ERROR]%s()/%d no memory\n";
        uVar4 = 0x953;
      }
      else {
        FUN_0051ad88(&local_48);
        FUN_004082d0(l_working_channel_mutex,0xffffffff);
        memcpy(&local_3c,&rdmngr_working_channel_set,0x18);
        memcpy(&rdmngr_working_channel_set_last,&rdmngr_working_channel_set,0x18);
        FUN_00407f30(l_working_channel_mutex);
        iVar3 = cw_service_msg_add(iVar2,0x25,&local_50,1,0x66,&local_3c);
        if (iVar3 == 0) {
          rdmngr_pkt_dump(iVar2);
          iVar3 = capwap_packet_assemble(iVar1,iVar2);
          if (iVar3 == 0) {
            iVar3 = serv_packet_send(&local_60,iVar1,0);
            if (iVar3 == 0) {
              uVar5 = 0;
              if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                printf("[RDMNGR_DEBUG]%s()/%d pkt_buf is null : %s\n",
                       "rdmngr_working_channel_set_collect",0x974,&DAT_00691368);
              }
              goto LAB_00613d18;
            }
            uVar5 = 0xffffffff;
            if ((rdmngr_warning_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_00613d18;
            __format = "[RDMNGR_WARNING]%s()/%d serv_packet_send() failed.\n";
            uVar4 = 0x96f;
          }
          else {
            uVar5 = 0xffffffff;
            if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_00613d18;
            __format = "[RDMNGR_ERROR]%s()/%d rdmngr capwap_packet_assemble() failed.\n";
            uVar4 = 0x96a;
          }
        }
        else {
          uVar5 = 0xffffffff;
          if ((rdmngr_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_00613d18;
          __format = "[RDMNGR_ERROR]%s()/%d vendor specific payload cw_service_msg_add() failed.\n";
          uVar4 = 0x962;
        }
      }
      uVar5 = 0xffffffff;
      printf(__format,"rdmngr_working_channel_set_collect",uVar4);
      goto LAB_00613d18;
    }
    iVar2 = 0;
    if (rdmngr_err_switch != 0) {
      iVar3 = is_target_debug_ap();
      uVar5 = 0xffffffff;
      if (iVar3 == 0) goto LAB_00613d18;
      printf("[RDMNGR_ERROR]%s()/%d cw_pkt_buf_create() failed.\n",
             "rdmngr_working_channel_set_collect",0x94d);
    }
  }
  iVar2 = 0;
  uVar5 = 0xffffffff;
LAB_00613d18:
  serv_wtp_address_arg_destroy(&local_60);
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  return uVar5;
}

