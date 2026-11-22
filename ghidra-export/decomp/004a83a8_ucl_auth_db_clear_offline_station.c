// func ucl_auth_db_clear_offline_station @ 004a83a8 size=208

void ucl_auth_db_clear_offline_station(void)

{
  int iVar1;
  
  uac_mutex_take(g_offline_station_mutex,0xffffffff);
  iVar1 = uac_list_first(&g_offline_station_list);
  while (iVar1 != 0) {
    uac_list_remove(iVar1);
    uac_hash_remove(g_offline_station_hash,iVar1);
    uac_mem_free_my(iVar1);
    iVar1 = uac_list_first(&g_offline_station_list);
  }
  uac_mutex_give(g_offline_station_mutex);
  return;
}

