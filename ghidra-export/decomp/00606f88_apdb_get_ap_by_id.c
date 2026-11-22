// func apdb_get_ap_by_id @ 00606f88 size=424

undefined4 apdb_get_ap_by_id(undefined4 param_1,int param_2,void *param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_3 == (void *)0x0) || (param_2 == 0)) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : input ap invalid.\n";
    uVar2 = 0x217e;
  }
  else {
    FUN_004082d0(l_apdb_mutex,0xffffffff);
    iVar1 = _apdb_ap_item_get_index_by_id(param_1);
    if (iVar1 == -1) {
      FUN_00407f30(l_apdb_mutex);
      if (apdb_warning_switch == 0) {
        return 0xffffffff;
      }
      __format = "[APDB_WARNING]%s()/line %d : get ap index failed.\n";
      uVar2 = 0x2188;
    }
    else {
      iVar3 = l_apdb_ap_item_cur + iVar1 * 0x58;
      iVar1 = *(int *)(iVar3 + 0x50);
      if (iVar1 == 0) {
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : the hash is NULL\n","apdb_get_ap_by_id",0x2190);
        }
        FUN_00407f30(l_apdb_mutex);
        return 0xffffffff;
      }
      iVar1 = FUN_00407fa0(iVar1,param_2);
      if (iVar1 != 0) {
        memcpy(param_3,(void *)(*(int *)(iVar3 + 0x54) + *(int *)(iVar1 + 0x10) * 0x168),0x168);
        FUN_00407f30(l_apdb_mutex);
        return 0;
      }
      FUN_00407f30(l_apdb_mutex);
      if (apdb_warning_switch == 0) {
        return 0xffffffff;
      }
      __format = "[APDB_WARNING]%s()/line %d : get  fwid  ap failed.\n";
      uVar2 = 0x2199;
    }
  }
  printf(__format,"apdb_get_ap_by_id",uVar2);
  return 0xffffffff;
}

