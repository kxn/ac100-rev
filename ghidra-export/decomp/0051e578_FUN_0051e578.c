// func FUN_0051e578 @ 0051e578 size=8

/* WARNING: Enum "__rlimit_resource": Some values do not have unique names */

undefined4 FUN_0051e578(void)

{
  int iVar1;
  undefined4 uVar2;
  rlimit local_20;
  rlimit rStack_18;
  
  uVar2 = 0;
  if (DAT_007c3b50 == 0) {
    uVar2 = 0xffffffff;
    iVar1 = getrlimit(__RLIMIT_MSGQUEUE,&rStack_18);
    if (iVar1 == 0) {
      local_20.rlim_max = 0x7fffffff;
      local_20.rlim_cur = 0x7fffffff;
      iVar1 = setrlimit(__RLIMIT_MSGQUEUE,&local_20);
      if (iVar1 == 0) {
        uVar2 = 0;
        DAT_007c3b50 = 1;
      }
    }
  }
  return uVar2;
}

