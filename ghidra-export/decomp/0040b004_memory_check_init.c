// func memory_check_init @ 0040b004 size=408

undefined4 memory_check_init(void)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = false;
  gMemCheckCtx = 0;
  puts("memory_check_init run...!");
  pcVar2 = getenv("MCHK_DEBUG_MALLOC_FREE");
  if (pcVar2 != (char *)0x0) {
    iVar3 = strcmp(pcVar2,"ON");
    if ((iVar3 == 0) && (bVar1 = true, gMemCheckCtx < 1)) {
      printf("[%s:%d]env: %s = %s","memory_check_init",0xc1,"MCHK_OVERFLOW_PROTECT_TYPE",pcVar2);
    }
  }
  uVar4 = 1;
  pcVar2 = getenv("MCHK_OVERFLOW_PROTECT_TYPE");
  if (pcVar2 != (char *)0x0) {
    iVar3 = strcmp(pcVar2,"HEAD");
    if ((iVar3 == 0) && (uVar4 = 0, gMemCheckCtx < 1)) {
      printf("[%s:%d]env: %s = %s","memory_check_init",199,"MCHK_OVERFLOW_PROTECT_TYPE",pcVar2);
    }
  }
  if (gMemCheckCtx < 1) {
    printf("[%s:%d]run....!\n","memory_check_init",0xc9);
  }
  if (bVar1) {
    mcDebugHeapInit(uVar4);
  }
  return 0;
}

