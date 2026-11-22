// func _apmngr_ap_entry_timer_send_md5_handler @ 0052a3e8 size=244

void _apmngr_ap_entry_timer_send_md5_handler(ushort *param_1)

{
  int iVar1;
  undefined4 extraout_v1;
  ushort uVar2;
  
  FUN_00407e70();
  if (param_1 != (ushort *)0x0) {
    if (apmngr_timer_switch == '\0') {
      uVar2 = *param_1;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar2 = *param_1;
      }
      else {
        printf("[APMNGR_TIMER]%s()/%d send ap[%d] md5, now is %d\n",
               "_apmngr_ap_entry_timer_send_md5_handler",0xc17,(uint)*param_1,extraout_v1);
        uVar2 = *param_1;
      }
    }
    apmngr_pkt_checksum_pkt_send_by_id(uVar2,param_1 + 1);
    apmngr_db_ap_entry_timer_stop(*param_1,1);
    apmngr_db_ap_entry_timer_time_set(*param_1,1,0);
    return;
  }
  if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d input error\n","_apmngr_ap_entry_timer_send_md5_handler",0xc13);
    return;
  }
  return;
}

