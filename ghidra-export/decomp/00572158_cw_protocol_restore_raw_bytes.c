// func cw_protocol_restore_raw_bytes @ 00572158 size=188

uint cw_protocol_restore_raw_bytes(int *param_1,void *param_2,ushort param_3)

{
  int iVar1;
  uint __n;
  
  __n = (uint)param_3;
  if ((((param_1 == (int *)0x0) || (*param_1 == 0)) || (__n == 0)) ||
     (((int)(param_1[2] - (uint)*(ushort *)(param_1 + 1)) < (int)__n || (param_2 == (void *)0x0))))
  {
    __n = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_restore_raw_bytes",0x17e
            );
    }
  }
  else {
    memcpy((void *)(*param_1 + (uint)*(ushort *)(param_1 + 1)),param_2,__n);
    *(ushort *)(param_1 + 1) = param_3 + *(short *)(param_1 + 1);
  }
  return __n;
}

