// func cw_header_fragoffset_set @ 005a1bc8 size=76

void cw_header_fragoffset_set(int param_1,int param_2)

{
  undefined1 local_8;
  undefined1 uStack_7;
  
  if (param_1 != 0) {
    local_8 = (undefined1)((uint)(param_2 << 3) >> 8);
    *(undefined1 *)(param_1 + 6) = local_8;
    uStack_7 = (undefined1)(param_2 << 3);
    *(undefined1 *)(param_1 + 7) = uStack_7;
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_fragoffset_set",0x2e1,"NULL != buffer")
  ;
  return;
}

