// func cw_priv_sub_device_report_length @ 005c8670 size=28

uint cw_priv_sub_device_report_length(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(int *)(param_1 + 4) + 8U & 0xffff;
  }
  return uVar1;
}

