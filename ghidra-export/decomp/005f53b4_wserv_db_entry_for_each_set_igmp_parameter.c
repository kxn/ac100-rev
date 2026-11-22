// func wserv_db_entry_for_each_set_igmp_parameter @ 005f53b4 size=296

undefined4 wserv_db_entry_for_each_set_igmp_parameter(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar4 = 0xffffffff;
    if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> input error.\r\n",
             "wserv_db_entry_for_each_set_igmp_parameter",0x17d7);
    }
  }
  else {
    iVar2 = FUN_004081b0(&g_wserv_list);
    if (iVar2 == 0) {
      uVar4 = 0;
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x90);
      while( true ) {
        iVar1 = DAT_007cbefc;
        *(undefined1 *)(DAT_007cbefc + iVar3 * 0x21c + 0x20a) = *param_1;
        *(undefined1 *)(iVar1 + *(int *)(iVar2 + 0x90) * 0x21c + 0x20b) = param_1[1];
        *(undefined2 *)(iVar1 + *(int *)(iVar2 + 0x90) * 0x21c + 0x20c) =
             *(undefined2 *)(param_1 + 2);
        *(undefined2 *)(iVar1 + *(int *)(iVar2 + 0x90) * 0x21c + 0x20e) =
             *(undefined2 *)(param_1 + 4);
        *(undefined2 *)(iVar1 + *(int *)(iVar2 + 0x90) * 0x21c + 0x210) =
             *(undefined2 *)(param_1 + 6);
        *(undefined1 *)(iVar1 + *(int *)(iVar2 + 0x90) * 0x21c + 0x212) = param_1[8];
        iVar2 = FUN_00408680(iVar2);
        if (iVar2 == 0) break;
        iVar3 = *(int *)(iVar2 + 0x90);
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}

