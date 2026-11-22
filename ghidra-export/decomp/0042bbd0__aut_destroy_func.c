// func _aut_destroy_func @ 0042bbd0 size=184

void _aut_destroy_func(int param_1)

{
  int iVar1;
  
  FUN_00408500();
  if (*(int *)(param_1 + 0x118) == 0) {
    iVar1 = *(int *)(param_1 + 0x124);
  }
  else {
    FUN_00408500(param_1 + 0x110);
    iVar1 = *(int *)(param_1 + 0x124);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x130);
  }
  else {
    FUN_00408500(param_1 + 0x11c);
    iVar1 = *(int *)(param_1 + 0x130);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x160);
  }
  else {
    FUN_00408500(param_1 + 0x128);
    iVar1 = *(int *)(param_1 + 0x160);
  }
  if (iVar1 == 0 && *(int *)(param_1 + 0x164) == 0) {
    iVar1 = *(int *)(param_1 + 0x13c);
  }
  else {
    FUN_00408690(dm_sessid_rbtree,param_1 + 0x160);
    iVar1 = *(int *)(param_1 + 0x13c);
  }
  if (iVar1 != 0) {
    FUN_00408500(param_1 + 0x134);
  }
  FUN_00407df0(param_1);
  if (0 < aut_count) {
    aut_count = aut_count + -1;
  }
  return;
}

