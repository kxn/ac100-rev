// func _uac_wserv_pkt_config_status_req_listener @ 005e7d08 size=592

int _uac_wserv_pkt_config_status_req_listener(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_28 [3];
  
  local_28[0] = 0;
  if (g_wserv_debug == 0) {
    iVar2 = *(int *)(param_1 + 0x10);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x10);
    }
    else {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_pkt_config_status_req_listener() begin, req_pkt->ctrl_hdr.msg_type=%d.\r\n"
             ,"_uac_wserv_pkt_config_status_req_listener",0xc3,*(undefined4 *)(param_1 + 0x10));
      iVar2 = *(int *)(param_1 + 0x10);
    }
  }
  if (iVar2 == 5) {
    iVar2 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x1e);
    iVar4 = 0;
    if (iVar2 == 0) goto LAB_005e7d64;
    if ((g_wserv_debug != 0) && (iVar4 = is_target_debug_ap(iVar2), iVar4 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> WLAN LIST!\r\n","_uac_wserv_pkt_config_status_req_listener"
             ,0xcc);
    }
    iVar4 = _uac_wserv_pkt_wlan_list_proc(iVar2,param_1,param_2,param_3);
    if (iVar4 == 0) goto LAB_005e7d64;
    piVar1 = (int *)cw_msg_ele_val_get(param_3,0x21);
    if (piVar1 == (int *)0x0) {
      local_28[0] = 1;
      iVar2 = cw_service_msg_add(param_3,0x21,local_28,0);
      if (((iVar2 != 0) && (g_wserv_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wserv>[error]%s(): %d  -> cw_service_msg_add() fail!\r\n",
               "_uac_wserv_pkt_config_status_req_listener",0xd6);
      }
      goto LAB_005e7d64;
    }
    if (((*piVar1 == 0) || (g_wserv_error == 0)) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
    goto LAB_005e7d64;
    iVar2 = *piVar1;
    __format = "<wserv>[error]%s(): %d  -> rstl_val->result_code[%d] fail!\r\n";
    uVar3 = 0xdc;
  }
  else {
    iVar4 = 0;
    if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005e7d64;
    iVar2 = *(int *)(param_1 + 0x10);
    __format = "<wserv>[warning]%s(): %d  -> req_pkt->ctrl_hdr.msg_type = %d, ignore it.\r\n";
    uVar3 = 0xc6;
  }
  printf(__format,"_uac_wserv_pkt_config_status_req_listener",uVar3,iVar2);
LAB_005e7d64:
  if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_pkt_config_status_req_listener() finish.\r\n",
           "_uac_wserv_pkt_config_status_req_listener",0xe3);
  }
  return iVar4;
}

