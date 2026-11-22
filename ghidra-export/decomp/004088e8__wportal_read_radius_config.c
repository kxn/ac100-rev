// func _wportal_read_radius_config @ 004088e8 size=232

int _wportal_read_radius_config(void)

{
  int iVar1;
  int iVar2;
  int local_418;
  char acStack_414 [1032];
  
  local_418 = 0;
  memset(acStack_414,0,0x400);
  iVar1 = FUN_00408130("/etc/nouci_config/dbs/auth_server.db",&local_418,
                       uac_cfg_trigger_changed_by_restore);
  if (iVar1 == 0) {
    snprintf(acStack_414,0x400,"SELECT * FROM %s","radiusTable");
    iVar1 = FUN_00407fb0(local_418,acStack_414,_wportal_db_sqlite_get_radius_cb,0);
    if ((iVar1 != 0) && (iVar2 = FUN_00408410(), iVar2 != 0)) {
      printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"Read radius failed.\"\n",
             "_wportal_read_radius_config",0x436,iVar1,acStack_414);
    }
  }
  if (local_418 != 0) {
    FUN_004080b0();
  }
  return iVar1;
}

