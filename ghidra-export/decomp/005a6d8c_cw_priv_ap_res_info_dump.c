// func cw_priv_ap_res_info_dump @ 005a6d8c size=196

undefined4 cw_priv_ap_res_info_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap res info \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap res info (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x%02x%04x \r\n",(uint)*pbVar1,(uint)pbVar1[1],(uint)pbVar1[2],
         (uint)*(ushort *)(pbVar1 + 4));
  printf("\t\t\t\tradio id: %u \r\n",(uint)*pbVar1);
  printf("\t\t\t\tradio mode: %u \r\n",(uint)pbVar1[1]);
  printf("\t\t\t\tchannel: %u \r\n",(uint)pbVar1[2]);
  printf("\t\t\t\ttx power: %u \r\n",(uint)*(ushort *)(pbVar1 + 4));
  return 0;
}

