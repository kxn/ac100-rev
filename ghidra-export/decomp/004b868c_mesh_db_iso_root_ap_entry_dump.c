// func mesh_db_iso_root_ap_entry_dump @ 004b868c size=1

void mesh_db_iso_root_ap_entry_dump(void)

{
  int iVar1;
  
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  iVar1 = FUN_00407fe0(&DAT_00767f90);
  if (iVar1 == 0) {
    puts("No isolate ap nodes.\r");
  }
  else {
    _mesh_db_single_ap_entry_dump(&DAT_00767f70,0);
  }
  uac_mutex_give(DAT_00767eb4);
  return;
}

