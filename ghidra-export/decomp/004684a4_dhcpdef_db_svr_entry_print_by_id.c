// func dhcpdef_db_svr_entry_print_by_id @ 004684a4 size=1

undefined4 dhcpdef_db_svr_entry_print_by_id(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((int)param_1 < 0) || (l_dhcpdef_profile <= param_1)) {
    uVar2 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Invalid svr_id[%d]!\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_svr_entry_print_by_id",0x277,param_1);
    }
  }
  else {
    FUN_004082d0(DAT_00767094,0xffffffff);
    _dhcpdef_db_svr_entry_print(DAT_007670a0 + param_1 * 0xac);
    uVar2 = 0;
    FUN_00407f30(DAT_00767094);
  }
  return uVar2;
}

