// func apmngr_pkt_telnet_config_pkt_send @ 0055a480 size=964

undefined4 apmngr_pkt_telnet_config_pkt_send(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  uint uVar4;
  undefined4 uVar5;
  int local_320;
  undefined4 local_31c;
  undefined4 local_318;
  undefined4 local_314;
  int local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined1 auStack_2f0 [518];
  undefined1 local_ea;
  
  local_318 = 0;
  local_314 = 0;
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  local_304 = 0;
  local_300 = 0;
  local_2fc = 0;
  local_2f8 = 0;
  local_31c = 0;
  memset(auStack_2f0,0,0x2d8);
  local_320 = 0;
  apmngr_db_telnet_enable_get(&local_320);
  apmngr_db_entry_get_by_id(param_1,auStack_2f0);
  apmngr_db_telnet_port_get((int)&local_31c + 2);
  if (local_320 == 0) {
    uVar4 = local_31c & 0xffff;
    if (apmngr_debug_switch != '\0') {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar4 = local_31c & 0xffff;
      }
      else {
        printf("[APMNGR_DEBUG]%s()/%d telnet general switch is off! send pkt to close.\n",
               "apmngr_pkt_telnet_config_pkt_send",0xa2e);
        uVar4 = local_31c & 0xffff;
      }
    }
    apmngr_telnet_config_send(param_1,0,uVar4);
    return 0;
  }
  local_318 = 0;
  local_314 = 0;
  local_310 = 0;
  local_30c = 0;
  iVar1 = serv_wtp_address_arg_init(&local_318);
  if (iVar1 == 0) {
    iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_318,1,1,0x15f0000,1,0x45);
    if (iVar1 == 0) {
      if (local_310 == 0) {
        if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d AP not support telnet\n","apmngr_pkt_telnet_config_pkt_send"
                 ,0xa41);
        }
        serv_wtp_address_arg_destroy(&local_318);
        return 0;
      }
      iVar1 = cw_pkt_buf_create(0xfa);
      if (iVar1 == 0) goto LAB_0055a75c;
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 == 0) {
joined_r0x0055a800:
        if (iVar1 == 0) goto LAB_0055a75c;
      }
      else {
        FUN_0051ad88(&local_300);
        local_31c = CONCAT13(local_ea,local_31c._1_3_);
        if ((apmngr_debug_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d val.enable=%d, val.telnet_port=%d\n",
                 "apmngr_pkt_telnet_config_pkt_send",0xa54,local_31c >> 0x18,local_31c & 0xffff);
        }
        iVar3 = cw_service_msg_add(iVar2,0x25,&local_308,1,0x9f,&local_31c);
        if (iVar3 == 0) {
          if (apmngr_pkt_switch != '\0') {
            capwap_parsed_packet_dump(iVar2);
          }
          iVar3 = capwap_packet_assemble(iVar1,iVar2);
          if (iVar3 != -1) {
            cw_parsed_pkt_destroy(iVar2);
            iVar2 = serv_packet_send(&local_318,iVar1,1);
            if (iVar2 != -1) {
              cw_pkt_buf_destroy(iVar1);
              serv_wtp_address_arg_destroy(&local_318);
              if (apmngr_debug_switch == '\0') {
                return 0;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 != 0) {
                printf("[APMNGR_DEBUG]%s()/%d send ap telnet configure to AP successfully.\n",
                       "apmngr_pkt_telnet_config_pkt_send",0xa6f);
                return 0;
              }
              return 0;
            }
            if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[APMNGR_ERROR]%s()/%d send packet failed.\n",
                     "apmngr_pkt_telnet_config_pkt_send",0xa67);
            }
            goto joined_r0x0055a800;
          }
        }
        cw_parsed_pkt_destroy(iVar2);
      }
      cw_pkt_buf_destroy(iVar1);
      goto LAB_0055a75c;
    }
    if ((apmngr_err_switch == '\0') || (iVar1 = is_target_debug_ap(&local_318), iVar1 == 0))
    goto LAB_0055a75c;
    __format = "[APMNGR_ERROR]%s()/%d get addr from apmngr failed.\n";
    uVar5 = 0xa3c;
  }
  else {
    if ((apmngr_err_switch == '\0') || (iVar1 = is_target_debug_ap(&local_318), iVar1 == 0))
    goto LAB_0055a75c;
    __format = "[APMNGR_ERROR]%s()/%d init arg failed.\n";
    uVar5 = 0xa36;
  }
  printf(__format,"apmngr_pkt_telnet_config_pkt_send",uVar5);
LAB_0055a75c:
  serv_wtp_address_arg_destroy(&local_318);
  return 0xffffffff;
}

