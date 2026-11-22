// func apmngr_db_sqlite_notify_msg @ 005478a0 size=400

undefined4 apmngr_db_sqlite_notify_msg(undefined4 param_1,void *param_2,size_t param_3)

{
  int iVar1;
  void *__dest;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_2 == (void *)0x0) {
    return 0xffffffff;
  }
  if ((int)param_3 < 1) {
    return 0xffffffff;
  }
  iVar1 = FUN_00408450(0x14,0x5f3);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(iVar1 + 0xc) = param_1;
  __dest = (void *)FUN_00408450(param_3,0x5f9);
  *(void **)(iVar1 + 0x10) = __dest;
  if (__dest == (void *)0x0) {
    FUN_00407df0(iVar1);
    return 0xffffffff;
  }
  memcpy(__dest,param_2,param_3);
  iVar2 = _apmngr_sql_op_change_option(iVar1);
  if (iVar2 == 1) {
    FUN_00407e80("apmngr_db_sqlite_notify_msg");
  }
  FUN_004082d0(apmngr_msg_mutex,0xffffffff);
  if (iVar2 == 1) {
    g_apmngr_sql_option_changed_node_num = g_apmngr_sql_option_changed_node_num + 1;
  }
  FUN_004086b0(&g_apmngr_msg_list,iVar1);
  FUN_004084b0(apmngr_msg_cond);
  uVar3 = *(uint *)(iVar1 + 0xc);
  if (uVar3 == 0) {
    uVar4 = *(uint *)(*(int *)(iVar1 + 0x10) + 0x14);
    uVar5 = 2;
    if (((uVar4 == 4) || (uVar4 == 8)) || (uVar3 = uVar4 ^ 5, uVar4 == 6)) goto LAB_005479a0;
  }
  else {
    uVar5 = 2;
    if (uVar3 == 5) goto LAB_005479a0;
    uVar3 = uVar3 ^ 7;
  }
  uVar5 = 2;
  if (uVar3 != 0) {
    uVar5 = 1;
  }
LAB_005479a0:
  FUN_00407f30(apmngr_msg_mutex);
  if (iVar2 == 1) {
    FUN_004082b0(uVar5,"apmngr_db_sqlite_notify_msg");
  }
  return 0;
}

