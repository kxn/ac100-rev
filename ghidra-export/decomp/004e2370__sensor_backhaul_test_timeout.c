// func _sensor_backhaul_test_timeout @ 004e2370 size=176

void _sensor_backhaul_test_timeout(void)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  iVar1 = unfinished_sensor_num_first;
  g_sensor_backhaul_test_state = 2;
  iVar3 = 0;
  sensor_backhaul_test_timer = 0xffffffff;
  psVar2 = unfinished_sensor_list;
  while (iVar3 < iVar1) {
    if ((*psVar2 == -1) || (*(int *)(psVar2 + 2) != 1)) {
      iVar3 = iVar3 + 1;
      psVar2 = psVar2 + 0x18;
    }
    else {
      psVar2[2] = 0;
      psVar2[3] = 3;
      backhaul_test_finished_sensor_num = backhaul_test_finished_sensor_num + 1;
      iVar3 = iVar3 + 1;
      psVar2 = psVar2 + 0x18;
    }
  }
  FUN_00407f30(g_sensor_mngt_mutex);
  return;
}

