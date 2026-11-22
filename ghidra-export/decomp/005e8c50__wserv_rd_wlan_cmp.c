// func _wserv_rd_wlan_cmp @ 005e8c50 size=56

bool _wserv_rd_wlan_cmp(int *param_1,int *param_2)

{
  if (((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) && (*param_1 == *param_2)) {
    return *(char *)(param_1 + 1) == *(char *)(param_2 + 1);
  }
  return false;
}

