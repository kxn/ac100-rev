// func _audit_client_access_notify @ 0050ad80 size=376

undefined4 _audit_client_access_notify(undefined2 param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_2f8;
  undefined4 local_2f4;
  int local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == -1) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[AUDIT_ERR]%s()/%d get ap entry by id failed.\n";
    uVar4 = 0xec;
LAB_0050aec4:
    printf(pcVar2,"_audit_client_access_notify",uVar4);
    return 0xffffffff;
  }
  iVar1 = serv_wtp_address_arg_init(&local_2f8);
  if (iVar1 == -1) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[AUDIT_ERR]%s()/%d serv arg init failed\n";
    uVar4 = 0xf3;
    goto LAB_0050aec4;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(local_2d8,&local_2f8,1,1,0x15f0000,1,0x29);
  if ((iVar1 == -1) || (local_2f0 == 0)) {
    uVar4 = 0;
    if (audit_debug_switch == 0) goto LAB_0050ae2c;
    pcVar2 = "[AUDIT_DBG]%s()/%d no AP need to send configure\n";
    uVar3 = 0xf9;
  }
  else {
    uVar4 = 0;
    iVar1 = _audit_client_sniffing_ctl_packet_send(&local_2f8);
    if ((iVar1 != -1) || (uVar4 = 0xffffffff, audit_err_switch == 0)) goto LAB_0050ae2c;
    pcVar2 = "[AUDIT_ERR]%s()/%d send packet to AP failed\n";
    uVar3 = 0x100;
  }
  printf(pcVar2,"_audit_client_access_notify",uVar3);
LAB_0050ae2c:
  serv_wtp_address_arg_destroy(&local_2f8);
  return uVar4;
}

