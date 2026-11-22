// func reset_ap_batch_cloud_config_id_in_mem_db @ 00531e78 size=1

undefined4 reset_ap_batch_cloud_config_id_in_mem_db(undefined2 *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char acStack_230 [68];
  undefined1 auStack_1ec [8];
  undefined2 uStack_1e4;
  char acStack_5b [71];
  
  memset(acStack_230,0,0x41);
  acStack_230[0] = '0';
  memset(auStack_1ec,0,0x1d4);
  iVar3 = 0;
  strncpy(acStack_5b,acStack_230,0x40);
  apmngr_db_specify_entry_cloud_config_id_reset(param_1,param_2,acStack_230);
  bVar1 = 0 < param_2;
  while( true ) {
    if (!bVar1) {
      return 0;
    }
    uStack_1e4 = *param_1;
    param_1 = param_1 + 1;
    iVar2 = apmngr_db_sqlite_notify_msg(6,auStack_1ec,0x1d4);
    if (iVar2 != 0) break;
    iVar3 = iVar3 + 1;
    bVar1 = iVar3 < param_2;
  }
  if (apmngr_err_switch == '\0') {
    return 0xffffffff;
  }
  iVar3 = is_target_debug_ap();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  printf("[APMNGR_ERROR]%s()/%d ap cloud_config_id reset error in db\n",
         "reset_ap_batch_cloud_config_id_in_mem_db",0xd84);
  return 0xffffffff;
}

