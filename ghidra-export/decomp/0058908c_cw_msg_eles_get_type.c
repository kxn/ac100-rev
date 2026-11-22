// func cw_msg_eles_get_type @ 0058908c size=240

void cw_msg_eles_get_type(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) &&
     (iVar3 = FUN_004081b0(param_3 + 0x1c), iVar3 != 0)) {
    uVar1 = *(undefined2 *)(iVar3 + 0xc);
    while( true ) {
      uVar4 = msg_ele_add(param_1,uVar1);
      sVar2 = *(short *)(iVar3 + 0xc);
      if (sVar2 == 0x25) {
        cw_msg_eles_get_type_by_vendor_specific_payload
                  (param_1,param_2,*(undefined4 *)(iVar3 + 0x10));
      }
      else if (sVar2 == 0x26) {
        cw_msg_eles_get_type_by_wtp_board(uVar4,*(undefined4 *)(iVar3 + 0x10));
      }
      else if (sVar2 == 0x27) {
        cw_msg_eles_get_type_by_wtp_descriptor(uVar4,*(undefined4 *)(iVar3 + 0x10));
      }
      iVar3 = FUN_00408680(iVar3);
      if (iVar3 == 0) break;
      uVar1 = *(undefined2 *)(iVar3 + 0xc);
    }
  }
  return;
}

