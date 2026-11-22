// func cw_header_flag_f_set @ 005a1d6c size=160

void cw_header_flag_f_set(void *param_1,int param_2)

{
  uint local_18 [3];
  
  local_18[0] = 0;
  if (param_1 != (void *)0x0) {
    memcpy(local_18,param_1,4);
    if (param_2 == 0) {
      local_18[0] = local_18[0] & 0xffffff7f;
    }
    else {
      local_18[0] = local_18[0] | 0x80;
    }
    memcpy(param_1,local_18,4);
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_flag_f_set",0x337,"NULL != buffer");
  return;
}

