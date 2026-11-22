// func rate_info_destroy @ 0055cb34 size=8

void rate_info_destroy(void)

{
  rrc_destroy(rate_cfg);
  rate_cfg = 0;
  if (rate_db_mutex != 0) {
    FUN_00408360();
  }
  rate_db_mutex = 0;
  return;
}

