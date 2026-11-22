// func apdb_hwver_exist_by_id @ 0060ae90 size=424

undefined4 apdb_hwver_exist_by_id(undefined4 param_1,short *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  
  if (param_2 == (short *)0x0) {
    if (apdb_warning_switch != 0) {
      printf("[APDB_WARNING]%s()/line %d : Input error.\n","apdb_hwver_exist_by_id",0x2a0d);
    }
  }
  else {
    FUN_004082d0(l_apdb_mutex,0xffffffff);
    iVar1 = _apdb_ap_item_get_index_by_id(param_1);
    if (iVar1 == -1) {
      FUN_00407f30(l_apdb_mutex);
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d :  Failed to search ap[0x%x].\n","apdb_hwver_exist_by_id"
               ,0x2a18,param_1);
      }
    }
    else {
      iVar1 = l_apdb_ap_item_cur + iVar1 * 0x58;
      for (iVar2 = 0; iVar2 < *(int *)(iVar1 + 0x4c); iVar2 = iVar2 + 1) {
        iVar5 = *(int *)(iVar1 + 0x54) + iVar2 * 0x168;
        iVar3 = 0;
        while (iVar3 < *(int *)(iVar5 + 0x160)) {
          psVar4 = (short *)(*(int *)(iVar5 + 0x164) + iVar3 * 0x38);
          if (psVar4 == (short *)0x0) {
            iVar3 = iVar3 + 1;
          }
          else if ((int)*param_2 == (int)*psVar4) {
            iVar3 = iVar3 + 1;
            if ((int)psVar4[1] == (int)param_2[1]) {
              if (apdb_warning_switch != 0) {
                printf("[APDB_WARNING]%s()/line %d : Access ap model hwver is the same as apdb ap hwver:(%d.%d).\n"
                       ,"apdb_hwver_exist_by_id",0x2a25,(int)*param_2,(int)psVar4[1]);
              }
              FUN_00407f30(l_apdb_mutex);
              return 1;
            }
          }
          else {
            iVar3 = iVar3 + 1;
          }
        }
      }
      FUN_00407f30(l_apdb_mutex);
    }
  }
  return 0;
}

