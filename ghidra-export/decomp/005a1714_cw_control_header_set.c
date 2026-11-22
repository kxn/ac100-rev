// func cw_control_header_set @ 005a1714 size=92

undefined4
cw_control_header_set(int param_1,undefined4 param_2,undefined1 param_3,undefined2 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_control_header_set",0x1e9,
           "NULL != parsed_pkt");
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x10) = param_2;
    *(undefined1 *)(param_1 + 0x14) = param_3;
    *(undefined2 *)(param_1 + 0x16) = param_4;
    *(undefined1 *)(param_1 + 0x18) = 0;
  }
  return uVar1;
}

