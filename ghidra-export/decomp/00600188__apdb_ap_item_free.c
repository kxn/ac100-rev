// func _apdb_ap_item_free @ 00600188 size=208

void _apdb_ap_item_free(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (0 < param_2)) {
    iVar3 = 0;
    uVar1 = *(undefined4 *)(param_1 + 0x50);
    iVar2 = param_1;
    while( true ) {
      iVar3 = iVar3 + 1;
      _apdb_ap_fwid_hash_free(uVar1);
      _apdb_ap_free(*(undefined4 *)(iVar2 + 0x54),*(undefined4 *)(iVar2 + 0x4c));
      if (iVar3 == param_2) break;
      uVar1 = *(undefined4 *)(iVar2 + 0xa8);
      iVar2 = iVar2 + 0x58;
    }
    FUN_00407df0(param_1);
    return;
  }
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : input para is NULL\n","_apdb_ap_item_free",0x3fe);
    return;
  }
  return;
}

