// func wsta_roam_pkt_uninit @ 0048a260 size=104

int wsta_roam_pkt_uninit(void)

{
  int iVar1;
  
  iVar1 = serv_msg_mngr_unregister(9,0x5a,_wsta_roam_pkt_wtp_event_listener);
  if ((iVar1 != 0) && (wsta_roam_err_switch != '\0')) {
    printf("[WSTA_ROAM_ERROR]%s()/%d unregister wtp event req for wstation module fail.\n",
           "wsta_roam_pkt_uninit",0xe63);
  }
  return iVar1;
}

