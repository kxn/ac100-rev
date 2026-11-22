// func _uac_bcast_storm_ctrl_pkt_send_to_wtp @ 0045ebc4 size=464

undefined4 _uac_bcast_storm_ctrl_pkt_send_to_wtp(uint param_1)

{
  int iVar1;
  undefined4 local_2f8;
  undefined4 local_2f4;
  int local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [732];
  
  param_1 = param_1 & 0xffff;
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = serv_wtp_address_arg_init(&local_2f8);
  if (iVar1 == 0) {
    iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
    if (iVar1 == 0) {
      iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_2f8,1,1,0x15f0000,1,0xe);
      if (iVar1 != 0) {
        if (bcast_storm_ctrl_error_switch != 0) {
          printf("[BCAST_STORM_CTRL_ERROR]%s()/line %d : get capacity[%d] of wtp by id[%d] failed.\n"
                 ,"_uac_bcast_storm_ctrl_pkt_send_to_wtp",0x173,0xe,param_1);
        }
LAB_0045ed34:
        serv_wtp_address_arg_destroy(&local_2f8);
        return 0xffffffff;
      }
      if (local_2f0 == 0) {
        if (bcast_storm_ctrl_debug_switch != 0) {
          printf("[BCAST_STORM_CTRL_DEBUG]%s()/line %d : no wtp support capacity[%d].\n",
                 "_uac_bcast_storm_ctrl_pkt_send_to_wtp",0x17a,0xe);
        }
      }
      else {
        iVar1 = _uac_bcast_storm_ctrl_pkt_send(&local_2f8);
        if (iVar1 != 0) {
          if (bcast_storm_ctrl_error_switch != 0) {
            printf("[BCAST_STORM_CTRL_ERROR]%s()/line %d : send packet failed.\n",
                   "_uac_bcast_storm_ctrl_pkt_send_to_wtp",0x182);
          }
          goto LAB_0045ed34;
        }
      }
      serv_wtp_address_arg_destroy(&local_2f8);
      return 0;
    }
    if (bcast_storm_ctrl_error_switch != 0) {
      printf("[BCAST_STORM_CTRL_ERROR]%s()/line %d : get wtp by id[%d] failed.\n",
             "_uac_bcast_storm_ctrl_pkt_send_to_wtp",0x16c,param_1);
      return 0xffffffff;
    }
  }
  else if (bcast_storm_ctrl_error_switch != 0) {
    printf("[BCAST_STORM_CTRL_ERROR]%s()/line %d : init serv wtp argument failed.\n",
           "_uac_bcast_storm_ctrl_pkt_send_to_wtp",0x165);
    return 0xffffffff;
  }
  return 0xffffffff;
}

