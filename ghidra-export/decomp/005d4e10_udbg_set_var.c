// func udbg_set_var @ 005d4e10 size=576

void udbg_set_var(int param_1)

{
  code *pcVar1;
  longlong *plVar2;
  int iVar3;
  char *__format;
  int iVar4;
  longlong lVar5;
  int local_20 [2];
  
  if (param_1 == 0) {
    return;
  }
  if (1 < *(int *)(param_1 + 100)) {
LAB_005d4e48:
    puts("\n Syntax Error");
    return;
  }
  if (*(int *)(param_1 + 100) == 1) {
    if (*(int *)(param_1 + 0x68) != 0) goto LAB_005d4e48;
    lVar5 = strtoll((char *)(param_1 + 0x6c),(char **)0x0,0);
    plVar2 = (longlong *)udbg_get_var_addr(param_1 + 4,local_20);
    if (plVar2 == (longlong *)0x0) {
      __format = "\n Variable named [%s] not found\n";
      goto LAB_005d5038;
    }
    if (local_20[0] == 2) {
      *(short *)plVar2 = (short)lVar5;
    }
    else if (local_20[0] < 3) {
      if (local_20[0] != 1) goto LAB_005d4fa0;
      *(char *)plVar2 = (char)lVar5;
    }
    else if (local_20[0] == 4) {
      *(int *)plVar2 = (int)lVar5;
    }
    else {
      if (local_20[0] != 8) goto LAB_005d4fa0;
      *plVar2 = lVar5;
    }
    printf("\n Set variable %s = %lld (0x%llx)\n",param_1 + 4,(int)((ulonglong)lVar5 >> 0x20),
           (int)lVar5,lVar5);
    iVar3 = *(int *)(param_1 + 100);
  }
  else {
    iVar3 = *(int *)(param_1 + 100);
  }
  if (iVar3 != 0) {
    return;
  }
  iVar4 = param_1 + 4;
  iVar3 = udbg_get_var_addr(iVar4,local_20);
  pcVar1 = (code *)udbg_get_fun_addr(iVar4);
  if (iVar3 == 0) {
    if (pcVar1 != (code *)0x0) {
      iVar3 = (*pcVar1)();
      printf("\n Execute %s() return %lld(0x%llx)\n",iVar4,iVar3 >> 0x1f,iVar3,iVar3 >> 0x1f,iVar3);
      return;
    }
    __format = "\n Variable or function named [%s] not found\n";
LAB_005d5038:
    printf(__format,param_1 + 4);
    return;
  }
  if (local_20[0] == 2) {
LAB_005d4ee4:
    printf("\n Variable [%s] : addr = %p, value = %lld(0x%llx)\n",iVar4,iVar3);
    return;
  }
  if (local_20[0] < 3) {
    if (local_20[0] == 1) goto LAB_005d4ee4;
  }
  else if ((local_20[0] == 4) || (local_20[0] == 8)) goto LAB_005d4ee4;
LAB_005d4fa0:
  printf("\n Variable %s(len=%d) is not a built-in type\n",param_1 + 4);
  return;
}

