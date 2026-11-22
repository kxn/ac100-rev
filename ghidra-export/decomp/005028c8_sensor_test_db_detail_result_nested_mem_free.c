// func sensor_test_db_detail_result_nested_mem_free @ 005028c8 size=396

void sensor_test_db_detail_result_nested_mem_free(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0) {
      iVar2 = param_1[1];
    }
    else if (*(char *)(param_1 + 2) == '\0') {
      sensor_test_db_stage_nested_mem_free();
      FUN_00407df0(*param_1);
      *param_1 = 0;
      *(undefined1 *)(param_1 + 2) = 0;
      if (sensor_test_err_switch == '\0') {
        iVar2 = param_1[1];
      }
      else {
        printf("[SENSOR_TEST_ERROR]%s()/%d test_stage_cnt<=0 but test_ptr is not null, may cause mem leak\n"
               ,"sensor_test_db_detail_result_nested_mem_free",0xf24);
        iVar2 = param_1[1];
      }
    }
    else {
      iVar2 = param_1[1];
    }
    if (iVar2 == 0) {
      iVar2 = param_1[1];
    }
    else if (*(char *)((int)param_1 + 9) == '\0') {
      sensor_test_db_stage_nested_mem_free();
      FUN_00407df0(param_1[1]);
      param_1[1] = 0;
      *(undefined1 *)((int)param_1 + 9) = 0;
      if (sensor_test_err_switch == '\0') {
        iVar2 = param_1[1];
      }
      else {
        printf("[SENSOR_TEST_ERROR]%s()/%d diagnosis_stage_cnt<=0 but diagnosis_ptr is not null, may cause mem leak\n"
               ,"sensor_test_db_detail_result_nested_mem_free",0xf2d);
        iVar2 = param_1[1];
      }
    }
    else {
      iVar2 = param_1[1];
    }
    iVar3 = 0;
    if ((iVar2 != 0) && (uVar1 = (uint)*(byte *)((int)param_1 + 9), uVar1 != 0)) {
      for (; iVar3 < (int)uVar1; iVar3 = iVar3 + 1) {
        sensor_test_db_stage_nested_mem_free(param_1[1] + iVar3 * 0x14);
        uVar1 = (uint)*(byte *)((int)param_1 + 9);
      }
      FUN_00407df0();
      param_1[1] = 0;
      *(undefined1 *)(param_1 + 2) = 0;
    }
    iVar2 = 0;
    if ((*param_1 != 0) && (uVar1 = (uint)*(byte *)(param_1 + 2), uVar1 != 0)) {
      for (; iVar2 < (int)uVar1; iVar2 = iVar2 + 1) {
        sensor_test_db_stage_nested_mem_free(*param_1 + iVar2 * 0x14);
        uVar1 = (uint)*(byte *)(param_1 + 2);
      }
      FUN_00407df0();
      *(undefined1 *)((int)param_1 + 9) = 0;
      *param_1 = 0;
    }
  }
  return;
}

