// func FUN_00650298 @ 00650298 size=792

undefined4 FUN_00650298(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined2 local_2fc;
  undefined4 local_2f8;
  undefined4 local_2f4;
  int local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  local_308 = 0;
  local_304 = 0;
  local_300 = 0;
  local_2fc = 0;
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  memset(auStack_2e8,0,0x2d8);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar4 = 0x17ac;
LAB_00650368:
    printf(pcVar3,"apupd_reset_request_send",uVar4);
    return 0xffffffff;
  }
  iVar1 = apmngr_db_entry_get_by_mac(param_1,auStack_2e8);
  if (iVar1 != 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: Get AP entry failed.\r\n";
    uVar4 = 0x17b1;
    goto LAB_00650368;
  }
  iVar1 = serv_wtp_address_arg_init(&local_2f8);
  if (iVar1 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: init serv argv failed.\r\n";
    uVar4 = 0x17b7;
    goto LAB_00650368;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(local_2d8,&local_2f8,1,1,0xffffffff,0);
  if (iVar1 == -1) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(&local_2f8), iVar1 == 0))
    goto LAB_006504c8;
    pcVar3 = "[APUPD_ERROR]%32s() %05d: add argv failed.\r\n";
    uVar4 = 0x17bc;
  }
  else {
    if (local_2f0 == 0) {
LAB_00650470:
      serv_wtp_address_arg_destroy(&local_2f8);
      return 0;
    }
    iVar1 = apupd_software_version_to_buffer(param_2,&local_308,0xe);
    if (iVar1 == -1) {
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(&local_2f8), iVar1 == 0))
      goto LAB_006504c8;
      pcVar3 = "[APUPD_ERROR]%32s() %05d: turn software version to buffer failed.\r\n";
      uVar4 = 0x17c7;
    }
    else {
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: apupd_reset_request_create\r\n","apupd_reset_request_send"
               ,0x17cc);
      }
      iVar1 = apupd_reset_request_create(0x12345678,&local_308,0xe,1);
      if (iVar1 != 0) {
        iVar2 = serv_packet_send(&local_2f8,iVar1,0);
        if (iVar2 != -1) {
          cw_pkt_buf_destroy(iVar1);
          goto LAB_00650470;
        }
        if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: send reset packet failed.\r\n",
                 "apupd_reset_request_send",0x17d6);
        }
        cw_pkt_buf_destroy(iVar1);
        goto LAB_006504c8;
      }
      if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(&local_2f8), iVar1 == 0))
      goto LAB_006504c8;
      pcVar3 = "[APUPD_ERROR]%32s() %05d: create reset reqeust failed.\r\n";
      uVar4 = 0x17cf;
    }
  }
  printf(pcVar3,"apupd_reset_request_send",uVar4);
LAB_006504c8:
  serv_wtp_address_arg_destroy(&local_2f8);
  return 0xffffffff;
}

