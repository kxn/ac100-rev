// func _quick_sort_impl @ 00483800 size=384

void _quick_sort_impl(int param_1,undefined4 param_2,uint param_3,uint param_4,code *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  iVar1 = param_3 << 2;
  do {
    uVar7 = *(undefined4 *)(param_1 + iVar1);
    uVar4 = param_3;
    uVar5 = param_4;
    while (uVar4 < uVar5) {
      puVar2 = (undefined4 *)(param_1 + uVar5 * 4);
      while (iVar1 = (*param_5)(*puVar2,uVar7,param_2), -1 < iVar1) {
        uVar6 = uVar5;
        if (uVar5 == uVar4) goto LAB_004838b0;
        uVar5 = uVar5 - 1;
        puVar2 = puVar2 + -1;
      }
      uVar6 = uVar4;
      if (uVar4 != uVar5) {
        iVar1 = uVar4 * 4;
        uVar4 = uVar4 + 1;
        *(undefined4 *)(param_1 + iVar1) = *puVar2;
        uVar6 = uVar5;
      }
LAB_004838b0:
      puVar3 = (undefined4 *)(param_1 + uVar4 * 4);
      while( true ) {
        iVar1 = (*param_5)(*puVar3,uVar7,param_2);
        if ((0 < iVar1) || (uVar6 <= uVar4)) break;
        uVar4 = uVar4 + 1;
        puVar3 = puVar3 + 1;
      }
      if (uVar4 != uVar6) {
        uVar5 = uVar6 - 1;
        *puVar2 = *puVar3;
      }
    }
    *(undefined4 *)(param_1 + uVar4 * 4) = uVar7;
    if (param_3 < uVar4) {
      _quick_sort_impl(param_1,param_2,param_3,uVar4 - 1,param_5);
    }
    param_3 = uVar4 + 1;
    if (param_4 <= uVar4) {
      return;
    }
    iVar1 = param_3 * 4;
  } while( true );
}

