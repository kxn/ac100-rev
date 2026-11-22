// func apupd_upgrade_check_reg @ 006497c8 size=292

undefined4 apupd_upgrade_check_reg(int param_1)

{
  void *__s;
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: input error\r\n";
    uVar2 = 0x1312;
  }
  else {
    __s = (void *)FUN_00408450(0x10,0x1316);
    if (__s != (void *)0x0) {
      memset(__s,0,0x10);
      *(int *)((int)__s + 0xc) = param_1;
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: insert register entry\r\n","apupd_upgrade_check_reg",
               0x1320);
      }
      FUN_004086b0(&apupd_check_callback_list,__s);
      return 0;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: malloc reg_node error\r\n";
    uVar2 = 0x1319;
  }
  printf(__format,"apupd_upgrade_check_reg",uVar2);
  return 0xffffffff;
}

