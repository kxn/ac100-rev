// func cw_vendor_specific_payload_assemble @ 005820f8 size=748

undefined4 cw_vendor_specific_payload_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  puVar7 = *(undefined4 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*(ushort *)((int)puVar7 + 6) + 6 == (uint)*(ushort *)(param_2 + 0xe)) {
    cw_protocol_restore32(param_1,*puVar7);
    cw_protocol_restore16(param_1,*(undefined2 *)(puVar7 + 1));
    for (iVar2 = FUN_004081b0(puVar7 + 2); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
      puVar3 = (ushort *)cw_msg_ele_priv_mngr_get(*(undefined2 *)(iVar2 + 0xc));
      if (puVar3 == (ushort *)0x0) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n",
                 "cw_msg_eles_priv_assemble",0x11f,(uint)*(ushort *)(iVar2 + 0xc));
        }
LAB_00582290:
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar5 = "[CW_ERROR]%32s():%4d failed to assemble private message element\n";
        uVar6 = 500;
        goto LAB_00582190;
      }
      iVar4 = cw_msg_ele_priv_check(iVar2,puVar3);
      if (iVar4 == -1) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar5 = "[CW_ERROR]%32s():%4d capwap message element doesn\'t match manager\n";
          uVar6 = 0x125;
LAB_005822f4:
          printf(pcVar5,"cw_msg_eles_priv_assemble",uVar6);
        }
        goto LAB_00582290;
      }
      if (*(int *)(iVar2 + 0x10) == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          uVar1 = *puVar3;
          uVar8 = *(undefined4 *)(puVar3 + 2);
          pcVar5 = "[CW_ERROR]%32s():%4d %s(%d) doesn\'t have value \r\n\n";
          uVar6 = 299;
LAB_00582340:
          printf(pcVar5,"cw_msg_eles_priv_assemble",uVar6,uVar8,(uint)uVar1);
        }
        goto LAB_00582290;
      }
      if ((int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)) <
          (int)(*(ushort *)(iVar2 + 0xe) + 4)) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar5 = "[CW_ERROR]%32s():%4d packet buffer isn\'t enough\n";
          uVar6 = 0x131;
          goto LAB_005822f4;
        }
        goto LAB_00582290;
      }
      cw_msg_ele_priv_format_assemble(param_1,*(undefined2 *)(iVar2 + 0xc));
      iVar4 = (**(code **)(puVar3 + 8))(param_1,iVar2);
      if (iVar4 == -1) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          uVar1 = *puVar3;
          uVar8 = *(undefined4 *)(puVar3 + 2);
          pcVar5 = "[CW_ERROR]%32s():%4d failed to assemble %s(%d)\n";
          uVar6 = 0x139;
          goto LAB_00582340;
        }
        goto LAB_00582290;
      }
    }
    uVar8 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar8 = 0;
    }
  }
  else {
    uVar8 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      pcVar5 = "[CW_ERROR]%32s():%4d failed to write value\n";
      uVar6 = 0x1ed;
LAB_00582190:
      uVar8 = 0xffffffff;
      printf(pcVar5,"cw_vendor_specific_payload_assemble",uVar6);
    }
  }
  return uVar8;
}

