// func _apmngr_pkt_ifindex_change_cb @ 0055ab6c size=520

undefined4 _apmngr_pkt_ifindex_change_cb(int param_1)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  undefined1 local_5d4 [28];
  undefined1 auStack_5b8 [16];
  ushort local_5a8;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  undefined4 local_340;
  undefined4 local_33c;
  short local_338;
  undefined1 auStack_2e0 [16];
  undefined2 local_2d0;
  short local_2c8;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  short local_60;
  
  memset(auStack_2e0,0,0x2d8);
  memset(auStack_5b8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_mac(param_1,auStack_2e0);
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0xc) == '\0') {
      for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
        local_5d4[uVar2] = *(undefined1 *)(param_1 + 0x10 + uVar2);
      }
      iVar1 = FUN_004085c0(local_74,local_70,local_6c,local_68,local_64);
      if ((iVar1 != 0) && (local_60 == *(short *)(param_1 + 0x24))) {
LAB_0055ad54:
        apmngr_pkt_ac_ipaddr_pkt_send
                  (local_2d0,*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
                   *(undefined4 *)(param_1 + 0x28));
        return 0;
      }
      if (apmngr_debug_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_DEBUG]%s()/%d The ap\'s ip&port do not match when ifindex change.\n";
      uVar3 = 0xbf7;
    }
    else {
      iVar1 = apmngr_db_entry_get_by_mac(param_1 + 6,auStack_5b8);
      if ((iVar1 == 0) && ((int)local_2c8 == (uint)local_5a8)) {
        for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
          local_5d4[uVar2] = *(undefined1 *)(param_1 + 0x10 + uVar2);
        }
        iVar1 = FUN_004085c0(local_34c,local_348,local_344,local_340,local_33c);
        if ((iVar1 != 0) && (local_338 == *(short *)(param_1 + 0x24))) goto LAB_0055ad54;
      }
      if (apmngr_warning_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_WARNING]%s()/%d Failed to find cap when ifindex change.\n";
      uVar3 = 0xbef;
    }
  }
  else {
    if ((apmngr_warning_switch == '\0') || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
      return 0xffffffff;
    }
    __format = "[APMNGR_WARNING]%s()/%d Failed to find ap when go to reset-state.\n";
    uVar3 = 0xbe7;
  }
  printf(__format,"_apmngr_pkt_ifindex_change_cb",uVar3);
  return 0xffffffff;
}

