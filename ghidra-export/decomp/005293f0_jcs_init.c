// func jcs_init @ 005293f0 size=372

undefined4 jcs_init(void)

{
  __pid_t _Var1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (DAT_007c5438 == 0) {
    if (jcs_cb_tbl != 0) {
      if (jcs_debug_switch != 0) {
        printf("[JCS_DBG]%s()/%d jcs callback table has existed already!\n","jcs_init",0x1b6);
      }
      DAT_007c5438 = 1;
      return 0;
    }
    jcs_cb_tbl = uac_hash_new_fixed(jcs_hash_obj_func,jcs_hash_key_func,jcs_hash_cmp_func,0x100);
    if (jcs_cb_tbl == 0) {
      uVar4 = 0xffffffff;
      if (jcs_err_switch == 0) {
        return 0xffffffff;
      }
      uVar3 = 0x1c0;
      __format = "[JCS_ERR]%s()/%d Malloc jcs callback table failed.\n";
    }
    else {
      _Var1 = getpid();
      iVar2 = uac_com_get_name_by_pid(_Var1,&pname);
      if (-1 < iVar2) {
        DAT_007c5438 = 1;
        return 0;
      }
      uVar4 = 0xffffffff;
      if (jcs_err_switch == 0) {
        return 0xffffffff;
      }
      uVar3 = 0x1c6;
      __format = "[JCS_ERR]%s()/%d Get process name failed.\n";
    }
  }
  else {
    uVar4 = 0;
    if (jcs_debug_switch == 0) {
      return 0;
    }
    uVar3 = 0x1b0;
    __format = "[JCS_DBG]%s()/%d jcs has been inited already!\n";
  }
  printf(__format,"jcs_init",uVar3);
  return uVar4;
}

