// func _apmngr_sql_op_change_option @ 005456f4 size=92

bool _apmngr_sql_op_change_option(int param_1)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  bVar1 = false;
  if ((uVar2 < 0x1b) && (4 < uVar2 - 10)) {
    if (uVar2 == 0) {
      return *(int *)(*(int *)(param_1 + 0x10) + 0x3c) == 1;
    }
    bVar1 = true;
    if (uVar2 == 0x11) {
      bVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x4c) == 1;
    }
  }
  return bVar1;
}

