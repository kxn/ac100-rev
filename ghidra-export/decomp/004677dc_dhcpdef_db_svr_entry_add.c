// func dhcpdef_db_svr_entry_add @ 004677dc size=452

uint dhcpdef_db_svr_entry_add(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *__dest;
  char *__format;
  undefined4 uVar4;
  
  if (param_1 == (uint *)0x0) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
           "dhcpdef_db_svr_entry_add",0x1b7,"entry");
    return 0xffffffff;
  }
  FUN_004082d0(DAT_00767094,0xffffffff);
  uVar1 = FUN_004085b0(DAT_00767098);
  *param_1 = uVar1;
  if (((int)uVar1 < 0) || (l_dhcpdef_profile <= uVar1)) {
    uVar1 = 0xffffffff;
    if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00467848;
    uVar3 = *param_1;
    __format = "\x1b[31;49m[%s]<%s():%d> Invalid svr_id[%d]!\x1b[0m\r\n";
    uVar4 = 0x1c0;
  }
  else {
    __dest = (uint *)(DAT_007670a0 + uVar1 * 0xac);
    uVar1 = *__dest;
    if (((int)uVar1 < 0) || (l_dhcpdef_profile <= uVar1)) {
      memcpy(__dest,param_1,0xac);
      DAT_0076709c = DAT_0076709c + 1;
      uVar1 = *param_1;
      goto LAB_00467848;
    }
    uVar1 = 0xffffffff;
    if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00467848;
    uVar3 = *param_1;
    __format = "\x1b[31;49m[%s]<%s():%d> svr_id[%d] has been used!\x1b[0m\r\n";
    uVar4 = 0x1c1;
  }
  uVar1 = 0xffffffff;
  printf(__format,"dhcp_defend","dhcpdef_db_svr_entry_add",uVar4,uVar3);
LAB_00467848:
  FUN_00407f30(DAT_00767094);
  return uVar1;
}

