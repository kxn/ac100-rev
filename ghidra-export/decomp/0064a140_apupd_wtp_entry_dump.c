// func apupd_wtp_entry_dump @ 0064a140 size=540

void apupd_wtp_entry_dump(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_60 [68];
  
  puts("=========>wtp dump:");
  memset(auStack_60,0,0x40);
  FUN_00408190(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
               *(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
               *(undefined4 *)(param_1 + 0x28),auStack_60,0x40,"---");
  printf("ip: %s\n",auStack_60);
  printf("port: %d\n",(uint)*(ushort *)(param_1 + 0x2c));
  printf("mac: %02x:%02x:%02x:%02x:%02x:%02x\n",(uint)*(byte *)(param_1 + 0x2e),
         (uint)*(byte *)(param_1 + 0x2f),(uint)*(byte *)(param_1 + 0x30),
         (uint)*(byte *)(param_1 + 0x31),(uint)*(byte *)(param_1 + 0x32),
         (uint)*(byte *)(param_1 + 0x33));
  printf("model id: %d\n",*(undefined4 *)(param_1 + 0x34));
  uVar1 = *(uint *)(param_1 + 0x40);
  printf("soft ver: %d.%d.%d Build %02d%02d%02d Rel.%05d\n",(uint)*(ushort *)(param_1 + 0x38),
         (uint)*(ushort *)(param_1 + 0x3a),(uint)*(ushort *)(param_1 + 0x3c),uVar1 >> 0x10,
         (uVar1 << 0x10) >> 0x18,uVar1 & 0xff,*(undefined4 *)(param_1 + 0x44));
  printf("state: %d\n",*(undefined4 *)(param_1 + 0x48));
  printf("current offset: %d\n",*(undefined4 *)(param_1 + 0x4c));
  if (*(int *)(*(int *)(param_1 + 0x50) + 300) != 0) {
    iVar4 = 0;
    printf("firmware id: ");
    iVar2 = param_1;
    do {
      iVar4 = iVar4 + 1;
      printf("%02X",(uint)*(byte *)(iVar2 + 0x58));
      iVar2 = param_1 + iVar4;
    } while (iVar4 != 0x10);
    printf("\nbl firmware num:%d\n",(uint)*(byte *)(param_1 + 0x68));
    if (*(char *)(param_1 + 0x68) != '\0') {
      puts("bl firmware list:");
      iVar2 = param_1;
      for (iVar4 = 0; iVar4 < (int)(uint)*(byte *)(param_1 + 0x68); iVar4 = iVar4 + 1) {
        iVar5 = 0;
        putchar(9);
        iVar3 = iVar2;
        do {
          iVar5 = iVar5 + 1;
          printf("%02X",(uint)*(byte *)(iVar3 + 0x69));
          iVar3 = iVar2 + iVar5;
        } while (iVar5 != 0x10);
        putchar(10);
        iVar2 = iVar2 + 0x10;
      }
    }
  }
  return;
}

