// func cw_send_pkt_buffer_set @ 005883c8 size=52

undefined4 cw_send_pkt_buffer_set(int param_1,int param_2,short param_3)

{
  undefined4 uVar1;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) && (param_2 != 0)) && (param_3 != 0)) {
    uVar1 = cw_pkt_buf_buffer_set(param_1 + 0x10);
    return uVar1;
  }
  return 0xffffffff;
}

