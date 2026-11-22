// func wportal_db_event_register @ 00433848 size=316

undefined4 wportal_db_event_register(void *param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  if (((param_1 == (void *)0x0) || (*(int *)((int)param_1 + 0x24) < 0)) ||
     (1 < *(int *)((int)param_1 + 0x24))) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d Params is invalid.\n";
    uVar3 = 0x1b5b;
  }
  else {
    iVar1 = FUN_00408450(0x3c,0x1b5f);
    if (iVar1 != 0) {
      memcpy((void *)(iVar1 + 0xc),param_1,0x30);
      iVar2 = FUN_004081b0(&g_wportal_event_list);
      while( true ) {
        if (iVar2 == 0) {
          FUN_004086b0(&g_wportal_event_list,iVar1);
          return 0;
        }
        if (*(int *)(iVar2 + 0x2c) <= *(int *)((int)param_1 + 0x20)) break;
        iVar2 = FUN_00408680();
      }
      FUN_00408170(iVar2,iVar1);
      return 0;
    }
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d Memory is not enough.\n";
    uVar3 = 0x1b62;
  }
  printf(__format,"wportal_db_event_register",uVar3);
  return 0xffffffff;
}

