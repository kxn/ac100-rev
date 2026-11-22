// func wserv_db_entry_del @ 005ec8ec size=744

undefined4 wserv_db_entry_del(uint param_1)

{
  int iVar1;
  char *__format;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint local_res0 [4];
  
  local_res0[0] = param_1;
  if (((int)param_1 < 0) || (l_wserv_profile <= param_1)) {
    uVar6 = 0xffffffff;
    if (g_wserv_warning == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n";
    pcVar2 = "wserv_db_entry_del";
    uVar4 = 0x983;
    uVar5 = local_res0[0];
  }
  else {
    FUN_004082d0(DAT_007cbef0,0xffffffff);
    if (*(int *)(DAT_007cbefc + local_res0[0] * 0x21c + 0xc) == 0) {
      iVar1 = -1;
      if ((g_wserv_warning != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> entry.id[%d] is not used!\r\n","wserv_db_entry_del",
               0x98a,local_res0[0]);
      }
    }
    else {
      FUN_00408500();
      FUN_00407f40(g_wserv_hash,DAT_007cbefc + local_res0[0] * 0x21c + 0x10);
      FUN_004080f0(DAT_007cbef4,local_res0[0]);
      iVar1 = *(int *)(DAT_007cbefc + local_res0[0] * 0x21c + 0x218);
      if (iVar1 != 0) {
        FUN_00408570(iVar1,_wserv_del_rd_hash_cb,local_res0);
        FUN_00408310(*(undefined4 *)(DAT_007cbefc + local_res0[0] * 0x21c + 0x218));
        *(undefined4 *)(DAT_007cbefc + local_res0[0] * 0x21c + 0x218) = 0;
      }
      iVar1 = 0;
      *(undefined4 *)(DAT_007cbefc + local_res0[0] * 0x21c + 0xc) = 0;
      DAT_007cbef8 = DAT_007cbef8 + -1;
    }
    FUN_00407f30(DAT_007cbef0);
    uVar5 = local_res0[0];
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    uVar6 = 0;
    if ((-1 < (int)local_res0[0]) && (local_res0[0] < l_wserv_profile)) {
      if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> _wserv_do_del_event() do event[%s], wserv_id=%d.\r\n",
               "_wserv_do_del_event",0x481,"DELETE",uVar5);
      }
      if (DAT_007cbf50 == 0) {
        return 0;
      }
      for (iVar1 = FUN_004081b0(&DAT_007cbf48); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        if (*(code **)(iVar1 + 0x30) != (code *)0x0) {
          if ((*(int **)(iVar1 + 0x34) == (int *)0x0) ||
             (iVar3 = **(int **)(iVar1 + 0x34), iVar3 == 0)) {
            iVar3 = 0;
          }
          (**(code **)(iVar1 + 0x30))(uVar5,iVar3);
        }
      }
      return 0;
    }
    if (g_wserv_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "<wserv>[error]%s(): %d  -> invalid wserv id[%d].\r\n";
    pcVar2 = "_wserv_do_del_event";
    uVar4 = 0x47d;
  }
  printf(__format,pcVar2,uVar4,uVar5);
  return uVar6;
}

