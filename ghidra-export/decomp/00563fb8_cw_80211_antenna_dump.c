// func cw_80211_antenna_dump @ 00563fb8 size=528

undefined4 cw_80211_antenna_dump(int param_1)

{
  char *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  
  pbVar4 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) IEEE 802.11 Antenna \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: IEEE 802.11 Antenna (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %02x%02x%02x... \r\n",(uint)*pbVar4,(uint)pbVar4[1],(uint)pbVar4[2]);
  uVar2 = (uint)*pbVar4;
  if (0x1f < uVar2) {
    pcVar1 = "\t\t\t***Radio ID(%d) Is Wrong \r\n";
    goto LAB_0056409c;
  }
  printf("\t\t\tRadio ID: %d \r\n");
  uVar2 = (uint)pbVar4[1];
  if (uVar2 == 0) {
    uVar3 = 0;
    pcVar1 = "\t\t\tDiversity: Disable(%d) \r\n";
  }
  else {
    if (uVar2 != 1) {
      pcVar1 = "\t\t\t***Diversity(%d) Is Wrong \r\n";
      goto LAB_0056409c;
    }
    uVar3 = 1;
    pcVar1 = "\t\t\tDiversity: Enable(%d) \r\n";
  }
  printf(pcVar1,uVar3);
  uVar2 = (uint)pbVar4[2];
  if (uVar2 == 2) {
    uVar3 = 2;
    pcVar1 = "\t\t\tCombiner: Sectorized (RIGHT)(%d) \r\n";
  }
  else if (uVar2 < 3) {
    if (uVar2 != 1) {
LAB_00564084:
      pcVar1 = "\t\t\t***Combiner(%d) Is Wrong \r\n";
      goto LAB_0056409c;
    }
    uVar3 = 1;
    pcVar1 = "\t\t\tCombiner: Sectorized (Left)(%d) \r\n";
  }
  else if (uVar2 == 3) {
    uVar3 = 3;
    pcVar1 = "\t\t\tCombiner: Omni(%d) \r\n";
  }
  else {
    if (uVar2 != 4) goto LAB_00564084;
    uVar3 = 4;
    pcVar1 = "\t\t\tCombiner: MIMO(%d) \r\n";
  }
  printf(pcVar1,uVar3);
  uVar2 = (uint)pbVar4[3];
  if ((*(ushort *)(param_1 + 0xe) - 4 == uVar2) && (*(ushort *)(param_1 + 0xe) != 4)) {
    printf("\t\t\tAntenna Count: %d \r\n");
    if (*(int *)(pbVar4 + 4) != 0) {
      printf("\t\t\tAntenna Selection: ");
      for (iVar5 = 0; iVar5 < (int)(uint)pbVar4[3]; iVar5 = iVar5 + 1) {
        printf("%02x",(uint)*(byte *)(*(int *)(pbVar4 + 4) + iVar5));
      }
      puts("\r");
      return 0;
    }
    puts("\t\t\t***Antenna Selection Is NULL \r");
    return 0xffffffff;
  }
  pcVar1 = "\t\t\t***Antenna Count(%d) Is Wrong \r\n";
LAB_0056409c:
  printf(pcVar1,uVar2);
  return 0xffffffff;
}

