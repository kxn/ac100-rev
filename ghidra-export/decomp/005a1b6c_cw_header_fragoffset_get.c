// func cw_header_fragoffset_get @ 005a1b6c size=92

ushort cw_header_fragoffset_get(int param_1)

{
  ushort uVar1;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_fragoffset_get",0x2ce,
           "NULL != buffer");
    uVar1 = 0;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 6) >> 3;
  }
  return uVar1;
}

