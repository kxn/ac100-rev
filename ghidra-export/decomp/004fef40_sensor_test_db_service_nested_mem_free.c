// func sensor_test_db_service_nested_mem_free @ 004fef40 size=316

void sensor_test_db_service_nested_mem_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 4) == 0) {
      iVar1 = *(int *)(param_1 + 8);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 4) = 0;
      iVar1 = *(int *)(param_1 + 8);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      if (*(int *)(iVar1 + 4) != 0) {
        FUN_00407df0();
        *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0;
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 8));
      *(undefined4 *)(param_1 + 8) = 0;
      iVar1 = *(int *)(param_1 + 0xc);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x10);
    }
    else {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0xc) = 0;
      iVar1 = *(int *)(param_1 + 0x10);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x14);
    }
    else {
      if (*(int *)(iVar1 + 4) != 0) {
        FUN_00407df0();
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 4) = 0;
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = 0;
      iVar1 = *(int *)(param_1 + 0x14);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x18);
    }
    else {
      if (*(int *)(iVar1 + 4) != 0) {
        FUN_00407df0();
        *(undefined4 *)(*(int *)(param_1 + 0x14) + 4) = 0;
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x14) = 0;
      iVar1 = *(int *)(param_1 + 0x18);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    else {
      if (*(int *)(iVar1 + 4) != 0) {
        FUN_00407df0();
        *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = 0;
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0x18) = 0;
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    if (iVar1 != 0) {
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return;
}

