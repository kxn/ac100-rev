// func apmngr_db_debug_entry_show @ 00542e34 size=1

/* WARNING: Removing unreachable block (ram,0x00538448) */
/* WARNING: Removing unreachable block (ram,0x00538458) */
/* WARNING: Removing unreachable block (ram,0x00538460) */
/* WARNING: Removing unreachable block (ram,0x00538468) */

int apmngr_db_debug_entry_show(void)

{
  bool bVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  
  puVar2 = (undefined2 *)FUN_00408450(apmngr_group_num_max << 1,0x4d5);
  if (puVar2 == (undefined2 *)0x0) {
    iVar3 = 1;
    if ((apmngr_err_switch != '\0') && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      iVar3 = 1;
      printf("[APMNGR_ERROR]%s()/%d Malloc groud ids failed.\n","apmngr_db_foreach_proc",0x4d8);
    }
  }
  else {
    iVar7 = 0;
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    iVar3 = FUN_004081b0(&g_apmngr_group_list);
    if (iVar3 != 0) {
      uVar4 = *(undefined2 *)(iVar3 + 0xc);
      puVar5 = puVar2;
      while( true ) {
        iVar7 = iVar7 + 1;
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
        iVar3 = FUN_00408680(iVar3);
        if (iVar3 == 0) break;
        uVar4 = *(undefined2 *)(iVar3 + 0xc);
      }
    }
    iVar3 = 0;
    iVar6 = 0;
    FUN_00407f30(apmngr_db_mutex);
    bVar1 = 0 < iVar7;
    puVar5 = puVar2;
    while (bVar1) {
      iVar3 = apmngr_db_foreach_proc_by_group(*puVar5,0xffffffff,_apmngr_db_entry_printf_pf,0);
      puVar5 = puVar5 + 1;
      if (iVar3 == 2) break;
      iVar6 = iVar6 + 1;
      bVar1 = iVar6 < iVar7;
    }
    FUN_00407df0(puVar2);
  }
  return iVar3;
}

