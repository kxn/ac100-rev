// func dhcpdef_db_apbind_entry_shallow_copy @ 0046863c size=1

undefined4 dhcpdef_db_apbind_entry_shallow_copy(void *param_1,void *param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint unaff_s1;
  uint uVar5;
  
  if ((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) {
    uVar4 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "dhcpdef_db_apbind_entry_shallow_copy",0x2f8,"dst && src");
    }
  }
  else {
    uVar1 = (int)param_1 + 0xdU & 3;
    uVar5 = (int)param_1 + 0x10U & 3;
    uVar5 = (*(int *)(((int)param_1 + 0xdU) - uVar1) << uVar1 * 8 |
            unaff_s1 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar5 + 1) * 8 |
            *(uint *)(((int)param_1 + 0x10U) - uVar5) >> (3 - uVar5) * 8;
    memcpy(param_1,param_2,0x11);
    uVar1 = (int)param_1 + 0xdU & 3;
    puVar2 = (uint *)(((int)param_1 + 0xdU) - uVar1);
    *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | uVar5 >> uVar1 * 8;
    uVar1 = (int)param_1 + 0x10U & 3;
    puVar2 = (uint *)(((int)param_1 + 0x10U) - uVar1);
    *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | uVar5 << (3 - uVar1) * 8;
    uVar4 = 0;
  }
  return uVar4;
}

