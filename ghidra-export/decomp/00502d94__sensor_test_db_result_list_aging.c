// func _sensor_test_db_result_list_aging @ 00502d94 size=132

undefined4 _sensor_test_db_result_list_aging(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    iVar2 = FUN_004081b0();
    while (uVar1 = 0, iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      if (param_2 <= *(uint *)(iVar2 + 0x2c)) {
        return 0;
      }
      FUN_00408500(iVar2);
      sensor_test_db_result_unit_node_mem_free(iVar2);
      iVar2 = iVar3;
    }
  }
  return uVar1;
}

