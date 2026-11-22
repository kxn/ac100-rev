// func cw_wtp_board_data_create @ 00583534 size=528

int cw_wtp_board_data_create(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  short sVar7;
  
  iVar2 = cw_protocol_clone(param_1,0x10);
  if (iVar2 == 0) {
    iVar3 = 0;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_wtp_board_data_create",0x121);
    }
  }
  else {
    sVar7 = 4;
    FUN_0051ad88(iVar2 + 4);
    iVar3 = FUN_004081b0(param_1 + 4);
    while (iVar3 != 0) {
      iVar4 = cw_protocol_clone(iVar3,0x14);
      if (iVar4 == 0) {
        if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_00583684;
        __format = "[CW_ERROR]%32s():%4d failed to clone subelement\n";
        uVar6 = 0x12f;
LAB_005836b4:
        printf(__format,"cw_wtp_board_data_create",uVar6);
LAB_00583684:
        cw_wtp_board_data_val_free(iVar2);
        return 0;
      }
      *(undefined4 *)(iVar4 + 0x10) = 0;
      FUN_004086b0(iVar2 + 4,iVar4);
      sVar1 = *(short *)(iVar4 + 0xe);
      if ((*(short *)(iVar3 + 0xe) != 0) && (*(int *)(iVar3 + 0x10) != 0)) {
        iVar5 = cw_protocol_clone();
        *(int *)(iVar4 + 0x10) = iVar5;
        if (iVar5 == 0) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_00583684;
          __format = "[CW_ERROR]%32s():%4d failed to clone subelement data\n";
          uVar6 = 0x13d;
          goto LAB_005836b4;
        }
      }
      iVar3 = FUN_00408680(iVar3);
      sVar7 = sVar7 + sVar1 + 4;
    }
    iVar3 = cw_protocol_msg_ele_create(0x26,sVar7,iVar2);
    if (iVar3 == 0) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message element\n","cw_wtp_board_data_create",
               0x148);
      }
      cw_wtp_board_data_val_free(iVar2);
    }
  }
  return iVar3;
}

