// func _uac_wserv_rd_disable @ 005da950 size=680

undefined4 _uac_wserv_rd_disable(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *__format;
  undefined4 uVar5;
  uint uVar6;
  uint local_30 [2];
  
  local_30[0] = 0;
  local_30[1] = 0;
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_rd_disable() begin.\r\n","_uac_wserv_rd_disable",
           0x126b);
  }
  FUN_004082d0(DAT_007598e4,0xffffffff);
  iVar1 = wserv_db_rd_for_each_wserv(param_1,2,_uac_wserv_del_cb,0);
  if (iVar1 == 0) {
    uVar2 = rdmngr_db_generate_ap_id(param_1);
    iVar1 = apmngr_db_ap_is_run_state(uVar2 & 0xffff);
    if (iVar1 != 0) {
      uVar6 = (param_1 & 0xf) - 1;
      if (((((int)uVar2 < 0) || (iVar1 = apmngr_db_get_ap_max(local_30), iVar1 <= (int)uVar2)) ||
          ((int)uVar6 < 0)) || (uVar3 = rdmngr_profile_get_max_rd_per_ap(), uVar3 <= uVar6)) {
        if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> rd_index[%d] is invalid!\r\n",
                 "_uac_wserv_packet_type_set_by_rd_id",0xc6,uVar6);
        }
      }
      else {
        for (uVar3 = 0; uVar4 = rdmngr_profile_get_max_wlan_per_rd(), uVar3 < uVar4;
            uVar3 = uVar3 + 1) {
          *(undefined1 *)(*(int *)(*(int *)(DAT_007598e8 + uVar2 * 0xc + 8) + uVar6 * 4) + uVar3) =
               0x20;
        }
      }
      _uac_wserv_packet_next_cur_id_update_by_ap_id(uVar2);
    }
    local_30[0] = param_1;
    iVar1 = FUN_005d9738(local_30);
    if (iVar1 == 0) {
      FUN_00407f30(DAT_007598e4);
      if (g_wserv_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_rd_disable() success.\r\n",
             "_uac_wserv_rd_disable",0x1283);
      return 0;
    }
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(DAT_007598e4), iVar1 == 0))
    goto LAB_005dab80;
    __format = "<wserv>[error]%s(): %d  -> _uac_wserv_checksum_cb() fail\r\n";
    uVar5 = 0x127e;
  }
  else {
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(DAT_007598e4), iVar1 == 0))
    goto LAB_005dab80;
    __format = "<wserv>[error]%s(): %d  -> wserv_db_rd_for_each_wserv() fail\r\n";
    uVar5 = 0x1270;
  }
  printf(__format,"_uac_wserv_rd_disable",uVar5);
LAB_005dab80:
  FUN_00407f30(DAT_007598e4);
  return 0xffffffff;
}

