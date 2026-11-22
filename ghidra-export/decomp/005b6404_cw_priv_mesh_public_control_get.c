// func cw_priv_mesh_public_control_get @ 005b6404 size=1

int cw_priv_mesh_public_control_get(int param_1,short param_2)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((param_1 != 0) && (iVar2 = FUN_004081b0(param_1 + 0xc), iVar2 != 0)) {
    sVar1 = *(short *)(iVar2 + 0xc);
    while (sVar1 != param_2) {
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) {
        return 0;
      }
      sVar1 = *(short *)(iVar2 + 0xc);
    }
    iVar2 = *(int *)(iVar2 + 0x10);
  }
  return iVar2;
}

