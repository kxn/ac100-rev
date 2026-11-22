// func uac_wservice_rd_modify @ 005dd8b8 size=1

int uac_wservice_rd_modify(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = -1;
  if (param_3 != 0 || param_2 != 0) {
    if ((param_2 == 0) ||
       (iVar3 = wserv_db_rd_for_each_wserv(param_1,2,_uac_wserv_del_cb,0), iVar3 == 0)) {
      if (param_3 == 0) {
        return iVar3;
      }
      iVar3 = wserv_db_rd_for_each_wserv(param_1,1,_uac_wserv_add_cb,0);
      if (iVar3 == 0) {
        return 0;
      }
      if (g_wserv_error == 0) {
        return iVar3;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return iVar3;
      }
      uVar2 = 0x158a;
    }
    else {
      if (g_wserv_error == 0) {
        return iVar3;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return iVar3;
      }
      uVar2 = 0x1580;
    }
    printf("<wserv>[error]%s(): %d  -> wserv_db_rd_for_each_wserv() fail\r\n",
           "uac_wservice_rd_modify",uVar2);
  }
  return iVar3;
}

