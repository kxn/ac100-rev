// func cw_priv_statistics_control_dump @ 005c82cc size=212

undefined4 cw_priv_statistics_control_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private statistics control request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private statistics control request(%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",(uint)*pbVar1);
  printf("\t\t\t\tstation switch: %u\r\n",(uint)*pbVar1);
  printf("\t\t\t\trssi switch: %u\r\n",(uint)pbVar1[1]);
  printf("\t\t\t\tap switch: %u\r\n",(uint)pbVar1[2]);
  printf("\t\t\t\tstation notify intvl: %u\r\n",(uint)*(ushort *)(pbVar1 + 4));
  printf("\t\t\t\trssi notify intvl: %u\r\n",(uint)*(ushort *)(pbVar1 + 6));
  printf("\t\t\t\tap notify intvl: %u\r\n",(uint)*(ushort *)(pbVar1 + 8));
  return 0;
}

