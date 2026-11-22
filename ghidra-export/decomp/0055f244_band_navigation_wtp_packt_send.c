// func band_navigation_wtp_packt_send @ 0055f244 size=572

undefined4 band_navigation_wtp_packt_send(undefined2 param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_2f0;
  undefined4 local_2ec;
  int local_2e8;
  undefined4 local_2e4;
  undefined1 auStack_2e0 [16];
  undefined2 local_2d0;
  
  local_2f0 = 0;
  local_2ec = 0;
  local_2e8 = 0;
  local_2e4 = 0;
  memset(auStack_2e0,0,0x2d8);
  uVar4 = 0xffffffff;
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e0);
  if (iVar1 == -1) {
    if (band_navigation_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[BAND_NAVIGATION_ERR]%s()/%d get ap entry by id failed.\n";
    uVar3 = 0xf3;
LAB_0055f368:
    printf(pcVar2,"band_navigation_wtp_packt_send",uVar3);
    return uVar4;
  }
  iVar1 = serv_wtp_address_arg_init(&local_2f0);
  if (iVar1 == -1) {
    uVar4 = 0xffffffff;
    if (band_navigation_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[BAND_NAVIGATION_ERR]%s()/%d init serv argv failed.\n";
    uVar3 = 0xf9;
    goto LAB_0055f368;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(local_2d0,&local_2f0,1,1,0x15f0000,1,3);
  if (iVar1 == -1) {
    if ((band_navigation_err_switch == 0) || (iVar1 = is_target_debug_ap(&local_2f0), iVar1 == 0))
    goto LAB_0055f408;
    pcVar2 = "[BAND_NAVIGATION_ERR]%s()/%d get addr from apmngr failed.\n";
    uVar4 = 0xfe;
  }
  else {
    if (local_2e8 == 0) {
      if ((band_navigation_debug_switch != 0) &&
         (iVar1 = is_target_debug_ap(&local_2f0), iVar1 != 0)) {
        printf("[BAND_NAVIGATION_DEBUG]%s()/%d AP not support band navigation\n",
               "band_navigation_wtp_packt_send",0x103);
      }
      serv_wtp_address_arg_destroy(&local_2f0);
      return 0;
    }
    iVar1 = band_navigation_packet_send(&local_2f0);
    if (iVar1 != -1) {
      uVar4 = 0;
      serv_wtp_address_arg_destroy(&local_2f0);
      if (band_navigation_debug_switch == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      pcVar2 = "[BAND_NAVIGATION_DEBUG]%s()/%d send band navigation configure to AP successfully.\n"
      ;
      uVar3 = 0x10f;
      goto LAB_0055f368;
    }
    if ((band_navigation_err_switch == 0) || (iVar1 = is_target_debug_ap(&local_2f0), iVar1 == 0))
    goto LAB_0055f408;
    pcVar2 = "[BAND_NAVIGATION_ERR]%s()/%d init serv argv failed.\n";
    uVar4 = 0x10a;
  }
  printf(pcVar2,"band_navigation_wtp_packt_send",uVar4);
LAB_0055f408:
  serv_wtp_address_arg_destroy(&local_2f0);
  return 0xffffffff;
}

