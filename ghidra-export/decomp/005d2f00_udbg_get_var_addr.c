// func udbg_get_var_addr @ 005d2f00 size=720

long udbg_get_var_addr(int param_1,long *param_2)

{
  bool bVar1;
  int iVar2;
  FILE *pFVar3;
  size_t sVar4;
  long lVar5;
  long lVar6;
  undefined4 uVar7;
  char acStack_1a9 [64];
  char acStack_169 [65];
  char acStack_128 [256];
  
  memset(acStack_169 + 1,0,0x40);
  memset(acStack_1a9 + 1,0,0x40);
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == (long *)0x0) {
    return 0;
  }
  iVar2 = access(UDBG_OBJ_FILE,0);
  if (iVar2 != 0) {
    return 0;
  }
  sprintf(acStack_128,"cat %s | grep -w %s | awk \'{print $1}\' > %s",UDBG_OBJ_FILE,param_1,
          UDBG_TMP_SYM_FILE);
  system(acStack_128);
  pFVar3 = fopen(UDBG_TMP_SYM_FILE,"r");
  if (pFVar3 == (FILE *)0x0) {
    if (udbg_err_switch == 0) {
      return 0;
    }
    uVar7 = 0x4a9;
    goto LAB_005d3074;
  }
  fgets(acStack_169 + 1,0x40,pFVar3);
  sVar4 = strlen(acStack_169 + 1);
  if (acStack_169[sVar4] == '\n') {
    acStack_169[sVar4] = '\0';
    sVar4 = strlen(acStack_169 + 1);
    if ((int)sVar4 < 1) goto LAB_005d30b0;
LAB_005d3008:
    bVar1 = true;
    lVar5 = strtol(acStack_169 + 1,(char **)0x0,0x10);
    if (udbg_debug_switch != 0) {
      printf("[UDBG_DBG]%s()/%d Object [%s] found from global symbol table, addr=0x%lx\n",
             "udbg_get_var_addr",0x4b7,param_1,lVar5);
    }
  }
  else {
    if (0 < (int)sVar4) goto LAB_005d3008;
LAB_005d30b0:
    bVar1 = false;
    lVar5 = 0;
  }
  fclose(pFVar3);
  if (!bVar1) {
    return 0;
  }
  sprintf(acStack_128,"cat %s | grep -w %s | awk \'{print $2}\' > %s",UDBG_OBJ_FILE,param_1,
          UDBG_TMP_SYM_FILE);
  system(acStack_128);
  pFVar3 = fopen(UDBG_TMP_SYM_FILE,"r");
  if (pFVar3 != (FILE *)0x0) {
    fgets(acStack_1a9 + 1,0x40,pFVar3);
    sVar4 = strlen(acStack_1a9 + 1);
    if (acStack_1a9[sVar4] == '\n') {
      acStack_1a9[sVar4] = '\0';
    }
    lVar6 = strtol(acStack_1a9 + 1,(char **)0x0,0x10);
    *param_2 = lVar6;
    fclose(pFVar3);
    if (udbg_debug_switch == 0) {
      return lVar5;
    }
    printf("[UDBG_DBG]%s()/%d Object [%s] len=%d\n","udbg_get_var_addr",0x4d3,param_1,*param_2);
    return lVar5;
  }
  if (udbg_err_switch == 0) {
    return 0;
  }
  uVar7 = 0x4c7;
LAB_005d3074:
  printf("[UDBG_ERR]%s()/%d Open temp symbol failed.\n","udbg_get_var_addr",uVar7);
  return 0;
}

