// func _radius_find_option @ 00447788 size=172

char * _radius_find_option(int *param_1,char *param_2,uint param_3)

{
  int iVar1;
  char *__s1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while( true ) {
    __s1 = (char *)(iVar1 + iVar2);
    iVar1 = strcmp(__s1,param_2);
    if ((iVar1 == 0) && ((param_3 & *(uint *)(__s1 + 0x40)) != 0)) break;
    iVar2 = iVar2 + 0x4c;
    if (iVar2 == 0xe4) {
      return (char *)0x0;
    }
    iVar1 = *param_1;
  }
  return __s1;
}

