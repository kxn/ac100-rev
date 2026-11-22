// func wportal_db_cmcc_del_wq @ 0043350c size=184

undefined4 wportal_db_cmcc_del_wq(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_48 [40];
  undefined1 auStack_20 [16];
  
  memset(auStack_48,0,0x34);
  memcpy(auStack_20,param_1,6);
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

