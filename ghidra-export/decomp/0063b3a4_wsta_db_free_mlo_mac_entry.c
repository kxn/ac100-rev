// func wsta_db_free_mlo_mac_entry @ 0063b3a4 size=276

void wsta_db_free_mlo_mac_entry(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  iVar1 = FUN_00407fa0(DAT_007cc728,param_1 + 0xc);
  if (iVar1 != 0) {
    iVar2 = FUN_00407f40(DAT_007cc728,iVar1);
    if (((iVar2 != 0) && (g_wsta_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wsta>[error]%s(): %d  -> remove mld faile\n\r\n","wsta_db_free_mlo_mac_entry",0xf4f);
    }
    FUN_00407df0(iVar1);
  }
  for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(param_1 + 0x12); iVar1 = iVar1 + 1) {
    iVar2 = FUN_00407fa0(DAT_007cc72c,param_1 + iVar1 * 0xc + 0x16);
    if (iVar2 != 0) {
      FUN_00407f40(DAT_007cc72c,iVar2);
      FUN_00407df0(iVar2);
    }
  }
  FUN_00407f30(DAT_007cc6bc);
  return;
}

