// func apupd_model_entry_dump @ 0064a35c size=1048

void apupd_model_entry_dump(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char acStack_98 [132];
  
  memset(acStack_98,0,0x80);
  if (param_1 == 0) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_model_entry_dump",0xbc1);
    }
  }
  else {
    puts("======>model dump:");
    if ((*(uint *)(param_1 + 0x18) & 1) == 0) {
      iVar3 = 0;
      printf("group id:\t");
      iVar1 = param_1;
      while( true ) {
        iVar3 = iVar3 + -4;
        printf("0x%08x\t",*(undefined4 *)(iVar1 + 0x54));
        if (iVar3 == -0x40) break;
        iVar1 = param_1 + iVar3;
      }
      putchar(10);
    }
    else {
      puts("group id: [ ALL ]");
    }
    printf("model id: %d\n",*(undefined4 *)(param_1 + 0x58));
    printf("file name: %s\n",param_1 + 0xc4);
    printf("hard ver number: %d\n",*(undefined4 *)(param_1 + 0xa0));
    printf("hard ver:");
    uVar2 = *(uint *)(param_1 + 0xa0);
    iVar1 = param_1;
    for (uVar4 = 0; uVar4 < uVar2; uVar4 = uVar4 + 1) {
      printf(" %d.%d",(uint)*(ushort *)(iVar1 + 0xa4),(uint)*(ushort *)(iVar1 + 0xa6));
      uVar2 = *(uint *)(param_1 + 0xa0);
      iVar1 = iVar1 + 4;
    }
    putchar(10);
    printf("state: %d\n",*(undefined4 *)(param_1 + 0x140));
    printf("is_sys: %d\n",(uint)*(byte *)(param_1 + 0x139));
    printf("is_large_fw: %d\n",(uint)*(byte *)(param_1 + 0x13a));
    if (*(char *)(param_1 + 0x13a) == '\x01') {
      printf("total_image_size: %d\n",*(undefined4 *)(param_1 + 0x188));
      printf("total_image_piece: %d\n",*(undefined4 *)(param_1 + 0x18c));
      printf("sub_image_num: %d\n",(uint)*(byte *)(param_1 + 0x1a0));
      printf("can_down_sub_image: %d\n",(uint)*(byte *)(param_1 + 0x1a1));
      printf("got_image_size: %d\n",*(undefined4 *)(param_1 + 0x1a4));
      printf("reply_num: %d\n",*(undefined4 *)(param_1 + 0x1a8));
      printf("parent_need_update: %d\n",*(undefined4 *)(param_1 + 0x148));
    }
    iVar3 = 0;
    printf("upd_type: %d\n",*(undefined4 *)(param_1 + 0x7ec));
    printf("need upgrade: %d\n",*(undefined4 *)(param_1 + 0x144));
    printf("finish upgrade: %d\n",*(undefined4 *)(param_1 + 0x14c));
    printf("upgrade datetime type: %d\n",*(undefined4 *)(param_1 + 0x7f0));
    iVar1 = *(int *)(param_1 + 0x15c);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    sprintf(acStack_98,"%02d/%02d/%04d %02d:%02d:%02d",*(int *)(param_1 + 0x160) + 1,iVar1,
            *(int *)(param_1 + 0x164) + 0x76c,*(undefined4 *)(param_1 + 0x158),
            *(undefined4 *)(param_1 + 0x154),*(undefined4 *)(param_1 + 0x150));
    printf("time update: %s\n",acStack_98);
    printf("file size: %d\n",*(undefined4 *)(param_1 + 0x1ac));
    printf("md5: ");
    iVar1 = param_1;
    do {
      iVar3 = iVar3 + 1;
      printf("%02x",(uint)*(byte *)(iVar1 + 0x1b4));
      iVar1 = param_1 + iVar3;
    } while (iVar3 != 0x10);
    putchar(10);
    uVar2 = *(uint *)(param_1 + 0x1cc);
    printf("soft ver: %d.%d.%d Build %02d%02d%02d Rel.%05d\n",(uint)*(ushort *)(param_1 + 0x1c4),
           (uint)*(ushort *)(param_1 + 0x1c6),(uint)*(ushort *)(param_1 + 0x1c8),uVar2 >> 0x10,
           (uVar2 << 0x10) >> 0x18,uVar2 & 0xff,*(undefined4 *)(param_1 + 0x1d0));
    printf("support cloud upgrade: %d\n",*(undefined4 *)(param_1 + 300));
    if (*(int *)(param_1 + 300) != 0) {
      iVar3 = 0;
      printf("hardware id:");
      iVar1 = param_1;
      while( true ) {
        iVar3 = iVar3 + 1;
        printf("%02X",(uint)*(byte *)(iVar1 + 0x119));
        if (iVar3 == 0x10) break;
        iVar1 = param_1 + iVar3;
      }
      putchar(10);
    }
    printf("support large fw upgrade: %d\n",*(undefined4 *)(param_1 + 0x130));
    printf("is mesh device: %d\n",*(undefined4 *)(param_1 + 0x134));
    printf("product type: %d\n",(uint)*(byte *)(param_1 + 0x138));
    printf("wtp number: %d\n",*(undefined4 *)(param_1 + 0x7fc));
    for (iVar1 = FUN_004081b0(param_1 + 0x7f4); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      apupd_wtp_entry_dump(iVar1);
    }
  }
  return;
}

