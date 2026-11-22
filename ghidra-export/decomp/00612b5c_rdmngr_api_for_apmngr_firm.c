// func rdmngr_api_for_apmngr_firm @ 00612b5c size=304

undefined4 rdmngr_api_for_apmngr_firm(int param_1)

{
  undefined2 uVar3;
  int iVar1;
  int iVar2;
  undefined4 uVar4;
  undefined4 local_18;
  
  local_18 = 0;
  if (param_1 == 0) {
    uVar4 = 0xffffffff;
    if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d Invalid ap entry.\n","rdmngr_api_for_apmngr_firm",0xa9);
    }
  }
  else {
    if (rdmngr_debug_switch == 0) {
      uVar3 = *(undefined2 *)(param_1 + 0x44);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar3 = *(undefined2 *)(param_1 + 0x44);
      }
      else {
        printf("[RDMNGR_DEBUG]%s()/%d in rdmngr_api_for_apmngr_firm().\n",
               "rdmngr_api_for_apmngr_firm",0xad);
        uVar3 = *(undefined2 *)(param_1 + 0x44);
      }
    }
    local_18 = CONCAT22(uVar3,*(undefined2 *)(param_1 + 0x46));
    iVar1 = rdmngr_db_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_18);
    if (iVar1 < 0) {
      uVar4 = 0xffffffff;
      if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n",
               "rdmngr_api_for_apmngr_firm",0xb5,iVar1);
      }
    }
    else {
      uVar4 = 0;
      rdmngr_db_ap_firm(*(undefined2 *)(param_1 + 0x10),iVar1);
    }
  }
  return uVar4;
}

