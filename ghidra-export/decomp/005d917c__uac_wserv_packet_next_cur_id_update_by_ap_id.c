// func _uac_wserv_packet_next_cur_id_update_by_ap_id @ 005d917c size=420

void _uac_wserv_packet_next_cur_id_update_by_ap_id(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if ((param_1 < 0) || (iVar2 = apmngr_db_get_ap_max(), iVar2 <= param_1)) {
    if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> ap_id[%d] is invalid!\r\n",
             "_uac_wserv_packet_next_cur_id_update_by_ap_id",0x11c,param_1);
      return;
    }
  }
  else {
    param_1 = param_1 * 0xc;
    iVar2 = (int)*(char *)(DAT_007598e8 + param_1);
    if ((iVar2 != -1) && (((char *)(DAT_007598e8 + param_1))[1] != -1)) {
      iVar6 = 0;
      bVar1 = true;
      while( true ) {
        uVar5 = iVar6 + iVar2;
        uVar3 = rdmngr_profile_get_max_rd_per_ap();
        if (uVar3 <= uVar5) break;
        uVar3 = 0;
        if (bVar1) {
          uVar3 = (uint)*(char *)(DAT_007598e8 + param_1 + 1);
        }
        for (; uVar4 = rdmngr_profile_get_max_wlan_per_rd(), uVar3 < uVar4; uVar3 = uVar3 + 1) {
          if ((*(byte *)(*(int *)(*(int *)((undefined1 *)(DAT_007598e8 + param_1) + 8) + uVar5 * 4)
                        + uVar3) & 0xf) != 0) {
            *(undefined1 *)(DAT_007598e8 + param_1) = (char)uVar5;
            *(char *)(DAT_007598e8 + param_1 + 1) = (char)uVar3;
            return;
          }
        }
        iVar6 = iVar6 + 1;
        bVar1 = false;
      }
      *(undefined1 *)(DAT_007598e8 + param_1) = 0xff;
      *(undefined1 *)(DAT_007598e8 + param_1 + 1) = 0xff;
    }
  }
  return;
}

