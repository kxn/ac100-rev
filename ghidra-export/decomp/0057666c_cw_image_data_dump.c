// func cw_image_data_dump @ 0057666c size=400

undefined4 cw_image_data_dump(int param_1)

{
  char *__format;
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Image Data \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Image Data (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x... \r\n",(uint)*pbVar2);
  uVar1 = (uint)*pbVar2;
  if ((uVar1 - 1 < 2) || (uVar1 == 5)) {
    printf("\t\t\tType: %d \r\n");
    uVar1 = (uint)*(ushort *)(pbVar2 + 2);
    if (*pbVar2 == 5) {
      if (uVar1 == 0) goto LAB_00576710;
    }
    else if (uVar1 != 0) {
LAB_00576710:
      if ((uVar1 < 0x401) && (*(ushort *)(param_1 + 0xe) - 1 == uVar1)) {
        if (uVar1 == 0) {
          if (*(int *)(pbVar2 + 4) == 0) {
            return 0;
          }
        }
        else if (*(int *)(pbVar2 + 4) != 0) {
          printf("\t\t\tData: ");
          for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(pbVar2 + 2); iVar3 = iVar3 + 1) {
            printf("%02x",(uint)*(byte *)(*(int *)(pbVar2 + 4) + iVar3));
          }
          puts("\r");
          return 0;
        }
        puts("\t\t\t***Length is not fit to data \r");
        return 0xffffffff;
      }
      __format = "\t\t\t***Length(%d) is wrong \r\n";
      goto LAB_005767d0;
    }
    printf("\t\t\t***Type(%d) is not fit to length(%d) \r\n");
  }
  else {
    __format = "\t\t\t***type(%d) is wrong \r\n";
LAB_005767d0:
    printf(__format,uVar1);
  }
  return 0xffffffff;
}

