// func mesh_db_discover_entry_dump_all @ 004b815c size=1

void mesh_db_discover_entry_dump_all(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  char *apcStack_60 [5];
  undefined *puStack_4c;
  char *pcStack_48;
  char *pcStack_44;
  char *apcStack_40 [6];
  
  puStack_4c = &DAT_006a2bdc;
  pcStack_48 = "Discovering";
  pcStack_44 = "Discover Finished";
  memcpy(apcStack_60 + 8,&PTR_DAT_006a34a0,0x14);
  apcStack_60[0] = "AP";
  apcStack_60[1] = "Router";
  apcStack_60[2] = "Unknown";
  apcStack_60[3] = "Fit";
  apcStack_60[4] = "Fat";
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  printf("Discover state:\t%s\n",apcStack_60[DAT_00767f58 + 5]);
  puts("****************Dev list*****************");
  iVar3 = FUN_004081b0(&DAT_00767f5c);
  if (iVar3 != 0) {
    bVar1 = *(byte *)(iVar3 + 0x55);
    while( true ) {
      iVar12 = iVar3 + 0x12;
      pcVar8 = "Unknown";
      uVar13 = (uint)*(byte *)(iVar3 + 0x11);
      uVar11 = (uint)*(byte *)(iVar3 + 0x53);
      uVar10 = (uint)*(byte *)(iVar3 + 0x54);
      if (bVar1 < 2) {
        pcVar8 = apcStack_60[bVar1];
      }
      pcVar4 = "Unknown";
      if (*(byte *)(iVar3 + 0x56) < 3) {
        pcVar4 = apcStack_60[*(byte *)(iVar3 + 0x56) + 2];
      }
      pcVar5 = apcStack_60[*(int *)(iVar3 + 100) + 8];
      printf("Dev mac:\t[%02x:%02x:%02x:%02x:%02x:%02x] \tModel:%s %d.%d \tproduct type:%s(%s)\tState:%s\n"
             ,(uint)*(byte *)(iVar3 + 0xc),(uint)*(byte *)(iVar3 + 0xd),(uint)*(byte *)(iVar3 + 0xe)
             ,(uint)*(byte *)(iVar3 + 0xf),(uint)*(byte *)(iVar3 + 0x10),uVar13,iVar12,uVar11,uVar10
             ,pcVar8,pcVar4,pcVar5);
      iVar6 = FUN_004081b0(iVar3 + 0x58);
      if (iVar6 != 0) {
        cVar2 = *(char *)(iVar6 + 0x10);
        while( true ) {
          pcVar9 = "Wireless";
          if (cVar2 != '\x02') {
            pcVar9 = "Wired";
          }
          pcVar7 = "true";
          if (*(char *)(iVar6 + 0x18) == '\0') {
            pcVar7 = "false";
          }
          printf("\tCap id:%d Pap id:%d Link info:(%s, %d) Selected:%s\n",
                 (uint)*(ushort *)(iVar6 + 0xc),(uint)*(ushort *)(iVar6 + 0xe),pcVar9,
                 *(undefined4 *)(iVar6 + 0x14),pcVar7,uVar13,iVar12,uVar11,uVar10,pcVar8,pcVar4,
                 pcVar5);
          iVar6 = FUN_00408680(iVar6);
          if (iVar6 == 0) break;
          cVar2 = *(char *)(iVar6 + 0x10);
        }
      }
      iVar3 = FUN_00408680(iVar3);
      if (iVar3 == 0) break;
      bVar1 = *(byte *)(iVar3 + 0x55);
    }
  }
  puts("*****************************************");
  uac_mutex_give(DAT_00767eb4);
  return;
}

