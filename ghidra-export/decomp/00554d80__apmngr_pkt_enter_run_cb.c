// func _apmngr_pkt_enter_run_cb @ 00554d80 size=828

undefined4 _apmngr_pkt_enter_run_cb(byte *param_1)

{
  int iVar1;
  byte bVar3;
  uint uVar2;
  char *__format;
  undefined4 uVar4;
  char *local_63c;
  byte *local_638;
  char *local_634;
  uint local_630;
  char *local_62c;
  undefined4 local_628;
  char local_618 [88];
  undefined1 auStack_5c0 [16];
  ushort local_5b0;
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  short local_340;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  undefined4 local_2d4;
  short local_2d0;
  char acStack_29a [542];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  short local_68;
  
  memset(auStack_2e8,0,0x2d8);
  memset(auStack_5c0,0,0x2d8);
  local_618[0] = '\0';
  local_618[1] = '\0';
  local_618[2] = '\0';
  local_618[3] = '\0';
  local_618[4] = '\0';
  local_618[5] = '\0';
  local_618[6] = '\0';
  local_618[7] = '\0';
  local_618[8] = '\0';
  local_618[9] = '\0';
  local_618[10] = '\0';
  local_618[0xb] = '\0';
  local_618[0xc] = '\0';
  local_618[0xd] = '\0';
  local_618[0xe] = '\0';
  local_618[0xf] = '\0';
  local_618[0x10] = '\0';
  local_618[0x11] = '\0';
  local_618[0x12] = '\0';
  local_618[0x13] = '\0';
  iVar1 = apmngr_db_entry_get_by_mac(param_1,auStack_2e8);
  if (iVar1 != 0) {
    if (apmngr_warning_switch == '\0') {
      bVar3 = param_1[0xc];
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        bVar3 = param_1[0xc];
      }
      else {
        printf("[APMNGR_WARNING]%s()/%d Failed to find ap when go to run-state.\n",
               "_apmngr_pkt_enter_run_cb",0xb7a);
        bVar3 = param_1[0xc];
      }
    }
    if (bVar3 != 0) {
      return 0xffffffff;
    }
    local_63c = (char *)(uint)*(ushort *)(param_1 + 0x24);
    local_638 = param_1;
    _apmngr_delete_wtp_session
              (*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
               *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
               *(undefined4 *)(param_1 + 0x20));
    return 0xffffffff;
  }
  if (param_1[0xc] == 0) {
    for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
      *(byte *)((int)&local_63c + uVar2) = param_1[uVar2 + 0x10];
    }
    iVar1 = FUN_004085c0(local_7c,local_78,local_74,local_70,local_6c);
    if ((iVar1 == 0) || (local_68 != *(short *)(param_1 + 0x24))) {
      if (apmngr_debug_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_DEBUG]%s()/%d The ap\'s ip&port do not match when go to run-state.\n";
      uVar4 = 0xb8e;
      goto LAB_00554e94;
    }
LAB_00554fcc:
    iVar1 = apmngr_ap_run_state_update(local_2d8,2);
    if (iVar1 == 0) {
      memset(local_618 + 0x14,0,0x40);
      local_63c = local_618 + 0x14;
      local_638 = (byte *)0x40;
      local_634 = "---";
      FUN_00408190(local_7c,local_78,local_74,local_70,local_6c);
      local_63c = (char *)(uint)param_1[2];
      local_638 = (byte *)(uint)param_1[3];
      local_634 = (char *)(uint)param_1[4];
      local_630 = (uint)param_1[5];
      snprintf(local_618,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_1,(uint)param_1[1]);
      uVar4 = apmngr_db_product_type_str_by_ap_role(local_2d4);
      local_63c = acStack_29a;
      local_634 = local_618 + 0x14;
      local_638 = (byte *)0x1;
      local_630 = 1;
      local_628 = 0;
      local_62c = local_618;
      loggerk_reg(0x53,0x3cf1,1,uVar4,1);
      return 0;
    }
  }
  else {
    iVar1 = apmngr_db_entry_get_by_mac(param_1 + 6,auStack_5c0);
    if ((iVar1 == 0) && ((int)local_2d0 == (uint)local_5b0)) {
      for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
        *(byte *)((int)&local_63c + uVar2) = param_1[uVar2 + 0x10];
      }
      iVar1 = FUN_004085c0(local_354,local_350,local_34c,local_348,local_344);
      if ((iVar1 != 0) && (local_340 == *(short *)(param_1 + 0x24))) goto LAB_00554fcc;
    }
    if (apmngr_warning_switch != '\0') {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_WARNING]%s()/%d Failed to find cap when go to reset-state.\n";
      uVar4 = 0xb86;
LAB_00554e94:
      printf(__format,"_apmngr_pkt_enter_run_cb",uVar4);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

