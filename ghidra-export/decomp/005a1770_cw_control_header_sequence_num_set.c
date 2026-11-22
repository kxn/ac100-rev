// func cw_control_header_sequence_num_set @ 005a1770 size=76

undefined4 cw_control_header_sequence_num_set(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_control_header_sequence_num_set",0x201,
           "NULL != parsed_pkt");
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    *(undefined1 *)(param_1 + 0x14) = param_2;
  }
  return uVar1;
}

