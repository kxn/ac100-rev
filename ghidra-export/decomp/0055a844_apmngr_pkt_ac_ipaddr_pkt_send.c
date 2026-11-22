// func apmngr_pkt_ac_ipaddr_pkt_send @ 0055a844 size=808

undefined4
apmngr_pkt_ac_ipaddr_pkt_send
          (undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
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
  
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  iVar1 = serv_wtp_address_arg_init(&local_58);
  if (iVar1 == -1) {
    uVar6 = 0xffffffff;
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d init serv argv failed.\n";
    uVar5 = 0xa8c;
LAB_0055a97c:
    printf(__format,"apmngr_pkt_ac_ipaddr_pkt_send",uVar5);
    return uVar6;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_58,1,1,0x15f0000,1,0x22);
  if (iVar1 == -1) {
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(&local_58), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d get addr from apmngr failed.\n","apmngr_pkt_ac_ipaddr_pkt_send",
             0xa91);
    }
    goto LAB_0055aafc;
  }
  if (local_50 == 0) {
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(&local_58), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d AP not support report log\n","apmngr_pkt_ac_ipaddr_pkt_send",
             0xa96);
    }
    serv_wtp_address_arg_destroy(&local_58);
    return 0;
  }
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) goto LAB_0055aafc;
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 == 0) {
LAB_0055ab30:
    if (iVar1 == 0) goto LAB_0055aafc;
  }
  else {
    iVar3 = capwap_socket_ifindex_to_addr(param_2,0,param_4,&local_34,&local_48);
    uVar6 = 0;
    if (iVar3 == 0) {
      uVar6 = local_30;
    }
    _apmngr_local_ipv4_add(iVar2,uVar6);
    iVar3 = capwap_socket_ifindex_to_addr(param_3,1,param_4,&local_34,&local_48);
    puVar4 = &local_30;
    if (iVar3 != 0) {
      puVar4 = &local_68;
    }
    _apmngr_local_ipv6_add(iVar2,puVar4);
    iVar3 = capwap_packet_assemble(iVar1,iVar2);
    if (iVar3 != -1) {
      cw_parsed_pkt_destroy(iVar2);
      iVar2 = serv_packet_send(&local_58,iVar1,1);
      if (iVar2 != -1) {
        cw_pkt_buf_destroy(iVar1);
        uVar6 = 0;
        serv_wtp_address_arg_destroy(&local_58);
        if (apmngr_debug_switch == '\0') {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        __format = "[APMNGR_DEBUG]%s()/%d send ac ip address to AP successfully.\n";
        uVar5 = 0xac9;
        goto LAB_0055a97c;
      }
      if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APMNGR_ERROR]%s()/%d send packet failed.\n","apmngr_pkt_ac_ipaddr_pkt_send",0xac1);
      }
      goto LAB_0055ab30;
    }
    cw_parsed_pkt_destroy(iVar2);
  }
  cw_pkt_buf_destroy(iVar1);
LAB_0055aafc:
  serv_wtp_address_arg_destroy(&local_58);
  return 0xffffffff;
}

