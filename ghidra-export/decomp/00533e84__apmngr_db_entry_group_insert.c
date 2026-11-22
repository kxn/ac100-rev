// func _apmngr_db_entry_group_insert @ 00533e84 size=264

void _apmngr_db_entry_group_insert(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && ((int)(uint)*(ushort *)(param_1 + 0x12) < apmngr_group_num_max)) {
    iVar2 = g_apmngr_group_array + (uint)*(ushort *)(param_1 + 0x12) * 0x84 + 0x78;
    if ((*(int *)(param_1 + 0xc) == 0) && (iVar1 = FUN_004081b0(iVar2), iVar1 != 0)) {
      iVar3 = *(int *)(iVar1 + 0xc);
      while( true ) {
        if (iVar3 != 0) {
          FUN_00408170(iVar1,param_1);
          return;
        }
        iVar1 = FUN_00408680();
        if (iVar1 == 0) break;
        iVar3 = *(int *)(iVar1 + 0xc);
      }
    }
    FUN_004086b0(iVar2,param_1);
    return;
  }
  if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Invalid group id.\n","_apmngr_db_entry_group_insert",0x743);
    return;
  }
  return;
}

