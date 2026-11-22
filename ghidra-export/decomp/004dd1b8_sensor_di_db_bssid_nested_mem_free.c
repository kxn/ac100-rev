// func sensor_di_db_bssid_nested_mem_free @ 004dd1b8 size=60

void sensor_di_db_bssid_nested_mem_free(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0xf4) != 0)) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0xf4) = 0;
  }
  return;
}

