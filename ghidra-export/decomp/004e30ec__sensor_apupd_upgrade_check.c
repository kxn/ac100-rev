// func _sensor_apupd_upgrade_check @ 004e30ec size=216

bool _sensor_apupd_upgrade_check(uint param_1)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_2e8 [20];
  int local_2d4;
  
  bVar2 = true;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2e8);
  if ((iVar1 == 0) && (local_2d4 == 7)) {
    FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
    if ((g_sensor_enable != 0) && ((g_sensor_state == 3 && (0 < unfinished_sensor_num)))) {
      bVar2 = *(short *)(unfinished_sensor_id_map + ((param_1 & 0xffff) - 50000) * 2) == -1;
    }
    FUN_00407f30(g_sensor_mngt_mutex);
  }
  return bVar2;
}

