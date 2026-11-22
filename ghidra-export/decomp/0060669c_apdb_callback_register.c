// func apdb_callback_register @ 0060669c size=420

undefined4 apdb_callback_register(int param_1)

{
  void *__s;
  size_t sVar1;
  void *__s_00;
  undefined4 uVar2;
  char *pcVar3;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) == 0)) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APDB_ERROR]%s()/line %d : input error\n";
    uVar2 = 0x205d;
  }
  else {
    __s = (void *)FUN_00408450(0x18,0x2061);
    if (__s != (void *)0x0) {
      memset(__s,0,0x18);
      sVar1 = strlen(*(char **)(param_1 + 0xc));
      __s_00 = (void *)FUN_00408450(sVar1 + 1,0x2069);
      *(void **)((int)__s + 0xc) = __s_00;
      if (__s_00 != (void *)0x0) {
        sVar1 = strlen(*(char **)(param_1 + 0xc));
        memset(__s_00,0,sVar1 + 1);
        pcVar3 = *(char **)(param_1 + 0xc);
        sVar1 = strlen(pcVar3);
        strncpy(*(char **)((int)__s + 0xc),pcVar3,sVar1);
        *(undefined4 *)((int)__s + 0x10) = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 *)((int)__s + 0x14) = *(undefined4 *)(param_1 + 0x14);
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : insert register entry\n","apdb_callback_register",
                 0x2075);
        }
        FUN_004086b0(&l_apdb_callback_list,__s);
        return 0;
      }
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : malloc reg_node name error\n","apdb_callback_register",
               0x206c);
      }
      FUN_00407df0(__s);
      return 0xffffffff;
    }
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APDB_ERROR]%s()/line %d : malloc reg_node error\n";
    uVar2 = 0x2064;
  }
  printf(pcVar3,"apdb_callback_register",uVar2);
  return 0xffffffff;
}

