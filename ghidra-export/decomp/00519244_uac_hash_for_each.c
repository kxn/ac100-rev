// func uac_hash_for_each @ 00519244 size=276

void uac_hash_for_each(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((param_1 != 0) && (uVar3 = 0, *(int *)(param_1 + 0x10) != 0)) {
    iVar4 = *(int *)(param_1 + 0x14);
LAB_005192a0:
    if (uVar3 < *(uint *)(param_1 + 0x14)) {
      iVar2 = uac_list_first(*(int *)(param_1 + 0x1c) + uVar3 * 0xc);
      do {
        do {
          iVar1 = iVar2;
          if (iVar1 == 0) {
            uVar3 = uVar3 + 1;
            goto LAB_005192a0;
          }
          iVar2 = uac_list_next(iVar1);
        } while (param_2 == (code *)0x0);
        (*param_2)(*(undefined4 *)(iVar1 + 0xc),param_3);
      } while (iVar4 == *(int *)(param_1 + 0x14));
      uVar3 = 0;
      iVar4 = *(int *)(param_1 + 0x14);
      goto LAB_005192a0;
    }
  }
  return;
}

