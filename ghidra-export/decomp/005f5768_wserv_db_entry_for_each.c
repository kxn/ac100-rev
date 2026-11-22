// func wserv_db_entry_for_each @ 005f5768 size=380

undefined4 wserv_db_entry_for_each(code *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  FUN_0051ad88(&local_38);
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  if (l_wserv_data != 0) {
    for (iVar1 = FUN_004081b0(&g_wserv_list); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      iVar2 = wserv_calloc(1,0x21c);
      if (iVar2 == 0) {
        if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> no memory!!\r\n","wserv_db_entry_for_each",0x1839);
        }
      }
      else {
        memcpy((void *)(iVar2 + 0xc),(void *)(iVar1 + 0x10),0x205);
        FUN_004086b0(&local_38,iVar2);
      }
    }
  }
  FUN_00407f30(DAT_007cbef0);
  iVar1 = FUN_004081b0(&local_38);
  while (iVar1 != 0) {
    iVar2 = FUN_00408680(iVar1);
    (*param_1)(iVar1 + 0xc,param_2);
    FUN_00407df0(iVar1);
    iVar1 = iVar2;
  }
  return 0;
}

