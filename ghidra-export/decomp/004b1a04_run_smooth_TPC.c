// func run_smooth_TPC @ 004b1a04 size=352

undefined4
run_smooth_TPC(short *param_1,int param_2,int param_3,int *param_4,char param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  for (iVar4 = 0; iVar4 < param_3; iVar4 = iVar4 + 1) {
    piVar3 = param_4;
    for (iVar5 = 0; iVar5 < (int)(uint)*(byte *)(param_1 + 1); iVar5 = iVar5 + 1) {
      iVar1 = FUN_00407fe0(*piVar3 + iVar4 * 0xc);
      if ((0 < iVar1) && (iVar1 < param_6)) {
        for (iVar1 = FUN_004081b0(*piVar3 + iVar4 * 0xc); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
          if ((int)param_5 <= (int)*(short *)(iVar1 + 0x10)) {
            for (iVar2 = FUN_004081b0(*piVar3 + *(short *)(param_2 +
                                                          (uint)*(ushort *)(iVar1 + 0xc) * 2) * 0xc)
                ; (iVar2 != 0 && ((int)param_5 <= (int)*(short *)(iVar2 + 0x10)));
                iVar2 = FUN_00408680(iVar2)) {
              do {
              } while (*(short *)(iVar2 + 0xc) == *param_1);
            }
          }
        }
      }
      piVar3 = piVar3 + 1;
    }
    param_1 = param_1 + 9;
  }
  return 0;
}

