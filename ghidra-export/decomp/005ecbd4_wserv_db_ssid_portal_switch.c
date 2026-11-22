// func wserv_db_ssid_portal_switch @ 005ecbd4 size=400

int wserv_db_ssid_portal_switch(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_2f0 [592];
  uint local_a0;
  byte abStack_8d [121];
  
  memset(auStack_2f0,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2f0);
  if (iVar1 == -1) {
    iVar1 = -1;
    if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_ssid_portal_switch",
             0x9b7,param_1);
    }
  }
  else {
    iVar1 = 0;
    if ((local_a0 & 4) != 0) {
      iVar2 = apmngr_db_get_sub_capability_idx(2);
      if ((iVar2 != -1) && ((abStack_8d[iVar2 * 4] & 2) != 0)) {
        if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[debug]%s(): %d  -> _wserv_do_del_event() do event[%s], ap_id=%d.\r\n",
                 "_wserv_do_ssid_switch_event",0x4bf,"SSID_SWITCH",param_1);
        }
        iVar1 = 0;
        if (DAT_007cbf5c != 0) {
          for (iVar1 = FUN_004081b0(&DAT_007cbf54); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
            if (*(code **)(iVar1 + 0x30) != (code *)0x0) {
              if ((*(int **)(iVar1 + 0x34) == (int *)0x0) ||
                 (iVar2 = **(int **)(iVar1 + 0x34), iVar2 == 0)) {
                iVar2 = 0;
              }
              (**(code **)(iVar1 + 0x30))(param_1,param_2,iVar2);
            }
          }
        }
      }
    }
  }
  return iVar1;
}

