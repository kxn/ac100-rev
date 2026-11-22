// func _apmngr_pkt_enter_reset_cb @ 00554ae0 size=672

undefined4 _apmngr_pkt_enter_reset_cb(int param_1)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  uint local_5d4;
  int local_5d0;
  undefined1 auStack_5b8 [16];
  ushort local_5a8;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  undefined4 local_340;
  undefined4 local_33c;
  short local_338;
  undefined1 auStack_2e0 [16];
  undefined2 local_2d0 [2];
  int local_2cc;
  short local_2c8;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  ushort local_60;
  
  memset(auStack_2e0,0,0x2d8);
  memset(auStack_5b8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_mac(param_1,auStack_2e0);
  if (iVar1 != 0) {
    uVar4 = 0xffffffff;
    if (apmngr_warning_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_WARNING]%s()/%d Failed to find ap when go to reset-state.\n";
    uVar3 = 0xbbc;
    goto LAB_00554c38;
  }
  if (*(char *)(param_1 + 0xc) == '\0') {
    for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
      *(undefined1 *)((int)&local_5d4 + uVar2) = *(undefined1 *)(param_1 + 0x10 + uVar2);
    }
    iVar1 = FUN_004085c0(local_74,local_70,local_6c,local_68,local_64);
    if ((iVar1 == 0) || (local_60 != *(ushort *)(param_1 + 0x24))) {
      uVar4 = 0xffffffff;
      if (apmngr_warning_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_WARNING]%s()/%d The ap\'s ip&port do not match when go to reset-state.\n";
      uVar3 = 0xbcd;
      goto LAB_00554c38;
    }
LAB_00554cd0:
    apmngr_ap_try_delete(local_2d0[0]);
    local_5d4 = (uint)local_60;
    local_5d0 = param_1;
    _apmngr_delete_wtp_session(local_74,local_70,local_6c,local_68,local_64);
    if ((*(char *)(param_1 + 0xc) == '\0') &&
       (((local_2cc == 1 || (local_2cc == 3)) || (local_2cc == 2)))) {
      apmngr_db_foreach_proc(0x200000,_apmngr_child_router_enter_reset,local_2d0);
    }
    uVar4 = 0;
    if (apmngr_debug_switch == '\0') {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[APMNGR_DEBUG]%s()/%d _apmngr_pkt_enter_reset_cb success\n";
    uVar3 = 0xbdb;
  }
  else {
    iVar1 = apmngr_db_entry_get_by_mac(param_1 + 6,auStack_5b8);
    if ((iVar1 == 0) && (((int)local_2c8 == 0xffffffff || ((int)local_2c8 == (uint)local_5a8)))) {
      for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
        *(undefined1 *)((int)&local_5d4 + uVar2) = *(undefined1 *)(param_1 + 0x10 + uVar2);
      }
      iVar1 = FUN_004085c0(local_34c,local_348,local_344,local_340,local_33c);
      if ((iVar1 != 0) && (local_338 == *(short *)(param_1 + 0x24))) goto LAB_00554cd0;
    }
    uVar4 = 0xffffffff;
    if (apmngr_warning_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = 
    "[APMNGR_WARNING]%s()/%d Role is not right or failed to find cap when go to reset-state.\n";
    uVar3 = 0xbc5;
  }
LAB_00554c38:
  printf(__format,"_apmngr_pkt_enter_reset_cb",uVar3);
  return uVar4;
}

