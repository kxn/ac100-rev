// func band_navigation_destroy @ 0055fac8 size=8

void band_navigation_destroy(void)

{
  band_navigation_config_destroy(band_navigation_cfg);
  band_navigation_cfg = 0;
  if (band_navigation_db_mutex != 0) {
    FUN_00408360();
  }
  band_navigation_db_mutex = 0;
  return;
}

