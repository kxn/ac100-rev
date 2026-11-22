// func test_case_start_time_dump @ 00508658 size=1

void test_case_start_time_dump(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (uVar2 < g_sensor_test_case_num_max) {
    iVar1 = *(int *)(l_sensor_test_case_list + uVar2 * 4);
    if (iVar1 == 0) {
      uVar2 = uVar2 + 1;
    }
    else {
      iVar1 = *(int *)(iVar1 + 4);
      if (iVar1 != 0) {
        printf("case_id=%d, sch_start_time=%d(s), sch_period=%d(mins)\n",uVar2,
               *(undefined4 *)(iVar1 + 4),(int)*(short *)(iVar1 + 2));
      }
      uVar2 = uVar2 + 1;
    }
  }
  return;
}

