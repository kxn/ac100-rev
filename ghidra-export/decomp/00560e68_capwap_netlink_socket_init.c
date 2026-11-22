// func capwap_netlink_socket_init @ 00560e68 size=252

undefined4 capwap_netlink_socket_init(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == (int *)0x0) {
    uVar3 = 0xffffffff;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","capwap_netlink_socket_init",300,"socket_fd");
  }
  else {
    iVar1 = socket(0x10,3,0);
    if (iVar1 < 0) {
      uVar3 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d create socket failed.\n","capwap_netlink_socket_init",0x131);
      }
    }
    else {
      *param_1 = iVar1;
      uVar3 = 0;
      if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_DEBUG]%32s():%4d socket[%d] created.\n","capwap_netlink_socket_init",0x137,iVar1
              );
      }
    }
  }
  return uVar3;
}

