// func _uac_wserv_packet_cur_id_get_by_ap_id @ 005d881c size=216

undefined4
_uac_wserv_packet_cur_id_get_by_ap_id(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_1 < 0) || (iVar1 = apmngr_db_get_ap_max(), iVar1 <= param_1)) ||
      (param_2 == (undefined1 *)0x0)) || (param_3 == (undefined1 *)0x0)) {
    uVar2 = 0xffffffff;
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> ap_id[%d] is invalid!\r\n",
             "_uac_wserv_packet_cur_id_get_by_ap_id",0x100,param_1);
    }
  }
  else {
    *param_2 = *(undefined1 *)(DAT_007598e8 + param_1 * 0xc);
    uVar2 = 0;
    *param_3 = *(undefined1 *)(DAT_007598e8 + param_1 * 0xc + 1);
  }
  return uVar2;
}

