// func ac_passthrough_reponse_init @ 0050e180 size=320

undefined4 ac_passthrough_reponse_init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (ac_passthrough_debug_switch != '\0') {
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d .............ac_passthrough_reponse_init............\n",
           "ac_passthrough_reponse_init",0x8e5);
  }
  ac_passthrough_get_reponse_mutex = FUN_00407f00("ac_passthrough_get_reponse_mutex",0);
  if (ac_passthrough_get_reponse_mutex == 0) {
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d Create ac_passthrough_get_reponse msg mutex failed.\n",
             "ac_passthrough_reponse_init",0x8ea);
    }
    ac_passthrough_reponse_fini();
  }
  else {
    iVar1 = serv_msg_mngr_register(9,0x78,ac_sub_device_report_pkt_wtp_event_req_listen);
    if (iVar1 == -1) {
      if (ac_passthrough_err_switch == '\0') {
        return 0xffffffff;
      }
      uVar2 = 0x8ef;
    }
    else {
      iVar1 = serv_msg_mngr_register(0xd,0x78,ac_sub_device_report_pkt_echo_req_listen);
      if (iVar1 != -1) {
        return 0;
      }
      if (ac_passthrough_err_switch == '\0') {
        return 0xffffffff;
      }
      uVar2 = 0x8f4;
    }
    printf("[AC_PASSTHROUGH_ERROR]%s()/%d register callback to listen join-req capwap message event failed.\n"
           ,"ac_passthrough_reponse_init",uVar2);
  }
  return 0xffffffff;
}

