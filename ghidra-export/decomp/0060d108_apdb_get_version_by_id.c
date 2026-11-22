// func apdb_get_version_by_id @ 0060d108 size=1

undefined4 apdb_get_version_by_id(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[APDB_ERROR]%s()/line %d : the fwid is NULL\n","apdb_get_version_by_id",0x2e17);
    return 0xffffffff;
  }
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  iVar1 = _apdb_ap_item_get_index_by_id(param_1);
  if (iVar1 == -1) {
    FUN_00407f30(l_apdb_mutex);
    if (apdb_warning_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_WARNING]%s()/line %d :  Failed to search ap[0x%x].\n";
    uVar3 = 0x2e23;
  }
  else {
    iVar2 = FUN_00407fa0(*(undefined4 *)(l_apdb_ap_item_cur + iVar1 * 0x58 + 0x50),param_2);
    if (iVar2 != 0) {
      uVar3 = *(undefined4 *)
               (*(int *)(l_apdb_ap_item_cur + iVar1 * 0x58 + 0x54) + *(int *)(iVar2 + 0x10) * 0x168
               + 0x15c);
      FUN_00407f30(l_apdb_mutex);
      return uVar3;
    }
    FUN_00407f30(l_apdb_mutex);
    if (apdb_warning_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_WARNING]%s()/line %d : Failed to search ap[0x%x].\n";
    uVar3 = 0x2e2c;
  }
  printf(__format,"apdb_get_version_by_id",uVar3,param_1);
  return 0xffffffff;
}

