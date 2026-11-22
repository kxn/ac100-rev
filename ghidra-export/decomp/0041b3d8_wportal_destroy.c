// func wportal_destroy @ 0041b3d8 size=200

undefined4 wportal_destroy(void)

{
  FUN_00408060(free_strategy_timer);
  FUN_004082d0(wportal_free_strategy_packet_mutex,0xffffffff);
  serv_wtp_address_arg_destroy(&free_strategy_arg);
  serv_wtp_address_arg_destroy(&free_strategy_arg_nosupp);
  serv_wtp_address_arg_destroy(&free_strategy_arg_v6);
  FUN_00407f30(wportal_free_strategy_packet_mutex);
  FUN_00408360(wportal_free_strategy_packet_mutex);
  wportal_free_strategy_packet_mutex = 0;
  FUN_00408360(wportal_update_rdt_ftt_mutex);
  wportal_update_rdt_ftt_mutex = 0;
  FUN_00408220(wportal_update_rdt_ftt_cond);
  wportal_update_rdt_ftt_cond = 0;
  if (g_wportal_update_rdt_ftt_thread != 0) {
    pthread_kill(g_wportal_update_rdt_ftt_thread,3);
    g_wportal_update_rdt_ftt_thread = 0;
  }
  wportal_db_destroy();
  ac_cmcc_portal_deInit();
  sso_notify_deInit();
  return 0;
}

