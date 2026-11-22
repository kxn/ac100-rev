// func wportal_db_foreach_event_list @ 00433984 size=216

int wportal_db_foreach_event_list(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 < 2) && (param_2 != 0)) {
    for (iVar2 = FUN_004081b0(&g_wportal_event_list); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
      if (*(uint *)(iVar2 + 0x30) == param_1) {
        (**(code **)(iVar2 + 0x34))(param_2,*(undefined4 *)(iVar2 + 0x38),param_3);
      }
    }
  }
  else {
    iVar2 = -1;
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Param is invalid.\n","wportal_db_foreach_event_list",0x1b87);
    }
  }
  return iVar2;
}

