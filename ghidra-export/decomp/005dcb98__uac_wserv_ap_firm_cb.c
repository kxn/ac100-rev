// func _uac_wserv_ap_firm_cb @ 005dcb98 size=488

undefined4 _uac_wserv_ap_firm_cb(int param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 local_20;
  undefined2 local_1e;
  int local_1c [3];
  
  uVar4 = 0xffffffff;
  local_1c[0] = 0;
  local_1c[1] = 0;
  if (param_1 != 0) {
    if (g_wserv_debug == 0) {
      local_20 = *(undefined2 *)(param_1 + 0x44);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        local_20 = *(undefined2 *)(param_1 + 0x44);
      }
      else {
        printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ap_firm_cb() begin, ap_id=%d.\r\n",
               "_uac_wserv_ap_firm_cb",0x10a1,(uint)*(ushort *)(param_1 + 0x10));
        local_20 = *(undefined2 *)(param_1 + 0x44);
      }
    }
    local_1e = *(undefined2 *)(param_1 + 0x46);
    iVar1 = uac_wservice_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_20)
    ;
    if (iVar1 < 0) {
      uVar4 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n",
               "_uac_wserv_ap_firm_cb",0x10a9,iVar1);
      }
    }
    else {
      iVar1 = wserv_db_ap_firm(*(undefined2 *)(param_1 + 0x10),iVar1);
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 0x14);
        if ((((iVar1 == 4) || (iVar1 == 8)) || (iVar1 == 6)) || (iVar1 == 5)) {
          wserv_db_ap_sync_bind_list
                    (*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x10),
                     _uac_wserv_add_cb,_uac_wserv_del_cb,0,0);
          return 0;
        }
        local_1c[1] = 0;
        local_1c[0] = param_1;
        wserv_db_entry_for_each(_wserv_db_entry_auto_bind,local_1c);
        uVar4 = 0;
        if (g_wserv_debug == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        __format = "<wserv>[debug]%s(): %d  -> _uac_wserv_ap_firm_cb() success.\r\n";
        uVar3 = 0x10c0;
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
        __format = "<wserv>[error]%s(): %d  -> uac_wservice_ap_firm() fail.\r\n";
        uVar3 = 0x10af;
      }
      printf(__format,"_uac_wserv_ap_firm_cb",uVar3);
    }
  }
  return uVar4;
}

