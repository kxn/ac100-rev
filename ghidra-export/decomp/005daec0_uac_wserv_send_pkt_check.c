// func uac_wserv_send_pkt_check @ 005daec0 size=140

undefined4 uac_wserv_send_pkt_check(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char local_18 [8];
  
  iVar3 = 0;
  local_18[0] = '\0';
  FUN_004082d0(DAT_007598e4,0xffffffff);
  do {
    iVar1 = apmngr_db_get_ap_max();
    if (iVar1 <= iVar3) {
      uVar2 = 0;
      goto LAB_005daf28;
    }
    iVar1 = _uac_wserv_packet_waiting_status_get_by_ap_id(iVar3,local_18);
    iVar3 = iVar3 + 1;
  } while ((iVar1 != 0) || (local_18[0] == '\0'));
  uVar2 = 1;
LAB_005daf28:
  FUN_00407f30(DAT_007598e4);
  return uVar2;
}

