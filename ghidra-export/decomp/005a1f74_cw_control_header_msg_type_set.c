// func cw_control_header_msg_type_set @ 005a1f74 size=1

void cw_control_header_msg_type_set(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 auStack_18 [3];
  
  auStack_18[0] = 0;
  if (param_1 != 0) {
    iVar1 = cw_header_length_get();
    auStack_18[0] = param_2;
    memcpy((void *)(param_1 + iVar1),auStack_18,4);
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_control_header_msg_type_set",0x39b,
         "NULL != buffer");
  return;
}

