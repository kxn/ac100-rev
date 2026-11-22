// func _sensor_db_sqlite_wips_whitelist_delete @ 004cfe84 size=152

undefined4 _sensor_db_sqlite_wips_whitelist_delete(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_808 [2048];
  
  memset(acStack_808,0,0x800);
  snprintf(acStack_808,0x800,"DELETE FROM whitelist_table WHERE (whitelist_id == %d)",param_1);
  uVar2 = 0;
  iVar1 = FUN_00407d60(g_sensor_db_ptr,acStack_808);
  if ((iVar1 != 0) && (uVar2 = 0xffffffff, sensor_err_switch != '\0')) {
    printf("[SENSOR_ERROR]%s()/%d uac_sqlite_exec_no_cb() fail, sql_cmd=%s\n",
           "_sensor_db_sqlite_wips_whitelist_delete",0x130,acStack_808);
  }
  return uVar2;
}

