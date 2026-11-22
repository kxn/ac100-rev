// func apmngr_db_set_dft_offline_selfmanage @ 00541aec size=16

void apmngr_db_set_dft_offline_selfmanage(int param_1)

{
  apmngr_dft_offline_selfmanage = (uint)(param_1 != 0);
  return;
}

