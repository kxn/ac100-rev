// func rrm_ap_para_exceed_neighbor_delete @ 004b2a20 size=452

undefined4 rrm_ap_para_exceed_neighbor_delete(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (param_1 != 0) {
    iVar8 = 0;
    FUN_004082d0(rrm_mutex,0xffffffff);
    if (*(int *)(param_1 + 0x20) != 0) {
      while (iVar8 < *(int *)(param_1 + 0xc)) {
        iVar2 = FUN_00407fe0(*(int *)(param_1 + 0x20) + iVar8 * 0xc);
        if (param_2 < iVar2) {
          iVar9 = iVar8 * 0x2a;
          for (iVar10 = 0; iVar10 < iVar2 - param_2; iVar10 = iVar10 + 1) {
            iVar3 = FUN_00408610(*(int *)(param_1 + 0x20) + iVar8 * 0xc);
            FUN_00408500(iVar3);
            iVar7 = *(int *)(iVar3 + 0x24);
            if (iVar7 == 0) {
              iVar7 = *(int *)(param_1 + 0x18);
            }
            else {
              FUN_00408500(iVar7);
              FUN_00407df0(iVar7);
              iVar7 = *(int *)(param_1 + 0x18);
            }
            *(short *)(iVar7 + iVar9 + 10) =
                 *(short *)(iVar7 + iVar9 + 10) - *(short *)(iVar3 + 0x10);
            for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(iVar3 + 0xe); iVar7 = iVar7 + 1) {
              psVar5 = (short *)(iVar3 + iVar7 * 6 + 0x12);
              for (iVar4 = 0; iVar6 = *(int *)(param_1 + 0x18) + iVar9,
                  iVar4 < (int)(uint)*(byte *)(iVar6 + 2); iVar4 = iVar4 + 1) {
                iVar6 = iVar6 + (iVar4 + 4) * 2;
                *(short *)(iVar6 + 4) = *(short *)(iVar6 + 4) - *psVar5;
                iVar6 = *(int *)(param_1 + 0x18) + iVar9 + (iVar4 + 2) * 8;
                sVar1 = *psVar5;
                psVar5 = psVar5 + 1;
                *(short *)(iVar6 + 2) = *(short *)(iVar6 + 2) - sVar1;
              }
            }
            FUN_00407df0(iVar3);
          }
          iVar8 = iVar8 + 1;
        }
        else {
          iVar8 = iVar8 + 1;
        }
      }
    }
    FUN_00407f30(rrm_mutex);
  }
  return 0;
}

