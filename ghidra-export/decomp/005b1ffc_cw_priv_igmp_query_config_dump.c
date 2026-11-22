// func cw_priv_igmp_query_config_dump @ 005b1ffc size=132

undefined4 cw_priv_igmp_query_config_dump(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private igmp query config \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private igmp query config (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tquery interval: %d \r\n",(uint)*puVar1);
  printf("\t\t\t\tmax response time: %d \r\n",(uint)*(byte *)(puVar1 + 1));
  return 0;
}

