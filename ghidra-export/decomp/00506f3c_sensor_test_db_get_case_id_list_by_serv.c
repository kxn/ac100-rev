// func sensor_test_db_get_case_id_list_by_serv @ 00506f3c size=272

undefined4 sensor_test_db_get_case_id_list_by_serv(int param_1,int param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  uVar1 = 0xffffffff;
  if ((param_2 != 0) && (param_3 != (uint *)0x0)) {
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    uVar3 = 0;
    uVar2 = 0;
    piVar5 = l_sensor_test_case_list;
LAB_00506f94:
    uVar1 = l_sensor_test_db_mutex;
    if (uVar3 < g_sensor_test_case_num_max) {
      if ((*piVar5 != 0) && (iVar6 = *(int *)(*piVar5 + 4), iVar6 != 0)) {
        iVar4 = 0;
        if (*(byte *)(iVar6 + 0xb) != 0) {
          for (; iVar4 < (int)(uint)*(byte *)(iVar6 + 0xb); iVar4 = iVar4 + 1) {
            if (*(int *)(*(int *)(iVar6 + 0x38) + iVar4 * 0x220) == param_1) {
              if (uVar2 < g_sensor_test_case_num_max) {
                iVar6 = uVar2 * 4;
                piVar5 = piVar5 + 1;
                uVar2 = uVar2 + 1;
                *(uint *)(param_2 + iVar6) = uVar3;
                uVar3 = uVar3 + 1;
                goto LAB_00506f94;
              }
              break;
            }
          }
        }
      }
      uVar3 = uVar3 + 1;
      piVar5 = piVar5 + 1;
      goto LAB_00506f94;
    }
    *param_3 = uVar2;
    FUN_00407f30(uVar1);
    uVar1 = 0;
  }
  return uVar1;
}

