// func uac_wstation_pkt_uninit @ 0063645c size=192

int uac_wstation_pkt_uninit(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004081b0(&l_wsta_assoc_check_reg);
  while (iVar1 != 0) {
    iVar2 = FUN_00408680(iVar1);
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
    iVar1 = iVar2;
  }
  iVar1 = serv_msg_mngr_unregister(9,100,_uac_wsta_pkt_wtp_event_listener);
  if (((iVar1 != 0) && (g_wsta_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wsta>[error]%s(): %d  -> unregister wtp event req for wstation module fail.\r\n",
           "uac_wstation_pkt_uninit",0x3fa);
  }
  return iVar1;
}

