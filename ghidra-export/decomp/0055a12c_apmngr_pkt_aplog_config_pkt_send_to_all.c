// func apmngr_pkt_aplog_config_pkt_send_to_all @ 0055a12c size=852

undefined4 apmngr_pkt_aplog_config_pkt_send_to_all(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
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
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_70 = 0;
  local_74 = 0;
  local_78 = 0;
  local_7c = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_80 = 0x14;
  iVar1 = serv_wtp_address_arg_init(&local_6c);
  if (iVar1 == -1) {
    uVar5 = 0xffffffff;
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d init serv argv failed.\n";
    uVar4 = 0x9d1;
LAB_0055a268:
    printf(__format,"apmngr_pkt_aplog_config_pkt_send_to_all",uVar4);
    return uVar5;
  }
  iVar1 = apmngr_db_get_all_addr_by_capacity(&local_6c,1,1,0x15f0000,1,0x1d);
  if (iVar1 == -1) {
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(&local_6c), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d get addr from apmngr failed.\n",
             "apmngr_pkt_aplog_config_pkt_send_to_all",0x9d6);
    }
    goto LAB_0055a410;
  }
  if (local_64 == 0) {
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(&local_6c), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d AP not support to report log\n",
             "apmngr_pkt_aplog_config_pkt_send_to_all",0x9db);
    }
    serv_wtp_address_arg_destroy(&local_6c);
    return 0;
  }
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) goto LAB_0055a410;
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 == 0) {
LAB_0055a444:
    if (iVar1 == 0) goto LAB_0055a410;
  }
  else {
    FUN_0051ad88(&local_40);
    apmngr_aplog_config_get(&local_70,&local_74,&local_78,&local_7c,&local_5c,&local_80);
    local_30 = CONCAT13(1,local_30._1_3_);
    local_34 = CONCAT31(CONCAT21(CONCAT11((char)local_70,(char)local_74),(char)local_78),
                        (char)local_7c);
    local_1c = local_80;
    cw_common_ip_to_protocol_ip(&local_30,&local_5c);
    iVar3 = cw_service_msg_add(iVar2,0x25,&local_48,1,0x60,&local_34);
    if ((iVar3 == 0) && (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 != -1)) {
      cw_parsed_pkt_destroy(iVar2);
      iVar2 = serv_packet_send(&local_6c,iVar1,1);
      if (iVar2 != -1) {
        cw_pkt_buf_destroy(iVar1);
        uVar5 = 0;
        serv_wtp_address_arg_destroy(&local_6c);
        if (apmngr_debug_switch == '\0') {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        __format = "[APMNGR_DEBUG]%s()/%d send ap log configure to AP successfully.\n";
        uVar4 = 0xa0f;
        goto LAB_0055a268;
      }
      if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APMNGR_ERROR]%s()/%d send packet failed.\n",
               "apmngr_pkt_aplog_config_pkt_send_to_all",0xa07);
      }
      goto LAB_0055a444;
    }
    cw_parsed_pkt_destroy(iVar2);
  }
  cw_pkt_buf_destroy(iVar1);
LAB_0055a410:
  serv_wtp_address_arg_destroy(&local_6c);
  return 0xffffffff;
}

