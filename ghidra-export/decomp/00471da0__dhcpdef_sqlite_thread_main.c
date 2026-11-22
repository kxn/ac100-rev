// func _dhcpdef_sqlite_thread_main @ 00471da0 size=456

void _dhcpdef_sqlite_thread_main(void)

{
  int iVar1;
  int iVar2;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> %s() start.\r\n","dhcp_defend","_dhcpdef_sqlite_thread_main",0x2ef,
           "_dhcpdef_sqlite_thread_main");
  }
  do {
    FUN_004082d0(DAT_007670c8,0xffffffff);
    while (iVar1 = FUN_004081b0(&DAT_007670bc), iVar1 == 0) {
      FUN_004086c0(DAT_007670cc,DAT_007670c8,0xffffffff);
    }
    FUN_00408500(iVar1);
    FUN_00407f30(DAT_007670c8);
    if (*(int *)(iVar1 + 0x10) == 0) {
      if (g_dhcpdef_error == 0) {
        iVar2 = *(int *)(iVar1 + 0x10);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar1 + 0x10);
        }
        else {
          printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
                 "_dhcpdef_sqlite_do",0x2c5,"msg && msg->data");
          iVar2 = *(int *)(iVar1 + 0x10);
        }
      }
    }
    else {
      iVar2 = *(int *)(iVar1 + 0xc);
      if (iVar2 == 1) {
        _dhcpdef_sqlite_do_delete();
        iVar2 = *(int *)(iVar1 + 0x10);
      }
      else if (iVar2 < 2) {
        if (iVar2 == 0) {
          _dhcpdef_sqlite_do_insert();
          iVar2 = *(int *)(iVar1 + 0x10);
        }
        else {
          iVar2 = *(int *)(iVar1 + 0x10);
        }
      }
      else if (iVar2 == 2) {
        _dhcpdef_sqlite_do_del_ins();
        iVar2 = *(int *)(iVar1 + 0x10);
      }
      else if (iVar2 == 3) {
        _dhcpdef_sqlite_do_update();
        iVar2 = *(int *)(iVar1 + 0x10);
      }
      else {
        iVar2 = *(int *)(iVar1 + 0x10);
      }
    }
    if (iVar2 != 0) {
      FUN_00407df0();
      *(undefined4 *)(iVar1 + 0x10) = 0;
    }
    FUN_00407df0(iVar1);
  } while( true );
}

