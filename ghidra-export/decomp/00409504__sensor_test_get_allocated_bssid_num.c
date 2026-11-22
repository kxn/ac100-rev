// func _sensor_test_get_allocated_bssid_num @ 00409504 size=308

int _sensor_test_get_allocated_bssid_num(undefined2 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined2 local_res0 [8];
  short local_7f8 [2];
  int local_7f4;
  int local_7f0 [500];
  
  iVar6 = 0;
  local_res0[0] = param_1;
  memset(local_7f0,0,2000);
  local_7f4 = 0;
  local_7f8[0] = 0;
  iVar1 = sensor_test_db_get_case_id_list_by_sensor(param_1,local_7f0,&local_7f4);
  if ((iVar1 == 0) && (piVar5 = local_7f0, local_7f4 != 0)) {
    for (iVar1 = 0; iVar1 < local_7f4; iVar1 = iVar1 + 1) {
      if ((((*piVar5 != param_2) &&
           (iVar2 = *(int *)(l_sensor_test_ssid_alloc_list + *piVar5 * 4), iVar2 != 0)) &&
          (iVar2 = *(int *)(iVar2 + 0x10), iVar2 != 0)) &&
         (((iVar2 = FUN_00407fa0(iVar2,local_res0), iVar2 != 0 &&
           (iVar3 = sensor_test_db_get_case_sch_period(*piVar5,local_7f8), iVar3 == 0)) &&
          (uVar4 = (uint)local_7f8[0], uVar4 != 0)))) {
        if (uVar4 == 0) {
          trap(7);
        }
        iVar6 = iVar6 + ((uint)*(ushort *)(iVar2 + 2) * 0x5a0) / uVar4;
      }
      piVar5 = piVar5 + 1;
    }
  }
  return iVar6;
}

