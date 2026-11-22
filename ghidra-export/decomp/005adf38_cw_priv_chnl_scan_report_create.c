// func cw_priv_chnl_scan_report_create @ 005adf38 size=452

int cw_priv_chnl_scan_report_create(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  
  if ((*param_1 == 0) || (*(int *)(param_1 + 4) != 0)) {
    pbVar1 = (byte *)cw_protocol_clone(param_1,8);
    if (pbVar1 != (byte *)0x0) {
      *pbVar1 = *param_1;
      iVar2 = cw_protocol_clone(*(undefined4 *)(param_1 + 4),(uint)*param_1 * 9);
      *(int *)(pbVar1 + 4) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to clone chnl list\n",
                 "cw_priv_chnl_scan_report_create",0xe8);
        }
        FUN_00407df0(pbVar1);
        return 0;
      }
      iVar2 = cw_protocol_msg_ele_create(0x9c,(uint)*pbVar1 * 9,pbVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (capwap_err_switch == 0) {
        iVar2 = *(int *)(pbVar1 + 4);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(pbVar1 + 4);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_chnl_scan_report_create",0xf2);
          iVar2 = *(int *)(pbVar1 + 4);
        }
      }
      if (iVar2 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(pbVar1);
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d failed to clone value\n";
    uVar3 = 0xe0;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d chnl list is null\n";
    uVar3 = 0xd9;
  }
  printf(__format,"cw_priv_chnl_scan_report_create",uVar3);
  return 0;
}

