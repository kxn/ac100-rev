// func capwap_socket_init @ 005609ec size=448

undefined4 capwap_socket_init(int *param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_20 [3];
  
  local_20[0] = 1;
  if (param_1 == (int *)0x0) {
    uVar4 = 0xffffffff;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","capwap_socket_init",0xe2,"socket_fd");
  }
  else {
    iVar1 = socket(2,1,0);
    if (iVar1 < 0) {
      uVar4 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d create socket failed.\n","capwap_socket_init",0xe7);
      }
    }
    else {
      uVar4 = 0xffffffff;
      iVar2 = setsockopt(iVar1,0,8,local_20,4);
      if (iVar2 == -1) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        __format = "[CW_ERROR]%32s():%4d socket[%d] set PKTINFO failed.\n";
        uVar3 = 0xec;
      }
      else {
        iVar2 = setsockopt(iVar1,0xffff,0x20,local_20,4);
        if (iVar2 == -1) {
          uVar4 = 0xffffffff;
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          __format = "[CW_ERROR]%32s():%4d socket[%d] set broadcast failed.\n";
          uVar3 = 0xf1;
        }
        else {
          *param_1 = iVar1;
          uVar4 = 0;
          if (capwap_debug_switch == 0) {
            return 0;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0;
          }
          __format = "[CW_DEBUG]%32s():%4d socket[%d] created.\n";
          uVar3 = 0xf7;
        }
      }
      printf(__format,"capwap_socket_init",uVar3,iVar1);
    }
  }
  return uVar4;
}

