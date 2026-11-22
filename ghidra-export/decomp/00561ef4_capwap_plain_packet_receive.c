// func capwap_plain_packet_receive @ 00561ef4 size=972

ssize_t capwap_plain_packet_receive
                  (int param_1,undefined1 *param_2,undefined1 *param_3,void *param_4,size_t param_5,
                  undefined4 *param_6)

{
  ssize_t sVar1;
  cmsghdr *__cmsg;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  iovec local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  msghdr local_ac;
  cmsghdr acStack_90 [9];
  
  local_d0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  memset(acStack_90,0,100);
  local_ac.msg_name = (void *)0x0;
  local_ac.msg_namelen = 0;
  local_ac.msg_iov = (iovec *)0x0;
  local_ac.msg_iovlen = 0;
  local_ac.msg_control = (void *)0x0;
  local_ac.msg_controllen = 0;
  local_ac.msg_flags = 0;
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  if ((((param_2 == (undefined1 *)0x0) || (param_4 == (void *)0x0)) || ((int)param_5 < 1)) ||
     (param_6 == (undefined4 *)0x0)) {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d input is null.\n","capwap_plain_packet_receive",0x2bf);
    }
  }
  else {
    local_ac.msg_name = &local_d0;
    local_d8.iov_len = param_5;
    local_ac.msg_namelen = 0x10;
    local_ac.msg_controllen = 100;
    local_ac.msg_iov = &local_d8;
    local_ac.msg_iovlen = 1;
    local_d8.iov_base = param_4;
    local_ac.msg_control = acStack_90;
    sVar1 = recvmsg(param_1,&local_ac,0);
    if ((sVar1 < 1) || ((int)param_5 < sVar1)) {
      if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        __format = "[CW_DEBUG]%32s():%4d recv msg error - len = %d\n";
        uVar3 = 0x2ce;
LAB_00562194:
        printf(__format,"capwap_plain_packet_receive",uVar3,sVar1);
      }
    }
    else {
      __cmsg = (cmsghdr *)local_ac.msg_control;
      if (local_ac.msg_controllen < 0xc) {
        __cmsg = (cmsghdr *)0x0;
      }
      for (; __cmsg != (cmsghdr *)0x0; __cmsg = __cmsg_nxthdr(&local_ac,__cmsg)) {
        if ((__cmsg->cmsg_level == 0) && (__cmsg->cmsg_type == 8)) {
          *(undefined4 *)(param_2 + 4) = local_cc;
          *(undefined2 *)(param_2 + 0x14) = local_d0._2_2_;
          *(int *)(param_3 + 4) = __cmsg[1].cmsg_type;
          *(size_t *)(param_3 + 0x18) = __cmsg[1].cmsg_len;
          *(size_t *)(param_2 + 0x18) = __cmsg[1].cmsg_len;
          *param_2 = 1;
          *param_3 = 1;
          if (*(int *)(param_3 + 4) == -1) {
            iVar2 = capwap_socket_ifindex_to_addr
                              (param_1,0,*(undefined4 *)(param_3 + 0x18),param_3,&local_c0);
            if (iVar2 == -1) {
              if ((capwap_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                sVar1 = *(ssize_t *)(param_3 + 0x18);
                __format = "[CW_WARNING]%32s():%4d change ifindex %d to addr failed.\n";
                uVar3 = 0x2e4;
                goto LAB_00562194;
              }
              break;
            }
            iVar2 = capwap_socket_addr_in_same_subnet(param_2,param_3,&local_c0);
            if (iVar2 == 0) {
              *param_6 = 0xfffffffe;
              if (capwap_warning_switch == 0) {
                return -1;
              }
              iVar2 = is_target_debug_ap();
              if (iVar2 == 0) {
                return -1;
              }
              printf("[CW_WARNING]%32s():%4d IP addresses(%08x %08x %08x) are not in same subnet.\n"
                     ,"capwap_plain_packet_receive",0x2eb,*(undefined4 *)(param_2 + 4),
                     *(undefined4 *)(param_3 + 4),local_bc);
              return -1;
            }
            if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[CW_DEBUG]%32s():%4d #############recv brdcast req. ifindex:%d, ip:0x%08x\n",
                     "capwap_plain_packet_receive",0x2ee,__cmsg[1].cmsg_len,
                     *(undefined4 *)(param_3 + 4));
            }
          }
          if (capwap_debug_switch == 0) {
            *param_6 = 0;
            return sVar1;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            *param_6 = 0;
            return sVar1;
          }
          printf("[CW_DEBUG]%32s():%4d [route ip:%08x dst ip:%08x] recieve packet[len = %d] from [%08x:%d]\n"
                 ,"capwap_plain_packet_receive",0x2f2,__cmsg[1].cmsg_level,
                 *(undefined4 *)(param_3 + 4),sVar1,*(undefined4 *)(param_2 + 4),
                 (uint)*(ushort *)(param_2 + 0x14));
          *param_6 = 0;
          return sVar1;
        }
      }
    }
    *param_6 = 0xffffffff;
  }
  return -1;
}

