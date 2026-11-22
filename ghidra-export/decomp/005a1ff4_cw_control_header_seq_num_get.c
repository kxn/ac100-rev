// func cw_control_header_seq_num_get @ 005a1ff4 size=92

undefined1 cw_control_header_seq_num_get(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_control_header_seq_num_get",0x3ae,
           "NULL != buffer");
    uVar2 = 0;
  }
  else {
    iVar1 = cw_header_length_get();
    uVar2 = *(undefined1 *)(param_1 + iVar1 + 4);
  }
  return uVar2;
}

