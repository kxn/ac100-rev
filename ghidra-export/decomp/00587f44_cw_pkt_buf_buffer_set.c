// func cw_pkt_buf_buffer_set @ 00587f44 size=84

undefined4 cw_pkt_buf_buffer_set(undefined4 *param_1,void *param_2,ushort param_3)

{
  undefined4 uVar1;
  uint __n;
  
  __n = (uint)param_3;
  uVar1 = 0xffffffff;
  if ((((param_1 != (undefined4 *)0x0) && ((void *)*param_1 != (void *)0x0)) && (__n != 0)) &&
     ((int)__n <= (int)param_1[2])) {
    *(ushort *)(param_1 + 1) = param_3;
    memcpy((void *)*param_1,param_2,__n);
    uVar1 = 0;
  }
  return uVar1;
}

