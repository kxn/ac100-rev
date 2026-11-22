// func _wportal_db_cmcc_del_serialno @ 0042bb30 size=104

undefined4 _wportal_db_cmcc_del_serialno(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_res0 [8];
  
  local_res0[0] = param_1;
  iVar1 = FUN_004080c0(cmcc_serialno_tree,local_res0);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    FUN_00408500(iVar1 + 0x14);
    FUN_00408690(cmcc_serialno_tree,local_res0);
    uVar2 = 0;
    if (0 < cmcc_serialno_node_num) {
      cmcc_serialno_node_num = cmcc_serialno_node_num + -1;
    }
  }
  return uVar2;
}

