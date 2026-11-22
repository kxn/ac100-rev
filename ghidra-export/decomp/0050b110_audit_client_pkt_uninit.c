// func audit_client_pkt_uninit @ 0050b110 size=1

int audit_client_pkt_uninit(void)

{
  int iVar1;
  
  iVar1 = serv_msg_mngr_unregister(9,0x50,_audit_client_pkt_wtp_event_listener);
  if ((iVar1 != 0) && (audit_err_switch != 0)) {
    printf("[AUDIT_ERR]%s()/%d unregister wtp event req for wstation module fail.\n",
           "audit_client_pkt_uninit",0x166);
  }
  return iVar1;
}

