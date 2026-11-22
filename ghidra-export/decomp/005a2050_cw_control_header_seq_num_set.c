// func cw_control_header_seq_num_set @ 005a2050 size=112

void cw_control_header_seq_num_set(int param_1,undefined1 param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = cw_header_length_get();
    *(undefined1 *)(param_1 + iVar1 + 4) = param_2;
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_control_header_seq_num_set",0x3c2,
         "NULL != buffer");
  return;
}

