// func _uac_wserv_packet_type_set_by_wlan_id @ 005d8a58 size=268

void _uac_wserv_packet_type_set_by_wlan_id(int param_1,uint param_2,uint param_3,undefined1 param_4)

{
  int iVar1;
  uint uVar2;
  
  if ((((param_1 < 0) || (iVar1 = apmngr_db_get_ap_max(), iVar1 <= param_1)) || ((int)param_2 < 0))
     || ((uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar2 <= param_2 ||
         (uVar2 = rdmngr_profile_get_max_wlan_per_rd(), uVar2 <= param_3)))) {
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> wlan_id[%d] is invalid!\r\n",
             "_uac_wserv_packet_type_set_by_wlan_id",0xbb,param_3);
      return;
    }
  }
  else {
    *(undefined1 *)(*(int *)(*(int *)(DAT_007598e8 + param_1 * 0xc + 8) + param_2 * 4) + param_3) =
         param_4;
  }
  return;
}

