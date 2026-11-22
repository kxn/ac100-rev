// func _stats_ctl_packet_send @ 00674400 size=220

undefined4 _stats_ctl_packet_send(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  iVar2 = _stats_ctl_packet_create(iVar1);
  if (iVar2 == -1) {
    if (stats_err_switch == '\0') goto LAB_00674464;
    __format = "[STATISTICS_ERROR]%s()/%d create packet failed\n";
    uVar3 = 0x1d6;
  }
  else {
    iVar2 = serv_packet_send(param_1,iVar1,1);
    if (iVar2 != -1) {
      cw_pkt_buf_destroy(iVar1);
      return 0;
    }
    if (stats_err_switch == '\0') goto LAB_00674464;
    __format = "[STATISTICS_ERROR]%s()/%d send packet failed.\n";
    uVar3 = 0x1db;
  }
  printf(__format,"_stats_ctl_packet_send",uVar3);
LAB_00674464:
  cw_pkt_buf_destroy(iVar1);
  return 0xffffffff;
}

