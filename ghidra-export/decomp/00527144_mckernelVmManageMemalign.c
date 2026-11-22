// func mckernelVmManageMemalign @ 00527144 size=1

int mckernelVmManageMemalign
              (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int *piVar2;
  int in_t9;
  int iVar3;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  
  if (*(char *)(*(int *)(in_t9 + 0x232120) + 4) == '\0') {
    (**(code **)(in_t9 + 0x2325b4))(*(int *)(in_t9 + 0x231fe4) + 0x4774);
  }
  else if (param_1 - 1U < 0x1000) {
    iVar3 = *(int *)(in_t9 + 0x232124);
    if (param_1 == 0) {
      trap(7);
    }
    param_1 = ((param_2 + param_1 + -1) / param_1) * param_1;
    (**(code **)(iVar3 + 0x232a58))(&uStack_50,0,0x2c);
    piVar2 = *(int **)(iVar3 + 0x232514);
    if (*(char *)(piVar2 + 1) == '\0') {
      iVar1 = uac_mem_malloc_my(param_1,param_3);
    }
    else {
      uStack_50 = 2;
      uStack_48 = param_5;
      uStack_4c = param_4;
      iVar1 = (**(code **)(iVar3 + 0x232924))(piVar2[3],0,param_1,piVar2[2],0,&uStack_50);
      if ((iVar1 == 0) && (*piVar2 < 3)) {
        (**(code **)(iVar3 + 0x232b80))
                  (*(int *)(iVar3 + 0x2323d8) + 0x4700,*(int *)(iVar3 + 0x2323d8) + 0x48e0,0x2b,
                   param_1);
      }
    }
    return iVar1;
  }
  return 0;
}

