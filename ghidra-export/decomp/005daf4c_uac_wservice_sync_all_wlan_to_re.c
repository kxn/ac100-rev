// func uac_wservice_sync_all_wlan_to_re @ 005daf4c size=44

undefined4 uac_wservice_sync_all_wlan_to_re(void)

{
  apmngr_db_foreach_proc(0xe0000,_uac_wserv_sync_wlan_to_re,0);
  return 0;
}

