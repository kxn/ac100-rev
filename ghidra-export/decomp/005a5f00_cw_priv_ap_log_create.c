// func cw_priv_ap_log_create @ 005a5f00 size=804

int cw_priv_ap_log_create(ushort *param_1)

{
  int iVar1;
  ushort *puVar2;
  ushort uVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  int iVar6;
  
  if (0x20 < *param_1) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d log_num(%d) is too large\n","cw_priv_ap_log_create",0x115,
           (uint)*param_1);
    return 0;
  }
  puVar2 = (ushort *)cw_protocol_clone(param_1,8);
  if (puVar2 == (ushort *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_ap_log_create",0x11c);
    return 0;
  }
  puVar2[2] = 0;
  puVar2[3] = 0;
  if (*param_1 == 0) {
LAB_005a60b8:
    uVar5 = cw_priv_ap_log_length(puVar2);
    iVar1 = cw_protocol_msg_ele_create(0x5f,uVar5,puVar2);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (capwap_err_switch == 0) {
      uVar3 = *puVar2;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar3 = *puVar2;
      }
      else {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n","cw_priv_ap_log_create",
               0x14b);
        uVar3 = *puVar2;
      }
    }
LAB_005a6048:
    if ((uVar3 != 0) && (iVar1 = 0, *(int *)(puVar2 + 2) != 0)) {
      while (iVar1 < (int)(uint)*puVar2) {
        iVar4 = iVar1 * 8;
        iVar1 = iVar1 + 1;
        if (*(int *)(*(int *)(puVar2 + 2) + iVar4 + 4) != 0) {
          FUN_00407df0();
          *(undefined4 *)(*(int *)(puVar2 + 2) + iVar4 + 4) = 0;
        }
      }
      FUN_00407df0();
      puVar2[2] = 0;
      puVar2[3] = 0;
    }
  }
  else {
    if (*(int *)(param_1 + 2) == 0) {
      if ((capwap_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005a614c;
      __format = "[CW_ERROR]%32s():%4d wlan info is null\n";
      uVar5 = 0x126;
    }
    else {
      iVar1 = cw_protocol_clone(*(int *)(param_1 + 2),(*param_1 & 0x1fff) << 3);
      iVar4 = 0;
      *(int *)(puVar2 + 2) = iVar1;
      if (iVar1 != 0) {
        for (; iVar4 < (int)(uint)*param_1; iVar4 = iVar4 + 1) {
          *(undefined4 *)(*(int *)(puVar2 + 2) + iVar4 * 8 + 4) = 0;
        }
        iVar1 = 0;
        while (iVar1 < (int)(uint)*param_1) {
          iVar6 = *(int *)(puVar2 + 2);
          iVar4 = iVar1 * 8;
          uVar3 = *(ushort *)(iVar6 + iVar4 + 2);
          if (0x400 < uVar3) {
            if (capwap_err_switch == 0) {
              uVar3 = *puVar2;
            }
            else {
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                uVar3 = *puVar2;
              }
              else {
                printf("[CW_ERROR]%32s():%4d log\'s len(%d) is too large\n","cw_priv_ap_log_create",
                       0x139,(uint)*(ushort *)(*(int *)(puVar2 + 2) + iVar4 + 2));
                uVar3 = *puVar2;
              }
            }
            goto LAB_005a6048;
          }
          if (uVar3 == 0) {
            iVar1 = iVar1 + 1;
          }
          else {
            uVar5 = cw_protocol_clone(*(undefined4 *)(*(int *)(param_1 + 2) + iVar4 + 4),
                                      *(undefined2 *)(*(int *)(param_1 + 2) + iVar4 + 2));
            *(undefined4 *)(iVar6 + iVar4 + 4) = uVar5;
            if (*(int *)(*(int *)(puVar2 + 2) + iVar4 + 4) == 0) {
              uVar3 = *puVar2;
              goto LAB_005a6048;
            }
            iVar1 = iVar1 + 1;
          }
        }
        goto LAB_005a60b8;
      }
      if ((capwap_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005a614c;
      __format = "[CW_ERROR]%32s():%4d failed to clone wlan info\n";
      uVar5 = 0x12d;
    }
    printf(__format,"cw_priv_ap_log_create",uVar5);
  }
LAB_005a614c:
  FUN_00407df0(puVar2);
  return 0;
}

