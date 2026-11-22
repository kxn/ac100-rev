// func _wsta_roam_sta_tmprcd_idle_timer_handle @ 00480df0 size=252

void _wsta_roam_sta_tmprcd_idle_timer_handle(void)

{
  int iVar1;
  undefined4 extraout_v1;
  undefined4 local_18 [2];
  
  FUN_00407e70();
  local_18[0] = extraout_v1;
  if (wsta_roam_debug_switch != '\0') {
    printf("[WSTA_ROAM_DEBUG]%s()/%d wsta roam sta tmprcd idle time start\n",
           "_wsta_roam_sta_tmprcd_idle_timer_handle",0x14f);
  }
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  FUN_00408570(DAT_00767560,_wsta_roam_idle_tmprcd_delete,local_18);
  FUN_00407f30(l_wsta_roam_data);
  iVar1 = FUN_00408340(0x3c,0,_wsta_roam_sta_tmprcd_idle_timer_handle,0,0,
                       "_wsta_roam_sta_tmprcd_idle_timer_handle",0x155);
  if ((iVar1 == -1) && (wsta_roam_err_switch != '\0')) {
    printf("[WSTA_ROAM_ERROR]%s()/%d uac_timer_add() fail!\n",
           "_wsta_roam_sta_tmprcd_idle_timer_handle",0x158);
  }
  DAT_00767564 = iVar1;
  return;
}

