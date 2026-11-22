// func wsta_intelligent_roam_do_acs @ 00489c00 size=8

undefined4 wsta_intelligent_roam_do_acs(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iStack_40;
  undefined1 uStack_3c;
  byte bStack_3b;
  
  iStack_40 = 0;
  memset(&uStack_3c,0,0x22);
  wsta_roam_db_cfg_get(&uStack_3c);
  uVar4 = (uint)bStack_3b;
  if (uVar4 == 1) {
    uVar3 = 0;
    iVar1 = get_acs_process_state();
    if (iVar1 != 1) {
      apmngr_db_foreach_proc(0x15f0000,_wstat_roam_check_support_acs,&iStack_40);
      iVar1 = iStack_40;
      if ((begin_acs_container == 0) && (0 < iStack_40)) {
        FUN_004082d0(wsta_roam_pkt_chnl_mutex,0xffffffff);
        acs_ap_cnt = iVar1;
        is_process_acs = uVar4;
        FUN_00407f30(wsta_roam_pkt_chnl_mutex);
        iVar2 = get_acs_timeout();
        begin_acs_container =
             FUN_00408180("begin_to_acs",iVar2 + 1,iVar1,wsta_roam_chnl_obj_hash_func,
                          wsta_roam_chnl_key_hash_func,wsta_roam_chnl_cmp_func,
                          wsta_roam_chnl_key_get_func,wsta_roam_chnl_data_free,
                          wsta_roam_chnl_update_func,wsta_roam_chnl_handle);
        if (begin_acs_container == 0) {
          if (wsta_roam_err_switch != '\0') {
            printf("[WSTA_ROAM_ERROR]%s()/%d Failed to create begin_acs_container container\n",
                   "begin_to_acs",0x94e);
          }
          if (wsta_roam_err_switch != '\0') {
            uVar3 = get_acs_timeout();
            printf("[WSTA_ROAM_ERROR]%s()/%d get_acs_timeout():%d\n","begin_to_acs",0x94f,uVar3);
          }
          if (wsta_roam_err_switch != '\0') {
            printf("[WSTA_ROAM_ERROR]%s()/%d ap_cnt:%d\n","begin_to_acs",0x950,iVar1);
          }
          init_acs_to_end_state();
          return 0xffffffff;
        }
        if (g_acs_timer_id != -1) {
          FUN_00408060();
          g_acs_timer_id = -1;
        }
        iVar1 = get_acs_timeout();
        g_acs_timer_id = FUN_00408340(iVar1 + 5,0,acs_timeout_handle,0,0,"begin_to_acs",0x95c);
      }
      uVar3 = 0;
      apmngr_db_foreach_proc(0x15f0000,_wstat_roam_start_acs_to_ap,0);
    }
  }
  else {
    uVar3 = 0xffffffff;
    if (wsta_roam_warning_switch != '\0') {
      printf("[WSTA_ROAM_WARNING]%s()/%d  ap mode:%d not support acs to rrm\n",
             "_wsta_intelligent_roam_do_acs",0xc48,uVar4);
    }
  }
  return uVar3;
}

