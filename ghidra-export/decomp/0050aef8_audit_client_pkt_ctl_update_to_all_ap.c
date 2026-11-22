// func audit_client_pkt_ctl_update_to_all_ap @ 0050aef8 size=284

undefined4 audit_client_pkt_ctl_update_to_all_ap(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_20);
  if (iVar1 == -1) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[AUDIT_ERR]%s()/%d serv arg init failed\n","audit_client_pkt_ctl_update_to_all_ap",0x12d
          );
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_all_addr_by_capacity(&local_20,1,1,0x15f0000,1,0x29);
  if ((iVar1 == -1) || (local_18 == 0)) {
    uVar3 = 0;
    if (audit_debug_switch == 0) goto LAB_0050af70;
    __format = "[AUDIT_DBG]%s()/%d no AP need to send configure\n";
    uVar2 = 0x133;
  }
  else {
    uVar3 = 0;
    iVar1 = _audit_client_sniffing_ctl_packet_send(&local_20);
    if ((iVar1 != -1) || (uVar3 = 0xffffffff, audit_err_switch == 0)) goto LAB_0050af70;
    __format = "[AUDIT_ERR]%s()/%d send packet to AP failed\n";
    uVar2 = 0x13a;
  }
  printf(__format,"audit_client_pkt_ctl_update_to_all_ap",uVar2);
LAB_0050af70:
  serv_wtp_address_arg_destroy(&local_20);
  return uVar3;
}

