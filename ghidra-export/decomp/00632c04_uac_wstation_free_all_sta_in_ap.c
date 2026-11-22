// func uac_wstation_free_all_sta_in_ap @ 00632c04 size=24

void uac_wstation_free_all_sta_in_ap(undefined4 param_1,code *param_2)

{
  if (param_2 != (code *)0x0) {
    param_2 = _uac_wsta_del_cb;
  }
  wsta_db_free_ap_sta(param_1,param_2,0);
  return;
}

