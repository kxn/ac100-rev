// func cw_priv_sniffing_control_dump @ 005c014c size=160

undefined4 cw_priv_sniffing_control_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private sniffing control request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private sniffing control request(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc))
  ;
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tsniffer_switch: %d \r\n",(uint)*pbVar1);
  printf("\t\t\t\treport_time: %u \r\n",(uint)*(ushort *)(pbVar1 + 2));
  printf("\t\t\t\treport_count: %u \r\n",(uint)*(ushort *)(pbVar1 + 4));
  puts("\r");
  return 0;
}

