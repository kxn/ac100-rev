// func rrc_rate_set_get @ 0055e5a0 size=196

undefined4 rrc_rate_set_get(int *param_1,void *param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  uVar1 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (param_2 != (void *)0x0)) &&
     (iVar5 = 0, piVar3 = param_1, param_4 != (int *)0x0)) {
    do {
      if (*piVar3 == 0) break;
      iVar5 = iVar5 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar5 != 0x10);
    uVar1 = 0xffffffff;
    if (iVar5 < param_3) {
      memset(param_2,0,param_3 << 2);
      iVar2 = 0;
      do {
        piVar3 = (int *)((int)param_1 + iVar2);
        if (*piVar3 == 0) break;
        piVar4 = (int *)((int)param_2 + iVar2);
        iVar2 = iVar2 + 4;
        *piVar4 = *piVar3;
      } while (iVar2 != 0x40);
      uVar1 = 0;
      *param_4 = iVar5;
    }
  }
  return uVar1;
}

