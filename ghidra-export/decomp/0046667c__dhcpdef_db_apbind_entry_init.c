// func _dhcpdef_db_apbind_entry_init @ 0046667c size=224

undefined4 _dhcpdef_db_apbind_entry_init(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  *param_1 = 0xffffffff;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined4 *)((int)param_1 + 9) = 0;
  uVar4 = 0;
  if (*(int *)((int)param_1 + 0xd) == 0) {
    uVar5 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "_dhcpdef_db_apbind_entry_init",0x2e5,"entry->svr_id_list");
    }
  }
  else {
    for (; uVar4 < DAT_0076708c != 0; uVar4 = uVar4 + 1) {
      uVar1 = (int)param_1 + 0xdU & 3;
      uVar2 = (uint)(param_1 + 4) & 3;
      *(undefined4 *)
       (uVar4 * 4 +
       ((*(int *)(((int)param_1 + 0xdU) - uVar1) << uVar1 * 8 |
        (uint)(uVar4 < DAT_0076708c) & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
       *(uint *)((int)(param_1 + 4) - uVar2) >> (3 - uVar2) * 8)) = 0xffffffff;
    }
    uVar5 = 0;
  }
  return uVar5;
}

