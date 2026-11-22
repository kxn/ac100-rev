// func sensor_test_db_case_setting_mem_free @ 00500f1c size=136

void sensor_test_db_case_setting_mem_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x34) == 0) {
      iVar1 = *(int *)(param_1 + 0x38);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x34) = 0;
      iVar1 = *(int *)(param_1 + 0x38);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x30);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x38) = 0;
      iVar1 = *(int *)(param_1 + 0x30);
    }
    if (iVar1 != 0) {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    sensor_test_db_service_nested_mem_free(param_1 + 0x3c);
    FUN_00407df0(param_1);
    return;
  }
  return;
}

