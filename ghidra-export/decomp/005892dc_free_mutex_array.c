// func free_mutex_array @ 005892dc size=136

void free_mutex_array(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while (uVar1 < *(uint *)(l_profile + 0x28)) {
    iVar2 = uVar1 * 4;
    uVar1 = uVar1 + 1;
    if (*(int *)(*(int *)(g_write_snapshot_data + 4) + iVar2) != 0) {
      FUN_00408360();
      *(undefined4 *)(*(int *)(g_write_snapshot_data + 4) + iVar2) = 0;
    }
  }
  return;
}

