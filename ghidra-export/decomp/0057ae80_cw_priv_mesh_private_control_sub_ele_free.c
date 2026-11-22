// func cw_priv_mesh_private_control_sub_ele_free @ 0057ae80 size=440

undefined4 cw_priv_mesh_private_control_sub_ele_free(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_1 == 0) {
    uVar5 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n",
             "cw_priv_mesh_private_control_sub_ele_free",0x977);
    }
  }
  else {
    while (iVar1 = FUN_004081b0(param_1), iVar1 != 0) {
      FUN_00408500(iVar1);
      iVar4 = *(int *)(iVar1 + 0x10);
      if (iVar4 == 0) goto LAB_0057af18;
      switch(*(short *)(iVar1 + 0xc) + -1) {
      case 0:
      case 1:
      case 5:
      case 6:
      case 7:
      case 8:
      case 10:
      case 0xe:
      case 0x12:
      case 0x13:
      case 0x15:
        iVar4 = *(int *)(iVar4 + 4);
        goto LAB_0057af00;
      case 3:
      case 4:
        while (iVar2 = FUN_004081b0(iVar4 + 8), iVar2 != 0) {
          iVar3 = cw_msg_ele_mngr_get(*(undefined2 *)(iVar2 + 0xc));
          if (iVar3 == 0) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0xffffffff;
            }
            printf("[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n",
                   "cw_priv_mesh_private_control_sub_ele_free",0x9ad,(uint)*(ushort *)(iVar2 + 0xc))
            ;
            return 0xffffffff;
          }
          FUN_00408500(iVar2);
          (**(code **)(iVar3 + 0x18))(iVar2);
          FUN_00407df0(iVar2);
        }
        break;
      case 9:
        if (*(int *)(iVar4 + 0x24) == 0) {
          iVar4 = *(int *)(iVar4 + 0x2c);
        }
        else {
          FUN_00407df0();
          iVar4 = *(int *)(iVar4 + 0x2c);
        }
LAB_0057af00:
        if (iVar4 != 0) {
          FUN_00407df0();
        }
      }
      FUN_00407df0(*(undefined4 *)(iVar1 + 0x10));
LAB_0057af18:
      FUN_00407df0(iVar1);
    }
    uVar5 = 0;
  }
  return uVar5;
}

