// func cloud_mngt_sync_module_config_show @ 0049c3ec size=1

void cloud_mngt_sync_module_config_show(void)

{
  int iVar1;
  int iVar2;
  
  puts("=====cloud mngt sync module config=====");
  for (iVar1 = FUN_004081b0(&g_cloud_mngt_sync_module_list); iVar1 != 0; iVar1 = FUN_00408680(iVar1)
      ) {
    puts((char *)(iVar1 + 0xc));
    for (iVar2 = FUN_004081b0(iVar1 + 0x40); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
      puts((char *)(iVar2 + 0xc));
    }
    putchar(10);
  }
  return;
}

