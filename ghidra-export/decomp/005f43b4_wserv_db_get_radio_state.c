// func wserv_db_get_radio_state @ 005f43b4 size=296

undefined4 wserv_db_get_radio_state(undefined4 param_1,size_t param_2,void *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_db_get_radio_state() begin, ap_id=%d, rd_cnt=%d.\r\n",
           "wserv_db_get_radio_state",0x15ef,param_1,param_2);
  }
  if ((param_3 == (void *)0x0) || ((int)param_2 < 1)) {
    uVar1 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> invalid para!\r\n","wserv_db_get_radio_state",0x15f2);
    }
  }
  else {
    iVar3 = 1;
    memset(param_3,0,param_2);
    do {
      uVar1 = rdmngr_db_generate_rd_id(param_1,iVar3);
      iVar2 = _wserv_is_rd_enable(uVar1);
      if (iVar2 != 0) {
        *(undefined1 *)((int)param_3 + iVar3 + -1) = 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= (int)param_2);
    uVar1 = 0;
  }
  return uVar1;
}

