// func uac_wservice_recover_rdentry @ 005e0104 size=156

undefined4 uac_wservice_recover_rdentry(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_10 [2];
  
  local_10[0] = 0;
  iVar1 = apmngr_db_foreach_proc(0xffffffff,collect_recover_rdentry_from_ap,local_10);
  if (iVar1 == 1) {
    uVar2 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[error]%s(): %d  -> apmngr_db_foreach_proc() fail!\r\n",
             "uac_wservice_recover_rdentry",0x16f8);
    }
  }
  else {
    uVar2 = 0;
    if (local_10[0] != 0) {
      FUN_00408400();
    }
  }
  return uVar2;
}

