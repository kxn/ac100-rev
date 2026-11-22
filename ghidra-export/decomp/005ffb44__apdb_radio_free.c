// func _apdb_radio_free @ 005ffb44 size=148

void _apdb_radio_free(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = param_1;
  for (iVar2 = 0; iVar2 < param_2; iVar2 = iVar2 + 1) {
    if (*(int *)(iVar1 + 0x110) != 0) {
      _apdb_radio_free(*(int *)(iVar1 + 0x110),1);
      *(undefined4 *)(iVar1 + 0x110) = 0;
    }
    iVar1 = iVar1 + 0x114;
  }
  FUN_00407df0(param_1);
  return;
}

