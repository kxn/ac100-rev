// func ucl_auth_db_add_offline_station @ 004a7ff4 size=392

undefined4 ucl_auth_db_add_offline_station(undefined4 param_1,undefined4 param_2)

{
  void *__s;
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res0;
  undefined4 local_res4;
  
  local_res0 = param_1;
  local_res4 = param_2;
  __s = (void *)uac_mem_malloc_my(0x14,0x1a0);
  if (__s == (void *)0x0) {
    uVar2 = 0xffffffff;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Memory is not enough.\n","ucl_auth_db_add_offline_station",0x1a3
            );
    }
  }
  else {
    memset(__s,0,0x14);
    memcpy((void *)((int)__s + 0xc),&local_res0,6);
    uac_mutex_take(g_offline_station_mutex,0xffffffff);
    iVar1 = uac_hash_get(g_offline_station_hash,(void *)((int)__s + 0xc));
    if (iVar1 == 0) {
      iVar1 = uac_hash_add(g_offline_station_hash,__s);
      if (iVar1 != 0) {
        uac_mutex_give(g_offline_station_mutex);
        uac_mem_free_my(__s);
        return 0xffffffff;
      }
      uac_list_insert_last(&g_offline_station_list,__s);
    }
    else {
      uac_mem_free_my(__s);
    }
    uVar2 = 0;
    uac_mutex_give(g_offline_station_mutex);
  }
  return uVar2;
}

