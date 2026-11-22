// func cw_sub_msg_ele_get @ 00562a54 size=216

undefined4 cw_sub_msg_ele_get(int param_1,ushort param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 != 0) && (iVar1 = cw_msg_ele_get(param_1,param_2), iVar1 != 0)) {
    if (param_2 == 0x25) {
      uVar2 = cw_msg_ele_priv_get(*(undefined4 *)(iVar1 + 0x10),param_3);
      return uVar2;
    }
    if (param_2 < 0x26) {
      if (param_2 == 1) {
        uVar2 = cw_ac_descriptor_subelement_get(*(undefined4 *)(iVar1 + 0x10),param_3);
        return uVar2;
      }
    }
    else {
      if (param_2 == 0x26) {
        uVar2 = cw_wtp_board_data_subelement_get(*(undefined4 *)(iVar1 + 0x10),param_3);
        return uVar2;
      }
      if (param_2 == 0x27) {
        uVar2 = cw_wtp_descriptor_subdescelement_get(*(undefined4 *)(iVar1 + 0x10),param_3);
        return uVar2;
      }
    }
  }
  return 0;
}

