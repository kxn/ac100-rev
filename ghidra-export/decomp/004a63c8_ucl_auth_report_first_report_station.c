// func ucl_auth_report_first_report_station @ 004a63c8 size=448

/* WARNING: Removing unreachable block (ram,0x004a645c) */

int ucl_auth_report_first_report_station(void)

{
  void *__s;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_30 [2];
  
  local_30[0] = 0;
  __s = (void *)uac_mem_malloc_my(0x2fda0,0x155);
  if (__s == (void *)0x0) {
    iVar2 = -1;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Memory is not enough.\n","ucl_auth_report_first_report_station",
             0x158);
    }
  }
  else {
    memset(__s,0,0x2fda0);
    iVar3 = 0;
    iVar2 = -1;
    iVar1 = ucl_auth_db_get_first_report_num();
    iVar1 = iVar1 / 1000 + (uint)(iVar1 % 1000 != 0);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    for (; iVar3 < iVar1; iVar3 = iVar3 + 1) {
      uVar4 = 1;
      if (((iVar1 != 1) && (uVar4 = 2, iVar3 != 0)) && (uVar4 = 4, iVar1 + -1 != iVar3)) {
        uVar4 = 3;
      }
      iVar2 = ucl_auth_db_get_multi_first_report_station(__s,1000,local_30);
      if ((iVar2 == -1) ||
         (iVar2 = ucl_auth_fill_first_report_station
                            (__s,local_30[0],uVar4,ucl_auth_send_first_report_station), iVar2 == -1)
         ) break;
      iVar2 = ucl_auth_db_del_multi_first_report_station(local_30[0]);
    }
    uac_mem_free_my(__s);
  }
  return iVar2;
}

