// func _dhcpdef_sqlite_try_create_tbl @ 00472048 size=1228

int _dhcpdef_sqlite_try_create_tbl(void)

{
  FILE *pFVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int local_418;
  char acStack_414 [1028];
  
  local_418 = 0;
  memset(acStack_414,0,0x400);
  pFVar1 = fopen("/etc/nouci_config/dbs/dhcpdef_svr.db","a+");
  if (pFVar1 == (FILE *)0x0) {
    iVar4 = -1;
    if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_004720f0;
    pcVar5 = "svr_db_file";
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    uVar3 = 0x1ac;
  }
  else {
    fclose(pFVar1);
    pFVar1 = fopen("/etc/nouci_config/dbs/dhcpdef_bind.db","a+");
    if (pFVar1 == (FILE *)0x0) {
      iVar4 = -1;
      if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_004720f0;
      __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
      pcVar5 = "bind_db_file";
      uVar3 = 0x1b0;
    }
    else {
      fclose(pFVar1);
      pcVar5 = (char *)_dhcpdef_sqlite_open("/etc/nouci_config/dbs/dhcpdef_svr.db",&local_418);
      if (pcVar5 == (char *)0x0) {
        if (local_418 == 0) {
          iVar4 = -1;
          if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_004720f0;
          pcVar5 = "db";
          __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
          uVar3 = 0x1b5;
        }
        else {
          snprintf(acStack_414,0x400,
                   "CREATE TABLE IF NOT EXISTS svr_tbl (svr_id INTEGER UNIQUE,name VARCHAR(%d) UNIQUE,addr_type INTEGER,svr_addr VARCHAR(%d) UNIQUE,priv_key INTEGER PRIMARY KEY AUTOINCREMENT);"
                   ,0xa0,0x28);
          pcVar5 = (char *)_dhcpdef_sqlite_exec(local_418,acStack_414);
          if (pcVar5 == (char *)0x0) {
            snprintf(acStack_414,0x400,
                     "CREATE INDEX IF NOT EXISTS svr_tbl_svr_id ON svr_tbl(svr_id);");
            pcVar5 = (char *)_dhcpdef_sqlite_exec(local_418,acStack_414);
            if (pcVar5 == (char *)0x0) {
              if (local_418 != 0) {
                FUN_004080b0();
                local_418 = 0;
              }
              pcVar5 = (char *)_dhcpdef_sqlite_open
                                         ("/etc/nouci_config/dbs/dhcpdef_bind.db",&local_418);
              if (pcVar5 == (char *)0x0) {
                if (local_418 == 0) {
                  iVar4 = -1;
                  if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                  goto LAB_004720f0;
                  pcVar5 = "db";
                  __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
                  uVar3 = 0x1cd;
                }
                else {
                  iVar4 = dhcpdef_db_get_max_svr_per_ap();
                  snprintf(acStack_414,0x400,
                           "CREATE TABLE IF NOT EXISTS bind_tbl (ap_id INTEGER UNIQUE,enable INTEGER,svr_ids VARCHAR(%d),priv_key INTEGER PRIMARY KEY AUTOINCREMENT);"
                           ,iVar4 * 6);
                  pcVar5 = (char *)_dhcpdef_sqlite_exec(local_418,acStack_414);
                  if (pcVar5 == (char *)0x0) {
                    snprintf(acStack_414,0x400,
                             "CREATE INDEX IF NOT EXISTS bind_tbl_ap_id ON bind_tbl(ap_id);");
                    iVar4 = _dhcpdef_sqlite_exec(local_418,acStack_414);
                    if (iVar4 != 0) {
                      if (g_dhcpdef_error == 0) {
                        iVar4 = -1;
                      }
                      else {
                        iVar2 = is_target_debug_ap();
                        if (iVar2 == 0) {
                          iVar4 = -1;
                        }
                        else {
                          printf("\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n",
                                 "dhcp_defend","_dhcpdef_sqlite_try_create_tbl",0x1dd,iVar4,
                                 "_dhcpdef_sqlite_exec(db, sql_cmd)");
                          iVar4 = -1;
                        }
                      }
                    }
                    goto LAB_004720f0;
                  }
                  iVar4 = -1;
                  if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                  goto LAB_004720f0;
                  __format = "\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n";
                  uVar3 = 0x1d6;
                }
              }
              else {
                iVar4 = -1;
                if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                goto LAB_004720f0;
                __format = "\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n";
                uVar3 = 0x1cc;
              }
            }
            else {
              iVar4 = -1;
              if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_004720f0;
              __format = "\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n";
              uVar3 = 0x1c7;
            }
          }
          else {
            iVar4 = -1;
            if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_004720f0;
            __format = "\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n";
            uVar3 = 0x1c0;
          }
        }
      }
      else {
        iVar4 = -1;
        if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_004720f0;
        __format = "\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n";
        uVar3 = 0x1b4;
      }
    }
  }
  printf(__format,"dhcp_defend","_dhcpdef_sqlite_try_create_tbl",uVar3,pcVar5);
  iVar4 = -1;
LAB_004720f0:
  if (local_418 != 0) {
    FUN_004080b0();
  }
  return iVar4;
}

