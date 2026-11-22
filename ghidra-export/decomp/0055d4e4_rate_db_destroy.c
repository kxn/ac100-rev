// func rate_db_destroy @ 0055d4e4 size=72

void rate_db_destroy(void)

{
  rrc_destroy(rate_cfg);
  rate_cfg = 0;
  if (rate_db_mutex != 0) {
    FUN_00408360();
  }
  rate_db_mutex = 0;
  return;
}

