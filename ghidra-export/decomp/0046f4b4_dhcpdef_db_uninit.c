// func dhcpdef_db_uninit @ 0046f4b4 size=352

undefined4 dhcpdef_db_uninit(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (l_dhcpdef_data == 0) {
    if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> dhcpdef data has not been inited yet!\x1b[0m\r\n",
             "dhcp_defend","dhcpdef_db_uninit",0x868);
    }
  }
  else {
    if (DAT_007670a0 != 0) {
      FUN_00407df0();
      DAT_007670a0 = 0;
    }
    DAT_0076709c = 0;
    if (l_dhcpdef_svrid_list != 0) {
      FUN_00407df0();
      l_dhcpdef_svrid_list = 0;
    }
    uVar3 = 0;
    if (DAT_007670a8 != 0) {
      while( true ) {
        uVar1 = dhcpdef_db_get_max_ap();
        iVar2 = uVar3 * 0x11;
        if (uVar1 <= uVar3) break;
        uVar3 = uVar3 + 1;
        *(undefined4 *)(DAT_007670a8 + iVar2 + 0xd) = 0;
      }
      FUN_00407df0(DAT_007670a8);
      DAT_007670a8 = 0;
    }
    DAT_007670a4 = 0;
    if (DAT_00767098 != 0) {
      FUN_00408160();
      DAT_00767098 = 0;
    }
    if (DAT_00767094 == 0) {
      l_dhcpdef_data = 0;
    }
    else {
      FUN_00408360();
      DAT_00767094 = 0;
      l_dhcpdef_data = 0;
    }
  }
  return 0;
}

