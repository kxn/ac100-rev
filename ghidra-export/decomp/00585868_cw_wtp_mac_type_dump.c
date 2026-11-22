// func cw_wtp_mac_type_dump @ 00585868 size=184

undefined4 cw_wtp_mac_type_dump(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) WTP MAC Type \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: WTP MAC Type (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x \r\n",(uint)*pbVar3);
  uVar2 = (uint)*pbVar3;
  if (uVar2 < 3) {
    printf("\t\t\tWTP MAC Type: %s (%d) \r\n",(&PTR_s_Local_MAC_006dd410)[uVar2]);
    uVar1 = 0;
  }
  else {
    printf("\t\t\t***WTP MAC Type(%d) is wrong \r\n",uVar2);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

