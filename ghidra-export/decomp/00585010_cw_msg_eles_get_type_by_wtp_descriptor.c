// func cw_msg_eles_get_type_by_wtp_descriptor @ 00585010 size=112

void cw_msg_eles_get_type_by_wtp_descriptor(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    for (iVar1 = FUN_004081b0(param_2 + 0x10); (iVar1 != 0 && (*(ushort *)(iVar1 + 0x10) < 4));
        iVar1 = FUN_00408680(iVar1)) {
      msg_ele_add_sub(param_1,(int)(short)*(ushort *)(iVar1 + 0x10));
    }
  }
  return;
}

