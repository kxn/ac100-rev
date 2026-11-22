// func ucl_auth_db_get_multi_offline_station @ 004a7ec4 size=304

undefined4 ucl_auth_db_get_multi_offline_station(void *param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 == (void *)0x0) || (param_2 < 1)) {
    uVar2 = 0xffffffff;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Para is invalid.\n","ucl_auth_db_get_multi_offline_station",
             0x17c);
    }
  }
  else {
    uac_mutex_take(g_offline_station_mutex,0xffffffff);
    iVar1 = uac_list_first(&g_offline_station_list);
    for (iVar3 = 0; (iVar1 != 0 && (iVar3 != param_2)); iVar3 = iVar3 + 1) {
      memcpy(param_1,(void *)(iVar1 + 0xc),6);
      param_1 = (void *)((int)param_1 + 6);
      iVar1 = uac_list_next(iVar1);
    }
    uVar2 = 0;
    *param_3 = iVar3;
    uac_mutex_give(g_offline_station_mutex);
  }
  return uVar2;
}

