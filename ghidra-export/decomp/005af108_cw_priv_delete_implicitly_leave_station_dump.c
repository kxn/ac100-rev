// func cw_priv_delete_implicitly_leave_station_dump @ 005af108 size=356

undefined4 cw_priv_delete_implicitly_leave_station_dump(int param_1)

{
  uint uVar1;
  char *pcVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Delete Station \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Delete Station (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar3,(uint)pbVar3[1]);
  if (*pbVar3 < 0x20) {
    printf("\t\t\tRadio ID: %d \r\n");
    if ((pbVar3[1] == 6) || (pbVar3[1] == 8)) {
      printf("\t\t\tLength: %d \r\n");
      if ((*(int *)(pbVar3 + 4) != 0) && (*(ushort *)(param_1 + 0xe) - 2 == (uint)pbVar3[1])) {
        printf("\t\t\tMAC Address: ");
        uVar1 = 0;
        while ((int)uVar1 < (int)(uint)pbVar3[1]) {
          pcVar2 = "%02x \r\n";
          if (uVar1 + 1 != (uint)pbVar3[1]) {
            pcVar2 = "%02x:";
          }
          printf(pcVar2,(uint)*(byte *)(*(int *)(pbVar3 + 4) + uVar1));
          uVar1 = uVar1 + 1;
        }
        return 0;
      }
      puts("\t\t\t***MAC Address is wrong \r");
      return 0xffffffff;
    }
    pcVar2 = "\t\t\t***Length(%d) is wrong \r\n";
  }
  else {
    pcVar2 = "\t\t\t***Radio ID(%d) is wrong \r\n";
  }
  printf(pcVar2);
  return 0xffffffff;
}

