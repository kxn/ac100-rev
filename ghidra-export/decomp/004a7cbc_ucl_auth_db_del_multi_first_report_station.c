// func ucl_auth_db_del_multi_first_report_station @ 004a7cbc size=344

undefined4 ucl_auth_db_del_multi_first_report_station(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 < 0) {
    uVar2 = 0xffffffff;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Para is invalid.\n","ucl_auth_db_del_multi_first_report_station"
             ,300);
    }
  }
  else {
    iVar3 = 0;
    uac_mutex_take(g_first_report_mutex,0xffffffff);
    iVar1 = uac_list_first(&g_first_report_list);
    while (iVar1 != 0) {
      if (iVar3 == param_1) goto LAB_004a7d88;
      iVar3 = iVar3 + 1;
      uac_list_remove(iVar1);
      uac_mem_free_my(iVar1);
      iVar1 = uac_list_first(&g_first_report_list);
    }
    if ((iVar3 != param_1) && (ucl_info_switch != 0)) {
      printf("[UCL_AUTH_INFO]%s()/%d Del first report station num is %d, and don\'t match with given para %d.\n"
             ,"ucl_auth_db_del_multi_first_report_station",0x13f,iVar3,param_1);
    }
LAB_004a7d88:
    uVar2 = 0;
    uac_mutex_give(g_first_report_mutex);
  }
  return uVar2;
}

