// func cw_protocol_retrieve_bytes @ 00571c08 size=192

uint cw_protocol_retrieve_bytes(int *param_1,void *param_2,ushort param_3)

{
  int iVar1;
  uint __n;
  
  __n = (uint)param_3;
  if ((((param_1 == (int *)0x0) || (*param_1 == 0)) || (__n == 0)) ||
     (((int)((uint)*(ushort *)(param_1 + 1) - (uint)*(ushort *)((int)param_1 + 6)) < (int)__n ||
      (param_2 == (void *)0x0)))) {
    __n = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_retrieve_bytes",0xde);
    }
  }
  else {
    memcpy(param_2,(void *)(*param_1 + (uint)*(ushort *)((int)param_1 + 6)),__n);
    *(ushort *)((int)param_1 + 6) = param_3 + *(short *)((int)param_1 + 6);
  }
  return __n;
}

