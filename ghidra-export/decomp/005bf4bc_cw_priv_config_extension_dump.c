// func cw_priv_config_extension_dump @ 005bf4bc size=516

undefined4 cw_priv_config_extension_dump(int param_1)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  pbVar4 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private wlan_serv_config_extension list \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private wlan_serv_config_extension list (%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tradio_id: %d \r\n",(uint)*pbVar4);
  printf("\t\t\t\twlan_list_len: %d \r\n",*(undefined4 *)(pbVar4 + 4));
  puts("\t\t\t\twlan info: \r");
  if ((*(int *)(pbVar4 + 4) != 0) && (uVar5 = 0, *(int *)(pbVar4 + 8) != 0)) {
    uVar1 = *(uint *)(pbVar4 + 4);
    for (; uVar5 < uVar1; uVar5 = uVar8 + uVar5 + 5) {
      printf("\t\t\t\t\twlan_id: %d\r\n",(uint)*(byte *)(*(int *)(pbVar4 + 8) + uVar5));
      pbVar2 = (byte *)(*(int *)(pbVar4 + 8) + uVar5 + 1);
      uVar8 = (uint)*pbVar2 * 0x1000000 + (uint)pbVar2[1] * 0x10000 + (uint)pbVar2[2] * 0x100 +
              (uint)pbVar2[3];
      printf("\t\t\t\t\textConfLen: %d\r\n",uVar8);
      puts("\t\t\t\t\textConfList: \r");
      printf("\t\t\t\t\t\t tag\t len\t value\t \r\n: ");
      for (uVar1 = 0; uVar1 < uVar8; uVar1 = uVar1 + uVar6 + 2 & 0xff) {
        iVar7 = uVar5 + 5 + uVar1;
        printf("\t\t\t\t\t\t %2X\t %2X\t ",(uint)*(byte *)(*(int *)(pbVar4 + 8) + iVar7),
               (uint)*(byte *)(*(int *)(pbVar4 + 8) + iVar7 + 1));
        iVar3 = *(int *)(pbVar4 + 8);
        for (uVar6 = 0; uVar6 < *(byte *)(iVar3 + iVar7 + 1); uVar6 = uVar6 + 1 & 0xff) {
          printf("%2X",(uint)*(byte *)(iVar3 + uVar6 + iVar7 + 2));
          iVar3 = *(int *)(pbVar4 + 8);
        }
      }
      puts("\r");
      uVar1 = *(uint *)(pbVar4 + 4);
    }
  }
  return 0;
}

