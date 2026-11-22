// func cw_msg_eles_get_type_by_vendor_specific_payload @ 00583150 size=212

void cw_msg_eles_get_type_by_vendor_specific_payload(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar4;
  
  if ((((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) &&
     (iVar2 = FUN_004081b0(param_3 + 8), iVar2 != 0)) {
    uVar1 = *(undefined2 *)(iVar2 + 0xc);
    while( true ) {
      uVar3 = msg_ele_add(param_2,uVar1);
      sVar4 = *(short *)(iVar2 + 0xc);
      if (sVar4 == 0x75) {
        cw_msg_eles_get_type_by_mesh_public_control(param_1,param_2,*(undefined4 *)(iVar2 + 0x10));
        sVar4 = *(short *)(iVar2 + 0xc);
      }
      if (sVar4 == 0x76) {
        cw_msg_eles_get_type_by_mesh_private_control(uVar3,*(undefined4 *)(iVar2 + 0x10));
      }
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      uVar1 = *(undefined2 *)(iVar2 + 0xc);
    }
  }
  return;
}

