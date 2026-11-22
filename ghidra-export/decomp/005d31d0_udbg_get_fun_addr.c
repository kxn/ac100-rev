// func udbg_get_fun_addr @ 005d31d0 size=684

int udbg_get_fun_addr(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  FILE *__stream;
  size_t sVar6;
  long lVar7;
  char *pcVar8;
  char acStack_169 [65];
  char acStack_128 [256];
  
  memset(acStack_169 + 1,0,0x40);
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = access(UDBG_FUN_FILE,0);
  if (iVar2 == 0) {
    sprintf(acStack_128,"cat %s | grep -w %s | awk \'{print $1}\' > %s",UDBG_FUN_FILE,param_1,
            UDBG_TMP_SYM_FILE);
    system(acStack_128);
    __stream = fopen(UDBG_TMP_SYM_FILE,"r");
    if (__stream == (FILE *)0x0) {
      if (udbg_err_switch != 0) {
        printf("[UDBG_ERR]%s()/%d Open temp symbol failed.\n","udbg_get_fun_addr",0x455);
        return 0;
      }
      return 0;
    }
    fgets(acStack_169 + 1,0x40,__stream);
    sVar6 = strlen(acStack_169 + 1);
    if (acStack_169[sVar6] == '\n') {
      acStack_169[sVar6] = '\0';
      sVar6 = strlen(acStack_169 + 1);
    }
    if ((int)sVar6 < 1) {
      bVar1 = false;
      lVar7 = 0;
    }
    else {
      bVar1 = true;
      lVar7 = strtol(acStack_169 + 1,(char **)0x0,0x10);
      if (udbg_debug_switch != 0) {
        printf("[UDBG_DBG]%s()/%d Function %s() found from global symbol table, addr=0x%lx\n",
               "udbg_get_fun_addr",0x463,param_1,lVar7);
      }
    }
    fclose(__stream);
    if (bVar1) {
      return lVar7;
    }
  }
  pcVar8 = &udlso;
  iVar2 = 0;
  do {
    if (*pcVar8 == '\0') {
      return 0;
    }
    iVar3 = iVar2 * 0x80;
    if (udbg_debug_switch != 0) {
      printf("[UDBG_DBG]%s()/%d Try to find from %s\n","udbg_get_fun_addr",0x475,&udlso + iVar3);
      iVar3 = iVar2 << 7;
    }
    strcpy(acStack_128,&udlso + iVar3);
    iVar4 = dlopen(acStack_128,9);
    if (iVar4 != 0) {
      iVar5 = dlsym(iVar4,param_1);
      if (iVar5 != 0) {
        dlclose(iVar4);
        if (udbg_debug_switch != 0) {
          printf("[UDBG_DBG]%s()/%d Function %s found from %s, addr=%p\n","udbg_get_fun_addr",0x486,
                 param_1,&udlso + iVar3,iVar5);
          return iVar5;
        }
        return iVar5;
      }
      dlclose(iVar4);
    }
    iVar2 = iVar2 + 1;
    pcVar8 = pcVar8 + 0x80;
  } while (iVar2 != 0x20);
  return 0;
}

