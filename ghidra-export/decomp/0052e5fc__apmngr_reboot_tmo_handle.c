// func _apmngr_reboot_tmo_handle @ 0052e5fc size=248

void _apmngr_reboot_tmo_handle(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d Warning: reboot timer timeout, reboot all ap NOW.\n",
           "_apmngr_reboot_tmo_handle",0x2b1);
  }
  iVar1 = apmngr_check_evt_notify(0,0);
  if (iVar1 == 0) {
    uVar2 = 0x3c;
    uVar3 = 0x2b4;
  }
  else {
    iVar1 = apmngr_reboot_all_ap(2,0);
    uVar2 = 0x1e;
    if (iVar1 == 0) {
      uVar2 = _apmngr_tmo_caculate(1,g_apmngr_reboot_date,&g_apmngr_reboot_time);
    }
    uVar3 = 0x2bd;
  }
  g_apmngr_reboot_timer =
       FUN_00408340(uVar2,0,_apmngr_reboot_tmo_handle,0,0,"_apmngr_reboot_tmo_handle",uVar3);
  return;
}

