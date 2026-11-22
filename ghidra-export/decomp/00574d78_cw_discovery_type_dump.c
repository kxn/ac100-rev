// func cw_discovery_type_dump @ 00574d78 size=184

undefined4 cw_discovery_type_dump(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Discovery Type \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Discovery Type (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x \r\n",(uint)*pbVar3);
  uVar2 = (uint)*pbVar3;
  if (uVar2 < 5) {
    printf("\t\t\tDiscovery Type: %s (%d) \r\n",(&PTR_s_Unknow_006d8880)[uVar2]);
    uVar1 = 0;
  }
  else {
    printf("\t\t\t***Discovery Type(%d) is Wrong \r\n",uVar2);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

