// func cw_header_rid_set @ 005a192c size=1

void cw_header_rid_set(void *param_1,uint param_2)

{
  uint auStack_18 [3];
  
  auStack_18[0] = 0;
  if (param_1 != (void *)0x0) {
    memcpy(auStack_18,param_1,4);
    auStack_18[0] = (param_2 & 0x1f) << 0xe | auStack_18[0] & 0xfff83fff;
    memcpy(param_1,auStack_18,4);
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_rid_set",0x25b,"NULL != buffer");
  return;
}

