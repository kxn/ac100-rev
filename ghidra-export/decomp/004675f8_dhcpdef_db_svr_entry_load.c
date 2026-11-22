// func dhcpdef_db_svr_entry_load @ 004675f8 size=484

undefined4 dhcpdef_db_svr_entry_load(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  uint *__dest;
  char *__format;
  undefined4 uVar6;
  
  if (param_1 == (uint *)0x0) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "entry";
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    uVar6 = 0x19b;
  }
  else {
    if ((-1 < (int)*param_1) && (*param_1 < l_dhcpdef_profile)) {
      FUN_004082d0(DAT_00767094,0xffffffff);
      __dest = (uint *)(DAT_007670a0 + *param_1 * 0xac);
      uVar3 = *__dest;
      if (((int)uVar3 < 0) || (l_dhcpdef_profile <= uVar3)) {
        memcpy(__dest,param_1,0xac);
        FUN_00408440(DAT_00767098,*param_1);
        DAT_0076709c = DAT_0076709c + 1;
        uVar6 = 0;
      }
      else {
        uVar6 = 0xffffffff;
        if ((g_dhcpdef_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("\x1b[31;49m[%s]<%s():%d> svr_id[%d] has been used!\x1b[0m\r\n","dhcp_defend",
                 "dhcpdef_db_svr_entry_load",0x19f,*param_1);
        }
      }
      FUN_00407f30(DAT_00767094);
      return uVar6;
    }
    if ((g_dhcpdef_error == 0) || (uVar3 = is_target_debug_ap(), uVar3 == 0)) {
      return 0xffffffff;
    }
    uVar1 = (uint)param_1 & 3;
    __format = "\x1b[31;49m[%s]<%s():%d> Invalid svr_id[%d]!\x1b[0m\r\n";
    uVar2 = (int)param_1 + 3U & 3;
    pcVar4 = (char *)((*(int *)((int)param_1 - uVar1) << uVar1 * 8 |
                      uVar3 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
                     *(uint *)(((int)param_1 + 3U) - uVar2) >> (3 - uVar2) * 8);
    uVar6 = 0x19c;
  }
  printf(__format,"dhcp_defend","dhcpdef_db_svr_entry_load",uVar6,pcVar4);
  return 0xffffffff;
}

