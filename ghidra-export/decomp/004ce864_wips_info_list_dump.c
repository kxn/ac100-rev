// func wips_info_list_dump @ 004ce864 size=1

void wips_info_list_dump(void)

{
  int iVar1;
  
  FUN_004082d0(wips_global_mutex,0xffffffff);
  puts("\nwips info list dump:");
  for (iVar1 = FUN_004081b0(&g_wips_list); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
    wips_info_dump(iVar1);
  }
  uac_mutex_give(wips_global_mutex);
  return;
}

