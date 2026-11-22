// func cw_protocol_duplicate_string @ 00572424 size=232

void * cw_protocol_duplicate_string(void *param_1,uint param_2)

{
  int iVar1;
  void *__dest;
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
    uVar2 = 0x1d5;
  }
  else {
    __dest = (void *)FUN_00408450(param_2 + 1,0x1d9);
    if (__dest != (void *)0x0) {
      memcpy(__dest,param_1,param_2);
      *(undefined1 *)((int)__dest + param_2) = 0;
      return __dest;
    }
    if (capwap_err_switch == 0) {
      return (void *)0x0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return (void *)0x0;
    }
    __format = "[CW_ERROR]%32s():%4d out of memory\n";
    uVar2 = 0x1dc;
  }
  printf(__format,"cw_protocol_duplicate_string",uVar2);
  return (void *)0x0;
}

