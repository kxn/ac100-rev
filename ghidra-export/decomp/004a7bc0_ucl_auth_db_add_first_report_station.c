// func ucl_auth_db_add_first_report_station @ 004a7bc0 size=252

undefined4 ucl_auth_db_add_first_report_station(void *param_1)

{
  void *__s;
  undefined4 uVar1;
  
  __s = (void *)uac_mem_malloc_my(0xd0,0x10a);
  if (__s == (void *)0x0) {
    uVar1 = 0xffffffff;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Memory is not enough.\n","ucl_auth_db_add_first_report_station",
             0x10d);
    }
  }
  else {
    memset(__s,0,0xd0);
    memcpy((void *)((int)__s + 0xc),param_1,0xc4);
    uac_mutex_take(g_first_report_mutex,0xffffffff);
    uVar1 = 0;
    uac_list_insert_last(&g_first_report_list,__s);
    uac_mutex_give(g_first_report_mutex);
  }
  return uVar1;
}

