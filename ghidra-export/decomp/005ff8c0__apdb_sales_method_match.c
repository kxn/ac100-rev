// func _apdb_sales_method_match @ 005ff8c0 size=284

undefined4 _apdb_sales_method_match(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *__s2;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (param_1 != (char *)0x0) {
    uVar4 = 1;
    iVar2 = strcmp(param_1,&sales_method);
    if ((iVar2 != 0) &&
       ((cVar1 = *param_1, cVar1 != '\0' || (iVar2 = strcmp(&sales_method,"channel"), iVar2 != 0))))
    {
      if ((sales_method == '\0') && (iVar2 = strcmp(param_1,"channel"), iVar2 == 0)) {
        return 1;
      }
      __s2 = &extra_sales_methods;
      for (iVar2 = 0; iVar2 < extra_sales_method_count; iVar2 = iVar2 + 1) {
        iVar3 = strcmp(param_1,__s2);
        if (iVar3 == 0) {
          return 1;
        }
        if ((cVar1 == '\0') && (iVar3 = strcmp(__s2,"channel"), iVar3 == 0)) {
          return 1;
        }
        __s2 = __s2 + 0x81;
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}

