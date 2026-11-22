// func _ac_cmcc_send_pkt @ 00435b98 size=320

undefined4 _ac_cmcc_send_pkt(uint *param_1,int *param_2,int param_3,int param_4)

{
  ssize_t sVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(short *)((int)param_1 + 0xe) = (short)(param_4 << 8);
  *param_1 = param_3 << 0x10 | *param_1 & 0xff00ffff;
  if (*param_2 == 1) {
    sVar1 = sendto(cmcc_sockfd,param_1,0x10,0,(sockaddr *)(param_2 + 1),0x10);
    if (-1 < sVar1) {
      return 0;
    }
    if (wportal_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar3 = 0xf7;
  }
  else {
    if (*param_2 != 2) {
      return 0;
    }
    sVar1 = sendto(cmcc_sockfd_v6,param_1,0x10,0,(sockaddr *)(param_2 + 1),0x1c);
    if (-1 < sVar1) {
      return 0;
    }
    if (wportal_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar3 = 0x100;
  }
  printf("[WPORTAL_DBG]%s()/%d Send error\n","_ac_cmcc_send_pkt",uVar3);
  return 0xffffffff;
}

