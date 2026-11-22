// func cw_80211_supported_rates_create @ 00569808 size=224

int cw_80211_supported_rates_create(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = cw_protocol_clone(param_1,10);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_80211_supported_rates_create",0xb0);
    }
  }
  else {
    iVar2 = cw_protocol_msg_ele_create(0x410,*(byte *)(iVar1 + 1) + 1,iVar1);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
               "cw_80211_supported_rates_create",0xb8);
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

