// func _apdb_get_ap_by_id @ 005fb500 size=332

undefined4 _apdb_get_ap_by_id(undefined4 param_1,int param_2,void *param_3)

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
    uVar2 = 0x21ae;
  }
  else {
    iVar1 = _apdb_ap_item_get_index_by_id();
    if (iVar1 == -1) {
      if (apdb_warning_switch == 0) {
        return 0xffffffff;
      }
      __format = "[APDB_WARNING]%s()/line %d : get ap index failed.\n";
      uVar2 = 0x21b5;
    }
    else {
      iVar3 = l_apdb_ap_item_cur + iVar1 * 0x58;
      iVar1 = *(int *)(iVar3 + 0x50);
      if (iVar1 == 0) {
        if (apdb_debug_switch == 0) {
          return 0xffffffff;
        }
        __format = "[APDB_DEBUG]%s()/line %d : the hash is NULL\n";
        uVar2 = 0x21bd;
      }
      else {
        iVar1 = FUN_00407fa0(iVar1,param_2);
        if (iVar1 != 0) {
          memcpy(param_3,(void *)(*(int *)(iVar3 + 0x54) + *(int *)(iVar1 + 0x10) * 0x168),0x168);
          return 0;
        }
        if (apdb_warning_switch == 0) {
          return 0xffffffff;
        }
        __format = "[APDB_WARNING]%s()/line %d : get  fwid  ap failed.\n";
        uVar2 = 0x21c4;
      }
    }
  }
  printf(__format,"_apdb_get_ap_by_id",uVar2);
  return 0xffffffff;
}

