// func cw_timer_add @ 0059bff0 size=576

void * cw_timer_add(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  int iVar1;
  void *__s;
  char *__format;
  undefined4 uVar2;
  longlong lVar3;
  
  if (param_1 == (int *)0x0) {
    if (capwap_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return (void *)0x0;
      }
      __format = "[CW_ERROR]%32s():%4d The cw_timer is NULL\n";
      uVar2 = 0x78;
      goto LAB_0059c1e8;
    }
  }
  else if (param_2 == 0) {
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "[CW_ERROR]%32s():%4d timer\'s time to be set can not be 0 sec\n";
      uVar2 = 0x7d;
      goto LAB_0059c1e8;
    }
  }
  else {
    if (param_2 <= param_1[1]) {
      if (param_1[2] < *param_1) {
        __s = (void *)FUN_00408450(0x30,0x8a);
        if (__s != (void *)0x0) {
          memset(__s,0,0x30);
          lVar3 = FUN_00524078();
          *(int *)((int)__s + 0x18) = param_2;
          *(undefined4 *)((int)__s + 0x1c) = param_3;
          *(undefined4 *)((int)__s + 0x24) = param_4;
          lVar3 = lVar3 + param_2 * 1000000;
          *(int *)((int)__s + 0x14) = (int)lVar3;
          *(undefined4 *)((int)__s + 0x20) = param_5;
          *(int *)((int)__s + 0x10) = (int)((ulonglong)lVar3 >> 0x20);
          param_1[2] = param_1[2] + 1;
          FUN_004086b0(param_1[4] + (param_2 + -1) * 0xc,__s);
          return __s;
        }
        if (capwap_err_switch == 0) {
          return (void *)0x0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return (void *)0x0;
        }
        __format = "[CW_ERROR]%32s():%4d malloc capwap timer node failed\n";
        uVar2 = 0x8d;
      }
      else {
        if (capwap_err_switch == 0) {
          return (void *)0x0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return (void *)0x0;
        }
        __format = 
        "[CW_ERROR]%32s():%4d the timer list is already full, can not add new timers for now\n";
        uVar2 = 0x87;
      }
LAB_0059c1e8:
      printf(__format,"cw_timer_add",uVar2);
      return (void *)0x0;
    }
    if (capwap_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 != 0) {
        printf("[CW_ERROR]%32s():%4d timer\'s time(%d) is too big, should be no more than %ds\n",
               "cw_timer_add",0x82,param_2,param_1[1]);
        return (void *)0x0;
      }
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}

