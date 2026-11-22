// func sensor_id_db_pkt_stat_mem_free @ 004dd26c size=148

void sensor_id_db_pkt_stat_mem_free(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    for (; iVar1 < *(short *)(param_1 + 6); iVar1 = iVar1 + 1) {
      sensor_di_db_ssid_nested_mem_free(*(int *)(param_1 + 0x14) + iVar1 * 0x44);
    }
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  FUN_00407df0(param_1);
  return;
}

