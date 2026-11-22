// func cw_ac_thread_stat_reset @ 0058cc9c size=116

void cw_ac_thread_stat_reset(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ac;
  if (*(uint *)(ac + 0x18) <= param_1) {
    puts("ac thread\'s index is wrong");
    return;
  }
  iVar2 = param_1 * 0xa0;
  *(undefined4 *)(*(int *)(ac + 0x1c) + iVar2 + 100) = 0;
  *(undefined4 *)(*(int *)(iVar1 + 0x1c) + iVar2 + 0x68) = 0;
  *(undefined4 *)(*(int *)(iVar1 + 0x1c) + iVar2 + 0x6c) = 0;
  *(undefined4 *)(*(int *)(iVar1 + 0x1c) + iVar2 + 0x70) = 0;
  *(undefined4 *)(*(int *)(iVar1 + 0x1c) + iVar2 + 0x74) = 0;
  *(undefined4 *)(*(int *)(iVar1 + 0x1c) + iVar2 + 0x78) = 0;
  return;
}

