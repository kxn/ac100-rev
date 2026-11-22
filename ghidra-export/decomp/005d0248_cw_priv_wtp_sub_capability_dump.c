// func cw_priv_wtp_sub_capability_dump @ 005d0248 size=344

undefined4 cw_priv_wtp_sub_capability_dump(int param_1)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  puVar3 = *(ushort **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private wtp sub capability \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private wtp sub capability (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %04x...\r\n",(uint)*puVar3);
  printf("\t\t\t\tcap num: %u \r\n",(uint)*puVar3);
  if ((*puVar3 != 0) && (*(int *)(puVar3 + 2) != 0)) {
    puts("\t\t\t\tsub cap list: \r");
    uVar1 = *puVar3;
    for (iVar5 = 0; iVar5 < (int)(uint)uVar1; iVar5 = iVar5 + 1) {
      iVar6 = iVar5 * 8;
      printf("\t\t\t\t\t%d: ",(uint)*(ushort *)(*(int *)(puVar3 + 2) + iVar6));
      iVar4 = 4 - (uint)*(ushort *)(*(int *)(puVar3 + 2) + iVar6 + 2);
      if (iVar4 != 4) {
        iVar2 = *(int *)(puVar3 + 2);
        while( true ) {
          iVar2 = iVar2 + iVar6 + iVar4;
          iVar4 = iVar4 + 1;
          printf("%02x",(uint)*(byte *)(iVar2 + 4));
          if (iVar4 == 4) break;
          iVar2 = *(int *)(puVar3 + 2);
        }
      }
      putchar(10);
      uVar1 = *puVar3;
    }
  }
  return 0;
}

