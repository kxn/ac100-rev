// func apdb_get_vendor_by_id @ 006087dc size=1

undefined4 apdb_get_vendor_by_id(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_180 [24];
  undefined4 uStack_168;
  
  memset(auStack_180,0,0x168);
  if (param_3 == (undefined4 *)0x0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : Input vendor invalid.\n";
    uVar2 = 0x24e5;
  }
  else {
    if (param_2 != 0) {
      memset(auStack_180,0,0x168);
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      iVar1 = _apdb_get_ap_by_id(param_1,param_2,auStack_180);
      uVar2 = l_apdb_mutex;
      if (iVar1 == 0) {
        *param_3 = uStack_168;
        FUN_00407f30(uVar2);
        return 0;
      }
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d : get apdb failed\n","apdb_get_vendor_by_id",0x24f3);
      }
      FUN_00407f30(l_apdb_mutex);
      return 0xffffffff;
    }
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
    uVar2 = 0x24ea;
  }
  printf(__format,"apdb_get_vendor_by_id",uVar2);
  return 0xffffffff;
}

