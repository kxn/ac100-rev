// func radius_pair_insert @ 00449410 size=1

void radius_pair_insert(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (((param_1 == (int *)0x0) || (param_2 == 0)) || (*(int *)(param_2 + 0x150) != 0)) {
    return;
  }
  if (*param_1 == 0) {
    *param_1 = param_2;
    return;
  }
  iVar1 = *param_1;
  if (*(int *)(param_2 + 0x44) <= *(int *)(iVar1 + 0x44)) {
    *(int *)(param_2 + 0x150) = iVar1;
    return;
  }
  iVar3 = *(int *)(iVar1 + 0x150);
  if (iVar3 == 0) {
    *(undefined4 *)(param_2 + 0x150) = 0;
  }
  else {
    iVar5 = *(int *)(iVar3 + 0x44);
    iVar2 = iVar1;
    iVar1 = iVar3;
    while (iVar5 < *(int *)(param_2 + 0x44)) {
      iVar3 = *(int *)(iVar1 + 0x150);
      if (iVar3 == 0) {
        uVar4 = *(undefined4 *)(iVar1 + 0x150);
        goto LAB_00448fa8;
      }
      iVar2 = iVar1;
      iVar1 = iVar3;
      iVar5 = *(int *)(iVar3 + 0x44);
    }
    uVar4 = *(undefined4 *)(iVar2 + 0x150);
    iVar1 = iVar2;
LAB_00448fa8:
    *(undefined4 *)(param_2 + 0x150) = uVar4;
  }
  *(int *)(iVar1 + 0x150) = param_2;
  return;
}

