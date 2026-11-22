// func _dhcpdef_sqlite_svr_entry_load_one @ 00471070 size=720

bool _dhcpdef_sqlite_svr_entry_load_one
               (undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  char *__s1;
  char *__nptr;
  int iVar2;
  char acStack_100 [39];
  undefined1 local_d9;
  int local_d8;
  char acStack_d4 [150];
  undefined1 local_3e;
  char local_3d;
  undefined1 auStack_3c [20];
  
  memset(&local_d8,0,0xac);
  memset(acStack_100,0,0x28);
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_dhcpdef_sqlite_svr_entry_load_one",0xa2,
           "_dhcpdef_sqlite_svr_entry_load_one");
  }
  memset(&local_d8,0,0xac);
  local_d8 = -1;
  memset(acStack_d4,0,0x97);
  local_3d = -1;
  iVar2 = 0;
  do {
    if (param_2 <= iVar2) {
      iVar2 = dhcpdef_db_svr_entry_load(&local_d8);
      return iVar2 != 0;
    }
    __s1 = (char *)*param_4;
    if ((__s1 == (char *)0x0) || (__nptr = (char *)*param_3, __nptr == (char *)0x0)) {
      if (g_dhcpdef_error == 0) {
        return true;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return true;
      }
      printf("\x1b[31;49m[%s]<%s():%d> column_name or column_value is null!\x1b[0m\r\n",
             "dhcp_defend","_dhcpdef_sqlite_svr_entry_load_one",0xaa);
      return true;
    }
    iVar1 = strcmp(__s1,"svr_id");
    if (iVar1 == 0) {
      local_d8 = atoi(__nptr);
    }
    else {
      iVar1 = strcmp(__s1,"name");
      if (iVar1 == 0) {
        strncpy(acStack_d4,__nptr,0x96);
        local_3e = 0;
      }
      else {
        iVar1 = strcmp(__s1,"addr_type");
        if (iVar1 == 0) {
          iVar1 = atoi(__nptr);
          local_3d = (char)iVar1;
        }
        else {
          iVar1 = strcmp(__s1,"svr_addr");
          if (iVar1 == 0) {
            strncpy(acStack_100,__nptr,0x27);
            local_d9 = 0;
            if (local_3d != '\x01') {
              local_3d = dhcpdef_str2iptype(acStack_100);
            }
            iVar1 = dhcpdef_str2addr((int)local_3d,acStack_100,auStack_3c);
            if (iVar1 != 0) {
              return true;
            }
          }
          else {
            iVar1 = strcmp(__s1,"priv_key");
            if (iVar1 != 0) {
              if (g_dhcpdef_error == 0) {
                return true;
              }
              iVar2 = is_target_debug_ap();
              if (iVar2 == 0) {
                return true;
              }
              printf("\x1b[31;49m[%s]<%s():%d> invalid column_name[%s]!\x1b[0m\r\n","dhcp_defend",
                     "_dhcpdef_sqlite_svr_entry_load_one",0xcb,*param_4);
              return true;
            }
          }
        }
      }
    }
    iVar2 = iVar2 + 1;
    param_4 = param_4 + 1;
    param_3 = param_3 + 1;
  } while( true );
}

