// func uac_hash_resize @ 00518ec4 size=368

undefined4 uac_hash_resize(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(param_1 + 0x1c);
  uVar6 = *(uint *)(param_1 + 0x14);
  if (param_2 == 0) {
    iVar1 = (uVar6 >> 1) - 1;
  }
  else {
    iVar1 = uVar6 * 2 + 3;
  }
  *(int *)(param_1 + 0x14) = iVar1;
  uVar5 = 0;
  iVar1 = uac_mem_calloc_my(*(undefined4 *)(param_1 + 0x14),0xc,0x5c);
  *(int *)(param_1 + 0x1c) = iVar1;
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x14) = uVar6;
    uVar4 = 0xfffffffe;
    *(int *)(param_1 + 0x1c) = iVar8;
  }
  else {
    for (; uVar5 < *(uint *)(param_1 + 0x14); uVar5 = uVar5 + 1) {
      uac_list_init(*(int *)(param_1 + 0x1c) + uVar5 * 0xc);
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
    iVar1 = iVar8;
    for (iVar7 = 0; iVar7 < (int)uVar6; iVar7 = iVar7 + 1) {
      iVar2 = uac_list_first(iVar1);
      while (iVar2 != 0) {
        uac_hash_add(param_1,*(undefined4 *)(iVar2 + 0xc));
        iVar3 = uac_list_next(iVar2);
        uac_mem_free_my(iVar2);
        iVar2 = iVar3;
      }
      iVar1 = iVar1 + 0xc;
    }
    uac_mem_free_my(iVar8);
    uVar4 = 0;
  }
  return uVar4;
}

