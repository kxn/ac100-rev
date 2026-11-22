// func FUN_0050c8a0 @ 0050c8a0 size=88

int FUN_0050c8a0(char *param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  pcVar1 = strtok(param_1,",");
  while (pcVar1 != (char *)0x0) {
    pcVar1 = strtok((char *)0x0,",");
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

