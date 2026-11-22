// func wserv_ip_print_all @ 005f5c28 size=1

void wserv_ip_print_all(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined1 auStack_68 [64];
  
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  if (l_wserv_data != 0) {
    puts("########################################################");
    iVar3 = 0;
    printf("l_wserv_data.id_used = %d\n",DAT_007cbf10);
    do {
      pcVar2 = (char *)(DAT_007cbf14 + iVar3);
      if (*pcVar2 != '\0') {
        memset(auStack_68,0,0x40);
        FUN_00408190(*(undefined4 *)(pcVar2 + 8),*(undefined4 *)(pcVar2 + 0xc),
                     *(undefined4 *)(pcVar2 + 0x10),*(undefined4 *)(pcVar2 + 0x14),
                     *(undefined4 *)(pcVar2 + 0x18),auStack_68,0x40,"---");
        printf("id        = %d\n",*(undefined4 *)(pcVar2 + 4));
        printf("ip_addr     = %s\n",auStack_68);
        if ((byte)pcVar2[0x1c] == 1) {
          pcVar1 = "multi2uni";
        }
        else {
          pcVar1 = "multi";
        }
        printf("relay     = %d(%s)\n",(uint)(byte)pcVar2[0x1c],pcVar1);
        if ((byte)pcVar2[0x1d] == 1) {
          pcVar1 = "enable";
        }
        else {
          pcVar1 = "disable";
        }
        printf("status     = %d(%s)\n",(uint)(byte)pcVar2[0x1d],pcVar1);
        puts("#####################################################################");
      }
      iVar3 = iVar3 + 0x20;
    } while (iVar3 != 0x400);
  }
  FUN_00407f30(DAT_007cbef0);
  return;
}

