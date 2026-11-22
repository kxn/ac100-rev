// func uac_id_fix @ 00519db8 size=144

void uac_id_fix(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if ((param_1 != (int *)0x0) && (iVar1 = 0, param_1[5] != 0)) {
    iVar2 = param_1[4] + -1;
    while (iVar1 < iVar2) {
      iVar4 = *(int *)(*param_1 + iVar1 * 4);
      if (iVar4 == -1) {
        iVar1 = iVar1 + 1;
      }
      else {
        piVar3 = (int *)(*param_1 + iVar2 * 4);
        if (*piVar3 == -1) {
          *piVar3 = iVar4;
          *(undefined4 *)(*param_1 + iVar1 * 4) = 0xffffffff;
        }
        else {
          iVar2 = iVar2 + -1;
        }
      }
    }
    param_1[3] = 0;
    if (param_1[4] == 0) {
      trap(7);
    }
    param_1[2] = param_1[5] % param_1[4];
  }
  return;
}

