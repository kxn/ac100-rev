// func sensor_test_db_result_unit_node_mem_free @ 00502d3c size=88

void sensor_test_db_result_unit_node_mem_free(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    sensor_test_db_detail_result_nested_mem_free();
    FUN_00407df0(*(undefined4 *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  FUN_00407df0(param_1);
  return;
}

