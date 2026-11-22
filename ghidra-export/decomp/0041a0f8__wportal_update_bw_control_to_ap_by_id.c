// func _wportal_update_bw_control_to_ap_by_id @ 0041a0f8 size=236

undefined4
_wportal_update_bw_control_to_ap_by_id
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_28 [8];
  int local_20;
  
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Update user bw control to ap: %d\n",
           "_wportal_update_bw_control_to_ap_by_id",0x22e,param_1);
  }
  serv_wtp_address_arg_init(auStack_28);
  uVar2 = 0;
  apmngr_db_get_addr_by_capacity(param_1 & 0xffff,auStack_28,1,1,0x15f0000,1,0xd);
  if (local_20 != 0) {
    uVar2 = _wportal_update_bw_control_to_ap(auStack_28,param_2,param_3,param_4,param_5);
  }
  serv_wtp_address_arg_destroy(auStack_28);
  return uVar2;
}

