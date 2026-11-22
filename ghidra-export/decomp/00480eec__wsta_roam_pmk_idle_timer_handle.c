// func _wsta_roam_pmk_idle_timer_handle @ 00480eec size=252

void _wsta_roam_pmk_idle_timer_handle(void)

{
  int iVar1;
  undefined4 extraout_v1;
  undefined4 local_18 [2];
  
  FUN_00407e70();
  local_18[0] = extraout_v1;
  if (wsta_roam_debug_switch != '\0') {
    printf("[WSTA_ROAM_DEBUG]%s()/%d wsta roam pmk idle time start\n",
           "_wsta_roam_pmk_idle_timer_handle",0xf7);
  }
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  FUN_00408570(DAT_0076754c,_wsta_roam_idle_pmk_delete,local_18);
  FUN_00407f30(l_wsta_roam_data);
  iVar1 = FUN_00408340(0x3c,0,_wsta_roam_pmk_idle_timer_handle,0,0,
                       "_wsta_roam_pmk_idle_timer_handle",0xfd);
  if ((iVar1 == -1) && (wsta_roam_err_switch != '\0')) {
    printf("[WSTA_ROAM_ERROR]%s()/%d uac_timer_add() fail!\n","_wsta_roam_pmk_idle_timer_handle",
           0x100);
  }
  DAT_00767554 = iVar1;
  return;
}

