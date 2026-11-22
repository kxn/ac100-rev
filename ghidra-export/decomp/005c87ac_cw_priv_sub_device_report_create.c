// func cw_priv_sub_device_report_create @ 005c87ac size=468

int cw_priv_sub_device_report_create(undefined2 *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  char *__format;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined2 *)cw_protocol_clone(param_1,0xc);
  if (puVar1 == (undefined2 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_sub_device_report_create",0xc1);
    return 0;
  }
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 2) = 0;
  *puVar1 = 0;
  puVar1[1] = 0;
  iVar3 = *(int *)(param_1 + 2);
  if (iVar3 == 0) {
LAB_005c882c:
    iVar3 = cw_protocol_msg_ele_create(0x80,iVar3 + 8U & 0xffff,puVar1);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar2 = *(int *)(puVar1 + 4);
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = *(int *)(puVar1 + 4);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_sub_device_report_create",0xe0);
          iVar2 = *(int *)(puVar1 + 4);
        }
      }
      if (iVar2 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(puVar1);
    }
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar4 = 0xcd;
LAB_005c894c:
        printf(__format,"cw_priv_sub_device_report_create",uVar4);
      }
    }
    else {
      iVar3 = cw_protocol_clone(*(int *)(param_1 + 4),iVar3 + 1U & 0xffff);
      *(int *)(puVar1 + 4) = iVar3;
      if (iVar3 != 0) {
        *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(param_1 + 2);
        *puVar1 = *param_1;
        puVar1[1] = param_1[1];
        iVar3 = *(int *)(param_1 + 2);
        goto LAB_005c882c;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar4 = 0xd4;
        goto LAB_005c894c;
      }
    }
    FUN_00407df0(puVar1);
    iVar3 = 0;
  }
  return iVar3;
}

