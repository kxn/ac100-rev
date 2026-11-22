// func cw_protocol_retrieve_str @ 005719d0 size=288

void * cw_protocol_retrieve_str(int *param_1,ushort param_2)

{
  void *__dest;
  int iVar1;
  char *__format;
  undefined4 uVar2;
  uint __n;
  
  __n = (uint)param_2;
  if ((((param_1 == (int *)0x0) || (*param_1 == 0)) || (__n == 0)) ||
     ((int)((uint)*(ushort *)(param_1 + 1) - (uint)*(ushort *)((int)param_1 + 6)) < (int)__n)) {
    if (capwap_err_switch == 0) {
      return (void *)0x0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return (void *)0x0;
    }
    __format = "[CW_ERROR]%32s():%4d input parameter is wrong\n";
    uVar2 = 0xa1;
  }
  else {
    __dest = (void *)FUN_00408450(__n + 1,0xa5);
    if (__dest != (void *)0x0) {
      memcpy(__dest,(void *)(*param_1 + (uint)*(ushort *)((int)param_1 + 6)),__n);
      *(undefined1 *)((int)__dest + __n) = 0;
      *(ushort *)((int)param_1 + 6) = param_2 + *(short *)((int)param_1 + 6);
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
    uVar2 = 0xa8;
  }
  printf(__format,"cw_protocol_retrieve_str",uVar2);
  return (void *)0x0;
}

