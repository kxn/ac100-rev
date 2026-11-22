// func uac_wservice_ap_connect @ 005dd608 size=1

int uac_wservice_ap_connect(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_db_ap_connect() begin, ap_id=%d, rd_cnt=%d.\r\n",
           "wserv_db_ap_connect",0x11a8,param_1,param_2);
  }
  iVar2 = 1;
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  do {
    iVar3 = 0;
    if (param_2 < iVar2) {
LAB_005f14f4:
      FUN_00407f30(DAT_007cbef0);
      return iVar3;
    }
    uVar1 = rdmngr_db_generate_rd_id(param_1,iVar2);
    if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> rd_id=%d connect\r\n","wserv_db_ap_connect",0x11ad,uVar1);
    }
    iVar3 = _wserv_rd_add(uVar1);
    if (iVar3 != 0) {
      if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> _wserv_rd_add() fail!\r\n","wserv_db_ap_connect",0x11b1
              );
      }
      goto LAB_005f14f4;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}

