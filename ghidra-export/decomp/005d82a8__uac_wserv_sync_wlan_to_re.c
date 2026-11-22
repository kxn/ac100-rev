// func _uac_wserv_sync_wlan_to_re @ 005d82a8 size=256

undefined4 _uac_wserv_sync_wlan_to_re(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  code *local_1c;
  int local_18;
  undefined4 *local_14;
  
  local_24 = 0;
  local_20 = (code *)0x0;
  local_1c = (code *)0x0;
  local_18 = 0;
  local_14 = (undefined4 *)0x0;
  local_28 = 0;
  iVar1 = apmngr_db_get_ap_max();
  uVar2 = apmngr_db_get_ap_max();
  iVar1 = FUN_004082a0((iVar1 >> 5) + (uint)((uVar2 & 0x1f) != 0),4,0x11de);
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[error]%s(): %d  -> wserv_calloc() fail\r\n","_uac_wserv_sync_wlan_to_re",
             0x11e1);
    }
  }
  else {
    local_24 = CONCAT22(*(undefined2 *)(param_1 + 0x10),local_24._2_2_);
    local_20 = _uac_wserv_add_cb;
    local_1c = _uac_wserv_del_cb;
    local_14 = &local_28;
    local_18 = iVar1;
    wserv_db_sync_wlan_to_re(&local_24);
    _uac_wserv_update_aps_md5(iVar1,local_28);
    uVar3 = 0;
    FUN_00407df0(iVar1);
  }
  return uVar3;
}

