// func uac_id_clone @ 00519f84 size=108

int uac_id_clone(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = uac_id_new(*(undefined4 *)(param_1 + 0x10));
    if (iVar1 != 0) {
      uac_id_copy(iVar1,param_1);
    }
  }
  return iVar1;
}

