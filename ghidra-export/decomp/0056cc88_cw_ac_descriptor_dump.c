// func cw_ac_descriptor_dump @ 0056cc88 size=940

undefined4 cw_ac_descriptor_dump(int param_1)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  
  puVar6 = *(ushort **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) AC Descriptor \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: AC Descriptor (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %04x%04x%04x%04x...\r\n",(uint)*puVar6,(uint)puVar6[1],(uint)puVar6[2],
         (uint)puVar6[3]);
  printf("\t\t\tStations: %d \r\n",(uint)*puVar6);
  printf("\t\t\tLimit Stations: %d\r\n",(uint)puVar6[1]);
  printf("\t\t\tActive WTPs: %d\r\n",(uint)puVar6[2]);
  printf("\t\t\tMax WTPs: %d \r\n",(uint)puVar6[3]);
  if ((*(byte *)(puVar6 + 4) & 6) == *(byte *)(puVar6 + 4)) {
    puts("\t\t\tSecurity Flags\r");
    puts("\t\t\t\t0000 0..0 = Reserved: Not set\r");
    iVar2 = (int)((uint)*(byte *)(puVar6 + 4) << 0x1d) >> 0x1f;
    printf("\t\t\t\t.... .%d.. = AC supports the pre-shared: %s \r\n",-iVar2,
           *(undefined4 *)(&UNK_006d6be0 + iVar2 * -4));
    iVar2 = (int)((uint)*(byte *)(puVar6 + 4) << 0x1e) >> 0x1f;
    printf("\t\t\t\t.... ..%d. = AC supports X.509 Certificate: %s \r\n",-iVar2,
           *(undefined4 *)(&UNK_006d6be0 + iVar2 * -4));
    if (*(char *)((int)puVar6 + 9) == '\x01') {
      uVar4 = 1;
      pcVar3 = "\t\t\tR-MAC Field: Supported (%d)\r\n";
    }
    else {
      if (*(char *)((int)puVar6 + 9) != '\x02') {
        pcVar3 = "\t\t\t***R-MAC Field: Supported(%d) Is Wrong \r\n";
        goto LAB_0056cfcc;
      }
      uVar4 = 2;
      pcVar3 = "\t\t\tR-MAC Field: Not Supported (%d)\r\n";
    }
    printf(pcVar3,uVar4);
    if (*(char *)(puVar6 + 5) == '\0') {
      puts("\t\t\tReserved: 0 \r");
      if ((*(byte *)((int)puVar6 + 0xb) & 6) == *(byte *)((int)puVar6 + 0xb)) {
        puts("\t\t\tDTLS Policy Flags \r");
        puts("\t\t\t\t0000 0..0 = Reserved: Not set\r");
        iVar2 = (int)((uint)*(byte *)((int)puVar6 + 0xb) << 0x1d) >> 0x1f;
        printf("\t\t\t\t.... .%d.. = DTLS-Enabled Data Channel Supported: %s \r\n",-iVar2,
               *(undefined4 *)(&UNK_006d6be0 + iVar2 * -4));
        iVar2 = (int)((uint)*(byte *)((int)puVar6 + 0xb) << 0x1e) >> 0x1f;
        printf("\t\t\t\t.... ..%d. = Clear Text Data Channel Supported: %s \r\n",-iVar2,
               *(undefined4 *)(&UNK_006d6be0 + iVar2 * -4));
        iVar2 = FUN_004081b0(puVar6 + 6);
        if (iVar2 == 0) {
          return 0;
        }
        uVar1 = *(ushort *)(iVar2 + 0x10);
        while (uVar5 = (uint)uVar1, uVar5 - 4 < 2) {
          printf("\t\t\tAC Information: (t=%d,l=%d) %s \r\n",uVar5,(uint)*(ushort *)(iVar2 + 0x12),
                 *(undefined4 *)(&UNK_006d6be8 + uVar5 * 4));
          printf("\t\t\t\tAC Information Vendor: Unknown (%d)\r\n",*(undefined4 *)(iVar2 + 0xc));
          printf("\t\t\t\tAC Information Type: %s (%d) \r\n",
                 *(undefined4 *)(&UNK_006d6be8 + (uint)*(ushort *)(iVar2 + 0x10) * 4));
          if (*(short *)(iVar2 + 0x12) == 0) {
            pcVar3 = "\t\t\t***AC Descriptor SubElement Length(%d) Is Wrong Or NULL";
            goto LAB_0056cfcc;
          }
          if (*(int *)(iVar2 + 0x14) == 0) {
            pcVar3 = "\t\t\t***AC Descriptor SubElement Length(%d) Is Wrong Or NULL";
            goto LAB_0056cfcc;
          }
          printf("\t\t\t\tAC Information Length: %d \r\n");
          printf("\t\t\t\tAC Information Value: ");
          uVar1 = *(ushort *)(iVar2 + 0x12);
          for (iVar7 = 0; iVar7 < (int)(uint)uVar1; iVar7 = iVar7 + 1) {
            printf("%02x",(uint)*(byte *)(*(int *)(iVar2 + 0x14) + iVar7));
            uVar1 = *(ushort *)(iVar2 + 0x12);
          }
          puts("\r");
          printf("\t\t\t\t%s: ",*(undefined4 *)(&UNK_006d6be8 + (uint)*(ushort *)(iVar2 + 0x10) * 4)
                );
          uVar1 = *(ushort *)(iVar2 + 0x12);
          for (iVar7 = 0; iVar7 < (int)(uint)uVar1; iVar7 = iVar7 + 1) {
            putchar((uint)*(byte *)(*(int *)(iVar2 + 0x14) + iVar7));
            uVar1 = *(ushort *)(iVar2 + 0x12);
          }
          puts("\r");
          iVar2 = FUN_00408680(iVar2);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = *(ushort *)(iVar2 + 0x10);
        }
        pcVar3 = "\t\t\t***AC Descriptor SubElement Type(%d) Is Wrong";
      }
      else {
        pcVar3 = "\t\t\t***DTLS Policy Flags(%02x) Is Wrong \r\n";
      }
    }
    else {
      pcVar3 = "\t\t\tReserved(%d) Is Wrong \r\n";
    }
  }
  else {
    pcVar3 = "\t\t\t***Security Flags(%02x) Is Wrong \r\n";
  }
LAB_0056cfcc:
  printf(pcVar3);
  return 0xffffffff;
}

