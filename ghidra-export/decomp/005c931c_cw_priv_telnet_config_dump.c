// func cw_priv_telnet_config_dump @ 005c931c size=132

undefined4 cw_priv_telnet_config_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private telnet config \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private telnet config (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tenable: %d \r\n",(uint)*pbVar1);
  printf("\t\t\t\ttelnet port: %d \r\n",(uint)*(ushort *)(pbVar1 + 2));
  return 0;
}

