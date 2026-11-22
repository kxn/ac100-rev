// func apdb_get_ap_by_id_array @ 00606db0 size=472

undefined4
apdb_get_ap_by_id_array(undefined4 param_1,int param_2,void *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (param_3 == (void *)0x0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : input ap invalid\n";
    uVar2 = 0x213e;
  }
  else if (param_2 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
    uVar2 = 0x2143;
  }
  else {
    FUN_004082d0(l_apdb_mutex,0xffffffff);
    iVar1 = _apdb_ap_item_get_index_by_id_array(param_1,param_4,param_5);
    if (iVar1 == -1) {
      FUN_00407f30(l_apdb_mutex);
      if (apdb_warning_switch == 0) {
        return 0xffffffff;
      }
      __format = "[APDB_WARNING]%s()/line %d : get ap index failed\n";
      uVar2 = 0x214d;
    }
    else {
      param_4 = param_4 + iVar1 * 0x58;
      iVar1 = *(int *)(param_4 + 0x50);
      if (iVar1 == 0) {
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : the hash is NULL\n","apdb_get_ap_by_id_array",0x2155);
        }
        FUN_00407f30(l_apdb_mutex);
        return 0xffffffff;
      }
      iVar1 = FUN_00407fa0(iVar1,param_2);
      if (iVar1 != 0) {
        memcpy(param_3,(void *)(*(int *)(param_4 + 0x54) + *(int *)(iVar1 + 0x10) * 0x168),0x168);
        FUN_00407f30(l_apdb_mutex);
        return 0;
      }
      FUN_00407f30(l_apdb_mutex);
      if (apdb_warning_switch == 0) {
        return 0xffffffff;
      }
      __format = "[APDB_WARNING]%s()/line %d : get  fwid  ap failed.\n";
      uVar2 = 0x215e;
    }
  }
  printf(__format,"apdb_get_ap_by_id_array",uVar2);
  return 0xffffffff;
}

