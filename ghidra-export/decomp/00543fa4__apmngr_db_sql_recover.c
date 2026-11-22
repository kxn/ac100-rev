// func _apmngr_db_sql_recover @ 00543fa4 size=648

int _apmngr_db_sql_recover(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined **ppuVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_438;
  undefined4 local_434;
  int local_430;
  char acStack_42c [1028];
  
  uVar6 = 0xffffffff;
  iVar5 = 0;
  ppuVar4 = &g_apmngr_sql_entry;
  memset(acStack_42c,0,0x400);
  local_434 = 0;
  local_430 = 0;
  local_438 = 1;
  do {
    if (ppuVar4[2] != (undefined *)0x0) {
      if (uVar6 < 2) {
        iVar1 = apmngr_db_get_template_max();
        iVar2 = apmngr_db_get_ap_max();
        FUN_00408300(&local_434,&local_430,iVar1 + iVar2);
        puVar3 = *ppuVar4;
      }
      else {
        puVar3 = *ppuVar4;
      }
      snprintf(acStack_42c,0x400," SELECT * FROM %s;",puVar3);
      if (apmngr_debug_switch == '\0') {
        puVar3 = ppuVar4[1];
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          puVar3 = ppuVar4[1];
        }
        else {
          printf("[APMNGR_DEBUG]%s()/%d [SQL Command] %s\n\n","_apmngr_db_sql_recover",0x5c3,
                 acStack_42c);
          puVar3 = ppuVar4[1];
        }
      }
      iVar1 = FUN_00407fb0((&g_apmngr_db)[(int)puVar3],acStack_42c,ppuVar4[2],&local_438);
      if (iVar1 != 0) {
        iVar2 = FUN_00408410();
        if (iVar2 == 0) {
          return iVar1;
        }
        printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"Failed to recover %s.\"\n",
               "_apmngr_db_sql_recover",0x5c5,iVar1,acStack_42c,(&g_apmngr_sql_entry)[iVar5 * 3]);
        return iVar1;
      }
      if (uVar6 < 2) {
        iVar1 = FUN_00408490(local_434,local_430,(&g_apmngr_db)[(int)ppuVar4[1]],*ppuVar4,"entry_id"
                            );
        if (iVar1 != 0) {
LAB_005441c8:
          FUN_00407de0(&local_434,&local_430);
          return iVar1;
        }
        if (0 < local_430) {
          FUN_00408400();
        }
        if ((iVar5 == 2) &&
           (iVar1 = FUN_00408490(local_434,local_430,(&g_apmngr_db)[DAT_0074c0d4],
                                 PTR_s_ApEntryRun_table_0074c0d0,"entry_id"), iVar1 != 0))
        goto LAB_005441c8;
        FUN_00407de0(&local_434,&local_430);
      }
    }
    iVar5 = iVar5 + 1;
    ppuVar4 = ppuVar4 + 3;
    uVar6 = uVar6 + 1;
    if (iVar5 == 5) {
      return 0;
    }
  } while( true );
}

