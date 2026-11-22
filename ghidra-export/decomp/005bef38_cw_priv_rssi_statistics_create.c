// func cw_priv_rssi_statistics_create @ 005bef38 size=436

int cw_priv_rssi_statistics_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x10) == 0) ||
     ((iVar3 = 0, *(int *)(param_1 + 0x14) != 0 && (*(uint *)(param_1 + 0x10) < 0x191)))) {
    iVar1 = cw_protocol_clone(param_1,0x18);
    if (iVar1 == 0) {
      iVar3 = 0;
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_rssi_statistics_create",0x103
              );
      }
    }
    else {
      *(undefined4 *)(iVar1 + 0x14) = 0;
      if (*(int *)(param_1 + 0x10) == 0) {
        iVar3 = *(int *)(iVar1 + 0x10);
      }
      else if (*(int *)(param_1 + 0x14) == 0) {
        iVar3 = *(int *)(iVar1 + 0x10);
      }
      else {
        iVar3 = cw_protocol_clone(*(int *)(param_1 + 0x14),*(int *)(param_1 + 0x10) * 0xe & 0xfffe);
        *(int *)(iVar1 + 0x14) = iVar3;
        if (iVar3 == 0) {
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d failed to clone sta_list\n",
                   "cw_priv_rssi_statistics_create",0x10e);
          }
          FUN_00407df0(iVar1);
          return 0;
        }
        iVar3 = *(int *)(iVar1 + 0x10);
      }
      iVar3 = cw_protocol_msg_ele_create(0x53,iVar3 * 0xe + 0x14U & 0xfffe,iVar1);
      if (iVar3 == 0) {
        if (capwap_err_switch == 0) {
          iVar2 = *(int *)(iVar1 + 0x14);
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            iVar2 = *(int *)(iVar1 + 0x14);
          }
          else {
            printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
                   "cw_priv_rssi_statistics_create",0x118);
            iVar2 = *(int *)(iVar1 + 0x14);
          }
        }
        if (iVar2 != 0) {
          FUN_00407df0();
        }
        FUN_00407df0(iVar1);
      }
    }
  }
  return iVar3;
}

