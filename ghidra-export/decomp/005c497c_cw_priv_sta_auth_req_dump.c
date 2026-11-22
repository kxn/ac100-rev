// func cw_priv_sta_auth_req_dump @ 005c497c size=312

undefined4 cw_priv_sta_auth_req_dump(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private station authentication request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private station authentication request(%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  uVar2 = 0;
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x.. \r\n",(uint)*pbVar1,(uint)pbVar1[1]);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar1);
  printf("\t\t\t\twlan id: %d \r\n",(uint)pbVar1[1]);
  printf("\t\t\t\tclient mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)pbVar1[2],(uint)pbVar1[3],
         (uint)pbVar1[4],(uint)pbVar1[5],(uint)pbVar1[6],(uint)pbVar1[7]);
  printf("\t\t\t\tbackfill length: %d \r\n",*(undefined4 *)(pbVar1 + 8));
  printf("\t\t\t\tbackfill: ");
  if (*(int *)(pbVar1 + 0xc) != 0) {
    for (; uVar2 < *(uint *)(pbVar1 + 8); uVar2 = uVar2 + 1) {
      printf("%02x",(uint)*(byte *)(*(int *)(pbVar1 + 0xc) + uVar2));
    }
  }
  puts("\r");
  return 0;
}

