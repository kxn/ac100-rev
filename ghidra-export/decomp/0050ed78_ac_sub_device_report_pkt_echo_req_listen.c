// func ac_sub_device_report_pkt_echo_req_listen @ 0050ed78 size=320

undefined4 ac_sub_device_report_pkt_echo_req_listen(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  time_t tVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_2f0 [16];
  undefined2 local_2e0;
  
  uVar4 = 0;
  piVar1 = (int *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x8d);
  memset(auStack_2f0,0,0x2d8);
  if (piVar1 != (int *)0x0) {
    tVar2 = time((time_t *)0x0);
    if (ac_passthrough_debug_switch == '\0') {
      iVar3 = *piVar1;
    }
    else {
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d AP time:%d, DUT time:%d, threshold:%d\n",
             "ac_sub_device_report_pkt_echo_req_listen",0x67b,*piVar1,tVar2,piVar1[1]);
      iVar3 = *piVar1;
    }
    if (((iVar3 < tVar2) && (piVar1[1] < tVar2 - iVar3)) ||
       ((uVar4 = 0, tVar2 < iVar3 && (piVar1[1] < iVar3 - tVar2)))) {
      iVar3 = apmngr_db_entry_get_by_mac(param_2,auStack_2f0);
      if (iVar3 == 0) {
        uVar4 = 0;
        ac_passthrough_time_stamp_sync_to_ap(local_2e0);
      }
      else {
        uVar4 = 0xffffffff;
        if (ac_passthrough_err_switch != '\0') {
          printf("[AC_PASSTHROUGH_ERROR]%s()/%d apmngr_db_entry_get_by_mac() fail.\n",
                 "ac_sub_device_report_pkt_echo_req_listen",0x681);
        }
      }
    }
  }
  return uVar4;
}

