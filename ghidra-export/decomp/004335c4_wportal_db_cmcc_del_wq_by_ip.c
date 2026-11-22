// func wportal_db_cmcc_del_wq_by_ip @ 004335c4 size=172

undefined4 wportal_db_cmcc_del_wq_by_ip(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  
  memset(auStack_48,0,0x34);
  local_28 = param_1;
  FUN_004082d0(wportal_cmcc_waitque_mutex,0xffffffff);
  iVar1 = FUN_004080c0(cmcc_wq_tree,auStack_48);
  if (iVar1 == 0) {
    FUN_00407f30(wportal_cmcc_waitque_mutex);
    uVar2 = 0xffffffff;
  }
  else {
    FUN_00408690(cmcc_wq_tree,auStack_48);
    if (0 < cmcc_wq_node_num) {
      cmcc_wq_node_num = cmcc_wq_node_num + -1;
    }
    FUN_00407f30(wportal_cmcc_waitque_mutex);
    uVar2 = 0;
  }
  return uVar2;
}

