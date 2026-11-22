// func dhcpdef_db_svr_entry_del @ 004679a0 size=432

undefined4 dhcpdef_db_svr_entry_del(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_svr_entry_del",0x1d5,
           "dhcpdef_db_svr_entry_del");
  }
  if (((int)param_1 < 0) || (l_dhcpdef_profile <= param_1)) {
    uVar3 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Invalid svr_id[%d]!\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_svr_entry_del",0x1d7,param_1);
    }
  }
  else {
    FUN_004082d0(DAT_00767094,0xffffffff);
    uVar2 = *(uint *)(DAT_007670a0 + param_1 * 0xac);
    if (((int)uVar2 < 0) || (l_dhcpdef_profile <= uVar2)) {
      uVar3 = 0xffffffff;
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> svr_id[%d] is not used!\x1b[0m\r\n","dhcp_defend",
               "dhcpdef_db_svr_entry_del",0x1da,param_1);
      }
    }
    else {
      FUN_004080f0(DAT_00767098,param_1);
      _dhcpdef_db_svr_entry_init(DAT_007670a0 + param_1 * 0xac);
      DAT_0076709c = DAT_0076709c + -1;
      uVar3 = 0;
    }
    FUN_00407f30(DAT_00767094);
  }
  return uVar3;
}

