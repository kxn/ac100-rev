// func uac_hash_get @ 00519170 size=212

undefined4 uac_hash_get(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  if (((param_1 != 0) && (param_2 != 0)) && (*(int *)(param_1 + 0x14) != 0)) {
    uVar1 = (**(code **)(param_1 + 4))(param_2);
    if (*(uint *)(param_1 + 0x14) == 0) {
      trap(7);
    }
    pcVar4 = uac_list_first;
    iVar3 = *(int *)(param_1 + 0x1c) + (uVar1 % *(uint *)(param_1 + 0x14)) * 0xc;
    while (iVar3 = (*pcVar4)(iVar3), iVar3 != 0) {
      iVar2 = (**(code **)(param_1 + 8))(*(undefined4 *)(iVar3 + 0xc),param_2);
      if (iVar2 != 0) {
        return *(undefined4 *)(iVar3 + 0xc);
      }
      pcVar4 = uac_list_next;
    }
  }
  return 0;
}

