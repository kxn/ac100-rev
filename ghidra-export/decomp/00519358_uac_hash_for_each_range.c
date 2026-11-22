// func uac_hash_for_each_range @ 00519358 size=360

void uac_hash_for_each_range(int param_1,uint param_2,int param_3,code *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((((param_1 != 0) && (*(uint *)(param_1 + 0x10) != 0)) && (0 < param_3)) &&
     (iVar5 = 0, param_2 < *(uint *)(param_1 + 0x10))) {
    iVar6 = 0;
    uVar3 = 0;
    iVar4 = *(int *)(param_1 + 0x14);
LAB_005193d0:
    if (uVar3 < *(uint *)(param_1 + 0x14)) {
      iVar1 = uac_list_first(*(int *)(param_1 + 0x1c) + uVar3 * 0xc);
      while (iVar2 = iVar1, iVar1 != 0) {
        while (iVar6 < (int)param_2) {
          iVar6 = iVar6 + 1;
          iVar2 = uac_list_next(iVar2);
          if (iVar2 == 0) goto LAB_00519430;
        }
        iVar1 = uac_list_next(iVar2);
        if (param_4 != (code *)0x0) {
          (*param_4)(*(undefined4 *)(iVar2 + 0xc),param_5);
          if (iVar4 != *(int *)(param_1 + 0x14)) {
            uVar3 = 0;
            iVar4 = *(int *)(param_1 + 0x14);
            goto LAB_005193d0;
          }
        }
        iVar5 = iVar5 + 1;
        if (param_3 <= iVar5) {
          return;
        }
      }
LAB_00519430:
      uVar3 = uVar3 + 1;
      goto LAB_005193d0;
    }
  }
  return;
}

