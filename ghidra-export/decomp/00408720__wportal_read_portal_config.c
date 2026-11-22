// func _wportal_read_portal_config @ 00408720 size=456

int _wportal_read_portal_config(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_420;
  int local_41c;
  char acStack_418 [1024];
  
  local_41c = 0;
  memset(acStack_418,0,0x400);
  local_420 = 0;
  iVar1 = FUN_0051eb48("wportal","portal_max",&local_420);
  if (iVar1 == 0) {
    iVar1 = FUN_00408130("/etc/nouci_config/dbs/portal.db",&local_41c,
                         uac_cfg_trigger_changed_by_restore);
    if (iVar1 == 0) {
      FUN_00408300(&g_invalid_portal_entry_id,&g_invalid_portal_entry_id_pos,local_420);
      snprintf(acStack_418,0x400,"SELECT * FROM %s","portalTable");
      iVar1 = FUN_00407fb0(local_41c,acStack_418,_wportal_db_sqlite_get_portal_cb,0);
      if (iVar1 == 0) {
        iVar2 = FUN_00408490(g_invalid_portal_entry_id,g_invalid_portal_entry_id_pos,local_41c,
                             "portalTable","entry_id");
        iVar1 = -1;
        if (0 < g_invalid_portal_entry_id_pos) {
          FUN_00408400();
        }
        if (iVar2 == 0) {
          iVar1 = 0;
        }
      }
      else {
        iVar2 = FUN_00408410();
        if (iVar2 != 0) {
          printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"get portalDb failed.\"\n",
                 "_wportal_read_portal_config",0x39f,iVar1,acStack_418);
        }
      }
    }
    FUN_00407de0(&g_invalid_portal_entry_id,&g_invalid_portal_entry_id_pos);
    if (local_41c != 0) {
      FUN_004080b0();
    }
  }
  else {
    iVar1 = -1;
    if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d get portal max size error.\n","_wportal_read_portal_config",0x398
            );
    }
  }
  return iVar1;
}

