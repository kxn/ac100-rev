// func _wsta_free_entry @ 00636d4c size=256

void _wsta_free_entry(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 + 0xc;
  if (DAT_007cc710 == iVar3) {
    DAT_007cc710 = FUN_00408680(iVar3);
  }
  iVar1 = FUN_00407f40(DAT_007cc6cc,param_1);
  if (((iVar1 != 0) && (g_wsta_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wsta>[error]%s(): %d  -> uac_hash_remove() fail, wsta_entry->id=%d, ret = %d!\r\n",
           "_wsta_free_entry",0x26b,*(undefined4 *)(param_1 + 0x1c),iVar1);
  }
  FUN_00407f40(DAT_007cc6d0,param_1);
  FUN_00407f40(DAT_007cc6d4,param_1);
  FUN_00408500(iVar3);
  FUN_00408500(param_1);
  FUN_004080f0(DAT_007cc6c0,*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}

