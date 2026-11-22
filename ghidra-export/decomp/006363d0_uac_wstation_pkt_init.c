// func uac_wstation_pkt_init @ 006363d0 size=140

int uac_wstation_pkt_init(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = serv_msg_mngr_register(9,100,_uac_wsta_pkt_wtp_event_listener);
  if (iVar1 == 0) {
    FUN_0051ad88(&l_wsta_assoc_check_reg);
  }
  else if ((g_wsta_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wsta>[error]%s(): %d  -> register wtp event req for wstation module fail.\r\n",
           "uac_wstation_pkt_init",0x3dd);
  }
  return iVar1;
}

