// func sensor_db_entry_free @ 004d0cf4 size=84

void sensor_db_entry_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x10) == 0) {
      iVar1 = *(int *)(param_1 + 0x14);
    }
    else {
      *(undefined2 *)(param_1 + 0xc) = 0;
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x10) = 0;
      iVar1 = *(int *)(param_1 + 0x14);
    }
    if (iVar1 != 0) {
      *(undefined2 *)(param_1 + 0xe) = 0;
      FUN_00407df0();
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
  }
  return;
}

