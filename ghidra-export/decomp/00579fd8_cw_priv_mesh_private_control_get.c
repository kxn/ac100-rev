// func cw_priv_mesh_private_control_get @ 00579fd8 size=96

int cw_priv_mesh_private_control_get(int param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (((param_1 != 0) && (param_2 < 0x1c)) && (iVar2 = FUN_004081b0(), iVar2 != 0)) {
    uVar1 = *(ushort *)(iVar2 + 0xc);
    while (uVar1 != param_2) {
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) {
        return 0;
      }
      uVar1 = *(ushort *)(iVar2 + 0xc);
    }
    iVar2 = *(int *)(iVar2 + 0x10);
  }
  return iVar2;
}

