// func sensor_test_db_is_change_id_equal @ 00506700 size=164

bool sensor_test_db_is_change_id_equal(uint param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((-1 < (int)param_1) && (param_1 < g_sensor_test_case_num_max)) {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    iVar1 = *(int *)(l_sensor_test_case_list + param_1 * 4);
    if (iVar1 != 0) {
      bVar2 = *(byte *)(*(int *)(iVar1 + 4) + 8) == param_2;
    }
    FUN_00407f30(l_sensor_test_db_mutex);
  }
  return bVar2;
}

