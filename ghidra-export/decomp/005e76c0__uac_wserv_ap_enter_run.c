// func _uac_wserv_ap_enter_run @ 005e76c0 size=496

undefined4 _uac_wserv_ap_enter_run(uint param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined2 local_2f8;
  undefined2 local_2f6;
  undefined1 auStack_2f0 [16];
  undefined2 local_2e0;
  undefined4 local_2b0;
  undefined2 local_2ac;
  undefined2 local_2aa;
  undefined1 auStack_d8 [196];
  
  param_1 = param_1 & 0xffff;
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ap_enter_run() begin, ap_id=%d.\r\n",
           "_uac_wserv_ap_enter_run",0x1161,param_1);
  }
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f0);
  if (iVar1 == -1) {
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "<wserv>[error]%s(): %d  -> apmngr_db_entry_get_by_id() fail, ap_id=%d.\r\n";
    uVar5 = 0x1164;
  }
  else {
    local_2f8 = local_2ac;
    local_2f6 = local_2aa;
    uVar2 = uac_wservice_get_ap_radio_cnt(local_2b0,auStack_d8,&local_2f8);
    if (-1 < (int)uVar2) {
      iVar1 = uac_wservice_ap_enter_run(param_1,uVar2,param_2);
      if (iVar1 == 0) {
        uVar5 = 0;
        _uac_wserv_igmp_snooping_parameter_to_ap(local_2e0);
        _uac_wserv_igmp_query_parameter_to_ap(local_2e0);
        _uac_wserv_igmp_snooping_switch_to_ap(local_2e0);
        _uac_wserv_igmp_query_switch_to_ap(local_2e0);
        _uac_wserv_igmp_white_list_to_ap(local_2e0);
        if (g_wserv_debug == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        pcVar3 = "<wserv>[debug]%s(): %d  -> _uac_wserv_ap_enter_run() success.\r\n";
        uVar4 = 0x117c;
      }
      else {
        uVar5 = 0xffffffff;
        if (g_wserv_error == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        pcVar3 = "<wserv>[error]%s(): %d  -> uac_wservice_ap_enter_run() fail.\r\n";
        uVar4 = 0x1174;
      }
      printf(pcVar3,"_uac_wserv_ap_enter_run",uVar4);
      return uVar5;
    }
    if (g_wserv_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n";
    uVar5 = 0x116e;
    param_1 = uVar2;
  }
  printf(pcVar3,"_uac_wserv_ap_enter_run",uVar5,param_1);
  return 0xffffffff;
}

