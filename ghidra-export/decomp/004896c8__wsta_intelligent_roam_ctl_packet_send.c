// func _wsta_intelligent_roam_ctl_packet_send @ 004896c8 size=220

undefined4 _wsta_intelligent_roam_ctl_packet_send(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  iVar2 = _wsta_intelligent_roam_ctl_packet_create(iVar1);
  if (iVar2 == -1) {
    if (wsta_roam_err_switch == '\0') goto LAB_0048972c;
    __format = "[WSTA_ROAM_ERROR]%s()/%d create packet failed\n";
    uVar3 = 0x9e4;
  }
  else {
    iVar2 = serv_packet_send(param_1,iVar1,1);
    if (iVar2 != -1) {
      cw_pkt_buf_destroy(iVar1);
      return 0;
    }
    if (wsta_roam_err_switch == '\0') goto LAB_0048972c;
    __format = "[WSTA_ROAM_ERROR]%s()/%d send packet failed.\n";
    uVar3 = 0x9e9;
  }
  printf(__format,"_wsta_intelligent_roam_ctl_packet_send",uVar3);
LAB_0048972c:
  cw_pkt_buf_destroy(iVar1);
  return 0xffffffff;
}

