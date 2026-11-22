// func check_cur_wireless_network_mode @ 00486994 size=276

undefined4 check_cur_wireless_network_mode(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  char local_38;
  char local_37;
  
  memset(&local_38,0,0x22);
  wsta_roam_db_cfg_get(&local_38);
  if (local_38 == '\0') {
    if ((param_1 != 1) && (local_37 == '\x02')) {
      return 0;
    }
    cVar4 = '\x02';
    iVar1 = apmngr_db_active_ap_num_get();
    iVar2 = get_high_per_ap_cnt();
    if (iVar1 <= iVar2) {
      iVar1 = get_high_per_sta_cnt();
      iVar2 = wsta_db_get_total_num();
      if (iVar2 <= iVar1) {
        cVar4 = '\x01';
      }
    }
    if (local_37 == cVar4) {
      return 0;
    }
  }
  else if (local_38 == '\x01') {
    cVar4 = '\x01';
    if (local_37 == '\x01') {
      return 0;
    }
  }
  else {
    if (local_38 != '\x02') {
      return 0;
    }
    cVar4 = '\x02';
    if (local_37 == '\x02') {
      return 0;
    }
  }
  iVar1 = wireless_network_mode_change_handle(cVar4);
  uVar3 = 0xffffffff;
  if ((iVar1 == 0) && (uVar3 = 0, cVar4 == '\x01')) {
    uVar3 = _wsta_intelligent_roam_do_acs();
  }
  return uVar3;
}

