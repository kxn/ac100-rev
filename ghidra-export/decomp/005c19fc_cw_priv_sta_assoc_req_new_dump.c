// func cw_priv_sta_assoc_req_new_dump @ 005c19fc size=908

undefined4 cw_priv_sta_assoc_req_new_dump(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  char *pcVar6;
  byte *pbVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  
  pbVar7 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private station association request new\r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private station association request new(%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x.. \r\n",(uint)*pbVar7,(uint)pbVar7[1]);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar7);
  printf("\t\t\t\twlan id: %d \r\n",(uint)pbVar7[1]);
  printf("\t\t\t\tclient mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)pbVar7[2],(uint)pbVar7[3],
         (uint)pbVar7[4],(uint)pbVar7[5],(uint)pbVar7[6],(uint)pbVar7[7]);
  printf("\t\t\t\trssi: %d \r\n",*(undefined4 *)(pbVar7 + 8));
  if (pbVar7[0xc] == 0) {
    puVar4 = &DAT_00691368;
  }
  else {
    puVar4 = &DAT_006a2b04;
  }
  printf("\t\t\t\treassoc: %s \r\n",puVar4);
  iVar2 = FUN_004081b0(pbVar7 + 0x14);
  if (iVar2 != 0) {
    uVar1 = *(ushort *)(iVar2 + 0xc);
    while( true ) {
      uVar5 = (uint)uVar1;
      pcVar6 = "Unknown";
      if (uVar5 < 2) {
        pcVar6 = (&PTR_s_Backfill_006ef890)[uVar5];
      }
      printf("\t\t\tSub Element Data: (t=%d,l=%d) %s \r\n",uVar5,(uint)*(ushort *)(iVar2 + 0xe),
             pcVar6);
      pcVar6 = "Unknown";
      if (*(ushort *)(iVar2 + 0xc) < 2) {
        pcVar6 = (&PTR_s_Backfill_006ef890)[*(ushort *)(iVar2 + 0xc)];
      }
      printf("\t\t\t\tSub Element Type: %s (%d) \r\n",pcVar6);
      printf("\t\t\t\tSub Element Length: %d \r\n",(uint)*(ushort *)(iVar2 + 0xe));
      printf("\t\t\t\tSub Element Value: ");
      piVar8 = *(int **)(iVar2 + 0x10);
      if (*(short *)(iVar2 + 0xc) == 0) {
        if ((*piVar8 != 0) && ((byte *)piVar8[1] != (byte *)0x0)) {
          printf("\n\t\t\t\t\tBackfill:    %02x..(%d)\n",(uint)*(byte *)piVar8[1]);
        }
      }
      else if (*(short *)(iVar2 + 0xc) == 1) {
        if (*piVar8 != 0) {
          printf("\n\t\t\t\t\tMLD mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",
                 (uint)*(byte *)(piVar8 + 1),(uint)*(byte *)((int)piVar8 + 5),
                 (uint)*(byte *)((int)piVar8 + 6),(uint)*(byte *)((int)piVar8 + 7),
                 (uint)*(byte *)(piVar8 + 2),(uint)*(byte *)((int)piVar8 + 9));
          printf("\t\t\t\t\tlink num: %d \r\n",(uint)*(byte *)((int)piVar8 + 10));
          if ((*(char *)((int)piVar8 + 10) != '\0') && (iVar10 = 0, piVar8[3] != 0)) {
            for (; iVar10 < (int)(uint)*(byte *)((int)piVar8 + 10); iVar10 = iVar10 + 1) {
              iVar9 = iVar10 * 0xc;
              printf("\t\t\t\t\tradio id: %d \r\n",(uint)*(byte *)(piVar8[3] + iVar9));
              printf("\t\t\t\t\twlan id: %d \r\n",(uint)*(byte *)(piVar8[3] + iVar9 + 1));
              iVar3 = piVar8[3] + iVar9;
              printf("\t\t\t\t\tpeer mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",
                     (uint)*(byte *)(iVar3 + 2),(uint)*(byte *)(iVar3 + 3),
                     (uint)*(byte *)(iVar3 + 4),(uint)*(byte *)(iVar3 + 5),
                     (uint)*(byte *)(iVar3 + 6),(uint)*(byte *)(iVar3 + 7));
              printf("\t\t\t\t\trssi: %d \r\n",*(undefined4 *)(piVar8[3] + iVar9 + 8));
            }
          }
        }
      }
      else {
        if (piVar8 == (int *)0x0) {
          puts("\t\t\t\tNULL \r");
          return 0;
        }
        iVar10 = 0;
        while( true ) {
          uVar5 = (uint)*(ushort *)(iVar2 + 0xe);
          if (0x32 < uVar5) {
            uVar5 = 0x32;
          }
          if ((int)uVar5 <= iVar10) break;
          pbVar7 = (byte *)(*(int *)(iVar2 + 0x10) + iVar10);
          iVar10 = iVar10 + 1;
          printf("%02x",(uint)*pbVar7);
        }
        puts("\r");
      }
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      uVar1 = *(ushort *)(iVar2 + 0xc);
    }
    return 0;
  }
  return 0;
}

