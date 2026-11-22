// func free_reponse_from_list @ 0050cabc size=108

void free_reponse_from_list(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    while (iVar1 = FUN_004081b0(param_1 + 4), iVar1 != 0) {
      if (*(int *)(iVar1 + 0x18) != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 0x18) = 0;
      }
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
    }
  }
  return;
}

