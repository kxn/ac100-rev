// func uac_cfg_db_reg @ 00513378 size=196

undefined4 uac_cfg_db_reg(char *param_1,int param_2)

{
  void *__s;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    __s = (void *)uac_mem_malloc_my(0x94,0x1f5);
    if (__s != (void *)0x0) {
      memset(__s,0,0x94);
      *(int *)((int)__s + 0x90) = param_2;
      uVar1 = 0;
      strncpy((char *)((int)__s + 0xc),param_1,0x80);
      uac_list_insert_last(&cfg_reg_list,__s);
    }
  }
  return uVar1;
}

