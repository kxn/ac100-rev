// func cw_priv_mesh_public_control_create @ 005b68c0 size=704

int cw_priv_mesh_public_control_create(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  if ((99 < (ushort)(*param_1 - 1)) || (*(int *)(param_1 + 2) == 0)) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d ap count(%d) is wrong or mac list is NULL\n",
           "cw_priv_mesh_public_control_create",0x14e,(uint)*param_1);
    return 0;
  }
  iVar2 = cw_protocol_clone(param_1,0x18);
  if (iVar2 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_mesh_public_control_create",0x155
          );
    return 0;
  }
  FUN_0051ad88(iVar2 + 0xc);
  iVar3 = cw_protocol_clone(*(undefined4 *)(param_1 + 2),*param_1 * 6);
  *(int *)(iVar2 + 4) = iVar3;
  if (iVar3 == 0) {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005b6a98;
    pcVar5 = "[CW_ERROR]%32s():%4d failed to malloc mac list\n";
    uVar6 = 0x15c;
  }
  else {
    *(undefined2 *)(iVar2 + 8) = 0;
    for (iVar3 = FUN_004081b0(param_1 + 6); iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
      uVar1 = *(ushort *)(iVar3 + 0xc);
      uVar6 = *(undefined4 *)(iVar3 + 0x10);
      iVar4 = cw_msg_ele_mngr_get((uint)uVar1);
      if (iVar4 == 0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          pcVar5 = "[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n";
          uVar6 = 0x16c;
LAB_005b6ad8:
          printf(pcVar5,"cw_priv_mesh_public_control_create",uVar6,(uint)uVar1);
        }
        goto LAB_005b6a98;
      }
      iVar4 = (**(code **)(iVar4 + 0x14))(uVar6);
      if (iVar4 == 0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          pcVar5 = "[CW_ERROR]%32s():%4d failed to create message element(%d)\n";
          uVar6 = 0x174;
          goto LAB_005b6ad8;
        }
        goto LAB_005b6a98;
      }
      FUN_004086b0(iVar2 + 0xc,iVar4);
      *(short *)(iVar2 + 8) = *(short *)(iVar2 + 8) + *(short *)(iVar4 + 0xe) + 4;
    }
    iVar3 = cw_protocol_msg_ele_create(0x75,*(short *)(iVar2 + 8) + 4 + *param_1 * 6,iVar2);
    if (iVar3 != 0) {
      return iVar3;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005b6a98;
    pcVar5 = "[CW_ERROR]%32s():%4d failed to create message eleemnt\n";
    uVar6 = 0x181;
  }
  printf(pcVar5,"cw_priv_mesh_public_control_create",uVar6);
LAB_005b6a98:
  cw_priv_mesh_public_control_val_destroy(iVar2);
  return 0;
}

