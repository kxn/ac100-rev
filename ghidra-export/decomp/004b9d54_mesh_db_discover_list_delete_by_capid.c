// func mesh_db_discover_list_delete_by_capid @ 004b9d54 size=292

undefined4 mesh_db_discover_list_delete_by_capid(short param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  iVar2 = FUN_004081b0(&DAT_00767f5c);
  do {
    iVar1 = iVar2;
    if (iVar1 == 0) {
      FUN_00407f30(DAT_00767eb4);
      return 0;
    }
    iVar2 = FUN_00408680(iVar1);
    iVar3 = FUN_004081b0(iVar1 + 0x58);
    while (iVar3 != 0) {
      if (*(short *)(iVar3 + 0xc) == param_1) {
        FUN_00408500(iVar3);
        FUN_00407df0(iVar3);
        break;
      }
      iVar3 = FUN_00408680();
    }
    iVar3 = FUN_00407fe0(iVar1 + 0x58);
    if (iVar3 == 0) {
      FUN_00408500(iVar1);
      FUN_00407f40(DAT_00767f68,iVar1);
      FUN_00407df0(iVar1);
    }
  } while( true );
}

