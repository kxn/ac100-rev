// func capwap_ipv6_socket_bind @ 00561328 size=736

undefined4 capwap_ipv6_socket_bind(int param_1,ushort param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  short *psVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  uint local_88;
  sockaddr local_84;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 auStack_68 [68];
  
  uVar6 = (uint)param_2;
  local_9c = 0;
  memset(auStack_68,0,0x40);
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84.sa_data[2] = '\0';
  local_84.sa_data[3] = '\0';
  local_84.sa_data[4] = '\0';
  local_84.sa_data[5] = '\0';
  local_84.sa_data[6] = '\0';
  local_84.sa_data[7] = '\0';
  local_84.sa_data[8] = '\0';
  local_84.sa_data[9] = '\0';
  local_84.sa_data[10] = '\0';
  local_84.sa_data[0xb] = '\0';
  local_84.sa_data[0xc] = '\0';
  local_84.sa_data[0xd] = '\0';
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_84.sa_data[0] = '\0';
  local_84.sa_data[1] = '\0';
  local_84.sa_family = 10;
  memcpy(local_84.sa_data + 6,in6addr_any,0x10);
  local_84.sa_data._0_2_ = param_2;
  iVar1 = bind(param_1,&local_84,0x1c);
  if (iVar1 < 0) {
    uVar5 = 0xffffffff;
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[CW_ERROR]%32s():%4d socket[%d] failed to bind %d\n";
    uVar3 = 0x1b1;
  }
  else {
    inet_pton(10,"FF0E::18C",&local_98);
    iVar1 = getifaddrs(&local_a0);
    if (iVar1 == -1) {
      uVar5 = 0xffffffff;
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar2 = "[CW_ERROR]%32s():%4d socket[%d] failed to bind %d\n";
      uVar3 = 0x1b9;
    }
    else {
      if (local_a0 != (undefined4 *)0x0) {
        psVar4 = (short *)local_a0[3];
        puVar7 = local_a0;
        while( true ) {
          if (psVar4 == (short *)0x0) {
            puVar7 = (undefined4 *)*puVar7;
          }
          else {
            pcVar2 = (char *)puVar7[1];
            if (pcVar2 == (char *)0x0) {
              puVar7 = (undefined4 *)*puVar7;
            }
            else if (*psVar4 == 10) {
              iVar1 = strcmp(pcVar2,"lo");
              if (iVar1 == 0) {
                puVar7 = (undefined4 *)*puVar7;
              }
              else if (((*(byte *)(psVar4 + 4) & 0xf0) == 0x20) ||
                      ((*(byte *)(psVar4 + 4) & 0xf0) == 0x30)) {
                local_88 = if_nametoindex(pcVar2);
                setsockopt(param_1,0x29,0x14,&local_98,0x14);
                puVar7 = (undefined4 *)*puVar7;
              }
              else {
                puVar7 = (undefined4 *)*puVar7;
              }
            }
            else {
              puVar7 = (undefined4 *)*puVar7;
            }
          }
          if (puVar7 == (undefined4 *)0x0) break;
          psVar4 = (short *)puVar7[3];
        }
      }
      freeifaddrs(local_a0);
      iVar1 = setsockopt(param_1,0x29,0x13,&local_9c,4);
      if (iVar1 < 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d socket[%d] set IPV6_MULTICAST_LOOP failed.\n",
               "capwap_ipv6_socket_bind",0x1d2,param_1);
        return 0xffffffff;
      }
      uVar5 = 0;
      if (capwap_debug_switch == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      uVar6 = capwap_socket_addr_to_string(&local_84,1,auStack_68,0x40);
      pcVar2 = "[CW_DEBUG]%32s():%4d socket[%d] bind to %s\n";
      uVar3 = 0x1d5;
    }
  }
  printf(pcVar2,"capwap_ipv6_socket_bind",uVar3,param_1,uVar6);
  return uVar5;
}

