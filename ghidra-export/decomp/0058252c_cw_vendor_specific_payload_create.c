// func cw_vendor_specific_payload_create @ 0058252c size=832

int cw_vendor_specific_payload_create(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  iVar2 = cw_protocol_clone(param_1,0x14);
  if (iVar2 == 0) {
    iVar3 = 0;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_vendor_specific_payload_create",
             0x20c);
    }
  }
  else {
    FUN_0051ad88(iVar2 + 8);
    *(undefined2 *)(iVar2 + 6) = 0;
    if (param_1 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        pcVar6 = "[CW_ERROR]%32s():%4d input parameter is wrong\n";
        uVar7 = 0x149;
LAB_00582634:
        printf(pcVar6,"cw_msg_eles_priv_clone",uVar7);
      }
LAB_00582640:
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(iVar2), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to clone private message element\n",
               "cw_vendor_specific_payload_create",0x214);
      }
      iVar3 = 0;
      cw_msg_eles_priv_free(iVar2);
      FUN_00407df0(iVar2);
    }
    else {
      for (iVar3 = FUN_004081b0(param_1 + 8); iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
        puVar4 = (ushort *)cw_msg_ele_priv_mngr_get(*(undefined2 *)(iVar3 + 0xc));
        if (puVar4 == (ushort *)0x0) {
          if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n",
                   "cw_msg_eles_priv_clone",0x156,(uint)*(ushort *)(iVar3 + 0xc));
          }
          goto LAB_00582640;
        }
        iVar5 = cw_msg_ele_priv_check(iVar3,puVar4);
        if (iVar5 == -1) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_00582640;
          pcVar6 = "[CW_ERROR]%32s():%4d capwap message element doesn\'t match manager\n";
          uVar7 = 0x15c;
          goto LAB_00582634;
        }
        if (*(int *)(iVar3 + 0x10) == 0) {
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            uVar1 = *puVar4;
            uVar8 = *(undefined4 *)(puVar4 + 2);
            pcVar6 = "[CW_ERROR]%32s():%4d %s(%d) doesn\'t have value\n";
            uVar7 = 0x162;
LAB_005827bc:
            printf(pcVar6,"cw_msg_eles_priv_clone",uVar7,uVar8,(uint)uVar1);
          }
          goto LAB_00582640;
        }
        iVar5 = (**(code **)(puVar4 + 10))();
        if (iVar5 == 0) {
          if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            uVar1 = *puVar4;
            uVar8 = *(undefined4 *)(puVar4 + 2);
            pcVar6 = "[CW_ERROR]%32s():%4d failed to dump %s(%d)\n";
            uVar7 = 0x169;
            goto LAB_005827bc;
          }
          goto LAB_00582640;
        }
        FUN_004086b0(iVar2 + 8,iVar5);
        *(short *)(iVar2 + 6) = *(short *)(iVar2 + 6) + *(short *)(iVar5 + 0xe) + 4;
      }
      iVar3 = cw_protocol_msg_ele_create(0x25,*(short *)(iVar2 + 6) + 6,iVar2);
      if (iVar3 == 0) {
        if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to create message element\n",
                 "cw_vendor_specific_payload_create",0x21e);
        }
        cw_msg_eles_priv_free(iVar2);
        FUN_00407df0(iVar2);
      }
    }
  }
  return iVar3;
}

