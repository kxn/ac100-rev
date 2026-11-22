// func _stats_sta_ssid_leave_handle @ 0066883c size=136

void _stats_sta_ssid_leave_handle(int param_1,short *param_2)

{
  int extraout_v1;
  
  FUN_00407e70();
  if ((((param_1 != 0) && (param_2 != (short *)0x0)) && (*(short *)(param_1 + 8) == *param_2)) &&
     (param_2[1] == *(short *)(param_1 + 10))) {
    *(int *)(param_1 + 0x40) = stat_sample_report_time + 5 + extraout_v1;
    *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xfc | 8;
  }
  return;
}

