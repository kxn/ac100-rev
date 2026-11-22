// func _uac_wserv_packet_cur_id_set_by_ap_id @ 005d88f4 size=192

void _uac_wserv_packet_cur_id_set_by_ap_id(int param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  
  if ((param_1 < 0) || (iVar1 = apmngr_db_get_ap_max(), iVar1 <= param_1)) {
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> ap_id[%d] is invalid!\r\n",
             "_uac_wserv_packet_cur_id_set_by_ap_id",0x10e,param_1);
      return;
    }
  }
  else {
    *(undefined1 *)(DAT_007598e8 + param_1 * 0xc) = param_2;
    *(undefined1 *)(DAT_007598e8 + param_1 * 0xc + 1) = param_3;
  }
  return;
}

