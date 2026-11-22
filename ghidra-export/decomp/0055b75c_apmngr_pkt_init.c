// func apmngr_pkt_init @ 0055b75c size=764

undefined4 apmngr_pkt_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = serv_msg_mngr_register(0xd,0x78,_apmngr_pkt_echo_req_listen);
  if (iVar1 == -1) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = 
    "[APMNGR_ERROR]%s()/%d register callback to listen join-req capwap message event failed.\n";
    uVar2 = 0xc04;
  }
  else {
    iVar1 = serv_msg_mngr_register(9,0x78,_apmngr_pkt_wtp_event_req_listen);
    if (iVar1 == -1) {
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = 
      "[APMNGR_ERROR]%s()/%d register callback to listen wtp-event-req capwap message event failed.\n"
      ;
      uVar2 = 0xc09;
    }
    else {
      iVar1 = serv_msg_mngr_register(3,0x78,_apmngr_pkt_join_req_listen);
      if (iVar1 == -1) {
        if (apmngr_err_switch == '\0') {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = 
        "[APMNGR_ERROR]%s()/%d register callback to listen join-req capwap message event failed.\n";
        uVar2 = 0xc0e;
      }
      else {
        iVar1 = serv_msg_mngr_register(1,0xff,_apmngr_pkt_discover_req_listen);
        if (iVar1 == -1) {
          if (apmngr_err_switch == '\0') {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = 
          "[APMNGR_ERROR]%s()/%d register callback to listen join-req capwap message event failed.\n"
          ;
          uVar2 = 0xc13;
        }
        else {
          iVar1 = serv_msg_mngr_register(5,0x50,_apmngr_pkt_config_status_req_listen);
          if (iVar1 == -1) {
            if (apmngr_err_switch == '\0') {
              return 0xffffffff;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0xffffffff;
            }
            __format = 
            "[APMNGR_ERROR]%s()/%d register callback to listen config status req capwap message event failed.\n"
            ;
            uVar2 = 0xc18;
          }
          else {
            iVar1 = serv_ent_mngr_register(1,0x79,_apmngr_pkt_enter_run_cb);
            if (iVar1 == 0) {
              iVar1 = serv_ent_mngr_register(2,0x79,_apmngr_pkt_enter_reset_cb);
              if (iVar1 == 0) {
                iVar1 = serv_ent_mngr_register(0,0x79,_apmngr_pkt_enter_reset_cb);
                if (iVar1 == 0) {
                  iVar1 = serv_ent_mngr_register(3,0x79,_apmngr_pkt_ifindex_change_cb);
                  if (iVar1 == 0) {
                    return 0;
                  }
                  if (apmngr_err_switch == '\0') {
                    return 0xffffffff;
                  }
                  iVar1 = is_target_debug_ap();
                  if (iVar1 == 0) {
                    return 0xffffffff;
                  }
                  __format = "[APMNGR_ERROR]%s()/%d register callback to listen Enter-Run Event.\n";
                  uVar2 = 0xc2c;
                }
                else {
                  if (apmngr_err_switch == '\0') {
                    return 0xffffffff;
                  }
                  iVar1 = is_target_debug_ap();
                  if (iVar1 == 0) {
                    return 0xffffffff;
                  }
                  __format = "[APMNGR_ERROR]%s()/%d register callback to listen Enter-Run Event.\n";
                  uVar2 = 0xc27;
                }
              }
              else {
                if (apmngr_err_switch == '\0') {
                  return 0xffffffff;
                }
                iVar1 = is_target_debug_ap();
                if (iVar1 == 0) {
                  return 0xffffffff;
                }
                __format = "[APMNGR_ERROR]%s()/%d register callback to listen Enter-Reset Event.\n";
                uVar2 = 0xc22;
              }
            }
            else {
              if (apmngr_err_switch == '\0') {
                return 0xffffffff;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                return 0xffffffff;
              }
              __format = "[APMNGR_ERROR]%s()/%d register callback to listen Enter-Run Event.\n";
              uVar2 = 0xc1d;
            }
          }
        }
      }
    }
  }
  printf(__format,"apmngr_pkt_init",uVar2);
  return 0xffffffff;
}

