// func cw_header_flag_t_get @ 005a1c14 size=92

uint cw_header_flag_t_get(void *param_1)

{
  uint uVar1;
  int local_10 [3];
  
  local_10[0] = 0;
  if (param_1 == (void *)0x0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_flag_t_get",0x2f1,"NULL != buffer");
    uVar1 = 0;
  }
  else {
    memcpy(local_10,param_1,4);
    uVar1 = (uint)(local_10[0] << 0x17) >> 0x1f;
  }
  return uVar1;
}

