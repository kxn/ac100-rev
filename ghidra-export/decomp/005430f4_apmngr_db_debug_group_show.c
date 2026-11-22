// func apmngr_db_debug_group_show @ 005430f4 size=1

void apmngr_db_debug_group_show(void)

{
  ushort uVar1;
  int iVar2;
  
  puts("Group List:");
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  iVar2 = FUN_004081b0(&g_apmngr_group_list);
  if (iVar2 != 0) {
    uVar1 = *(ushort *)(iVar2 + 0xc);
    while( true ) {
      printf(" %5d,",(uint)uVar1);
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      uVar1 = *(ushort *)(iVar2 + 0xc);
    }
  }
  puts("\b");
  uac_mutex_give(apmngr_db_mutex);
  return;
}

