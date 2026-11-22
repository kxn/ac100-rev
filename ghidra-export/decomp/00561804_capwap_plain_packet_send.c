// func capwap_plain_packet_send @ 00561804 size=748

size_t capwap_plain_packet_send(int param_1,int param_2,byte *param_3,void *param_4,size_t param_5)

{
  ushort uVar1;
  int iVar2;
  ssize_t sVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  size_t sVar7;
  char *__format;
  undefined4 uVar8;
  iovec local_90;
  sockaddr local_88;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  msghdr local_60;
  undefined1 auStack_44 [40];
  
  memset(auStack_44,0,0x20);
  if ((((param_3 == (byte *)0x0) || (param_4 == (void *)0x0)) || ((int)param_5 < 1)) ||
     (local_60.msg_iovlen = (size_t)*param_3, local_60.msg_iovlen != 1)) {
    param_5 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d inputs error.\n","capwap_plain_packet_send",0x21e);
    }
  }
  else if ((param_2 == 0) || (local_68 = *(int *)(param_2 + 4), local_68 == -1)) {
    local_88.sa_data._2_4_ = *(undefined4 *)(param_3 + 4);
    local_88.sa_data[6] = '\0';
    local_88.sa_data[7] = '\0';
    local_88.sa_data[8] = '\0';
    local_88.sa_data[9] = '\0';
    local_88.sa_data[10] = '\0';
    local_88.sa_data[0xb] = '\0';
    local_88.sa_data[0xc] = '\0';
    local_88.sa_data[0xd] = '\0';
    local_88.sa_data._0_2_ = *(undefined2 *)(param_3 + 0x14);
    local_88.sa_family = 2;
    param_5 = sendto(param_1,param_4,param_5,0,&local_88,0x10);
    if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      uVar4 = capwap_socket_addr_to_string(&local_88,0,auStack_44,0x20);
      piVar6 = __errno_location();
      printf("[CW_DEBUG]%32s():%4d socket[%d] send pkt to %s, ret=%d, errno=%d\n",
             "capwap_plain_packet_send",0x22a,param_1,uVar4,param_5,*piVar6);
    }
    if ((int)param_5 < 0) {
      param_5 = 0xffffffff;
    }
  }
  else {
    local_88.sa_data._2_4_ = *(undefined4 *)(param_3 + 4);
    local_60.msg_name = &local_88;
    local_88.sa_data._0_2_ = *(undefined2 *)(param_3 + 0x14);
    local_60.msg_namelen = 0x10;
    local_60.msg_control = &local_78;
    local_70 = 8;
    local_88.sa_family = 2;
    local_60.msg_iov = &local_90;
    local_60.msg_flags = 0;
    local_88.sa_data[6] = '\0';
    local_88.sa_data[7] = '\0';
    local_88.sa_data[8] = '\0';
    local_88.sa_data[9] = '\0';
    local_88.sa_data[10] = '\0';
    local_88.sa_data[0xb] = '\0';
    local_88.sa_data[0xc] = '\0';
    local_88.sa_data[0xd] = '\0';
    local_90.iov_len = param_5;
    local_60.msg_controllen = 0x18;
    local_74 = 0;
    local_78 = 0x18;
    local_6c = *(undefined4 *)(param_3 + 0x18);
    local_90.iov_base = param_4;
    sVar3 = sendmsg(param_1,&local_60,0);
    if (sVar3 < 1) {
      param_5 = 0xffffffff;
      if (capwap_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = 
      "[CW_DEBUG]%32s():%4d socket[%d]ifIndex[%d][%08x:%d] send packet to [%08x:%d] failed\n\n";
      uVar4 = *(undefined4 *)(param_2 + 4);
      uVar8 = 0x254;
      uVar1 = *(ushort *)(param_2 + 0x14);
      sVar7 = *(size_t *)(param_3 + 4);
      uVar5 = (uint)*(ushort *)(param_3 + 0x14);
    }
    else {
      if (capwap_debug_switch == 0) {
        return param_5;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return param_5;
      }
      __format = 
      "[CW_DEBUG]%32s():%4d socket[%d]ifIndex[%d][%08x:%d] sends packet[len = %d] to [%08x:%d]\n";
      uVar4 = *(undefined4 *)(param_2 + 4);
      uVar8 = 0x250;
      uVar1 = *(ushort *)(param_2 + 0x14);
      uVar5 = *(uint *)(param_3 + 4);
      sVar7 = param_5;
    }
    printf(__format,"capwap_plain_packet_send",uVar8,param_1,local_6c,uVar4,(uint)uVar1,sVar7,uVar5)
    ;
  }
  return param_5;
}

