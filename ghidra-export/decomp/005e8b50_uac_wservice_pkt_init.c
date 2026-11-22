// func uac_wservice_pkt_init @ 005e8b50 size=124

int uac_wservice_pkt_init(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = serv_msg_mngr_register(5,100,_uac_wserv_pkt_config_status_req_listener);
  if (((iVar1 != 0) && (g_wserv_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[error]%s(): %d  -> register config status req for wservice module fail.\r\n",
           "uac_wservice_pkt_init",0x2b3);
  }
  return iVar1;
}

