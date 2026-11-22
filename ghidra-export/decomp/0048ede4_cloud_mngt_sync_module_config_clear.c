// func cloud_mngt_sync_module_config_clear @ 0048ede4 size=56

void cloud_mngt_sync_module_config_clear(void)

{
  FUN_004082d0(cloud_mngt_data_mutex,0xffffffff);
  _cloud_mngt_sync_module_config_clear();
  FUN_00407f30(cloud_mngt_data_mutex);
  return;
}

