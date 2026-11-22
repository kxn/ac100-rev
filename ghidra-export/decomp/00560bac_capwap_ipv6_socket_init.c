// func capwap_ipv6_socket_init @ 00560bac size=700

undefined4 capwap_ipv6_socket_init(int *param_1)

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
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","capwap_ipv6_socket_init",0x101,"socket_fd");
  }
  else {
    iVar1 = socket(10,1,0);
    if (iVar1 < 0) {
      uVar4 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d create socket failed.\n","capwap_ipv6_socket_init",0x106);
      }
    }
    else {
      uVar4 = 0xffffffff;
      iVar2 = setsockopt(iVar1,0x29,0x31,local_20,4);
      if (iVar2 == -1) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        __format = "[CW_ERROR]%32s():%4d socket[%d] set IPV6_RECVPKTINFO failed.\n";
        uVar3 = 0x10b;
      }
      else {
        iVar2 = setsockopt(iVar1,0x29,0x3a,local_20,4);
        if (iVar2 == -1) {
          uVar4 = 0xffffffff;
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          __format = "[CW_ERROR]%32s():%4d socket[%d] set IPV6_RECVDSTOPTS failed.\n";
          uVar3 = 0x110;
        }
        else {
          iVar2 = setsockopt(iVar1,0x29,0x38,local_20,4);
          if (iVar2 == -1) {
            uVar4 = 0xffffffff;
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              return 0xffffffff;
            }
            __format = "[CW_ERROR]%32s():%4d socket[%d] set IPV6_RECVRTHDR failed.\n";
            uVar3 = 0x115;
          }
          else {
            iVar2 = setsockopt(iVar1,0xffff,4,local_20,4);
            if (iVar2 == -1) {
              uVar4 = 0xffffffff;
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar2 = is_target_debug_ap();
              if (iVar2 == 0) {
                return 0xffffffff;
              }
              __format = "[CW_ERROR]%32s():%4d socket[%d] set SO_REUSEADDR failed.\n";
              uVar3 = 0x11a;
            }
            else {
              iVar2 = setsockopt(iVar1,0x29,0x1a,local_20,4);
              if (iVar2 == -1) {
                uVar4 = 0xffffffff;
                if (capwap_err_switch == 0) {
                  return 0xffffffff;
                }
                iVar2 = is_target_debug_ap();
                if (iVar2 == 0) {
                  return 0xffffffff;
                }
                __format = "[CW_ERROR]%32s():%4d socket[%d] set IPV6_V6ONLY failed.\n";
                uVar3 = 0x11f;
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
                uVar3 = 0x124;
              }
            }
          }
        }
      }
      printf(__format,"capwap_ipv6_socket_init",uVar3,iVar1);
    }
  }
  return uVar4;
}

