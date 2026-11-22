// func ac_passthrough_reponse_fini @ 0050e0fc size=132

void ac_passthrough_reponse_fini(void)

{
  int iVar1;
  
  iVar1 = serv_msg_mngr_unregister(9,0x78,ac_sub_device_report_pkt_echo_req_listen);
  if (iVar1 == -1) {
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d unregister callback to listen join-req capwap message event failed.\n"
             ,"ac_passthrough_reponse_fini",0x8dc);
      return;
    }
  }
  else if (ac_passthrough_get_reponse_mutex != 0) {
    FUN_00408360();
    ac_passthrough_get_reponse_mutex = 0;
  }
  return;
}

