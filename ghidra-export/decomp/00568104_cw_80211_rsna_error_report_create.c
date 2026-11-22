// func cw_80211_rsna_error_report_create @ 00568104 size=220

int cw_80211_rsna_error_report_create(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = cw_protocol_clone(param_1,0x28);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_80211_rsna_error_report_create",0xf1
            );
    }
  }
  else {
    iVar2 = cw_protocol_msg_ele_create(0x40b,0x28,iVar1);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
               "cw_80211_rsna_error_report_create",0xf9);
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

