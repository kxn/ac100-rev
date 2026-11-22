// func cw_add_station_dump @ 0056fd04 size=432

undefined4 cw_add_station_dump(int param_1)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Add Station \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Add Station (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar4,(uint)pbVar4[1]);
  if (*pbVar4 < 0x20) {
    printf("\t\t\t***Radio ID: %d \r\n");
    if ((pbVar4[1] == 6) || (pbVar4[1] == 8)) {
      printf("\t\t\tLength: %d \r\n");
      if (*(int *)(pbVar4 + 4) == 0) {
        pcVar2 = "\t\t\t***MAC Address Is NULL \r";
      }
      else {
        printf("\t\t\tMAC Address: ");
        uVar3 = 0;
        while (uVar1 = (uint)pbVar4[1], (int)uVar3 < (int)uVar1) {
          pcVar2 = "%02x \r\n";
          if (uVar3 + 1 != uVar1) {
            pcVar2 = "%02x:";
          }
          printf(pcVar2,(uint)*(byte *)(*(int *)(pbVar4 + 4) + uVar3));
          uVar3 = uVar3 + 1;
        }
        uVar3 = (uint)*(ushort *)(pbVar4 + 8);
        if (uVar3 != (*(ushort *)(param_1 + 0xe) - 2) - uVar1) {
          pcVar2 = "\t\t\t***Vlan Length(%d) Is Wrong \r\n";
          goto LAB_0056fe78;
        }
        if (uVar3 == 0) {
          return 0;
        }
        if (uVar3 < 0x201) {
          if (*(int *)(pbVar4 + 0xc) != 0) {
            printf("\t\t\tVLAN Name: %s \r\n");
            return 0;
          }
          pcVar2 = "\t\t\t***Vlan Name Is NULL \r";
        }
        else {
          pcVar2 = "\t\t\t***Vlan Name Is NULL \r";
        }
      }
      puts(pcVar2);
      return 0xffffffff;
    }
    pcVar2 = "\t\t\tLength(%d) Is Wrong \r\n";
  }
  else {
    pcVar2 = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
  }
LAB_0056fe78:
  printf(pcVar2);
  return 0xffffffff;
}

