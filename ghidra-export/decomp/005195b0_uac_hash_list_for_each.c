// func uac_hash_list_for_each @ 005195b0 size=240

undefined4 uac_hash_list_for_each(int param_1,undefined4 param_2,code *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  uVar4 = uVar5;
  if (((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) &&
     (uVar4 = 0xffffffff, param_3 != (code *)0x0)) {
    uVar1 = (**(code **)(param_1 + 4))(param_2);
    if (*(uint *)(param_1 + 0x14) == 0) {
      trap(7);
    }
    iVar2 = uac_list_first(*(int *)(param_1 + 0x1c) + (uVar1 % *(uint *)(param_1 + 0x14)) * 0xc);
    uVar4 = uVar5;
    while (iVar2 != 0) {
      iVar3 = uac_list_next(iVar2);
      uVar4 = (*param_3)(*(undefined4 *)(iVar2 + 0xc),param_4);
      iVar2 = iVar3;
    }
  }
  return uVar4;
}

