// func cw_image_identifier_dump @ 00576e1c size=296

undefined4 cw_image_identifier_dump(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Image Identifier \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Image Identifier (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %08x... \r\n",*puVar2);
  if ((*(ushort *)(puVar2 + 1) - 1 < 0x400) &&
     (*(ushort *)(param_1 + 0xe) - 4 == (uint)*(ushort *)(puVar2 + 1))) {
    if (puVar2[2] == 0) {
      puts("\t\t\t***Data is NULL \r");
      uVar1 = 0xffffffff;
    }
    else {
      printf("\t\t\tData Value: ");
      for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(puVar2 + 1); iVar3 = iVar3 + 1) {
        printf("%02x",(uint)*(byte *)(puVar2[2] + iVar3));
      }
      puts("\r");
      printf("\t\t\tData: %s \r\n",puVar2[2]);
      uVar1 = 0;
    }
  }
  else {
    printf("\t\t\t***Data Length(%d) is wrong \r\n");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

