// func mesh_child_rd_disable @ 004ac7f0 size=1

bool mesh_child_rd_disable(void)

{
  int iVar1;
  
  iVar1 = uac_wstation_rd_disable();
  return iVar1 != 0;
}

