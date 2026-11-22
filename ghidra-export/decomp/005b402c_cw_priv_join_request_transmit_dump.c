// func cw_priv_join_request_transmit_dump @ 005b402c size=148

undefined4 cw_priv_join_request_transmit_dump(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private MESH2.0 Router join request transmit \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private MESH2.0 Router join request transmit (%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x\r\n",(uint)*puVar1);
  printf("\t\t\t\tjoin request transmit_interval: %d\r\n",(uint)*puVar1);
  printf("\t\t\t\tjoin request transmit_times: %d\r\n",(uint)puVar1[1]);
  return 0;
}

