// func sensor_db_delete @ 004d1470 size=580

undefined4 sensor_db_delete(ushort param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  void *__s;
  undefined4 uVar4;
  ushort local_res0 [8];
  
  local_res0[0] = param_1;
  if ((param_1 < 50000) || (iVar2 = apmngr_db_get_sensor_max(), iVar2 + 50000 <= (int)(uint)param_1)
     ) {
    uVar4 = 0xffffffff;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Invalid entry id:%d\n","sensor_db_delete",0x3bb,
             (uint)local_res0[0]);
    }
  }
  else {
    FUN_004082d0(g_sensor_mutex,0xffffffff);
    iVar2 = g_sensor_entry_array + (uint)local_res0[0] * 0x18 + -1200000;
    if (*(char *)(iVar2 + 2) == '\0') {
      if (sensor_warning_switch != '\0') {
        printf("[SENSOR_WARNING]%s()/%d Entry id %d is not used\n","sensor_db_delete",0x3c2);
      }
      uVar4 = 0xffffffff;
      FUN_00407f30(g_sensor_mutex);
    }
    else {
      if (*(int *)(iVar2 + 0x10) != 0) {
        FUN_00407df0();
      }
      iVar2 = 0;
      if (*(int *)(g_sensor_entry_array + (uint)local_res0[0] * 0x18 + -0x124f6c) != 0) {
        for (; iVar3 = g_sensor_entry_array + (uint)local_res0[0] * 0x18 + -1200000,
            iVar2 < *(short *)(iVar3 + 0xe); iVar2 = iVar2 + 1) {
          iVar3 = FUN_00407fa0(g_sensor_vap_hash,*(int *)(iVar3 + 0x14) + iVar2 * 0xc);
          if (iVar3 != 0) {
            FUN_00407f40(g_sensor_vap_hash,iVar3);
            FUN_00407df0(iVar3);
          }
        }
        FUN_00407df0(*(undefined4 *)(iVar3 + 0x14));
      }
      uVar4 = 0;
      __s = (void *)(g_sensor_entry_array + (uint)local_res0[0] * 0x18 + -1200000);
      cVar1 = *(char *)((int)__s + 3);
      memset(__s,0,0x18);
      FUN_00407f30(g_sensor_mutex);
      if (cVar1 != '\0') {
        uVar4 = 0xffffffff;
        iVar2 = sensor_db_sqlite_notify_msg(2,local_res0,2);
        if (iVar2 == 0) {
          uVar4 = 0;
        }
      }
    }
  }
  return uVar4;
}

