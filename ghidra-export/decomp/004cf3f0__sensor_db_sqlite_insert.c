// func _sensor_db_sqlite_insert @ 004cf3f0 size=300

undefined4 _sensor_db_sqlite_insert(ushort *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_420 [1048];
  
  memset(local_420 + 0x14,0,0x400);
  local_420[0] = '\0';
  local_420[1] = '\0';
  local_420[2] = '\0';
  local_420[3] = '\0';
  local_420[4] = '\0';
  local_420[5] = '\0';
  local_420[6] = '\0';
  local_420[7] = '\0';
  local_420[8] = '\0';
  local_420[9] = '\0';
  local_420[10] = '\0';
  local_420[0xb] = '\0';
  local_420[0xc] = '\0';
  local_420[0xd] = '\0';
  local_420[0xe] = '\0';
  local_420[0xf] = '\0';
  local_420[0x10] = '\0';
  local_420[0x11] = '\0';
  local_420[0x12] = '\0';
  local_420[0x13] = '\0';
  if (*(char *)(param_1 + 2) != '\0') {
    snprintf(local_420,0x14,"%02X%02X%02X%02X%02X%02X",(uint)*(byte *)((int)param_1 + 5),
             (uint)*(byte *)(param_1 + 3),(uint)*(byte *)((int)param_1 + 7),
             (uint)*(byte *)(param_1 + 4),(uint)*(byte *)((int)param_1 + 9),
             (uint)*(byte *)(param_1 + 5));
  }
  uVar2 = 0xffffffff;
  iVar1 = snprintf(local_420 + 0x14,0x400,"INSERT INTO %s (%s, %s) VALUES( %d, \'%s\');",
                   "sensorCfgTable","sensor_id","primary_bssid",(uint)*param_1,local_420);
  if (-1 < iVar1) {
    uVar2 = 0;
    iVar1 = FUN_00407d60(g_sensor_db_ptr,local_420 + 0x14);
    if ((iVar1 != 0) && (uVar2 = 0xffffffff, sensor_err_switch != '\0')) {
      printf("[SENSOR_ERROR]%s()/%d Failed to insert to AP-entry table.\n",
             "_sensor_db_sqlite_insert",0xd0);
    }
  }
  return uVar2;
}

