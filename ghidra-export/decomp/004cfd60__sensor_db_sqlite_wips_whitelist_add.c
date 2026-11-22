// func _sensor_db_sqlite_wips_whitelist_add @ 004cfd60 size=292

undefined4 _sensor_db_sqlite_wips_whitelist_add(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_888;
  undefined4 local_884;
  undefined4 local_880;
  undefined4 local_87c;
  undefined2 local_878;
  undefined1 auStack_874 [100];
  char acStack_810 [2048];
  
  memset(acStack_810,0,0x800);
  local_888 = 0;
  local_884 = 0;
  local_880 = 0;
  local_87c = 0;
  local_878 = 0;
  memset(auStack_874,0,100);
  wips_mac2str(param_1 + 0x10,&local_888);
  FUN_00408420(param_1 + 0x16,0x32,auStack_874,100);
  uVar2 = 0;
  snprintf(acStack_810,0x800,
           "INSERT INTO whitelist_table(whitelist_id, mac, ssid, ssid_encode, sensor_id, rssi, last_discover_time, operation_time)VALUES(%d, \'%s\', \'%s\', %d, %d, %d, %d, %d)"
           ,*(undefined4 *)(param_1 + 0xc),&local_888,auStack_874,*(undefined4 *)(param_1 + 0x48),
           (uint)*(ushort *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x50),
           *(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x58));
  iVar1 = FUN_00407d60(g_sensor_db_ptr,acStack_810);
  if ((iVar1 != 0) && (uVar2 = 0xffffffff, sensor_err_switch != '\0')) {
    printf("[SENSOR_ERROR]%s()/%d uac_sqlite_exec_no_cb() fail, sql_cmd=%s\n",
           "_sensor_db_sqlite_wips_whitelist_add",0x11b,acStack_810);
  }
  return uVar2;
}

