// func uac_dhcpdef_uninit @ 00466520 size=248

int uac_dhcpdef_uninit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = dhcpdef_sqlite_uninit();
  if (iVar1 == 0) {
    iVar3 = dhcpdef_db_uninit();
    if (iVar3 != 0) {
      if (g_dhcpdef_error == 0) {
        iVar3 = -1;
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          iVar3 = -1;
        }
        else {
          printf("\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n","dhcp_defend",
                 "uac_dhcpdef_uninit",0x9c5,iVar3,"dhcpdef_db_uninit()");
          iVar3 = -1;
        }
      }
    }
  }
  else {
    iVar3 = -1;
    if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n","dhcp_defend",
             "uac_dhcpdef_uninit",0x9c4,iVar1,"dhcpdef_sqlite_uninit()");
    }
  }
  return iVar3;
}

