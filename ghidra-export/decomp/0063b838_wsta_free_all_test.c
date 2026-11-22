// func wsta_free_all_test @ 0063b838 size=1

void wsta_free_all_test(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_50 [56];
  
  memset(auStack_50,0,0x38);
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  iVar1 = FUN_004081b0(&DAT_007cc6d8);
  while (iVar1 != 0) {
    iVar2 = FUN_00408680(iVar1);
    iVar3 = wsta_db_get_mac_entry_by_peer(iVar1 + 0x5c,auStack_50);
    if ((iVar3 == 0) || (iVar3 = wsta_db_get_mac_entry_by_mld(iVar1 + 0x5c,auStack_50), iVar3 == 0))
    {
      wsta_db_free_mlo_mac_entry(auStack_50);
    }
    _wsta_free_entry(iVar1 + -0xc);
    iVar1 = iVar2;
  }
  FUN_00407f30(DAT_007cc6bc);
  return;
}

