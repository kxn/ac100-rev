// func bssid_changed_callback_proc @ 0066871c size=288

undefined4 bssid_changed_callback_proc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined1 auStack_2f8 [728];
  
  memset(auStack_2f8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_2,auStack_2f8);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d get ap entry by id failed.\n",
             "bssid_changed_callback_proc",0x110);
    }
  }
  else {
    uVar2 = 0;
    iVar1 = FUN_004081b0(&g_bssid_changed_callback_list);
    for (; iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      if (param_1 == 1) {
        pcVar3 = *(code **)(iVar1 + 0x14);
LAB_006687ac:
        uVar2 = 0;
        if (pcVar3 != (code *)0x0) {
          uVar2 = (*pcVar3)(auStack_2f8);
        }
      }
      else {
        if (param_1 == 0) {
          pcVar3 = *(code **)(iVar1 + 0x18);
          goto LAB_006687ac;
        }
        uVar2 = 0;
        if (param_1 == 2) {
          pcVar3 = *(code **)(iVar1 + 0x1c);
          goto LAB_006687ac;
        }
      }
    }
  }
  return uVar2;
}

