// func cw_msg_ele_priv_format_assemble @ 005a2230 size=164

undefined4 cw_msg_ele_priv_format_assemble(int *param_1,ushort param_2,undefined2 param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_msg_ele_priv_format_assemble",0x126,
           "((NULL != pkt_buf) && (NULL != pkt_buf->buf))");
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0xffffffff;
    if ((3 < (int)(param_1[2] - (uint)*(ushort *)(param_1 + 1))) && (param_2 < 0xc1)) {
      cw_protocol_restore16();
      cw_protocol_restore16(param_1,param_3);
      uVar1 = 0;
    }
  }
  return uVar1;
}

