// func cloud_mngt_client_data_free @ 0048beb8 size=80

void cloud_mngt_client_data_free(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  FUN_00407df0(param_1);
  return;
}

