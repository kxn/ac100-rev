// func _uac_wsta_pkt_rssi_report @ 00635db0 size=204

undefined4
_uac_wsta_pkt_rssi_report(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = 0;
  if (*(uint *)(param_1 + 4) < 0x3e9) {
    for (; uVar2 < *(uint *)(param_1 + 4); uVar2 = uVar2 + 1) {
      iVar1 = *(int *)(param_1 + 8) + uVar2 * 7;
      uac_wstation_update_rssi(iVar1,(int)*(char *)(iVar1 + 6));
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0x15;
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> rssi_val->sta_cnt=%d is invalid.\r\n",
             "_uac_wsta_pkt_rssi_report",0x33b,*(undefined4 *)(param_1 + 4));
    }
  }
  _uac_wsta_pkt_set_result_code(param_4,uVar3);
  return 0;
}

