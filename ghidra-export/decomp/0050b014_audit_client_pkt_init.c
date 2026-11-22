// func audit_client_pkt_init @ 0050b014 size=252

int audit_client_pkt_init(void)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  char *local_20;
  undefined4 local_1c;
  code *local_18;
  undefined4 local_14;
  
  iVar1 = serv_msg_mngr_register(9,0x50,_audit_client_pkt_wtp_event_listener);
  if (iVar1 == 0) {
    local_14 = 0;
    local_20 = "audit_client";
    local_1c = 0xa000000;
    local_18 = _audit_client_access_notify;
    iVar2 = multi_link_reg(&local_20);
    if (iVar2 != -1) {
      return 0;
    }
    if (audit_err_switch != 0) {
      printf("[AUDIT_ERR]%s()/%d register callback to multi link failed.\n",
             "_audit_client_register_to_multilink",0x11a);
    }
    if (audit_err_switch == 0) {
      return 0;
    }
    __format = "[AUDIT_ERR]%s()/%d _audit_client_register_to_multilink failed.\n";
    uVar3 = 0x154;
  }
  else {
    if (audit_err_switch == 0) {
      return iVar1;
    }
    __format = "[AUDIT_ERR]%s()/%d register wtp event req for STATS_pkt module fail.\n";
    uVar3 = 0x14e;
  }
  printf(__format,"audit_client_pkt_init",uVar3);
  return iVar1;
}

