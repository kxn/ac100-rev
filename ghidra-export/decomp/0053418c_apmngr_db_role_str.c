// func apmngr_db_role_str @ 0053418c size=44

undefined * apmngr_db_role_str(uint param_1)

{
  if (param_1 < 9) {
    return (&PTR_s_normal_006c9cb4)[param_1];
  }
  return &DAT_00688af8;
}

