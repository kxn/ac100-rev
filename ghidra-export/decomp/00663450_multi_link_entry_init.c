// func multi_link_entry_init @ 00663450 size=176

undefined4 multi_link_entry_init(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = g_multi_link_array;
  if (*(int *)(param_1 + 0xc) != 0) {
    uVar3 = (uint)*(ushort *)(param_1 + 0x10);
    if (49999 < uVar3) {
      iVar2 = apmngr_db_get_ap_max();
      uVar3 = (uVar3 - 50000) + iVar2;
    }
    *(undefined1 *)(iVar1 + uVar3) = 0;
    iVar1 = g_multi_link_config_changed_array;
    uVar3 = (uint)*(ushort *)(param_1 + 0x10);
    if (49999 < uVar3) {
      iVar2 = apmngr_db_get_ap_max();
      uVar3 = (uVar3 - 50000) + iVar2;
    }
    *(undefined1 *)(iVar1 + uVar3) = 1;
  }
  return 0;
}

