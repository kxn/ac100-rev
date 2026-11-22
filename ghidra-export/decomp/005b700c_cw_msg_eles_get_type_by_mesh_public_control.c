// func cw_msg_eles_get_type_by_mesh_public_control @ 005b700c size=164

void cw_msg_eles_get_type_by_mesh_public_control(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  
  if ((((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) &&
     (iVar2 = FUN_004081b0(param_3 + 0xc), iVar2 != 0)) {
    sVar1 = *(short *)(iVar2 + 0xc);
    while( true ) {
      if (sVar1 == 0x25) {
        cw_msg_eles_get_type_by_vendor_specific_payload
                  (param_1,param_2,*(undefined4 *)(iVar2 + 0x10));
      }
      else {
        msg_ele_add();
      }
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      sVar1 = *(short *)(iVar2 + 0xc);
    }
  }
  return;
}

