// func FUN_00553cc8 @ 00553cc8 size=184

int FUN_00553cc8(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  size_t __n;
  int iVar3;
  
  iVar3 = 0;
  while (pcVar2 = strchr(param_2,0x22), pcVar2 != (char *)0x0) {
    __n = (int)pcVar2 - (int)param_2;
    memcpy(param_1,param_2,__n);
    pcVar1 = param_1 + __n;
    iVar3 = iVar3 + 1;
    param_2 = pcVar2 + 1;
    *pcVar1 = '\"';
    param_1 = param_1 + __n + 2;
    pcVar1[1] = '\"';
  }
  strcpy(param_1,param_2);
  return iVar3;
}

