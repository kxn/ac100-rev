// func cw_80211_wtp_qos_create @ 0056bad0 size=220

int cw_80211_wtp_qos_create(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = cw_protocol_clone(param_1,0x2a);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_80211_wtp_qos_create",0xf5);
    }
  }
  else {
    iVar2 = cw_protocol_msg_ele_create(0x415,0x22,iVar1);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n","cw_80211_wtp_qos_create",
               0xfd);
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

