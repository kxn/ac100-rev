// func cw_priv_mac_filter_create @ 005b56fc size=452

int cw_priv_mac_filter_create(int *param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  
  piVar2 = (int *)cw_protocol_clone(param_1,0xc);
  if (piVar2 == (int *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_mac_filter_create",199);
    return 0;
  }
  piVar2[2] = 0;
  if (*param_1 == 0) {
    bVar1 = *(byte *)(piVar2 + 1);
LAB_005b575c:
    iVar3 = cw_protocol_msg_ele_create(0x3f,(uint)(bVar1 >> 3) * *piVar2 + 8 & 0xffff,piVar2);
    if (iVar3 == 0) {
      if (capwap_err_switch == 0) {
        iVar4 = piVar2[2];
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          iVar4 = piVar2[2];
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                 "cw_priv_mac_filter_create",0xe2);
          iVar4 = piVar2[2];
        }
      }
      if (iVar4 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(piVar2);
    }
  }
  else {
    if (param_1[2] == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d data is null\n";
        uVar5 = 0xd1;
LAB_005b588c:
        printf(__format,"cw_priv_mac_filter_create",uVar5);
      }
    }
    else {
      iVar3 = cw_protocol_clone(param_1[2],(uint)(*(byte *)(param_1 + 1) >> 3) * *param_1 & 0xffff);
      piVar2[2] = iVar3;
      if (iVar3 != 0) {
        bVar1 = *(byte *)(piVar2 + 1);
        goto LAB_005b575c;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        __format = "[CW_ERROR]%32s():%4d failed to clone data\n";
        uVar5 = 0xd8;
        goto LAB_005b588c;
      }
    }
    FUN_00407df0(piVar2);
    iVar3 = 0;
  }
  return iVar3;
}

