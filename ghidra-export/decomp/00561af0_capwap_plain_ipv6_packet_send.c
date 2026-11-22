// func capwap_plain_ipv6_packet_send @ 00561af0 size=1028

undefined1 *
capwap_plain_ipv6_packet_send
          (int param_1,char *param_2,char *param_3,void *param_4,undefined1 *param_5)

{
  ushort uVar1;
  int iVar2;
  ssize_t sVar3;
  undefined1 *puVar4;
  char *__format;
  undefined4 uVar5;
  undefined1 *puVar6;
  iovec local_100;
  msghdr local_f8;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [64];
  char acStack_60 [64];
  
  local_dc = 0;
  local_d8 = 0;
  local_d4 = 0;
  local_d0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_f8.msg_name = (void *)0x0;
  local_f8.msg_namelen = 0;
  local_f8.msg_iov = (iovec *)0x0;
  local_f8.msg_iovlen = 0;
  local_f8.msg_control = (void *)0x0;
  local_f8.msg_controllen = 0;
  local_f8.msg_flags = 0;
  local_100.iov_base = (void *)0x0;
  local_100.iov_len = 0;
  if ((((param_3 == (char *)0x0) || (param_4 == (void *)0x0)) || ((int)param_5 < 1)) ||
     ((*param_2 != '\x02' || (*param_3 != '\x02')))) {
    param_5 = (undefined1 *)0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d inputs error.\n","capwap_plain_ipv6_packet_send",0x273);
    }
  }
  else {
    local_f8.msg_name = (void *)0x0;
    local_f8.msg_namelen = 0;
    local_f8.msg_iov = (iovec *)0x0;
    local_f8.msg_iovlen = 0;
    local_f8.msg_control = (void *)0x0;
    local_f8.msg_controllen = 0;
    local_f8.msg_flags = 0;
    local_dc = 0;
    local_d8 = 0;
    local_d4 = 0;
    local_d0 = 0;
    local_cc = 0;
    local_c8 = 0;
    local_c4 = 0;
    memcpy(&local_d4,param_3 + 4,0x10);
    local_f8.msg_iov = &local_100;
    local_f8.msg_iovlen = 1;
    local_dc = CONCAT22(10,*(undefined2 *)(param_3 + 0x14));
    local_bc = 0x29;
    local_f8.msg_namelen = 0x1c;
    local_f8.msg_control = &local_c0;
    local_b8 = 0x32;
    local_100.iov_len = (size_t)param_5;
    local_f8.msg_controllen = 0x20;
    local_c0 = 0x20;
    local_a4 = 0;
    local_b4 = 0;
    local_b0 = 0;
    local_ac = 0;
    local_a8 = 0;
    local_100.iov_base = param_4;
    local_f8.msg_name = &local_dc;
    memset(acStack_60,0,0x40);
    FUN_00408190(*(undefined4 *)param_2,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                 *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),acStack_60,0x40,
                 &DAT_00698ca0);
    iVar2 = strcasecmp(acStack_60,"FF0E::18C");
    if (iVar2 != 0) {
      local_a4 = *(undefined4 *)(param_3 + 0x18);
      memcpy(&local_b4,param_2 + 4,0x10);
    }
    sVar3 = sendmsg(param_1,&local_f8,0);
    if (sVar3 < 1) {
      memset(auStack_a0,0,0x40);
      FUN_00408190(*(undefined4 *)param_2,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                   *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),acStack_60,0x40,
                   "---");
      param_5 = (undefined1 *)0xffffffff;
      FUN_00408190(*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4),*(undefined4 *)(param_3 + 8),
                   *(undefined4 *)(param_3 + 0xc),*(undefined4 *)(param_3 + 0x10),auStack_a0,0x40,
                   "---");
      if (capwap_debug_switch == 0) {
        return (undefined1 *)0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return (undefined1 *)0xffffffff;
      }
      __format = "[CW_DEBUG]%32s():%4d socket[%d]ifIndex[%d][%s/%d] send packet to [%s/%d] failed\n"
      ;
      uVar5 = 0x2a0;
      uVar1 = *(ushort *)(param_2 + 0x14);
      puVar6 = auStack_a0;
      puVar4 = (undefined1 *)(uint)*(ushort *)(param_3 + 0x14);
    }
    else {
      memset(auStack_a0,0,0x40);
      FUN_00408190(*(undefined4 *)param_2,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                   *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),acStack_60,0x40,
                   "---");
      FUN_00408190(*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4),*(undefined4 *)(param_3 + 8),
                   *(undefined4 *)(param_3 + 0xc),*(undefined4 *)(param_3 + 0x10),auStack_a0,0x40,
                   "---");
      if (capwap_debug_switch == 0) {
        return param_5;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return param_5;
      }
      __format = 
      "[CW_DEBUG]%32s():%4d socket[%d]ifIndex[%d][%s/%d] sends packet[len = %d] to [%s/%d]\n";
      uVar5 = 0x299;
      uVar1 = *(ushort *)(param_2 + 0x14);
      puVar4 = auStack_a0;
      puVar6 = param_5;
    }
    printf(__format,"capwap_plain_ipv6_packet_send",uVar5,param_1,local_a4,acStack_60,(uint)uVar1,
           puVar6,puVar4);
  }
  return param_5;
}

