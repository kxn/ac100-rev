// func _uac_nms_report_pkt_enter_run_cb @ 0049de50 size=136

undefined4 _uac_nms_report_pkt_enter_run_cb(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2e0 [16];
  undefined2 local_2d0;
  
  memset(auStack_2e0,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_mac(param_1,auStack_2e0);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    iVar1 = nms_call_wtp_online(local_2d0);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffff;
    if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d get ap entry by id failed.\n",
             "_uac_nms_report_pkt_enter_run_cb",0x1fd);
    }
  }
  return uVar2;
}

