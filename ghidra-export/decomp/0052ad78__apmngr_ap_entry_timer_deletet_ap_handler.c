// func _apmngr_ap_entry_timer_deletet_ap_handler @ 0052ad78 size=240

void _apmngr_ap_entry_timer_deletet_ap_handler(ushort *param_1)

{
  int iVar1;
  ushort local_2e8 [4];
  undefined1 auStack_2e0 [728];
  
  memset(auStack_2e0,0,0x2d8);
  if (param_1 != (ushort *)0x0) {
    local_2e8[0] = *param_1;
    iVar1 = apmngr_db_entry_get_by_id(local_2e8[0],auStack_2e0);
    if (iVar1 == 0) {
      apmngr_evt_notify(3,auStack_2e0);
      apmngr_db_entry_delete(local_2e8[0]);
      apmngr_db_id_free(1,local_2e8[0]);
      apmngr_db_sync_ap_entry_del(local_2e8,1,1);
      apmngr_db_datasync_ap_entry_del(local_2e8,1,1);
      apmngr_db_ap_entry_timer_stop(local_2e8[0],0);
      apmngr_db_ap_entry_timer_time_set(local_2e8[0],0,0);
    }
    else if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id failed: %d.\n",
             "_apmngr_ap_entry_timer_deletet_ap_handler",0xbf3,(uint)local_2e8[0]);
    }
  }
  return;
}

