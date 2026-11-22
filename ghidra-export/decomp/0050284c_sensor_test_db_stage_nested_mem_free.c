// func sensor_test_db_stage_nested_mem_free @ 0050284c size=124

void sensor_test_db_stage_nested_mem_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 4) == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      if (*(char *)(param_1 + 0x11) != '\0') {
        FUN_00407df0();
        *(undefined4 *)(param_1 + 4) = 0;
      }
      iVar1 = *(int *)(param_1 + 0xc);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 8);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0xc) = 0;
      iVar1 = *(int *)(param_1 + 8);
    }
    if (iVar1 != 0) {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 8) = 0;
    }
  }
  return;
}

