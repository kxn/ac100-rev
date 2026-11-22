// func band_navigation_db_dump @ 0055fd60 size=60

void band_navigation_db_dump(void)

{
  FUN_004082d0(band_navigation_db_mutex,0xffffffff);
  band_navigation_config_dump(band_navigation_cfg);
  FUN_00407f30(band_navigation_db_mutex);
  return;
}

