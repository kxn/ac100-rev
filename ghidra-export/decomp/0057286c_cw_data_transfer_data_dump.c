// func cw_data_transfer_data_dump @ 0057286c size=432

undefined4 cw_data_transfer_data_dump(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  
  pbVar4 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) AC Name \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: AC Name (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar4,(uint)pbVar4[1]);
  bVar1 = *pbVar4;
  if (bVar1 == 2) {
    uVar2 = 2;
    pcVar3 = "\t\t\tData Type: Last Transfer Data Block is included (End of File (EOF))(%d) \r\n";
LAB_00572924:
    printf(pcVar3,uVar2);
    if (pbVar4[1] == 1) {
      uVar2 = 1;
      pcVar3 = "\t\t\tData Mode: WTP Crash Data(%d) \r\n";
    }
    else {
      if (pbVar4[1] != 2) {
        pcVar3 = "\t\t\t***Data Mode(%d) Is Wrong \r\n";
        goto LAB_005728f8;
      }
      uVar2 = 2;
      pcVar3 = "\t\t\tData Mode: WTP Memory Dump(%d) \r\n";
    }
    printf(pcVar3,uVar2);
    if (((*(int *)(pbVar4 + 4) == 0) ||
        ((uint)*(ushort *)(pbVar4 + 2) != *(ushort *)(param_1 + 0xe) - 4)) ||
       (*(ushort *)(pbVar4 + 2) == 0)) {
      puts("\t\t\t***Data Or Length Is Wrong \r");
      uVar2 = 0xffffffff;
    }
    else {
      printf("\t\t\tData: ");
      for (iVar5 = 0; iVar5 < (int)(uint)*(ushort *)(pbVar4 + 2); iVar5 = iVar5 + 1) {
        printf("%02x",(uint)*(byte *)(*(int *)(pbVar4 + 4) + iVar5));
      }
      puts("\r");
      uVar2 = 0;
    }
  }
  else {
    if (bVar1 == 5) {
      uVar2 = 5;
      pcVar3 = "\t\t\tData Type: An error occurred(%d) \r\n";
      goto LAB_00572924;
    }
    if (bVar1 == 1) {
      uVar2 = 1;
      pcVar3 = "\t\t\tData Type: Transfer data is included(%d) \r\n";
      goto LAB_00572924;
    }
    pcVar3 = "\t\t\t***Data Type(%d) Is Wrong \r\n";
LAB_005728f8:
    printf(pcVar3);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

