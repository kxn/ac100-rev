// func cw_priv_chnl_scan_dump @ 005ad500 size=316

void cw_priv_chnl_scan_dump(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private chnl scan \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private time sync (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tscan_time: %dms\r\n",(uint)*pbVar3);
  printf("\t\t\t\tradio_num: %d\r\n",(uint)pbVar3[1]);
  puts("\t\t\t\tscan_chnl_list: \r");
  puts("\t\t\t\t\r");
  bVar1 = pbVar3[1];
  for (iVar4 = 0; iVar4 < (int)(uint)bVar1; iVar4 = iVar4 + 1) {
    iVar2 = iVar4 * 8;
    puts("\t\t\t\t\r");
    printf("\t\t\t\tradio: %d\r\n",(uint)*(byte *)(*(int *)(pbVar3 + 4) + iVar2));
    printf("\t\t\t\tchn_lst_len: %d\r\n",(uint)*(byte *)(*(int *)(pbVar3 + 4) + iVar2 + 1));
    printf("\t\t\t\tchn_lst_str: %s\r\n",*(undefined4 *)(*(int *)(pbVar3 + 4) + iVar2 + 4));
    bVar1 = pbVar3[1];
  }
  return;
}

