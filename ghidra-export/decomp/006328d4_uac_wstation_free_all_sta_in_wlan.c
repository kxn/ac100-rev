// func uac_wstation_free_all_sta_in_wlan @ 006328d4 size=48

void uac_wstation_free_all_sta_in_wlan
               (undefined4 param_1,undefined1 param_2,undefined1 param_3,code *param_4)

{
  if (param_4 != (code *)0x0) {
    param_4 = _uac_wsta_del_cb;
  }
  wsta_db_free_wlan_sta(param_1,param_2,param_3,param_4,0);
  return;
}

