// func mesh_db_uninit @ 004babd8 size=220

undefined4 mesh_db_uninit(void)

{
  int iVar1;
  int iVar2;
  
  if (l_mesh_data != 0) {
    if (DAT_00767eb4 != 0) {
      FUN_00408360();
      DAT_00767eb4 = 0;
    }
    if (DAT_00767f68 != 0) {
      FUN_00408310();
    }
    iVar2 = 0;
    if (DAT_00767f6c != 0) {
      while (iVar1 = apmngr_db_get_ap_max(), iVar2 < iVar1) {
        iVar1 = iVar2 * 8;
        iVar2 = iVar2 + 1;
        if (*(int *)(DAT_00767f6c + iVar1 + 4) != 0) {
          FUN_00407df0();
          *(undefined4 *)(DAT_00767f6c + iVar1 + 4) = 0;
        }
      }
      FUN_00407df0(DAT_00767f6c);
    }
    l_mesh_data = 0;
    DAT_00767f58 = 0;
  }
  return 0;
}

