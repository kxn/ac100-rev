// func udbg_help_register @ 005d5704 size=280

void udbg_help_register(char *param_1,char *param_2)

{
  void *__s;
  
  if ((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) {
    if (udbg_err_switch != 0) {
      printf("[UDBG_ERR]%s()/%d Error input parm\n","udbg_help_register",0x84f);
      return;
    }
  }
  else {
    __s = (void *)FUN_00408450(0xcc,0x853);
    if (__s != (void *)0x0) {
      memset(__s,0,0xcc);
      strncpy((char *)((int)__s + 0xc),param_1,0x5f);
      strncpy((char *)((int)__s + 0x6c),param_2,0x5f);
      FUN_004086b0(&udbg_help_list,__s);
      return;
    }
    if (udbg_err_switch != 0) {
      printf("[UDBG_ERR]%s()/%d Malloc memory failed, mod=[%s], help-fun=[%s]\n",
             "udbg_help_register",0x856,param_1,param_2);
    }
  }
  return;
}

