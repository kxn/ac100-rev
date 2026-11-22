// func _apdb_unsupport_cmp_func @ 0060ece4 size=108

bool _apdb_unsupport_cmp_func(char *param_1,char *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if (((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) &&
     (iVar1 = strcmp(param_1,param_2), iVar1 == 0)) {
    iVar1 = memcmp(param_1 + 0x42,param_2 + 0x42,4);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

