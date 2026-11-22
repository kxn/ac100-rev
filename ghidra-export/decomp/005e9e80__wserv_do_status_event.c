// func _wserv_do_status_event @ 005e9e80 size=376

undefined4 _wserv_do_status_event(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 < 6) {
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> _wserv_do_status_event() do event[%s], rd_id=%d, wlan_id=%u.\r\n"
             ,"_wserv_do_status_event",0x43a,(&PTR_DAT_006fa204)[param_1],param_2,param_3);
    }
    if (param_1 == 2) {
      puVar2 = &DAT_007cbf30;
    }
    else {
      if (param_1 != 3) {
        return 0xffffffff;
      }
      puVar2 = &DAT_007cbf3c;
    }
    uVar4 = 0;
    if (*(int *)(puVar2 + 8) != 0) {
      for (iVar1 = FUN_004081b0(); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        if (*(code **)(iVar1 + 0x30) != (code *)0x0) {
          if ((*(int **)(iVar1 + 0x34) == (int *)0x0) ||
             (iVar3 = **(int **)(iVar1 + 0x34), iVar3 == 0)) {
            iVar3 = 0;
          }
          (**(code **)(iVar1 + 0x30))(param_2,param_3,iVar3);
        }
      }
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[error]%s(): %d  -> invalid event[%d].\r\n","_wserv_do_status_event",0x437,
             param_1);
    }
  }
  return uVar4;
}

