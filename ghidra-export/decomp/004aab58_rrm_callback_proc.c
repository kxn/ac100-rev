// func rrm_callback_proc @ 004aab58 size=236

undefined4 rrm_callback_proc(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = 0;
  iVar1 = FUN_004081b0(&g_rrm_cb_list);
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 == 0) {
      pcVar3 = *(code **)(iVar1 + 0x10);
LAB_004aabb4:
      if (pcVar3 != (code *)0x0) {
        iVar2 = (*pcVar3)();
      }
    }
    else if (param_1 == 1) {
      pcVar3 = *(code **)(iVar1 + 0x14);
      goto LAB_004aabb4;
    }
    if ((iVar2 != 0) && (rrm_err_switch != '\0')) {
      printf("[RRM_ERROR]%s()/%d Failed to proc %d callback of [%s].\n","rrm_callback_proc",0x171,
             param_1,*(undefined4 *)(iVar1 + 0xc));
    }
    iVar1 = FUN_00408680(iVar1);
  } while( true );
}

