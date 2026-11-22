// func wsta_roam_db_print_real_chnl @ 004837a8 size=1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wsta_roam_db_print_real_chnl(void)

{
  printf("_2g_radio_chn: %d\n",(int)high_per_ap_chn_info);
  printf("_5g1_radio_chn: %d\n",(int)_DAT_0076756e);
  printf("_5g2_radio_chn: %d\n",(int)DAT_00767570);
  return;
}

