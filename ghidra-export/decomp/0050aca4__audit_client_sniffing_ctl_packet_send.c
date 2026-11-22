// func _audit_client_sniffing_ctl_packet_send @ 0050aca4 size=220

undefined4 _audit_client_sniffing_ctl_packet_send(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  iVar2 = _audit_client_sniffing_ctl_packet_create(iVar1);
  if (iVar2 == -1) {
    if (audit_err_switch == 0) goto LAB_0050ad08;
    __format = "[AUDIT_ERR]%s()/%d create packet failed\n";
    uVar3 = 0xcd;
  }
  else {
    iVar2 = serv_packet_send(param_1,iVar1,1);
    if (iVar2 != -1) {
      cw_pkt_buf_destroy(iVar1);
      return 0;
    }
    if (audit_err_switch == 0) goto LAB_0050ad08;
    __format = "[AUDIT_ERR]%s()/%d send packet failed.\n";
    uVar3 = 0xd2;
  }
  printf(__format,"_audit_client_sniffing_ctl_packet_send",uVar3);
LAB_0050ad08:
  cw_pkt_buf_destroy(iVar1);
  return 0xffffffff;
}

