// func ucl_auth_db_del_offline_station_by_mac @ 004a817c size=268

undefined4 ucl_auth_db_del_offline_station_by_mac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Mac is null.\n","ucl_auth_db_del_offline_station_by_mac",0x1c9);
    }
  }
  else {
    uac_mutex_take(g_offline_station_mutex,0xffffffff);
    iVar1 = uac_hash_get(g_offline_station_hash,param_1);
    if (iVar1 == 0) {
      uac_mutex_give(g_offline_station_mutex);
      uVar2 = 0;
    }
    else {
      uac_hash_remove(g_offline_station_hash,iVar1);
      uac_list_remove(iVar1);
      uac_mutex_give(g_offline_station_mutex);
      uVar2 = 0;
      uac_mem_free_my(iVar1);
    }
  }
  return uVar2;
}

