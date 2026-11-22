// func capwap_socket_sendbuffer_set @ 005610b8 size=340

undefined4 capwap_socket_sendbuffer_set(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_res4 [3];
  int local_18 [3];
  
  local_18[1] = 4;
  local_18[0] = 0;
  local_res4[0] = param_2;
  iVar1 = setsockopt(param_1,0xffff,0x1001,local_res4,4);
  if (iVar1 == -1) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x16f;
  }
  else {
    iVar1 = getsockopt(param_1,0xffff,0x1001,local_18,(socklen_t *)(local_18 + 1));
    if (iVar1 != -1) {
      if (local_18[0] == local_res4[0] << 1) {
        return 0;
      }
      if (capwap_err_switch == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      printf("[CW_ERROR]%32s():%4d setsockopt(SO_SNDBUF) fail. send_buf_len=%d,need to be set %d\n\n"
             ,"capwap_socket_sendbuffer_set",0x17b,local_18[0],local_res4[0]);
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x175;
  }
  printf("[CW_ERROR]%32s():%4d socket[%d] set recv buf failed.\n","capwap_socket_sendbuffer_set",
         uVar2,param_1);
  return 0xffffffff;
}

