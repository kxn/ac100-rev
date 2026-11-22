// func cw_priv_pwr_state_dump @ 005b918c size=152

undefined4 cw_priv_pwr_state_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private power state \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private power state (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x \r\n",(uint)*pbVar1,(uint)pbVar1[1]);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar1);
  printf("\t\t\t\top: %d \r\n",(uint)pbVar1[1]);
  return 0;
}

