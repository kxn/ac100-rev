// func tdcp_mutex_init @ 005121f8 size=432

undefined4 tdcp_mutex_init(void)

{
  char *__format;
  undefined4 uVar1;
  
  tdcp_from_ap_mutex = FUN_00407f00("tdcp_from_ap_mutex",0);
  if (tdcp_from_ap_mutex == 0) {
    if (tdcp_err_switch == 0) goto LAB_005122c4;
    __format = "[TDCP_ERROR]%s()/%d Create tdcp_from_ap_mutex msg mutex failed.\n";
    uVar1 = 0x421;
  }
  else {
    tdcp_to_ap_mutex = FUN_00407f00("tdcp_to_ap_mutex",0);
    if (tdcp_to_ap_mutex == 0) {
      if (tdcp_err_switch == 0) goto LAB_005122c4;
      __format = "[TDCP_ERROR]%s()/%d Create tdcp_to_ap_mutex msg mutex failed.\n";
      uVar1 = 0x428;
    }
    else {
      tdcp_waiting_response_mutex = FUN_00407f00("tdcp_waiting_response_mutex",0);
      if (tdcp_waiting_response_mutex == 0) {
        if (tdcp_err_switch == 0) goto LAB_005122c4;
        __format = "[TDCP_ERROR]%s()/%d Create tdcp_waiting_response_mutex msg mutex failed.\n";
        uVar1 = 0x42f;
      }
      else {
        tdcp_send_request_id_mutex = FUN_00407f00("tdcp_send_request_id_mutex",0);
        if (tdcp_send_request_id_mutex == 0) {
          if (tdcp_err_switch == 0) goto LAB_005122c4;
          __format = "[TDCP_ERROR]%s()/%d Create tdcp_send_request_id_mutex msg mutex failed.\n";
          uVar1 = 0x436;
        }
        else {
          tdcp_from_ap_cond = FUN_00407d80("tdcp_from_ap_cond");
          if (tdcp_from_ap_cond == 0) {
            if (tdcp_err_switch == 0) goto LAB_005122c4;
            __format = "[TDCP_ERROR]%s()/%d Create tdcp_from_ap_cond failed.\n";
            uVar1 = 0x43d;
          }
          else {
            tdcp_to_ap_cond = FUN_00407d80("tdcp_to_ap_cond");
            if (tdcp_to_ap_cond != 0) {
              return 0;
            }
            tdcp_to_ap_cond = 0;
            if (tdcp_err_switch == 0) goto LAB_005122c4;
            __format = "[TDCP_ERROR]%s()/%d Create tdcp_to_ap_cond failed.\n";
            uVar1 = 0x444;
          }
        }
      }
    }
  }
  printf(__format,"tdcp_mutex_init",uVar1);
LAB_005122c4:
  tdcp_fini();
  return 0xffffffff;
}

