// func mesh_db_discover_pair_state_update @ 004b9c80 size=212

undefined4 mesh_db_discover_pair_state_update(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 == 0) || (param_2 < 1)) {
    uVar2 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Illegal input\n","mesh_db_discover_pair_state_update",0x622);
    }
  }
  else {
    iVar3 = 0;
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    do {
      iVar1 = FUN_00407fa0(DAT_00767f68,param_1);
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 100) = param_3;
      }
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 6;
    } while (iVar3 != param_2);
    uVar2 = 0;
    FUN_00407f30(DAT_00767eb4);
  }
  return uVar2;
}

