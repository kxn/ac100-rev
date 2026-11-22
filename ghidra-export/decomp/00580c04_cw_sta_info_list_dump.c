// func cw_sta_info_list_dump @ 00580c04 size=356

undefined4 cw_sta_info_list_dump(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) station info list \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: station info list (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x... \r\n",(uint)*pbVar1);
  printf("\t\t\tradio id: %d \r\n",(uint)*pbVar1);
  printf("\t\t\twlan id: %d \r\n",*(undefined4 *)(pbVar1 + 4));
  printf("\t\t\tstation count: %d \r\n",*(undefined4 *)(pbVar1 + 8));
  if ((*(int *)(pbVar1 + 8) != 0) && (uVar2 = 0, *(int *)(pbVar1 + 0xc) != 0)) {
    for (; uVar2 < *(uint *)(pbVar1 + 8); uVar2 = uVar2 + 1) {
      iVar3 = uVar2 * 0x10;
      printf("\t\t\tonline time: %d \r\n",*(undefined4 *)(*(int *)(pbVar1 + 0xc) + iVar3));
      printf("\t\t\trssi: %d \r\n",*(undefined4 *)(*(int *)(pbVar1 + 0xc) + iVar3 + 4));
      iVar3 = *(int *)(pbVar1 + 0xc) + iVar3;
      printf("\t\t\tclient mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*(byte *)(iVar3 + 8),
             (uint)*(byte *)(iVar3 + 9),(uint)*(byte *)(iVar3 + 10),(uint)*(byte *)(iVar3 + 0xb),
             (uint)*(byte *)(iVar3 + 0xc),(uint)*(byte *)(iVar3 + 0xd));
    }
  }
  return 0;
}

