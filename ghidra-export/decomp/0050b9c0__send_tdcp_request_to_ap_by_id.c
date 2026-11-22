// func _send_tdcp_request_to_ap_by_id @ 0050b9c0 size=652

undefined4
_send_tdcp_request_to_ap_by_id
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,char *param_5,
          undefined4 param_6,int param_7)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  if (param_5 == (char *)0x0) {
    return 0xffffffff;
  }
  if (*param_5 == '\0') {
    return 0xffffffff;
  }
  if (ac_passthrough_debug_switch != '\0') {
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d _send_tdcp_request_to_ap: %s\n",
           "_send_tdcp_request_to_ap_by_id",0x2de,param_5);
  }
  iVar1 = serv_wtp_address_arg_init(&local_34);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      iVar1 = apmngr_db_get_addr_by_capacity
                        (param_3,&local_34,1,1,param_4,param_7 + 1,0x31,&stack0x0000001c);
      if (iVar1 == 0) {
LAB_0050bb84:
        if (ac_passthrough_debug_switch != '\0') {
          printf("[AC_PASSTHROUGH_DEBUG]%s()/%d number of ap to send: %d\n",
                 "_send_tdcp_request_to_ap_by_id",0x2f7,local_2c);
        }
        if (local_2c == 0) {
          uVar3 = 0;
          if (ac_passthrough_debug_switch == '\0') goto LAB_0050ba4c;
          __format = "[AC_PASSTHROUGH_DEBUG]%s()/%d no wtp to send.\n";
          uVar2 = 0x2fa;
        }
        else {
          iVar1 = ac_passthrough_send_packet_handle(param_1,&local_34,param_5,param_6);
          if (0 < iVar1) {
            serv_wtp_address_arg_destroy(&local_34);
            if (ac_passthrough_debug_switch == '\0') {
              return 0;
            }
            printf("[AC_PASSTHROUGH_DEBUG]%s()/%d send fit ap report cfg info msgele success\n",
                   "_send_tdcp_request_to_ap_by_id",0x308);
            return 0;
          }
          uVar3 = 0xffffffff;
          if (ac_passthrough_err_switch == '\0') goto LAB_0050ba4c;
          __format = "[AC_PASSTHROUGH_ERROR]%s()/%d send packet failed.\n";
          uVar2 = 0x302;
        }
      }
      else {
        uVar3 = 0xffffffff;
        if (ac_passthrough_err_switch == '\0') goto LAB_0050ba4c;
        __format = "[AC_PASSTHROUGH_ERROR]%s()/%d get serv argv failed.\n";
        uVar2 = 0x2e9;
      }
    }
    else {
      iVar1 = apmngr_db_get_all_addr_by_capacity
                        (&local_34,1,1,param_4,param_7 + 1,0x31,&stack0x0000001c);
      if (iVar1 == 0) goto LAB_0050bb84;
      uVar3 = 0xffffffff;
      if (ac_passthrough_err_switch == '\0') goto LAB_0050ba4c;
      __format = "[AC_PASSTHROUGH_ERROR]%s()/%d get serv argv failed.\n";
      uVar2 = 0x2f2;
    }
  }
  else {
    uVar3 = 0xffffffff;
    if (ac_passthrough_err_switch == '\0') goto LAB_0050ba4c;
    __format = "[AC_PASSTHROUGH_ERROR]%s()/%d init serv argv failed.\n";
    uVar2 = 0x2e1;
  }
  printf(__format,"_send_tdcp_request_to_ap_by_id",uVar2);
LAB_0050ba4c:
  serv_wtp_address_arg_destroy(&local_34);
  return uVar3;
}

