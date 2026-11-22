// func wips_ap_multilink @ 004c69f0 size=52

undefined4 wips_ap_multilink(undefined2 param_1)

{
  wips_counter_reset_send(param_1);
  wips_counter_setting_send(param_1);
  return 0;
}

