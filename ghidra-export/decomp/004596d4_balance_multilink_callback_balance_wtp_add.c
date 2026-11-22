// func balance_multilink_callback_balance_wtp_add @ 004596d4 size=716

undefined4 balance_multilink_callback_balance_wtp_add(undefined2 param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 local_308;
  undefined4 local_304;
  int local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined4 local_2e8;
  undefined4 local_2e4;
  undefined1 auStack_2e0 [16];
  undefined2 local_2d0;
  undefined1 auStack_298 [656];
  
  memset(auStack_2e0,0,0x2d8);
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  local_2e8 = 0;
  local_2e4 = 0;
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e0);
  if (iVar1 == -1) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[BALANCE_ERROR](%32s) %05d: get ap entry by id failed.\r\n";
    uVar3 = 0x453;
    goto LAB_0045981c;
  }
  iVar1 = balance_wtp_connect_ac(auStack_298);
  if (iVar1 == -1) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[BALANCE_ERROR](%32s) %05d: add wtp failed.\r\n";
    uVar3 = 0x45a;
    goto LAB_0045981c;
  }
  iVar1 = balance_db_config_get(&local_2f8);
  if (iVar1 == -1) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[BALANCE_ERROR](%32s) %05d: get balance config failed.\r\n";
    uVar3 = 0x461;
    goto LAB_0045981c;
  }
  local_308 = 0;
  local_304 = 0;
  local_300 = 0;
  local_2fc = 0;
  iVar1 = serv_wtp_address_arg_init(&local_308);
  if (iVar1 == -1) {
    if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: init serv argv failed.\r\n","balance_wtp_packt_send",0x1be
            );
    }
  }
  else {
    iVar1 = apmngr_db_get_addr_by_capacity(local_2d0,&local_308,1,1,0x15f0000,0);
    if (iVar1 == -1) {
      if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar2 = "[BALANCE_ERROR](%32s) %05d: get serv argv failed.\r\n";
        uVar3 = 0x1c4;
LAB_0045996c:
        printf(pcVar2,"balance_wtp_packt_send",uVar3);
      }
    }
    else {
      if (local_300 == 0) {
        if ((g_balance_debug != 0) && (iVar1 = is_target_debug_ap(&local_308), iVar1 != 0)) {
          printf("[BALANCE_DEBUG](%32s) %05d: no wtp need send balance pakcet.\r\n",
                 "balance_wtp_packt_send",0x1cb);
        }
LAB_0045989c:
        serv_wtp_address_arg_destroy(&local_308);
        return 0;
      }
      iVar1 = balance_packet_send(&local_308,&local_2f8);
      if (iVar1 != -1) goto LAB_0045989c;
      if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(&local_308), iVar1 != 0)) {
        pcVar2 = "[BALANCE_ERROR](%32s) %05d: init serv argv failed.\r\n";
        uVar3 = 0x1d3;
        goto LAB_0045996c;
      }
    }
    serv_wtp_address_arg_destroy(&local_308);
  }
  if (g_balance_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar2 = "[BALANCE_ERROR](%32s) %05d: add wtp, then send packet failed.\r\n";
  uVar3 = 0x468;
LAB_0045981c:
  printf(pcVar2,"balance_multilink_callback_balance_wtp_add",uVar3);
  return 0xffffffff;
}

