// func _multi_link_reboot_tmo_handle @ 00663688 size=96

void _multi_link_reboot_tmo_handle(void)

{
  int iVar1;
  
  iVar1 = apmngr_reboot_all_ap(3,0);
  if (iVar1 != 0) {
    g_multi_link_reboot_timer =
         FUN_00408340(0x1e,0,_multi_link_reboot_tmo_handle,0,0,"_multi_link_reboot_tmo_handle",0x23c
                     );
  }
  return;
}

