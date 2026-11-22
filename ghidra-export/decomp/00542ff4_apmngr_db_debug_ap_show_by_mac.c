// func apmngr_db_debug_ap_show_by_mac @ 00542ff4 size=1

void apmngr_db_debug_ap_show_by_mac(char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 uStack_300;
  undefined2 uStack_2fc;
  undefined4 uStack_2f8;
  undefined1 auStack_2f4 [4];
  undefined1 auStack_2f0 [4];
  undefined1 auStack_2ec [4];
  undefined1 auStack_2e8 [4];
  undefined1 auStack_2e4 [4];
  undefined1 auStack_2e0 [728];
  
  uStack_300 = 0;
  uStack_2fc = 0;
  memset(auStack_2e0,0,0x2d8);
  iVar1 = sscanf(param_1,"%2X-%2X-%2X-%2X-%2X-%2X",&uStack_2f8,auStack_2f4,auStack_2f0,auStack_2ec,
                 auStack_2e8,auStack_2e4);
  if (iVar1 == 6) {
    puVar2 = &uStack_2f8;
    iVar1 = 0;
    do {
      puVar3 = (undefined1 *)((int)&uStack_300 + iVar1);
      uVar4 = *puVar2;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
      *puVar3 = (char)uVar4;
    } while (iVar1 != 6);
    iVar1 = apmngr_db_entry_get_by_mac(&uStack_300,auStack_2e0);
    if (iVar1 == 0) {
      printf(
            "  ID (type, link, role )|GID|     Entry-Name     |       MAC       |      Hardware      |         Soft Ver        | Status|  LED  |"
            );
      puts("\nOptions..");
      apmngr_debug_ap_print(auStack_2e0,1);
    }
    else {
      printf("can\'t find ap entry for %s\n",param_1);
    }
  }
  else {
    puts("parameter is wrong");
  }
  return;
}

