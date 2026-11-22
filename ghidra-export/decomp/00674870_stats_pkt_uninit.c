// func stats_pkt_uninit @ 00674870 size=104

int stats_pkt_uninit(void)

{
  int iVar1;
  
  iVar1 = serv_msg_mngr_unregister(9,0x50,_stats_pkt_wtp_event_listener);
  if ((iVar1 != 0) && (stats_err_switch != '\0')) {
    printf("[STATISTICS_ERROR]%s()/%d unregister wtp event req for wstation module fail.\n",
           "stats_pkt_uninit",0x26b);
  }
  return iVar1;
}

