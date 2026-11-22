// func wserv_sqlite_load_rd @ 005f8b20 size=704

undefined4 wserv_sqlite_load_rd(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  int local_828;
  char acStack_824 [2056];
  
  local_828 = 0;
  memset(acStack_824,0,0x800);
  iVar1 = _wserv_sqlite_try_create_tbl();
  if (iVar1 == 0) {
    iVar1 = _wserv_sqlite_open("/etc/nouci_config/dbs/wserv_rd.db",&local_828);
    if (iVar1 == 0) {
      uVar6 = rdmngr_profile_get_max_wlan_per_rd();
      iVar1 = FUN_004082a0(uVar6,6,0x526);
      if (iVar1 != 0) {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        iVar4 = apmngr_db_get_sensor_max();
        iVar5 = rdmngr_profile_get_max_rd_per_ap();
        FUN_00408300(&g_invalid_rf_id,&g_invalid_rf_id_pos,(iVar2 + iVar3 + iVar4) * iVar5);
        snprintf(acStack_824,0x800,"select * from bind_tbl");
        iVar2 = FUN_00407fb0(local_828,acStack_824,_rd_for_each_cb,iVar1);
        if (iVar2 == 0) {
          iVar2 = FUN_00408490(g_invalid_rf_id,g_invalid_rf_id_pos,local_828,"bind_tbl","radio_id");
          if (0 < g_invalid_rf_id_pos) {
            FUN_00408400();
          }
          if (iVar2 == 0) {
            FUN_00407de0(&g_invalid_rf_id,&g_invalid_rf_id_pos);
            if (local_828 != 0) {
              FUN_004080b0();
              local_828 = 0;
            }
            FUN_00407df0(iVar1);
            return 0;
          }
        }
        else {
          iVar3 = FUN_00408410();
          if (iVar3 != 0) {
            printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n","wserv_sqlite_load_rd"
                   ,0x530,iVar2,acStack_824,"select wserv fail");
          }
        }
        goto LAB_005f8b80;
      }
      if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(&g_invalid_rf_id), iVar2 == 0))
      goto LAB_005f8b80;
      __format = "<wserv>[error]%s(): %d  -> no memory!\r\n";
      uVar6 = 0x529;
      goto LAB_005f8c58;
    }
    iVar1 = 0;
    if (g_wserv_error != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 != 0) {
        printf("<wserv>[error]%s(): %d  -> sqlite3_open() fail, path=%s\r\n","wserv_sqlite_load_rd",
               0x522,"/etc/nouci_config/dbs/wserv.db");
      }
      goto LAB_005f8b80;
    }
  }
  else {
    iVar1 = 0;
    if (g_wserv_error != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) goto LAB_005f8b80;
      __format = "<wserv>[error]%s(): %d  -> _wserv_sqlite_try_create_tbl() fail.\r\n";
      uVar6 = 0x51b;
LAB_005f8c58:
      printf(__format,"wserv_sqlite_load_rd",uVar6);
      goto LAB_005f8b80;
    }
  }
  iVar1 = 0;
LAB_005f8b80:
  FUN_00407de0(&g_invalid_rf_id,&g_invalid_rf_id_pos);
  if (local_828 != 0) {
    FUN_004080b0();
    local_828 = 0;
  }
  if (iVar1 != 0) {
    FUN_00407df0(iVar1);
  }
  return 0xffffffff;
}

