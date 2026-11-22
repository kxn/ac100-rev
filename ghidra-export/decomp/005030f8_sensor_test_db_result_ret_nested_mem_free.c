// func sensor_test_db_result_ret_nested_mem_free @ 005030f8 size=68

void sensor_test_db_result_ret_nested_mem_free(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 100) != 0)) {
    sensor_test_db_detail_result_nested_mem_free();
    FUN_00407df0(*(undefined4 *)(param_1 + 100));
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return;
}

