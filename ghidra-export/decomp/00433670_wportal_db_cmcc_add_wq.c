// func wportal_db_cmcc_add_wq @ 00433670 size=376

undefined4 wportal_db_cmcc_add_wq(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_v1;
  undefined4 extraout_v1_00;
  undefined1 auStack_58 [48];
  int local_28;
  
  if (999 < cmcc_wq_node_num) {
    return 0xffffffff;
  }
  FUN_004082d0(wportal_cmcc_waitque_mutex,0xffffffff);
  iVar2 = FUN_00407e20(cmcc_wq_tree,param_1);
  if (iVar2 != 0) {
    FUN_00407f30(wportal_cmcc_waitque_mutex);
    memset(auStack_58,0,0x34);
    iVar2 = wportal_db_cmcc_get_wq(param_1 + 0x28,auStack_58);
    if (iVar2 != 0) {
      if (*(int *)(param_1 + 0x20) == 0) {
        return 0xffffffff;
      }
      iVar2 = wportal_db_cmcc_get_wq_by_ip(*(int *)(param_1 + 0x20),auStack_58);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
    FUN_00407e70();
    if (extraout_v1 - local_28 < 0x3d) {
      return 0xffffffff;
    }
    iVar2 = wportal_db_cmcc_del_wq(param_1 + 0x28);
    if ((iVar2 != 0) &&
       (iVar2 = wportal_db_cmcc_del_wq_by_ip(*(undefined4 *)(param_1 + 0x20)), iVar2 != 0)) {
      return 0xffffffff;
    }
    FUN_004082d0(wportal_cmcc_waitque_mutex,0xffffffff);
    iVar2 = FUN_00407e20(cmcc_wq_tree,param_1);
    if (iVar2 != 0) {
      FUN_00407f30(wportal_cmcc_waitque_mutex);
      return 0xffffffff;
    }
    puts("success to reAdd wqEntry ");
  }
  cmcc_wq_node_num = cmcc_wq_node_num + 1;
  FUN_00407e70();
  uVar1 = wportal_cmcc_waitque_mutex;
  *(undefined4 *)(param_1 + 0x30) = extraout_v1_00;
  FUN_00407f30(uVar1);
  return 0;
}

