// func cw_priv_mesh_private_control_length @ 00578060 size=76

short cw_priv_mesh_private_control_length(void)

{
  int iVar1;
  short sVar2;
  
  sVar2 = 2;
  for (iVar1 = FUN_004081b0(); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
    sVar2 = sVar2 + *(short *)(iVar1 + 0xe) + 4;
  }
  return sVar2;
}

