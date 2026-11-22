// func sensor_test_db_wserv_id_update @ 005048d8 size=228

undefined4 sensor_test_db_wserv_id_update(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0xffffffff;
  if (((param_2 != (int *)0x0) && (0 < param_3)) && (param_1 != 0)) {
    iVar4 = 0;
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    iVar3 = *param_2;
    while( true ) {
      iVar1 = l_sensor_test_case_list;
      iVar3 = *(int *)(l_sensor_test_case_list + iVar3 * 4);
      if (iVar3 == 0) {
        iVar3 = *param_2;
      }
      else {
        iVar3 = *(int *)(iVar3 + 4);
        if (iVar3 == 0) {
          iVar3 = *param_2;
        }
        else {
          *(char *)(iVar3 + 8) = *(char *)(iVar3 + 8) + '\x01';
          iVar3 = *param_2;
        }
      }
      iVar4 = iVar4 + 1;
      param_2 = param_2 + 1;
      uVar2 = _sensor_test_db_deep_copy_test_case(*(undefined4 *)(iVar1 + iVar3 * 4));
      sensor_test_db_msg_send(2,uVar2);
      if (iVar4 == param_3) break;
      iVar3 = *param_2;
    }
    FUN_00407f30(l_sensor_test_db_mutex);
    uVar2 = 0;
  }
  return uVar2;
}

