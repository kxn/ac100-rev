// func _uac_wserv_rd_enable @ 005d9b8c size=400

undefined4 _uac_wserv_rd_enable(undefined4 param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_rd_enable() begin.\r\n","_uac_wserv_rd_enable",
           0x11c2);
  }
  FUN_004082d0(DAT_007598e4,0xffffffff);
  iVar1 = wserv_db_rd_for_each_wserv(param_1,1,_uac_wserv_add_cb,0);
  if (iVar1 == 0) {
    local_20 = param_1;
    iVar1 = FUN_005d9738(&local_20);
    if (iVar1 == 0) {
      FUN_00407f30(DAT_007598e4);
      if (g_wserv_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_rd_enable() success.\r\n","_uac_wserv_rd_enable"
             ,0x11d4);
      return 0;
    }
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(DAT_007598e4), iVar1 == 0))
    goto LAB_005d9ca4;
    __format = "<wserv>[error]%s(): %d  -> _uac_wserv_checksum_cb() fail\r\n";
    uVar2 = 0x11cf;
  }
  else {
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(DAT_007598e4), iVar1 == 0))
    goto LAB_005d9ca4;
    __format = "<wserv>[error]%s(): %d  -> wserv_db_rd_for_each_wserv() fail\r\n";
    uVar2 = 0x11c7;
  }
  printf(__format,"_uac_wserv_rd_enable",uVar2);
LAB_005d9ca4:
  FUN_00407f30(DAT_007598e4);
  return 0xffffffff;
}

