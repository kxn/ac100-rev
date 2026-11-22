// func ucl_auth_report_offline_station @ 004a71cc size=300

int ucl_auth_report_offline_station(void)

{
  void *__s;
  int iVar1;
  int local_18 [2];
  
  local_18[0] = 0;
  __s = (void *)uac_mem_malloc_my(6000,0x376);
  if (__s == (void *)0x0) {
    iVar1 = -1;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Memory is not enough.\n","ucl_auth_report_offline_station",0x379
            );
    }
  }
  else {
    while( true ) {
      memset(__s,0,6000);
      iVar1 = ucl_auth_db_get_multi_offline_station(__s,1000,local_18);
      if (iVar1 == -1) break;
      if (local_18[0] < 1) {
        iVar1 = 0;
        break;
      }
      iVar1 = ucl_auth_fill_offline_station(__s,local_18[0],ucl_auth_send_offline_station);
      if ((iVar1 == -1) ||
         (iVar1 = ucl_auth_db_del_multi_offline_station(__s,local_18[0]), local_18[0] != 1000))
      break;
    }
    uac_mem_free_my(__s);
  }
  return iVar1;
}

