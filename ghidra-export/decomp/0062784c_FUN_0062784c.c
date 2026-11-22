// func FUN_0062784c @ 0062784c size=152

int FUN_0062784c(char *param_1,int *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  
  pcVar1 = strtok(param_1,",");
  piVar3 = param_2;
  for (iVar2 = 0; (pcVar1 != (char *)0x0 && (iVar2 < param_3)); iVar2 = iVar2 + 1) {
    *piVar3 = (int)pcVar1;
    pcVar1 = strtok((char *)0x0,",");
    piVar3 = piVar3 + 1;
  }
  param_2[iVar2] = 0;
  return iVar2;
}

