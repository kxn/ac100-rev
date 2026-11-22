// func mesh_db_single_ap_entry_dump @ 004b87bc size=120

void mesh_db_single_ap_entry_dump(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  pcVar2 = (char *)(DAT_00767f6c + param_1 * 8);
  if ((*pcVar2 != '\0') && (iVar1 = *(int *)(pcVar2 + 4), iVar1 != 0)) {
    _mesh_db_single_ap_entry_dump(iVar1,0);
  }
  FUN_00407f30(DAT_00767eb4);
  return;
}

