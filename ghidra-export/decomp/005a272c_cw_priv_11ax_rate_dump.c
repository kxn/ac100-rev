// func cw_priv_11ax_rate_dump @ 005a272c size=180

undefined4 cw_priv_11ax_rate_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private rate \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private rate (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",(uint)*pbVar1);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar1);
  printf("\t\t\t\t11ax base: %d \r\n",(uint)pbVar1[1]);
  printf("\t\t\t\t11ax supp: %d \r\n",(uint)pbVar1[2]);
  printf("\t\t\t\t11ax mult: %d \r\n",(uint)pbVar1[3]);
  return 0;
}

