// func udbg_init_dl @ 005d2c70 size=532

void udbg_init_dl(void)

{
  int iVar1;
  FILE *__stream;
  int iVar2;
  size_t sVar3;
  char *__s;
  char acStack_128 [256];
  
  iVar1 = access("/usr/bin/ldd",0);
  if (iVar1 == 0) {
    sprintf(acStack_128,"dd if=%s of=%s","/usr/bin/ldd","/lib/ldd");
    system(acStack_128);
  }
  sprintf(acStack_128,"%s %s 2>/dev/null | awk \'{print $1}\' | grep / > %s","/lib/ldd",
          UDBG_BIN_FILE,UDBG_SO_FILE);
  system(acStack_128);
  iVar1 = 0;
  sprintf(acStack_128,"%s %s 2>/dev/null | awk \'{print $3}\' | grep / >> %s","/lib/ldd",
          UDBG_BIN_FILE,UDBG_SO_FILE);
  system(acStack_128);
  __stream = fopen(UDBG_SO_FILE,"r");
  if (__stream == (FILE *)0x0) {
    if (udbg_err_switch != 0) {
      printf("[UDBG_ERR]%s()/%d Open sofile failed.\n","udbg_init_dl",0x418);
    }
  }
  else {
    do {
      do {
        iVar2 = feof(__stream);
        if (iVar2 != 0) goto LAB_005d2db0;
        __s = &udlso + iVar1 * 0x80;
        fgets(__s,0x80,__stream);
        sVar3 = strlen(__s);
        if ((&DAT_007c5a4f)[iVar1 * 0x80 + sVar3] == '\n') {
          (&DAT_007c5a4f)[iVar1 * 0x80 + sVar3] = '\0';
          sVar3 = strlen(__s);
        }
      } while (sVar3 == 0);
      if (udbg_debug_switch != 0) {
        printf("[UDBG_DBG]%s()/%d Library %s loaded.\n","udbg_init_dl",0x42a,__s);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != 0x20);
LAB_005d2db0:
    fclose(__stream);
    sprintf(acStack_128,"rm -f %s",UDBG_SO_FILE);
    system(acStack_128);
  }
  return;
}

