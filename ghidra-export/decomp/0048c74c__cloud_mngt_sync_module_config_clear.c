// func _cloud_mngt_sync_module_config_clear @ 0048c74c size=148

void _cloud_mngt_sync_module_config_clear(void)

{
  int iVar1;
  int iVar2;
  
  FUN_004081b0(&g_cloud_mngt_sync_module_list);
  while (iVar1 = FUN_004081b0(&g_cloud_mngt_sync_module_list), iVar1 != 0) {
    while (iVar2 = FUN_004081b0(iVar1 + 0x40), iVar2 != 0) {
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
    }
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  }
  return;
}

