// func _audit_client_sniffing_ctl_packet_create @ 0050ab34 size=368

undefined4 _audit_client_sniffing_ctl_packet_create(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 local_50;
  undefined2 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34 [3];
  undefined1 uStack_31;
  undefined2 uStack_16;
  
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_50 = 0;
  local_4c = 0;
  memset(local_34,0,0x24);
  iVar1 = cw_parsed_pkt_create(7);
  if (iVar1 == 0) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[AUDIT_ERR]%s()/%d cw_parsed_pkt_create failed\n",
           "_audit_client_sniffing_ctl_packet_create",0x98);
    return 0xffffffff;
  }
  FUN_0051ad88(&local_40);
  audit_client_db_server_get(local_34);
  local_50 = CONCAT13(uStack_31,local_50._1_3_);
  local_50 = CONCAT22(local_50._0_2_,uStack_16);
  iVar2 = cw_service_msg_add(iVar1,0x25,&local_48,1,0x6d,&local_50);
  if (iVar2 == 0) {
    iVar2 = capwap_packet_assemble(param_1,iVar1);
    if (iVar2 != -1) {
      cw_parsed_pkt_destroy(iVar1);
      return 0;
    }
    if (audit_err_switch == 0) goto LAB_0050abe8;
    __format = "[AUDIT_ERR]%s()/%d capwap_packet_assemble failed\n";
    uVar3 = 0xae;
  }
  else {
    if (audit_err_switch == 0) goto LAB_0050abe8;
    __format = "[AUDIT_ERR]%s()/%d cw_service_msg_add failed\n";
    uVar3 = 0xa6;
  }
  printf(__format,"_audit_client_sniffing_ctl_packet_create",uVar3);
LAB_0050abe8:
  cw_parsed_pkt_destroy(iVar1);
  return 0xffffffff;
}

