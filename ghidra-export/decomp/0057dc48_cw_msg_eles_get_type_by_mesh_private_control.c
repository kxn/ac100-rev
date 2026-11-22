// func cw_msg_eles_get_type_by_mesh_private_control @ 0057dc48 size=124

void cw_msg_eles_get_type_by_mesh_private_control(int param_1,int param_2)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0)) && (iVar1 = FUN_00407fe0(param_2), iVar1 != 0)) {
    for (iVar1 = FUN_004081b0(param_2); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      msg_ele_add_sub(param_1,(int)*(short *)(iVar1 + 0xc));
    }
  }
  return;
}

