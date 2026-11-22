// func cw_protocol_clone @ 00572330 size=244

void * cw_protocol_clone(void *param_1,uint param_2)

{
  int iVar1;
  void *__s;
  char *__format;
  undefined4 uVar2;
  
  param_2 = param_2 & 0xffff;
  if ((param_1 == (void *)0x0) || (param_2 == 0)) {
    if (capwap_err_switch == 0) {
      return (void *)0x0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return (void *)0x0;
    }
    __format = "[CW_ERROR]%32s():%4d input parameter is wrong\n";
    uVar2 = 0x1b6;
  }
  else {
    __s = (void *)FUN_00408450(param_2,0x1ba);
    if (__s != (void *)0x0) {
      memset(__s,0,param_2);
      memcpy(__s,param_1,param_2);
      return __s;
    }
    if (capwap_err_switch == 0) {
      return (void *)0x0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return (void *)0x0;
    }
    __format = "[CW_ERROR]%32s():%4d out of memory\n";
    uVar2 = 0x1bd;
  }
  printf(__format,"cw_protocol_clone",uVar2);
  return (void *)0x0;
}

