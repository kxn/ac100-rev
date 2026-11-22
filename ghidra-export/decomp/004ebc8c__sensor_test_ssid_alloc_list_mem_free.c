// func _sensor_test_ssid_alloc_list_mem_free @ 004ebc8c size=312

void _sensor_test_ssid_alloc_list_mem_free(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else if (*(int *)(param_1 + 4) == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      iVar1 = 0;
      if (*(int *)(param_1 + 0xc) != 0) {
        for (; iVar1 < *(int *)(param_1 + 4); iVar1 = iVar1 + 1) {
          iVar2 = *(int *)(param_1 + 8);
          while (iVar2 = FUN_004081b0(iVar2 + iVar1 * 0x14 + 8), iVar2 != 0) {
            FUN_00408500(iVar2);
            FUN_00407f40(*(undefined4 *)(param_1 + 0xc),iVar2);
            FUN_00407df0(iVar2);
            iVar2 = *(int *)(param_1 + 8);
          }
        }
        FUN_00408310(*(undefined4 *)(param_1 + 0xc));
        *(undefined4 *)(param_1 + 0xc) = 0;
        FUN_00407df0(*(undefined4 *)(param_1 + 8));
        *(undefined4 *)(param_1 + 8) = 0;
      }
      iVar1 = *(int *)(param_1 + 0xc);
    }
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x10);
    }
    else {
      FUN_00408310();
      *(undefined4 *)(param_1 + 0xc) = 0;
      iVar1 = *(int *)(param_1 + 0x10);
    }
    if (iVar1 != 0) {
      FUN_00408570(iVar1,_sensor_test_delete_sensor_alloc_hash_cb,iVar1);
      FUN_00408310(*(undefined4 *)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    FUN_00407df0(param_1);
    return;
  }
  return;
}

