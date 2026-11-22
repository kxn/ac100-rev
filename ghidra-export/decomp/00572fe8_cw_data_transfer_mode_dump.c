// func cw_data_transfer_mode_dump @ 00572fe8 size=180

undefined4 cw_data_transfer_mode_dump(int param_1)

{
  byte bVar1;
  char *__format;
  undefined4 uVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Data Transfer Mode \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Data Transfer Mode (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x \r\n",(uint)*pbVar3);
  bVar1 = *pbVar3;
  if (bVar1 == 1) {
    uVar2 = 1;
    __format = "\t\t\tData Mode: WTP Crash Data(%d) \r\n";
  }
  else {
    if (bVar1 != 2) {
      return 0xffffffff;
    }
    uVar2 = 2;
    __format = "\t\t\tData Mode: WTP Memory Dump(%d) \r\n";
  }
  printf(__format,uVar2);
  return 0;
}

