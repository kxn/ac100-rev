// func _sensor_test_sqlite_bssid_alloc_insert @ 004fd5d8 size=624

int _sensor_test_sqlite_bssid_alloc_insert(int param_1)

{
  int iVar1;
  int iVar2;
  char *__s;
  char local_140 [280];
  
  __s = local_140 + 0x14;
  memset(__s,0,0x100);
  local_140[0] = '\0';
  local_140[1] = '\0';
  local_140[2] = '\0';
  local_140[3] = '\0';
  local_140[4] = '\0';
  local_140[5] = '\0';
  local_140[6] = '\0';
  local_140[7] = '\0';
  local_140[8] = '\0';
  local_140[9] = '\0';
  local_140[10] = '\0';
  local_140[0xb] = '\0';
  local_140[0xc] = '\0';
  local_140[0xd] = '\0';
  local_140[0xe] = '\0';
  local_140[0xf] = '\0';
  local_140[0x10] = '\0';
  local_140[0x11] = '\0';
  local_140[0x12] = '\0';
  local_140[0x13] = '\0';
  if (((param_1 == 0) || (*(int *)(param_1 + 8) == 0)) || (*(int *)(param_1 + 4) < 1)) {
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d input invalid\n","_sensor_test_sqlite_bssid_alloc_insert",
             0x1e7);
    }
    iVar1 = -1;
    if (param_1 == 0) {
      return -1;
    }
  }
  else {
    iVar1 = -1;
    for (iVar2 = 0; iVar2 < *(int *)(param_1 + 4); iVar2 = iVar2 + 1) {
      local_140[0] = '\0';
      local_140[1] = '\0';
      local_140[2] = '\0';
      local_140[3] = '\0';
      local_140[4] = '\0';
      local_140[5] = '\0';
      local_140[6] = '\0';
      local_140[7] = '\0';
      local_140[8] = '\0';
      local_140[9] = '\0';
      local_140[10] = '\0';
      local_140[0xb] = '\0';
      local_140[0xc] = '\0';
      local_140[0xd] = '\0';
      local_140[0xe] = '\0';
      local_140[0xf] = '\0';
      local_140[0x10] = '\0';
      local_140[0x11] = '\0';
      local_140[0x12] = '\0';
      local_140[0x13] = '\0';
      iVar1 = *(int *)(param_1 + 8) + iVar2 * 0x24;
      snprintf(local_140,0x14,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",(uint)*(byte *)(iVar1 + 0xc),
               (uint)*(byte *)(iVar1 + 0xd),(uint)*(byte *)(iVar1 + 0xe),
               (uint)*(byte *)(iVar1 + 0xf),(uint)*(byte *)(iVar1 + 0x10),
               (uint)*(byte *)(iVar1 + 0x11));
      iVar1 = *(int *)(param_1 + 8) + iVar2 * 0x24;
      snprintf(__s,0x100,"INSERT INTO %s VALUES( \'%s\', %d, %d,%d, %d, %d, %d,null);",
               "bssidalloc_tbl",local_140,*(undefined4 *)(iVar1 + 0x18),
               (uint)*(byte *)(iVar1 + 0x22),(uint)*(ushort *)(iVar1 + 0x20),
               (int)*(char *)(iVar1 + 0x23),*(undefined4 *)(iVar1 + 0x14),
               *(undefined4 *)(iVar1 + 0x1c));
      iVar1 = FUN_00407d60(l_sensor_test_db_ptr,__s);
      if (iVar1 != 0) {
        iVar2 = FUN_00408410();
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_1 + 8);
        }
        else {
          printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                 "_sensor_test_sqlite_bssid_alloc_insert",0x1fa,iVar1,__s,
                 "Failed to insert into bssid_alloc table in flash.");
          iVar2 = *(int *)(param_1 + 8);
        }
        goto LAB_004fd75c;
      }
    }
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d sqlite bssid_alloc insert success\n",
             "_sensor_test_sqlite_bssid_alloc_insert",0x1fc);
      iVar2 = *(int *)(param_1 + 8);
      goto LAB_004fd75c;
    }
  }
  iVar2 = *(int *)(param_1 + 8);
LAB_004fd75c:
  if (iVar2 != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 8) = 0;
  }
  FUN_00407df0(param_1);
  return iVar1;
}

