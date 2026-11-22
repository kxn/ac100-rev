// func _uac_mac_auth_sta_check @ 0044c480 size=1348

undefined4 _uac_mac_auth_sta_check(int param_1)

{
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 *__src;
  void *__dest;
  uint in_stack_fffffb10;
  ushort local_4d8 [2];
  int local_4d4;
  undefined4 local_4d0;
  undefined4 local_4cc;
  undefined4 local_4c8;
  undefined4 local_4c4;
  undefined4 local_4c0;
  undefined4 local_4bc;
  undefined1 local_4b8;
  undefined1 auStack_4b4 [12];
  undefined1 auStack_4a8 [6];
  byte local_4a2;
  undefined1 auStack_49e [34];
  undefined1 auStack_47c [396];
  undefined1 auStack_2f0 [20];
  uint local_2dc;
  
  memset(auStack_47c,0,0x188);
  local_4d8[0] = 0;
  local_4d4 = 1;
  memset(auStack_2f0,0,0x2d8);
  memset(auStack_4b4,0,0x38);
  if (param_1 == 0) {
    uVar7 = 0xffffffff;
    if (macauth_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[MACAUTH_ERROR]%s()/%d Invalid params.\n";
    uVar6 = 0x5e;
    goto LAB_0044c61c;
  }
  if (macauth_debug_switch == 0) {
    uVar1 = *(undefined2 *)(param_1 + 0x22);
  }
  else {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_sta_check start\n","_uac_mac_auth_sta_check",0x61);
    uVar1 = *(undefined2 *)(param_1 + 0x22);
  }
  iVar3 = apmngr_db_entry_get_by_id(uVar1,auStack_2f0);
  if (iVar3 == -1) {
    uVar7 = 0xffffffff;
    if (macauth_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[MACAUTH_ERROR]%s()/%d get apentry by id failed.\n";
    uVar6 = 0x65;
    goto LAB_0044c61c;
  }
  if ((((1 < local_2dc) && (local_2dc != 3)) && (local_2dc != 2)) &&
     (((local_2dc != 4 && (local_2dc != 8)) && (local_2dc != 6)))) {
    uVar7 = 0;
    if (macauth_debug_switch == 0) {
      return 0;
    }
    pcVar5 = "[MACAUTH_DEBUG]%s()/%d Non-AP no need to check.\n";
    uVar6 = 0x6a;
    goto LAB_0044c61c;
  }
  iVar3 = wsta_db_get_mac_entry_by_peer(param_1 + 0x68,auStack_4b4);
  if (iVar3 == 0) {
LAB_0044c588:
    if (macauth_debug_switch != 0) {
      in_stack_fffffb10 = (uint)*(byte *)(param_1 + 0x6b);
      printf("[MACAUTH_DEBUG]%s()/%d mld mac: %02x:%02x:%02x:%02x:%02x:%02x\n",
             "_uac_mac_auth_sta_check",0x72,(uint)*(byte *)(param_1 + 0x68),
             (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),in_stack_fffffb10,
             (uint)*(byte *)(param_1 + 0x6c),(uint)*(byte *)(param_1 + 0x6d));
    }
    __src = auStack_49e;
    __dest = (void *)((int)&local_4cc + 3);
    memcpy((void *)((int)&local_4d0 + 1),auStack_4a8,6);
    for (iVar3 = 0; iVar3 < (int)(uint)local_4a2; iVar3 = iVar3 + 1) {
      memcpy(__dest,__src,6);
      __src = __src + 0xc;
      __dest = (void *)((int)__dest + 6);
    }
    bVar2 = true;
  }
  else {
    iVar3 = wsta_db_get_mac_entry_by_mld(param_1 + 0x68,auStack_4b4);
    bVar2 = false;
    if (iVar3 == 0) goto LAB_0044c588;
  }
  if (g_macauth_mode == 1) {
    iVar3 = uac_wservice_get_vlan
                      (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                       *(undefined1 *)(param_1 + 0x25),local_4d8);
    if (iVar3 != 0) {
      uVar7 = 0xffffffff;
      if (macauth_err_switch == 0) {
        return 0xffffffff;
      }
      pcVar5 = "[MACAUTH_ERROR]%s()/%d get vlan id failed.\n";
      uVar6 = 0x83;
LAB_0044c61c:
      printf(pcVar5,"_uac_mac_auth_sta_check",uVar6);
      return uVar7;
    }
    if (macauth_debug_switch != 0) {
      printf("[MACAUTH_DEBUG]%s()/%d VLAN is %d\n","_uac_mac_auth_sta_check",0x86,(uint)local_4d8[0]
            );
    }
    iVar3 = mac_auth_db_group_entry_get_by_vid(local_4d8[0],auStack_47c);
    if (iVar3 != 0) {
      if (macauth_debug_switch == 0) {
        return 0;
      }
      uVar4 = (uint)local_4d8[0];
      pcVar5 = "[MACAUTH_DEBUG]%s()/%d MAC auth is not enabled in vlan(%d).\n";
      uVar7 = 0x89;
      goto LAB_0044c89c;
    }
    if (bVar2) {
      iVar3 = mac_auth_db_mlo_mac_get_bind_status
                        (local_4d0,local_4cc,local_4c8,local_4c4,local_4c0,local_4bc,
                         CONCAT13(local_4b8,(int3)in_stack_fffffb10),auStack_47c,&local_4d4);
    }
    else {
      iVar3 = mac_auth_db_mac_get_vlan_bind_status(param_1 + 0x68,local_4d8[0],auStack_47c);
    }
    if (iVar3 == 0) goto LAB_0044c7e4;
  }
  else {
    uVar4 = uac_wservice_get_wserv_id();
    if (uVar4 == 0xffffffff) {
      if (macauth_err_switch == 0) {
        return 0xffffffff;
      }
      printf("[MACAUTH_ERROR]%s()/%d wservice not found for [%d-%d-%d].\n","_uac_mac_auth_sta_check"
             ,0x9f,*(undefined4 *)(param_1 + 0x20),(uint)*(byte *)(param_1 + 0x24),
             (uint)*(byte *)(param_1 + 0x25));
      return 0xffffffff;
    }
    iVar3 = mac_auth_db_group_entry_get_by_ssid(uVar4,auStack_47c);
    if (iVar3 != 0) {
      if (macauth_debug_switch == 0) {
        return 0;
      }
      pcVar5 = "[MACAUTH_DEBUG]%s()/%d MAC auth is not enabled in ssid(%d).\n";
      uVar7 = 0xa4;
LAB_0044c89c:
      printf(pcVar5,"_uac_mac_auth_sta_check",uVar7,uVar4);
      return 0;
    }
    if (bVar2) {
      iVar3 = mac_auth_db_mlo_mac_get_bind_status
                        (local_4d0,local_4cc,local_4c8,local_4c4,local_4c0,local_4bc,
                         CONCAT13(local_4b8,(int3)in_stack_fffffb10),auStack_47c,&local_4d4);
      if (iVar3 == 0) goto LAB_0044c7e4;
      if (macauth_debug_switch != 0) {
        pcVar5 = "[MACAUTH_DEBUG]%s()/%d mac_auth_db_mlo_mac_get_bind_status() failed.\n";
        uVar7 = 0xb5;
LAB_0044c8e4:
        local_4d4 = 0;
        printf(pcVar5,"_uac_mac_auth_sta_check",uVar7);
        goto LAB_0044c7e4;
      }
    }
    else {
      iVar3 = mac_auth_db_mac_get_ssid_bind_status(param_1 + 0x68,uVar4 & 0xffff,auStack_47c);
      if (iVar3 == 0) goto LAB_0044c7e4;
      if (macauth_debug_switch != 0) {
        pcVar5 = "[MACAUTH_DEBUG]%s()/%d mac_auth_db_mac_get_ssid_bind_status() failed.\n";
        uVar7 = 0xad;
        goto LAB_0044c8e4;
      }
    }
  }
  local_4d4 = 0;
LAB_0044c7e4:
  if (local_4d4 == 0) {
    uac_wstation_free_sta_by_mac(param_1 + 0x68,1);
  }
  if (macauth_debug_switch == 0) {
    return 0;
  }
  if (local_4d4 == 0) {
    pcVar5 = "forbid";
  }
  else {
    pcVar5 = "passed";
  }
  printf("[MACAUTH_DEBUG]%s()/%d MACAUTH: STA [%02X:%02X:%02X:%02X:%02X:%02X] %s\n",
         "_uac_mac_auth_sta_check",0xbe,(uint)*(byte *)(param_1 + 0x68),
         (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
         (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
         (uint)*(byte *)(param_1 + 0x6d),pcVar5);
  return 0;
}

