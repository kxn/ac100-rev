// func _apdb_ap_free @ 006000c4 size=196

void _apdb_ap_free(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = param_1;
    for (iVar2 = 0; iVar2 < param_2; iVar2 = iVar2 + 1) {
      if (*(int *)(iVar1 + 0x164) == 0) {
        *(undefined4 *)(iVar1 + 0x160) = 0;
      }
      else {
        _apdb_ap_model_radios_free(*(int *)(iVar1 + 0x164),*(undefined4 *)(iVar1 + 0x160));
        _apdb_ap_model_phy_info_free(*(undefined4 *)(iVar1 + 0x164),*(undefined4 *)(iVar1 + 0x160));
        _apdb_ap_model_rrst_free(*(undefined4 *)(iVar1 + 0x164),*(undefined4 *)(iVar1 + 0x160));
        _apdb_ap_model_region_list_free
                  (*(undefined4 *)(iVar1 + 0x164),*(undefined4 *)(iVar1 + 0x160));
        FUN_00407df0(*(undefined4 *)(iVar1 + 0x164));
        *(undefined4 *)(iVar1 + 0x164) = 0;
        *(undefined4 *)(iVar1 + 0x160) = 0;
      }
      iVar1 = iVar1 + 0x168;
    }
    FUN_00407df0(param_1);
    return;
  }
  return;
}

