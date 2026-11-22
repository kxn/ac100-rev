// func apmngr_db_date_str @ 00534100 size=44

undefined * apmngr_db_date_str(uint param_1)

{
  if (param_1 < 8) {
    return (&g_apmngr_date_str)[param_1];
  }
  return &DAT_00688af8;
}

