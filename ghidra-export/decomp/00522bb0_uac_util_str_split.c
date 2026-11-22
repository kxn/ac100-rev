// func uac_util_str_split @ 00522bb0 size=176

int uac_util_str_split(char *param_1,char *param_2,int *param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  
  pcVar1 = strtok(param_1,param_2);
  piVar3 = param_3;
  for (iVar2 = 0; (pcVar1 != (char *)0x0 && (iVar2 < param_4)); iVar2 = iVar2 + 1) {
    *piVar3 = (int)pcVar1;
    pcVar1 = strtok((char *)0x0,param_2);
    piVar3 = piVar3 + 1;
  }
  param_3[iVar2] = 0;
  return iVar2;
}

