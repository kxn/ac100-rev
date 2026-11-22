// func _wsta_free_entry_new @ 0063b91c size=408

void _wsta_free_entry_new(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_50 [12];
  undefined1 auStack_44 [6];
  byte local_3e;
  undefined1 auStack_3a [34];
  
  memset(auStack_50,0,0x38);
  if (((param_1 == 0) && (g_wsta_error != 0)) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[error]%s(): %d  -> get wsta entry fail.\r\n","_wsta_free_entry_new",0x27e);
  }
  iVar1 = wsta_db_get_mac_entry_by_peer(param_1 + 0x68,auStack_50);
  if ((iVar1 == 0) || (iVar1 = wsta_db_get_mac_entry_by_mld(param_1 + 0x68,auStack_50), iVar1 == 0))
  {
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    iVar1 = FUN_00407fa0(DAT_007cc6cc,auStack_44);
    if (iVar1 != 0) {
      _wsta_free_entry(iVar1);
    }
    iVar1 = 0;
    FUN_00407f30(DAT_007cc6bc);
    while (iVar1 < (int)(uint)local_3e) {
      iVar2 = memcmp(auStack_44,auStack_3a + iVar1 * 0xc,6);
      if (iVar2 == 0) {
        iVar1 = iVar1 + 1;
      }
      else {
        FUN_004082d0(DAT_007cc6bc,0xffffffff);
        iVar2 = FUN_00407fa0(DAT_007cc6cc,auStack_3a + iVar1 * 0xc);
        if (iVar2 != 0) {
          _wsta_free_entry(iVar2);
        }
        iVar1 = iVar1 + 1;
        FUN_00407f30(DAT_007cc6bc);
      }
    }
    wsta_db_free_mlo_mac_entry(auStack_50);
  }
  else {
    _wsta_free_entry(param_1);
  }
  return;
}

