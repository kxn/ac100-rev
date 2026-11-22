// func cw_priv_spec_rssi_dump @ 005c0ffc size=132

undefined4 cw_priv_spec_rssi_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private spec rssi \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private spec rssi (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x \r\n",*puVar1);
  printf("\t\t\t\tprivate spec rssi: %d \r\n ",*puVar1);
  return 0;
}

