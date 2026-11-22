// func cw_priv_ap_firmware_id_create @ 005a4afc size=408

int cw_priv_ap_firmware_id_create(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  
  iVar2 = cw_protocol_clone(param_1,0x18);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_ap_firmware_id_create",0xc5);
    return 0;
  }
  *(undefined4 *)(iVar2 + 0x14) = 0;
  if (*(byte *)(param_1 + 0x10) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x10);
LAB_005a4b50:
    iVar3 = cw_protocol_msg_ele_create(0x5b,(uint)bVar1 * 0x10 + 0x11,iVar2);
    if (iVar3 == 0) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
               "cw_priv_ap_firmware_id_create",0xdd);
      }
      FUN_00407df0(iVar2);
    }
  }
  else {
    if (*(int *)(param_1 + 0x14) == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d bl firmware list is null\n";
        uVar5 = 0xcd;
LAB_005a4c60:
        printf(__format,"cw_priv_ap_firmware_id_create",uVar5);
      }
    }
    else {
      iVar3 = cw_protocol_clone(*(int *)(param_1 + 0x14),(uint)*(byte *)(param_1 + 0x10) << 4);
      *(int *)(iVar2 + 0x14) = iVar3;
      if (iVar3 != 0) {
        bVar1 = *(byte *)(iVar2 + 0x10);
        goto LAB_005a4b50;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone bl firmware list\n";
        uVar5 = 0xd4;
        goto LAB_005a4c60;
      }
    }
    FUN_00407df0(iVar2);
    iVar3 = 0;
  }
  return iVar3;
}

