// func capwap_socket_bind @ 0056120c size=284

undefined4 capwap_socket_bind(int param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  sockaddr local_48;
  undefined1 auStack_38 [36];
  
  memset(auStack_38,0,0x20);
  local_48.sa_data[6] = '\0';
  local_48.sa_data[7] = '\0';
  local_48.sa_data[8] = '\0';
  local_48.sa_data[9] = '\0';
  local_48.sa_data[10] = '\0';
  local_48.sa_data[0xb] = '\0';
  local_48.sa_data[0xc] = '\0';
  local_48.sa_data[0xd] = '\0';
  local_48.sa_family = 2;
  local_48.sa_data._0_2_ = param_3;
  local_48.sa_data._2_4_ = param_2;
  iVar1 = bind(param_1,&local_48,0x10);
  if (iVar1 < 0) {
    uVar3 = 0xffffffff;
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d socket[%d] failed to bind %u:%d\n";
    uVar2 = 0x199;
  }
  else {
    uVar3 = 0;
    if (capwap_debug_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    param_2 = capwap_socket_addr_to_string(&local_48,0,auStack_38,0x20);
    __format = "[CW_DEBUG]%32s():%4d socket[%d] bind to %s\n";
    uVar2 = 0x19d;
  }
  printf(__format,"capwap_socket_bind",uVar2,param_1,param_2);
  return uVar3;
}

