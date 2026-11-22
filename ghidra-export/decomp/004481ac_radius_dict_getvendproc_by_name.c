// func radius_dict_getvendproc_by_name @ 004481ac size=64

undefined4 radius_dict_getvendproc_by_name(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = uac_hash_get(*(undefined4 *)(param_1 + 0x1c));
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x44);
  }
  return uVar2;
}

