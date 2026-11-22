// func uac_bcast_storm_ctrl_init @ 0045f0b8 size=352

undefined4 uac_bcast_storm_ctrl_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  char *local_18;
  undefined4 local_14;
  code *local_10;
  undefined4 local_c;
  
  iVar1 = bcast_storm_ctrl_cfg_init();
  if (iVar1 == 0) {
    iVar1 = FUN_004084d0("bcast_storm_ctrl",2,_uac_bcast_storm_ctrl_jcs_set);
    if (iVar1 == 0) {
      local_c = 0;
      local_18 = "broadcast storm control";
      local_14 = 0x64000000;
      local_10 = _uac_bcast_storm_ctrl_pkt_send_to_wtp;
      iVar1 = multi_link_reg(&local_18);
      if (iVar1 == 0) {
        apmngr_support_capacity_register(0xe);
        return 0;
      }
      if (bcast_storm_ctrl_error_switch != 0) {
        printf("[BCAST_STORM_CTRL_ERROR]%s()/line %d : register failed.\n",
               "_uac_bcast_storm_ctrl_multilink_callback_register",0x1a5);
      }
      if ((bcast_storm_ctrl_cfg_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_0045f144;
      __format = 
      "[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : broadcast storm control register multilink callback failed.\n"
      ;
      uVar2 = 0x1d4;
    }
    else {
      if ((bcast_storm_ctrl_cfg_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_0045f144;
      __format = 
      "[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : broadcast storm control register jcs callback failed.\n"
      ;
      uVar2 = 0x1cb;
    }
  }
  else {
    if ((bcast_storm_ctrl_cfg_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_0045f144;
    __format = 
    "[BCAST_STORM_CTRL_CFG_ERROR]%s()/line %d : broadcast storm control init config failed.\n";
    uVar2 = 0x1c2;
  }
  printf(__format,"uac_bcast_storm_ctrl_init",uVar2);
LAB_0045f144:
  bcast_storm_ctrl_cfg_destory();
  return 0xffffffff;
}

