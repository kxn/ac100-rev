// func uac_wservice_get_ap_radio_cnt @ 005db850 size=116

int uac_wservice_get_ap_radio_cnt(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = apdb_radio_count_by_id();
  if (((iVar1 == -1) && (g_wserv_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[error]%s(): %d  -> apdb_radio_count_by_id() fail.\r\n",
           "uac_wservice_get_ap_radio_cnt",0x1430);
  }
  return iVar1;
}

