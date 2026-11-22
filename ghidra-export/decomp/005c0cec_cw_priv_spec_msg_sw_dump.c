// func cw_priv_spec_msg_sw_dump @ 005c0cec size=152

undefined4 cw_priv_spec_msg_sw_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private spec msg sw \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private spec msg sw (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x%8x \r\n",*puVar1,puVar1[1]);
  printf("\t\t\t\tmessage mask: 0x%08x\r\n",*puVar1);
  printf("\t\t\t\tsw mask: 0x%08x\r\n",puVar1[1]);
  return 0;
}

