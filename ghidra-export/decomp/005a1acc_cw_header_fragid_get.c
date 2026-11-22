// func cw_header_fragid_get @ 005a1acc size=88

undefined2 cw_header_fragid_get(int param_1)

{
  undefined2 uVar1;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_fragid_get",0x2aa,"NULL != buffer");
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined2 *)(param_1 + 4);
  }
  return uVar1;
}

