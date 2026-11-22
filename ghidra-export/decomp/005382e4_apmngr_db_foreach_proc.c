// func apmngr_db_foreach_proc @ 005382e4 size=424

int apmngr_db_foreach_proc(undefined4 param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 uVar4;
  char *__format;
  undefined4 uVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  
  if (param_2 == 0) {
    if (apmngr_err_switch == '\0') {
      return 1;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 1;
    }
    __format = "[APMNGR_ERROR]%s()/%d Callback is null.\n";
    uVar5 = 0x4d1;
  }
  else {
    puVar2 = (undefined2 *)FUN_00408450(apmngr_group_num_max << 1,0x4d5);
    if (puVar2 != (undefined2 *)0x0) {
      iVar8 = 0;
      FUN_004082d0(apmngr_db_mutex,0xffffffff);
      iVar3 = FUN_004081b0(&g_apmngr_group_list);
      if (iVar3 != 0) {
        uVar4 = *(undefined2 *)(iVar3 + 0xc);
        puVar6 = puVar2;
        while( true ) {
          iVar8 = iVar8 + 1;
          *puVar6 = uVar4;
          puVar6 = puVar6 + 1;
          iVar3 = FUN_00408680(iVar3);
          if (iVar3 == 0) break;
          uVar4 = *(undefined2 *)(iVar3 + 0xc);
        }
      }
      iVar3 = 0;
      iVar7 = 0;
      FUN_00407f30(apmngr_db_mutex);
      bVar1 = 0 < iVar8;
      puVar6 = puVar2;
      while (bVar1) {
        iVar3 = apmngr_db_foreach_proc_by_group(*puVar6,param_1,param_2,param_3);
        puVar6 = puVar6 + 1;
        if (iVar3 == 2) break;
        iVar7 = iVar7 + 1;
        bVar1 = iVar7 < iVar8;
      }
      FUN_00407df0(puVar2);
      return iVar3;
    }
    if (apmngr_err_switch == '\0') {
      return 1;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 1;
    }
    __format = "[APMNGR_ERROR]%s()/%d Malloc groud ids failed.\n";
    uVar5 = 0x4d8;
  }
  printf(__format,"apmngr_db_foreach_proc",uVar5);
  return 1;
}

