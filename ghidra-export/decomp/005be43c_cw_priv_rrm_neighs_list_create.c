// func cw_priv_rrm_neighs_list_create @ 005be43c size=576

int cw_priv_rrm_neighs_list_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  int iVar6;
  
  iVar1 = cw_protocol_clone(param_1,8);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_rrm_neighs_list_create",0x149);
    }
  }
  else {
    if (*(short *)(iVar1 + 2) != 0) {
      iVar2 = cw_protocol_clone(*(undefined4 *)(param_1 + 4),*(short *)(iVar1 + 2) * 0xc);
      iVar4 = 0;
      *(int *)(iVar1 + 4) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          __format = "[CW_ERROR]%32s():%4d failed to malloc neighbor list\n";
          uVar5 = 0x151;
LAB_005be5b0:
          printf(__format,"cw_priv_rrm_neighs_list_create",uVar5);
        }
LAB_005be580:
        cw_priv_rrm_neighs_list_val_free(iVar1);
        return 0;
      }
      for (; iVar4 < (int)(uint)*(ushort *)(iVar1 + 2); iVar4 = iVar4 + 1) {
        *(undefined4 *)(*(int *)(iVar1 + 4) + iVar4 * 0xc + 8) = 0;
      }
      for (iVar2 = 0; iVar4 = iVar2 * 0xc, iVar2 < (int)(uint)*(ushort *)(iVar1 + 2);
          iVar2 = iVar2 + 1) {
        iVar6 = *(int *)(iVar1 + 4);
        iVar3 = *(int *)(param_1 + 4) + iVar4;
        uVar5 = cw_protocol_clone(*(undefined4 *)(iVar3 + 8),(uint)*(byte *)(iVar3 + 7) * 3);
        *(undefined4 *)(iVar6 + iVar4 + 8) = uVar5;
        if (*(int *)(*(int *)(iVar1 + 4) + iVar4 + 8) == 0) {
          if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_005be580;
          __format = "[CW_ERROR]%32s():%4d failed to malloc neighbor\'s rssi list\n";
          uVar5 = 0x15e;
          goto LAB_005be5b0;
        }
      }
    }
    uVar5 = cw_priv_rrm_neighs_list_length(iVar1);
    iVar2 = cw_protocol_msg_ele_create(0x5d,uVar5,iVar1);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
               "cw_priv_rrm_neighs_list_create",0x168);
      }
      cw_priv_rrm_neighs_list_val_free(iVar1);
    }
  }
  return iVar2;
}

