// func cw_header_length_set @ 005a181c size=1

void cw_header_length_set(void *param_1,uint param_2)

{
  uint auStack_18 [3];
  
  auStack_18[0] = 0;
  if (((param_1 != (void *)0x0) && ((param_2 & 3) == 0)) && ((param_2 & 0xffff) != 0)) {
    memcpy(auStack_18,param_1,4);
    auStack_18[0] = (((param_2 & 0xffff) << 0x19) >> 0x1b) << 0x13 | auStack_18[0] & 0xff07ffff;
    memcpy(param_1,auStack_18,4);
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_length_set",0x229,
         "(NULL != buffer) && (0 == length % 4 && 0 != length)");
  return;
}

