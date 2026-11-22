// func cw_priv_special_frame_rate_ctrl_dump @ 005bb1bc size=296

undefined4 cw_priv_special_frame_rate_ctrl_dump(int param_1)

{
  ushort *puVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private special frame rate ctrl \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private special frame rate ctrl (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc))
  ;
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x%02x%02x...\r\n",(uint)*pbVar2,(uint)pbVar2[1],(uint)pbVar2[2],
         (uint)pbVar2[3]);
  printf("\t\t\t\tradio id: %u \r\n",(uint)*pbVar2);
  printf("\t\t\t\twlan id: %u \r\n",(uint)pbVar2[1]);
  printf("\t\t\t\tframe cnt: %u \r\n",(uint)pbVar2[2]);
  if ((pbVar2[2] != 0) && (*(int *)(pbVar2 + 4) != 0)) {
    iVar4 = 0;
    printf("\t\t\t\tframe info:\r\n ");
    iVar3 = 0;
    while (iVar3 < (int)(uint)pbVar2[2]) {
      iVar3 = iVar3 + 1;
      puVar1 = (ushort *)(*(int *)(pbVar2 + 4) + iVar4);
      iVar4 = iVar4 + 4;
      printf("\t\t\t\t\t%d:(%d, %d)\r\n",iVar3,(uint)*puVar1,(uint)puVar1[1]);
    }
  }
  return 0;
}

