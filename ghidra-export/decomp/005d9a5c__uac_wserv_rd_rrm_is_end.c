// func _uac_wserv_rd_rrm_is_end @ 005d9a5c size=304

undefined4 _uac_wserv_rd_rrm_is_end(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = 0;
  local_14 = 0;
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_rd_rrm_is_end() begin.\r\n",
           "_uac_wserv_rd_rrm_is_end",0x128a);
  }
  FUN_004082d0(DAT_007598e4,0xffffffff);
  local_18 = param_1;
  iVar1 = FUN_005d9738(&local_18);
  if (iVar1 == 0) {
    uVar2 = 0;
    FUN_00407f30(DAT_007598e4);
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_rd_rrm_is_end() success.\r\n",
             "_uac_wserv_rd_rrm_is_end",0x1294);
    }
  }
  else {
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(DAT_007598e4), iVar1 != 0)) {
      printf("<wserv>[error]%s(): %d  -> _uac_wserv_checksum_cb() fail\r\n",
             "_uac_wserv_rd_rrm_is_end",0x128f);
    }
    uVar2 = 0xffffffff;
    FUN_00407f30(DAT_007598e4);
  }
  return uVar2;
}

