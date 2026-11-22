// func cw_priv_sta_deassoc_dump @ 005c576c size=200

undefined4 cw_priv_sta_deassoc_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private station disassocitation \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private station disassocitation(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x.. \r\n",(uint)*pbVar1,(uint)pbVar1[1]);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar1);
  printf("\t\t\t\twlan id: %d \r\n",(uint)pbVar1[1]);
  printf("\t\t\t\tclient mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)pbVar1[2],(uint)pbVar1[3],
         (uint)pbVar1[4],(uint)pbVar1[5],(uint)pbVar1[6],(uint)pbVar1[7]);
  return 0;
}

