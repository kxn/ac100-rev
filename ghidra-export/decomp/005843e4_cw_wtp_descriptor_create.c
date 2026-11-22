// func cw_wtp_descriptor_create @ 005843e4 size=656

int cw_wtp_descriptor_create(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  short sVar7;
  
  iVar2 = cw_protocol_clone(param_1,0x1c);
  if (iVar2 == 0) {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to create value\n","cw_wtp_descriptor_create",0x19b);
    }
  }
  else {
    FUN_0051ad88(iVar2 + 4);
    FUN_0051ad88(iVar2 + 0x10);
    sVar7 = 3;
    for (iVar3 = FUN_004081b0(param_1 + 4); iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
      iVar4 = cw_protocol_clone(iVar3,0x10);
      if (iVar4 == 0) {
        if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_0058453c;
        __format = "[CW_ERROR]%32s():%4d failed to clone encryption subelement\n";
        uVar6 = 0x1a8;
        goto LAB_00584604;
      }
      FUN_004086b0(iVar2 + 4,iVar4);
      sVar7 = sVar7 + 3;
    }
    iVar3 = FUN_004081b0(param_1 + 0x10);
    while( true ) {
      if (iVar3 == 0) {
        iVar3 = cw_protocol_msg_ele_create(0x27,sVar7,iVar2);
        if (iVar3 != 0) {
          return iVar3;
        }
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed t create message element\n","cw_wtp_descriptor_create"
                 ,0x1d2);
        }
        cw_wtp_descriptor_val_free(iVar2);
        return 0;
      }
      iVar4 = cw_protocol_clone(iVar3,0x18);
      if (iVar4 == 0) break;
      *(undefined4 *)(iVar4 + 0x14) = 0;
      FUN_004086b0(iVar2 + 0x10,iVar4);
      sVar1 = *(short *)(iVar4 + 0x12);
      if ((*(short *)(iVar3 + 0x12) != 0) && (*(int *)(iVar3 + 0x14) != 0)) {
        iVar5 = cw_protocol_clone();
        *(int *)(iVar4 + 0x14) = iVar5;
        if (iVar5 == 0) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_0058453c;
          __format = "[CW_ERROR]%32s():%4d failed to clone descriptor subelement data\n";
          uVar6 = 0x1c7;
          goto LAB_00584604;
        }
      }
      sVar7 = sVar7 + sVar1 + 8;
      iVar3 = FUN_00408680(iVar3);
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0058453c;
    __format = "[CW_ERROR]%32s():%4d failed to clone descriptor subelement\n";
    uVar6 = 0x1b9;
LAB_00584604:
    printf(__format,"cw_wtp_descriptor_create",uVar6);
LAB_0058453c:
    cw_wtp_descriptor_val_free(iVar2);
  }
  return 0;
}

