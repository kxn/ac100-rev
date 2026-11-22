// func _apdb_hw_exist @ 00602e68 size=212

undefined4 _apdb_hw_exist(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : input para is null.\n","_apdb_hw_exist",0x1e4c);
    }
  }
  else {
    uVar2 = 0;
    iVar1 = _apdb_ap_item_get_index_by_id();
    if (iVar1 != -1) {
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      iVar1 = FUN_00407fa0(*(undefined4 *)(l_apdb_ap_item_cur + iVar1 * 0x58 + 0x50),param_2);
      if (iVar1 == 0) {
        FUN_00407f30(l_apdb_mutex);
      }
      else {
        uVar2 = 1;
        FUN_00407f30(l_apdb_mutex);
      }
    }
  }
  return uVar2;
}

