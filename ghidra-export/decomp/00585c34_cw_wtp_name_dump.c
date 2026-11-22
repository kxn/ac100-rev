// func cw_wtp_name_dump @ 00585c34 size=244

undefined4 cw_wtp_name_dump(int param_1)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar2 = *(ushort **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) WTP Name \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: WTP Name (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  if ((*(int *)(puVar2 + 2) == 0) || (*puVar2 != *(ushort *)(param_1 + 0xe))) {
    printf("\t\t\t***length(%d) is not fit to name \r\n");
    uVar1 = 0xffffffff;
  }
  else {
    printf("\t\t\tValue: ");
    for (iVar3 = 0; iVar3 < (int)(uint)*puVar2; iVar3 = iVar3 + 1) {
      printf("%02x",(uint)*(byte *)(*(int *)(puVar2 + 2) + iVar3));
    }
    puts("\r");
    printf("\t\t\tWTP Name: %s \r\n",*(undefined4 *)(puVar2 + 2));
    uVar1 = 0;
  }
  return uVar1;
}

