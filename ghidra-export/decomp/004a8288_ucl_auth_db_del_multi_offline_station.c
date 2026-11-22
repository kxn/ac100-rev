// func ucl_auth_db_del_multi_offline_station @ 004a8288 size=288

undefined4 ucl_auth_db_del_multi_offline_station(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 < 1) {
    uVar2 = 0xffffffff;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Para is invalid.\n","ucl_auth_db_del_multi_offline_station",
             0x1ee);
    }
  }
  else {
    iVar3 = 0;
    uac_mutex_take(g_offline_station_mutex,0xffffffff);
    do {
      iVar1 = uac_hash_get(g_offline_station_hash,param_1);
      if (iVar1 != 0) {
        uac_hash_remove(g_offline_station_hash,iVar1);
        uac_list_remove(iVar1);
        uac_mem_free_my(iVar1);
      }
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 6;
    } while (iVar3 != param_2);
    uVar2 = 0;
    uac_mutex_give(g_offline_station_mutex);
  }
  return uVar2;
}

