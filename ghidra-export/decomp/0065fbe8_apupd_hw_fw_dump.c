// func apupd_hw_fw_dump @ 0065fbe8 size=1

void apupd_hw_fw_dump(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte abStack_50 [20];
  byte abStack_3c [20];
  
  puts("===================hw-fw dump===============\r");
  if (DAT_007cc7c0 != 0) {
    printf("hw total count is [%d]\r\n",DAT_007cc7c4);
    for (iVar1 = FUN_004081b0(&apupd_report_upgrade_info); iVar1 != 0; iVar1 = FUN_00408680(iVar1))
    {
      abStack_3c[0] = 0;
      abStack_3c[1] = 0;
      abStack_3c[2] = 0;
      abStack_3c[3] = 0;
      abStack_3c[4] = 0;
      abStack_3c[5] = 0;
      abStack_3c[6] = 0;
      abStack_3c[7] = 0;
      abStack_3c[8] = 0;
      abStack_3c[9] = 0;
      abStack_3c[10] = 0;
      abStack_3c[0xb] = 0;
      iVar3 = 0;
      abStack_3c[0xc] = 0;
      abStack_3c[0xd] = 0;
      abStack_3c[0xe] = 0;
      abStack_3c[0xf] = 0;
      memcpy(abStack_3c,(void *)(iVar1 + 0xc),0x10);
      abStack_3c[0x10] = 0;
      printf("Hw:");
      pbVar2 = abStack_3c;
      do {
        iVar3 = iVar3 + 1;
        printf("%02X",(uint)*pbVar2);
        pbVar2 = abStack_3c + iVar3;
      } while (iVar3 != 0x10);
      puts("\r");
      if (*(int *)(iVar1 + 0x1c) != 0) {
        for (iVar3 = FUN_004081b0(); iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
          abStack_50[0] = 0;
          abStack_50[1] = 0;
          abStack_50[2] = 0;
          abStack_50[3] = 0;
          abStack_50[4] = 0;
          abStack_50[5] = 0;
          abStack_50[6] = 0;
          abStack_50[7] = 0;
          abStack_50[8] = 0;
          abStack_50[9] = 0;
          abStack_50[10] = 0;
          abStack_50[0xb] = 0;
          abStack_50[0xc] = 0;
          abStack_50[0xd] = 0;
          abStack_50[0xe] = 0;
          abStack_50[0xf] = 0;
          iVar4 = 0;
          abStack_50[0x10] = 0;
          memcpy(abStack_50,(void *)(iVar3 + 0xc),0x10);
          printf("\tFw:");
          do {
            pbVar2 = abStack_50 + iVar4;
            iVar4 = iVar4 + 1;
            printf("%02X",(uint)*pbVar2);
          } while (iVar4 != 0x10);
          printf(" ref[%d]\r\n",*(undefined4 *)(iVar3 + 0x1c));
        }
      }
    }
  }
  return;
}

