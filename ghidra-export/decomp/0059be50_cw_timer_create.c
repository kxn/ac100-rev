// func cw_timer_create @ 0059be50 size=416

int * cw_timer_create(int param_1,int param_2,int param_3)

{
  int *__s;
  void *__s_00;
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  
  if (((param_1 < 1) || (param_2 < 1)) || (param_3 < 1)) {
    if (capwap_err_switch == 0) {
      return (int *)0x0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return (int *)0x0;
    }
    __format = 
    "[CW_ERROR]%32s():%4d max num,max time or max process times shouldn\'t be less than 0\n";
    uVar2 = 0x49;
  }
  else {
    __s = (int *)FUN_00408450(0x14,0x4c);
    if (__s == (int *)0x0) {
      if (capwap_err_switch == 0) {
        return (int *)0x0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return (int *)0x0;
      }
      __format = "[CW_ERROR]%32s():%4d malloc capwap timer failed\n";
      uVar2 = 0x4f;
    }
    else {
      memset(__s,0,0x14);
      *__s = param_1;
      __s[1] = param_2;
      __s[3] = param_3;
      __s_00 = (void *)FUN_00408450(param_2 * 0xc,0x56);
      __s[4] = (int)__s_00;
      if (__s_00 != (void *)0x0) {
        memset(__s_00,0,__s[1] * 0xc);
        iVar1 = __s[1];
        for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
          FUN_0051ad88(__s[4] + iVar3 * 0xc);
          iVar1 = __s[1];
        }
        return __s;
      }
      FUN_00407df0(__s);
      if (capwap_err_switch == 0) {
        return (int *)0x0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return (int *)0x0;
      }
      __format = "[CW_ERROR]%32s():%4d malloc capwap timer\'s timer list failed\n";
      uVar2 = 0x5a;
    }
  }
  printf(__format,"cw_timer_create",uVar2);
  return (int *)0x0;
}

