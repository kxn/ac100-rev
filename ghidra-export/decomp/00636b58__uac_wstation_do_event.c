// func _uac_wstation_do_event @ 00636b58 size=340

undefined4 _uac_wstation_do_event(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 < 3) {
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> do event[%d].\r\n","_uac_wstation_do_event",0x2be,param_1)
      ;
    }
    if (param_1 == 1) {
      puVar2 = &DAT_007cc6f4;
    }
    else if (param_1 == 2) {
      puVar2 = &DAT_007cc700;
    }
    else {
      puVar2 = &DAT_007cc6e8;
    }
    uVar4 = 0;
    if (*(int *)(puVar2 + 8) != 0) {
      for (iVar1 = FUN_004081b0(); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        if ((*(int **)(iVar1 + 0x34) == (int *)0x0) ||
           (iVar3 = **(int **)(iVar1 + 0x34), iVar3 == 0)) {
          iVar3 = 0;
        }
        (**(code **)(iVar1 + 0x30))(param_2,iVar3);
      }
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[error]%s(): %d  -> invalid event[%d].\r\n","_uac_wstation_do_event",0x2ba,
             param_1);
    }
  }
  return uVar4;
}

