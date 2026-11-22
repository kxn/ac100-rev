// func cw_priv_mac_filter_dump @ 005b5468 size=572

undefined4 cw_priv_mac_filter_dump(int param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  char *__format;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  
  puVar5 = *(uint **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private mac filter \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private mac filter (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x%02x...\r\n",*puVar5,(uint)*(byte *)(puVar5 + 1));
  printf("\t\t\t\tvlan id: %u\r\n ",(uint)*(ushort *)((int)puVar5 + 6));
  printf("\t\t\t\tmac num: %u\r\n ",*puVar5);
  printf("\t\t\t\toperation: %u",(uint)*(byte *)((int)puVar5 + 5));
  bVar1 = *(byte *)((int)puVar5 + 5);
  if (bVar1 == 2) {
    __format = "(delete mac filter)";
    goto LAB_005b553c;
  }
  if (bVar1 < 3) {
    if (bVar1 == 1) {
      __format = "(add mac filter)";
      goto LAB_005b553c;
    }
  }
  else {
    if (bVar1 == 3) {
      __format = "(reset mac filter)";
      goto LAB_005b553c;
    }
    if (bVar1 == 4) {
      __format = "(no mac filter)";
      goto LAB_005b553c;
    }
  }
  __format = "(unknown operation)";
LAB_005b553c:
  printf(__format);
  puts("\r");
  if (*puVar5 != 0) {
    uVar6 = 0;
    printf("\t\t\t\tmac list: ");
LAB_005b55b8:
    uVar3 = *puVar5;
LAB_005b55bc:
    bVar2 = 6 < uVar3;
    if (bVar2) {
      uVar3 = 6;
    }
    if (uVar6 < uVar3) {
      iVar4 = 0;
      do {
        bVar1 = *(byte *)(puVar5 + 1);
        while( true ) {
          if ((int)(uint)(bVar1 >> 3) <= iVar4) {
            uVar3 = *puVar5;
            if (6 < uVar3) {
              uVar3 = 6;
            }
            if (uVar6 < uVar3 - 1) {
              uVar6 = uVar6 + 1;
              putchar(0x2f);
              uVar3 = *puVar5;
              goto LAB_005b55bc;
            }
            uVar6 = uVar6 + 1;
            goto LAB_005b55b8;
          }
          printf("%02x",(uint)*(byte *)(puVar5[2] + iVar4 + (bVar1 >> 3) * uVar6));
          if ((int)((*(byte *)(puVar5 + 1) >> 3) - 1) <= iVar4) break;
          iVar4 = iVar4 + 1;
          putchar(0x2d);
          bVar1 = *(byte *)(puVar5 + 1);
        }
        iVar4 = iVar4 + 1;
      } while( true );
    }
    if (bVar2) {
      printf("...");
    }
    puts("\r");
  }
  return 0;
}

