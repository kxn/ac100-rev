// func _uac_wserv_ap_del_cb @ 005dcd80 size=368

undefined4 _uac_wserv_ap_del_cb(int param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 local_18;
  undefined2 local_16;
  
  uVar4 = 0xffffffff;
  if (param_1 != 0) {
    if (g_wserv_debug == 0) {
      local_18 = *(undefined2 *)(param_1 + 0x44);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        local_18 = *(undefined2 *)(param_1 + 0x44);
      }
      else {
        printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ap_del_cb() begin, ap_id=%d.\r\n",
               "_uac_wserv_ap_del_cb",0x1147,(uint)*(ushort *)(param_1 + 0x10));
        local_18 = *(undefined2 *)(param_1 + 0x44);
      }
    }
    local_16 = *(undefined2 *)(param_1 + 0x46);
    iVar1 = uac_wservice_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_18)
    ;
    if (iVar1 < 0) {
      uVar4 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n",
               "_uac_wserv_ap_del_cb",0x114e,iVar1);
      }
    }
    else {
      iVar1 = wserv_db_ap_del(*(undefined2 *)(param_1 + 0x10),iVar1);
      if (iVar1 == 0) {
        uVar4 = 0;
        if (g_wserv_debug == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        __format = "<wserv>[debug]%s(): %d  -> _uac_wserv_ap_del_cb() success.\r\n";
        uVar3 = 0x1157;
      }
      else {
        uVar4 = 0xffffffff;
        if (g_wserv_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "<wserv>[error]%s(): %d  -> uac_wservice_ap_del() fail.\r\n";
        uVar3 = 0x1154;
      }
      printf(__format,"_uac_wserv_ap_del_cb",uVar3);
    }
  }
  return uVar4;
}

