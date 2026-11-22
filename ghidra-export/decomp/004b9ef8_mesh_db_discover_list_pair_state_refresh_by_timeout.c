// func mesh_db_discover_list_pair_state_refresh_by_timeout @ 004b9ef8 size=140

undefined4 mesh_db_discover_list_pair_state_refresh_by_timeout(void)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  iVar1 = FUN_004081b0(&DAT_00767f5c);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 100);
    while( true ) {
      if (iVar2 == 1) {
        *(undefined4 *)(iVar1 + 100) = 3;
      }
      iVar1 = FUN_00408680(iVar1);
      if (iVar1 == 0) break;
      iVar2 = *(int *)(iVar1 + 100);
    }
  }
  FUN_00407f30(DAT_00767eb4);
  return 0;
}

