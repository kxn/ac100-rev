// func _uac_wsta_pkt_ip_report @ 00635e7c size=288

undefined4
_uac_wsta_pkt_ip_report(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  uVar2 = *param_1;
  iVar1 = rdmngr_profile_get_max_rd_per_ap();
  uVar3 = 0;
  if ((uint)(iVar1 * 2000) < uVar2) {
    uVar4 = 0x15;
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> ip_list_val->sta_cnt=%d is invalid.\r\n",
             "_uac_wsta_pkt_ip_report",0x352,*param_1);
    }
  }
  else {
    for (; uVar3 < *param_1; uVar3 = uVar3 + 1) {
      cw_protocol_ip_to_common_ip(param_1[1] + uVar3 * 0x1c + 8,&local_30);
      uac_wstation_update_ip(param_1[1] + uVar3 * 0x1c,local_30,local_2c,local_28,local_24,local_20)
      ;
    }
    uVar4 = 0;
  }
  _uac_wsta_pkt_set_result_code(param_4,uVar4);
  return 0;
}

