// func apmngr_led_timer_handler @ 0052c8c0 size=328

void apmngr_led_timer_handler(ushort *param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  ushort local_2f0 [4];
  undefined1 auStack_2e8 [445];
  undefined1 local_12b;
  undefined1 auStack_12a [3];
  undefined1 local_127;
  undefined1 auStack_126 [206];
  undefined4 local_58;
  undefined1 local_54;
  
  memset(auStack_2e8,0,0x2d8);
  if (param_1 != (ushort *)0x0) {
    local_2f0[0] = *param_1;
    uVar4 = (uint)local_2f0[0];
    iVar1 = apmngr_db_entry_get_by_id(uVar4,auStack_2e8);
    if (iVar1 == 0) {
      apmngr_ap_led_update(local_2f0,1,local_54);
      local_58 = 0xffffffff;
      iVar2 = _apmngr_tmo_caculate(1,local_127,auStack_126);
      iVar1 = _apmngr_tmo_caculate(1,local_12b,auStack_12a);
      uVar3 = 2;
      if (iVar2 < iVar1) {
        uVar3 = 1;
        iVar1 = iVar2;
      }
      iVar1 = apmngr_db_ap_led_timer_start(uVar4,iVar1,apmngr_led_timer_handler,uVar3);
      if (iVar1 == 0) {
        return;
      }
      if (apmngr_err_switch == '\0') {
        return;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return;
      }
      __format = "[APMNGR_ERROR]%s()/%d Failed to start led timer for ap %d.\n";
      uVar3 = 0xbc8;
    }
    else {
      if (apmngr_err_switch == '\0') {
        return;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return;
      }
      __format = "[APMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id failed: %d.\n";
      uVar3 = 0xbbf;
    }
    printf(__format,"apmngr_led_timer_handler",uVar3,uVar4);
  }
  return;
}

