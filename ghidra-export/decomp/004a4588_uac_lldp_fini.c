// func uac_lldp_fini @ 004a4588 size=60

void uac_lldp_fini(void)

{
  uac_lldp_pkt_uninit();
  if (uac_lldp_mutex != 0) {
    FUN_00408360();
    uac_lldp_mutex = 0;
  }
  return;
}

