// func stats_db_ctl_rssi_register @ 0066bfd0 size=156

void stats_db_ctl_rssi_register(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    FUN_004082d0(l_stats_data,0xffffffff);
    iVar1 = rssi_reg_num;
    piVar2 = &rssi_switch_fun + rssi_reg_num;
    rssi_reg_num = rssi_reg_num + 1;
    *piVar2 = param_1;
    (&rssi_interval_fun)[iVar1] = param_2;
    FUN_00407f30(l_stats_data);
    return;
  }
  return;
}

