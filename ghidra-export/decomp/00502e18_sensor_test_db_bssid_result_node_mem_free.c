// func sensor_test_db_bssid_result_node_mem_free @ 00502e18 size=736

void sensor_test_db_bssid_result_node_mem_free(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x95) == '\0') {
    cVar1 = *(char *)(param_1 + 0x96);
  }
  else {
    iVar3 = 0;
    if (*(int *)(param_1 + 0x84) != 0) {
      for (; iVar3 < (int)(uint)*(byte *)(param_1 + 0x95); iVar3 = iVar3 + 1) {
        iVar2 = *(int *)(param_1 + 0x84);
        while (iVar2 = FUN_004081b0(iVar2 + iVar3 * 0xc), iVar2 != 0) {
          FUN_00408500(iVar2);
          sensor_test_db_result_unit_node_mem_free(iVar2);
          iVar2 = *(int *)(param_1 + 0x84);
        }
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x84));
      *(undefined4 *)(param_1 + 0x84) = 0;
    }
    cVar1 = *(char *)(param_1 + 0x96);
  }
  if (cVar1 == '\0') {
    cVar1 = *(char *)(param_1 + 0x97);
  }
  else {
    iVar3 = 0;
    if (*(int *)(param_1 + 0x88) != 0) {
      for (; iVar3 < (int)(uint)*(byte *)(param_1 + 0x96); iVar3 = iVar3 + 1) {
        iVar2 = *(int *)(param_1 + 0x88);
        while (iVar2 = FUN_004081b0(iVar2 + iVar3 * 0xc), iVar2 != 0) {
          FUN_00408500(iVar2);
          sensor_test_db_result_unit_node_mem_free(iVar2);
          iVar2 = *(int *)(param_1 + 0x88);
        }
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x88));
      *(undefined4 *)(param_1 + 0x88) = 0;
    }
    cVar1 = *(char *)(param_1 + 0x97);
  }
  if (cVar1 == '\0') {
    cVar1 = *(char *)(param_1 + 0x98);
  }
  else {
    iVar3 = 0;
    if (*(int *)(param_1 + 0x8c) != 0) {
      for (; iVar3 < (int)(uint)*(byte *)(param_1 + 0x97); iVar3 = iVar3 + 1) {
        iVar2 = *(int *)(param_1 + 0x8c);
        while (iVar2 = FUN_004081b0(iVar2 + iVar3 * 0xc), iVar2 != 0) {
          FUN_00408500(iVar2);
          sensor_test_db_result_unit_node_mem_free(iVar2);
          iVar2 = *(int *)(param_1 + 0x8c);
        }
      }
      FUN_00407df0(*(undefined4 *)(param_1 + 0x8c));
      *(undefined4 *)(param_1 + 0x8c) = 0;
    }
    cVar1 = *(char *)(param_1 + 0x98);
  }
  if ((cVar1 != '\0') && (iVar3 = 0, *(int *)(param_1 + 0x90) != 0)) {
    for (; iVar3 < (int)(uint)*(byte *)(param_1 + 0x98); iVar3 = iVar3 + 1) {
      iVar2 = *(int *)(param_1 + 0x90);
      while (iVar2 = FUN_004081b0(iVar2 + iVar3 * 0xc), iVar2 != 0) {
        FUN_00408500(iVar2);
        sensor_test_db_result_unit_node_mem_free(iVar2);
        iVar2 = *(int *)(param_1 + 0x90);
      }
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x90));
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  while (iVar3 = FUN_004081b0(param_1 + 0x48), iVar3 != 0) {
    FUN_00408500(iVar3);
    sensor_test_db_result_unit_node_mem_free(iVar3);
  }
  while (iVar3 = FUN_004081b0(param_1 + 0x54), iVar3 != 0) {
    FUN_00408500(iVar3);
    sensor_test_db_result_unit_node_mem_free(iVar3);
  }
  while (iVar3 = FUN_004081b0(param_1 + 0x6c), iVar3 != 0) {
    FUN_00408500(iVar3);
    sensor_test_db_result_unit_node_mem_free(iVar3);
  }
  while (iVar3 = FUN_004081b0(param_1 + 0x78), iVar3 != 0) {
    FUN_00408500(iVar3);
    sensor_test_db_result_unit_node_mem_free(iVar3);
  }
  while (iVar3 = FUN_004081b0(param_1 + 0x60), iVar3 != 0) {
    FUN_00408500(iVar3);
    sensor_test_db_result_unit_node_mem_free(iVar3);
  }
  FUN_00407df0(param_1);
  return;
}

