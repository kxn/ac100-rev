// func cw_priv_chnl_scan_report_dump @ 005add4c size=408

undefined4 cw_priv_chnl_scan_report_dump(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap acs report \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap acs report(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tchnl count: %d... \r\n",(uint)*pbVar1);
  if ((*pbVar1 != 0) && (iVar3 = 0, *(int *)(pbVar1 + 4) != 0)) {
    for (; iVar3 < (int)(uint)*pbVar1; iVar3 = iVar3 + 1) {
      iVar2 = iVar3 * 9;
      printf("\t\t\t\tchannle: %u \r\n",(uint)*(byte *)(*(int *)(pbVar1 + 4) + iVar2));
      printf("\t\t\t\t  bss: %u \r\n",(uint)*(byte *)(*(int *)(pbVar1 + 4) + iVar2 + 1));
      printf("\t\t\t\t  load: %u \r\n",(uint)*(byte *)(*(int *)(pbVar1 + 4) + iVar2 + 2));
      printf("\t\t\t\t  reject_flag: %u \r\n",(uint)*(byte *)(*(int *)(pbVar1 + 4) + iVar2 + 3));
      printf("\t\t\t\t  res: %u \r\n",(uint)*(byte *)(*(int *)(pbVar1 + 4) + iVar2 + 4));
      printf("\t\t\t\t  res: %u \r\n",(uint)*(byte *)(*(int *)(pbVar1 + 4) + iVar2 + 5));
      printf("\t\t\t\t  res: %u \r\n",(uint)*(byte *)(*(int *)(pbVar1 + 4) + iVar2 + 6));
      printf("\t\t\t\t  res: %u \r\n",(uint)*(byte *)(*(int *)(pbVar1 + 4) + iVar2 + 7));
    }
  }
  return 0;
}

