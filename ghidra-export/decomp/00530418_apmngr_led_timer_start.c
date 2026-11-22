// func apmngr_led_timer_start @ 00530418 size=332

undefined4 apmngr_led_timer_start(uint param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_2f0 [445];
  undefined1 local_133;
  undefined1 auStack_132 [3];
  undefined1 local_12f;
  undefined1 auStack_12e [278];
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2f0,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f0);
  if (iVar1 == 0) {
    iVar2 = _apmngr_tmo_caculate(1,local_12f,auStack_12e);
    iVar3 = _apmngr_tmo_caculate(1,local_133,auStack_132);
    iVar1 = iVar2;
    if (iVar3 <= iVar2) {
      iVar1 = iVar3;
    }
    uVar4 = 1;
    uVar5 = iVar2 < iVar3 ^ 1;
    if (uVar5 != 0) {
      uVar4 = 2;
    }
    iVar1 = apmngr_db_ap_led_timer_start(param_1,iVar1,apmngr_led_timer_handler,uVar4);
    if (iVar1 == 0) {
      if (param_2 == (uint *)0x0) {
        return 0;
      }
      *param_2 = uVar5;
      return 0;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Failed to start led timer for ap %d.\n";
    uVar4 = 0xbda;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id failed: %d.\n";
    uVar4 = 0xbd4;
  }
  printf(__format,"apmngr_led_timer_start",uVar4,param_1);
  return 0xffffffff;
}

