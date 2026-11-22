// func cw_control_header_msg_type_get @ 005a1f08 size=108

undefined4 cw_control_header_msg_type_get(int param_1)

{
  int iVar1;
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_control_header_msg_type_get",0x385,
           "NULL != buffer");
    local_10[0] = 0;
  }
  else {
    iVar1 = cw_header_length_get();
    memcpy(local_10,(void *)(param_1 + iVar1),4);
  }
  return local_10[0];
}

