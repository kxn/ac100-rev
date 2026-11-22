// func resolveAddr @ 005d37c8 size=716

void resolveAddr(uint *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  FILE *__stream;
  char *__nptr;
  char *pcVar3;
  ulong uVar4;
  ulong uVar5;
  char *pcVar6;
  size_t sVar7;
  uint uVar8;
  int iVar9;
  undefined4 local_220;
  undefined4 local_21c;
  char *local_218;
  undefined4 local_214;
  char acStack_210 [100];
  undefined1 auStack_1ac [127];
  char acStack_12d [261];
  
  iVar9 = 0;
  memset(auStack_1ac,0,0x80);
  memset(acStack_210,0,0x61);
  do {
    if (param_2 <= iVar9) {
      return;
    }
    uVar8 = *param_1;
    if (uVar8 == 0) {
      return;
    }
    memset(acStack_210,0,0x61);
    local_220 = 0;
    local_21c = 0;
    local_218 = (char *)0x0;
    local_214 = 0;
    iVar2 = access(UDBG_FUN_FILE,0);
    if (iVar2 == 0) {
      __stream = fopen(UDBG_FUN_FILE,"r");
      if (__stream == (FILE *)0x0) {
        if (udbg_err_switch != 0) {
          printf("[UDBG_ERR]%s()/%d Open uac_symbol_fun failed.\n","getAddrFuncName",0x21e);
        }
        goto LAB_005d3a0c;
      }
      while( true ) {
        pcVar6 = fgets(acStack_12d + 1,0x100,__stream);
        bVar1 = false;
        if (pcVar6 == (char *)0x0) break;
        sVar7 = strlen(acStack_12d + 1);
        if (acStack_12d[sVar7] == '\n') {
          acStack_12d[sVar7] = '\0';
        }
        pcVar6 = strtok(acStack_12d + 1," ");
        if ((((pcVar6 != (char *)0x0) && (__nptr = strtok((char *)0x0," "), __nptr != (char *)0x0))
            && (pcVar3 = strtok((char *)0x0," "), pcVar3 != (char *)0x0)) &&
           (pcVar3 = strtok((char *)0x0," "), pcVar3 != (char *)0x0)) {
          uVar4 = strtoul(pcVar6,(char **)0x0,0x10);
          uVar5 = strtoul(__nptr,(char **)0x0,0x10);
          if ((uVar4 <= uVar8) && (uVar8 < uVar5 + uVar4)) {
            strncpy(acStack_210,pcVar3,0x60);
            bVar1 = true;
            if (udbg_debug_switch != 0) {
              printf("[UDBG_DBG]%s()/%d Function %s() found from global symbol table, addr=0x%08x\n"
                     ,"getAddrFuncName",0x24c,acStack_210,uVar8);
            }
            break;
          }
        }
        memset(acStack_12d + 1,0,0x100);
      }
      fclose(__stream);
      if (!bVar1) goto LAB_005d398c;
    }
    else {
LAB_005d398c:
      dladdr(uVar8,&local_220);
      if (local_218 == (char *)0x0) {
LAB_005d3a0c:
        strcpy(acStack_210,"(null)");
      }
      else {
        strncpy(acStack_210,local_218,0x60);
      }
    }
    getCodeIn(*param_1,auStack_1ac,0x80);
    printf("<%d>:[0x%08x]:{%s}, in %s\r\n",iVar9,*param_1,acStack_210,auStack_1ac);
    iVar9 = iVar9 + 1;
    param_1 = param_1 + 1;
  } while( true );
}

