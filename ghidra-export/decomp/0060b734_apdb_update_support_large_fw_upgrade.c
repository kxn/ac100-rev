// func apdb_update_support_large_fw_upgrade @ 0060b734 size=492

undefined4 apdb_update_support_large_fw_upgrade(undefined4 param_1,undefined4 param_2,int param_3)

{
  void *__s;
  void *__s_00;
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : apdb_update_support_large_fw_upgrade ENTER, model_id=%d, state=%d\n"
           ,"apdb_update_support_large_fw_upgrade",0x2b29,param_1,param_3);
  }
  __s = (void *)FUN_00408450(0x168,0x2b30);
  if (__s == (void *)0x0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[APDB_ERROR]%s()/line %d : Failed to malloc memory for apdb_ap.\n",
           "apdb_update_support_large_fw_upgrade",0x2b33);
    return 0xffffffff;
  }
  memset(__s,0,0x168);
  __s_00 = (void *)FUN_00408450(0x168,0x2b38);
  if (__s_00 == (void *)0x0) {
    uVar3 = 0xffffffff;
    if (apdb_err_switch == 0) goto LAB_0060b7e4;
    __format = "[APDB_ERROR]%s()/line %d : Failed to malloc memory for apdb_ap.\n";
    uVar2 = 0x2b3b;
  }
  else {
    memset(__s_00,0,0x168);
    iVar1 = apdb_get_ap_by_id(param_1,param_2,__s_00);
    if (iVar1 == -1) {
      uVar3 = 0xffffffff;
      if (apdb_err_switch == 0) goto LAB_0060b7e4;
      __format = "[APDB_ERROR]%s()/line %d : apdb_get_ap_by_id failed\n";
      uVar2 = 0x2b44;
    }
    else {
      _apdb_ap_copy(__s,__s_00,1);
      if (*(int *)((int)__s + 0x78) != param_3) {
        *(int *)((int)__s + 0x78) = param_3;
        uVar3 = 0;
        _apdb_add_ap_to_item_list_force(*(undefined4 *)((int)__s + 0x10),param_2,__s);
        goto LAB_0060b7e4;
      }
      uVar3 = 0;
      if (apdb_debug_switch == 0) goto LAB_0060b7e4;
      __format = "[APDB_DEBUG]%s()/line %d : state is same\n";
      uVar2 = 0x2b4c;
    }
  }
  printf(__format,"apdb_update_support_large_fw_upgrade",uVar2);
LAB_0060b7e4:
  _apdb_ap_free(__s,1);
  if (__s_00 != (void *)0x0) {
    FUN_00407df0(__s_00);
  }
  return uVar3;
}

