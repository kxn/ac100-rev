// func uac_mesh_uninit @ 004c014c size=168

undefined4 uac_mesh_uninit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (mesh_signal != 0) {
    FUN_00408390();
  }
  iVar1 = mesh_db_uninit();
  if (iVar1 == 0) {
    iVar1 = mesh_pkt_uninit();
    if (iVar1 == 0) {
      return 0;
    }
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    uVar2 = 0x90e;
  }
  else {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    uVar2 = 0x909;
  }
  printf("[MESH_ERROR]%s()/%d mesh_db_uninit() fail!\n","uac_mesh_uninit",uVar2);
  return 0xffffffff;
}

