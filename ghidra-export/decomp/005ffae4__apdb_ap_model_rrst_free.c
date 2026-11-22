// func _apdb_ap_model_rrst_free @ 005ffae4 size=96

void _apdb_ap_model_rrst_free(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = 0, 0 < param_2)) {
    do {
      iVar1 = iVar1 + 1;
      if (*(int *)(param_1 + 0x34) != 0) {
        FUN_00407df0();
        *(undefined4 *)(param_1 + 0x34) = 0;
      }
      param_1 = param_1 + 0x38;
    } while (iVar1 != param_2);
  }
  return;
}

