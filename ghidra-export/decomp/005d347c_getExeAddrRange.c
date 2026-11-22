// func getExeAddrRange @ 005d347c size=420

void getExeAddrRange(void)

{
  FILE *__stream;
  char *pcVar1;
  ulong uVar2;
  int iVar3;
  char acStack_388 [32];
  char acStack_368 [64];
  char acStack_328 [256];
  char acStack_228 [512];
  
  memset(acStack_228,0,0x200);
  memset(acStack_368,0,0x40);
  memset(acStack_328,0,0x100);
  memset(acStack_388,0,0x20);
  memset(&valid_addr_range,0,21000);
  __stream = fopen("/proc/self/maps","r");
  iVar3 = 0;
  if (__stream != (FILE *)0x0) {
    while( true ) {
      pcVar1 = fgets(acStack_228,0x200,__stream);
      if ((pcVar1 == (char *)0x0) || (0x95 < iVar3)) break;
      sscanf(acStack_228,"%s %s %*s %*s %*s %s",acStack_368,acStack_388,acStack_328);
      pcVar1 = strchr(acStack_388,0x78);
      if ((pcVar1 != (char *)0x0) && (pcVar1 = strchr(acStack_368,0x2d), pcVar1 != (char *)0x0)) {
        *pcVar1 = '\0';
        uVar2 = strtoul(acStack_368,(char **)0x0,0x10);
        (&valid_addr_range)[iVar3 * 0x23] = uVar2;
        uVar2 = strtoul(pcVar1 + 1,(char **)0x0,0x10);
        (&DAT_007c6a58)[iVar3 * 0x23] = uVar2;
        strncpy(&DAT_007c6a5c + iVar3 * 0x8c,acStack_328,0x7f);
        (&DAT_007c6adb)[iVar3 * 0x8c] = 0;
        iVar3 = iVar3 + 1;
      }
    }
    fclose(__stream);
  }
  return;
}

