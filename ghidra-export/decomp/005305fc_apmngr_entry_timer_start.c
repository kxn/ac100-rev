// func apmngr_entry_timer_start @ 005305fc size=952

undefined4 apmngr_entry_timer_start(ushort param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  int extraout_v1;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_2f8 [56];
  int local_2c0;
  undefined1 auStack_5e [66];
  
  uVar5 = (uint)param_1;
  memset(auStack_2f8,0,0x2d8);
  FUN_00407e70();
  if ((apmngr_timer_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_TIMER]%s()/%d apmngr_entry_timer_start: ap[%d], op_type :%d, timer_sec :%d, now_time: %d\n"
           ,"apmngr_entry_timer_start",0xc2a,uVar5,param_2,param_3,extraout_v1);
  }
  iVar1 = apmngr_db_entry_get_by_id(uVar5,auStack_2f8);
  if (iVar1 != 0) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id failed: %d.\n",
           "apmngr_entry_timer_start",0xc2d,uVar5);
    return 0xffffffff;
  }
  if (param_2 == 0) {
    puVar3 = (ushort *)FUN_00408450(2,0xc32);
    if (puVar3 == (ushort *)0x0) {
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      uVar4 = 0xc35;
      goto LAB_00530914;
    }
    *puVar3 = param_1;
    iVar1 = apmngr_db_ap_entry_timer_time_set(uVar5,0,extraout_v1);
    if ((iVar1 == 0) &&
       (iVar1 = apmngr_db_ap_entry_timer_start
                          (uVar5,0,param_3,_apmngr_ap_entry_timer_deletet_ap_handler,puVar3,
                           _apmngr_ap_entry_timer_deletet_ap_free), iVar1 == 0)) {
      return 0;
    }
    if ((apmngr_err_switch == '\0') || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_005307b8;
    uVar4 = 0xc3b;
  }
  else {
    if (param_2 != 1) {
      return 0;
    }
    if (local_2c0 == 0) {
      apmngr_db_ap_entry_timer_time_set(uVar5,1,extraout_v1);
    }
    else {
      uVar2 = apmngr_db_timer_md5_send_interval_max_get();
      if (uVar2 < (uint)(extraout_v1 - local_2c0)) {
        if ((apmngr_timer_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APMNGR_TIMER]%s()/%d now must send ap[%d] md5\n","apmngr_entry_timer_start",0xc46
                 ,uVar5);
        }
        apmngr_pkt_checksum_pkt_send_by_id(uVar5,auStack_5e);
        apmngr_db_ap_entry_timer_stop(uVar5,1);
        apmngr_db_ap_entry_timer_time_set(uVar5,1,0);
        return 0;
      }
      iVar1 = apmngr_db_timer_md5_send_interval_gap_get();
      param_3 = param_3 + iVar1;
      if ((apmngr_timer_switch != '\0') && (iVar1 = is_target_debug_ap(0x12), iVar1 != 0)) {
        printf("[APMNGR_TIMER]%s()/%d ap[%d] last md5 need wait %d send\n",
               "apmngr_entry_timer_start",0xc4d,uVar5,param_3);
      }
    }
    puVar3 = (ushort *)FUN_00408450(0x12,0xc53);
    if (puVar3 == (ushort *)0x0) {
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      uVar4 = 0xc56;
LAB_00530914:
      printf("[APMNGR_ERROR]%s()/%d malloc fail\n","apmngr_entry_timer_start",uVar4);
      return 0xffffffff;
    }
    *puVar3 = param_1;
    memcpy(puVar3 + 1,auStack_5e,0x10);
    iVar1 = apmngr_db_ap_entry_timer_start
                      (uVar5,1,param_3,_apmngr_ap_entry_timer_send_md5_handler,puVar3,
                       _apmngr_ap_entry_timer_send_md5_free);
    if (iVar1 == 0) {
      return 0;
    }
    if ((apmngr_err_switch == '\0') || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_005307b8;
    uVar4 = 0xc5e;
  }
  printf("[APMNGR_ERROR]%s()/%d Failed to start ap entry timer for ap %d.\n",
         "apmngr_entry_timer_start",uVar4,uVar5);
LAB_005307b8:
  FUN_00407df0(puVar3);
  return 0xffffffff;
}

