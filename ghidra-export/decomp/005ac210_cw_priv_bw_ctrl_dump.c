// func cw_priv_bw_ctrl_dump @ 005ac210 size=404

undefined4 cw_priv_bw_ctrl_dump(int param_1)

{
  uint *puVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private bandwidth control \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private bandwidth control type (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tBw_type: %d \r\n",(uint)*pbVar3);
  puVar1 = *(uint **)(pbVar3 + 0xc);
  if ((*pbVar3 == 0) || (*pbVar3 == 4)) {
    printf("\t\t\t\tmac_num: %d \r\n",*puVar1);
    iVar2 = 0;
    for (uVar4 = 0; uVar4 < *puVar1; uVar4 = uVar4 + 1) {
      printf("\t\t\t\tmac[%d]: %02x:%02x:%02x:%02x:%02x:%02x \r\n",uVar4,
             (uint)*(byte *)((int)puVar1 + iVar2 + 4),(uint)*(byte *)((int)puVar1 + iVar2 + 5),
             (uint)*(byte *)((int)puVar1 + iVar2 + 6),(uint)*(byte *)((int)puVar1 + iVar2 + 7),
             (uint)*(byte *)((int)puVar1 + iVar2 + 8),(uint)*(byte *)((int)puVar1 + iVar2 + 9));
      iVar2 = iVar2 + 6;
    }
  }
  else {
    printf("\t\t\t\tradio id: %d \r\n",(uint)*(byte *)puVar1);
    printf("\t\t\t\twlan id: %d \r\n",(uint)*(byte *)((int)puVar1 + 1));
  }
  printf("\t\t\t\tupstream_rate: %d \r\n",*(undefined4 *)(pbVar3 + 4));
  printf("\t\t\t\tdownstream_rate: %d \r\n",*(undefined4 *)(pbVar3 + 8));
  return 0;
}

