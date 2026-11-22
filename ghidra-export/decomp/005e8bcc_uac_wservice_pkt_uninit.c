// func uac_wservice_pkt_uninit @ 005e8bcc size=124

int uac_wservice_pkt_uninit(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = serv_msg_mngr_unregister(5,100,_uac_wserv_pkt_config_status_req_listener);
  if (((iVar1 != 0) && (g_wserv_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[error]%s(): %d  -> unregister config status req for wservice module fail.\r\n",
           "uac_wservice_pkt_uninit",0x2c0);
  }
  return iVar1;
}

