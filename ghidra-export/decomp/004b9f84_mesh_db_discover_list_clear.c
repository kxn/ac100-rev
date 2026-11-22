// func mesh_db_discover_list_clear @ 004b9f84 size=184

undefined4 mesh_db_discover_list_clear(void)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  while (iVar1 = FUN_004081b0(&DAT_00767f5c), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407f40(DAT_00767f68,iVar1);
    while (iVar2 = FUN_004081b0(iVar1 + 0x58), iVar2 != 0) {
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
    }
  }
  FUN_00407f30(DAT_00767eb4);
  return 0;
}

