// func capwap_plain_ipv6_packet_receive @ 005622c0 size=1484

ssize_t capwap_plain_ipv6_packet_receive
                  (int param_1,undefined4 *param_2,undefined4 *param_3,void *param_4,size_t param_5,
                  undefined4 *param_6)

{
  ssize_t sVar1;
  cmsghdr *__cmsg;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  iovec local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  msghdr local_28c;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined1 auStack_254 [64];
  undefined1 auStack_214 [64];
  undefined1 auStack_1d4 [64];
  char acStack_194 [64];
  cmsghdr acStack_154 [25];
  
  local_270 = 0;
  local_26c = 0;
  local_268 = 0;
  local_264 = 0;
  local_260 = 0;
  local_25c = 0;
  local_258 = 0;
  memset(acStack_154,0,300);
  local_28c.msg_name = (void *)0x0;
  local_28c.msg_namelen = 0;
  local_28c.msg_iov = (iovec *)0x0;
  local_28c.msg_iovlen = 0;
  local_28c.msg_control = (void *)0x0;
  local_28c.msg_controllen = 0;
  local_28c.msg_flags = 0;
  local_2a0 = 0;
  local_29c = 0;
  local_298 = 0;
  local_294 = 0;
  local_290 = 0;
  if ((((param_2 == (undefined4 *)0x0) || (param_4 == (void *)0x0)) || ((int)param_5 < 1)) ||
     (param_6 == (undefined4 *)0x0)) {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d input is null.\n","capwap_plain_ipv6_packet_receive",0x306);
    }
  }
  else {
    local_28c.msg_name = &local_270;
    local_2a8.iov_len = param_5;
    local_28c.msg_namelen = 0x1c;
    local_28c.msg_controllen = 300;
    local_28c.msg_iov = &local_2a8;
    local_28c.msg_iovlen = 1;
    local_2a8.iov_base = param_4;
    local_28c.msg_control = acStack_154;
    sVar1 = recvmsg(param_1,&local_28c,0);
    if ((sVar1 < 1) || ((int)param_5 < sVar1)) {
      if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_DEBUG]%32s():%4d recv msg error - len = %d\n";
        uVar3 = 0x315;
LAB_0056272c:
        printf(__format,"capwap_plain_ipv6_packet_receive",uVar3,sVar1);
      }
    }
    else {
      __cmsg = (cmsghdr *)local_28c.msg_control;
      if (local_28c.msg_controllen < 0xc) {
        __cmsg = (cmsghdr *)0x0;
      }
      if (__cmsg != (cmsghdr *)0x0) {
        iVar2 = __cmsg->cmsg_level;
        while ((iVar2 != 0x29 || (__cmsg->cmsg_type != 0x32))) {
          __cmsg = __cmsg_nxthdr(&local_28c,__cmsg);
          if (__cmsg == (cmsghdr *)0x0) goto LAB_00562430;
          iVar2 = __cmsg->cmsg_level;
        }
        memcpy(param_2 + 1,&local_268,0x10);
        *(undefined2 *)(param_2 + 5) = local_270._2_2_;
        memcpy(param_3 + 1,__cmsg + 1,0x10);
        param_3[6] = __cmsg[2].cmsg_level;
        param_2[6] = __cmsg[2].cmsg_level;
        *(undefined1 *)param_2 = 2;
        *(undefined1 *)param_3 = 2;
        memset(acStack_194,0,0x40);
        FUN_00408190(*param_3,param_3[1],param_3[2],param_3[3],param_3[4],acStack_194,0x40,
                     &DAT_00698ca0);
        iVar2 = strcasecmp(acStack_194,"FF0E::18C");
        if (iVar2 != 0) {
LAB_0056254c:
          memset(auStack_254,0,0x40);
          memset(auStack_214,0,0x40);
          FUN_00408190(*param_2,param_2[1],param_2[2],param_2[3],param_2[4],auStack_254,0x40,"---");
          FUN_00408190(*param_3,param_3[1],param_3[2],param_3[3],param_3[4],auStack_214,0x40,"---");
          if (capwap_debug_switch == 0) {
            *param_6 = 0;
            return sVar1;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            *param_6 = 0;
            return sVar1;
          }
          printf("[CW_DEBUG]%32s():%4d socket[%d]ifIndex[%d][%s] receives packet[len = %d] from [%s/%d]\n"
                 ,"capwap_plain_ipv6_packet_receive",0x347,param_1,param_2[6],auStack_214,sVar1,
                 auStack_254,(uint)*(ushort *)(param_2 + 5));
          *param_6 = 0;
          return sVar1;
        }
        iVar2 = capwap_socket_ifindex_to_addr(param_1,1,param_3[6],param_3,&local_2a0);
        if (iVar2 != -1) {
          iVar2 = capwap_socket_addr_in_same_subnet(param_2,param_3,&local_2a0);
          if (iVar2 == 0) {
            memset(auStack_1d4,0,0x40);
            memset(auStack_214,0,0x40);
            memset(auStack_254,0,0x40);
            FUN_00408190(*param_2,param_2[1],param_2[2],param_2[3],param_2[4],auStack_1d4,0x40,"---"
                        );
            FUN_00408190(*param_3,param_3[1],param_3[2],param_3[3],param_3[4],auStack_214,0x40,"---"
                        );
            FUN_00408190(local_2a0,local_29c,local_298,local_294,local_290,auStack_254,0x40,"---");
            if ((capwap_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[CW_WARNING]%32s():%4d IP addresses(%s %s %s)) are not in same subnet.\n",
                     "capwap_plain_ipv6_packet_receive",0x33a,auStack_1d4,auStack_214,auStack_254);
            }
            *param_6 = 0xfffffffe;
            return -1;
          }
          FUN_00408190(*param_3,param_3[1],param_3[2],param_3[3],param_3[4],acStack_194,0x40,"---");
          if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[CW_DEBUG]%32s():%4d #############recv brdcast req. ifindex:%d, ip:%s\n",
                   "capwap_plain_ipv6_packet_receive",0x33f,__cmsg[2].cmsg_level,acStack_194);
          }
          goto LAB_0056254c;
        }
        if ((capwap_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          sVar1 = param_3[6];
          __format = "[CW_WARNING]%32s():%4d change ifindex %d to addr failed.\n";
          uVar3 = 0x32e;
          goto LAB_0056272c;
        }
      }
    }
LAB_00562430:
    *param_6 = 0xffffffff;
  }
  return -1;
}

