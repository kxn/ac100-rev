// func uac_wstation_free_sta_by_mac @ 00632e80 size=24

void uac_wstation_free_sta_by_mac(undefined4 param_1,code *param_2)

{
  if (param_2 != (code *)0x0) {
    param_2 = _uac_wsta_del_cb;
  }
  wsta_db_free_sta_by_mac_new(param_1,param_2,0);
  return;
}

