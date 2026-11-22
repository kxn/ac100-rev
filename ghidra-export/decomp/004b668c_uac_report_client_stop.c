// func uac_report_client_stop @ 004b668c size=252

undefined4 uac_report_client_stop(void)

{
  if (report_debug_switch != 0) {
    printf("[REPORT_DEBUG]%s()/line %d : uac_report_client_stop\n","uac_report_client_stop",399);
  }
  _reset_by_jcs = 1;
  if ((byte)(server_session - 1U) < 2) {
    shutdown(DAT_00767e70,2);
    close(DAT_00767e70);
  }
  else if (_g_curl != 0) {
    if (report_debug_switch != 0) {
      printf("[REPORT_DEBUG]%s()/line %d : uac_report_client_stop shutdown http _g_sockfd = %d\n",
             "uac_report_client_stop",0x19b,_g_sockfd);
    }
    shutdown(_g_sockfd,2);
    close(_g_sockfd);
    _g_curl = 0;
    _g_sockfd = -1;
  }
  return 0;
}

