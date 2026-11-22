// func _uac_wserv_packet_type_get_by_wlan_id @ 005d61cc size=272

undefined4
_uac_wserv_packet_type_get_by_wlan_id(int param_1,uint param_2,uint param_3,undefined1 *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (((((param_1 < 0) || (iVar1 = apmngr_db_get_ap_max(), iVar1 <= param_1)) || ((int)param_2 < 0))
      || ((uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar2 <= param_2 ||
          (uVar2 = rdmngr_profile_get_max_wlan_per_rd(), uVar2 <= param_3)))) ||
     (param_4 == (undefined1 *)0x0)) {
    uVar3 = 0xffffffff;
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> wlan_id[%d] is invalid!\r\n",
             "_uac_wserv_packet_type_get_by_wlan_id",0xaf,param_3);
    }
  }
  else {
    uVar3 = 0;
    *param_4 = *(undefined1 *)
                (*(int *)(*(int *)(DAT_007598e8 + param_1 * 0xc + 8) + param_2 * 4) + param_3);
  }
  return uVar3;
}

