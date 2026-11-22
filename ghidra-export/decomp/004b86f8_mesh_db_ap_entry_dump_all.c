// func mesh_db_ap_entry_dump_all @ 004b86f8 size=1

void mesh_db_ap_entry_dump_all(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  while (iVar1 = apmngr_db_get_ap_max(), iVar3 < iVar1) {
    pcVar2 = (char *)(DAT_00767f6c + iVar3 * 8);
    if (*pcVar2 == '\0') {
      iVar3 = iVar3 + 1;
    }
    else {
      iVar1 = *(int *)(pcVar2 + 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 + 1;
      }
      else if (*(int *)(iVar1 + 0x10) == 0) {
        iVar3 = iVar3 + 1;
      }
      else {
        iVar3 = iVar3 + 1;
        _mesh_db_single_ap_entry_dump(iVar1,0);
      }
    }
  }
  iVar3 = FUN_00407fe0(&DAT_00767f90);
  if (iVar3 != 0) {
    _mesh_db_single_ap_entry_dump(&DAT_00767f70,0);
  }
  uac_mutex_give(DAT_00767eb4);
  return;
}

