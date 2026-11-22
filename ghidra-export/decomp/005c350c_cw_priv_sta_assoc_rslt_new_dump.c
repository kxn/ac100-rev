// func cw_priv_sta_assoc_rslt_new_dump @ 005c350c size=808

undefined4 cw_priv_sta_assoc_rslt_new_dump(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  char *pcVar6;
  byte *pbVar7;
  
  pbVar7 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private station association result new\r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private station association result new(%d) \r\n",
         (uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x.. \r\n",(uint)*pbVar7,(uint)pbVar7[1]);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar7);
  printf("\t\t\t\twlan id: %d \r\n",(uint)pbVar7[1]);
  printf("\t\t\t\tclient mac: %02x:%02x:%02x:%02x:%02x:%02x \r\n",(uint)pbVar7[2],(uint)pbVar7[3],
         (uint)pbVar7[4],(uint)pbVar7[5],(uint)pbVar7[6],(uint)pbVar7[7]);
  printf("\t\t\t\trslt: %d \r\n",*(undefined4 *)(pbVar7 + 8));
  if (pbVar7[0xc] == 0) {
    puVar4 = &DAT_00691368;
  }
  else {
    puVar4 = &DAT_006a2b04;
  }
  printf("\t\t\t\treassoc: %s \r\n",puVar4);
  iVar2 = FUN_004081b0(pbVar7 + 0x14);
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + 0x10);
    while( true ) {
      uVar5 = (uint)*(ushort *)(iVar2 + 0xc);
      if ((iVar3 == 0) && (uVar5 != 2)) {
        puts("\t\t\t***Subelement Data is NULL \r");
        return 0xffffffff;
      }
      pcVar6 = "Unknown";
      if (uVar5 < 3) {
        pcVar6 = (&PTR_DAT_006efb60)[uVar5];
      }
      printf("\t\t\tSub Element Data: (t=%d,l=%d) %s \r\n",uVar5,(uint)*(ushort *)(iVar2 + 0xe),
             pcVar6);
      pcVar6 = "Unknown";
      if (*(ushort *)(iVar2 + 0xc) < 3) {
        pcVar6 = (&PTR_DAT_006efb60)[*(ushort *)(iVar2 + 0xc)];
      }
      printf("\t\t\t\tSub Element Type: %s (%d) \r\n",pcVar6);
      printf("\t\t\t\tSub Element Length: %d \r\n",(uint)*(ushort *)(iVar2 + 0xe));
      printf("\t\t\t\tSub Element Value: ");
      sVar1 = *(short *)(iVar2 + 0xc);
      if (sVar1 == 1) {
        if ((**(int **)(iVar2 + 0x10) != 0) &&
           (pbVar7 = (byte *)(*(int **)(iVar2 + 0x10))[1], pbVar7 != (byte *)0x0)) {
          printf("\n\t\t\t\t\tBackfill:    %02x..(%d)\n",(uint)*pbVar7);
        }
      }
      else if (sVar1 == 0) {
        printf("\n\t\t\t\t\tVlan id:    %d\n",(uint)**(ushort **)(iVar2 + 0x10));
      }
      else {
        if (sVar1 == 2) {
          if (((*(short *)(iVar2 + 0xe) == 0) || (capwap_warning_switch == 0)) ||
             (iVar3 = is_target_debug_ap(), iVar3 == 0)) {
            pcVar6 = "\n\t\t\t\t\tMLO_info: NULL.\r";
          }
          else {
            printf("[CW_WARNING]%32s():%4d Uncorrect sub ele len(%d)\n",
                   "cw_priv_sta_assoc_rslt_new_dump",0x252,(uint)*(ushort *)(iVar2 + 0xe));
            pcVar6 = "\n\t\t\t\t\tMLO_info: NULL.\r";
          }
        }
        else {
          if (*(int *)(iVar2 + 0x10) == 0) {
            puts("\t\t\t\tNULL \r");
            return 0;
          }
          iVar3 = 0;
          while( true ) {
            uVar5 = (uint)*(ushort *)(iVar2 + 0xe);
            if (0x32 < uVar5) {
              uVar5 = 0x32;
            }
            if ((int)uVar5 <= iVar3) break;
            pbVar7 = (byte *)(*(int *)(iVar2 + 0x10) + iVar3);
            iVar3 = iVar3 + 1;
            printf("%02x",(uint)*pbVar7);
          }
          pcVar6 = "\r";
        }
        puts(pcVar6);
      }
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      iVar3 = *(int *)(iVar2 + 0x10);
    }
  }
  return 0;
}

