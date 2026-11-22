// func _apdb_expired_unsupport_ap_collect @ 0060ed50 size=108

void _apdb_expired_unsupport_ap_collect(int param_1,int *param_2)

{
  if ((((param_1 != 0) && (param_2 != (int *)0x0)) && (param_2[3] != 0)) &&
     (((*param_2 < param_2[1] && (*(int *)(param_1 + 0x48) < param_2[2])) &&
      (299 < param_2[2] - *(int *)(param_1 + 0x48))))) {
    *(int *)(param_2[3] + *param_2 * 4) = param_1;
    *param_2 = *param_2 + 1;
  }
  return;
}

