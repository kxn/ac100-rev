// func FUN_005d9738 @ 005d9738 size=804

undefined4 FUN_005d9738(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  char local_308 [4];
  undefined4 local_304;
  undefined4 local_300;
  int local_2fc;
  undefined4 local_2f8;
  undefined1 auStack_2f0 [16];
  ushort local_2e0;
  
  uVar4 = 0xffffffff;
  local_308[0] = '\0';
  memset(auStack_2f0,0,0x2d8);
  local_304 = 0;
  local_300 = 0;
  local_2fc = 0;
  local_2f8 = 0;
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  uVar1 = rdmngr_db_generate_ap_id(*param_1);
  iVar2 = apmngr_db_entry_get_by_id(uVar1 & 0xffff,auStack_2f0);
  if (iVar2 != 0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "<wserv>[error]%s(): %d  -> apmngr_db_entry_get_by_id() fail.ap_id=%d\r\n";
    uVar3 = 0x85b;
    goto LAB_005d9844;
  }
  iVar2 = apmngr_checksum_update(auStack_2f0,0);
  if (iVar2 != 0) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("<wserv>[error]%s(): %d  -> update md5 failed.\r\n","_uac_wserv_checksum_cb",0x860);
    return 0xffffffff;
  }
  FUN_004082d0(DAT_007598e4,0xffffffff);
  _uac_wserv_packet_waiting_status_get_by_ap_id(uVar1,local_308);
  if (local_308[0] == '\x01') {
    _uac_wserv_packet_md5_type_set_by_ap_id(uVar1,1);
    _uac_wserv_packet_last_send_status_set_by_ap_id(uVar1,1);
  }
  else {
    local_304 = 0;
    local_300 = 0;
    local_2fc = 0;
    local_2f8 = 0;
    iVar2 = serv_wtp_address_arg_init(&local_304);
    if (iVar2 == -1) {
      if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(&local_304), iVar2 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> serv_wtp_address_arg_init() fail.\r\n",
               "_uac_wserv_checksum_cb",0x870);
      }
LAB_005d99d4:
      serv_wtp_address_arg_destroy(&local_304);
      FUN_00407f30(DAT_007598e4);
      return 0xffffffff;
    }
    iVar2 = apmngr_db_get_addr_by_capacity(uVar1 & 0xffff,&local_304,0,1,0x15f0000,0);
    if (iVar2 == -1) {
      if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(&local_304), iVar2 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n",
               "_uac_wserv_checksum_cb",0x877,uVar1);
      }
    }
    else if (local_2fc != 0) {
      iVar2 = serv_user_defined_packet_send(&local_304,_uac_wserv_packet_send_callback);
      if (iVar2 != 0) {
        if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(&local_304), iVar2 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> serv_user_defined_packet_send() failed.ap_id=%d\r\n",
                 "_uac_wserv_checksum_cb",0x882,uVar1);
        }
        goto LAB_005d99d4;
      }
      serv_wtp_address_arg_destroy(&local_304);
      _uac_wserv_packet_md5_type_set_by_ap_id(uVar1,1);
      _uac_wserv_packet_last_send_status_set_by_ap_id(uVar1,1);
      _uac_wserv_packet_waiting_status_set_by_ap_id(uVar1,1);
      goto LAB_005d9918;
    }
    serv_wtp_address_arg_destroy(&local_304);
  }
LAB_005d9918:
  uVar4 = 0;
  FUN_00407f30(DAT_007598e4);
  if (g_wserv_debug == 0) {
    return 0;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0;
  }
  uVar1 = (uint)local_2e0;
  __format = "<wserv>[debug]%s(): %d  -> @ ap_id=%d\n\r\n";
  uVar3 = 0x88e;
LAB_005d9844:
  printf(__format,"_uac_wserv_checksum_cb",uVar3,uVar1);
  return uVar4;
}

