// func cw_header_flag_t_set @ 005a1c70 size=1

void cw_header_flag_t_set(void *param_1,int param_2)

{
  uint auStack_18 [3];
  
  auStack_18[0] = 0;
  if (param_1 != (void *)0x0) {
    memcpy(auStack_18,param_1,4);
    if (param_2 == 0) {
      auStack_18[0] = auStack_18[0] & 0xfffffeff;
    }
    else {
      auStack_18[0] = auStack_18[0] | 0x100;
    }
    memcpy(param_1,auStack_18,4);
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_flag_t_set",0x306,"NULL != buffer");
  return;
}

