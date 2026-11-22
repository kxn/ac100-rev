// func rate_db_dump @ 0055d52c size=72

void rate_db_dump(void)

{
  FUN_004082d0(rate_db_mutex,0xffffffff);
  rrc_dump(rate_cfg);
  rrc_md5_dump(rate_cfg_md5);
  FUN_00407f30(rate_db_mutex);
  return;
}

