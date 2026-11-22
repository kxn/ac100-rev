// func udbg_call_fun @ 005d4b0c size=772

void udbg_call_fun(int param_1)

{
  code *pcVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_48 [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  memset(local_48,0,0x28);
  iVar7 = param_1 + 4;
  if (param_1 == 0) {
    return;
  }
  pcVar1 = (code *)udbg_get_fun_addr(iVar7);
  if (pcVar1 == (code *)0x0) {
    printf("\n Function named %s() not found\n",iVar7);
    return;
  }
  piVar5 = local_48;
  iVar6 = param_1;
  for (iVar4 = 0; iVar4 < *(int *)(param_1 + 100); iVar4 = iVar4 + 1) {
    if (*(int *)(iVar6 + 0x68) == 0) {
      lVar2 = strtol((char *)(param_1 + iVar4 * 100 + 0x6c),(char **)0x0,0);
      *piVar5 = lVar2;
    }
    else {
      *piVar5 = param_1 + iVar4 * 100 + 0x6c;
    }
    piVar5 = piVar5 + 1;
    iVar6 = iVar6 + 100;
  }
  uVar3 = 0;
  switch(*(int *)(param_1 + 100)) {
  case 0:
    uVar3 = (*pcVar1)();
    break;
  case 1:
    uVar3 = (*pcVar1)(local_48[0]);
    break;
  case 2:
    uVar3 = (*pcVar1)(local_48[0],local_48[1]);
    break;
  case 3:
    uVar3 = (*pcVar1)(local_48[0],local_48[1],local_48[2]);
    break;
  case 4:
    uVar3 = (*pcVar1)(local_48[0],local_48[1],local_48[2],local_48[3]);
    break;
  case 5:
    goto LAB_005d4d00;
  case 6:
LAB_005d4d00:
    uVar3 = (*pcVar1)(local_48[0],local_48[1],local_48[2],local_48[3],local_38);
    break;
  case 7:
    goto LAB_005d4cb4;
  case 8:
LAB_005d4cb4:
    uVar3 = (*pcVar1)(local_48[0],local_48[1],local_48[2],local_48[3],local_38,local_34,local_30);
    break;
  case 9:
    goto LAB_005d4c74;
  case 10:
LAB_005d4c74:
    uVar3 = (*pcVar1)(local_48[0],local_48[1],local_48[2],local_48[3],local_38,local_34,local_30,
                      local_2c,local_28);
  }
  printf("\n Execute %s() return %ld(0x%lx)\n",iVar7,uVar3,uVar3);
  return;
}

