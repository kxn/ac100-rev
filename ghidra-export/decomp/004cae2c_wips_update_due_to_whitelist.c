// func wips_update_due_to_whitelist @ 004cae2c size=364

void wips_update_due_to_whitelist(int param_1,int param_2)

{
  int iVar1;
  void *__src;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = FUN_00408450((uint)g_wips_info_max_size * 0xb0,0xce3);
  FUN_004082d0(wips_global_mutex,0xffffffff);
  for (__src = (void *)FUN_004081b0(&g_wips_list); __src != (void *)0x0;
      __src = (void *)FUN_00408680(__src)) {
    iVar2 = FUN_004081b0((int)__src + 0x9c);
    if ((*(int *)(iVar2 + 0x28) + 0xfecea7fcU < 2) &&
       (iVar2 = wips_info_match(__src,*(int *)(iVar2 + 0x28),param_1 + 0x10,&DAT_00688af8,0),
       iVar2 != 0)) {
      if (param_2 == 0) {
        *(undefined4 *)((int)__src + 0xa8) = 1;
      }
      else {
        *(undefined4 *)((int)__src + 0xa8) = 2;
        if (*(int *)((int)__src + 0xac) == 1) {
          iVar2 = iVar3 * 0xb0;
          iVar3 = iVar3 + 1;
          memcpy((void *)(iVar1 + iVar2),__src,0xb0);
        }
      }
    }
  }
  FUN_00407f30(wips_global_mutex);
  if (iVar3 != 0) {
    wips_entry_counter(iVar1,iVar3,0);
  }
  FUN_00407df0(iVar1);
  return;
}

