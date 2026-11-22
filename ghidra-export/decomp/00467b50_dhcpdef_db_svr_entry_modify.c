// func dhcpdef_db_svr_entry_modify @ 00467b50 size=652

undefined4 dhcpdef_db_svr_entry_modify(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint *__s1;
  char *__format;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (param_1 == (uint *)0x0) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "entry";
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    uVar7 = 0x1f8;
LAB_00467ca0:
    printf(__format,"dhcp_defend","dhcpdef_db_svr_entry_modify",uVar7,pcVar5);
    return 0xffffffff;
  }
  if (((int)*param_1 < 0) || (l_dhcpdef_profile <= *param_1)) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    uVar3 = is_target_debug_ap();
    if (uVar3 == 0) {
      return 0xffffffff;
    }
    uVar1 = (uint)param_1 & 3;
    __format = "\x1b[31;49m[%s]<%s():%d> Invalid svr_id[%d]!\x1b[0m\r\n";
    uVar2 = (int)param_1 + 3U & 3;
    pcVar5 = (char *)((*(int *)((int)param_1 - uVar1) << uVar1 * 8 |
                      uVar3 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
                     *(uint *)(((int)param_1 + 3U) - uVar2) >> (3 - uVar2) * 8);
    uVar7 = 0x1f9;
    goto LAB_00467ca0;
  }
  FUN_004082d0(DAT_00767094,0xffffffff);
  __s1 = (uint *)(DAT_007670a0 + *param_1 * 0xac);
  uVar3 = *__s1;
  if (((int)uVar3 < 0) || (l_dhcpdef_profile <= uVar3)) {
    uVar7 = 0xffffffff;
    if ((g_dhcpdef_error == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00467d10;
    uVar3 = *param_1;
    pcVar5 = "\x1b[31;49m[%s]<%s():%d> svr_id[%d] is not used!\x1b[0m\r\n";
    uVar6 = 0x1fc;
  }
  else {
    iVar4 = memcmp(__s1,param_1,0xac);
    if (iVar4 != 0) {
      if (g_dhcpdef_info == 0) {
        uVar3 = *param_1;
      }
      else {
        iVar4 = is_target_debug_ap();
        uVar3 = *param_1;
        if (iVar4 != 0) {
          printf("[%s]<%s():%d> server entry[%d] something has changed\r\n","dhcp_defend",
                 "dhcpdef_db_svr_entry_modify",0x200,uVar3);
          uVar3 = *param_1;
        }
      }
      uVar7 = 0;
      memcpy((void *)(DAT_007670a0 + uVar3 * 0xac),param_1,0xac);
      goto LAB_00467d10;
    }
    uVar7 = 0;
    if ((g_dhcpdef_info == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00467d10;
    uVar3 = *param_1;
    pcVar5 = "[%s]<%s():%d> server entry[%d] nothing changed\r\n";
    uVar6 = 0x205;
  }
  printf(pcVar5,"dhcp_defend","dhcpdef_db_svr_entry_modify",uVar6,uVar3);
LAB_00467d10:
  FUN_00407f30(DAT_00767094);
  return uVar7;
}

