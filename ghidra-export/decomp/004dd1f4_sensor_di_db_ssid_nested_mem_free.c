// func sensor_di_db_ssid_nested_mem_free @ 004dd1f4 size=120

void sensor_di_db_ssid_nested_mem_free(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = 0, *(int *)(param_1 + 0x40) != 0)) {
    for (; iVar1 < *(short *)(param_1 + 0x3c); iVar1 = iVar1 + 1) {
      sensor_di_db_bssid_nested_mem_free(*(int *)(param_1 + 0x40) + iVar1 * 0xf8);
    }
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  return;
}

