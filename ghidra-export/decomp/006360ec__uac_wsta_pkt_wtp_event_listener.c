// func _uac_wsta_pkt_wtp_event_listener @ 006360ec size=740

undefined4
_uac_wsta_pkt_wtp_event_listener(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  piVar1 = (int *)cw_msg_ele_val_get(param_3,0x21);
  if (piVar1 == (int *)0x0) {
    local_20[0] = 0;
    iVar3 = cw_service_msg_add(param_3,0x21,local_20,0);
    if (iVar3 != 0) {
      uVar2 = 0;
      if ((g_wsta_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("<wsta>[error]%s(): %d  -> cw_service_msg_add() fail!\r\n",
               "_uac_wsta_pkt_wtp_event_listener",0x39d);
      }
      goto LAB_006361c8;
    }
  }
  else if (*piVar1 != 0) {
    if (g_wsta_error == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    printf("<wsta>[error]%s(): %d  -> rstl_val->result_code[%d] fail!\r\n",
           "_uac_wsta_pkt_wtp_event_listener",0x3a3,*piVar1);
    return 0;
  }
  iVar3 = cw_msg_ele_val_get(param_1,0x33);
  if (iVar3 == 0) {
    iVar3 = cw_msg_ele_val_get(param_1,0x34);
    if (iVar3 == 0) {
      iVar3 = cw_msg_ele_priv_val_get_from_pkt(param_1,2);
      if (iVar3 == 0) {
        iVar3 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x8a);
        if (iVar3 == 0) {
          iVar3 = cw_msg_ele_priv_val_get_from_pkt(param_1,3);
          if (iVar3 == 0) {
            iVar3 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x4d);
            uVar2 = 0;
            if (iVar3 != 0) {
              DAT_007cc684 = DAT_007cc684 + 1;
              uVar2 = _uac_wsta_pkt_ip_report(iVar3,param_1,param_2,param_3);
            }
          }
          else {
            DAT_007cc680 = DAT_007cc680 + 1;
            uVar2 = _uac_wsta_pkt_deassocicate(iVar3,param_1,param_2,param_3);
          }
        }
        else {
          if (*(char *)(iVar3 + 0xc) == '\0') {
            DAT_007cc678 = DAT_007cc678 + 1;
          }
          else {
            DAT_007cc67c = DAT_007cc67c + 1;
          }
          uVar2 = _uac_wsta_pkt_associcate_new(iVar3,param_1,param_2,param_3);
        }
      }
      else {
        DAT_007cc678 = DAT_007cc678 + 1;
        uVar2 = _uac_wsta_pkt_associcate(iVar3,param_1,param_2,param_3);
      }
    }
    else {
      DAT_007cc674 = DAT_007cc674 + 1;
      uVar2 = _uac_wsta_pkt_sta_info_list(iVar3,param_1,param_2,param_3);
    }
  }
  else {
    l_wsta_pkt_info_stat = l_wsta_pkt_info_stat + 1;
    uVar2 = _uac_wsta_pkt_rssi_report(iVar3,param_1,param_2,param_3);
  }
LAB_006361c8:
  if ((g_wsta_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_pkt_wtp_event_listener() finish.\r\n",
           "_uac_wsta_pkt_wtp_event_listener",0x3cf);
  }
  return uVar2;
}

