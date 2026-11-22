// func _sensor_di_db_get_sensor_node_from_cached_list @ 004dc56c size=80

void _sensor_di_db_get_sensor_node_from_cached_list(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004081b0(&l_sensor_di_cached_sensor_list);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0xc);
    while ((param_1 != iVar2 && (iVar1 = FUN_00408680(iVar1), iVar1 != 0))) {
      iVar2 = *(int *)(iVar1 + 0xc);
    }
  }
  return;
}

