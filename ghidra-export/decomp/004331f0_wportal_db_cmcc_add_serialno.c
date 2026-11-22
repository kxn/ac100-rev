// func wportal_db_cmcc_add_serialno @ 004331f0 size=284

undefined4 wportal_db_cmcc_add_serialno(undefined2 param_1,void *param_2,undefined2 param_3)

{
  undefined4 uVar1;
  void *__dest;
  int iVar2;
  int iVar3;
  
  __dest = (void *)FUN_00408450(0x20,0x19ce);
  if (__dest != (void *)0x0) {
    memcpy(__dest,param_2,0x10);
    uVar1 = wportal_cmcc_serialno_mutex;
    *(undefined2 *)((int)__dest + 0x10) = param_1;
    *(undefined2 *)((int)__dest + 0x12) = param_3;
    FUN_004082d0(uVar1,0xffffffff);
    if ((999 < cmcc_serialno_node_num) && (iVar2 = FUN_004081b0(cmcc_serialno_list), iVar2 != 0)) {
      _wportal_db_cmcc_del_serialno(*(undefined2 *)(iVar2 + -4));
    }
    iVar3 = -1;
    iVar2 = FUN_00407e20(cmcc_serialno_tree,__dest);
    if (iVar2 == 0) {
      iVar3 = 0;
      FUN_004086b0(cmcc_serialno_list,(int)__dest + 0x14);
      cmcc_serialno_node_num = cmcc_serialno_node_num + 1;
    }
    FUN_00407f30(wportal_cmcc_serialno_mutex);
    if (iVar3 == 0) {
      return 0;
    }
    FUN_00407df0(__dest);
  }
  return 0xffffffff;
}

