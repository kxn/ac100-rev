// func ucl_auth_db_clear_first_report_station @ 004a7e14 size=176

void ucl_auth_db_clear_first_report_station(void)

{
  int iVar1;
  
  uac_mutex_take(g_first_report_mutex,0xffffffff);
  iVar1 = uac_list_first(&g_first_report_list);
  while (iVar1 != 0) {
    uac_list_remove(iVar1);
    uac_mem_free_my(iVar1);
    iVar1 = uac_list_first(&g_first_report_list);
  }
  uac_mutex_give(g_first_report_mutex);
  return;
}

