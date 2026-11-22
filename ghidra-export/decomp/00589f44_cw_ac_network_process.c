// func cw_ac_network_process @ 00589f44 size=1024

/* WARNING: Type propagation algorithm not settling */

undefined4 cw_ac_network_process(int param_1)

{
  size_t __n;
  undefined4 *__s;
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  int local_50 [13];
  undefined4 local_1c;
  undefined4 local_18;
  
  local_50[8] = 0;
  local_50[9] = 0;
  local_50[10] = 0;
  local_50[0xb] = 0;
  local_50[0xc] = 0;
  local_1c = 0;
  local_18 = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_50[0] = 0;
  if (ac == 0) {
    uVar3 = 0x91e;
    pcVar4 = "ac";
LAB_0058a2e0:
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_network_process",uVar3,pcVar4);
    return 0xffffffff;
  }
  if (*(int *)(ac + 0xc) == -1) {
    uVar3 = 0x91f;
    pcVar4 = "-1 != ac->sock_fd";
    goto LAB_0058a2e0;
  }
  if (*(int *)(ac + 0x10) == -1) {
    uVar3 = 0x921;
    pcVar4 = "-1 != ac->sock6_fd";
    goto LAB_0058a2e0;
  }
  if (*(int *)(ac + 0x1c) == 0) {
    uVar3 = 0x923;
    pcVar4 = "ac->ac_data";
    goto LAB_0058a2e0;
  }
  if (param_1 == 0) {
    __n = capwap_plain_packet_receive
                    (*(int *)(ac + 0xc),local_50 + 8,local_50 + 1,ac + 0x24,0xcc00,local_50);
  }
  else {
    __n = capwap_plain_ipv6_packet_receive
                    (*(int *)(ac + 0x10),local_50 + 8,local_50 + 1,ac + 0x24,0xcc00,local_50);
  }
  if ((int)__n < 1) {
    if ((capwap_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_WARNING]%32s():%4d socket[%d] receive packet failed.\n","cw_ac_network_process",
             0x930,*(undefined4 *)(ac + 0xc));
    }
    if (local_50[0] != -2) {
      return 0xffffffff;
    }
    capwap_package_receive_network_conflict_handle(local_50 + 8);
    return 0xffffffff;
  }
  if (pkt_handler_switch == 0) {
    if (capwap_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[CW_DEBUG]%32s():%4d Packet handler is switch off, do not respond.\n";
    uVar3 = 0x93a;
LAB_0058a24c:
    printf(pcVar4,"cw_ac_network_process",uVar3);
    return 0xffffffff;
  }
  __s = (undefined4 *)FUN_00408450(0x3c,0x93f);
  if (__s == (undefined4 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[CW_ERROR]%32s():%4d malloc failed.\n";
    uVar3 = 0x941;
    goto LAB_0058a24c;
  }
  memset(__s,0,0x3c);
  puVar1 = (undefined4 *)cw_pkt_buf_create(__n);
  __s[0xe] = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    if (capwap_err_switch == 0) {
      iVar2 = __s[0xe];
      goto LAB_0058a198;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = __s[0xe];
      goto LAB_0058a198;
    }
    pcVar4 = "[CW_ERROR]%32s():%4d malloc failed.\n";
    uVar3 = 0x947;
  }
  else {
    memcpy((void *)*puVar1,(void *)(ac + 0x24),__n);
    *(short *)(__s[0xe] + 4) = (short)__n;
    *(undefined2 *)(__s[0xe] + 6) = 0;
    memcpy(__s,local_50 + 8,0x14);
    *(undefined2 *)(__s + 5) = local_1c._0_2_;
    __s[6] = local_18;
    memcpy(__s + 7,local_50 + 1,0x14);
    iVar2 = __s[0xe];
    *(undefined2 *)(__s + 0xc) = 0x147e;
    __s[0xd] = local_50[7];
    uVar5 = FUN_00524078();
    *(undefined8 *)(iVar2 + 0x10) = uVar5;
    iVar2 = ip_to_ac_data(*__s,__s[1],__s[2],__s[3],__s[4],*(undefined2 *)(__s + 5));
    iVar2 = cw_packet_queue_push_tail
                      (*(undefined4 *)(*(int *)(ac + 0x1c) + iVar2 * 0xa0 + 0x20),__s);
    if (iVar2 != -1) {
      return 0;
    }
    if (capwap_warning_switch == 0) {
      iVar2 = __s[0xe];
      goto LAB_0058a198;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = __s[0xe];
      goto LAB_0058a198;
    }
    pcVar4 = "[CW_WARNING]%32s():%4d insert capwap packet to packet queue failed.\n";
    uVar3 = 0x95b;
  }
  printf(pcVar4,"cw_ac_network_process",uVar3);
  iVar2 = __s[0xe];
LAB_0058a198:
  if (iVar2 != 0) {
    cw_pkt_buf_destroy();
  }
  FUN_00407df0(__s);
  return 0xffffffff;
}

