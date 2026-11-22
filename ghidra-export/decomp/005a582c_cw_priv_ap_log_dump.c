// func cw_priv_ap_log_dump @ 005a582c size=272

undefined4 cw_priv_ap_log_dump(int param_1)

{
  undefined1 *puVar1;
  byte *pbVar2;
  ushort *puVar3;
  int iVar4;
  
  puVar3 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap log \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap log (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x...\r\n",(uint)*puVar3);
  printf("\t\t\t\tlog count: %u \r\n",(uint)*puVar3);
  if ((*puVar3 != 0) && (*(int *)(puVar3 + 2) != 0)) {
    puts("\t\t\t\tlog info: \r");
    for (iVar4 = 0; iVar4 < (int)(uint)*puVar3; iVar4 = iVar4 + 1) {
      pbVar2 = (byte *)(*(int *)(puVar3 + 2) + iVar4 * 8);
      puVar1 = &DAT_00688af8;
      if (*(ushort *)(pbVar2 + 2) != 0) {
        puVar1 = *(undefined1 **)(pbVar2 + 4);
        if (*(undefined1 **)(pbVar2 + 4) == (undefined1 *)0x0) {
          puVar1 = &DAT_00688af8;
        }
      }
      printf("\t\t\t\t\ttype: %d,level:%d,len:%d,content:%s\n",(uint)*pbVar2,(uint)pbVar2[1],
             (uint)*(ushort *)(pbVar2 + 2),puVar1);
    }
  }
  return 0;
}

