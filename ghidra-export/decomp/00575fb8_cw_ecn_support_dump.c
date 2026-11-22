// func cw_ecn_support_dump @ 00575fb8 size=184

undefined4 cw_ecn_support_dump(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) ECN Support \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: ECN Support (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x \r\n",(uint)*pbVar3);
  uVar2 = (uint)*pbVar3;
  if (uVar2 < 2) {
    printf("\t\t\tECN Support: %s (%d) \r\n",*(undefined4 *)(&UNK_006d8c70 + uVar2 * 4));
    uVar1 = 0;
  }
  else {
    printf("\t\t\t***ECN Support(%d) is wrong \r\n",uVar2);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

