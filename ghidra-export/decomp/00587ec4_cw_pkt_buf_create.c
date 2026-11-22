// func cw_pkt_buf_create @ 00587ec4 size=128

int * cw_pkt_buf_create(int param_1)

{
  int iVar1;
  int *__s;
  
  __s = (int *)0x0;
  if ((0 < param_1) && (__s = (int *)FUN_00408450(0x28,0x463), __s != (int *)0x0)) {
    memset(__s,0,0x28);
    iVar1 = FUN_00408450(param_1,0x467);
    *__s = iVar1;
    __s[2] = param_1;
    if (iVar1 == 0) {
      FUN_00407df0(__s);
      __s = (int *)0x0;
    }
  }
  return __s;
}

