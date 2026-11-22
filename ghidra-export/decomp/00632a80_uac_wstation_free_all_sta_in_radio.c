// func uac_wstation_free_all_sta_in_radio @ 00632a80 size=24

void uac_wstation_free_all_sta_in_radio(undefined4 param_1,undefined1 param_2,code *param_3)

{
  if (param_3 != (code *)0x0) {
    param_3 = _uac_wsta_del_cb;
  }
  wsta_db_free_rd_sta(param_1,param_2,param_3,0);
  return;
}

