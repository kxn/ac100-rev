// func cw_ac_descriptor_val_free @ 0056d034 size=128

void cw_ac_descriptor_val_free(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  while (iVar1 = FUN_004081b0(param_1 + 0xc), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(*(undefined4 *)(iVar1 + 0x14));
    FUN_00407df0(iVar1);
  }
  FUN_00407df0(param_1);
  return;
}

