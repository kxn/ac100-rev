// func uac_count_split @ 00522b44 size=108

int uac_count_split(char *param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  pcVar1 = strtok(param_1,param_2);
  while (pcVar1 != (char *)0x0) {
    iVar2 = iVar2 + 1;
    pcVar1 = strtok((char *)0x0,param_2);
  }
  return iVar2;
}

