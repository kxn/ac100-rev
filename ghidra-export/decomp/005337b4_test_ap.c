// func test_ap @ 005337b4 size=1

void test_ap(undefined1 *param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_2e0 [536];
  undefined1 auStack_c8 [192];
  
  memset(auStack_2e0,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id((uint)param_1 & 0xffff,auStack_2e0);
  if (iVar1 == 0) {
    if (apmngr_err_switch == '\0') {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    __format = "[APMNGR_ERROR]%s()/%d firmware_id:%s\n";
    uVar2 = 0xfb1;
    param_1 = auStack_c8;
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
    uVar2 = 0xfad;
  }
  printf(__format,"test_ap",uVar2,param_1);
  return;
}

