// func sensor_db_entry_dump @ 004d16b4 size=1

void sensor_db_entry_dump(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 50000;
  iVar2 = 0;
  FUN_004082d0(g_sensor_mutex,0xffffffff);
  while( true ) {
    iVar1 = apmngr_db_get_sensor_max();
    if (iVar1 + 50000 <= iVar3) break;
    if (*(char *)(g_sensor_entry_array + iVar2 + 2) == '\0') {
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18;
    }
    else {
      _sensor_db_single_entry_dump(g_sensor_entry_array + iVar2,param_1 == 1);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18;
    }
  }
  uac_mutex_give(g_sensor_mutex);
  return;
}

