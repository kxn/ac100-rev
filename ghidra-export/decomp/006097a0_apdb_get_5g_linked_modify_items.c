// func apdb_get_5g_linked_modify_items @ 006097a0 size=332

undefined4 apdb_get_5g_linked_modify_items(undefined4 param_1,int param_2,void *param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_180 [72];
  undefined1 auStack_138 [292];
  
  memset(auStack_180,0,0x168);
  if (param_3 == (void *)0x0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : Input items invalid.\n";
    uVar2 = 0x26e7;
  }
  else {
    if (param_2 != 0) {
      memset(auStack_180,0,0x168);
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      iVar1 = _apdb_get_ap_by_id(param_1,param_2,auStack_180);
      if (iVar1 == 0) {
        memcpy(param_3,auStack_138,0x28);
        FUN_00407f30(l_apdb_mutex);
        return 0;
      }
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d : get apdb failed\n","apdb_get_5g_linked_modify_items",
               0x26f4);
      }
      FUN_00407f30(l_apdb_mutex);
      return 0xffffffff;
    }
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
    uVar2 = 0x26ec;
  }
  printf(__format,"apdb_get_5g_linked_modify_items",uVar2);
  return 0xffffffff;
}

