// func uac_wserv_packet_dump_all @ 005dae48 size=1

void uac_wserv_packet_dump_all(void)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(DAT_007598e4,0xffffffff);
  puts("*******************************************");
  for (iVar2 = 0; iVar1 = apmngr_db_get_ap_max(), iVar2 < iVar1; iVar2 = iVar2 + 1) {
    uac_wserv_packet_dump_by_id(iVar2);
  }
  puts("*********************END*******************");
  uac_mutex_give(DAT_007598e4);
  return;
}

