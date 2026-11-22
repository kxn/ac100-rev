// func _apdb_ap_model_radios_free @ 005ffbd8 size=108

void _apdb_ap_model_radios_free(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
      if (*(int *)(param_1 + 0x28) == 0) {
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
      else {
        _apdb_radio_free(*(int *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x10));
        *(undefined4 *)(param_1 + 0x28) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
      param_1 = param_1 + 0x38;
    }
  }
  return;
}

