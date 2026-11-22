// func cw_priv_ap_log_report_para_create @ 005a6628 size=240

int cw_priv_ap_log_report_para_create(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = cw_protocol_clone(param_1,0x1c);
  if (iVar1 == 0) {
    iVar3 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_ap_log_report_para_create",0xbd
            );
    }
  }
  else {
    uVar2 = 0xd;
    if (*(char *)(iVar1 + 4) != '\x01') {
      uVar2 = 0x19;
    }
    iVar3 = cw_protocol_msg_ele_create(0x60,uVar2,iVar1);
    if (iVar3 == 0) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
               "cw_priv_ap_log_report_para_create",0xc5);
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar3;
}

