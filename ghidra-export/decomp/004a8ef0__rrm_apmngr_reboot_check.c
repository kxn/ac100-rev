// func _rrm_apmngr_reboot_check @ 004a8ef0 size=104

undefined4 _rrm_apmngr_reboot_check(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  iVar1 = rrm_db_state_get();
  if (((iVar1 != 0) && (iVar1 != 7)) && (uVar2 = 0, rrm_debug_switch != '\0')) {
    printf("[RRM_DEBUG]%s()/%d RRM state is %d,can,t reboot now\n","_rrm_apmngr_reboot_check",0xa3c,
           iVar1);
  }
  return uVar2;
}

