// func cw_priv_port_info_dump @ 005b7f5c size=220

undefined4 cw_priv_port_info_dump(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private port info \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private port info(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tphy num: %u \r\n",(uint)*pbVar2);
  if ((*pbVar2 != 0) && (*(int *)(pbVar2 + 4) != 0)) {
    puts("\t\t\t\tphy info: \r");
    for (iVar3 = 0; iVar3 < (int)(uint)*pbVar2; iVar3 = iVar3 + 1) {
      pbVar1 = (byte *)(*(int *)(pbVar2 + 4) + iVar3 * 8);
      printf("\t\t\t\t\tphy: %d,type:%d,speed:%d\n",(uint)*pbVar1,(uint)pbVar1[1],
             *(undefined4 *)(pbVar1 + 4));
    }
  }
  return 0;
}

