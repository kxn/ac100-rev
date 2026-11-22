// func dhcpdef_sqlite_init @ 00472bbc size=896

undefined4 dhcpdef_sqlite_init(void)

{
  int iVar1;
  char *__format;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_sqlite_init",0x3be,
           "dhcpdef_sqlite_init");
  }
  if (l_sql_data == 0) {
    memset(&l_sql_data,0,0x20);
    DAT_007670c8 = FUN_00407f00("dhcpdef_sql_msg_mutex",0);
    if (DAT_007670c8 == 0) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar2 = "l_sql_data.msg_mutex";
        __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
        uVar4 = 0x3c8;
LAB_00472d24:
        printf(__format,"dhcp_defend","dhcpdef_sqlite_init",uVar4,pcVar2);
      }
    }
    else {
      DAT_007670cc = FUN_00407d80("dhcpdef_sql_msg_cond");
      if (DAT_007670cc == 0) {
        if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          pcVar2 = "l_sql_data.msg_cond";
          __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
          uVar4 = 0x3cb;
          goto LAB_00472d24;
        }
      }
      else {
        FUN_0051ad88(&DAT_007670bc);
        pcVar2 = (char *)_dhcpdef_sqlite_try_create_tbl();
        if (pcVar2 == (char *)0x0) {
          FUN_00408620("/etc/nouci_config/dbs/dhcpdef_bind.db",_dhcpdef_sqlite_get_msg_len);
          iVar1 = _dhcpdef_sqlite_open("/etc/nouci_config/dbs/dhcpdef_bind.db",&l_db_handle);
          if (iVar1 == 0) {
            iVar1 = FUN_004084e0(&DAT_007670d4,"dhcpdef_sql_thread",_dhcpdef_sqlite_thread_main,0);
            if (iVar1 == 0) {
              DAT_007670d0 = 1;
              l_sql_data = 1;
              uVar4 = 0;
              if (g_dhcpdef_info == 0) {
                l_sql_data = 1;
                DAT_007670d0 = 1;
                return 0;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                return 0;
              }
              pcVar2 = "[%s]<%s():%d> dhcpdef_sqlite_init() success.\r\n";
              uVar3 = 0x3e6;
              goto LAB_00472d4c;
            }
            if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar2 = "dhcpdef_sql_thread";
              __format = "\x1b[31;49m[%s]<%s():%d> create %s fail.\x1b[0m\r\n";
              uVar4 = 0x3df;
              goto LAB_00472d24;
            }
          }
          else if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            pcVar2 = "/etc/nouci_config/dbs/dhcpdef_bind.db";
            __format = "\x1b[31;49m[%s]<%s():%d> _dhcpdef_sqlite_open() fail, path=%s\x1b[0m\r\n";
            uVar4 = 0x3d8;
            goto LAB_00472d24;
          }
        }
        else if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          __format = "\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n";
          uVar4 = 0x3ce;
          goto LAB_00472d24;
        }
      }
    }
  }
  else if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("\x1b[31;49m[%s]<%s():%d> dhcpdef sqlite has inited.\x1b[0m\r\n","dhcp_defend",
           "dhcpdef_sqlite_init",0x3c2);
  }
  uVar4 = 0xffffffff;
  dhcpdef_sqlite_uninit();
  if (g_dhcpdef_error == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar2 = "\x1b[31;49m[%s]<%s():%d> dhcpdef_sqlite_init() fail.\x1b[0m\r\n";
  uVar3 = 0x3ec;
LAB_00472d4c:
  printf(pcVar2,"dhcp_defend","dhcpdef_sqlite_init",uVar3);
  return uVar4;
}

