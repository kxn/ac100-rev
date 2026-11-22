// func apdb_destroy @ 00606cd8 size=208

void apdb_destroy(void)

{
  int iVar1;
  int iVar2;
  
  _apdb_free_all_db();
  iVar1 = FUN_004081b0(&l_apdb_callback_list);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0xc);
    while( true ) {
      if (iVar2 != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
      iVar1 = FUN_004081b0(&l_apdb_callback_list);
      if (iVar1 == 0) break;
      iVar2 = *(int *)(iVar1 + 0xc);
    }
  }
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : destroy callback list finished\n","_apdb_free_callback_list",
           0x149d);
  }
  if (l_apdb_mutex != 0) {
    FUN_00408360();
    l_apdb_mutex = 0;
  }
  apdb_pkt_finish();
  apdb_sync_uninit();
  return;
}

