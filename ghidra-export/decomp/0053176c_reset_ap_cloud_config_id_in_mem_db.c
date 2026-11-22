// func reset_ap_cloud_config_id_in_mem_db @ 0053176c size=192

undefined4 reset_ap_cloud_config_id_in_mem_db(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_220 [68];
  undefined1 auStack_1dc [8];
  undefined2 local_1d4;
  char acStack_4b [67];
  
  memset(local_220,0,0x41);
  local_220[0] = '0';
  memset(auStack_1dc,0,0x1d4);
  local_1d4 = param_1;
  strncpy(acStack_4b,local_220,0x40);
  apmngr_db_entry_cloud_config_id_set(param_1,local_220);
  uVar2 = 0;
  iVar1 = apmngr_db_sqlite_notify_msg(6,auStack_1dc,0x1d4);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d ap cloud_config_id reset error in db\n",
           "reset_ap_cloud_config_id_in_mem_db",0xd6b);
  }
  return uVar2;
}

