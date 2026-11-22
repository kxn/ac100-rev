// func _send_tdcp_request_to_ap @ 0050bc4c size=752

undefined4
_send_tdcp_request_to_ap
          (undefined4 param_1,void *param_2,int param_3,char *param_4,undefined4 param_5,int param_6
          ,int param_7)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 local_31c;
  undefined2 local_318;
  undefined4 local_314;
  undefined4 local_310;
  int local_30c;
  undefined4 local_308;
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  
  local_314 = 0;
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  memset(auStack_300,0,0x2d8);
  local_31c = 0;
  local_318 = 0;
  if (param_4 == (char *)0x0) {
    return 0xffffffff;
  }
  if (*param_4 == '\0') {
    return 0xffffffff;
  }
  if (ac_passthrough_debug_switch != '\0') {
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d _send_tdcp_request_to_ap: %s\n","_send_tdcp_request_to_ap"
           ,0x29a,param_4);
  }
  local_314 = 0;
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_314);
  if (iVar1 == 0) {
    if ((param_2 == (void *)0x0) || (iVar1 = 0, param_3 < 1)) {
      iVar2 = param_7 + 1;
      iVar1 = apmngr_db_get_all_addr_by_capacity(&local_314,1,1,param_6,iVar2,0x31,&stack0x0000001c)
      ;
      if (iVar1 != 0) {
        if (ac_passthrough_err_switch == '\0') goto LAB_0050be1c;
        __format = "[AC_PASSTHROUGH_ERROR]%s()/%d get serv argv failed.\n";
        uVar3 = 0x2b4;
        goto LAB_0050be10;
      }
    }
    else {
      do {
        memcpy(&local_31c,param_2,6);
        iVar2 = apmngr_db_entry_get_by_mac(&local_31c,auStack_300);
        if (iVar2 != 0) goto LAB_0050be1c;
        iVar1 = iVar1 + 1;
        param_2 = (void *)((int)param_2 + 6);
        iVar2 = param_6;
        apmngr_db_get_addr_by_capacity
                  (local_2f0,&local_314,1,1,param_6,param_7 + 1,0x31,&stack0x0000001c);
      } while (iVar1 != param_3);
    }
    if (ac_passthrough_debug_switch != '\0') {
      iVar2 = local_30c;
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d number of ap support capacity[%d]: %d\n",
             "_send_tdcp_request_to_ap",0x2b9,0x31,local_30c);
    }
    if (local_30c == 0) {
      if (ac_passthrough_debug_switch != '\0') {
        printf("[AC_PASSTHROUGH_DEBUG]%s()/%d no wtp support capacity[%d].\n",
               "_send_tdcp_request_to_ap",700,0x31,iVar2);
      }
      goto LAB_0050be1c;
    }
    iVar1 = ac_passthrough_send_packet_handle(param_1,&local_314,param_4,param_5);
    if (0 < iVar1) {
      serv_wtp_address_arg_destroy(&local_314);
      if (ac_passthrough_debug_switch == '\0') {
        return 0;
      }
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d send fit ap report cfg info msgele success\n",
             "_send_tdcp_request_to_ap",0x2c9);
      return 0;
    }
    if (ac_passthrough_err_switch == '\0') goto LAB_0050be1c;
    __format = "[AC_PASSTHROUGH_ERROR]%s()/%d send packet failed.\n";
    uVar3 = 0x2c3;
  }
  else {
    if (ac_passthrough_err_switch == '\0') goto LAB_0050be1c;
    __format = "[AC_PASSTHROUGH_ERROR]%s()/%d init serv argv failed.\n";
    uVar3 = 0x29e;
  }
LAB_0050be10:
  printf(__format,"_send_tdcp_request_to_ap",uVar3);
LAB_0050be1c:
  serv_wtp_address_arg_destroy(&local_314);
  return 0xffffffff;
}

