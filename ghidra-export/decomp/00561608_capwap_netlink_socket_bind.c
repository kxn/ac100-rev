// func capwap_netlink_socket_bind @ 00561608 size=156

undefined4 capwap_netlink_socket_bind(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  sockaddr local_20;
  
  local_20.sa_family = 0x10;
  local_20.sa_data[0] = '\0';
  local_20.sa_data[1] = '\0';
  uVar2 = 0;
  local_20.sa_data[2] = '\0';
  local_20.sa_data[3] = '\0';
  local_20.sa_data[4] = '\0';
  local_20.sa_data[5] = '\0';
  local_20.sa_data[6] = '\0';
  local_20.sa_data[7] = '\0';
  local_20.sa_data[8] = '\x01';
  local_20.sa_data[9] = '\x01';
  iVar1 = bind(param_1,&local_20,0xc);
  if (((iVar1 < 0) && (uVar2 = 0xffffffff, capwap_err_switch != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_ERROR]%32s():%4d socket[%d] failed to bind\n","capwap_netlink_socket_bind",0x1e4,
           param_1);
  }
  return uVar2;
}

