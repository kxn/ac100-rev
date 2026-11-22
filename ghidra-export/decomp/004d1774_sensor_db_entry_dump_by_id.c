// func sensor_db_entry_dump_by_id @ 004d1774 size=184

void sensor_db_entry_dump_by_id(int param_1)

{
  int iVar1;
  
  if ((49999 < param_1) && (iVar1 = apmngr_db_get_sensor_max(), param_1 < iVar1 + 50000)) {
    FUN_004082d0(g_sensor_mutex,0xffffffff);
    iVar1 = g_sensor_entry_array + param_1 * 0x18 + -1200000;
    if (*(char *)(iVar1 + 2) != '\0') {
      _sensor_db_single_entry_dump(iVar1,1);
    }
    FUN_00407f30(g_sensor_mutex);
    return;
  }
  printf("Invalid sensor id %d",param_1);
  return;
}

