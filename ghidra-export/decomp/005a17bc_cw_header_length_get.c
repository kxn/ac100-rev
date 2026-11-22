// func cw_header_length_get @ 005a17bc size=96

int cw_header_length_get(void *param_1)

{
  int iVar1;
  int local_10 [3];
  
  local_10[0] = 0;
  if (param_1 == (void *)0x0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_length_get",0x214,"NULL != buffer");
    iVar1 = 0;
  }
  else {
    memcpy(local_10,param_1,4);
    iVar1 = ((uint)(local_10[0] << 8) >> 0x1b) << 2;
  }
  return iVar1;
}

