// func _online_sensor_id_collect @ 004e3218 size=168

undefined4 _online_sensor_id_collect(int param_1,int *param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x3c) != 0) && (*(int *)(param_1 + 0x2ac) - 2U < 2)) {
    iVar1 = multi_link_status_get(*(undefined2 *)(param_1 + 0x10));
    if (iVar1 == 0) {
      return 0;
    }
    if (param_2 == (int *)0x0) {
      return 2;
    }
    iVar1 = *param_2;
    if (param_2[1] <= iVar1) {
      return 2;
    }
    *(undefined2 *)(param_2[2] + iVar1 * 2) = *(undefined2 *)(param_1 + 0x10);
    *param_2 = iVar1 + 1;
  }
  return 0;
}

