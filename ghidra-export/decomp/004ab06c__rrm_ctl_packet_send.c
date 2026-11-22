// func _rrm_ctl_packet_send @ 004ab06c size=300

undefined4
_rrm_ctl_packet_send
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5,
          char param_6)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  iVar2 = _rrm_ctl_packet_create(iVar1,param_2,param_3,param_4,(int)param_5,(int)param_6);
  if (iVar2 == -1) {
    if (rrm_err_switch == '\0') goto LAB_004ab10c;
    __format = "[RRM_ERROR]%s()/%d create packet failed\n";
    uVar3 = 0x1f9;
  }
  else {
    iVar2 = serv_packet_send(param_1,iVar1,1);
    if (iVar2 != -1) {
      cw_pkt_buf_destroy(iVar1);
      return 0;
    }
    if (rrm_err_switch == '\0') goto LAB_004ab10c;
    __format = "[RRM_ERROR]%s()/%d send packet failed.\n";
    uVar3 = 0x1fe;
  }
  printf(__format,"_rrm_ctl_packet_send",uVar3);
LAB_004ab10c:
  cw_pkt_buf_destroy(iVar1);
  return 0xffffffff;
}

