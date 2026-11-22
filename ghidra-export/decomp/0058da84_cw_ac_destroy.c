// func cw_ac_destroy @ 0058da84 size=544

undefined4 cw_ac_destroy(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = ac;
  if (ac != 0) {
    if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_DEBUG]%32s():%4d ac[%p] free.\n","cw_ac_destroy",0xc56,iVar1);
    }
    for (uVar3 = 0; uVar3 < *(uint *)(ac + 0x18); uVar3 = uVar3 + 1) {
      cw_ac_data_destroy(*(int *)(ac + 0x1c) + uVar3 * 0xa0);
    }
    FUN_00407df0(*(undefined4 *)(ac + 0x1c));
    FUN_00407df0(*(undefined4 *)(ac + 0x20));
    if (*(int *)(ac + 0xc) != -1) {
      close(*(int *)(ac + 0xc));
    }
    FUN_00407df0(ac);
    ac = 0;
    ac_session_global_deinit();
    uVar3 = 0;
    if (g_write_snapshot_data != (int *)0x0) {
      for (; uVar3 < *(uint *)(l_profile + 0x28); uVar3 = uVar3 + 1) {
        snapshot_list_destroy(*g_write_snapshot_data + uVar3 * 0xc);
      }
      if (*g_write_snapshot_data == 0) {
        iVar1 = g_write_snapshot_data[1];
      }
      else {
        FUN_00407df0();
        *g_write_snapshot_data = 0;
        iVar1 = g_write_snapshot_data[1];
      }
      if (iVar1 != 0) {
        free_mutex_array();
        FUN_00407df0(g_write_snapshot_data[1]);
        g_write_snapshot_data[1] = 0;
      }
      if (g_write_snapshot_data[2] == 0) {
        iVar1 = g_write_snapshot_data[6];
      }
      else {
        FUN_00408360();
        g_write_snapshot_data[2] = 0;
        iVar1 = g_write_snapshot_data[6];
      }
      if (iVar1 != 0) {
        FUN_00407df0();
        g_write_snapshot_data[6] = 0;
      }
      if ((FILE *)g_write_snapshot_data[7] != (FILE *)0x0) {
        fclose((FILE *)g_write_snapshot_data[7]);
      }
      if (g_write_snapshot_data[4] != 0) {
        FUN_00408220();
        g_write_snapshot_data[4] = 0;
      }
      FUN_00407df0(g_write_snapshot_data);
      g_write_snapshot_data = (int *)0x0;
    }
  }
  return 0;
}

