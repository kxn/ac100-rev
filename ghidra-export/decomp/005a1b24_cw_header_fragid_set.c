// func cw_header_fragid_set @ 005a1b24 size=72

void cw_header_fragid_set(int param_1,undefined2 param_2)

{
  undefined1 local_8;
  undefined1 uStack_7;
  
  if (param_1 != 0) {
    local_8 = (undefined1)((ushort)param_2 >> 8);
    *(undefined1 *)(param_1 + 4) = local_8;
    uStack_7 = (undefined1)param_2;
    *(undefined1 *)(param_1 + 5) = uStack_7;
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_fragid_set",0x2be,"NULL != buffer");
  return;
}

