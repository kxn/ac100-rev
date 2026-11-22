// func ac_cmcc_port_set @ 00439f50 size=1016

undefined4 ac_cmcc_port_set(undefined4 param_1)

{
  undefined2 uVar1;
  int __fd;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  int __fd_00;
  undefined4 local_58;
  sockaddr local_54;
  sockaddr local_44;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  __fd_00 = cmcc_sockfd_v6;
  iVar4 = cmcc_sockfd;
  uVar1 = (undefined2)param_1;
  local_58 = 0;
  local_54.sa_data[6] = '\0';
  local_54.sa_data[7] = '\0';
  local_54.sa_data[8] = '\0';
  local_54.sa_data[9] = '\0';
  local_54.sa_data[10] = '\0';
  local_54.sa_data[0xb] = '\0';
  local_54.sa_data[0xc] = '\0';
  local_54.sa_data[0xd] = '\0';
  local_54.sa_data[2] = '\0';
  local_54.sa_data[3] = '\0';
  local_54.sa_data[4] = '\0';
  local_54.sa_data[5] = '\0';
  local_54.sa_family = 2;
  local_54.sa_data._0_2_ = uVar1;
  __fd = socket(2,1,0);
  if (__fd < 0) {
    if ((wportal_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Create cmcc socket error\n\n","_cmcc_socket_reinit",0x86b);
    }
    if (__fd == -1) {
      return 0xffffffff;
    }
    __fd_00 = -1;
  }
  else {
    local_58 = 0x100000;
    iVar2 = setsockopt(__fd,0xffff,0x1001,&local_58,4);
    if (iVar2 == -1) {
      __fd_00 = -1;
      if (wportal_err_switch == 0) {
LAB_0043a048:
        __fd_00 = -1;
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 != 0) {
          __format = "[WPORTAL_ERR]%s()/%d setsockopt cmcc_sockfd socket SO_SNDBUF error\n\n";
          uVar5 = 0x872;
          goto LAB_0043a11c;
        }
      }
    }
    else {
      local_58 = 1;
      iVar2 = setsockopt(__fd,0xffff,4,&local_58,4);
      if (iVar2 == -1) {
        __fd_00 = -1;
        if (wportal_err_switch == 0) goto LAB_0043a048;
        iVar4 = is_target_debug_ap();
        if (iVar4 != 0) {
          __format = "[WPORTAL_ERR]%s()/%d setsockopt cmcc socket SO_REUSEADDR error\n\n";
          uVar5 = 0x879;
          goto LAB_0043a11c;
        }
      }
      else {
        iVar2 = bind(__fd,&local_54,0x10);
        if (iVar2 == -1) {
          __fd_00 = -1;
          if (wportal_err_switch == 0) goto LAB_0043a048;
          iVar4 = is_target_debug_ap();
          if (iVar4 != 0) {
            __format = "[WPORTAL_ERR]%s()/%d setsockopt cmcc socket bind error\n\n";
            uVar5 = 0x880;
            goto LAB_0043a11c;
          }
        }
        else {
          local_44.sa_data[2] = '\0';
          local_44.sa_data[3] = '\0';
          local_44.sa_data[4] = '\0';
          local_44.sa_data[5] = '\0';
          local_44.sa_data[6] = '\0';
          local_44.sa_data[7] = '\0';
          local_44.sa_data[8] = '\0';
          local_44.sa_data[9] = '\0';
          local_44.sa_data[10] = '\0';
          local_44.sa_data[0xb] = '\0';
          local_44.sa_data[0xc] = '\0';
          local_44.sa_data[0xd] = '\0';
          local_34 = 0;
          local_30 = 0;
          local_2c = 0;
          local_44.sa_data[0] = '\0';
          local_44.sa_data[1] = '\0';
          local_44.sa_family = 10;
          memcpy(local_44.sa_data + 6,in6addr_any,0x10);
          local_44.sa_data[0] = SUB21(uVar1,1);
          local_44.sa_data[1] = (char)uVar1;
          iVar2 = socket(10,1,0);
          if (iVar2 < 0) {
            __fd_00 = iVar2;
            if ((wportal_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              __format = "[WPORTAL_ERR]%s()/%d Create cmcc socket error\n\n";
              uVar5 = 0x88e;
LAB_0043a11c:
              printf(__format,"_cmcc_socket_reinit",uVar5);
            }
          }
          else {
            local_58 = 0x100000;
            iVar3 = setsockopt(iVar2,0xffff,0x1001,&local_58,4);
            if (iVar3 == -1) {
              __fd_00 = iVar2;
              if ((wportal_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                __format = "[WPORTAL_ERR]%s()/%d setsockopt cmcc_sockfd socket SO_SNDBUF error\n\n";
                uVar5 = 0x895;
                goto LAB_0043a11c;
              }
            }
            else {
              local_58 = 1;
              iVar3 = setsockopt(iVar2,0xffff,4,&local_58,4);
              if (iVar3 == -1) {
                __fd_00 = iVar2;
                if ((wportal_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                  __format = "[WPORTAL_ERR]%s()/%d setsockopt cmcc socket SO_REUSEADDR error\n\n";
                  uVar5 = 0x89c;
                  goto LAB_0043a11c;
                }
              }
              else {
                iVar3 = bind(iVar2,&local_44,0x1c);
                if (iVar3 != -1) {
                  cmcc_sockfd = __fd;
                  cmcc_sockfd_v6 = iVar2;
                  g_cmcc_port = param_1;
                  if (iVar4 != -1) {
                    shutdown(iVar4,2);
                    close(iVar4);
                  }
                  uVar5 = 0;
                  if (__fd_00 == -1) {
                    return 0;
                  }
                  shutdown(__fd_00,2);
                  goto LAB_0043a05c;
                }
                __fd_00 = iVar2;
                if ((wportal_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                  __format = "[WPORTAL_ERR]%s()/%d setsockopt cmcc socket bind error\n\n";
                  uVar5 = 0x8a3;
                  goto LAB_0043a11c;
                }
              }
            }
          }
        }
      }
    }
  }
  uVar5 = 0xffffffff;
  close(__fd);
  if (__fd_00 == -1) {
    return 0xffffffff;
  }
LAB_0043a05c:
  close(__fd_00);
  return uVar5;
}

