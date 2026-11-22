// func cw_ac_manager_data_create @ 00589a18 size=124

void * cw_ac_manager_data_create(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *__s;
  
  __s = (void *)FUN_00408450(0x18,0x4a1);
  if (__s != (void *)0x0) {
    memset(__s,0,0x18);
    FUN_0051ad88(__s);
    *(undefined4 *)((int)__s + 0xc) = param_1;
    *(undefined4 *)((int)__s + 0x10) = param_2;
    *(undefined4 *)((int)__s + 0x14) = param_3;
  }
  return __s;
}

