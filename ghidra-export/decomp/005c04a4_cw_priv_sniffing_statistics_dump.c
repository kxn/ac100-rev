// func cw_priv_sniffing_statistics_dump @ 005c04a4 size=432

undefined4 cw_priv_sniffing_statistics_dump(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = *(int **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private sniffing statistics request \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private sniffing statistics request(%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x... \r\n",*piVar2);
  printf("\t\t\t\tstation cnt: %u \r\n",*piVar2);
  if ((0 < *piVar2) && (iVar4 = 0, piVar2[1] != 0)) {
    for (; iVar4 < *piVar2; iVar4 = iVar4 + 1) {
      iVar3 = iVar4 * 0x14;
      printf("\t\t\t\t  radio id: %u \r\n",(uint)*(byte *)(piVar2[1] + iVar3));
      printf("\t\t\t\t  wlan id: %u \r\n",(uint)*(byte *)(piVar2[1] + iVar3 + 1));
      iVar1 = piVar2[1] + iVar3;
      printf("\t\t\t\t  mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)*(byte *)(iVar1 + 2),
             (uint)*(byte *)(iVar1 + 3),(uint)*(byte *)(iVar1 + 4),(uint)*(byte *)(iVar1 + 5),
             (uint)*(byte *)(iVar1 + 6),(uint)*(byte *)(iVar1 + 7));
      printf("\t\t\t\t  type: %u \r\n",(uint)*(byte *)(piVar2[1] + iVar3 + 8));
      printf("\t\t\t\t  start_time: %u \r\n",*(undefined4 *)(piVar2[1] + iVar3 + 0xc));
      printf("\t\t\t\t  power: %d \r\n",(int)*(char *)(piVar2[1] + iVar3 + 0x10));
    }
  }
  puts("\r");
  return 0;
}

