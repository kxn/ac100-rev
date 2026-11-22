// func cw_wtp_reboot_statistics_length @ 00586720 size=12

undefined4 cw_wtp_reboot_statistics_length(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xf;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

