// func ac_cmcc_portal_deInit @ 00439be4 size=124

void ac_cmcc_portal_deInit(void)

{
  wportal_db_cmcc_data_deInit();
  if (0 < cmcc_sockfd) {
    close(cmcc_sockfd);
    cmcc_sockfd = -1;
  }
  if (0 < cmcc_sockfd_v6) {
    close(cmcc_sockfd_v6);
    cmcc_sockfd_v6 = -1;
  }
  if (_cmcc_threads != 0) {
    FUN_00407df0();
    _cmcc_threads = 0;
  }
  return;
}

