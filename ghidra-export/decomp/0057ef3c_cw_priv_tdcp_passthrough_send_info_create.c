// func cw_priv_tdcp_passthrough_send_info_create @ 0057ef3c size=468

int cw_priv_tdcp_passthrough_send_info_create(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char *__format;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined4 *)cw_protocol_clone(param_1,0x10);
  if (puVar1 == (undefined4 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n",
           "cw_priv_tdcp_passthrough_send_info_create",0xc1);
    return 0;
  }
  puVar1[3] = 0;
  puVar1[1] = 0;
  *puVar1 = 0;
  *(undefined1 *)(puVar1 + 2) = 0;
  iVar3 = param_1[1];
  if (iVar3 == 0) {
LAB_0057efbc:
    iVar3 = cw_protocol_msg_ele_create(0x83,iVar3 + 9U & 0xffff,puVar1);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar2 = puVar1[3];
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = puVar1[3];
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_tdcp_passthrough_send_info_create",0xe0);
          iVar2 = puVar1[3];
        }
      }
      if (iVar2 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(puVar1);
    }
  }
  else {
    if (param_1[3] == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar4 = 0xcd;
LAB_0057f0dc:
        printf(__format,"cw_priv_tdcp_passthrough_send_info_create",uVar4);
      }
    }
    else {
      iVar3 = cw_protocol_clone(param_1[3],iVar3 + 1U & 0xffff);
      puVar1[3] = iVar3;
      if (iVar3 != 0) {
        puVar1[1] = param_1[1];
        *puVar1 = *param_1;
        *(undefined1 *)(puVar1 + 2) = *(undefined1 *)(param_1 + 2);
        iVar3 = param_1[1];
        goto LAB_0057efbc;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar4 = 0xd4;
        goto LAB_0057f0dc;
      }
    }
    FUN_00407df0(puVar1);
    iVar3 = 0;
  }
  return iVar3;
}

