// func sensor_test_case_dump @ 00507ee4 size=1

void sensor_test_case_dump(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  puts("==========CASE===========");
  while (uVar2 < g_sensor_test_case_num_max) {
    iVar1 = uVar2 * 4;
    if (*(undefined4 **)(l_sensor_test_case_list + iVar1) == (undefined4 *)0x0) {
      uVar2 = uVar2 + 1;
    }
    else {
      iVar3 = iVar3 + 1;
      printf("case_id = %d\n",**(undefined4 **)(l_sensor_test_case_list + iVar1));
      printf("    change_id = %d\n",
             (uint)*(byte *)(*(int *)(*(int *)(l_sensor_test_case_list + iVar1) + 4) + 8));
      printf("    sch_type = %d\n",(int)**(short **)(*(int *)(l_sensor_test_case_list + iVar1) + 4))
      ;
      printf("    sch_period = %d\n",
             (int)*(short *)(*(int *)(*(int *)(l_sensor_test_case_list + iVar1) + 4) + 2));
      printf("    sch_time = %d\n",
             *(undefined4 *)(*(int *)(*(int *)(l_sensor_test_case_list + iVar1) + 4) + 4));
      printf("    rssi_threshold = %d\n",
             (int)*(char *)(*(int *)(*(int *)(l_sensor_test_case_list + iVar1) + 4) + 0xc));
      printf("    group_cnt = %d\n",
             (uint)*(byte *)(*(int *)(*(int *)(l_sensor_test_case_list + iVar1) + 4) + 9));
      printf("    sensor_cnt = %d\n",
             (uint)*(byte *)(*(int *)(*(int *)(l_sensor_test_case_list + iVar1) + 4) + 10));
      printf("    service_type = %d\n",
             (uint)*(ushort *)(*(int *)(*(int *)(l_sensor_test_case_list + iVar1) + 4) + 0x3c));
      puts("---------------------");
      uVar2 = uVar2 + 1;
    }
  }
  putchar(10);
  printf("there are/is %d test case(s)\n",iVar3);
  puts("==========================");
  uac_mutex_give(l_sensor_test_db_mutex);
  return;
}

