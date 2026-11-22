// func cw_image_information_dump @ 0057733c size=216

undefined4 cw_image_information_dump(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Image Identifier \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Image Identifier (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar2 = 0;
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %08x... \r\n",*puVar3);
  printf("\t\t\tFile Size: %d \r\n",*puVar3);
  printf("\t\t\tHash: ");
  puVar1 = puVar3;
  do {
    iVar2 = iVar2 + 1;
    printf("%02x",(uint)*(byte *)(puVar1 + 1));
    puVar1 = (undefined4 *)((int)puVar3 + iVar2);
  } while (iVar2 != 0x10);
  puts("\r");
  return 0;
}

