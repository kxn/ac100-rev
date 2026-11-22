// func isIndexExisted @ 00619d18 size=184

undefined4 isIndexExisted(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  char *__s1;
  int iVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    for (iVar2 = 0; iVar2 < param_2; iVar2 = iVar2 + 1) {
      __s1 = (char *)*param_4;
      param_4 = param_4 + 1;
      iVar1 = strcmp(__s1,"key");
      if (iVar1 == 0) {
        iVar2 = atoi(*(char **)(param_3 + iVar2 * 4));
        param_1[1] = iVar2;
        *param_1 = 1;
        return 0;
      }
    }
  }
  return 0;
}

