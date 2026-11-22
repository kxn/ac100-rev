// func cw_priv_ap_11ac_rate_dump @ 005a38fc size=196

undefined4 cw_priv_ap_11ac_rate_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap 11ac rate \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap 11ac rate (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x%02x%02x \r\n",(uint)*pbVar1,(uint)pbVar1[1],(uint)pbVar1[2],
         (uint)pbVar1[3]);
  printf("\t\t\t\tradio id: %u \r\n ",(uint)*pbVar1);
  printf("\t\t\t\tbase mcs: %u \r\n ",(uint)pbVar1[1]);
  printf("\t\t\t\tsupport mcs: %u \r\n ",(uint)pbVar1[2]);
  printf("\t\t\t\tmulticast mcs: %u \r\n ",(uint)pbVar1[3]);
  return 0;
}

