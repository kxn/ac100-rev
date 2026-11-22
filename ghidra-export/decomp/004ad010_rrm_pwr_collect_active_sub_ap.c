// func rrm_pwr_collect_active_sub_ap @ 004ad010 size=1

undefined4 rrm_pwr_collect_active_sub_ap(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2e8 [20];
  int iStack_2d4;
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0xc),auStack_2e8);
  if (iVar1 == 0) {
    if (((iStack_2d4 == 4) || (iStack_2d4 == 8)) || (uVar2 = 0, iStack_2d4 == 6)) {
      iVar1 = rrm_pwr_collect_active_ap(auStack_2e8,param_2);
      uVar2 = 0;
      if ((iVar1 != 0) && (uVar2 = 2, iVar1 != 2)) {
        uVar2 = 1;
      }
    }
  }
  else {
    uVar2 = 1;
    if (rrm_err_switch != '\0') {
      printf("[RRM_ERROR]%s()/%d apmngr_db_entry_get_by_id of %d failed\n",
             "rrm_pwr_collect_active_sub_ap",0x495,(uint)*(ushort *)(param_1 + 0xc));
    }
  }
  return uVar2;
}

