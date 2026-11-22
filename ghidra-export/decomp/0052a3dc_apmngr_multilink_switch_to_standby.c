// func apmngr_multilink_switch_to_standby @ 0052a3dc size=12

void apmngr_multilink_switch_to_standby(undefined2 param_1)

{
  apmngr_db_ap_ledsent_set(param_1,0);
  return;
}

