// func uac_wservice_ap_enter_run @ 005dd9fc size=28

void uac_wservice_ap_enter_run(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    wserv_db_ap_enter_run(param_1,param_2,_uac_wserv_add_cb);
    return;
  }
  wserv_db_ap_enter_run(param_1,param_2,_uac_wserv_packet_type_init_cb);
  return;
}

