// func cw_msg_ele_priv_format_parse @ 005a2180 size=176

undefined4 cw_msg_ele_priv_format_parse(int *param_1,undefined2 *param_2,undefined2 *param_3)

{
  undefined2 uVar2;
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_msg_ele_priv_format_parse",0x108,
           "((NULL != pkt_buf) && (NULL != pkt_buf->buf))");
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0xffffffff;
    if (((uint)*(ushort *)((int)param_1 + 6) <= (uint)*(ushort *)(param_1 + 1)) &&
       (3 < (int)((uint)*(ushort *)(param_1 + 1) - (uint)*(ushort *)((int)param_1 + 6)))) {
      uVar2 = cw_protocol_retrieve16();
      *param_2 = uVar2;
      uVar2 = cw_protocol_retrieve16(param_1);
      *param_3 = uVar2;
      uVar1 = 0;
    }
  }
  return uVar1;
}

